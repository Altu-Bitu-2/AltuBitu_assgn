#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 64; //ü���� ĭ ����

//(x, y)���� �����ϴ� 8*8 ü������ ����µ� �ʿ��� �ּ� ī��Ʈ ����
//�������� �����ϴ� ü������ �������� ���(b_count) -> ����(32) �̻��̸� ������� �����ϴ� ü���� ī��Ʈ(64 - b_count) ����
int chessChange(int row, int col, vector<vector<char>>& board) {
    int b_cnt = 0; //B�� �����ϴ� ü���� ����� ���� ī��Ʈ

    for (int i = 0; i < 8; i++) { //�� ��ȭ��
        for (int j = 0; j < 8; j++) { //�� ��ȭ��
            //i+j���� ¦���̰� board�� ��� ���� B�� �ƴϸ�
            if ((i + j) % 2 == 0 && board[row + i][col + j] != 'B') {
                b_cnt++; //ī��Ʈ
            }
            //i+j���� Ȧ���̰� board�� ��� ���� W�� �ƴϸ�
            else if ((i + j) % 2 && board[row + i][col + j] != 'W') { 
                b_cnt++; //ī��Ʈ
            }

        }
    }

    //�ּڰ� ����
    if (b_cnt > SIZE / 2) {
        return SIZE - b_cnt;
    }
    return b_cnt;
}

/**
 * [ü���� �ٽ� ĥ�ϱ�]
 * - ���� �� �ִ� ü������ ���: 2����
 * - (0, 0)�� ������ ���, ����� ���
 * - �������� �����ϴ� ü������ ���, �ε��� i+j�� ¦���� �� 'B'���� �̿�
 *
 * 1.  (0, 0) �ε������� ���ʷ� 8*8 ü���� ���� �� �ٲ�� �ϴ� ĭ ���� ����ϰ�, �� �� �ּڰ� ���ϱ�
 *
 * ���� ũ�� <= 2,500
 * �� ��ġ�� ���� ü���� �� ���� = 64��
 * �� ���� �� = 2,500 * 64 < 1�� -> ���Ʈ ���� ����
 */

int main() {
    int n, m;
    int ans = SIZE + 1; //������ ü���� ĭ ���� + 1 �� �ʱ�ȭ

    //�Է�
    cin >> n >> m; //n * m �� �Է¹ޱ�
    vector<vector<char>> board(n, vector<char>(m)); //��: n, ��: m
    for (int i = 0; i < n; i++) { //���� �Է�
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //����
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int cnt = chessChange(i, j, board); //�����ε����� (i,j)�� ü���� ����� �ּڰ�
            ans = min(ans, cnt); //�ּڰ� ����
        }
    }

    //���
    cout << ans << '\n';
    return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

int chess[52][52];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chess[i + 1][j + 1];
		}
	}

	int res;

	for (int x = 1; x <= N - 7; x++) {
		for (int y = 1; y <= M - 7; y++) {
			int cnt = 0;

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (i % 2 == 1) { // i�� Ȧ���� ��
						// j�� Ȧ���̸鼭 chess�� B�� ��
						if (j % 2 == 1 && chess[x + i][y + j] == 'B')
							cnt++;
						// j�� ¦���̸鼭 chess�� W�� ��
						else if (j % 2 == 0 && chess[x + i][y + j] == 'W')
							cnt++;
					}
					else { // i�� ¦���� ��
						// j�� ¦���̸鼭 'B'�� ��
						if (j % 2 == 0 && chess[x + i][y + j] == 'B')
							cnt++;
						//j�� Ȧ���̸鼭 'W'�� ��
						else if (j % 2 == 1 && chess[x + i][y + j] == 'W')
							cnt++;
					}
				}
			}
			cnt = min(cnt, 64 - cnt);
			res = min(cnt, res);
		}
	}
	cout << res;
}
*/