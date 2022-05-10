#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e7; //최대 n-1개의 연결관계 있으므로 -> n * (가중치 최대값)

//다익스트라
ci dijkstra(int start, int v, vector<vector<ci>>& graph) {
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(v + 1, INF); //거리

    dist[start] = 0; //거리의 처음은 0
    pq.push({ 0, start }); //시작점 push
    //INF가 아닌 수 중에서 가장 큰 값이 모든 PC 감염 시간
    //INF가 아닌 수들의 개수가 감염된 컴퓨터의 수
    int cnt = 0, t = 0;
    while (!pq.empty()) { //pq가 비어있지 않으면
        int weight = pq.top().first; //방문할 점의 weight (감염시간) (오름차순)
        int node = pq.top().second; //방문할 정점
        pq.pop(); //pq에서 맨 앞 원소 제거

        if (weight > dist[node]) { //weight의 값이 dist의 node값보다 크면
            continue; //continue
        }
        cnt++; //cnt값 증가
        t = weight; //weight의 값 t에 저장
        for (int i = 0; i < graph[node].size(); i++) { //graph의 node값의 크기만큼 반복
            int next_node = graph[node][i].first; //다음 정점
            int next_weight = weight + graph[node][i].second; //다음 정점의 감염 시간
            if (next_weight < dist[next_node]) { //만약 다음 정점의 감염 시간이 다음 정점의 dist보다 작으면
                dist[next_node] = next_weight; //다음 정점의 감염 시간은 다음 정점의 dist에 저장
                pq.push({ next_weight, next_node }); //다음 정점의 감염 시간 push
            }
        }
    }
    return { cnt, t };
}

/**
 * [해킹]
 *
 * - 기본적인 다익스트라 문제
 * - 다익스트라 내에서 이미 더 짧은 경로가 존재하는 정점은 탐색에서 배제하면서, 
 *    탐색하는 정점의 수와 마지막 시간을 저장
 *
 * !주의! 그래프 생성 시, a가 b를 의존한다는 건 b 감염 후 a가 감염된다는 뜻이므로 b -> a 방향임
 */

int main() {
    int t, n, d, c, a, b, s;

    //입력
    cin >> t; //테스트 케이스의 개수
    while (t--) { //테스트 케이스의 개수만큼 반복
        cin >> n >> d >> c; //컴퓨터 개수, 의존성 개수, 해킹당한 컴퓨터의 번호
        vector<vector<ci>> graph(n + 1, vector<ci>(0)); //방향 그래프
        while (d--) { //의존성의 개수만큼 반복
            //각 의존성을 나타내는 정수들
            cin >> a >> b >> s; //a가 b를 의존
            graph[b].push_back({ a, s }); //b가 감염되면 a는 s초 후에 감염
        }

        //연산
        ci ans = dijkstra(c, n, graph); //다익스트라 알고리즘 이용해서 ans 값 구하기

        //출력
        cout << ans.first << ' ' << ans.second << '\n'; //총 감염되는 컴퓨터 수, 마지막 컴퓨터가 감염되기까지 걸리는 시간
    }
    return 0;
}