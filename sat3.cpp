template <typename T, const n>
bool satisfiable(T variables[n]) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; i < n; i++) {
			if (variables[i] == variables[j]) {0
			}
		}
	}
}
