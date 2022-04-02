#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; //수열 A의 크기
	cin >> n;
	int len = 1;
	int num[1001];
	int dp[1001];

	for (int i = 0; i < n; i++) {
		cin >> num[i]; //A를 이루고 있는 Ai 입력
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			// 현재 위치보다 수가 작으면서 가지고 있는 값보다 크면 1 증가
			if (num[i] > num[j]) { // Ai가 Aj보다 크고
				if (dp[i] <= dp[j]) { // dp[j]값이 내가 갖고 있는 dp[i] 값 보다 크면
					dp[i] = dp[j] + 1; // dp값에 1 증가
				}
			}
		}
		len = max(len, dp[i]); // dp에서 가장 큰 값 출력
	}
	cout << len <<'\n'; // 가장 긴 길이 출력
}