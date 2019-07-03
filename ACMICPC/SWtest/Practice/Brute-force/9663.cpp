#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool check_col[15]; // "|"
bool check_dig1[100]; // "/"
bool check_dig2[100]; // "\"

bool check(int row, int col){

    if(check_col[col]) return false;
    if(check_dig1[row+col]) return false;
    if(check_dig2[row-col+N]) return false;

    return true;
}

int findNum(int row){

    if(row == N){
        return 1;
    }
    int total = 0;
    for(int col=0; col<N; col++){
        if(check(row, col)){
            check_col[col] = true;
            check_dig1[row+col] = true;
            check_dig2[row-col+N] = true;
            total += findNum(row+1);
            check_col[col] = false;
            check_dig1[row+col] = false;
            check_dig2[row-col+N] = false;
        }
    }
    return total;

}

int main(){

    scanf("%d", &N);
    printf("%d", findNum(0));

    return 0;
}