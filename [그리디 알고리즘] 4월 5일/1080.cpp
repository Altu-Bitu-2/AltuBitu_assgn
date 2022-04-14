#include <iostream>
#include <vector>

using namespace std;

//0�� 1�θ� �̷���� ��� A, B ����
//��� A�� ��� B�� �ٲٴµ� �ʿ��� ������ Ƚ���� �ּڰ�

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; //50���� �۰ų� ���� �ڿ���
	cin >> n >> m; //����� ũ��

	//n�� �ٿ��� ��� A�� �־�����
	//�� ���� n�� �ٿ��� ��� B�� �־�����.
	vector<vector<char>>a(n, vector<char>(m));
	vector<vector<char>>b(n, vector<char>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];

	//0~(n-2)���� �������
	int cnt = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			
			//��� A�� ��� B�� ���� ������
			if (a[i][j] != b[i][j]) {
				cnt++;

				//3x3��ŭ �ٲٱ�
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

	//��� A�� ��� B�� �ٲ� �� ���ٸ� -1 ���
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