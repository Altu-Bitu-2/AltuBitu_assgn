#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, a, b, res;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		res = 1;
		// a�� b�� ���ϱ�
		for (int j = 0; j < b; j++) {
			res = (res * a);
			res = res % 10;
		}
		// 0�� �� 10�� ��ǻ�� ���
		if (res == 0)
			cout << "10\n";
		// 0�� �ƴϸ� ��� ���
		else
			cout << res << '\n';
	}
}