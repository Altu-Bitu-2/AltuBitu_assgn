#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> m;

bool compare(string a, string b) {
	//알파벳 순으로
	if (m[a] == m[b]) {
	//길이가 길수록
		if (a.length() == b.length()) {
			return a < b;
		}
		return a.length() > b.length();
	}
	//빈도가 많을수록
	return m[a] > m[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<string> v;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s.length() < M) continue;
		if (m.find(s) == m.end()) { //s가 단어장에 없으면
			v.push_back(s);
		}
		m[s]++; //빈도 수 체크
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}