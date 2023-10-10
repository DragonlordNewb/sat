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
//	Clause<t> solve<n, k, t>(clauses);
//
// where
//
//	k is the number of literals per clause,
//	n is the number of clauses,
//	t is the total number of distinct literals.

template <int k>
struct Clause {
	int ids[k];
	bool invs[k];
};

template <int n, int k, int t>
Clause<t> solve(Clause<k> clauses[n]) {
}
