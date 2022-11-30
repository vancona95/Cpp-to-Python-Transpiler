#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for exit function used by uthash
#include "ast.h"
#include "uthash.h" // uthash handles hash tables

/***************************************************************************
                             Symbol Table Module
***************************************************************************/
/*=========================================================================
                             DECLARATIONS
=========================================================================*/

//                         SYMBOL TABLE
struct SymTab
{
    struct Symbol *symtab;      /* hash table */
    struct SymTab *next;        /* next table */
    int scope;                  /* scope of this table */

};

//                         SYMBOL TABLE ENTRY
struct Symbol
{
    char *name_sym;                 /* name of symbol and hash table Key */
    enum SYMBOL_TYPE symbol_type;   /* type of symbol */
    enum DATA_TYPE data_type;       /* type of data */
    enum DATA_TYPE ret_type;
    bool is_function;               /* is this symbol a function? */
    bool is_class;                  /* is this symbol a class?*/
    char *param_func_name;           // name of the function the parameter belongs to
    int line_num;                  /* line number of symbol */

    union Value_sym value_sym;      /* value of symbol */

    UT_hash_handle hh;         /* makes this structure hashable */

};

/*=========================================================================
                             FUNCTIONS
=========================================================================*/
struct Symbol *find_symbol(char *name_sym, struct SymTab *table); // find symbol in symbol table
struct Symbol *add_symbol(char *name_sym, struct SymTab *table, enum SYMBOL_TYPE symbol_type, enum DATA_TYPE data_type, enum DATA_TYPE ret_type, bool is_function,char *param_func_name, bool is_class, int line_num, union Value_sym value_sym);
struct SymTab *new_symtab(int scope, struct SymTab *next); // create new symbol table
struct Symbol *find_symtab(char *name_sym, struct SymTab *symtab); // find symbol table in symbol table list
struct SymTab *delete_symtab(struct SymTab *table); // delete symbol table


/*-------------------------------------------------------------------------
                         SYMBOL TABLE FUNCTIONS
-------------------------------------------------------------------------*/
struct Symbol *find_symbol(char *name_sym, struct SymTab *table) 
{
  struct Symbol *s;
  HASH_FIND_STR(table->symtab, name_sym, s);  /* s: output pointer */
  return s;
  if (s==NULL) {
    printf("\n\n\t***Error: Symbol %s not found***\n\n\n", name_sym);
    return NULL;
    }
  else {
  return s;
  }
}


struct Symbol *add_symbol(char *name_sym, struct SymTab *table, enum SYMBOL_TYPE symbol_type, enum DATA_TYPE data_type, enum DATA_TYPE ret_type, bool is_function, char *param_func_name, bool is_class, int line_num, union Value_sym value_sym) // add symbol to symbol table
{   
    struct Symbol *s;  
    s = find_symbol(name_sym, table);
    if (s==NULL) {
    s = (struct Symbol *)malloc(sizeof(struct Symbol));
    s->name_sym = name_sym;
    s->symbol_type = symbol_type;
    s->data_type = data_type;
    s->ret_type = ret_type;
    s->is_function = is_function;
    s->param_func_name = param_func_name; // This field is used to both flag a function parameter Symbol, and to know which fuction it belongs to
    s->is_class = is_class;
    s->line_num = line_num;
    s->value_sym = value_sym;

    HASH_ADD_STR(table->symtab, name_sym, s);  /* id: name of key field */  

    }
    else {
    printf("\n\n\t***Error: Symbol %s already exists***\n\n\n", name_sym);
    }
}

 // delete symbol from symbol table
void delete_symbol(struct Symbol *s, struct SymTab *table) 
{
    HASH_DEL(table->symtab, s); 
    free(s);
}



struct Symbol *find_symtab(char *name_sym, struct SymTab *table)
 {  
  struct Symbol *s;
  struct SymTab *t = table;
  while (t != NULL) {
    s = find_symbol(name_sym, t);
    if (s != NULL) {
      return s;
    }
    t = t->next;
  }
}

struct SymTab *new_symtab(int scope, struct SymTab *next) // create new symbol table
{
    struct Symbol *symtab = NULL;
    struct SymTab *table = (struct SymTab *) malloc(sizeof(struct SymTab));

    table->symtab = symtab;
    table->next = next;
    table->scope = scope;
    return table;
}

struct SymTab *delete_symtab(struct SymTab *table) // delete symbol table
{
    struct Symbol *s;
    struct Symbol *tmp;
    struct SymTab *t = table;
    HASH_ITER(hh, t->symtab, s, tmp) {
    HASH_DEL(t->symtab, s);  /* delete; users advances to next */
    free(s);                
    }
}



#endif
