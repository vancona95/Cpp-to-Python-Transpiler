%{
/****************** Prologue *****************/ 
	#include <math.h>
	#include <stdio.h>
	#include <ctype.h>
    #include <string.h>
	#include "symtab.h"
    #include "ast.h" 
    #include "translation.h"
    #include <stdbool.h>

    int yylex (void);
    int yyerror(char *s);
    int n_error = 0;
    extern int yylineno;
    // Pointer to file used for translation
    FILE *fptr;

/****************** Initialization of structs, counters and variables*****************/ 
    struct Ast_Node_Statements  *root;
    struct SymTab *local_table  = NULL; 
    struct AST_Node_Class       *class_array[100]       = { NULL };
    struct AST_Node_Object      *object_array[100]      = { NULL };
    struct AST_Node_FunctionDef *function_array[100]    = { NULL };
    int class_counter = 0;
    int object_counter = 0;
    int function_counter = 0;
    bool found = false;
    bool in_class = false;

/****************** functions declaration *****************/ 
    bool search_class_body(char* var_name, struct AST_Node_Statements *root);
    void check_function_call(struct AST_Node_FunctionCall *func_call);
    char * type_to_str(int type);
    void scope_enter();
    void scope_exit();
    
%}

    //%define parse.error verbose
    //%debug

    %token SEMICOLON
	%token IF 
	%token ELSE
	%token ID
	%token INT_NUMBER   
	%token FLOAT_NUMBER
    %token INT
	%token FLOAT
	%token STRING
	%token BOOL
    %token LPAR
    %token RPAR
    %token LBRACE
    %token RBRACE
    %token COLON
    %token COMMA
    %token DOT
    %token BRACKETS
	%token RETURN
	%token COUT
	%token CIN
	%token STRING_V
    %token BOOL_V
	%token FOR
    %token FUNCTION
    %token CLASS
    %token MAIN
    %token PRIVATE
    %token PUBLIC
    %token UNKNOWN
    %token EQ AND OR ADD SUB MUL DIV GT LT GE LE EEQ NE 
    %token LSHIFT RSHIFT
 
/****************** types *****************/ 
    %define api.value.type {union yystype}

    %type <string>          types ID STRING FLOAT_NUMBER INT_NUMBER FLOAT INT BOOL LPAR RPAR LBRACE RBRACE COLON SEMICOLON COMMA DOT BRACKETS RETURN COUT CIN STRING_V BOOL_V FOR FUNCTION CLASS UNKNOWN AND OR ADD SUB MUL DIV GT LT GE LE EEQ NE MAIN PRIVATE PUBLIC EQ
    %type <statements>      statements body program private_body public_body
    %type <instruction>     instruction 
    %type <functionCall>    function_call
    %type <functionDef>     function_def
    %type <params>          multi_fun_param fun_param  
    %type <ifNode>          if_statement
    %type <expression>      if_condition expr math_expr logic_expr rel_expr 
    %type <elseIfNode>      else_if_statement
    %type <elseNode>        else_statement
    %type <forNode>         for_loop
    %type <inputNode>       single_rshift multi_rshift input_stmnt
    %type <outputNode>      single_lshift multi_lshift output_stmnt 
    %type <assign>          assignment
    %type <init>            initialization 
    %type <operand>         content
    %type <FBodyNode>       func_body
    %type <classNode>       create_class create_class_child
    %type <CBodyNode>       class_body
    %type <objectNode>      create_object access_class

    %start program
%%  

    program:   { scope_enter(); }    statements    { root = $2; scope_exit(); };


    statements:
                instruction statements              {   
                                                        $$ = malloc(sizeof(struct AST_Node_Statements));
                                                        $$->n_type = STATEMENT_NODE;
                                                        $$->left = $1;
                                                        $$->right = $2;
                                                    }
            |   instruction                         {
                                                        $$ = malloc(sizeof(struct AST_Node_Statements));
                                                        $$->n_type = STATEMENT_NODE;
                                                        $$->left = $1;
                                                        $$->right = NULL;
                                                    };


    instruction:
                function_call SEMICOLON         {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = FUNC_CALL_NODE;
                                                $$->value.functionCall = $1;
                                                }
            |   function_def                    {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->value.functionDef = $1;
                                                struct Symbol *s = NULL;
                                                s = find_symtab($1->func_name, local_table);
                                                if (s == NULL)  {
                                                $$->n_type = FUNC_DEF_NODE;
                                                $$->value.functionDef = $1;
                                                struct Symbol *s = add_symbol($1->func_name, local_table, SYMBOL_FUNCTION, DATA_TYPE_NONE,$1->return_type, true, NULL, false, yylineno, null_value); }
                                                else { printf("\n\n\t***Error: %s already declared***\n\t***Line: %d***\n\n\n",s->name_sym,yylineno);n_error++; }
                                                }
            |   create_class SEMICOLON          {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = CLASS_NODE;
                                                $$->value.classNode = $1;
                                                struct Symbol *s = add_symbol($1->class_name, local_table, SYMBOL_CLASS, DATA_TYPE_NONE,DATA_TYPE_NONE, false, NULL, true, yylineno, null_value);
                                                }
            |   create_class_child SEMICOLON    {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = CLASS_CHILD_NODE;
                                                $$->value.classNode = $1;
                                                struct Symbol *s = add_symbol($1->class_name, local_table, SYMBOL_CLASS, DATA_TYPE_NONE,DATA_TYPE_NONE, false, NULL, true, yylineno, null_value);
                                                }
            |   create_object SEMICOLON         {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = OBJECT_NODE;
                                                $$->value.objectNode = $1;
                                                struct Symbol *s = add_symbol($1->obj_name, local_table, SYMBOL_OBJECT, DATA_TYPE_NONE,DATA_TYPE_NONE, false, NULL, true, yylineno, null_value);
                                                }
            |   access_class SEMICOLON          {      
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = ACCESS_CLASS_NODE;
                                                $$->value.objectNode = $1;
                                                }
            |   if_statement                    {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = IF_NODE;
                                                $$->value.ifNode = $1;
                                                }
            |   else_if_statement               {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = ELSE_IF_NODE;
                                                $$->value.elseIfNode = $1;
                                                }
            |   else_statement                  {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = ELSE_NODE;
                                                $$->value.elseNode = $1;
                                                }
            |   for_loop                        {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = FOR_NODE;
                                                $$->value.forNode = $1;
                                                }
            |   input_stmnt SEMICOLON           {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = INPUT_NODE;
                                                $$->value.inputNode = $1;
                                                }
            |   output_stmnt SEMICOLON          {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = OUTPUT_NODE;
                                                $$->value.outputNode = $1;
                                                }
            |   assignment SEMICOLON            {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                $$->n_type = ASSIGN_NODE;
                                                struct Symbol *s = find_symbol($1->var, local_table);
                                                if ((s->data_type != $1->val_type) || strcmp(type_to_str(s->data_type) , "Type none") == 0)   {
                                                    printf("\n\n\t***Error: Variable '%s' has been declared as a '%s' but type '%s' is assigned***\n\t***Line: %d***\n\n\n", 
                                                    $1->var, type_to_str(s->data_type), type_to_str($1->val_type),yylineno);n_error++;
                                                    }
                                                else    {
                                                    $$->value.assign = $1;
                                                    s->value_sym = $1->a_val;
                                                    }
                                                }
            |   initialization SEMICOLON        {
                                                $$ = malloc(sizeof(struct AST_Node_Instruction));
                                                struct Symbol *s = NULL;
                                                for(struct AST_Node_Init *init = $1; init != NULL; init = init->next_init) {
                                                    s = find_symbol(init->assign->var, local_table);
                                                    if (s == NULL)  {
                                                        $$->n_type = INIT_NODE;
                                                        $$->value.init = $1;
                                                        s = add_symbol(init->assign->var, local_table, SYMBOL_VARIABLE, $1->data_type, DATA_TYPE_NONE, false, NULL, false, yylineno, null_value);
                                                        }
                                                    else {printf("\n\n\t***Error: Variable %s already declared, value is %s ***\n\t***Line: %d***\n\n\n",$1->assign->var,s->value_sym.val,yylineno);n_error++;
                                                        }
                                                    }
                                                };

    
    function_call:
                ID LPAR multi_fun_param RPAR    { 
                                                $$ = malloc(sizeof(struct AST_Node_FunctionCall));
                                                struct Symbol *s = find_symtab($1, local_table);
                                                if (s!=NULL) 
                                                    {
                                                    if (s->is_function) {
                                                        $$->func_name = $1;
                                                        $$->return_type = s->ret_type;
                                                        $$->params = $3;
                                                        /* Check if the function exists and if parameters are legit */
                                                        check_function_call($$);                                                    
                                                        }
                                                    else {
                                                        printf("\n\n\t***Error: %s is not a function***\n\t***Line: %d***\n\n\n",$1,yylineno);n_error++;
                                                        }
                                                    }
                                                else { printf("\n\n\t***Error: %s is not declared***\n\t***Line: %d***\n\n\n",$1,yylineno); n_error++;}
                                                }
            |   ID LPAR RPAR                   { 
                                                $$ = malloc(sizeof(struct AST_Node_FunctionCall));
                                                struct Symbol *s = find_symtab($1, local_table);
                                                if (s!=NULL) 
                                                    {
                                                    if (s->is_function) {
                                                        $$->func_name = $1;
                                                        $$->return_type = s->ret_type;
                                                        $$->params = NULL;
                                                        /* Check if the function exists and if parameters are legit */
                                                        check_function_call($$);                                                    
                                                        }
                                                    else {
                                                        printf("\n\n\t***Error: %s is not a function***\n\t***Line: %d***\n\n\n",$1,yylineno);n_error++;
                                                        }
                                                    }
                                                else { printf("\n\n\t***Error: %s is not declared***\n\t***Line: %d***\n\n\n",$1,yylineno); n_error++;}
                                                };


    function_def:
                initialization LPAR                     { if (in_class == false ){scope_enter();}; }
                multi_fun_param                         { for(struct AST_Node_Params *param = $4; param != NULL; param = param->next_param) 
                                                        {
                                                        struct Symbol *s = add_symbol(param->decl_param->assign->var, local_table, SYMBOL_FUNCTION, $4->decl_param->data_type, DATA_TYPE_NONE, true, $1->assign->var, false, yylineno, param->decl_param->assign->a_val);};
                                                        }
                RPAR func_body                          {
                                                        $$ = malloc(sizeof(struct AST_Node_FunctionDef));
                                                        $$->func_name = $1->assign->var;
                                                        $$->params = $4;
                                                        $$->f_body = $7;
                                                        // check if return data type and function data type match
                                                        if ($1->data_type !=  $$->f_body->return_op->val_type)
                                                            {
                                                            printf("\n\n\t***Error: Function %s has been declared as a '%s' but type '%s' is returned ***\n\n\n", 
                                                            $$->func_name, type_to_str($1->data_type), type_to_str($$->f_body->return_op->val_type));n_error++;
                                                            }
                                                        $$->return_type = $1->data_type;
                                                        // add function to function array; 
                                                        function_array[function_counter] = $$;
                                                        function_counter++;
                                                        if (in_class == false ){scope_exit();};
                                                        }
            |   INT MAIN LPAR RPAR func_body            {     
                                                        scope_enter();
                                                        $$ = malloc(sizeof(struct AST_Node_FunctionDef));
                                                        $$->func_name = "main";
                                                        $$->params = NULL;
                                                        $$->return_type = DATA_TYPE_INT;
                                                        //controllo su return?
                                                        $$->f_body = $5;
                                                        scope_exit();
                                                        }
            |   initialization LPAR RPAR func_body      { if (in_class == false ){scope_enter();};
                                                        $$ = malloc(sizeof(struct AST_Node_FunctionDef));
                                                        $$->func_name = $1->assign->var;
                                                        $$->params = NULL;
                                                        $$->f_body = $4;
                                                        // check if return data type and function data type match
                                                        if ($1->data_type !=  $$->f_body->return_op->val_type)
                                                            {
                                                            printf("\n\n\t***Error: Function %s has been declared as a '%s' but type '%s' is returned ***\n\n\n", 
                                                            $$->func_name, type_to_str($1->data_type), type_to_str($$->f_body->return_op->val_type));n_error++;
                                                            }
                                                        $$->return_type = $1->data_type;
                                                        // add function to function array; 
                                                        function_array[function_counter] = $$;
                                                        function_counter++;
                                                        if (in_class == false ){scope_exit();};
                                                        };



    create_object:
                ID ID       { /*check if $1 exists */
                            struct Symbol *s = find_symtab($1, local_table);
                            if (s!=NULL) 
                                {
                                if (s->is_class) 
                                    {
                                    struct Symbol *s2 = find_symtab($2, local_table);
                                    if (s2==NULL) 
                                        {
                                        $$ = malloc(sizeof(struct AST_Node_Object));
                                        $$->obj_class = malloc(sizeof(struct AST_Node_Class));
                                        //Search class in the class array by name
                                        for (int i = 0; i<class_counter; i++){
                                            if (strcmp(class_array[i]->class_name, $1) ==0)
                                                { 
                                                $$->obj_class = class_array[i];
                                                $$->obj_name = $2;
                                                object_array[object_counter] = $$;
                                                object_counter++;
                                                break;
                                                }
                                            }
                                        }
                                    else { printf("\n\n\t***Error: object %s already exists***\n\t***Line: %d***\n\n\n",$2,yylineno); n_error++;}
                                    }
                                else { printf("\n\n\t***Error: %s is not a class***\n\t***Line: %d***\n\n\n",$1,yylineno); n_error++;}
                                }
                            else { printf("\n\n\t***Error: class %s is not declared***\n\t***Line: %d***\n\n\n",$1,yylineno); n_error++;}
                            };
                                      

 access_class:
                ID DOT ID               {
                                        // Search for the object in the object array by name
                                        for (int i = 0; i<object_counter; i++)
                                            {
                                            if (strcmp(object_array[i]->obj_name, $1) == 0)
                                                { 
                                                $$->obj_class = object_array[i]->obj_class;
                                                $$->obj_name = object_array[i]->obj_name;
                                                break;
                                                }
                                            }
                                        //Search class in class array by name
                                        for (int j = 0; j<class_counter; j++){
                                            if (strcmp(class_array[j]->class_name, $$->obj_class->class_name) ==0)
                                                {
                                                $$->obj_class->c_body->pub_body = class_array[j]->c_body->pub_body;
                                                break;
                                                }
                                            }
                                        //Search attribute in the same class of the object
                                        if (search_class_body($3, $$->obj_class->c_body->pub_body) == true)
                                            { $$->access_value.val = $3; }
                                        else 
                                            {
                                        // check if the attribute is present in the parent classes 
                                            for (int k = 0; k<class_counter; k++)
                                                {
                                                // check if the class is present in the classes array
                                                if (strcmp(class_array[k]->class_name, $$->obj_class->class_name) == 0)
                                                    {
                                                    // check if the class has a parent
                                                    if (class_array[k]->parent_class_public != NULL)
                                                        {
                                                        $$->obj_class->parent_class_public = class_array[k]->parent_class_public;
                                                        // cycle in the public body of each parent classes 
                                                        for (   class_array[k]->parent_class_public->parent_pub_body;
                                                                class_array[k]->parent_class_public->parent_pub_body != NULL;
                                                                class_array[k]->parent_class_public->parent_pub_body = class_array[k]->parent_class_public->next_parent_public->parent_pub_body
                                                            ){
                                                            // check if the attribute is present in the public body of the parent class
                                                            if (search_class_body($3, class_array[k]->parent_class_public->parent_pub_body) == true)
                                                                {                                       
                                                                $$->access_value.val = $3;
                                                                $$->access_type = ACCESS_TYPE_VAR;
                                                                break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if ($$->access_value.val == NULL){printf("\n\n\n\t\t***ERROR: %s not found in class %s***\n\n\n", $3,$$->obj_class->class_name);n_error++;}
                                        }
        |       ID DOT function_call    {                     
                                        // Search for the object in the object array by name
                                        for (int i = 0; i<object_counter; i++)
                                            {
                                            if (strcmp(object_array[i]->obj_name, $1) ==0)
                                                { 
                                                $$->obj_class = object_array[i]->obj_class;
                                                $$->obj_name = object_array[i]->obj_name;
                                                break;
                                                }
                                            }
                                        //Search class in class array by name
                                        for (int j = 0; j<class_counter; j++){
                                            if (strcmp(class_array[j]->class_name, $$->obj_class->class_name) ==0)
                                                {
                                                $$->obj_class->c_body->pub_body = class_array[j]->c_body->pub_body;
                                                break;
                                                }
                                            }
                                        //Search attribute in the same class of the object
                                        if (search_class_body($3->func_name, $$->obj_class->c_body->pub_body) == true)
                                            {
                                            $$->access_value.funca = $3;
                                            $$->access_type = ACCESS_TYPE_FUNCTION;
                                            }
                                        else 
                                            {
                                        // check if the attribute is present in the parent classes 
                                            for (int k = 0; k<class_counter; k++){
                                                // check if the class is present in the classes array
                                                if (strcmp(class_array[k]->class_name, $$->obj_class->class_name) == 0)
                                                    {
                                                    // check if the class has a parent
                                                    if (class_array[k]->parent_class_public != NULL)
                                                        {
                                                        $$->obj_class->parent_class_public = class_array[k]->parent_class_public;
                                                        // cycle in the public body of each parent classes   
                                                        for (   class_array[k]->parent_class_public->parent_pub_body;
                                                                class_array[k]->parent_class_public->parent_pub_body != NULL;
                                                                class_array[k]->parent_class_public->parent_pub_body = class_array[k]->parent_class_public->next_parent_public->parent_pub_body
                                                            ){
                                                            // check if the attribute is present in the public body of the parent class
                                                            if (search_class_body($3->func_name, class_array[k]->parent_class_public->parent_pub_body) == true){
                                                                $$->access_value.funca = $3;
                                                                $$->access_type = ACCESS_TYPE_FUNCTION;
                                                                break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            if ($$->access_value.funca == NULL){printf("\n\n\t***Error: %s not found in class %s***\n\t***Line: %d***\n\n\n",$3->func_name,$$->obj_class->class_name,yylineno);n_error++;}
                                        }
        |       ID DOT assignment       { 
                                        // Search for the object in the object array by name
                                        for (int i = 0; i<object_counter; i++)
                                            {
                                            if (strcmp(object_array[i]->obj_name, $1) == 0)
                                                { 
                                                $$->obj_class = object_array[i]->obj_class;
                                                $$->obj_name = object_array[i]->obj_name;
                                                break;
                                                }
                                            }
                                        //Search class in class array by name

                                        for (int j = 0; j<class_counter; j++)
                                            {
                                            if (strcmp(class_array[j]->class_name, $$->obj_class->class_name) == 0)
                                                {
                                                $$->obj_class->c_body->pub_body = class_array[j]->c_body->pub_body;
                                                break;
                                                }
                                            }

                                            //Search attribute in the same class of the object
                                        if (search_class_body($3->var, $$->obj_class->c_body->pub_body) == true)
                                            {
                                            $$->access_value.ass_val = $3;
                                            $$->access_type = ACCESS_TYPE_ASSIGN;
                                            }
                                        else 
                                            {
                                            // check if the attribute is present in the parent classes 
                                            for (int k = 0; k<class_counter; k++)
                                                {
                                                // check if the class is present in the classes array
                                                if (strcmp(class_array[k]->class_name, $$->obj_class->class_name) == 0)
                                                    {
                                                    // check if the class has a parent
                                                    if (class_array[k]->parent_class_public != NULL)
                                                        {
                                                        $$->obj_class->parent_class_public = class_array[k]->parent_class_public;
                                                        // cycle in the public body of each parent classes   
                                                        for (   class_array[k]->parent_class_public->parent_pub_body;
                                                                class_array[k]->parent_class_public->parent_pub_body != NULL;
                                                                class_array[k]->parent_class_public->parent_pub_body = class_array[k]->parent_class_public->next_parent_public->parent_pub_body
                                                            ){

                                                            // check if the attribute is present in the public body of the parent class
                                                            if (search_class_body($3->var, class_array[k]->parent_class_public->parent_pub_body) == true)
                                                                { 
                                                                $$->access_value.ass_val = $3;
                                                                $$->access_type = ACCESS_TYPE_ASSIGN;
                                                                break;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }                                                                    
                                            }
                                            if ($$->access_value.ass_val == NULL){printf("\n\n\t***Error: %s not found in class %s***\n\t***Line: %d***\n\n\n",$3->var,$$->obj_class->class_name,yylineno);n_error++;}
                                        };


    create_class:
                CLASS ID                {in_class = true;}
                class_body              {
                                        $$ = malloc(sizeof(struct AST_Node_Class));
                                        $$->parent_class_public = malloc(sizeof(struct AST_Node_Parent_Public));
                                        $$->class_name = $2;
                                        $$->c_body = $4;
                                        $$->parent_class_public = NULL;
                                        class_array[class_counter] = $$;
                                        class_counter++;
                                        in_class = false;
                                        };


    create_class_child:
                CLASS ID                       {in_class = true;}
                COLON PUBLIC ID class_body     {
                                                        $$ = malloc(sizeof(struct AST_Node_Class));
                                                        $$->parent_class_public = malloc(sizeof(struct AST_Node_Parent_Public));
                                                        $$->class_name = $2;
                                                        $$->c_body = $7;
                                                        // search parent class in the class array
                                                        for (int i = 0; i<class_counter; i++)
                                                            {
                                                            // compare the name of the parent class in the statement with the name of the class in the class array
                                                             if (strcmp(class_array[i]->class_name, $6) == 0)
                                                                {
                                                                $$->parent_class = class_array[i];
                                                                $$->parent_class->class_name = class_array[i]->class_name;
                                                                $$->parent_class_public->parent_pub_body = class_array[i]->c_body->pub_body;
                                                                $$->parent_class_public->next_parent_public = class_array[i]->parent_class_public;
                                                                class_array[class_counter] = $$;        
                                                                class_counter++;
                                                                break;
                                                                }
                                                             else if (i == class_counter){printf("\n\n\n\t\t***ERROR: class parent %s not found***\n\n\n",$6); n_error++;}
                                                        }
                                                        in_class = false;

                                                        };


    class_body:
                LBRACE private_body public_body RBRACE              {   
                                                                    $$ = malloc(sizeof(struct AST_Node_CBody));
                                                                    //$$->pri_body = malloc(sizeof(struct AST_Node_Statements));
                                                                    //$$->pub_body = malloc(sizeof(struct AST_Node_Statements));
                                                                    $$->pri_body = $2;
                                                                    $$->pub_body = $3;
                                                                    }
            |    LBRACE public_body private_body RBRACE             {
                                                                    $$ = malloc(sizeof(struct AST_Node_CBody));
                                                                    //$$->pri_body = malloc(sizeof(struct AST_Node_Statements));
                                                                    //$$->pub_body = malloc(sizeof(struct AST_Node_Statements));
                                                                    $$->pri_body = $3;
                                                                    $$->pub_body = $2;
                                                                    };


    private_body:
                PRIVATE COLON statements { $$ = $3; }
                |/*empty private body*/;


    public_body:
                PUBLIC COLON statements { $$ = $3; }
                |/*empty public body*/;


    if_statement:
                IF LPAR if_condition RPAR body          { 
                                                        $$ = malloc(sizeof(struct AST_Node_If));
                                                        $$->condition = $3;
                                                        $$->if_body = $5;
                                                        };


    if_condition:
                expr                            {
                                                if($1->expr_type != DATA_TYPE_BOOL) { printf("\n\n\t***Error: IF condition must be boolean type***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                                else { $$ = $1; }
                                                };
    

    else_if_statement:
                ELSE IF LPAR if_condition RPAR body {
                                                    $$ = malloc(sizeof(struct AST_Node_Else_If));
                                                    $$->condition = $4;
                                                    $$->elif_body = $6;
                                                    };
    
    
    else_statement:
                ELSE body                       {
                                                $$ = malloc(sizeof(struct AST_Node_Else));
                                                $$->else_body = $2;
                                                };


    for_loop:
                FOR LPAR assignment SEMICOLON rel_expr SEMICOLON assignment RPAR body   {
                                                                                        $$ = malloc(sizeof(struct AST_Node_For));
                                                                                        $$->init = $3;
                                                                                        $$->condition = $5;
                                                                                        $$->increment = $7;
                                                                                        // The increment can be expressed only as x = x + 1 and not as x++ or x += 1
                                                                                        // The sign of the increment expression will be used at translation time for further control:
                                                                                        // The control is needed to solve a problem where the decrement is written as x = x -1 and not as x = x - 1
                                                                                        $$->increment->a_val.expr->op = $7->a_val.expr->op;
                                                                                        $$->for_body = $9;
                                                                                        delete_symbol( find_symbol($3->var,local_table), local_table);
                                                                                        };


    body: 
                LBRACE statements RBRACE          { $$ = $2; };

    
    func_body:  LBRACE statements RETURN content SEMICOLON RBRACE       {   
                                                                        $$ = malloc(sizeof(struct AST_Node_FBody));                                       
                                                                        $$->func_body = $2;
                                                                        $$->return_op = $4;
                                                                        };


    expr:
                math_expr               { $$ = $1; }
            |   logic_expr              { $$ = $1; }
            |   rel_expr                { $$ = $1; }
            |                           { $$ = NULL; }
            |   LPAR expr RPAR          { $$ = $2; };


    math_expr:
                content ADD content         {
                                            $$ = malloc(sizeof(struct AST_Node_Expression));
                                            // queste malloc permettono il riconoscimento della x
                                            $$->left_op = malloc(sizeof(struct AST_Node_Operand));
                                            $$->right_op = malloc(sizeof(struct AST_Node_Operand));
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->op = $2;
                                            $$->expr_type = $3->val_type;
                                            if ($1->val_type != $3->val_type) 
                                                { printf("\n\n\t***Error: Cannot add '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str($1->val_type), type_to_str($3->val_type),yylineno); n_error++;}
                                                
                                            else 
                                                {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                                };
                                            }
            |   content SUB content         { 
                                            $$ = malloc(sizeof(struct AST_Node_Expression));
                                            $$->op = $2;
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->expr_type = $1->val_type;
                                            if ($1->val_type != $3->val_type) 
                                                { printf("\n\n\t***Error: Cannot subtract '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str($1->val_type), type_to_str($3->val_type),yylineno); n_error++;}
                                            else 
                                                {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                                };
                                            }
            |   content MUL content         { 
                                            $$ = malloc(sizeof(struct AST_Node_Expression));
                                            // queste malloc permettono il riconoscimento della x
                                            $$->left_op = malloc(sizeof(struct AST_Node_Operand));
                                            $$->right_op = malloc(sizeof(struct AST_Node_Operand));
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->op = $2;
                                            if ($1->val_type != $3->val_type) 
                                                { printf("\n\n\t***Error: Cannot multiply '%s' to '%s'***\n\t***Line: %d***\n\n\n",type_to_str($1->val_type), type_to_str($3->val_type),yylineno); n_error++;}
                                            else 
                                                {
                                                $$->left_op = $1;
                                                $$->right_op = $3;
                                                $$->expr_type = $1->val_type;
                                                }
                                            }
            |   content INT_NUMBER          {   
                                            // This rule is used in case expression written as: int x = A -B and not as x = A - B
                                            // check if the second token is a negative integer number
                                            if (atoi($2)<0) 
                                                {                                               
                                                int temp= atoi($2);
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%d", temp );
                                                char* temp_str = malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%d", temp );

                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = malloc(sizeof(struct AST_Node_Operand));
                                                S1->value = $1->value;
                                                S1->val_type = DATA_TYPE_INT;
                                                S1->operand_type = CONTENT_TYPE_INT_NUMBER;

                                                S2 = malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_INT;
                                                S2->operand_type = CONTENT_TYPE_INT_NUMBER;
                                                
                                                $$ = malloc(sizeof(struct AST_Node_Expression));
                                                $$->op = "-";
                                                $$->left_op = S1;
                                                $$->right_op = S2;
                                                $$->expr_type = DATA_TYPE_INT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed ***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
            |   INT_NUMBER INT_NUMBER       {   
                                            // This rule is used in case expression written as: int x = A -B and not as x = A - B
                                            // check if the second token is a negative integer number
                                            if (atoi($2)<0) 
                                                {                                               
                                                int temp= atoi($2);
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%d", temp );
                                                char* temp_str = malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%d", temp );

                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = malloc(sizeof(struct AST_Node_Operand));
                                                S1->value.val = $1;
                                                S1->val_type = DATA_TYPE_INT;
                                                S1->operand_type = CONTENT_TYPE_INT_NUMBER;

                                                S2 = malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_INT;
                                                S2->operand_type = CONTENT_TYPE_INT_NUMBER;
                                                
                                                $$ = malloc(sizeof(struct AST_Node_Expression));
                                                $$->op = "-";
                                                $$->left_op = S1;
                                                $$->right_op = S2;
                                                $$->expr_type = DATA_TYPE_INT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed ***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
                                            
            |   content FLOAT_NUMBER        {
                                            //check if the second token is a negative float number
                                            if (atof($2)<0) 
                                                {                                               
                                                float temp= atof($2);
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%4.3f", temp );
                                                char* temp_str = malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%4.3f", temp );
                                                
                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = malloc(sizeof(struct AST_Node_Operand));
                                                S1->value = $1->value;
                                                S1->val_type = DATA_TYPE_FLOAT;
                                                S1->operand_type = CONTENT_TYPE_FLOAT_NUMBER;

                                                S2 = malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_FLOAT;
                                                S2->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                                
                                                $$ = malloc(sizeof(struct AST_Node_Expression));
                                                $$->op = "-";
                                                $$->left_op = S1;
                                                $$->right_op = S2;
                                                $$->expr_type = DATA_TYPE_FLOAT;
                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                            }
            |   FLOAT_NUMBER FLOAT_NUMBER   {
                                            //check if the second token is a negative float number
                                            if (atof($2)<0) 
                                                {                                               
                                                float temp= atof($2);
                                                temp = -temp;
                                                int length = snprintf( NULL, 0, "%4.3f", temp );
                                                char* temp_str = malloc( length + 1 );
                                                //cast back to string
                                                snprintf( temp_str, length + 1, "%4.3f", temp );
                                                
                                                // Need to allocate operands in order to use the expression
                                                struct AST_Node_Operand *S1, *S2;
                                                S1 = malloc(sizeof(struct AST_Node_Operand));
                                                S1->value.val = $1;
                                                S1->val_type = DATA_TYPE_FLOAT;
                                                S1->operand_type = CONTENT_TYPE_FLOAT_NUMBER;

                                                S2 = malloc(sizeof(struct AST_Node_Operand));
                                                S2->value.val = temp_str;
                                                S2->val_type = DATA_TYPE_FLOAT;
                                                S2->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                                
                                                $$ = malloc(sizeof(struct AST_Node_Expression));
                                                $$->op = "-";
                                                $$->left_op = S1;
                                                $$->right_op = S2;
                                                $$->expr_type = DATA_TYPE_FLOAT;

                                            }
                                            else { printf("\n\n\t***Error: Operation not allowed***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            }
            |   content DIV content     { 
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        // queste malloc permettono il riconoscimento della x
                                        $$->left_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->right_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->left_op = $1;
                                        $$->right_op = $3;
                                        $$->op = $2;
                                        if ($1->val_type != $3->val_type) 
                                            { printf("\n\n\t***Error: Cannot divide '%s' by '%s'***\n\t***Line: %d***\n\n\n", type_to_str($1->val_type), type_to_str($3->val_type),yylineno); n_error++;}
                                        else    
                                            {
                                            if (strcmp($3->value.val,"0" ) == 0)   { printf("\n\n\t***Error: Cannot divide by 0***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                            else 
                                                {
                                                $$->left_op = $1;
                                                $$->right_op = $3;
                                                $$->expr_type = $1->val_type;
                                                }
                                            }
                                        };
    

    logic_expr:
                LPAR logic_expr RPAR    {   
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$ = $2;
                                        }
            |   content AND content     {   
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$->op = $2;
                                        if ($1->val_type != DATA_TYPE_BOOL || $3->val_type != DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot AND '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str($1->val_type), type_to_str($3->val_type),yylineno);n_error++; }
                                        else {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
            |   content OR content      {   
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$->op = $2;
                                        if ($1->val_type != DATA_TYPE_BOOL || $3->val_type != DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot OR '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str($1->val_type), type_to_str($3->val_type),yylineno);n_error++; }
                                        else 
                                            {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->expr_type = DATA_TYPE_BOOL;
                                            }
                                        };
    

    rel_expr:
                LPAR rel_expr RPAR      {  
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$ = $2; 
                                        }
            |   content LT content      { 
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$->left_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->right_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->left_op = $1;
                                        $$->right_op = $3;
                                        $$->op = $2;
                                        if ($1->val_type != $3->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str($1->val_type), type_to_str($3->val_type),yylineno); n_error++;}
                                        else if ($1->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                        else {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
            |   content LE content      { 
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$->op = $2;
                                        if ($1->val_type != $3->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str($1->val_type), type_to_str($3->val_type),yylineno); n_error++;}
                                        else if ($1->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                        else 
                                            {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
            |   content GT content      { 
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$->op = $2;
                                        if ($1->val_type != $3->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str($1->val_type), type_to_str($3->val_type),yylineno); n_error++;}
                                        else if ($1->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno); n_error++;}
                                        else 
                                            {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
            |   content GE content      {
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$->op = $2;
                                        if ($1->val_type != $3->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str($1->val_type), type_to_str($3->val_type),yylineno);n_error++; }
                                        else if ($1->val_type == DATA_TYPE_BOOL) 
                                            { printf("\n\n\t***Error: Cannot compare boolean values***\n\t***Line: %d***\n\n\n",yylineno);n_error++; }
                                        else 
                                            {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->expr_type = DATA_TYPE_BOOL;
                                            }
                                        }
            |   content EEQ content     { 
                                        $$ = malloc(sizeof(struct AST_Node_Expression));
                                        $$->op = $2;
                                        if ($1->val_type != $3->val_type) 
                                            { printf("\n\n\t***Error: Cannot compare '%s' with '%s'***\n\t***Line: %d***\n\n\n", type_to_str($1->val_type), type_to_str($3->val_type),yylineno); n_error++;}
                                        else 
                                            {
                                            $$->left_op = $1;
                                            $$->right_op = $3;
                                            $$->expr_type = DATA_TYPE_BOOL;
                                            }
                                        };


    input_stmnt:
                CIN multi_rshift  { $$=$2; };
        
    
    output_stmnt:
                COUT multi_lshift  { $$=$2; };
    
    
    multi_rshift:
                single_rshift multi_rshift  {                     
                                            $1->next_input = $2;
                                            $$ = $1; 
                                            }
            |                               { $$=NULL; };
    
    
    multi_lshift:
                single_lshift multi_lshift  { 
                                            $1->next_output = $2;
                                            $$ = $1;
                                            }
            |                               { $$ = NULL; };


    single_rshift:
                RSHIFT ID               {
                                        $$ = malloc(sizeof(struct AST_Node_Input));
                                        $$->input_op = malloc(sizeof(struct AST_Node_Operand));
                                        struct Symbol *s = find_symbol($2, local_table);
                                        if(s == NULL) { $$->input_op->val_type = DATA_TYPE_NONE; }
                                        else    
                                            {
                                        $$->input_op->value.val = $2;
                                        $$->input_op->val_type = s->data_type;
                                        $$->input_op->operand_type = CONTENT_TYPE_ID;
                                            }
                                        };
    
    
    single_lshift:
                LSHIFT ID               {
                                        $$ = malloc(sizeof(struct AST_Node_Output));
                                        $$->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        struct Symbol *s = find_symbol($2, local_table);
                                        if(s == NULL) { $$->output_op->val_type = DATA_TYPE_NONE; }
                                        else    
                                            {
                                            $$->output_op->value.val = $2;
                                            $$->output_op->val_type = s->data_type;
                                            $$->output_op->operand_type = CONTENT_TYPE_ID;
                                            }
                                        }
            |  LSHIFT STRING_V          {
                                        $$ = malloc(sizeof(struct AST_Node_Output));
                                        $$->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->output_op->value.val = $2;
                                        $$->output_op->val_type = DATA_TYPE_STRING;
                                        $$->output_op->operand_type = CONTENT_TYPE_STRING;
                                        $$->next_output = NULL;
                                        }
            |   LSHIFT FLOAT_NUMBER     {
                                        $$ = malloc(sizeof(struct AST_Node_Output));
                                        $$->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->output_op->value.val = $2;
                                        $$->output_op->val_type = DATA_TYPE_FLOAT;
                                        $$->output_op->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                        }
            |   LSHIFT INT_NUMBER       {
                                        $$ = malloc(sizeof(struct AST_Node_Output));
                                        $$->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->output_op->value.val = $2;
                                        $$->output_op->val_type = DATA_TYPE_INT;
                                        $$->output_op->operand_type = CONTENT_TYPE_INT_NUMBER;
                                        }
            |   LSHIFT BOOL_V           {
                                        $$ = malloc(sizeof(struct AST_Node_Output));
                                        $$->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->output_op->value.val = $2;
                                        $$->output_op->val_type = DATA_TYPE_BOOL;
                                        $$->output_op->operand_type = CONTENT_TYPE_BOOL;
                                        }
            |   LSHIFT function_call    {
                                        $$ = malloc(sizeof(struct AST_Node_Output));
                                        $$->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        struct Symbol *s = find_symbol($2, local_table);
                                        if(s==NULL) { $$->output_op->val_type = DATA_TYPE_NONE; }
                                        else 
                                            {
                                        $$->output_op->value.funca = $2;
                                        $$->output_op->val_type = s->data_type;
                                        $$->output_op->operand_type = CONTENT_TYPE_FUNCTION;
                                            }
                                        }
            |   LSHIFT expr             {
                                        $$ = malloc(sizeof(struct AST_Node_Output));
                                        $$->output_op = malloc(sizeof(struct AST_Node_Operand));
                                        $$->output_op->value.expr = $2;
                                        $$->output_op->val_type = $2->expr_type;
                                        $$->output_op->operand_type = CONTENT_TYPE_EXPRESSION;
                                        };


    multi_fun_param:
                fun_param                          {
                                                    $1->next_param = NULL;
                                                    $$ = $1;
                                                    }
            |   fun_param COMMA  multi_fun_param    {
                                                    $1->next_param = $3;
                                                    $$ = $1;
                                                    };


    fun_param:
                types ID        { 
                                $$ = malloc(sizeof(struct AST_Node_Params));
                                $$->decl_param = malloc(sizeof(struct AST_Node_Init));
                                $$->decl_param->data_type = str_to_type($1);
                                $$->decl_param->assign = malloc(sizeof(struct AST_Node_Assign));
                                $$->decl_param->assign->val_type = str_to_type($1);
                                $$->decl_param->assign->var = $2;
                                $$->decl_param->assign->a_val.val = NULL;
                                $$->decl_param->assign->a_type = CONTENT_TYPE_ID;
                                }
            |   content         { 
                                $$ = malloc(sizeof(struct AST_Node_Params));
                                //$$->call_param = malloc(sizeof(struct AST_Node_Operand));
                                $$->call_param = $1;
                                //$$->call_param->val_type = $1->val_type;
                                };
                                        

    initialization:
                types ID        {
                                $$ = malloc(sizeof(struct AST_Node_Init));
                                $$->data_type = str_to_type($1);
                                $$->next_init = NULL;
                                $$->assign = malloc(sizeof(struct AST_Node_Assign));
                                $$->assign->val_type = str_to_type($1);
                                $$->assign->var = $2;
                                $$->assign->a_val.val = NULL;
                                $$->assign->a_type = CONTENT_TYPE_ID;
                                };


    assignment:
                ID EQ ID            { 
                                    $$ = malloc(sizeof(struct AST_Node_Assign));
                                    $$->var = $1;
                                    $$->a_val.val = $3;
                                    $$->a_type = CONTENT_TYPE_ID;
                                    struct Symbol *s = find_symbol($3, local_table);
                                    if (s==NULL) { $$->val_type = DATA_TYPE_NONE; }
                                    else { $$-> val_type = s->data_type; }
                                    }
           |  types ID EQ content   { 
                                    struct Symbol *s = NULL;
                                    s = find_symbol($2, local_table);
                                    if (s == NULL)  
                                        { s = add_symbol($2, local_table, SYMBOL_VARIABLE, str_to_type($1), str_to_type($1), false, NULL, false, yylineno, $4->value); }
                                    else { printf("\n\n\t***Error: Variable %s already declared, value is %s***\n\t***Line: %d***\n\n\n",$2,s->value_sym.val,yylineno); n_error++;}
                                    if((str_to_type($1) != $4->val_type))
                                        { printf("\n\n\t***Error: Cannot assign type %s to type %s***\n\t***Line: %d***\n\n\n",type_to_str($4->val_type),type_to_str(str_to_type($1)),yylineno); n_error++;}
                                    else
                                        {
                                        $$ = malloc(sizeof(struct AST_Node_Assign));
                                        $$->a_type = $4->operand_type;
                                        $$->var = $2;
                                        $$->a_val = $4->value;
                                        $$->val_type = str_to_type($1);
                                        }
                                    }
           | ID EQ content          { 
                                    $$ = malloc(sizeof(struct AST_Node_Assign));
                                    $$->var = $1;
                                    $$->a_val = $3->value;
                                    $$->val_type = $3->val_type;
                                    $$->a_type = $3->operand_type;
                                    };


    content:
                ID              { 
                                $$ = malloc(sizeof(struct AST_Node_Operand));
                                struct Symbol *s = find_symtab($1, local_table);
                                if(s==NULL) { $$->val_type = DATA_TYPE_NONE; }
                                else 
                                    {
                                    $$->value.val = $1;
                                    $$->val_type = s->data_type;
                                    $$->operand_type = CONTENT_TYPE_ID;
                                    }
                                }
            |   FLOAT_NUMBER    {
                                $$ = malloc(sizeof(struct AST_Node_Operand));
                                $$->value.val = $1;
                                $$->val_type = DATA_TYPE_FLOAT;
                                $$->operand_type = CONTENT_TYPE_FLOAT_NUMBER;
                                }
            |   INT_NUMBER      {
                                $$ = malloc(sizeof(struct AST_Node_Operand));
                                $$->value.val = $1;
                                $$->val_type = DATA_TYPE_INT;
                                $$->operand_type = CONTENT_TYPE_INT_NUMBER;
                                }
            |   STRING_V        { 
                                $$ = malloc(sizeof(struct AST_Node_Operand));
                                $$->value.val = $1;
                                $$->val_type = DATA_TYPE_STRING;
                                $$->operand_type = CONTENT_TYPE_STRING;
                                }
            |   BOOL_V          { 
                                $$ = malloc(sizeof(struct AST_Node_Operand));
                                if (strcmp($1,"false")==0){$$->value.val = "False";}
                                else if (strcmp($1,"true")==0){$$->value.val = "True";}
                                $$->val_type = DATA_TYPE_BOOL;
                                $$->operand_type = CONTENT_TYPE_BOOL;
                                }
            |   function_call   {
                                $$ = malloc(sizeof(struct AST_Node_Operand));
                                $$->value.funca = $1;
                                $$->val_type = $1->return_type;
                                $$->operand_type = CONTENT_TYPE_FUNCTION;
                                }
            |   expr            { 
                                $$ = malloc(sizeof(struct AST_Node_Operand));
                                $$->value.expr = $1;
                                $$->val_type = $1->expr_type;
                                $$->operand_type = CONTENT_TYPE_EXPRESSION;
                                };


    types:
            FLOAT   { $$ = DATA_TYPE_FLOAT; }
        |   INT     { $$ = DATA_TYPE_INT; }
        |   STRING  { $$ = DATA_TYPE_STRING; }
        |   BOOL    { $$ = DATA_TYPE_BOOL; };
%%

/****************** Functions *****************/ 

int main(){
    
    yyparse();
    null_value.val = NULL;
    indent_counter=0;
    
    if (n_error == 0){
    fptr = fopen("python_transpiled.py","w");
    traverse(root);
    fclose(fptr);
    printf("\nParsing completed\n");
    }
    else {printf("\nParsing failed. errors found: %d\n",n_error);}
    return 0;
    }

int yyerror(char *s) { printf("\n\n\t***Error: %s***\n\t***Line: %d***\n\n\n",s,yylineno); n_error++;}

/****************** Scope handling *****************/ 

void scope_enter(){
    local_table = new_symtab(indent_counter, local_table);
    indent_counter++;
}

void scope_exit(){
    delete_symtab(local_table);
    indent_counter--;
}

/****************** Convert Data Type to String and viceversa *****************/ 

char * type_to_str(int type) {
    switch (type) {
        case DATA_TYPE_STRING:
            return "string";
        break;
        case DATA_TYPE_FLOAT:
            return "float";
        break;
        case DATA_TYPE_INT:
            return "int";
        break;
        case DATA_TYPE_BOOL:
            return "bool";
        break;
        case DATA_TYPE_NONE:
            return "Type none";
        break;
        default:
            return "Type not defined";
        break;
    }
}

int str_to_type (int type) {
    if      (strcmp(type_to_str(type), "string") == 0)  { return DATA_TYPE_STRING; }
    else if (strcmp(type_to_str(type), "float") == 0)   { return DATA_TYPE_FLOAT; }
    else if (strcmp(type_to_str(type), "int") == 0)     { return DATA_TYPE_INT; }
    else if (strcmp(type_to_str(type), "bool") == 0)    { return DATA_TYPE_BOOL; }
    else                                                { return DATA_TYPE_NONE; }
    }


/************************************************************* Support functions ***********************************************************************/

// Function to traverse the statements in class body
// Given a variable or function, it checks if is is present in the statements of the class body
// This function is used to check the parent class body when parent_class_body is given. (eg. in access_class rule)

bool search_class_body(char* var_name, struct AST_Node_Statements *root)
{
        if ( root->left == NULL && root->right == NULL) {} 
        else if (root->left != NULL && root->right == NULL)
        {       
            struct AST_Node_Instruction *left = root->left;
            struct AST_Node_Statements *right = root->right;
            switch (left->n_type)
            {
            case INIT_NODE:
                if (strcmp(left->value.init->assign->var, var_name)==0){
                    found = true;
                    return true;
                    break;
                    }
                else{                    
                    found = false;
                    return false;
                    break;
                    }
                break;
            case ASSIGN_NODE:
                if (strcmp(left->value.assign->var, var_name)==0){
                    found = true;
                    return true;
                    break;
                    }
                else{                    
                    found = false;
                    return false;
                    break;
                    }
                break;
            case FUNC_DEF_NODE:
                if (strcmp(left->value.functionDef->func_name, var_name)==0){
                    found = true;
                    return true;
                    break;
                    }
                else{                   
                    found = false;
                    return false;
                    break;
                    }
                break;
            default:
                printf("\n\n\t***Error: Unknown node***\n\t***Line: %d***\n\n\n",yylineno);n_error++;
                break;
            }
        }
        else {  
            bool found = false;
            struct AST_Node_Instruction *left = root->left;
            struct AST_Node_Statements *right = root->right;
            switch (left->n_type)
                {
                case INIT_NODE:
                    if (strcmp(left->value.init->assign->var, var_name)==0){
                        found = true;
                        return true;
                        break;
                        }
                    else{                    
                        found = false;
                        }
                    break;
                case ASSIGN_NODE:
                    if (strcmp(left->value.assign->var, var_name)==0){
                        found = true;
                        return true;
                        break;
                        }
                    else{                    
                        found = false;
                        }
                    break;
                case FUNC_DEF_NODE:
                    if (strcmp(left->value.functionDef->func_name, var_name)==0){
                        found = true;
                        return true;
                        break;
                        }
                    else{                    
                        found = false;
                        }
                    break;
                default:
                    printf("\n\n\t***Error: Unknown node***\n\t***Line: %d***\n\n\n",yylineno);n_error++;
                    break;
                }
        search_class_body(var_name,right); //continue traverse    
        }
}


/************************************************************* check function declarement ***********************************************************************/

// Check if the function name is already defined, if it is actually a function and then check parameters
void check_function_call(struct AST_Node_FunctionCall *func_call)
    {
    struct AST_Node_Params *func_call_first_param   = malloc(sizeof(struct AST_Node_Params));
    struct AST_Node_Params *func_def_first_param    = malloc(sizeof(struct AST_Node_Params));
    struct Symbol *s = NULL;
    s = find_symtab(func_call->func_name, local_table);
    if (s == NULL)  { printf("\n\n\t***Error: Function %s has not been declared ***\n\t***Line: %d***\n\n\n",func_call->func_name,yylineno); n_error++;}
    else if (s->is_function != true) { printf("\n\n\t***Error: Variable %s is not a function ***\n\t***Line: %d***\n\n\n",s->name_sym,yylineno); n_error++;}
    else    {
            for (int i = 0; i<function_counter; i++)
                {
                if (strcmp(function_array[i]->func_name, func_call->func_name) == 0)
                    {
                    // make a copy of the functions's FIRST parameters pointer, so we can roll back at the end of the check.
                    func_call_first_param = func_call->params;
                    func_def_first_param = function_array[i]->params;       
                    
                    // check if defined functin has empty parameters
                    if      ((function_array[i]->params == NULL) && (func_call->params != NULL))    { printf("\n\n\t***Error: Function %s has no parameters ***\n\t***Line: %d***\n\n\n",func_call->func_name,yylineno); n_error++;}
                    else if ((function_array[i]->params == NULL) && (func_call->params == NULL))    {/* both function definition and function call parameters are empty */}
                    else    
                        {
                        while((function_array[i]->params != NULL) && (func_call->params != NULL))
                        {
                        if (func_call->params->call_param->val_type == function_array[i]->params->decl_param->data_type)    { /* the parameter is of the correct type */ }
                        else 
                            {
                            printf("\n\n\t***Error: Parameter %s is type %s, while declared function needs type %s ***\n\n\n",func_call->params->call_param->value.val, type_to_str(func_call->params->call_param->val_type),type_to_str(function_array[i]->params->decl_param->data_type));n_error++;
                            }
                        // If one of the two functions has no more parameters, but the other has, then there is an error
                        if (    ((func_call->params->next_param == NULL) && (function_array[i]->params->next_param != NULL))
                                ||
                                ((func_call->params->next_param != NULL) && (function_array[i]->params->next_param == NULL))
                            )   { printf("\n\n\t***Error: Number of defined function parameter and called function differs ***\n\n\n");n_error++; }

                        // Check next parameters
                        func_call->params = func_call->params->next_param;
                        function_array[i]->params = function_array[i]->params->next_param;
                        }
                        // Roll back to the first parameter pointer of the functions.
                        func_call->params = func_call_first_param;
                        function_array[i]->params = func_def_first_param;  
                        }
                    }
                }
            }
}
