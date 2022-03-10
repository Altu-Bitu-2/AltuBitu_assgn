#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

void reverseOrder(int a, int b) {

	reverse(arr.begin() + a - 1, arr.begin() + b);
}

int main() {
	
	for (int i = 1; i <= 20; i++) {
		arr.push_back(i);
	}
	int a, b;

	for (int i = 0; i < 10; i++) {

		cin >> a >> b;
		reverseOrder(a, b);

	}
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}