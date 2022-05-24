#include <iostream>

using namespace std;

struct node_info { //노드의 정보 구조체
    int data; //노드의 데이터
    node_info* left; //노드의 왼쪽
    node_info* right; //노드의 오른쪽
};

node_info* makeTree(node_info* node, int data) {
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); //동적 할당
        node->data = data; //노드의 데이터 할당
        node->left = node->right = NULL; //노드의 왼쪽과 오른쪽 null로 할당
    }
    else if (node->data > data) { //노드의 데이터가 주어진 데이터보다 크면
        node->left = makeTree(node->left, data); //노드의 왼쪽으로 이동
    }
    else if (node->data < data) { //노드의 데이터가 주어진 데이터보다 작으면
        node->right = makeTree(node->right, data); //노드의 오른쪽으로 이동
    }
    return node; //노드 리턴
}

//후위 순회: root 노드를 제일 마지막에 방문하는 순회 방법
void postorder(node_info* node) {
    if (node == NULL) { //노드가 null이면
        return;
    }
    //재귀적 방법을 통해 구현
    postorder(node->left);
    postorder(node->right);
    //타고 들어갈 자식 노드가 없다면 현재 노드의 data 값을 출력
    cout << node->data << '\n';
}

/**
 * 맵과 셋 PPT 중 BST 노드 삽입 과정 참고
 *
 * [이진 검색 트리]
 *
 * 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 * 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 * 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 * 4. 완성한 트리를 후위 순회
 */

int main() {
    int input; //트리를 전위 순회한 결과

    //입력 & 연산
    node_info* root = NULL;
    while (cin >> input) { //트리를 전위 순회한 결과 입력
        root = makeTree(root, input); //tree 설정
    }

    //출럭
    postorder(root); //이진 검색 트리를 후위 순회한 결과
    return 0;
}