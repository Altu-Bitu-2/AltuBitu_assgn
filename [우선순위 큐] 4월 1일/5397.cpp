#include <iostream>
#include <deque>

using namespace std;

string dqToString(deque<char>& dq) {
    string ans = ""; //초기화
    while (!dq.empty()) { //dq가 비지 않을때까지
        ans += dq.front(); //ans에 dq의 front 더해주기
        dq.pop_front(); //dp의 front pop
    }
    return ans;
}

string findPass(string s) { //비밀번호를 찾는 함수
    deque<char> dq_left;  //커서 이전 내용을 저장
    deque<char> dq_right; //커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
        case '-': //현재 커서 앞에 있는 글자를 지운다.
            if (!dq_left.empty()) { //dq_left가 비어있지 않으면
                dq_left.pop_back(); //글자 pop
            }
            break;
        case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
            if (!dq_left.empty()) { //dq_left가 비어있지 않으면
                dq_right.push_front(dq_left.back()); //dq_left의 마지막을 dq_right 앞에 push
                dq_left.pop_back(); //글자 pop
            }
            break;
        case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
            if (!dq_right.empty()) { //dq_left가 비어있지 않으면
                dq_left.push_back(dq_right.front()); //dq_right의 처음을 dq_left의 마지막에 push
                dq_right.pop_front(); //글자 pop
            }
            break;
        default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
            dq_left.push_back(s[i]); //string s를 dq_left에 push
            break;
        }
    }

    string pass = dqToString(dq_left);
    pass += dqToString(dq_right);
    return pass;
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 
 * 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {
    int t;
    string s;

    //입력
    cin >> t; //테스트 케이스의 개수
    while (t--) {
        cin >> s; //문자열

        //연산 & 출력
        cout << findPass(s) << '\n';
    }
    return 0;
}