#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string word;
	int n;
	int cnt = 0;
	
	cin >> n; // 단어의 수
	for (int i = 0; i < n; i++) {
		cin >> word; // 단어
		bool check = true;

		// 입력받은 단어의 길이만큼 for문
		for (int j = 0; j < word.size(); j++) {
			for (int k = 0; k < j; k++) {
				// j번째 단어와 j-1번째 단어가 다르면 false
				// 앞에 나왔던 단어가 또 나오면 false
				if (word[j] != word[j - 1] && word[j] == word[k]) {
					check = false;
				}
			}
		}
		if (check)
			cnt++;
	}

	cout << cnt;
}