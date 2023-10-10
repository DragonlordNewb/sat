// Variables MUST be compactly ordered.
// This means that if variable n is used,
// variable 0, 1, 2, ..., n-2, and n-1
// must also be used.

// This is just a general syntax thing
// so that the program works. All CNF
// statements can be equivalently written
// this way.

// Syntax:
//
//	Clause<k> clauses[n] = ... ;
//	bool isSolvable1 = satisfiable(n, k, t);
//	bool isSolvabke2 = satisfiable(clauses);
//
// where
//
//	k is the number of literals per clause,
//	n is the number of clauses,
//	t is the total number of distinct literals.
//
// isSolvable (1 or 2) will be true if there is an 
// assignment of truth to the variables that renders 
// all of the clauses true simultaneously.
// solution will contain a clause representing
// an assignment of truth to the variables that
// renders all of the clauses true simultaneously,
// or will indicate that no solution exists.

template <int k>
struct Clause {
	int ids[k];
	bool invs[k];
};

bool satisfiable(int n, int k, int t) {
	
}
