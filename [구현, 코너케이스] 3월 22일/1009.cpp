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
		// a를 b번 곱하기
		for (int j = 0; j < b; j++) {
			res = (res * a);
			res = res % 10;
		}
		// 0일 때 10번 컴퓨터 출력
		if (res == 0)
			cout << "10\n";
		// 0이 아니면 결과 출력
		else
			cout << res << '\n';
	}
}