#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input;
    priority_queue<int> pq; //최대 힙

    //입력
    cin >> n; //아이들과 거점지를 방문한 횟수
    while (n--) {
        cin >> a;
        if (!a) { //아이들을 만난 경우
            if (pq.empty()) { //줄 선물이 없다면
                cout << "-1\n"; //-1 출력
            }
            else { //줄 선물이 있다면
                cout << pq.top() << '\n'; //최대 힙의 top을 출력 후
                pq.pop(); //pop
            }
        }
        else { //선물을 충전하는 경우
            while (a--) {
                cin >> input;
                pq.push(input); //선물들을pq에 push
            }
        }
    }
    return 0;
}