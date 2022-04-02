#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 1x2, 2x1, 2x2
	// 2x1: 1��, 2x2: 3��, 2x3: 5��, 2x4: 11��, 2x5: 21�� ..
	int n;
	cin >> n;
	int dp[1001];

	// 1��°���� 2��°������ ���� �� �ֱ�
	dp[1] = 1;
	dp[2] = 3;

	// 3��°���� n��°���� ���� ��ȹ������ ���
	for (int i = 3; i <= n; i++) {

		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	cout << dp[n] << '\n';
}