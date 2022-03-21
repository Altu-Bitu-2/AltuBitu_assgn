#include <iostream>
#include <cmath>
#include <vector>

#define MAX 1000000

using namespace std;

int primeNum[MAX + 1];
vector<int> prime;

void PrimeCheck() {
	//�����佺�׳׽��� ü
	for (int i = 2; i <= MAX; i++) {
		primeNum[i] = i;
	}

	for (int i = 2; i <= sqrt(MAX); i++) {
		if (primeNum[i] == 0) continue;
		//j = i * i ���� �˻�
		for (int j = i * i; j <= MAX; j += i) {
			primeNum[j] = 0;
		}
	}
	
	for (int i = 2; i <= MAX; i++) {
		if (primeNum[i] != 0) {
			prime.push_back(primeNum[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	PrimeCheck();
	int N;
	bool flag = false;
	
	while (true) {
		cin >> N;
		if (N == 0) break;

		//for������ ó������ ã�� ���� = b-a�� ���� ū ��
		for (int i = 0; i < prime.size(); i++) {
			if (primeNum[N - prime[i]] == N - prime[i]) {
				cout << N << " = " << prime[i] << " + " << N - prime[i] << '\n';
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "Goldbach's conjecture is wrong.";
		}
	}
}