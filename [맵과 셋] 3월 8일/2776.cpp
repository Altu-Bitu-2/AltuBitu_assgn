#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, M;
	cin >> T;
	unordered_set<int> s;

	while (T--) {
		cin >> N;
		s.clear();
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			s.insert(a);
		}
		cin >> M;

		for (int j = 0; j < M; j++) {
			int b;
			cin >> b;
			
			if (s.find(b) != s.end())
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}