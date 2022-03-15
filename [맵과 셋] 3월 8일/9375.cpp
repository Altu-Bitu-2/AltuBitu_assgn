#include <iostream>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T; //�׽�Ʈ ��
	map<string, int> m; //�ǻ� ����, �ǻ� ��

	while (T--) {
		int res = 1;
		m.clear();

		int n; //�ǻ� ��
		cin >> n;
		string a, b; //a: �ǻ� �̸�, b: �ǻ� ����

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			m[b]++;
		}

		for (auto t : m)
			res *= (t.second + 1);
		cout << res - 1 << "\n";
	}
}