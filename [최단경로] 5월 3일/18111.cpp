#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 1e9;

int mineLand(int n, int m, int b, int height, vector<vector<int>>& land) {
    int tot_time = 0; //전체 시간
    for (int i = 0; i < n; i++) { //n만큼 반복
        for (int j = 0; j < m; j++) { //m만큼 반복
            //블록 제거
            if (land[i][j] > height) { //height보다 land의 크기가 크면
                b += (land[i][j] - height); //land의 높이에서 height를 뺀 값을 인벤토리에 저장
                tot_time += 2 * (land[i][j] - height); // 블록 제거하므로 전체 시간에 2초 추가
            }
            //블록 쌓기
            else if (land[i][j] < height) { //height보다 land의 크기가 작으면
                b -= (height - land[i][j]); //height에서 land의 값을 뺀 것을 인벤토리에서 추출
                tot_time += (height - land[i][j]); //블록을 쌓으므로 전체 시간에 1초 추가
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1; //INF+1 return
    return tot_time; //전체 시간 return
}

/**
 * [마인크래프트]
 *
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 * !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
 * 제거하는 건 2초가 걸리고 놓는 건 1초가 걸림.
 */

int main() {
    int n, m, b, min_height = 256, max_height = 0;

    //입력
    cin >> n >> m >> b; // n개의 줄에 각각 m개의 정수, 인벤토리에 있는 블록의 수
    vector<vector<int>> land(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) { //n개의 줄에
        for (int j = 0; j < m; j++) { //각각 m개의 정수로
            cin >> land[i][j]; //땅의 높이가 주어짐
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0;
    for (int i = min_height; i <= max_height; i++) { //최소 높이에서 최대 높이까지 반복
        int t = mineLand(n, m, b, i, land); //t에 전체 시간 저장
        //가장 빨리 작업이 끝나는 높이
        if (t <= min_time) { //계산한 전체 시간이 최소 시간보다 작거나 같으면
            min_time = t; //최소시간에 계산한 전체 시간 저장
            height = i; //height에 i값 저장
        }
    }

    //출력
    cout << min_time << ' ' << height; //작업에 걸리는 최소 시간, 그 경우 땅의 높이
    return 0;
}