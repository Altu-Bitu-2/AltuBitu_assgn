#include <iostream>
#include <string.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M;
	cin >> M; // 연산 횟수
	bool checkNum[21]; //숫자를 출력하는 것이 아니기 때문에 숫자의 존재 유무가 중요

	for (int i = 0; i < M; i++)
	{
		string cmd; // 명령어 입력받기
		int num; // 1 ~ 20 숫자 입력받기
		cin >> cmd;
		
		// 연산
		if (cmd == "add") {
			cin >> num;
			checkNum[num] = true;
		}
		else if (cmd == "remove") {
			cin >> num;
			checkNum[num] = false;
		}
		else if (cmd == "check") {
			cin >> num;
			if (checkNum[num] == true) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (cmd == "toggle") {
			cin >> num;
			if (checkNum[num]) {
				checkNum[num] = false;
			}
			else {
				checkNum[num] = true;
			}
		}
		else if (cmd == "all") {
			memset(checkNum, true, sizeof(checkNum));
		}
		else {
			memset(checkNum, false, sizeof(checkNum));
		}
	}
}