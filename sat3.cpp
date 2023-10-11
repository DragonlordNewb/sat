template <typename T, const n>
bool satisfiable(T variables[n]) {

	// Satisfiable if 2^t > n * 2^(t - k)
	
	int t = 0;
	
	for (int i = 0; i < n; i++) {
		if (variables[i] == 0) {
			continue;
		}
		
		for (int j = i + 1; i < n; i++) {
			if (variables[i] == variables[j]) {
				variables[j] == 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (variables[i] != 0) {
			t++;
		}
	}
}
