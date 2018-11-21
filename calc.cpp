/*
BNF nyelvtan:

			Expr ::= Term ('+' Term | '-' Term)*
			Term ::= Factor ('*' Factor | '/' Factor)*
			Factor ::= ['-'] (Number | '(' Expr ')')
			Number ::= Digit+

Here * means the preceding element is repeated zero or more times, + means one or more repeats, square brackets means optional.
*/

#include "std_lib_facilities.h"





double parse_expr() {
	double term = parse_term();

	while(true) {

	}
}

double parse_term() {
	double factor = parse_factor();

}

double parse_factor() {
	
}

int main() {
    try {
            cout << "hw" << endl;

            return 0;
    }

    catch(...) {
            cout << "something VERY bad happened...";
    }
}
