#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int>& belt) {
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;
    sushi[c]++; //초밥 먹은 개수 증가

    //윈도우 초기화
    for (int i = 0; i < k; i++) {
        if (!sushi[belt[i]]) { //초밥 먹은 개수가 0이 아니면
            section_sushi++; //쿠폰으로 먹은 초밥 수 증가
        }
        sushi[belt[i]]++; //초밥 먹은 개수 증가
    }

    int ans = section_sushi; //ans은 쿠폰으로 먹은 초밥 수
    for (int i = k; i < n + k; i++) { //n+k 전까지 k길이의 슬라이딩 윈도우
        sushi[belt[i - k]]--; //뒤의 초밥 감소
        if (!sushi[belt[i - k]]) { //sushi가 0이 아니면
            section_sushi--; //쿠폰으로 먹은 초밥 수 감소
        }
        if (!sushi[belt[i % n]]) { //sushi가 0이 아니면
            section_sushi++; //쿠폰으로 먹은 초밥 수 증가
        }
        sushi[belt[i % n]]++; //뒤의 초밥 증가
        ans = max(ans, section_sushi); //ans과 쿠폰으로 먹은 초밥 중 큰 값 ans에 갱신
    }
    return ans;
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    //회전 초밥 벨트에 놓인 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0); //vector belt 변수
    //회전벨트 위 초밥
    for (int i = 0; i < n; i++) { //i가 0에서 n까지 반복
        cin >> belt[i]; //vector belt에 입력
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);
    return 0;
}