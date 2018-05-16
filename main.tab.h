/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_MAIN_TAB_H_INCLUDED
# define YY_YY_MAIN_TAB_H_INCLUDED
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
    _INTEGER_VALUE = 258,
    _VARIABLE_NAME = 259,
    _FLOAT_VALUE = 260,
    _CHAR_VALUE = 261,
    _INT_DECLARATION = 262,
    _FLOAT_RECLARATION = 263,
    _CHAR_DECLARATION = 264,
    _IF_CONDITION = 265,
    _WHILE_CONDITION = 266,
    _ASSIGN_UNARY_OP = 267,
    _PLUS_OP = 268,
    _MINUS_OP = 269,
    _MULTIPLE_OP = 270,
    _DIVIDE_OP = 271,
    _MODULE_OP = 272,
    _PLUS_ASSIGN_OP = 273,
    _MINUS_ASSIGN_OP = 274,
    _MULTI_ASSIGN_OP = 275,
    _DIVIDE_ASSIGN_OP = 276,
    _MODULE_ASSIGN_OP = 277,
    _SELF_PLUS_UNARY_OP = 278,
    _SELF_MINUS_UNARY_OP = 279,
    _LARGER_OP = 280,
    _LESS_OP = 281,
    _LARGER_EQUAL_OP = 282,
    _LESS_EQUAL_OP = 283,
    _NOT_EQUAL_OP = 284,
    _EQUAL_OP = 285,
    _LEFT_BRACKET = 286,
    _RIGHT_BRACKET = 287,
    _LEFT_BRACE = 288,
    _RIGHT_BRACE = 289,
    _END_DIVIDED_CHAR = 290,
    _COMMA_DIVIDED_CHAR = 291,
    _COMMENT_LEFT = 292,
    _COMMENT_RIGHT = 293,
    _LEFT_SELF_PLUS_UNARY_OP = 294,
    _LEFT_SELF_MINUS_UNARY_OP = 295,
    _RIGHT_SELF_PLUS_UNARY_OP = 296,
    _RIGHT_SELF_MINUS_UNARY_OP = 297,
    _UMINUS_OP = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "main.y" /* yacc.c:1915  */

    int int_value;
    char name_value[32];
    float float_value;
    struct tree_node * _tree_node;

#line 105 "main.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MAIN_TAB_H_INCLUDED  */
