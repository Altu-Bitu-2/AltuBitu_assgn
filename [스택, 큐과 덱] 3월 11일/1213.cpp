#include <iostream>
#include <algorithm>

using namespace std;

//���ĺ��� ������ Ȧ������ ���ĺ��� �ΰ��̻��̸� �縰��� ���ڿ��� �� �� ����.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	int alpha[26] = { 0 };

	for (int i = 0; i < s.length(); i++) { //�迭�� s ����
		alpha[s[i] - 'A']++;
	}
	int oddCnt = 0;
	int odd = -1;
	if (s.length() % 2 == 1) {
		for (int i = 0; i < 26; i++) {
			if (alpha[i] % 2 == 1) {
				oddCnt++;
				odd = i;
			}
		}
	}
	//Ȧ������ ���ĺ��� �ΰ� �̻�
	if (oddCnt >= 2)
		cout << "I'm Sorry Hansoo";
	else {
		string res;
		string temp;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				res += i + 'A';
			}
		}
		temp = res;
		reverse(temp.begin(), temp.end());
		if (odd != -1) {
			res += odd + 'A';
		}
		res += temp;
		cout << res;
	}
}