#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& table) {
    for (int k = 1; k <= n; k++) { //k는 거쳐가는 정점
        for (int i = 1; i <= n; i++) { //i는 행 (출발 정점)
            for (int j = 1; j <= n; j++) { //j는 열 (도착 정점)
                //정점 i에서 정점 n을 거쳐서 정점 j로 갈 때,
                int new_dist = graph[i][k] + graph[k][j];
                //n을 거쳐가는 것이 더 최단 경로일 경우 업데이트
                if (new_dist < graph[i][j]) {
                    graph[i][j] = new_dist;
                    table[i][j] = table[i][k];
                }
            }
        }
    }
}

/**
 * [택시]
 *
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 14을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */

int main() {
    int n, m, s, d, c;

    //입력
    cin >> n >> m; //집하장의 개수, 집하장간 경로의 개수
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //방향 그래프
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0)); //경로표
    for (int i = 1; i <= n; i++) { //n의 크기만큼 반복
        graph[i][i] = 0; //좌표 (i, i)는 0으로 저장
    }

    while (m--) { //무방향 그래프
        cin >> s >> d >> c; //두 집하장의 번호, 그 사이를 오가는데 필요한 시간
        //간선 정보
        graph[s][d] = graph[d][s] = c; 

        //경로 정보
        table[s][d] = d; 
        table[d][s] = s;
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for (int i = 1; i <= n; i++) { //i는 n의 크기만큼 반복
        for (int j = 1; j <= n; j++) { //j는 n의 크기만큼 반복
            if (i == j) { //i와 j의 값이 같다면
                cout << "- "; //- 출력
            }
            else { //i와 j의 값이 다르다면
                cout << table[i][j] << ' '; //경로표 출력
            }
        }
        cout << '\n';
    }
    return 0;
}