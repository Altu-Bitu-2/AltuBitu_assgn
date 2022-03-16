#include <iostream>
#include <algorithm>

using namespace std;

//알파벳의 개수가 홀수개인 알파벳이 두개이상이면 펠린드롬 문자열이 될 수 없다.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	int alpha[26] = { 0 };

	for (int i = 0; i < s.length(); i++) { //배열에 s 저장
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
	//홀수개인 알파벳이 두개 이상
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