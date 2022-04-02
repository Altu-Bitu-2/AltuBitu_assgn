#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// 리스트에 있는 점수 N개, 태수의 새로운 점수,
	// 랭킹 리스트에 올라갈 수 있는 점수의 개수 P개

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

	// 리스트가 꽉 찬 상태에서 태수의 점수가 가장 작은 점수보다 작거나 같으면
	// 새 점수가 이전 점수보다 점수가 좋을 때만 바뀐다.
	if (n == p && scores[n - 1] >= scoreT)
		cout << "-1";
	else {
		for (int i = 0; i < n; i++) {
			//리스트에 있는 점수가 태수의 점수보다 크면
			if (scores[i] > scoreT) {
				// 등수 세주기
				cnt++;
			}
		}
		cout << cnt;
	}
}