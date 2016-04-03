#ifndef _H_SDP
#define _H_SDP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

struct Sym {
	string tag,val;
	Sym(string,string); Sym(string);
	virtual string tagval(); string tagstr();
	virtual string dump(int=0); string pad(int);
	vector<Sym*> nest; void push(Sym*);
	virtual string sig(); // sig()nature
};

struct Str: Sym { Str(string); string dump(int); string sig(); };

struct List: Sym { List(); string tagval(); string sig(); };

struct Op: Sym { Op(string); };

struct Rule: Sym { Rule(Sym*,Sym*); };

extern int yylex();
extern int yylineno;
extern char* yytext;
#define TOC(C,X) { yylval.o = new C(yytext); return X; }
extern int yyparse();
extern void yyerror(string msg);
#include "ypp.tab.hpp"

#endif // _H_SDP
