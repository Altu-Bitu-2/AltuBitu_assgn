#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll finalChildren(ll t, vector<int>& rides) { //주어진 t까지 놀이기구를 탄 아이들 수 구하는 함수
    ll child = 0; //child 변수 초기화
    for (int i = 1; i < rides.size(); i++) { //놀이기구의 종류 수만큼 반복
        child += (t / rides[i] + 1); //해당 시각까지 놀이기구를 탄 아이들 수를 카운트
    }
    return child; //아이들 수 리턴
}

ll lowerSearch(ll left, ll right, ll target, vector<int>& rides) {
    while (left <= right) { //left의 값이 right의 값보다 작거나 같으면
        ll mid = (left + right) / 2; //left와 right의 중간값인 mid 저장
        ll child = finalChildren(mid, rides); //finalChildren의 함수 리턴값 child에 저장

        if (child >= target) { //줄의 마지막 아이보다 더 뒤에 있는 아이라면
            right = mid - 1; //right값은 mid -1
        }
        else { //줄의 마지막 아이보다 뒤에 있는 아이가 아니라면
            left = mid + 1; //left값은 mid+1
        }
    }
    return left; //left값 리턴
}

int findRides(int n, int m, vector<int>& rides) {
    ll t = lowerSearch(0, (ll)rides[1] * n, n, rides); //t는 최대 아이들 수 * 최대 놀이기구 시간을 넣은 lowerSearch 함수의 리턴값
    ll child = finalChildren(t, rides); //finalChildren함수의 리턴 값을 child에 저장
    for (int i = m; i >= 1; i--) {
        if (t % rides[i] == 0) { //아이가 탐
            if (child-- == n) { //놀이기구를 탄 아이들 수가 n이면
                return i; //놀이기구 번호를 리턴
            }
        }
    }
}

/**
 * [놀이 공원]
 *
 * n번째 아이가 놀이기구를 타는 시간을 구한 후, 해당 시간에 놀이기구를 타는 아이들을 모두 검사하며 n번째 아이가 타는 놀이기구의 번호를 구한다!
 *
 * 1. n번째 아이가 놀이기구를 타는 시간이 언제인지 parametric search 통해 구함
 *    - 이때, 각 시간 별 놀이기구 타는 아이의 마지막 번호 구하는 공식은 다음과 같음
 *      f(t) = (모든 i(놀이 기구)에 대해서) t/num[i] + n(시간 0일때 놀이기구 타는 아이 수)
 *
 *    - left: 놀이기구 타는 시간의 최소 = 0
 *    - right: 놀이기구 타는 시간의 최대 = 1번 놀이기구 운행 시간 x n (타이트하게 잡으면 최소 운행 시간 x n 이지만 편의상 이렇게 설정)
 *
 *    - n번째 아이가 놀이기구를 타는 첫 시간을 구해야 하므로 lower bound
 *
 * 2. n번째 아이가 놀이기구를 타는 시간을 구했다면, 그 시간에 마지막으로 놀이기구를 타는 아이부터 시작해서
 *    놀이기구를 m부터 탐색하면서 n번째 아이가 몇 번 놀이기구 타는지 구하면 됨!
 */

int main() {
    int n, m; //아이들 수, 놀이기구의 종류 수

    //입력
    cin >> n >> m;
    vector<int> rides(m + 1, 0); //각 놀이기구의 운행 시간을 저장하는 vector
    for (int i = 1; i <= m; i++) {
        cin >> rides[i]; //각 놀이기구의 운행 시간을 나타내는 m개의 수
    }

    if (n <= m) { //아이의 수가 놀이기구 수보다 적다면
        cout << n; //아이들 수 출력
        return 0;
    }

    //연산 & 출력
    cout << findRides(n, m, rides); //마지막 아이가 타게 되는 놀이기구의 번호 출력
    return 0;
}