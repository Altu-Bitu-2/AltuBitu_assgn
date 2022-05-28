#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>>& graph) {
    int pos = node, len = 0; //������ �����ϴ� ��� �� �ϳ�, �� �������� �Ÿ�
    for (int i = 0; i < graph[node].size(); i++) { //������ ����� ũ�⸸ŭ Ž��
        int next_node = graph[node][i].first;
        if (next_node == parent) { //���� ��尡 �θ� ����̸�
            continue; //continue
        }

        ci dfs_search = dfs(next_node, node, graph); //�ڽ� ��忡 ���� dfs Ž��
        if (graph[node][i].second + dfs_search.second > len) { //���� �Ÿ����� ��ٸ� ����
            len = graph[node][i].second + dfs_search.second; //�������� �Ÿ� ����
            pos = dfs_search.first; //������ �����ϴ� ��� ����
        }
    }
    return { pos, len }; //���� �� �Ÿ��� �� �ε����� ����
}

/**
 * [Ʈ���� ����]
 *
 * 1. ������ �̷�� �� ���� ��� ���� ���
 * 2. ������ �� ��忡�� ���� �ָ� �ִ� ���(���� ���)�� ������ �̷�� ��� �� �ϳ�
 * 3. ������ �̷�� ��忡�� ���� �ָ� �ִ� ���� ������ �̷�� �ٸ� ���
 *
 * �θ�->�ڽ��� ���⸸ �����ϸ� ���� ��忡�� �ٸ� ���� ���� Ž���� �� �����Ƿ� 
     ������ �׷����� ����
 */

int main() {
    int n, p, c, w;

    //�Է�
    cin >> n; //����� ����
    vector<vector<ci>> graph(n + 1, vector<ci>(0));
    for (int i = 1; i < n; i++) { //������ �׷����� �����
        cin >> p >> c >> w; //�θ� ����� ��ȣ, �ڽ� ���, ������ ����ġ
        graph[p].push_back({ c, w });
        graph[c].push_back({ p, w });
    }

    //����
    ci first_node = dfs(1, -1, graph); //������ �����ϴ� ��� �ϳ� ã��
    ci second_node = dfs(first_node.first, -1, graph); //������ �����ϴ� �ٸ� ��� ã��

    //���
    cout << second_node.second; //Ʈ���� ���� ���
    return 0;
}