#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string N;
	cin >> N;
	bool zero = 0;
	int sum = 0;

	for (int i = 0; i < N.size(); i++) {
		sum += N[i] - '0';

		if (N[i] - '0' == 0) {
			zero = 1;
		}
	}
	if (zero == 1 && sum % 3 == 0) {
		sort(N.begin(), N.end(),greater<int>());
		cout << N;
	}
	else {
		cout << -1;
	}
}