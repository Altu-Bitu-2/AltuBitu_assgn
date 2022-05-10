#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

//다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>>& graph) {
    vector<int> dist(v + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    dist[start] = 0;
    pq.push({ 0, start }); //현재까지 거리, 현재 위치
    while (!pq.empty()) { //pq가 비어있지 않으면
        int weight = pq.top().first; //방문할 점의 weight
        int node = pq.top().second; //방문할 정점
        pq.pop(); //pq에서 맨 앞 원소 제거

        if (weight > dist[node]) { //weight의 값이 dist의 node값보다 크면
            continue; //continue
        }
        for (int i = 0; i < graph[node].size(); i++) { //graph의 node값의 크기만큼 반복
            int next_node = graph[node][i].first; //다음 정점
            int next_weight = weight + graph[node][i].second; //다음 정점의 거리 값 갱신
            if (next_weight < dist[next_node]) { //거리가 작으면 값을 갱신
                dist[next_node] = next_weight; //다음 정점의 weight 값을 다음 정점의 dist에 저장
                pq.push({ next_weight, next_node }); //다음 정점의 weight값 push
            }
        }
    }
    return dist; //dist값 리턴
}

/**
 * [특정한 최단 경로]
 *
 * 가능한 경로
 * 1. 1 -> v1 -> v2 -> n
 * 2. 1 -> v2 -> v1 -> n
 * -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기
 *
 * !주의! 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
 */

int main() {
    int n, e, a, b, c, v1, v2;

    //입력
    cin >> n >> e; //정점의 개수, 간선의 개수
    
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //방향 그래프
    vector<vector<int>> dist(3, vector<int>(n + 1, 0));
    while (e--) { //무방향 그래프
        cin >> a >> b >> c; //a번 정점에서 b번 정점까지 양방향 길이 존재, 그 거리는 c
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    cin >> v1 >> v2; //반드시 거쳐야 하는 두 개의 서로 다른 정점 번호 v1, v2

    //연산
    vector<int> start_nodes = { 1, v1, v2 };
    for (int i = 0; i < 3; i++) { //1, v1, v2에서 시작한 다익스트라 결과 저장
        dist[i] = dijkstra(start_nodes[i], n, graph);
    }

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //출력
    cout << ((ans >= INF) ? -1 : ans); //두 개의 정점을 지나는 최단 경로의 길이 출력, 경로가 없으면 -1 출력
    return 0;
}