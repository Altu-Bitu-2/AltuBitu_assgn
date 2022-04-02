#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; //���� A�� ũ��
	cin >> n;
	int len = 1;
	int num[1001];
	int dp[1001];

	for (int i = 0; i < n; i++) {
		cin >> num[i]; //A�� �̷�� �ִ� Ai �Է�
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			// ���� ��ġ���� ���� �����鼭 ������ �ִ� ������ ũ�� 1 ����
			if (num[i] > num[j]) { // Ai�� Aj���� ũ��
				if (dp[i] <= dp[j]) { // dp[j]���� ���� ���� �ִ� dp[i] �� ���� ũ��
					dp[i] = dp[j] + 1; // dp���� 1 ����
				}
			}
		}
		len = max(len, dp[i]); // dp���� ���� ū �� ���
	}
	cout << len <<'\n'; // ���� �� ���� ���
}