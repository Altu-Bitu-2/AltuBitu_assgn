#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //�ִ� n-1���� ������ ������ ��

void floydWarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& table) {
    for (int k = 1; k <= n; k++) { //k�� ���İ��� ����
        for (int i = 1; i <= n; i++) { //i�� �� (��� ����)
            for (int j = 1; j <= n; j++) { //j�� �� (���� ����)
                //���� i���� ���� n�� ���ļ� ���� j�� �� ��,
                int new_dist = graph[i][k] + graph[k][j];
                //n�� ���İ��� ���� �� �ִ� ����� ��� ������Ʈ
                if (new_dist < graph[i][j]) {
                    graph[i][j] = new_dist;
                    table[i][j] = table[i][k];
                }
            }
        }
    }
}

/**
 * [�ý�]
 *
 * graph : �÷��̵�-���� ��� ��� �׷���
 * table : ���ǥ. table[i][j] = i->j�� ���� ���� ���� ���� ���ľ� �ϴ� ����
 *
 * 1. i->j�� �߰� ��θ� i�� �ʱ�ȭ
 * 2. i->k->j�� i->j���� ª�ٸ� i->j�� �߰� ��θ� i->k�� �߰� ���(table[i][k])�� ����
 *    k�� �����ϴ°� �ƴ϶� table[i][k]�� �����ϴ� ������?
 *    ���� i->k�� ��ΰ� i->t->k��� ���� ��δ� i->t->k->j
 *    �ٷ� k�� �����ϸ� t�� ��ĥ �� �ֱ� ������ table[i][k]�� ����
 *    line 14�� table[i][j] = k�� �ٲٸ� ����� ��� �Ǵ��� Ȯ���غ�����
 */

int main() {
    int n, m, s, d, c;

    //�Է�
    cin >> n >> m; //�������� ����, �����尣 ����� ����
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //���� �׷���
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0)); //���ǥ
    for (int i = 1; i <= n; i++) { //n�� ũ�⸸ŭ �ݺ�
        graph[i][i] = 0; //��ǥ (i, i)�� 0���� ����
    }

    while (m--) { //������ �׷���
        cin >> s >> d >> c; //�� �������� ��ȣ, �� ���̸� �����µ� �ʿ��� �ð�
        //���� ����
        graph[s][d] = graph[d][s] = c; 

        //��� ����
        table[s][d] = d; 
        table[d][s] = s;
    }

    //����
    floydWarshall(n, graph, table);

    //���
    for (int i = 1; i <= n; i++) { //i�� n�� ũ�⸸ŭ �ݺ�
        for (int j = 1; j <= n; j++) { //j�� n�� ũ�⸸ŭ �ݺ�
            if (i == j) { //i�� j�� ���� ���ٸ�
                cout << "- "; //- ���
            }
            else { //i�� j�� ���� �ٸ��ٸ�
                cout << table[i][j] << ' '; //���ǥ ���
            }
        }
        cout << '\n';
    }
    return 0;
}