/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    IF = 259,
    ELSE = 260,
    ID = 261,
    INT_NUMBER = 262,
    FLOAT_NUMBER = 263,
    INT = 264,
    FLOAT = 265,
    STRING = 266,
    BOOL = 267,
    LPAR = 268,
    RPAR = 269,
    LBRACE = 270,
    RBRACE = 271,
    COLON = 272,
    COMMA = 273,
    DOT = 274,
    BRACKETS = 275,
    RETURN = 276,
    COUT = 277,
    CIN = 278,
    STRING_V = 279,
    BOOL_V = 280,
    FOR = 281,
    FUNCTION = 282,
    CLASS = 283,
    MAIN = 284,
    PRIVATE = 285,
    PUBLIC = 286,
    UNKNOWN = 287,
    EQ = 288,
    AND = 289,
    OR = 290,
    ADD = 291,
    SUB = 292,
    MUL = 293,
    DIV = 294,
    GT = 295,
    LT = 296,
    GE = 297,
    LE = 298,
    EEQ = 299,
    NE = 300,
    LSHIFT = 301,
    RSHIFT = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union yystype YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
