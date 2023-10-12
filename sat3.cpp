// A tape consists of a few different symbols:
//
//	A positive integer refers to a variable of that index;
//	A -1 is an OR operator; and
//	A -2 is an AND operator.
//
// Since the problem is in conjunctive normal form, it is 
// expected that there are parentheses surrounding any
// consecutive string of OR operands.

struct Result {
	char resultCode;
	bool satisfiable;
};

template <const int size>
Result satisfiable(int tape[size]) {
}