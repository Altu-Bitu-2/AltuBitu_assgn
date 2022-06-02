#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //친구 관계가 모두 다른 사용자로 들어왔을 때의 정점 최댓값

vector<int> parent(MAX + 1, -1);
map<string, int> people; //각 이름을 int처럼 사용

//Find 연산
int findParent(int node) { //부모를 찾는 함수
    if (parent[node] < 0) { //노드의 부모가 음수가 될 때까지 재귀
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //같은 집합
        return;
    }
    if (parent[xp] < parent[yp]) { //xp를 root로 하는 노드가 더 많으면
        parent[xp] += parent[yp];
        parent[yp] = xp; //xp의 값을 yp로
    }
    else { //yp를 root로 하는 노드가 더 많으면
        parent[yp] += parent[xp];
        parent[xp] = yp; //yp의 값을 xp로
    }
}

/**
 * [친구 네트워크]
 *
 * 1. weighted union find -> 루트 정점에 친구의 수(집합 원소 수) 저장
 * 2. 친구 네트워크에 몇 명 있는지 구하기 -> 루트 정점의 parent값 접근
 *
 * !주의! 정점이 문자열로 들어오므로 map을 활용해 string을 int로 매핑
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, f;
    string a, b;

    //입력
    cin >> t; //테스트 케이스의 개수
    while (t--) {
        int idx = 1; //정점과 매핑할 수
        parent.assign(MAX + 1, -1); //최대 인원의 수

        cin >> f; //친구 관계의 수
        while (f--) {
            cin >> a >> b; //두 사용자의 아이디
            if (!people[a]) { //map에 아이디가 없으면
                people[a] = idx++; //idx 증가
            }
            if (!people[b]) { //map에 아이디가 없으면
                people[b] = idx++; //idx 증가
            }

            //연산
            int x = people[a], y = people[b];
            unionInput(x, y); //유니온 연산

            //출력
            cout << -parent[findParent(x)] << '\n'; //두 사람의친구 네트워크에 몇 명이 있는지
        }
    }
    return 0;
}