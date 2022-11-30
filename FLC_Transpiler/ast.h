#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************** Data Types *****************/ 

// TYPE OF SYMBOLS
enum SYMBOL_TYPE {
    SYMBOL_VARIABLE,
    SYMBOL_CONTENT,
    SYMBOL_FUNCTION,
    SYMBOL_CLASS,
    SYMBOL_OBJECT,
    SYMBOL_PARAMETER,
};

//  TYPE OF DATA 
enum DATA_TYPE {
    DATA_TYPE_NONE,
    DATA_TYPE_FLOAT,
    DATA_TYPE_INT,
    DATA_TYPE_STRING,
    DATA_TYPE_BOOL
};
/****************** Node Types *****************/ 

union yystype {
    char *string;
    struct AST_Node_Assign          *assign;
    struct AST_Node_Declare_Params  *declare_params;
    struct AST_Node_Params          *params;
    struct AST_Node_Instruction     *instruction;
    struct AST_Node_Expression      *expression;
    struct AST_Node_Statements      *statements;
    struct AST_Node_Value           *value;
    struct AST_Node_Variable        *variable;
    struct AST_Node_Init            *init;
    struct AST_Node_FunctionCall    *functionCall;
    struct AST_Node_FunctionDef     *functionDef;
    struct AST_Node_If              *ifNode;
    struct AST_Node_Else            *elseNode;
    struct AST_Node_Else_If         *elseIfNode;
    struct AST_Node_For             *forNode;
    struct AST_Node_Operand         *operand;
    struct AST_Node_Return          *returnNode;
    struct AST_Node_Input           *inputNode;
    struct AST_Node_Output          *outputNode;
    struct AST_Node_FBody           *FBodyNode;
    struct AST_Node_Class           *classNode;
    struct AST_Node_CBody           *CBodyNode;
    struct AST_Node_Object          *objectNode;
};

enum NODE_TYPE {
    INIT_NODE,
    ASSIGN_NODE,
    EXPR_NODE,
    FUNC_CALL_NODE,
    FUNC_DEF_NODE,
    IF_NODE,
    ELSE_NODE,
    ELSE_IF_NODE,
    FOR_NODE,
    INPUT_NODE,
    OUTPUT_NODE,
    STATEMENT_NODE,
    CLASS_NODE,
    CLASS_CHILD_NODE,
    OBJECT_NODE,
    ACCESS_CLASS_NODE,
};

enum CONTENT_TYPE {
    CONTENT_TYPE_ID,
    CONTENT_TYPE_STRING,
    CONTENT_TYPE_FLOAT_NUMBER,
    CONTENT_TYPE_INT_NUMBER,
    CONTENT_TYPE_EXPRESSION,
    CONTENT_TYPE_BOOL,
    CONTENT_TYPE_FUNCTION,
};

enum ACCESS_TYPE {
    ACCESS_TYPE_VAR,
    ACCESS_TYPE_ASSIGN,
    ACCESS_TYPE_FUNCTION,
};

/* ---------------------COMPLEX TYPES-------------------------- */

// TODO DA USARE CON AST_Node_Value 
typedef union Value_sym {
    char *val;
    struct AST_Node_Expression *expr;
    struct AST_Node_FunctionCall *funca; 
    struct AST_Node_Assign  *ass_val;
};

static union Value_sym null_value;

struct AST_Node_Statements{
    enum NODE_TYPE n_type;
    struct AST_Node_Instruction *left;
    struct AST_Node_Statements *right;
};

struct AST_Node_Instruction {
    enum NODE_TYPE n_type;
    union yystype value;
};

/* ----------------------------INITIALIZATION NODE--------------------------------------- */

struct AST_Node_Init{
    enum DATA_TYPE data_type;
    struct AST_Node_Assign *assign;
    struct AST_Node_Init *next_init;
};

struct AST_Node_Assign { 
    char *var;
    enum DATA_TYPE val_type;
    union Value_sym a_val;
    enum CONTENT_TYPE a_type;
};

struct AST_Node_FunctionCall{
    char *func_name;
    struct AST_Node_Params *params;  // parametri funzione
    enum DATA_TYPE return_type;
};

struct AST_Node_FunctionDef{
    char *func_name;
    struct AST_Node_Params *params;  // parametri funzione
    enum DATA_TYPE return_type;
    struct AST_Node_FBody *f_body;
};

struct AST_Node_Params{
    struct AST_Node_Init    *decl_param;    // da usare in dichiarazione di funzione
    struct AST_Node_Operand *call_param;    // da usare solo nella chiamata di funzione
    struct AST_Node_Params  *next_param;

};

struct AST_Node_If{
	struct AST_Node_Expression *condition;
	struct AST_Node_Statements *if_body;
};

struct AST_Node_Else_If{
    struct AST_Node_Expression *condition;
    struct AST_Node_Statements *elif_body;
};

struct AST_Node_Else{
    struct AST_Node_Statements *else_body;
};

struct AST_Node_Operand {
    union Value_sym value;
    enum DATA_TYPE val_type;
    enum CONTENT_TYPE operand_type;
};

struct AST_Node_For{
    struct AST_Node_Assign *init;
    struct AST_Node_Expression *condition;
    struct AST_Node_Assign *increment;
    struct AST_Node_Statements *for_body;
};

struct AST_Node_Expression{
    enum DATA_TYPE expr_type;
    char *op;
    struct AST_Node_Operand *left_op;  // left operand
	struct AST_Node_Operand *right_op; // right operand
    
};

struct AST_Node_Input{
    struct AST_Node_Operand  *input_op;
    struct AST_Node_Input *next_input;
};

struct AST_Node_Output{
    struct AST_Node_Operand  *output_op;
    struct AST_Node_Output *next_output;
};

struct AST_Node_FBody {
    struct AST_Node_Statements *func_body;
    struct AST_Node_Operand *return_op;

};

struct AST_Node_Class {
    char *class_name;
    struct AST_Node_CBody *c_body;
    struct AST_Node_Class *parent_class;
    struct AST_Node_Parent_Public *parent_class_public;
};


struct AST_Node_CBody {
    struct AST_Node_Statements *pri_body;
    struct AST_Node_Statements *pub_body;
};

struct AST_Node_Parent_Public {
    struct AST_Node_Statements      *parent_pub_body;
    struct AST_Node_Parent_Public   *next_parent_public;

};

struct AST_Node_Object {
    char *obj_name;
    union Value_sym access_value;
    struct AST_Node_Class *obj_class;
    enum ACCESS_TYPE access_type;
};

#endif
