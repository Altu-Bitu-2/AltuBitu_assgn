#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	string s;
	map<string, int> m;

	for (int i = 0; i < N; i++) {
		cin >> s;
		s = s.substr(s.find('.') + 1);
		m[s]++;
	}
	
	for (auto t : m) {
		cout << t.first << ' ' << t.second << '\n';
	}
}