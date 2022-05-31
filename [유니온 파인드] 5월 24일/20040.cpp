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

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() {
    int n, m, x, y;

    //입력
    cin >> n >> m; //점의 개수, 진행된 차례의 수
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //플레이어가 선택한 두 점의 번호

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클이 생성됨
            cout << i + 1; //사이클이 처음으로 만들어진 차례의 번호 출력
            return 0;
        }
    }
    cout << 0; //종료되지 않았다면 0 출력
    return 0;
}