using namespace std;

// Data class to store the problemn data.
// Do not use 0 as a variable ID.
template <const int k>
struct Clause {
	int ids[k];
	bool invs[k];
}

template <const int n, const int k>
bool satisfiable(Clause<k> clauses[n]) {
	// Logically we have to be allowed to use the
	// n clauses as memory because otherwise it would
	// be impossible to represent the problem at all

	// Store a single variable to keep track of the
	// total number of distinct variables in the problem.
	//
	// Time complexity: O(1) (constant time)
	//
	// Space complexity: O(1) (constant space)
	int t = 0;

	// Re-label the variables so that the total number
	// of distinct variables is known. The clauses
	// themselves are altered so that the variables
	// are in numerical order starting from zero.
	//
	// Time complexity: O(n^2k^2) (polynomial time)
	// since an O(nk) process is run O(nk) times
	// 
	// Space complexity: O(1) (constant space)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {

			// The "current variable" becomes
			// the jth variable of the ith clause
			// ...unless it's zero, in which case
			// we skip it because that means that it
			// was a duplicate found in a past loop

			// Check if the variable was already found
			// to be a duplicate
			//
			// Time complexity: O(1)
			//
			// Space complexity: O(1)
			if (clauses[i].ids[j] == 0) {
				continue;
			}
			
			// Iterate through the rest of the clauses
			// and set all other instances of the
			// duplicate variable to 0 - after this is
			// run for all distinct variables, the only
			// remaining nonzero variables will be all
			// unique
			//
			// Time complexity: O(nk)
			//
			// Space complexity: O(1)
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < k; y++) {

					// Ignore the current variable so
					// that we don't break anything
					if ((x == i) && (y == j)) {
						continue;
					}

					// If this variable is the same 
					// as the current variable, set it
					// to zero 
					if (clauses[x].ids[y] == clauses[i].ids[j]) {
						clauses[x].ids[y] = 0;
					}
				}
			}
		}
	}

	// Iterate through the clauses and count the nonzero
	// variables. Since we just set all duplicate values to
	// zero, the number of nonzero values is equal to the 
	// number of distinct variables.
	//
	// Time complexity: O(nk)
	//
	// Space complexity: O(1)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (clauses[i].ids[j] != 0) {
				t++;
			}
		}
	}

	// We now know that there are t total variables.
	//
	// Since there are t distinct variables and k variables
	// per clause, there are (t; k) ways to arrange them,
	// and for each of those possible arrangements, there
	// are 2^k ways to negate that arrangement.
	//
	// This means that there are (t; k) * 2^k possible clauses.
	//
	// Of those clauses, each has EXACTLY ONE assignment of
	// its k variables that negates it. For n clauses, this
	// means that there are n "incorrect solutions" (assuming
	// that the problem is in normal conjunctive form).
	//
	// Thus, there are 2^t possible solutions and n incorrect
	// solutions.
	//
	// From there, it is simple to extrapolate that any
	// solution that is not incorrect must be "correct" and 
	// satisfy the expression. Therefore, there are 2^t - n
	// correct solutions.
	//
	// All that's left is to check whether this number is
	// nonzero.

	// Actually exponentiating t is much more space-inefficient
	// than just using a floored logarithm to check if
	// t - log2 n > 0 which is the exact same as checking
	// 2^t - n > 0
}
