#include <iostream>
#include <vector>

using namespace std;

vector<int> possibleWeight(int left, int right, int g) {
    vector<int> ans; //vector ans 변수
    while (left < right) { //성원이의 현재 몸무게가 성원이가 기억하고 있던 몸무게보다 크면
        int diff = right * right - left * left; //성원이의 현재 몸무게의 제곱에서 성원이가 기억하고 있던 몸무게의 제곱을 뺀 값

        if (diff <= g) { //diff의 값이 g보다 작거나 같으면
            if (diff == g) { //diff의 값이 g이면
                ans.push_back(right); //ans vector에 성원이의 현재 몸무게 push
            }
            right++; //성원이의 현재 몸무게 값 증가
        }
        else { //diff의 값이 g보다 크면
            left++; //성원이가 기억하고 있던 몸무게의 값 증가
        }
    }
    return ans; //ans값 return
}

/**
 * [다이어트]
 *
 * left: 성원이가 기억하고 있던 몸무게
 * right: 성원이의 현재 몸무게
 *
 * 같은 위치에서 시작해서 점점 증가하는 투 포인터로 풀이
 * 대신, left ~ right를 모두 고려하는 것이 아니라 left, right 포인터 값 자체만 고려
 *
 * !주의! 몸무게의 범위가 딱히 정해져 있지 않으므로, 종료 조건을 잘 세우는 것이 중요!
 *       -> 두 몸무게가 같아지는 순간 종료!
 *       -> left가 right와 같은 값을 가진다면, 직전 상황은 두 몸무게가 1차이 나는 상황
 *       -> 이때 몸무게 차이가 g 이상이었다는 것은 이후로 나올 수 있는 차이는 무조건 g이상이 된다. (제곱수의 간격은 수가 커질수록 늘어나기 때문)
 */

int main() {
    int g; //현재 몸무게의 제곱에서 기억하고 있던 몸무게의 제곱을 뺀 것

    //입력
    cin >> g;

    //연산
    //기억하고 있던 몸무게가 1이고 현재 몸무게가 2인 값을 possibleWeight 함수에 적용
    vector<int> ans = possibleWeight(1, 2, g); 

    //출력
    if (!ans.size()) { //ans의 크기가 0이 아니면
        cout << "-1"; //-1 출력
        return 0;
    }
    for (int i = 0; i < ans.size(); i++) { //i가 0부터 ans의 크기까지 반복
        cout << ans[i] << '\n'; //vector ans의 값 출력
    }
    return 0;
}