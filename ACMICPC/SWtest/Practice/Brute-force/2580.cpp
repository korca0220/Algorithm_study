#include <iostream>
#include <algorithm>
#include <vector>
#define SQUARE(x,y) (x/3)*3+(y/3)
using namespace std;


int input[10][10];
bool check_col[10][10];
bool check_row[10][10];
bool check_square[10][10];

void printX(){

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
}

bool getSuc(int index){

    if(index == 81){ // 9*9 endpoint 
        printX();
        return true;
    }
    int x = index/9, y = index%9;
    if(input[x][y] != 0){
        return getSuc(index+1);
    }else{
        for(int i=1; i<=9; i++){ //스도쿠의 수 1~9;
            if(check_col[y][i] == 0 && check_row[x][i] == 0 && check_square[SQUARE(x,y)][i] == 0){
                check_col[y][i] = true;
                check_row[x][i] = true;
                check_square[SQUARE(x,y)][i] = true;
                input[x][y] = i;
                if(getSuc(index+1))return true;
                input[x][y] = 0;
                check_col[y][i] = false;
                check_row[x][i] = false;
                check_square[SQUARE(x,y)][i] = false;
            }
        }
    }
    return false;
}

int main(){

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            scanf("%d", &input[i][j]);
            if(input[i][j] != 0){
                check_col[j][input[i][j]] = true;
                check_row[i][input[i][j]] = true;
                check_square[SQUARE(i, j)][input[i][j]] = true;
            }
        }
    }
    getSuc(0);

    return 0;
}