/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
 */

#include <iostream>
#include <vector>
using namespace std;

int N;
bool check_col[15];
bool check_l[225]; // abs(row-col)
bool check_r[225]; // row+col
int cnt=0;
bool check(int row, int col){

    if(check_col[col]) return false;
    if(check_l[row-col+N]) return false;
    if(check_r[row+col]) return false;

    return true;
}

void findCase(int row){

    if(row==N)cnt+=1;

    for(int col=0; col<N; col++){
        if(check(row, col)){
            check_col[col] = true;
            check_l[row-col+N] = true;
            check_r[row+col] = true;
            findCase(row+1);
            check_col[col] = false;
            check_l[row-col+N] = false;
            check_r[row+col] = false;
        }
    }
}

int main(){

    scanf("%d", &N);
    findCase(0);
    printf("%d", cnt);

    return 0;
}