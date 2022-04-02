#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF_MAX = 1e9;
const int SIZE = 11;

int n;
vector<int> num(SIZE + 1);
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum); // max_value와 sum 중 최댓값 변수 저장
        min_value = min(min_value, sum); // min_value와 sum 중 최솟값 변수 저장
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {
            expression[i]--; //연산자 하나 사용했으므로 1개 감소
            int new_sum = 0;
            switch (i) { //연산자 종류에 따라
            case 0: // + 일 때
                new_sum = sum + num[cnt + 1];
                break;
            case 1: // - 일 때
                new_sum = sum - num[cnt + 1];
                break;
            case 2: // * 일 때
                new_sum = sum * num[cnt + 1];
                break;
            case 3: // / 일 때
                new_sum = sum / num[cnt + 1];
                break;
            }
            backtracking(cnt + 1, new_sum); // 최댓값과 최솟값 변수 저장
            expression[i]++; //다른 연산자를 사용할 것이므로 아까 줄였던 연산자의 개수 늘려줌
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n; // 수의 개수
    for (int i = 0; i < n; i++) {
        cin >> num[i]; //A1부터 An까지 입력
    }
    for (int i = 0; i < 4; i++) {
        cin >> expression[i]; // 덧셈의 개수, 뺄셈의 개수, 곱셈의 개수, 나눗셈의 개수
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}