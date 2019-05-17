/*
문제
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 50;
int input;
string candy[MAX];


int calculator(){

    // X 축 체크    
    int result = 1;

    for(int i=0; i<input; i++){
        int temp = 1;
        for(int j=1; j<input; j++){
            if ( candy[i][j] == candy[i][j-1] ) temp++;
            else{
                result = max(result, temp);
                temp = 1;
            }
            // 증가하고 끝난 경우
            result = max(result, temp);
        }
    }


    // y 축 체크
    for(int i=0; i<input; i++){
        int temp = 1;
        for(int j=0; j<input-1; j++){
            if ( candy[j][i] == candy[j+1][i])temp++;
            else{
                result = max(result, temp);
                temp = 1;
            }
            result = max(result, temp);
        }
    }    
    return result;
}


int bomboni(){
    
    int final_result=0;
    for(int i=0; i<input; i++){
        for(int j=0; j<input-1; j++){
            swap(candy[i][j], candy[i][j+1]);            
            final_result = max(final_result, calculator());
            swap(candy[i][j], candy[i][j+1]);

            swap(candy[j][i], candy[j+1][i]);            
            final_result = max(final_result, calculator());
            swap(candy[j][i], candy[j+1][i]);            
        }   
    }
    return final_result;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    for(int i=0; i<input; i++){        
        cin >> candy[i];
    }
    int ret = bomboni();
    cout << ret << "\n";
        

    return 0;
}