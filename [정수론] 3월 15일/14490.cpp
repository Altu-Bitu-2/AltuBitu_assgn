#include <iostream>

using namespace std;

int gcd(int a, int b) {
	
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b;
	char temp;
	cin >> a >> temp >> b;

	int A, B;
	A = a / gcd(a, b);
	B = b / gcd(a, b);
	cout << A << temp << B;
}