#include <iostream>
#include <algorithm>

using namespace std;
int alpha[26];
string res;

//알파벳의 개수가 홀수개인 알파벳이 두개이상이면 펠린드롬 문자열이 될 수 없다.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) { //배열에 s 저장
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
	//홀수개인 알파벳이 두개 이상
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