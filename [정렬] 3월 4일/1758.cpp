#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, a;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end(), greater<int>());

	long long sum = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] - i <= 0)
			break;
		sum += (v[i] - i);
	}

	cout << sum;
}