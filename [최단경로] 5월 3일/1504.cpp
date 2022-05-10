#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //�ִ� N-1���� ������ ������ �� * �ߺ� ��ȸ ����(3)

//���ͽ�Ʈ��
vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int> dist(v + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    dist[start] = 0;
    pq.push({ 0, start }); //������� �Ÿ�, ���� ��ġ
    while (!pq.empty()) { //pq�� ������� ������
        int weight = pq.top().first; //�湮�� ���� weight
        int node = pq.top().second; //�湮�� ����
        pq.pop(); //pq���� �� �� ���� ����

        if (weight > dist[node]) { //weight�� ���� dist�� node������ ũ��
            continue; //continue
        }
        for (int i = 0; i < graph[node].size(); i++) { //graph�� node���� ũ�⸸ŭ �ݺ�
            int next_node = graph[node][i].first; //���� ����
            int next_weight = weight + graph[node][i].second; //���� ������ �Ÿ� �� ����
            if (next_weight < dist[next_node]) { //�Ÿ��� ������ ���� ����
                dist[next_node] = next_weight; //���� ������ weight ���� ���� ������ dist�� ����
                pq.push({ next_weight, next_node }); //���� ������ weight�� push
            }
        }
    }
    return dist; //dist�� ����
}

/**
 * [Ư���� �ִ� ���]
 *
 * ������ ���
 * 1. 1 -> v1 -> v2 -> n
 * 2. 1 -> v2 -> v1 -> n
 * -> 1, v1, v2�� ���������� �ϴ� ���ͽ�Ʈ�� �Լ� �����ϱ�
 *
 * !����! �� �� �̵��ߴ� ����, ������ �ٽ� �湮�� �� ����. �� 1->N�� �ִ��� INF(1e5*8)�� �ƴ϶� 3*INF!
 */

int main() {
    int n, e, a, b, c, v1, v2;

    //�Է�
    cin >> n >> e; //������ ����, ������ ����
    
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //���� �׷���
    vector<vector<int>> dist(3, vector<int>(n + 1, 0));
    while (e--) { //������ �׷���
        cin >> a >> b >> c; //a�� �������� b�� �������� ����� ���� ����, �� �Ÿ��� c
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    cin >> v1 >> v2; //�ݵ�� ���ľ� �ϴ� �� ���� ���� �ٸ� ���� ��ȣ v1, v2

    //����
    vector<int> start_nodes = { 1, v1, v2 };
    for (int i = 0; i < 3; i++) { //1, v1, v2���� ������ ���ͽ�Ʈ�� ��� ����
        dist[i] = dijkstra(start_nodes[i], n, graph);
    }

    //1->v1->v2->n�� ��ο� 1->v2->v1->n�� ��� �� �ּڰ�
    //������ �׷����� ������ v1->v2�� v2->v1�� ��� ���� ��!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //���
    cout << ((ans >= INF) ? -1 : ans); //�� ���� ������ ������ �ִ� ����� ���� ���, ��ΰ� ������ -1 ���
    return 0;
}