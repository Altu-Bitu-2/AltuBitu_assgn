#include <iostream>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T; //테스트 수
	map<string, int> m; //의상 종류, 의상 수

	while (T--) {
		int res = 1;
		m.clear();

		int n; //의상 수
		cin >> n;
		string a, b; //a: 의상 이름, b: 의상 종류

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			m[b]++;
		}

		for (auto t : m)
			res *= (t.second + 1);
		cout << res - 1 << "\n";
	}
}