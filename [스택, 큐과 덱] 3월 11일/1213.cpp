#include <iostream>
#include <algorithm>

using namespace std;
int alpha[26];
string res;

//���ĺ��� ������ Ȧ������ ���ĺ��� �ΰ��̻��̸� �縰��� ���ڿ��� �� �� ����.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) { //�迭�� s ����
		alpha[s[i] - 'A']++;
	}
	int oddCnt = 0;
	int odd = -1;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			oddCnt++;
			odd = i;
		}
	}
	//Ȧ������ ���ĺ��� �ΰ� �̻�
	if (oddCnt > 1) {
		res = "I'm Sorry Hansoo";
	}
	else {
		string temp;
		for (int i = 0; i < 26; i++) {
			if (alpha[i] > 0) {
				for (int j = 0; j < alpha[i] / 2; j++) {
					res += i + 'A';
				}
			}
		}
		temp = res;
		reverse(temp.begin(), temp.end());
		if (odd != -1) {
			res += odd + 'A';
		}
		res += temp;
	}
	cout << res;
}