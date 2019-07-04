#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int R,C;
bool check[256];
char alpha[25][25];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int findMax(int x, int y){

    int ans = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx <R && 0<= ny && ny<C){
            if(check[alpha[nx][ny]]==false){
                check[alpha[nx][ny]] = true;
                int next = findMax(nx, ny);
                if(next > ans) ans = next;
                check[alpha[nx][ny]] = false;
            }
        }
    }
    return ans + 1;
}

int main(){

    scanf("%d %d", &R, &C);
    string str;
    for(int i=0; i<R; i++){
        cin >> str;
        for(int j=0; j<C; j++){
            alpha[i][j] = str[j];
        }
    }
    check[alpha[0][0]] = true;
    printf("%d", findMax(0, 0));


    return 0;
}