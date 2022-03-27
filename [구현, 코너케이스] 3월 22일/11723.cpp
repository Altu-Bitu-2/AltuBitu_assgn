#include <iostream>
#include <string.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M;
	cin >> M; // ���� Ƚ��
	bool checkNum[21]; //���ڸ� ����ϴ� ���� �ƴϱ� ������ ������ ���� ������ �߿�

	for (int i = 0; i < M; i++)
	{
		string cmd; // ��ɾ� �Է¹ޱ�
		int num; // 1 ~ 20 ���� �Է¹ޱ�
		cin >> cmd;
		
		// ����
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