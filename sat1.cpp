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
//	bool isSolvable1 = satisfiable<n, k>(t);
//	bool isSolvable2 = satisfiable<n, k>(clauses);
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

// How the algorithm works:
//
// For any satisfiability problem in conjunctive 
// normal form of n unique clauses each of k literals 
// totalling t different literals, then there are
// exactly n assignments of truth that make the
// expression false, namely any of the assignments
// which directly negate any of the clauses.
//
// There are also (t k) possible different clauses, 
// where (* *) is the binomial coefficient operator such
// that (a b) = a! / k!(n - k)!. The binomial coefficient
// can also be more efficiently computed as the product
// of 1 / k! and (a - x) for all integer values
// -1 < x < k.
//
// By the pigeon-hole principle, if there are as many
// incorrect answers as possible answers, then, since
// all answers are incorrect, the statement is not
// satisfiable.
//
// Conversely, this means that if there are FEWER
// incorrect answers than possible answers, then
// AT LEAST one of the possible answers is not
// incorrect, thus correct, meaning that the statement
// is satisfiable.
//
// So, it's trivial to reduce the satisfiability
// problem in question to checking whether (t k) > n.
//
// If (t k) can be computed efficiently (i.e. in
// polynomial time), then P=NP since Boolean satisfiability
// is NP-complete.

using namespace std;

template <int k>
struct Clause {
	int ids[k];
	bool invs[k];
};

// Given the total number of variables,
// is an n-k-satisfiability problem
// satisfiable?
template <int n, int k>
bool satisfiable(int t) {
	// Compute k!.
	int kfact = 1;
	for (int a = 1; a <= k; a++) {
		kfact *= a;
	}

	// Compute the product of all (t - x) for -1 < x < k.
	int result = 1;
	for (int x = 0; x < k; x++) {
		result *= t - x;
	}

	// Compute the binomial coefficient using the quotient 
	// of all (t - x) by k!.
	int binomialCoefficient = result / kfact;

	// If the binomial coefficient is greater than the number
	// of incorrect solutions, then there exists at least
	// one correct solution and the statement is satisfiable.
	return (binomialCoefficient > n);
}

// Given the clauses of an n-k-
// -satisfiability, is the problem
// satisfiable?
template <int n, int k>
bool satisfiable(Clause<k> clauses[n]) {
	int t = 0;
	Clause<k> clause;
	for (int i = 0; i < n; i++) {
		clause = clauses[i];
		for (int j = 0; j < k; j++) {
			if (clause.ids[j] > t) {
				t = clause.ids[j];
			}
		}
	}
	return (satisfiable<n, k>(t));
}

int main() {
	std::cout << "1 = true, 0 = false" << std::endl;
	
	std::cout << "Is a problem";
	std::cout << " with 5 variables and 3 clauses";
	std::cout << " of 3 variables each solvable: ";
	std::cout << satisfiable<3, 3>(5) << std::endl;

	std::cout << "Is a problem";
	std::cout << " with 3 variables and 6 clauses";
	std::cout << " of 3 variables each solvable: ";
	std::cout << satisfiable<6, 3>(3) << std::endl;

	return 0;
}
