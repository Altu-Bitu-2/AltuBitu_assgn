#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	while (T--) {
		int cnt = 0;
		cin >> N;
		vector<pair<int, int>> v(N);
		
		for (int i = 0; i < N; i++) {
			cin >> v[i].first >> v[i].second;
		}

		sort(v.begin(), v.end());

		int max = v[0].second; 
		for (int i = 0; i < N; i++) {
			if (max >= v[i].second) { //면접 성적 순위가 작을수록 카운트
				max = v[i].second;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}