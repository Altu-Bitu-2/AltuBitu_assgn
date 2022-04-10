#include <iostream>
#include <vector>

using namespace std;

//0과 1로만 이루어진 행렬 A, B 존재
//행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; //50보다 작거나 같은 자연수
	cin >> n >> m; //행렬의 크기

	//n개 줄에는 행렬 A가 주어지고
	//그 다음 n개 줄에는 행렬 B가 주어진다.
	vector<vector<char>>a(n, vector<char>(m));
	vector<vector<char>>b(n, vector<char>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];

	//0~(n-2)까지 뒤집어보기
	int cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			
			//행렬 A와 행렬 B가 같지 않으면
			if (a[i][j] != b[i][j]) {
				cnt++;

				//3x3만큼 바꾸기
				for (int k = i; k < i + 3; k++) {
					for (int l = j; l < j + 3; l++) {
						if (a[k][l] == '0')
							a[k][l] = '1';
						else
							a[k][l] = '0';
					}
				}
			}
		}
	}

	//행렬 A를 행렬 B로 바꿀 수 없다면 -1 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << cnt;
	return 0;
}