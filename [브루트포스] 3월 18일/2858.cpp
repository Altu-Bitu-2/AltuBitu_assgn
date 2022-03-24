#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int R, B;
	cin >> R >> B; //빨간색 타일 수, 갈색 타일 수

	// R + B = L * W
	// B = (L - 2) * (W - 2)
	// R = L * W - (L - 2) * (W - 2)

	int exR, exB;

	for (int i = 3; i <= 5000; i++) {
		for (int j = i; j >=3; j--) {
			exB = (i - 2) * (j - 2);
			exR = i * j - exB;

			if (exB == B && exR == R) {
				cout << i << " " << j;
			}
		}
	}
}