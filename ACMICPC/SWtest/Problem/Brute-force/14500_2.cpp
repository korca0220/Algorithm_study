#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[501][501];
bool check[501][501];
int ans = 0;
int n,m;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int except_tetro[4][3][2] ={
    {{0,1}, {1,1}, {0,2}},
    {{1,0}, {1,-1}, {1,1}},
    {{1,0}, {1,-1}, {2,0}},
    {{1,0}, {1,1}, {2,0}}
};

void getSum(int x, int y, int sum, int cnt){

    if(cnt == 4){
        if(ans < sum) ans = sum;
        return ;
    }
    if(0>x || x >= n || 0>y || y >= m) return ;
    if(check[x][y]) return ;
    check[x][y] = true;
    for(int i=0; i<4; i++){
        getSum(x+dx[i], y+dy[i], sum+map[x][y], cnt+1);
    }
    check[x][y] = false;

}

int main(){

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            getSum(i,j, 0, 0);
            for(int a=0; a<4; a++){
                int sum = map[i][j];
                for(int b=0; b<3; b++){
                    int nx = i + except_tetro[a][b][0];
                    int ny = j + except_tetro[a][b][1];
                    if(0>nx || nx >= n || 0>ny || ny >= m){
                        sum = 0;
                        break;
                    }
                    sum += map[nx][ny];
                }
            if(ans < sum) ans = sum;
            }
        }
    }
    printf("%d", ans);

    return 0;
}