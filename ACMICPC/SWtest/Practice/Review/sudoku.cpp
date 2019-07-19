#include <iostream>
#include <vector>
#include <algorithm>
#define SQUARE(x,y) (x/3)*3 + (y/3)
using namespace std;

int N = 9;
bool check_col[10][10];
bool check_row[10][10];
bool check_square[10][10];
int input[10][10];

bool check(int x, int y, int value){

    if(check_col[y][value]) return false;
    if(check_row[x][value]) return false;
    if(check_square[SQUARE(x,y)][value]) return false;
    return true;
}

void print(){

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }

}

bool fillSudoku(int z){

    if(z==81){
        print();
        return true;
    }
    int x = z/N, y = z%N;
    if(input[x][y] != 0)return fillSudoku(z+1);

    for(int i=1; i<=9; i++){
        if(check(x,y,i)){
            check_col[y][i] = true;
            check_row[x][i] = true;
            check_square[SQUARE(x,y)][i] = true;
            input[x][y] = i;
            if(fillSudoku(z+1)) return true;
            input[x][y] = 0;
            check_col[y][i] = check_row[x][i] = check_square[SQUARE(x,y)][i] = false;
        }
    }
    return false;

}


int main(){

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf(" %d", &input[i][j]);
            check_row[i][input[i][j]] = true;
            check_col[j][input[i][j]] = true;
            check_square[SQUARE(i,j)][input[i][j]] = true;
        }
    }
    fillSudoku(0);

    return 0;
}