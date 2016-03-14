%{

#include <string>
#include <cassert>
#include "include/scanner.hpp"

typedef lury::Parser::token token;
typedef lury::Parser::token_type token_type;

#define yyterminate() return token::END

#define YY_NO_UNISTD_H

#define MAX_DEPTH 72
unsigned int indent_stack[MAX_DEPTH] ;

typedef struct indent_stack_t {
	int size = 0;
	int width = 30;
	int* data = (int*)calloc(30, sizeof(int));
} STACK;

STACK indent;

int pop(STACK* stack) {
	if (stack->size > 0) {
		stack->size--;
		return stack->data[stack->size];
	}
}

void push(STACK* stack, int val) {
	if (stack->size >= stack->width / 2) {
		stack->width = stack->width * 2;
		stack->data = (int *)realloc(&stack->data, stack->width);
	}

	stack->data[stack->size] = val;
	stack->size++;
}

int peek(STACK* stack) {
	if (stack->size == 0) return -1;
	else {
		int val = stack->data[stack->size - 1];
		return val;
	}
}

void printStack(STACK* stack) {
	int i;
	for (i = 0; i < stack->size; i++) {
		printf("%d: %d\n", i, stack->data[i]);
	}
}

%}

%option c++

%option prefix="Lury"

%option batch

%option debug

%option yywrap nounput

%option stack

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%%

%{
	yylloc->step();
%}

^[ ]*\n {}
"###".*"###" {}
^"#".*\n {
	if (yyleng >= 3) {
		if (yytext[1] == '#' && yytext [2] == '#') {
			REJECT;
		}
	}
}
"#".*\n {
	if (yyleng >= 3) {
		if (yytext[1] == '#' && yytext [2] == '#') {
			REJECT;
		}
	}
	return token::NewLine;
}
\\\n {}

^[ ]* {
	if (yyleng == 0) {
		if (indent.size > 0) {
			pop(&indent);
			if (peek(&indent) > yyleng && indent.size != 0) {
				yylloc->lines(0);
				yyless(0);
				yy_set_bol(1);
			}
			return token::Dedent;
		}
	}
	else {
		if (peek(&indent) < yyleng || indent.size == 0) {
			push(&indent, yyleng);
			return token::Indent;
		}
		else if (peek(&indent) > yyleng && indent.size != 0) {
			pop(&indent);
			if (peek(&indent) > yyleng && indent.size != 0) {
				yyless(0);
			}
			return token::Dedent;
		}
	}
}

^[^ \n]+ {
	yyless(0);
	if (indent.size > 0) {
		pop(&indent);
		if (indent.size > 0) {
			yy_set_bol(1);
		}
		return token::Dedent;
	}
}

"if" return token::KeywordIf;
"elif" return token::KeywordElif;
"else" return token::KeywordElse;
"<=" return token::LessThan;
">=" return token::MoreThan;
"==" return token::Equal;
"def" return token::KeywordDef;
"nil" return token::KeywordNil;
"return" return token::KeywordReturn;
"continue" return token::KeywordContinue;
"break" return token::KeywordBreak;
"while" return token::KeywordWhile;
"true" return token::KeywordTrue;
"false" return token::KeywordFalse;
"+=" return token::AssignmentAdd;
"-=" return token::AssignmentSub;
"*=" return token::AssignmentMultiply;
"/=" return token::AssignmentDivide;
"not" return token::KeywordNot;
"=>" return token::Lambda;

[0-9]+ {
	yylval->int_value = atoi(yytext);
	return token::Integer;
}

[0-9]+"."[0-9]+"i" {
	yylval->double_value = atof(yytext);
	return token::ImaginaryNumber;
}

[0-9]+"."[0-9]+ {
	yylval->double_value = atof(yytext);
	return token::FloatNumber;
}

\"(\\.|[^\\"])*\" {
	yylval->string_value = new string(yytext);
	return token::StringLiteral;
}

[ \t\r]+ {
	yylloc->step();
}

\n\n* {
	yylloc->lines(yyleng);
	yylloc->step();
	return token::NewLine;
}

[a-z][a-zA-Z0-9]* {
	yylval->string_value = new string(yytext);
	return token::Identifier;
}

. {
	return static_cast<token_type>(*yytext);
}

<<EOF>> {
	if (indent.size > 0) {
		pop(&indent);
		return(token::Dedent);
	}
	yyterminate();
}

%%

unsigned int white_count(char* line) {
	unsigned int count = 0;
	while (*line == ' ') {
		count++;
		line++;
	}
	return count;
}

namespace lury {
	Scanner::Scanner(std::istream* in, std::ostream* out) : LuryFlexLexer(in, out){
	}

	Scanner::~Scanner() {
	}

	void Scanner::set_debug(bool b){
		yy_flex_debug = b;
	}
}

#ifdef yylex
#undef yylex
#endif

int LuryFlexLexer::yylex() {
	std::cerr << "in LuryFlexLexer::yylex() !" << std::endl;
	return 0;
}

int LuryFlexLexer::yywrap() {
	return 1;
}
