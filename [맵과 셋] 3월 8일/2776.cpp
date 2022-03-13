#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, M;
	cin >> T;
	set<int> s;

	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			s.insert(a);
		}
		cin >> M;

		for (int j = 0; j < M; j++) {
			int b;
			cin >> b;
			
			if (binary_search(s.begin(), s.end(), b))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}