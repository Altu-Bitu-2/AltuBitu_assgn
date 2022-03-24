#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int toNum(char ch) { return ch - '0'; }

char A[10005], B[10005];
int Ain[10005], Bin[10005], S[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	// a: A의 문자열 길이, b = B의 문자열 길이
	int a = strlen(A);
	int b = strlen(B);
	int cnt = 0;

	// 숫자로 변경
	for (int i = a - 1; i >= 0; i--)
		Ain[cnt++] = toNum(A[i]);
	cnt = 0;
	for (int i = b - 1; i >= 0; i--)
		Bin[cnt++] = toNum(B[i]);

	int sum, num;
	for (int i = 0; i < max(a, b); i++) {
		sum = Ain[i] + Bin[i];
		num = S[i] + sum;
		// 더한 값이 10보다 크면
		if (num >= 10) {
			S[i] = num - 10;
			S[i + 1] += 1;
		}
		// 더한 값이 10보다 작으면
		if (num < 10)
			S[i] = num;
	}

	int over = 0;
	if (S[max(a, b)] == 0) {
		over = 1;
	}
	for (int i = max(a, b) - over; i >= 0; i--) {
		cout << S[i];
	}
	cout << '\n';
}