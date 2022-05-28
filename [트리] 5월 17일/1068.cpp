#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int& erase_node) {
    if (node == erase_node) { //주어진 노드의 번호와 지울 노드의 번호가 같은 경우
        return 0;
    }
    //노드가 비어있거나 노드의 크기가 1이고 지울 노드의 번호가 tree node의 0번째일 경우
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1;
    }
    int cnt = 0; //리프 노드의 개수
    for (int i = 0; i < tree[node].size(); i++) {
        cnt += eraseLeafCnt(tree[node][i], erase_node); //재귀적으로 돌며 cnt 1씩 증가
    }
    return cnt; //cnt return
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 
    더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 
    해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node;

    //입력
    cin >> n; //노드의 개수
    tree.assign(n, vector<int>(0));
    for (int i = 0; i < n; i++) { //0번 노드부터 n-1 노드까지
        cin >> par; //각 노드의 부모
        if (par == -1) { //부모가 없다면
            root = i; //root 설정
            continue;
        }
        tree[par].push_back(i); //tree에 입력
    }
    cin >> erase_node; //지울 노드의 번호

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node); //리프 노드의 개수 출력
    return 0;
}