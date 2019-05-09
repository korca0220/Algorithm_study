/*
그림과 같이 4 x 4 개의 격자 형태로 배치된 16개의 시계가 있다. 이 시계들은 모두 12시, 3시, 6시, 혹은 9시를 가리키고 있다. 이 시계들이 모두 12시를 가리키도록 바꾸고 싶다.
시계의 시간을 조작하는 유일한 방법은 모두 10개 있는 스위치들을 조작하는 것으로, 각 스위치들은 모두 적게는 3개에서 많게는 5개의 시계에 연결되어 있다. 한 스위치를 누를 때마다, 해당 스위치와 연결된 시계들의 시간은 3시간씩 앞으로 움직인다. 스위치들과 그들이 연결된 시계들의 목록은 다음과 같다.

0	0, 1, 2
1	3, 7, 9, 11
2	4, 10, 14, 15
3	0, 4, 5, 6, 7
4	6, 7, 8, 10, 12
5	0, 2, 14, 15
6	3, 14, 15
7	4, 5, 7, 14, 15
8	1, 2, 3, 4, 5
9	3, 4, 5, 9, 13
시계들은 맨 윗줄부터, 왼쪽에서 오른쪽으로 순서대로 번호가 매겨졌다고 가정하자. 시계들이 현재 가리키는 시간들이 주어졌을 때, 모든 시계를 12시로 돌리기 위해 최소한 눌러야 할 스위치의 수를 계산하는 프로그램을 작성하시오.

입력
첫 줄에 테스트 케이스의 개수 C (<= 30) 가 주어진다. 
각 테스트 케이스는 한 줄에 16개의 정수로 주어지며, 각 정수는 0번부터 15번까지 각 시계가 가리키고 있는 시간을 12, 3, 6, 9 중 하나로 표현한다.

출력
각 테스트 케이스당 한 줄을 출력한다. 시계들을 모두 12시로 돌려놓기 위해 눌러야 할 스위치의 최소 수를 출력한다. 만약 이것이 불가능할 경우 -1 을 출력한다.

예제 입력
2
12 6 6 6 6 6 12 12 12 12 12 12 12 12 12 12 
12 9 3 12 6 6 9 3 12 9 12 9 12 12 6 6

예제 출력
2
9
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF=9999, SWITCHES=10, CLOCKS=16;

const char linked[SWITCHES][CLOCKS+1] = {
    "XXX.............",
    "...X...X.X.X....",
    "....X.....X...XX",
    "X...XXXX........",
    "......XXX.X.X...",
    "X.X...........XX",
    "...X..........XX",
    "....XX.X......XX",
    ".XXXXX..........",
    "...XXX...X...X.."};

// 모든 시게가 12시를 가리키고 있는지 확인
bool areAligned(const vector<int>& clocks){

    for(int i=0; i<CLOCKS; i++){
        if(clocks[i] != 12) return false;
    }
    return true;
}

// swtch번 시계를 누른다
void push(vector<int>& clocks, int swtch){
    for(int c = 0; c<CLOCKS; ++c){
        if(linked[swtch][c] == 'X'){
            clocks[c] += 3;
            if(clocks[c] == 15) clocks[c] = 3;
        }
    }
}

// clocks : 현재 시계들의 상태
// swtch : 이번에 누를 스위치의 번호
// 위의 값이 주어졌을때 남은 스위치들을 눌러서 clocks를 12시로 만들 수있는 최소수 반환
// 불가능하다면 INF 이상의 큰수를 반환.
int solve(vector<int>& clocks, int swtch){
    if(swtch == SWITCHES) return areAligned(clocks) ? 0:INF;

    // 스위치를 0번 누르는 경우부터 3번 누르는 경우까지 모두 시도
    int ret = INF;
    for(int cnt = 0; cnt<4; cnt++){
        ret = min(ret, cnt + solve(clocks, swtch+1));
        push(clocks, swtch);
    }    
    return ret;
}

int main(){

    int t_input;

    vector<int> clocks;
    clocks.reserve(16);

    scanf("%d", &t_input);
    while(t_input--){
        int ret = 0;
        for(int i=0; i<16; i++){
            scanf("%d", &clocks[i]);
        }
        ret = solve(clocks, 0);
        if(ret >= INF) ret = -1;
        printf("%d\n", ret);
    }

    return 0;
}