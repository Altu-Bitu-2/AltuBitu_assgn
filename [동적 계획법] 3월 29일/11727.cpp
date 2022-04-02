#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 1x2, 2x1, 2x2
	// 2x1: 1개, 2x2: 3개, 2x3: 5개, 2x4: 11개, 2x5: 21개 ..
	int n;
	cin >> n;
	int dp[1001];

	// 1번째부터 2번째까지는 직접 수 넣기
	dp[1] = 1;
	dp[2] = 3;

	// 3번째부터 n번째까지 동적 계획법으로 계산
	for (int i = 3; i <= n; i++) {

		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}
	cout << dp[n] << '\n';
}