#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int indent_counter=0;       // global variable to keep track of indentation
FILE *fptr;                 // global file pointer for translation

/*************** FUNCTION DECLARATION ****************/
void print_indent                       (int    indent_counter);
char* python_type                       (enum   DATA_TYPE type);
char* node_type                         (enum   NODE_TYPE type);
void traverse                           (struct AST_Node_Statements *root);
void translate_init                     (struct AST_Node_Init *init);
void translate_func_call                (struct AST_Node_FunctionCall *func_call);
void translate_params                   (struct AST_Node_Params *params);
void translate_func_def                 (struct AST_Node_FunctionDef *func_def);
void translate_expr                     (struct AST_Node_Expression *expr);
void translate_if                       (struct AST_Node_If *if_statement);
void translate_else_if                  (struct AST_Node_Else_If *else_if_statement);
void translate_else                     (struct AST_Node_Else *else_statement);
void translate_for                      (struct AST_Node_For *for_loop);
void translate_input                    (struct AST_Node_Input *input);
void translate_output                   (struct AST_Node_Output *output);
void translate_return                   (struct AST_Node_Return *return_statement);
void translate_operand                  (union  Value_sym value, int operand_type);
void translate_access_class             (struct AST_Node_Object *access_class);
void traverse_class_init                (struct AST_Node_Statements *root);
void translate_func_call_obj            (struct AST_Node_FunctionCall *func_call,char *obj_name);
void translate_public_class_func_def    (struct AST_Node_FunctionDef *func_def);


/*************** FUNCTION DEFINITION ****************/

// function to print indentation
void print_indent(int indent_counter){
         for (int i = 0; i<indent_counter;i++)
         { fprintf(fptr,"\t", indent_counter);} }

// Function to translate the type into Python
char* python_type(enum DATA_TYPE type)
{
    switch (type)
    {
        case DATA_TYPE_FLOAT:
            return "float";
            break;
        case DATA_TYPE_INT:
            return "int";
            break;
        case DATA_TYPE_STRING:
            return "string";
            break;
        case DATA_TYPE_BOOL:
            return "bool";
            break;
        default :
            return "unknown";
            break;
    } 
}

// Function to convert the Node 
char* node_type(enum NODE_TYPE type)
{
    switch(type)
    {
        case INIT_NODE:
            return "INIT_NODE";
            break;
        case ASSIGN_NODE:
            return "ASSIGN_NODE";
            break;
        case EXPR_NODE:
            return "EXPR_NODE";
            break;
        case FUNC_CALL_NODE:
            return "FUNC_CALL_NODE";
            break;
        case FUNC_DEF_NODE:
            return "FUNC_DEF_NODE";
            break;
        case IF_NODE:
            return "IF_NODE";
            break;
        case ELSE_NODE:
            return "ELSE_NODE";
            break;
        case FOR_NODE:
            return "FOR_NODE";
            break;
        case INPUT_NODE:
            return "INPUT_NODE";
            break;
        case OUTPUT_NODE:
            return "OUTPUT_NODE";
            break;
        case CLASS_NODE:
            return "CLASS_NODE";
            break;
        case CLASS_CHILD_NODE:
            return "CLASS_CHILD_NODE";
            break;
        case OBJECT_NODE:
            return "OBJECT_NODE";
            break;
        case ACCESS_CLASS_NODE:
            return "ACCESS_CLASS_NODE";
            break;
        default:
            return "unknown node";
            break;
    }
}


// Function to traverse the AST 
void traverse(struct AST_Node_Statements *root)
{
    if ( root->left == NULL && root->right == NULL) {/* end of traverse */} 
        else if (root->left != NULL && root->right == NULL)
            {   
            struct AST_Node_Instruction *left = root->left;
            struct AST_Node_Statements *right = root->right;
            switch (left->n_type)
                {
                case INIT_NODE:
                // translate_init(left->value.init); // it is not necessary to print "int x" in the general translation, but only when needed
                    break;
                case ASSIGN_NODE:
                    translate_assign(left->value.assign);
                    break;
                case EXPR_NODE:
                    translate_expr(left->value.expression);
                    break;
                case FUNC_CALL_NODE:
                    print_indent(indent_counter);
                    translate_func_call(left->value.functionCall);
                    break;
                case FUNC_DEF_NODE:
                    translate_func_def(left->value.functionDef);
                    break;
                case IF_NODE:
                    translate_if(left->value.ifNode);
                    break;
                case ELSE_NODE:
                    translate_else(left->value.elseNode);
                    break;
                case ELSE_IF_NODE:
                    translate_else_if(left->value.elseIfNode);
                    break;
                case FOR_NODE:
                    translate_for(left->value.forNode);
                    break;
                case INPUT_NODE:
                    translate_input(left->value.inputNode);
                    break;
                case OUTPUT_NODE:
                    translate_output(left->value.outputNode);
                    break;
                case CLASS_NODE:
                    translate_class(left->value.classNode);
                    break;
                case CLASS_CHILD_NODE:
                    translate_class_child(left->value.classNode);
                    break;
                case OBJECT_NODE:
                    translate_object(left->value.objectNode);
                    break;
                case ACCESS_CLASS_NODE:
                    translate_access_class(left->value.objectNode);
                    break;
                default:
                    printf("error: unknown node");
                    break;
                }
            }
        else 
            {
            struct AST_Node_Instruction *left = root->left;
            struct AST_Node_Statements *right = root->right;
            switch (left->n_type) 
                {
                case INIT_NODE:
                // translate_init(left->value.init);
                    break;
                case ASSIGN_NODE:
                    translate_assign(left->value.assign);
                    break;
                case EXPR_NODE:
                    translate_expr(left->value.expression);
                    break;
                case FUNC_CALL_NODE:
                    print_indent(indent_counter);
                    translate_func_call(left->value.functionCall);
                    break;
                case FUNC_DEF_NODE:
                    translate_func_def(left->value.functionDef);
                    break;
                case IF_NODE:
                    translate_if(left->value.ifNode);
                    break;
                case ELSE_NODE:
                    translate_else(left->value.elseNode);
                    break;
                case ELSE_IF_NODE:
                    translate_else_if(left->value.elseIfNode);
                    break;
                case FOR_NODE:
                    translate_for(left->value.forNode);
                    break;
                case INPUT_NODE:
                    translate_input(left->value.inputNode);
                    break;
                case OUTPUT_NODE:
                    translate_output(left->value.outputNode);
                    break;
                case CLASS_NODE:
                    translate_class(left->value.classNode);
                    break;
                case CLASS_CHILD_NODE:
                    translate_class_child(left->value.classNode);
                    break;
                case OBJECT_NODE:
                    translate_object(left->value.objectNode);
                    break;
                case ACCESS_CLASS_NODE:
                    translate_access_class(left->value.objectNode);
                    break;
                default:
                    printf("unknown node");
                    break;
                }
                traverse(right); //continue traverse    
            }
}


/************************************************************* Translation functions ***********************************************************************/

// Function to translate the initialization 
void translate_init(struct AST_Node_Init *init)
{
    print_indent(indent_counter);
    fprintf(fptr, "%s = %s", init->assign->var, init->assign->a_val.val);
    fprintf(fptr, "\n");
}


// translate assign node
void translate_assign(struct AST_Node_Assign *assign)
{  

    print_indent(indent_counter);
    if (assign->a_type == CONTENT_TYPE_FUNCTION) 
        {
        fprintf(fptr, "%s = ",assign->var);
        translate_func_call(assign->a_val.funca);
        }
    else if (assign->a_type == CONTENT_TYPE_EXPRESSION) 
        {
        fprintf(fptr, "%s = ",assign->var);
        translate_expr(assign->a_val.expr);
        fprintf(fptr, "\n");
        }
    else { fprintf(fptr, "%s = %s", assign->var, assign->a_val.val); }
    fprintf(fptr, "\n");
}


// translate function call
void translate_func_call(struct AST_Node_FunctionCall *func_call)
{
    fprintf(fptr, "%s(", func_call->func_name);
    if (func_call->params != NULL){translate_params(func_call->params);}
    fprintf(fptr, ")");
    fprintf(fptr, "\n");
}


// translate function parameters 
void translate_params(struct AST_Node_Params *params)
{
    if (params->decl_param) // this is used to translate parameters inside a function declaration
        {
        fprintf(fptr, "%s", params->decl_param->assign->var);
        if (params->next_param == NULL) {/* no more parameters to pass*/}
        else    
            {
            fprintf(fptr, ", ");
            translate_params(params = params->next_param);
            }
        }
    else // this is used to translate parameters inside a function call
        {
        fprintf(fptr, "%s", params->call_param->value);
        if (params->next_param == NULL) {}
        else    
            {
            fprintf(fptr, ", ");
            translate_params(params = params->next_param);
            }
        }
}


// translate function definition
void translate_func_def(struct AST_Node_FunctionDef *func_def)
{
    //translate main function
    if (func_def->func_name == "main")
        {
        fprintf(fptr,"\n\n");
        translate_main(func_def);
        }

    // translate function definition
    else 
        {
        print_indent(indent_counter);
        fprintf(fptr, "def %s(", func_def->func_name);
        if (func_def->params != NULL)   { translate_params(func_def->params); }
        fprintf(fptr, "):");
        fprintf(fptr, "\n");
        indent_counter++;
        traverse(func_def->f_body->func_body); // translate body of function
        //translate return
        fprintf(fptr, "\treturn ");
        translate_operand(func_def->f_body->return_op->value ,func_def->f_body->return_op->operand_type);
        fprintf(fptr,"\n");
        indent_counter--;
        }
}


void translate_main(struct AST_Node_FunctionDef *func_def)
{
    fprintf(fptr, "def main():\n");
    indent_counter++;
    traverse(func_def->f_body->func_body); // translate body of function
    //translate return
    fprintf(fptr, "\treturn ");
    translate_operand(func_def->f_body->return_op->value ,func_def->f_body->return_op->operand_type);
    fprintf(fptr,"\n");
    indent_counter--;
    fprintf(fptr, "\nif __name__ == \"__main__\":\n");
    fprintf(fptr, "\tmain()\n");
}


//translate expression
void translate_expr(struct AST_Node_Expression *expr)
{   
    fprintf(fptr, "%s %s %s", expr->left_op->value.val, expr->op, expr->right_op->value.val);
}


// translate if statement
void translate_if(struct AST_Node_If *if_statement)
{
    print_indent(indent_counter);
    fprintf(fptr, "if ");
    translate_expr(if_statement->condition);
    fprintf(fptr, ":");
    fprintf(fptr, "\n");
    indent_counter++;
    traverse(if_statement->if_body); // translate body of if statement
    indent_counter--;
}

// translate else if statement
void translate_else_if(struct AST_Node_Else_If *else_if_statement)
{
    print_indent(indent_counter);
    fprintf(fptr, "elif ");
    translate_expr(else_if_statement->condition);
    fprintf(fptr, ":");
    fprintf(fptr, "\n");
    indent_counter++;
    traverse(else_if_statement->elif_body); // translate body of else if statement
    indent_counter--;
}

// translate else statement
void translate_else(struct AST_Node_Else *else_statement)
{
    print_indent(indent_counter);
    fprintf(fptr, "else:");
    fprintf(fptr, "\n");
    indent_counter++;
    traverse(else_statement->else_body); // translate body of else statement
    indent_counter--;
}


// translate for loop
void translate_for(struct AST_Node_For *for_loop)
{   

    if (for_loop->init->val_type == 1) { printf("\n\n\t***Error: Cannot use Float type in for loop***\n\n\n");}
    else {
    
    if (strcmp(for_loop->increment->a_val.expr->op, "-") == 0) 
        {
        print_indent(indent_counter);
        fprintf(fptr, "for %s in range(%s, %s, -%s):",
            for_loop->init->var,
            for_loop->init->a_val.val,
            for_loop->condition->right_op->value.val,
            for_loop->increment->a_val.expr->right_op->value.val);
        }
    else 
        {
        print_indent(indent_counter);
        fprintf(fptr, "for %s in range(%s, %s, %s):",
            for_loop->init->var,
            for_loop->init->a_val.val,
            for_loop->condition->right_op->value.val,
            for_loop->increment->a_val.expr->right_op->value.val);
        }
    fprintf(fptr, "\n");
    indent_counter++;
    traverse(for_loop->for_body); // translate body of for loop
    indent_counter--;
    }
}


// translate input statement
void translate_input(struct AST_Node_Input *input)
{
    print_indent(indent_counter);
    if (input->input_op->value.val == NULL){ printf("\n\n\t***Error: Variable is not declared here***\n\n\n"); }
    else{
    fprintf(fptr, "input(%s)", input->input_op->value.val);
        }
    fprintf(fptr, "\n");
    if (input->next_input == NULL){}
    else {translate_input(input->next_input);}
}

// translate output statement
void translate_output(struct AST_Node_Output *output)
{
    print_indent(indent_counter);
    if (output->output_op->value.val == NULL){ printf("\n\n\t***Error: Variable is not declared here***\n\n\n"); }
    else{
    fprintf(fptr, "print(%s)", output->output_op->value.val);
        }
    fprintf(fptr, "\n");
    if (output->next_output == NULL) {}
    else {translate_output(output->next_output);}
}


void translate_operand(union Value_sym value, int operand_type) 
{
    switch(operand_type) 
    {
    case CONTENT_TYPE_STRING:
        fprintf(fptr,"%s",value.val);
        break;
    case CONTENT_TYPE_ID:
        fprintf(fptr,"%s",value.val);
        break;
    case CONTENT_TYPE_EXPRESSION:
        fprintf(fptr,"%s",value.expr);
        break;
    case CONTENT_TYPE_FUNCTION:
        fprintf(fptr,"%s",value.funca);
        break;
    case CONTENT_TYPE_FLOAT_NUMBER:
        fprintf(fptr,"%s",value.val);
        break;
    case CONTENT_TYPE_INT_NUMBER:
        fprintf(fptr,"%s",value.val);
        break;
    default:
        printf("Type %d not recognized!", operand_type);
        break;
    }
}

void translate_class(struct AST_Node_Class *create_class)
{   
    // translate 
    print_indent(indent_counter);
    fprintf(fptr, "class %s:\n", create_class->class_name);
    indent_counter++;
    print_indent(indent_counter);
    fprintf(fptr, "def __init__(self):\n");
    indent_counter++;
    
    //traverse to translate self.name = name
    if (create_class->c_body->pri_body != NULL){
    traverse_class_private_init(create_class->c_body->pri_body);}
    if (create_class->c_body->pub_body != NULL){
    traverse_class_public_init(create_class->c_body->pub_body);}
    indent_counter--;
    fprintf(fptr, "\n");

    //traverse function def
    if (create_class->c_body->pri_body != NULL){

    traverse_class_private_func(create_class->c_body->pri_body);}
    
    if (create_class->c_body->pub_body != NULL){

    traverse_class_public_func(create_class->c_body->pub_body);}


    indent_counter--;
    
    fprintf(fptr, "\n");
}


void translate_class_child(struct AST_Node_Class *create_child)
{
    print_indent(indent_counter);
    fprintf(fptr, "class %s(", create_child->class_name);
    fprintf(fptr, "%s):\n", create_child->parent_class->class_name);
    indent_counter++;
    print_indent(indent_counter);
    fprintf(fptr, "def __init__(self):\n");
    indent_counter++;
    
    //traverse  self.name = name
    if (create_child->c_body->pri_body != NULL){ traverse_class_private_init(create_child->c_body->pri_body); }
    if (create_child->c_body->pub_body != NULL){ traverse_class_public_init (create_child->c_body->pub_body); }
    indent_counter--;
    fprintf(fptr, "\n");

    //traverse function definitions
    if (create_child->c_body->pri_body != NULL){

    traverse_class_private_func(create_child->c_body->pri_body);}
    
    if (create_child->c_body->pub_body != NULL){
    traverse_class_public_func(create_child->c_body->pub_body);}
    indent_counter--;
}


// translate the object creation
void translate_object(struct AST_Node_Object *create_object)
{
    print_indent(indent_counter);
    fprintf(fptr, "%s = %s", create_object->obj_name, create_object->obj_class->class_name);
    fprintf(fptr, "\n");
}


void translate_access_class(struct AST_Node_Object *access_class)
{
    print_indent(indent_counter);
    switch(access_class->access_type){
        case ACCESS_TYPE_VAR:
            fprintf(fptr, "%s.%s\n",access_class->obj_name, access_class->access_value.val);
            break;
        case ACCESS_TYPE_ASSIGN:
            fprintf(fptr, "%s.",access_class->obj_name);
            translate_object_assign(access_class->access_value.ass_val);
            break;
        case ACCESS_TYPE_FUNCTION:
            fprintf(fptr, "%s.",access_class->obj_name);
            translate_func_call_obj(access_class->access_value.funca,access_class->obj_name);
            break;
        default:
            break;
        }
}


// translate function call
void translate_func_call_obj(struct AST_Node_FunctionCall *func_call,char *obj_name)
{
    fprintf(fptr, "%s(%s", func_call->func_name, obj_name);
    if (func_call->params != NULL){fprintf(fptr,", ");translate_params(func_call->params);}
    fprintf(fptr, ")");
    fprintf(fptr, "\n");
}



void traverse_class_init(struct AST_Node_Statements *root)
{
        if ( root->left == NULL && root->right == NULL) {
    } 
        else if (root->left != NULL && root->right == NULL)
        {   
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)
        {
            case INIT_NODE:
                fprintf(fptr, ", %s", left->value.init->assign->var);
                break;
            default:
                break;
            }
        }
        else 
        {
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)  
        {
            case INIT_NODE:
                fprintf(fptr, ", %s", left->value.init->assign->var);
                break;
        }
        traverse_class_init(right); //continue traverse
   }
}

// traverse class to initialize
void traverse_class_private_init(struct AST_Node_Statements *root)
{
        if ( root->left == NULL && root->right == NULL) {} 
        else if (root->left != NULL && root->right == NULL)
        {   
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)
        {
            case INIT_NODE:
                print_indent(indent_counter);
                fprintf(fptr, "self.__%s = %s\n", left->value.init->assign->var,left->value.init->assign->var);
                break;
            case ASSIGN_NODE:
                print_indent(indent_counter);
                fprintf(fptr, "self.__%s = %s\n", left->value.assign->var,left->value.assign->a_val);
                break;

            default:
                break;
            }
        }

        else {
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)
        
        {
            case INIT_NODE:
                print_indent(indent_counter);
                fprintf(fptr, "self.__%s = %s\n", left->value.init->assign->var,left->value.init->assign->var);
                break;
            case ASSIGN_NODE:
                print_indent(indent_counter);
                fprintf(fptr, "self.__%s = %s\n", left->value.assign->var,left->value.assign->a_val);
                break;
        }
        traverse_class_private_init(right); //continue traverse
   }
}

void traverse_class_public_init(struct AST_Node_Statements *root)
{
        if ( root->left == NULL && root->right == NULL) {
    } 
        else if (root->left != NULL && root->right == NULL)
        {   
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)
        
        {
            case INIT_NODE:
                print_indent(indent_counter);
                fprintf(fptr, "self.%s = %s\n", left->value.init->assign->var,left->value.init->assign->var);
                break;
            case ASSIGN_NODE:
                print_indent(indent_counter);
                fprintf(fptr, "self.%s = %s\n", left->value.assign->var,left->value.assign->a_val);
                break;
            default:
                break;
            }
        }
        else {
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)
        
        {
            case INIT_NODE:
                print_indent(indent_counter);
                fprintf(fptr, "self.%s = %s\n", left->value.init->assign->var,left->value.init->assign->var);
                break;
            case ASSIGN_NODE:
                print_indent(indent_counter);
                fprintf(fptr, "self.%s = %s\n", left->value.assign->var,left->value.assign->a_val);
                break;
        }
        traverse_class_public_init(right); //continue traverse
   }
}

// traverse public methods in class
// Function to traverse the AST 
void traverse_class_public_func(struct AST_Node_Statements *root)
{
        if ( root->left == NULL && root->right == NULL) {
    } 
        else if (root->left != NULL && root->right == NULL)
        {   
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)  
        {
            case FUNC_DEF_NODE:
                translate_public_class_func_def(left->value.functionDef);
            default:
                break;
            }}
        else {
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)
        {
            case FUNC_DEF_NODE:
                translate_public_class_func_def(left->value.functionDef);
            default:
                break;
        }
        traverse_class_public_func(right); //continue traverse
   }
}

// translate function definition inside class
void translate_public_class_func_def(struct AST_Node_FunctionDef *func_def)
{
    print_indent(indent_counter);
    fprintf(fptr, "def %s(self", func_def->func_name);
    if (func_def->params != NULL){
    fprintf(fptr, ", ");
    translate_params(func_def->params);
    }
    fprintf(fptr, "):");
    fprintf(fptr, "\n");
    indent_counter++;
    traverse(func_def->f_body->func_body); // translate body of function
    print_indent(indent_counter);
    fprintf(fptr, "return ");
    translate_operand(func_def->f_body->return_op->value ,func_def->f_body->return_op->operand_type);
    fprintf(fptr,"\n\n");
    indent_counter--;
}


// traverse public methods in class
// Function to traverse the AST 
void traverse_class_private_func(struct AST_Node_Statements *root)
{
        if ( root->left == NULL && root->right == NULL) {
    } 
        else if (root->left != NULL && root->right == NULL)
        {   
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)  
        {
            case FUNC_DEF_NODE:
                translate_private_class_func_def(left->value.functionDef);
            default:
                break;
            }
        }
        else {
        struct AST_Node_Instruction *left = root->left;
        struct AST_Node_Statements *right = root->right;
        switch (left->n_type)
        {
            case FUNC_DEF_NODE:
                translate_private_class_func_def(left->value.functionDef);
            default:
                break;
        }
        traverse_class_private_func(right); //continue traverse
   }
}

// translate function definition inside class
void translate_private_class_func_def(struct AST_Node_FunctionDef *func_def)
{
    print_indent(indent_counter);
    fprintf(fptr, "def __%s(self", func_def->func_name);
    if (func_def->func_name == NULL){    
    fprintf(fptr,", ");
    translate_params(func_def->params);
    }
    fprintf(fptr, "):");
    fprintf(fptr, "\n");
    indent_counter++;
    traverse(func_def->f_body->func_body); // translate body of function
    print_indent(indent_counter);
    fprintf(fptr, "return ");
    translate_operand(func_def->f_body->return_op->value ,func_def->f_body->return_op->operand_type);
    fprintf(fptr,"\n\n");
    indent_counter--;
}

// translate assign node inside class
void translate_object_assign(struct AST_Node_Assign *assign)
{  
    if (assign->a_type == CONTENT_TYPE_FUNCTION) {
    fprintf(fptr, "%s = ",assign->var);
    translate_func_call(assign->a_val.funca);
    }
    else if (assign->a_type == CONTENT_TYPE_EXPRESSION) {
        fprintf(fptr, "%s = ",assign->var);
        translate_expr(assign->a_val.expr);
    }
    else {
    fprintf(fptr, "%s = %s", assign->var, assign->a_val.val);
    }
    fprintf(fptr, "\n");
}
