#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<bool> is_valid;

//최대 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMax(priority_queue<ci>& heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) {
        heap.pop();
    }
}

//최소 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMin(priority_queue<ci, vector<ci>, greater<>>& heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) {
        heap.pop();
    }
}

/**
 * 우선순위 큐 풀이
 * 최대 힙과 최소 힙을 동시에 관리하면서 각각의 힙에서 삭제된 데이터를 다른 힙에 반영하는 방법
 * -> 각 데이터의 유효성을 체크하는 배열을 만들기
 */
int main() {
    int t, k, n;
    char cmd;

    cin >> t; //입력 데이터의 수
    while (t--) { //입력 데이터의 수만큼 while문 돌리기
        priority_queue<ci> max_heap; //최대 힙
        priority_queue<ci, vector<ci>, greater<>> min_heap; //최소 힙
        cin >> k; //우선순위 큐Q에 적용할 연산의 개수를 나타내는 정수
        int idx = 0; //I 연산으로 입력된 숫자의 인덱스
        while (k--) {
            //입력
            cin >> cmd >> n;

            //연산
            switch (cmd) {
            case 'I': //정수를 Q에 삽입하는 연산
                max_heap.push(ci(n, idx)); //최대힙에 값을 넣고
                min_heap.push(ci(n, idx)); //최소힙에 값을 넣은 후
                is_valid.push_back(true); //is_valid 벡터에도 추가
                idx++;
                break;
            case 'D': //삭제하는 연산
                if (n == 1) { //Q에서 최댓값을 삭제하는 연산
                    deleteMax(max_heap); //D연산 전처리
                    if (!max_heap.empty()) { //D연산
                        is_valid[max_heap.top().second] = false; //is_valid 벡터에 삭제
                        max_heap.pop(); //최대 힙에서 데이터 삭제
                    }
                }
                if (n == -1) { //Q에서 최솟값을 삭제하는 연산
                    deleteMin(min_heap); //D연산 전처리
                    if (!min_heap.empty()) { //D연산
                        is_valid[min_heap.top().second] = false;
                        min_heap.pop(); //최소 힙에서 데이터 삭제
                    }
                }
                break;
            }
        }
        //마지막으로 각 힙의 top이 valid 하도록 처리
        deleteMax(max_heap);
        deleteMin(min_heap);

        //출력
        if (max_heap.empty()) { //Q가 비어있다면
            cout << "EMPTY\n";
        }
        else { //Q에 남아 있는 값 중 최댓값과 최솟값 출력
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n';
        }
        is_valid.clear(); //새로운 테스트 케이스 전 is_valid 벡터 초기화
    }
}