#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 1 = 1 (1��)
	// 2 = 1+1, 2 (2��)
	// 3 = 1+1+1.1+2 (2), 3 (4��)
	// 4 = 1+1+1+1, 1+1+2 (3), 1+3 (2), 2+2 (7��)
	// 5 = 1+1+1+1+1, 1+1+1+2 (4), 1+1+3 (3), 1+2+2 (3), 2+3 (2) (13��)

	int t, n;
	cin >> t;
	int dp[12];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 0; i < t; i++) { // �׽�Ʈ ��
		cin >> n;
		for (int j = 4; j <= n; j++) { //���� ���� ex)4
			dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];
		}
		cout << dp[n] <<'\n';
	}
}