#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; //�ִ� n-1���� ������� �����Ƿ� -> n * (����ġ �ִ밪)

//���ͽ�Ʈ��
ci dijkstra(int start, int v, vector<vector<ci>>& graph) {
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(v + 1, INF); //�Ÿ�

    dist[start] = 0; //�Ÿ��� ó���� 0
    pq.push({ 0, start }); //������ push
    //INF�� �ƴ� �� �߿��� ���� ū ���� ��� PC ���� �ð�
    //INF�� �ƴ� ������ ������ ������ ��ǻ���� ��
    int cnt = 0, t = 0;
    while (!pq.empty()) { //pq�� ������� ������
        int weight = pq.top().first; //�湮�� ���� weight (�����ð�) (��������)
        int node = pq.top().second; //�湮�� ����
        pq.pop(); //pq���� �� �� ���� ����

        if (weight > dist[node]) { //weight�� ���� dist�� node������ ũ��
            continue; //continue
        }
        cnt++; //cnt�� ����
        t = weight; //weight�� �� t�� ����
        for (int i = 0; i < graph[node].size(); i++) { //graph�� node���� ũ�⸸ŭ �ݺ�
            int next_node = graph[node][i].first; //���� ����
            int next_weight = weight + graph[node][i].second; //���� ������ ���� �ð�
            if (next_weight < dist[next_node]) { //���� ���� ������ ���� �ð��� ���� ������ dist���� ������
                dist[next_node] = next_weight; //���� ������ ���� �ð��� ���� ������ dist�� ����
                pq.push({ next_weight, next_node }); //���� ������ ���� �ð� push
            }
        }
    }
    return { cnt, t };
}

/**
 * [��ŷ]
 *
 * - �⺻���� ���ͽ�Ʈ�� ����
 * - ���ͽ�Ʈ�� ������ �̹� �� ª�� ��ΰ� �����ϴ� ������ Ž������ �����ϸ鼭, 
 *    Ž���ϴ� ������ ���� ������ �ð��� ����
 *
 * !����! �׷��� ���� ��, a�� b�� �����Ѵٴ� �� b ���� �� a�� �����ȴٴ� ���̹Ƿ� b -> a ������
 */

int main() {
    int t, n, d, c, a, b, s;

    //�Է�
    cin >> t; //�׽�Ʈ ���̽��� ����
    while (t--) { //�׽�Ʈ ���̽��� ������ŭ �ݺ�
        cin >> n >> d >> c; //��ǻ�� ����, ������ ����, ��ŷ���� ��ǻ���� ��ȣ
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); //���� �׷���
        while (d--) { //�������� ������ŭ �ݺ�
            //�� �������� ��Ÿ���� ������
            cin >> a >> b >> s; //a�� b�� ����
            graph[b].push_back({ a, s }); //b�� �����Ǹ� a�� s�� �Ŀ� ����
        }

        //����
        ci ans = dijkstra(c, n, graph); //���ͽ�Ʈ�� �˰��� �̿��ؼ� ans �� ���ϱ�

        //���
        cout << ans.first << ' ' << ans.second << '\n'; //�� �����Ǵ� ��ǻ�� ��, ������ ��ǻ�Ͱ� �����Ǳ���� �ɸ��� �ð�
    }
    return 0;
}