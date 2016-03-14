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

  case 18:
#line 216 "lury.ypp"
    {
		(yyval.ast) = (yysemantic_stack_[(2) - (1)].ast);
	;}
    break;

  case 19:
#line 220 "lury.ypp"
    {
		(yyval.ast) = (yysemantic_stack_[(4) - (3)].ast);
	;}
    break;

  case 21:
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

  case 22:
#line 242 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST((yysemantic_stack_[(4) - (2)].ast), (yysemantic_stack_[(4) - (4)].ast));
	;}
    break;

  case 23:
#line 246 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST((yysemantic_stack_[(5) - (2)].ast), (yysemantic_stack_[(5) - (4)].ast), (yysemantic_stack_[(5) - (5)].ast));
	;}
    break;

  case 24:
#line 252 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST((yysemantic_stack_[(4) - (2)].ast), (yysemantic_stack_[(4) - (4)].ast));
	;}
    break;

  case 25:
#line 256 "lury.ypp"
    {
		(yyval.ast) = new IfStatementAST((yysemantic_stack_[(5) - (2)].ast), (yysemantic_stack_[(5) - (4)].ast), (yysemantic_stack_[(5) - (5)].ast));
	;}
    break;

  case 27:
#line 263 "lury.ypp"
    {
		(yyval.ast) = (yysemantic_stack_[(3) - (3)].ast);
	;}
    break;

  case 28:
#line 273 "lury.ypp"
    {
		(yyval.ast) = new WhileStatementAST((yysemantic_stack_[(4) - (2)].ast), (yysemantic_stack_[(4) - (4)].ast), NULL);
	;}
    break;

  case 29:
#line 277 "lury.ypp"
    {
		(yyval.ast) = new WhileStatementAST((yysemantic_stack_[(5) - (2)].ast), (yysemantic_stack_[(5) - (4)].ast), (yysemantic_stack_[(5) - (5)].ast));
	;}
    break;

  case 30:
#line 299 "lury.ypp"
    {
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(4) - (2)].ast);
			(yyval.ast) = new FunctionStatementAST(ident->getValue(), new list<string>, (yysemantic_stack_[(4) - (4)].ast));
	;}
    break;

  case 31:
#line 304 "lury.ypp"
    {
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(6) - (2)].ast);
			(yyval.ast) = new FunctionStatementAST(ident->getValue(), new list<string>, (yysemantic_stack_[(6) - (6)].ast));
	;}
    break;

  case 32:
#line 309 "lury.ypp"
    {
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(7) - (2)].ast);
			(yyval.ast) = new FunctionStatementAST(ident->getValue(), (yysemantic_stack_[(7) - (4)].param_list), (yysemantic_stack_[(7) - (7)].ast));
	;}
    break;

  case 35:
#line 327 "lury.ypp"
    {
			list<string> *l = new list<string>();
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(1) - (1)].string_value);
			l->push_back(ident->getValue());
			(yyval.param_list) = l;
	;}
    break;

  case 36:
#line 334 "lury.ypp"
    {
			list<string> *l = (yysemantic_stack_[(3) - (1)].param_list);
			IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(3) - (3)].string_value);
			l->push_back(ident->getValue());
			(yyval.param_list) = l;
	;}
    break;

  case 42:
#line 394 "lury.ypp"
    {
		(yyval.ast) = new ReturnStatementAST(new NilLitAST());
	;}
    break;

  case 43:
#line 398 "lury.ypp"
    {
		(yyval.ast) = new ReturnStatementAST((yysemantic_stack_[(2) - (2)].ast));
	;}
    break;

  case 44:
#line 404 "lury.ypp"
    {
		(yyval.ast) = new BreakStatementAST();
	;}
    break;

  case 45:
#line 410 "lury.ypp"
    {
		(yyval.ast) = new ContinueStatementAST();
	;}
    break;

  case 46:
#line 431 "lury.ypp"
    {
		(yyval.ast) = new IdentifierAST(*(yysemantic_stack_[(1) - (1)].string_value));
	;}
    break;

  case 49:
#line 451 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpEqual);
	;}
    break;

  case 50:
#line 455 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpAdd);
	;}
    break;

  case 51:
#line 459 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpSub);
	;}
    break;

  case 52:
#line 463 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpMul);
	;}
    break;

  case 53:
#line 467 "lury.ypp"
    {
		(yyval.ast) = new BinaryAssignAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpDiv);
	;}
    break;

  case 57:
#line 491 "lury.ypp"
    {
		list<string> params;
		IdentifierAST *ident = (IdentifierAST *)(yysemantic_stack_[(5) - (2)].string_value);
		params.push_back(ident->getValue());
		(yyval.ast) = new LambdaLitAST(params, (yysemantic_stack_[(5) - (4)].ast));
	;}
    break;

  case 58:
#line 498 "lury.ypp"
    {
		list<string> params;
		(yyval.ast) = new LambdaLitAST(params, (yysemantic_stack_[(4) - (3)].ast));
	;}
    break;

  case 59:
#line 503 "lury.ypp"
    {
		list<string> params = *(yysemantic_stack_[(5) - (2)].param_list);
		delete (yysemantic_stack_[(5) - (2)].param_list);
		(yyval.ast) = new LambdaLitAST(params, (yysemantic_stack_[(5) - (4)].ast));
	;}
    break;

  case 61:
#line 512 "lury.ypp"
    {
		(yyval.ast) = NULL;
	;}
    break;

  case 66:
#line 535 "lury.ypp"
    {
		(yyval.ast) = new NotAST((yysemantic_stack_[(2) - (2)].ast));
	;}
    break;

  case 67:
#line 539 "lury.ypp"
    {
		(yyval.ast) = new NotAST((yysemantic_stack_[(2) - (2)].ast));
	;}
    break;

  case 69:
#line 546 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpGreater);
	;}
    break;

  case 70:
#line 550 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpLess);
	;}
    break;

  case 71:
#line 554 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpLessOrEqual);
	;}
    break;

  case 72:
#line 558 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpGreaterOrEqual);
	;}
    break;

  case 73:
#line 562 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpEqual);
	;}
    break;

  case 80:
#line 602 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpAdd);
	;}
    break;

  case 81:
#line 606 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpSub);
	;}
    break;

  case 83:
#line 614 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpMul);
	;}
    break;

  case 84:
#line 619 "lury.ypp"
    {
		(yyval.ast) = new BinaryOpAST((yysemantic_stack_[(3) - (1)].ast), (yysemantic_stack_[(3) - (3)].ast), OpDiv);
	;}
    break;

  case 89:
#line 646 "lury.ypp"
    {
			list<AST *> empty;
			(yyval.ast) = new CallAST((yysemantic_stack_[(3) - (1)].ast), empty);
	;}
    break;

  case 90:
#line 651 "lury.ypp"
    {
			(yyval.ast) = new CallAST((yysemantic_stack_[(4) - (1)].ast), *(yysemantic_stack_[(4) - (3)].arg_list));
	;}
    break;

  case 91:
#line 659 "lury.ypp"
    {
			list<AST *> *args = new list<AST *>();
			args->push_back((yysemantic_stack_[(1) - (1)].ast));
			(yyval.arg_list) = args;
	;}
    break;

  case 92:
#line 665 "lury.ypp"
    {
			list<AST *> *args = (yysemantic_stack_[(3) - (1)].arg_list);
			args->push_back((yysemantic_stack_[(3) - (3)].ast));
			(yyval.arg_list) = args;
	;}
    break;

  case 96:
#line 682 "lury.ypp"
    {
		(yyval.ast) = new BooleanLitAST(true);
	;}
    break;

  case 97:
#line 686 "lury.ypp"
    {
		(yyval.ast) = new BooleanLitAST(false);
	;}
    break;

  case 98:
#line 690 "lury.ypp"
    {
		(yyval.ast) = new NilLitAST();
	;}
    break;

  case 99:
#line 696 "lury.ypp"
    {
	  (yyval.ast) = (yysemantic_stack_[(3) - (2)].ast);
	;}
    break;

  case 100:
#line 703 "lury.ypp"
    {
		(yyval.ast) = new StringLitAST(*(yysemantic_stack_[(1) - (1)].string_value));
	;}
    break;

  case 101:
#line 709 "lury.ypp"
    {
		(yyval.ast) = new ImaginaryNumberLitAST((yysemantic_stack_[(1) - (1)].double_value));
	;}
    break;

  case 102:
#line 713 "lury.ypp"
    {
		(yyval.ast) = new FloatNumberLitAST((yysemantic_stack_[(1) - (1)].double_value));
	;}
    break;

  case 103:
#line 717 "lury.ypp"
    {
		(yyval.ast) = new IntegerLitAST((yysemantic_stack_[(1) - (1)].int_value));
	;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 891 "lury.tab.cpp"
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
  const signed char Parser::yypact_ninf_ = -123;
  const short int
  Parser::yypact_[] =
  {
         4,  -123,  -123,  -123,   -29,  -123,   219,  -123,   249,   219,
    -123,   219,  -123,  -123,  -123,  -123,  -123,   -63,   249,   219,
      45,     4,  -123,  -123,    48,  -123,  -123,  -123,  -123,   -66,
    -123,  -123,  -123,  -123,  -123,  -123,   -60,  -123,  -123,  -123,
    -123,  -123,  -123,  -123,   -46,  -123,  -123,  -123,  -123,  -123,
     -80,   -64,  -123,  -123,  -123,   -61,  -123,  -123,   -78,  -123,
     -50,  -123,  -123,   -42,   189,   -51,   -85,  -123,  -123,   -47,
    -123,  -123,  -123,   141,  -123,   219,   219,   219,   219,   219,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   171,
      14,   -65,    14,    14,  -123,  -123,   -45,   189,   -29,   189,
    -123,   -66,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,
    -123,  -123,   -64,   -64,  -123,  -123,  -123,  -123,   -99,  -123,
      79,    94,  -123,   -10,  -123,   -96,    47,    83,  -123,   -12,
    -123,    -9,  -123,   219,  -123,   111,  -123,    14,     6,   219,
       8,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    93,  -123,
      14,     9,    14,  -123,  -123,  -123,    14,  -123,    47,  -123
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         2,     7,    44,    45,     0,    97,     0,    98,     0,    42,
      96,     0,    46,   101,   102,   103,   100,     0,     0,     0,
       0,     3,     4,     6,     0,     9,    15,    16,    17,    10,
      37,    38,    39,    40,    94,    41,    47,    48,    54,    55,
      56,    62,    63,    64,    65,    68,    74,    75,    76,    77,
      78,    79,    82,    85,    86,    87,    88,    95,     0,    33,
       0,    66,    43,     0,     0,    35,     0,    34,    67,     0,
       1,     5,     8,    12,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    60,     0,     0,     0,     0,
      99,    13,    50,    51,    52,    53,    49,    71,    72,    73,
      70,    69,    80,    81,    83,    84,    89,    93,     0,    91,
       0,     0,    30,     0,    35,     0,    22,    28,    58,     0,
      36,     0,    14,     0,    90,     0,    18,     0,     0,     0,
       0,    23,    26,    29,    57,    59,    92,    20,     0,    31,
       0,     0,     0,    19,    21,    32,     0,    27,    24,    25
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  Parser::yypgoto_[] =
  {
      -123,  -123,  -123,   100,  -122,     0,    21,  -123,   -57,  -123,
    -123,   -34,    10,  -123,  -123,  -123,   -82,    36,    63,  -123,
    -123,  -123,  -123,    -2,    -5,  -123,    27,  -123,  -123,   -87,
    -123,  -123,  -123,    34,  -123,    91,  -123,  -123,  -123,  -123,
    -123,     5,    22,  -123,  -123,  -123,  -123,     7,  -123,  -123
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,    20,    21,    22,    23,   121,    74,    25,   122,   148,
      26,   141,   142,    27,    28,    58,    65,    66,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    96,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,   118,   119,    56,    57
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        24,    60,    59,    12,    62,    12,    63,     1,   133,   124,
     129,    98,   131,   147,    69,    67,   130,   120,    75,     2,
      76,    24,    98,     3,     4,    77,   154,   134,    78,     2,
     138,     5,    90,     3,     6,   126,   127,    85,    86,    12,
      99,     5,    61,     7,     8,    70,    80,    91,    79,    81,
      82,    72,    68,     7,     8,     9,    87,    88,    73,    95,
      92,   123,    64,    10,    89,     9,    83,    84,    93,    11,
     139,   140,    12,    10,    97,    13,    14,    15,    16,   100,
     149,   128,    12,   135,   117,    13,    14,    15,    16,    67,
     112,   113,    95,   155,    95,   157,    67,   136,   153,   158,
     137,    17,   102,   103,   104,   105,   106,   140,     2,   114,
     115,    17,     3,     4,   144,    18,   150,   145,   152,   156,
       5,    71,   132,     6,   159,    18,     2,   125,   117,    19,
       3,     4,     7,     8,   151,    24,   101,   143,     5,    19,
     146,     6,     0,     0,     9,     0,     0,     0,    24,     0,
       7,     8,    10,     0,     0,     0,     2,     0,    11,     0,
       3,    12,     9,     0,    13,    14,    15,    16,     5,     0,
      10,   107,   108,   109,   110,   111,    11,     0,     0,    12,
       7,     8,    13,    14,    15,    16,     0,     0,     0,     0,
      17,     0,     9,     0,     0,     0,     0,     0,     5,     0,
      10,     0,     0,     0,    18,     0,     0,     0,    17,    12,
       7,     8,    13,    14,    15,    16,     5,     0,    19,     0,
       0,     0,    18,     0,     0,     0,     0,     0,     7,     8,
      10,     0,     0,    94,     0,     0,    19,     0,    17,    12,
       0,     0,    13,    14,    15,    16,     5,     0,    10,     0,
       0,     0,    18,     0,     0,     0,     0,    12,     7,     8,
      13,    14,    15,    16,     0,     0,    19,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     5,     0,    10,     0,
       0,     0,    18,     0,     0,     0,    17,    12,     7,     8,
      13,    14,    15,    16,     5,     0,    19,   116,     0,     0,
      18,     0,     0,     0,     0,     0,     7,     0,    10,     0,
       0,     0,     0,     0,    19,     0,    17,    12,     0,     0,
      13,    14,    15,    16,     0,     0,    10,     0,     0,     0,
      18,     0,     0,     0,     0,    12,     0,     0,    13,    14,
      15,    16,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
         0,     6,     4,    68,     9,    68,    11,     3,   107,    91,
      97,   107,    99,   135,    19,    17,    98,     3,    78,    15,
      80,    21,   107,    19,    20,    85,   148,   126,    88,    15,
     126,    27,   110,    19,    30,    92,    93,   117,   118,    68,
     125,    27,     8,    39,    40,     0,    92,   125,   108,    95,
      96,     3,    18,    39,    40,    51,   120,   121,   124,    64,
     110,   126,   125,    59,   125,    51,   112,   113,   110,    65,
      23,    24,    68,    59,   125,    71,    72,    73,    74,   126,
     137,   126,    68,     4,    89,    71,    72,    73,    74,    91,
      85,    86,    97,   150,    99,   152,    98,     3,     5,   156,
     110,    97,    75,    76,    77,    78,    79,    24,    15,    87,
      88,    97,    19,    20,   126,   111,   110,   126,   110,   110,
      27,    21,   101,    30,   158,   111,    15,    91,   133,   125,
      19,    20,    39,    40,   139,   135,    73,   127,    27,   125,
     133,    30,    -1,    -1,    51,    -1,    -1,    -1,   148,    -1,
      39,    40,    59,    -1,    -1,    -1,    15,    -1,    65,    -1,
      19,    68,    51,    -1,    71,    72,    73,    74,    27,    -1,
      59,    80,    81,    82,    83,    84,    65,    -1,    -1,    68,
      39,    40,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      97,    -1,    51,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      59,    -1,    -1,    -1,   111,    -1,    -1,    -1,    97,    68,
      39,    40,    71,    72,    73,    74,    27,    -1,   125,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    39,    40,
      59,    -1,    -1,    44,    -1,    -1,   125,    -1,    97,    68,
      -1,    -1,    71,    72,    73,    74,    27,    -1,    59,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    68,    39,    40,
      71,    72,    73,    74,    -1,    -1,   125,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    59,    -1,
      -1,    -1,   111,    -1,    -1,    -1,    97,    68,    39,    40,
      71,    72,    73,    74,    27,    -1,   125,   126,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    39,    -1,    59,    -1,
      -1,    -1,    -1,    -1,   125,    -1,    97,    68,    -1,    -1,
      71,    72,    73,    74,    -1,    -1,    59,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     3,    15,    19,    20,    27,    30,    39,    40,    51,
      59,    65,    68,    71,    72,    73,    74,    97,   111,   125,
     128,   129,   130,   131,   132,   134,   137,   140,   141,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   175,   176,   142,   150,
     151,   160,   151,   151,   125,   143,   144,   150,   160,   151,
       0,   130,     3,   124,   133,    78,    80,    85,    88,   108,
      92,    95,    96,   112,   113,   117,   118,   120,   121,   125,
     110,   125,   110,   110,    44,   151,   156,   125,   107,   125,
     126,   145,   153,   153,   153,   153,   153,   162,   162,   162,
     162,   162,   168,   168,   169,   169,   126,   151,   173,   174,
       3,   132,   135,   126,   143,   144,   135,   135,   126,   156,
     143,   156,   133,   107,   126,     4,     3,   110,   126,    23,
      24,   138,   139,   139,   126,   126,   174,   131,   136,   135,
     110,   151,   110,     5,   131,   135,   110,   135,   135,   138
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
     132,   132,   133,   133,   133,   134,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   138,   139,   140,   140,
     141,   141,   141,   142,   143,   144,   144,   145,   145,   145,
     145,   146,   147,   147,   148,   149,   150,   151,   152,   152,
     152,   152,   152,   152,   153,   154,   155,   155,   155,   155,
     156,   156,   157,   158,   159,   160,   160,   160,   161,   161,
     161,   161,   161,   161,   162,   163,   164,   165,   166,   167,
     167,   167,   168,   168,   168,   169,   170,   171,   172,   172,
     172,   173,   173,   174,   175,   175,   175,   175,   175,   175,
     176,   176,   176,   176
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     0,     1,     1,     2,     1,     1,     2,     1,
       1,     2,     1,     2,     3,     1,     1,     1,     2,     4,
       1,     2,     4,     5,     4,     5,     1,     3,     4,     5,
       4,     6,     7,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     5,     4,     5,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1
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
  "elif_statements", "else_statement", "while_statement",
  "function_definition", "function_name", "parameter", "parameter_list",
  "simple_statement", "expression_statement", "return_statement",
  "break_statement", "continue_statement", "identifier_all", "expression",
  "assignment_expression", "comma_expression", "generator_expression",
  "lambda_expression", "lambda_body", "conditional_expression",
  "bool_or_expression", "bool_and_expression", "bool_not_expression",
  "comparison_expression", "range_expression", "or_expression",
  "xor_expression", "and_expression", "shift_expression",
  "addition_expression", "multiplication_expression", "unary_expression",
  "power_expression", "callref_expression", "postfix_expression",
  "argument_list", "argument", "primary", "literal", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
       128,     0,    -1,    -1,   129,    -1,   130,    -1,   129,   130,
      -1,   131,    -1,     3,    -1,   132,     3,    -1,   134,    -1,
     145,    -1,   145,   133,    -1,   124,    -1,   124,   145,    -1,
     124,   145,   133,    -1,   137,    -1,   140,    -1,   141,    -1,
     132,     3,    -1,     3,     4,   136,     5,    -1,   131,    -1,
     136,   131,    -1,    30,   151,   110,   135,    -1,    30,   151,
     110,   135,   138,    -1,    23,   151,   110,   135,    -1,    23,
     151,   110,   135,   138,    -1,   139,    -1,    24,   110,   135,
      -1,    65,   151,   110,   135,    -1,    65,   151,   110,   135,
     139,    -1,    20,   142,   110,   135,    -1,    20,   142,   125,
     126,   110,   135,    -1,    20,   142,   125,   144,   126,   110,
     135,    -1,   150,    -1,   150,    -1,   143,    -1,   144,   107,
     143,    -1,   146,    -1,   147,    -1,   148,    -1,   149,    -1,
     151,    -1,    51,    -1,    51,   151,    -1,    15,    -1,    19,
      -1,    68,    -1,   152,    -1,   153,    -1,   152,   108,   153,
      -1,   152,    78,   153,    -1,   152,    80,   153,    -1,   152,
      85,   153,    -1,   152,    88,   153,    -1,   154,    -1,   155,
      -1,   157,    -1,    97,   143,   125,   156,   126,    -1,    97,
     125,   156,   126,    -1,    97,   144,   125,   156,   126,    -1,
     151,    -1,    44,    -1,   158,    -1,   159,    -1,   160,    -1,
     161,    -1,    40,   160,    -1,   111,   160,    -1,   162,    -1,
     161,   113,   162,    -1,   161,   112,   162,    -1,   161,    92,
     162,    -1,   161,    95,   162,    -1,   161,    96,   162,    -1,
     163,    -1,   164,    -1,   165,    -1,   166,    -1,   167,    -1,
     168,    -1,   167,   117,   168,    -1,   167,   118,   168,    -1,
     169,    -1,   168,   120,   169,    -1,   168,   121,   169,    -1,
     170,    -1,   171,    -1,   172,    -1,   175,    -1,   172,   125,
     126,    -1,   172,   125,   173,   126,    -1,   174,    -1,   173,
     107,   174,    -1,   151,    -1,   150,    -1,   176,    -1,    59,
      -1,    27,    -1,    39,    -1,   125,   151,   126,    -1,    74,
      -1,    71,    -1,    72,    -1,    73,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     4,     6,     8,    11,    13,    15,    18,
      20,    22,    25,    27,    30,    34,    36,    38,    40,    43,
      48,    50,    53,    58,    64,    69,    75,    77,    81,    86,
      92,    97,   104,   112,   114,   116,   118,   122,   124,   126,
     128,   130,   132,   134,   137,   139,   141,   143,   145,   147,
     151,   155,   159,   163,   167,   169,   171,   173,   179,   184,
     190,   192,   194,   196,   198,   200,   202,   205,   208,   210,
     214,   218,   222,   226,   230,   232,   234,   236,   238,   240,
     242,   246,   250,   252,   256,   260,   262,   264,   266,   268,
     272,   277,   279,   283,   285,   287,   289,   291,   293,   295,
     299,   301,   303,   305
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   128,   128,   132,   139,   140,   154,   155,   161,   165,
     168,   169,   183,   187,   191,   205,   207,   210,   215,   219,
     226,   227,   241,   245,   251,   255,   259,   262,   272,   276,
     298,   303,   308,   318,   323,   326,   333,   378,   381,   382,
     383,   390,   393,   397,   403,   409,   430,   446,   449,   450,
     454,   458,   462,   466,   481,   485,   489,   490,   497,   502,
     510,   511,   517,   523,   528,   533,   534,   538,   544,   545,
     549,   553,   557,   561,   578,   583,   587,   591,   595,   600,
     601,   605,   612,   613,   618,   625,   633,   637,   641,   645,
     650,   658,   664,   672,   679,   680,   681,   685,   689,   695,
     702,   708,   712,   716
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
  const int Parser::yylast_ = 392;
  const int Parser::yynnts_ = 50;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 70;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 127;

  const unsigned int Parser::yyuser_token_number_max_ = 361;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace lury

#line 763 "lury.ypp"


void lury::Parser::error(const Parser::location_type& l, const std::string& m) {
	driver.error(l, m);
}

