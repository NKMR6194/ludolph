/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

// Take the name prefix into account.
#define yylex   lurylex

#include "lury.tab.hpp"

/* User implementation prologue.  */
#line 112 "lury.ypp"


#include "include/driver.hpp"
#include "include/scanner.hpp"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc.  */
#line 57 "lury.tab.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace lury
{
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  Parser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    #line 27 "lury.ypp"
{
	yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 555 of yacc.c.  */
#line 293 "lury.tab.cpp"
    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
      yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:
#line 128 "lury.ypp"
    {
		(yyval.ast) = new CompoundAST();
		driver.ast = (yyval.ast);
	;}
    break;

  case 3:
#line 133 "lury.ypp"
    {
		driver.ast = (yysemantic_stack_[(1) - (1)].ast);
		(yyval.ast) = (yysemantic_stack_[(1) - (1)].ast);
	;}
    break;

  case 5:
#line 141 "lury.ypp"
    {
		CompoundAST *ast;
		if ((yysemantic_stack_[(2) - (1)].ast)->getValueID() == CompoundID) {
			ast = (CompoundAST *)(yysemantic_stack_[(2) - (1)].ast);
		}
		else {
			ast = new CompoundAST((yysemantic_stack_[(2) - (1)].ast));
		}
		ast->push_back((yysemantic_stack_[(2) - (2)].ast));
		(yyval.ast) = ast;
	;}
    break;

  case 7:
#line 156 "lury.ypp"
    {
		(yyval.ast) = new CompoundAST();
	;}
    break;

  case 8:
#line 162 "lury.ypp"
    {
		(yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
	;}
    break;

  case 11:
#line 170 "lury.ypp"
    {
		CompoundAST *ast;
		if ((yysemantic_stack_[(2) - (2)].ast)->getValueID() == CompoundID) {
			ast =  (CompoundAST *)(yysemantic_stack_[(2) - (2)].ast);
		}
		else {
			ast = new CompoundAST((yysemantic_stack_[(2) - (2)].ast));
		}
		ast->push_front((yysemantic_stack_[(2) - (1)].ast));
		(yyval.ast) = ast;
	;}
    break;

  case 12:
#line 184 "lury.ypp"
    {
		(yyval.ast) = new CompoundAST();
	;}
    break;

  case 13:
#line 188 "lury.ypp"
    {
		(yyval.ast) = (yysemantic_stack_[(2) - (2)].ast);
	;}
    break;

  case 14:
#line 192 "lury.ypp"
    {
		CompoundAST *ast;
		if ((yysemantic_stack_[(3) - (3)].ast)->getValueID() == CompoundID) {
			ast = (CompoundAST *)(yysemantic_stack_[(3) - (3)].ast);
		}
		else {
			ast = new CompoundAST((yysemantic_stack_[(3) - (3)].ast));
		}
		ast->push_front((yysemantic_stack_[(3) - (2)].ast));
		(yyval.ast) = ast;
	;}
    break;

  case 19:
#line 216 "lury.ypp"
    {
		(yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
	;}
    break;

  case 20:
#line 220 "lury.ypp"
    {
		(yyval.ast) = (yysemantic_stack_[(4) - (3)].ast);
	;}
    break;

  case 22:
#line 228 "lury.ypp"
    {
		CompoundAST *ast;
		if ((yysemantic_stack_[(2) - (1)].ast)->getValueID() == CompoundID) {
			ast = (CompoundAST *)(yysemantic_stack_[(2) - (1)].ast);
		}
		else {
			ast = new CompoundAST((yysemantic_stack_[(2) - (1)].ast));
		}
		ast->push_back((yysemantic_stack_[(2) - (2)].ast));
		(yyval.ast) = ast
	;}
    break;

  case 23:
#line 242 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST((yysemantic_stack_[(4) - (2)].ast), (yysemantic_stack_[(4) - (4)].ast));
	;}
    break;

  case 24:
#line 246 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST((yysemantic_stack_[(5) - (2)].ast), (yysemantic_stack_[(5) - (4)].ast), (yysemantic_stack_[(5) - (5)].ast));
	;}
    break;

  case 25:
#line 252 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST((yysemantic_stack_[(4) - (2)].ast), (yysemantic_stack_[(4) - (4)].ast));
	;}
    break;

  case 26:
#line 256 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST((yysemantic_stack_[(5) - (2)].ast), (yysemantic_stack_[(5) - (4)].ast), (yysemantic_stack_[(5) - (5)].ast));
	;}
    break;

  case 28:
#line 263 "lury.ypp"
    {
		(yyval.ast) = (yysemantic_stack_[(3) - (3)].ast);
	;}
    break;

  case 29:
#line 269 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST(new NotAST((yysemantic_stack_[(4) - (2)].ast)), (yysemantic_stack_[(4) - (4)].ast));
	;}
    break;

  case 30:
#line 273 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST(new NotAST((yysemantic_stack_[(5) - (2)].ast)), (yysemantic_stack_[(5) - (4)].ast), (yysemantic_stack_[(5) - (5)].ast));
	;}
    break;

  case 31:
#line 279 "lury.ypp"
    {
		(yyval.ast) = new WhileStatementAST((yysemantic_stack_[(4) - (2)].ast), (yysemantic_stack_[(4) - (4)].ast), NULL);
	;}
    break;

  case 32:
#line 283 "lury.ypp"
    {
		(yyval.ast) = new WhileStatementAST((yysemantic_stack_[(5) - (2)].ast), (yysemantic_stack_[(5) - (4)].ast), (yysemantic_stack_[(5) - (5)].ast));
	;}
    break;

  case 33:
#line 305 "lury.ypp"
    {
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(4) - (2)].ast);
			(yyval.ast) = new FunctionStatementAST(ident->getValue(), new list<string>, (yysemantic_stack_[(4) - (4)].ast));
	;}
    break;

  case 34:
#line 310 "lury.ypp"
    {
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(6) - (2)].ast);
			(yyval.ast) = new FunctionStatementAST(ident->getValue(), new list<string>, (yysemantic_stack_[(6) - (6)].ast));
	;}
    break;

  case 35:
#line 315 "lury.ypp"
    {
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(7) - (2)].ast);
			(yyval.ast) = new FunctionStatementAST(ident->getValue(), (yysemantic_stack_[(7) - (4)].param_list), (yysemantic_stack_[(7) - (7)].ast));
	;}
    break;

  case 38:
#line 333 "lury.ypp"
    {
			list<string> *l = new list<string>();
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(1) - (1)].string_value);
			l->push_back(ident->getValue());
			(yyval.param_list) = l;
	;}
    break;

  case 39:
#line 340 "lury.ypp"
    {
			list<string> *l = (yysemantic_stack_[(3) - (1)].param_list);
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(3) - (3)].string_value);
			l->push_back(ident->getValue());
			(yyval.param_list) = l;
	;}
    break;

  case 45:
#line 400 "lury.ypp"
    {
		(yyval.ast) = new ReturnStatementAST(new NilLitAST());
	;}
    break;

  case 46:
#line 404 "lury.ypp"
    {
		(yyval.ast) = new ReturnStatementAST((yysemantic_stack_[(2) - (2)].ast));
	;}
    break;

  case 47:
#line 410 "lury.ypp"
    {
		(yyval.ast) = new BreakStatementAST();
	;}
    break;

  case 48:
#line 416 "lury.ypp"
    {
		(yyval.ast) = new ContinueStatementAST();
	;}
    break;

  case 49:
#line 437 "lury.ypp"
    {
		(yyval.ast) = new IdentifierAST(*(yysemantic_stack_[(1) - (1)].string_value));
	;}
    break;

  case 52:
#line 457 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpEqual);
	;}
    break;

  case 53:
#line 461 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpAdd);
	;}
    break;

  case 54:
#line 465 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpSub);
	;}
    break;

  case 55:
#line 469 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpMul);
	;}
    break;

  case 56:
#line 473 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpDiv);
	;}
    break;

  case 60:
#line 497 "lury.ypp"
    {
		list<string> params;
		IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(5) - (2)].string_value);
		params.push_back(ident->getValue());
		(yyval.ast) = new LambdaLitAST(params, (yysemantic_stack_[(5) - (4)].ast));
	;}
    break;

  case 61:
#line 504 "lury.ypp"
    {
		list<string> params;
		(yyval.ast) = new LambdaLitAST(params, (yysemantic_stack_[(4) - (3)].ast));
	;}
    break;

  case 62:
#line 509 "lury.ypp"
    {
		list<string> params = *(yysemantic_stack_[(5) - (2)].param_list);
		delete (yysemantic_stack_[(5) - (2)].param_list);
		(yyval.ast) = new LambdaLitAST(params, (yysemantic_stack_[(5) - (4)].ast));
	;}
    break;

  case 64:
#line 518 "lury.ypp"
    {
		(yyval.ast) = NULL;
	;}
    break;

  case 69:
#line 541 "lury.ypp"
    {
		(yyval.ast) = new NotAST((yysemantic_stack_[(2) - (2)].ast));
	;}
    break;

  case 70:
#line 545 "lury.ypp"
    {
		(yyval.ast) = new NotAST((yysemantic_stack_[(2) - (2)].ast));
	;}
    break;

  case 72:
#line 552 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpGreater);
	;}
    break;

  case 73:
#line 556 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpLess);
	;}
    break;

  case 74:
#line 560 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpLessOrEqual);
	;}
    break;

  case 75:
#line 564 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpGreaterOrEqual);
	;}
    break;

  case 76:
#line 568 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpEqual);
	;}
    break;

  case 77:
#line 572 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpNotEqual);
	;}
    break;

  case 84:
#line 612 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpAdd);
	;}
    break;

  case 85:
#line 616 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpSub);
	;}
    break;

  case 87:
#line 624 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpMul);
	;}
    break;

  case 88:
#line 629 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpDiv);
	;}
    break;

  case 93:
#line 656 "lury.ypp"
    {
			list<AST *> empty;
			(yyval.ast) = new CallAST((yysemantic_stack_[(3) - (1)].ast), empty);
	;}
    break;

  case 94:
#line 661 "lury.ypp"
    {
			(yyval.ast) = new CallAST((yysemantic_stack_[(4) - (1)].ast), *(yysemantic_stack_[(4) - (3)].arg_list));
	;}
    break;

  case 95:
#line 669 "lury.ypp"
    {
			list<AST *> *args = new list<AST *>();
			args->push_back((yysemantic_stack_[(1) - (1)].ast));
			(yyval.arg_list) = args;
	;}
    break;

  case 96:
#line 675 "lury.ypp"
    {
			list<AST *> *args = (yysemantic_stack_[(3) - (1)].arg_list);
			args->push_back((yysemantic_stack_[(3) - (3)].ast));
			(yyval.arg_list) = args;
	;}
    break;

  case 100:
#line 692 "lury.ypp"
    {
		(yyval.ast) = new BooleanLitAST(true);
	;}
    break;

  case 101:
#line 696 "lury.ypp"
    {
		(yyval.ast) = new BooleanLitAST(false);
	;}
    break;

  case 102:
#line 700 "lury.ypp"
    {
		(yyval.ast) = new NilLitAST();
	;}
    break;

  case 103:
#line 706 "lury.ypp"
    {
	  (yyval.ast) = (yysemantic_stack_[(3) - (2)].ast);
	;}
    break;

  case 104:
#line 713 "lury.ypp"
    {
		(yyval.ast) = new StringLitAST(*(yysemantic_stack_[(1) - (1)].string_value));
	;}
    break;

  case 105:
#line 719 "lury.ypp"
    {
		(yyval.ast) = new ImaginaryNumberLitAST((yysemantic_stack_[(1) - (1)].double_value));
	;}
    break;

  case 106:
#line 723 "lury.ypp"
    {
		(yyval.ast) = new FloatNumberLitAST((yysemantic_stack_[(1) - (1)].double_value));
	;}
    break;

  case 107:
#line 727 "lury.ypp"
    {
		(yyval.ast) = new IntegerLitAST((yysemantic_stack_[(1) - (1)].int_value));
	;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 912 "lury.tab.cpp"
	default: break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse look-ahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		   &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -102;
  const short int
  Parser::yypact_[] =
  {
        -1,  -102,  -102,  -102,   -44,  -102,   222,  -102,   238,   222,
    -102,   222,   222,  -102,  -102,  -102,  -102,  -102,   -65,   238,
     222,    32,    -1,  -102,  -102,    41,  -102,  -102,  -102,  -102,
    -102,   -55,  -102,  -102,  -102,  -102,  -102,  -102,   -68,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,   -61,  -102,  -102,  -102,
    -102,  -102,   -28,   -27,  -102,  -102,  -102,   -72,  -102,  -102,
     -82,  -102,   -54,  -102,  -102,   -51,   -34,   173,   -38,   -71,
    -102,  -102,   -26,  -102,  -102,  -102,   155,  -102,   222,   222,
     222,   222,   222,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   162,     6,   -63,     6,     6,     6,  -102,
    -102,   -24,   173,   -44,   173,  -102,   -55,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   -27,   -27,
    -102,  -102,  -102,  -102,   -96,  -102,    88,    95,  -102,     4,
    -102,   -84,    84,   103,   103,  -102,     8,  -102,    10,  -102,
     222,  -102,   113,  -102,     6,    34,   222,    39,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,    86,  -102,     6,    40,
       6,  -102,  -102,  -102,     6,  -102,    84,  -102
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         2,     7,    47,    48,     0,   101,     0,   102,     0,    45,
     100,     0,     0,    49,   105,   106,   107,   104,     0,     0,
       0,     0,     3,     4,     6,     0,     9,    15,    16,    17,
      18,    10,    40,    41,    42,    43,    98,    44,    50,    51,
      57,    58,    59,    65,    66,    67,    68,    71,    78,    79,
      80,    81,    82,    83,    86,    89,    90,    91,    92,    99,
       0,    36,     0,    69,    46,     0,     0,     0,    38,     0,
      37,    70,     0,     1,     5,     8,    12,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      63,     0,     0,     0,     0,   103,    13,    53,    54,    55,
      56,    52,    74,    75,    76,    77,    73,    72,    84,    85,
      87,    88,    93,    97,     0,    95,     0,     0,    33,     0,
      38,     0,    23,    29,    31,    61,     0,    39,     0,    14,
       0,    94,     0,    19,     0,     0,     0,     0,    24,    27,
      30,    32,    60,    62,    96,    21,     0,    34,     0,     0,
       0,    20,    22,    35,     0,    28,    25,    26
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
      -102,  -102,  -102,   133,  -101,     0,    56,  -102,   -49,  -102,
    -102,    -3,    -4,  -102,  -102,  -102,  -102,   -87,    66,    89,
    -102,  -102,  -102,  -102,     9,    -5,  -102,     3,  -102,  -102,
     -36,  -102,  -102,  -102,    67,  -102,    35,  -102,  -102,  -102,
    -102,  -102,    49,    55,  -102,  -102,  -102,  -102,    26,  -102,
    -102
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,    21,    22,    23,    24,   127,    77,    26,   128,   156,
      27,   148,   149,    28,    29,    30,    60,    68,    69,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
     101,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   124,   125,    58,
      59
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        25,    62,     1,    13,    64,    13,    65,    66,   130,   126,
      78,   140,    79,    61,     2,    72,   137,    80,     3,     4,
      81,     2,    25,   103,    13,     3,     5,    70,    94,     6,
     141,    83,    73,     5,    84,    85,   103,    86,     7,     8,
      82,   155,   145,    95,    75,     7,     8,   132,   133,   134,
       9,    87,    88,    93,   104,   162,    96,     9,    10,    97,
      67,    11,   100,   129,    12,    10,   136,    13,   138,    76,
      14,    15,    16,    17,    13,    63,    98,    14,    15,    16,
      17,   107,   108,   109,   110,   111,    71,   102,   123,    89,
      90,   161,   142,    91,    92,   157,    18,   100,   143,   100,
     105,     2,   135,    18,    70,     3,     4,   146,   147,   163,
      19,   165,    70,     5,   144,   166,     6,    19,   112,   113,
     114,   115,   116,   117,    20,     7,     8,   147,     2,   150,
     151,    20,     3,     4,   152,   123,   153,     9,   118,   119,
       5,   159,    25,     6,   158,    10,   120,   121,    11,   160,
     164,    12,     7,     8,    13,    74,    25,    14,    15,    16,
      17,   131,   139,   167,     9,   106,   154,     0,     0,     0,
       2,     0,    10,     0,     3,    11,     0,     0,    12,     0,
       0,    13,     5,    18,    14,    15,    16,    17,     0,     5,
       0,     0,     0,     0,     7,     8,     0,    19,     0,     0,
       5,     7,     8,     0,     0,     0,     9,     0,     0,     0,
      18,    20,     7,     8,    10,     0,     0,    99,     0,     0,
       0,    10,     0,    13,    19,     0,    14,    15,    16,    17,
      13,     0,    10,    14,    15,    16,    17,     0,    20,     0,
       0,    13,     0,     0,    14,    15,    16,    17,     0,     5,
       0,     0,    18,     0,     0,     0,     0,     0,     0,    18,
       0,     7,     8,     0,     0,     5,    19,     0,     0,     0,
      18,     0,     0,    19,     0,     0,     0,     7,     8,     0,
      20,    10,     0,     0,    19,     0,     0,    20,   122,     0,
      13,     5,     0,    14,    15,    16,    17,    10,    20,     0,
       0,     0,     0,     7,     0,     0,    13,     0,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,    13,    19,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,     6,     3,    68,     9,    68,    11,    12,    95,     3,
      78,   107,    80,     4,    15,    20,   103,    85,    19,    20,
      88,    15,    22,   107,    68,    19,    27,    18,   110,    30,
     126,    92,     0,    27,    95,    96,   107,    98,    39,    40,
     108,   142,   126,   125,     3,    39,    40,    96,    97,    98,
      51,   112,   113,   125,   125,   156,   110,    51,    59,   110,
     125,    62,    67,   126,    65,    59,   102,    68,   104,   124,
      71,    72,    73,    74,    68,     8,   110,    71,    72,    73,
      74,    78,    79,    80,    81,    82,    19,   125,    93,   117,
     118,     5,     4,   120,   121,   144,    97,   102,     3,   104,
     126,    15,   126,    97,    95,    19,    20,    23,    24,   158,
     111,   160,   103,    27,   110,   164,    30,   111,    83,    84,
      85,    86,    87,    88,   125,    39,    40,    24,    15,   133,
     134,   125,    19,    20,   126,   140,   126,    51,    89,    90,
      27,   146,   142,    30,   110,    59,    91,    92,    62,   110,
     110,    65,    39,    40,    68,    22,   156,    71,    72,    73,
      74,    95,   106,   166,    51,    76,   140,    -1,    -1,    -1,
      15,    -1,    59,    -1,    19,    62,    -1,    -1,    65,    -1,
      -1,    68,    27,    97,    71,    72,    73,    74,    -1,    27,
      -1,    -1,    -1,    -1,    39,    40,    -1,   111,    -1,    -1,
      27,    39,    40,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      97,   125,    39,    40,    59,    -1,    -1,    44,    -1,    -1,
      -1,    59,    -1,    68,   111,    -1,    71,    72,    73,    74,
      68,    -1,    59,    71,    72,    73,    74,    -1,   125,    -1,
      -1,    68,    -1,    -1,    71,    72,    73,    74,    -1,    27,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    39,    40,    -1,    -1,    27,   111,    -1,    -1,    -1,
      97,    -1,    -1,   111,    -1,    -1,    -1,    39,    40,    -1,
     125,    59,    -1,    -1,   111,    -1,    -1,   125,   126,    -1,
      68,    27,    -1,    71,    72,    73,    74,    59,   125,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,   111,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     3,    15,    19,    20,    27,    30,    39,    40,    51,
      59,    62,    65,    68,    71,    72,    73,    74,    97,   111,
     125,   128,   129,   130,   131,   132,   134,   137,   140,   141,
     142,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   176,   177,
     143,   151,   152,   161,   152,   152,   152,   125,   144,   145,
     151,   161,   152,     0,   130,     3,   124,   133,    78,    80,
      85,    88,   108,    92,    95,    96,    98,   112,   113,   117,
     118,   120,   121,   125,   110,   125,   110,   110,   110,    44,
     152,   157,   125,   107,   125,   126,   146,   154,   154,   154,
     154,   154,   163,   163,   163,   163,   163,   163,   169,   169,
     170,   170,   126,   152,   174,   175,     3,   132,   135,   126,
     144,   145,   135,   135,   135,   126,   157,   144,   157,   133,
     107,   126,     4,     3,   110,   126,    23,    24,   138,   139,
     139,   139,   126,   126,   175,   131,   136,   135,   110,   152,
     110,     5,   131,   135,   110,   135,   135,   138
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,    44,    61,    63,
      58,    33,    60,    62,   124,    94,    38,    43,    45,   126,
      42,    47,    37,    46,    59,    40,    41
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   133,   134,   134,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   138,   139,   140,
     140,   141,   141,   142,   142,   142,   143,   144,   145,   145,
     146,   146,   146,   146,   147,   148,   148,   149,   150,   151,
     152,   153,   153,   153,   153,   153,   153,   154,   155,   156,
     156,   156,   156,   157,   157,   158,   159,   160,   161,   161,
     161,   162,   162,   162,   162,   162,   162,   162,   163,   164,
     165,   166,   167,   168,   168,   168,   169,   169,   169,   170,
     171,   172,   173,   173,   173,   174,   174,   175,   176,   176,
     176,   176,   176,   176,   177,   177,   177,   177
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     1,     1,     2,     1,     1,     2,     1,
       1,     2,     1,     2,     3,     1,     1,     1,     1,     2,
       4,     1,     2,     4,     5,     4,     5,     1,     3,     4,
       5,     4,     5,     4,     6,     7,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     1,
       5,     4,     5,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     1,     3,     3,     1,
       1,     1,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "NewLine", "Indent", "Dedent",
  "IdentifierGet", "IdentifierSet", "IdentifierFile", "IdentifierLine",
  "IdentifierExit", "IdentifierSuccess", "IdentifierFailure",
  "KeywordAbstract", "KeywordAnd", "KeywordBreak", "KeywordCase",
  "KeywordCatch", "KeywordClass", "KeywordContinue", "KeywordDef",
  "KeywordDefault", "KeywordDelete", "KeywordElif", "KeywordElse",
  "KeywordEnum", "KeywordExtended", "KeywordFalse", "KeywordFinally",
  "KeywordFor", "KeywordIf", "KeywordImport", "KeywordIn",
  "KeywordInterface", "KeywordInvariant", "KeywordIs", "KeywordLazy",
  "KeywordNameof", "KeywordNew", "KeywordNil", "KeywordNot", "KeywordOr",
  "KeywordOut", "KeywordOverride", "KeywordPass", "KeywordPrivate",
  "KeywordProperty", "KeywordProtected", "KeywordPublic", "KeywordRef",
  "KeywordReflect", "KeywordReturn", "KeywordScope", "KeywordSealed",
  "KeywordStatic", "KeywordSuper", "KeywordSwitch", "KeywordThis",
  "KeywordThrow", "KeywordTrue", "KeywordTry", "KeywordUnittest",
  "KeywordUnless", "KeywordUntil", "KeywordVar", "KeywordWhile",
  "KeywordWith", "KeywordYield", "Identifier", "EmbedStringLiteral",
  "WysiwygStringLiteral", "ImaginaryNumber", "FloatNumber", "Integer",
  "StringLiteral", "RangeOpen", "RangeClose", "Increment", "AssignmentAdd",
  "Decrement", "AssignmentSub", "AnnotationReturn", "AssignmentConcat",
  "AssignmentPower", "Power", "AssignmentMultiply", "AssignmentIntDivide",
  "IntDivide", "AssignmentDivide", "AssignmentModulo",
  "AssignmentLeftShift", "LeftShift", "LessThan", "AssignmentRightShift",
  "RightShift", "MoreThan", "Equal", "Lambda", "NotEqual", "NotIn",
  "IsNot", "AndShort", "AssignmentAnd", "AssignmentXor", "OrShort",
  "AssignmentOr", "NilCoalesce", "','", "'='", "'?'", "':'", "'!'", "'<'",
  "'>'", "'|'", "'^'", "'&'", "'+'", "'-'", "'~'", "'*'", "'/'", "'%'",
  "'.'", "';'", "'('", "')'", "$accept", "program", "program_lines",
  "program_line", "statement", "statement_list", "simple_statements",
  "compound_statement", "suite", "statements", "if_statement",
  "elif_statements", "else_statement", "unless_statement",
  "while_statement", "function_definition", "function_name", "parameter",
  "parameter_list", "simple_statement", "expression_statement",
  "return_statement", "break_statement", "continue_statement",
  "identifier_all", "expression", "assignment_expression",
  "comma_expression", "generator_expression", "lambda_expression",
  "lambda_body", "conditional_expression", "bool_or_expression",
  "bool_and_expression", "bool_not_expression", "comparison_expression",
  "range_expression", "or_expression", "xor_expression", "and_expression",
  "shift_expression", "addition_expression", "multiplication_expression",
  "unary_expression", "power_expression", "callref_expression",
  "postfix_expression", "argument_list", "argument", "primary", "literal", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       128,     0,    -1,    -1,   129,    -1,   130,    -1,   129,   130,
      -1,   131,    -1,     3,    -1,   132,     3,    -1,   134,    -1,
     146,    -1,   146,   133,    -1,   124,    -1,   124,   146,    -1,
     124,   146,   133,    -1,   137,    -1,   140,    -1,   141,    -1,
     142,    -1,   132,     3,    -1,     3,     4,   136,     5,    -1,
     131,    -1,   136,   131,    -1,    30,   152,   110,   135,    -1,
      30,   152,   110,   135,   138,    -1,    23,   152,   110,   135,
      -1,    23,   152,   110,   135,   138,    -1,   139,    -1,    24,
     110,   135,    -1,    62,   152,   110,   135,    -1,    62,   152,
     110,   135,   139,    -1,    65,   152,   110,   135,    -1,    65,
     152,   110,   135,   139,    -1,    20,   143,   110,   135,    -1,
      20,   143,   125,   126,   110,   135,    -1,    20,   143,   125,
     145,   126,   110,   135,    -1,   151,    -1,   151,    -1,   144,
      -1,   145,   107,   144,    -1,   147,    -1,   148,    -1,   149,
      -1,   150,    -1,   152,    -1,    51,    -1,    51,   152,    -1,
      15,    -1,    19,    -1,    68,    -1,   153,    -1,   154,    -1,
     153,   108,   154,    -1,   153,    78,   154,    -1,   153,    80,
     154,    -1,   153,    85,   154,    -1,   153,    88,   154,    -1,
     155,    -1,   156,    -1,   158,    -1,    97,   144,   125,   157,
     126,    -1,    97,   125,   157,   126,    -1,    97,   145,   125,
     157,   126,    -1,   152,    -1,    44,    -1,   159,    -1,   160,
      -1,   161,    -1,   162,    -1,    40,   161,    -1,   111,   161,
      -1,   163,    -1,   162,   113,   163,    -1,   162,   112,   163,
      -1,   162,    92,   163,    -1,   162,    95,   163,    -1,   162,
      96,   163,    -1,   162,    98,   163,    -1,   164,    -1,   165,
      -1,   166,    -1,   167,    -1,   168,    -1,   169,    -1,   168,
     117,   169,    -1,   168,   118,   169,    -1,   170,    -1,   169,
     120,   170,    -1,   169,   121,   170,    -1,   171,    -1,   172,
      -1,   173,    -1,   176,    -1,   173,   125,   126,    -1,   173,
     125,   174,   126,    -1,   175,    -1,   174,   107,   175,    -1,
     152,    -1,   151,    -1,   177,    -1,    59,    -1,    27,    -1,
      39,    -1,   125,   152,   126,    -1,    74,    -1,    71,    -1,
      72,    -1,    73,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     6,     8,    11,    13,    15,    18,
      20,    22,    25,    27,    30,    34,    36,    38,    40,    42,
      45,    50,    52,    55,    60,    66,    71,    77,    79,    83,
      88,    94,    99,   105,   110,   117,   125,   127,   129,   131,
     135,   137,   139,   141,   143,   145,   147,   150,   152,   154,
     156,   158,   160,   164,   168,   172,   176,   180,   182,   184,
     186,   192,   197,   203,   205,   207,   209,   211,   213,   215,
     218,   221,   223,   227,   231,   235,   239,   243,   247,   249,
     251,   253,   255,   257,   259,   263,   267,   269,   273,   277,
     279,   281,   283,   285,   289,   294,   296,   300,   302,   304,
     306,   308,   310,   312,   316,   318,   320,   322
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   128,   128,   132,   139,   140,   154,   155,   161,   165,
     168,   169,   183,   187,   191,   205,   206,   207,   210,   215,
     219,   226,   227,   241,   245,   251,   255,   259,   262,   268,
     272,   278,   282,   304,   309,   314,   324,   329,   332,   339,
     384,   387,   388,   389,   396,   399,   403,   409,   415,   436,
     452,   455,   456,   460,   464,   468,   472,   487,   491,   495,
     496,   503,   508,   516,   517,   523,   529,   534,   539,   540,
     544,   550,   551,   555,   559,   563,   567,   571,   588,   593,
     597,   601,   605,   610,   611,   615,   622,   623,   628,   635,
     643,   647,   651,   655,   660,   668,   674,   682,   689,   690,
     691,   695,   699,   705,   712,   718,   722,   726
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   111,     2,     2,     2,   122,   116,     2,
     125,   126,   120,   117,   107,   118,   123,   121,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   110,   124,
     112,   108,   113,   109,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   115,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   114,     2,   119,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 389;
  const int Parser::yynnts_ = 51;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 73;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 127;

  const unsigned int Parser::yyuser_token_number_max_ = 361;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace lury

#line 773 "lury.ypp"


void lury::Parser::error(const Parser::location_type& l, const std::string& m) {
	driver.error(l, m);
}

