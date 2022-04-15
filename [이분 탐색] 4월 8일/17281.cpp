#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이닝이 바뀌어도 누적되는 결과이므로 전역변수로 처리
int score, player; //점수, 타자
vector<int> entry = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }; //선수 순서
vector<vector<int>> board; //결과표

/**
 * 주자들 진루처리 (각 플레이트에 선수가 있는지 없는지 체크)
 * 비트 마스킹을 쓰면 타자 이동 쉽게 처리
 *
 * 1110 : 1, 2, 3루에 주자 존재
 * 0100 : 2루에 주자 존재
 * 1010 : 1, 3루에 주자 존재
 */
void running(int& run, int num) {
    run |= (1 << 0); //0번 플레이트에 타자 표시
    for (int i = (4 - num); i < 4; i++) { //홈까지 진루할 수 있는 주자들
        if (run & (1 << i)) { //주자가 있다면
            run &= ~(1 << i); //주자가 홈인 했기 때문에 플레이트를 비워줌
            score++; //점수 +1
        }
    }
    run = run << num; //주자들 이동
}

//idx 이닝 플레이
void playGame(int idx) {
    int out = 0, run = 0; //아웃카운트, 진루 상태
    while (out != 3) { //아웃카운트가 3 미만일 동안
        int hit = board[idx][entry[player]]; //이번 주자의 결과
        if (!hit) { //아웃
            out++; //아웃카운트 +1
        }
        else { //존재하는 모든 주자 진루
            running(run, hit); //running 함수 호출
        }
        player = (player + 1) % 9; //다음 선수
    }
}

/**
 * 순열, 비트마스킹 풀이
 * 1. 순열로 가능한 모든 타순을 구한다. (순열)
 *    4번 타자는 항상 1번 선수여야 하기 때문에 2번 ~ 9번 선수에 대해서만 순열을 돌린다.
 * 2. 엔트리에 대한 점수를 계산한다. 1~3루와 홈베이스 총 4개의 플레이트에 대해 선수의 존재여부를 비트로 표현한다.
 *
 * 해설 : https://myunji.tistory.com/439?category=1154147
 */

int main() {
    int n, ans = 0; //이닝 수, 얻을 수 있는 최대 점수

    //입력
    cin >> n; //이닝 수
    board.assign(n, vector<int>(9)); //결과표 board를 vector<int>(9)fmf n개 가지는 벡터로 만든다
    for (int i = 0; i < n; i++) { //n개의 줄
        //안타: 1, 2루타: 2, 3루타: 3, 홈런:4, 아웃: 0
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j]; //각 선수가 각 이닝에서 얻는 결과
        }
    }

    //연산
    do {
        //2-9번 선수들에 대해서만 순열 돌린 후 
        swap(entry[0], entry[3]); //1번 선수 4번 타자 되도록 바꿔준다
        score = player = 0; //초기화
        for (int i = 0; i < n; i++) { //각 n번 이닝 플레이
            playGame(i);
        }
        ans = max(ans, score); //최댓값 갱신
        swap(entry[3], entry[0]); //원래대로 복구
    } while (next_permutation(entry.begin() + 1, entry.end())); //모든 순열을 돌린 후

    //출력
    cout << ans; //최댓값 출력
    return 0;
}