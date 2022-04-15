#include <iostream>
#include <map>

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 
 * 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //칭호의 전투력 상한값, 그 칭호의 이름

    int n, m, power; //칭호의 개수, 칭호를 출력해야 하는 캐릭터들의 개수, 칭호의 전투력 상한값
    string name; //칭호의 이름

    //입력
    cin >> n >> m;
    while (n--) { //n개의 줄에
        cin >> name >> power; //칭호의 이름, 칭호의 전투력 상한값
        if (title[power].empty()) { //칭호의 전투력 상한값이 비어있으면
            title[power] = name; //칭호의 전투력 상한값을 칭호의 이름으로 처리
        }
    }

    //출력
    while (m--) {
        cin >> power; //캐릭터의 전투력
        //power값을 title에 넣었을 때, 비교 결과 주어진 power값과 같거나 보다 큰 값의 iterator를 리턴
        cout << title.lower_bound(power)->second<< '\n';
    }
}