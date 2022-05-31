#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) { //부모 노드를 확인
    if (parent[node] < 0) { //부모 노드가 음수가 될 때까지 재귀함수
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모
    int yp = findParent(y); //y의 부모

    if (xp == yp) { //부모 노드가 같으면 사이클이 생김
        return false; //false 반환
    }
    if (parent[xp] < parent[yp]) { //xp를 root로 하는 노드가 더 많으면
        parent[xp] += parent[yp];
        parent[yp] = xp; //xp의 값을 yp로
    }
    else { //yp를 root로 하는 노드가 더 많으면
        parent[yp] += parent[xp];
        parent[xp] = yp; //yp의 값을 xp로
    }
    return true;
}

int liarParty(vector<int>& parties) {
    int cnt = 0;
    for (int i = 0; i < parties.size(); i++) { //파이 정보의 첫번째 사람만 체크
        if (findParent(parties[i]) != findParent(0)) { 
            cnt++;
        }
    }
    return cnt;
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m; //사람의 수, 파티의 수
    parent.assign(n + 1, -1);

    int init, p;
    cin >> init; //진실을 아는 사람의 수
    while (init--) { //진실을 아는 사람들
        cin >> p; //진실을 아는 사람의 번호
        unionInput(0, p);
    }

    int cnt, first_person, person;
    vector<int> parties;
    while (m--) {
        cin >> cnt >> first_person; //각 파티마다 오는 사람의 수, 첫번째 사람의 번호

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) {
            cin >> person; //각 파티마다 오는 사람의 번호
            unionInput(first_person, person);
        }
    }

    //연산 & 출력
    cout << liarParty(parties); //파티의 개수의 최댓값
    return 0;
}