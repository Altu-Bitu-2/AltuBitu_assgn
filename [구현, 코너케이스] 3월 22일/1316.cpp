#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string word;
	int n;
	int cnt = 0;
	
	cin >> n; // �ܾ��� ��
	for (int i = 0; i < n; i++) {
		cin >> word; // �ܾ�
		bool check = true;
		int alpha[26] = { 0, };

		// �Է¹��� �ܾ��� ���̸�ŭ for��
		for (int j = 0; j < word.size(); j++) {
			alpha[(int)word[j] - 97]++;
			// j��° �ܾ�� j-1��° �ܾ �ٸ��� false
			// �տ� ���Դ� �ܾ �� ������ false
			if (alpha[(int)word[j] - 97] > 1 && word[j] != word[j - 1]) {
					check = false;
			}
		}
		if (check)
			cnt++;
	}

	cout << cnt;
}