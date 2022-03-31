#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// ����Ʈ�� �ִ� ���� N��, �¼��� ���ο� ����,
	// ��ŷ ����Ʈ�� �ö� �� �ִ� ������ ���� P��

	int n, scoreT, p;
	cin >> n >> scoreT >> p;
	long long num;
	int cnt = 1;

	vector<int> scores;

	for (int i = 0; i < n; i++) {
		cin >> num;
		scores.push_back(num);
	}

	sort(scores.begin(), scores.end(), greater<>());

	// ����Ʈ�� �� �� ���¿��� �¼��� ������ ���� ���� �������� �۰ų� ������
	// �� ������ ���� �������� ������ ���� ���� �ٲ��.
	if (n == p && scores[n - 1] >= scoreT)
		cout << "-1";
	else {
		for (int i = 0; i < n; i++) {
			//����Ʈ�� �ִ� ������ �¼��� �������� ũ��
			if (scores[i] > scoreT) {
				// ��� ���ֱ�
				cnt++;
			}
		}
		cout << cnt;
	}
}