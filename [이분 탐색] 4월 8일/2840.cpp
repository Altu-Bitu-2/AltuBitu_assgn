#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci; //typedef를 통해 pair 재정의

//특정 화살표에서 시작한 행운의 바퀴 리턴하는 함수
string arrowStartWheel(int arrow_point, int n, vector<char>& wheel) {
    string ans = ""; //ans 초기화
    int start = arrow_point; //start 변수를 arrow_point로 저장
    do { //반복
        ans += wheel[arrow_point]; //ans에 
        arrow_point = (arrow_point + 1) % n;
    } while (arrow_point != start); //arrow_point의 값이 start의 값이 아닐 때까지
    return ans; //ans 리턴
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci>& record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스 초기화
    for (int i = 0; i < record.size(); i++) {
        int rot = record[i].first; //화살표가 가리키는 글자가 몇 번 바뀌었는지
        char alpha = record[i].second; //회전을 멈추었을 때 가리키는 글자
        idx = (idx - rot % n + n) % n; //화살표가 가르키는 인덱스 바꿔줌
        if (wheel[idx] == alpha) { //바퀴의 화살표가 가리키는 인덱스가 멈추었을때 가리키는 글자와 같으면 
            continue; //continue
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) { //적어놓은 종이에 해당하는 행운의 바퀴가 없다면
            return "!"; //! 출력
        }
        wheel[idx] = alpha; //해당 칸에 글자 기록
        is_available[alpha - 'A'] = true; //글자 사용 처리
    }
    return arrowStartWheel(idx, n, wheel); //인덱스에서 시작한 행운의 바퀴 수를 리턴하는 함수
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 
     조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 
     동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k; //바퀴의 칸의 수, 상덕이가 바퀴를 돌리는 횟수

    //입력
    cin >> n >> k;
    vector<ci> record(k, { 0, 0 }); //바퀴 회전 기록
    for (int i = 0; i < k; i++) { //k줄
        //바퀴를 회전시켰을 때 화살표가 가리키는 글자가 몇번 바뀌는지
        //회전을 멈추었을 때 가리키던 글자
        cin >> record[i].first >> record[i].second;
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0;
}