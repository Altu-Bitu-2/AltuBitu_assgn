#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> m;

bool compare(string a, string b) {
	//���ĺ� ������
	if (m[a] == m[b]) {
	//���̰� �����
		if (a.length() == b.length()) {
			return a < b;
		}
		return a.length() > b.length();
	}
	//�󵵰� ��������
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
		if (m.find(s) == m.end()) { //s�� �ܾ��忡 ������
			v.push_back(s);
		}
		m[s]++; //�� �� üũ
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}