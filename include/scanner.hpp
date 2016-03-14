#ifndef LUDOLPH_SCANNER_HPP
#define LUDOLPH_SCANNER_HPP

#ifndef YY_DECL

#define YY_DECL						\
lury::Parser::token_type				\
lury::Scanner::lex(					\
	lury::Parser::semantic_type* yylval,		\
	lury::Parser::location_type* yylloc		\
)
#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer LuryFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif

#include "../lury.tab.hpp"

namespace lury {

	class Scanner : public LuryFlexLexer {
	public:
		Scanner(std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0);
		virtual ~Scanner();
		virtual Parser::token_type lex(Parser::semantic_type* yylval, Parser::location_type* yylloc);
		void set_debug(bool b);
	};

}

#endif
