#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	int max = 0;
	cin >> N >> M;
	int num[100];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	//num중에서 3장 골라서 더했을 때 sum <= M 중 가장 큰 값
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = 0;
				sum = num[i] + num[j] + num[k];
				if (sum <= M) 
					if (sum >= max) {
						max = sum;	
				}
			}
		}
	}
	cout << max << '\n';
}