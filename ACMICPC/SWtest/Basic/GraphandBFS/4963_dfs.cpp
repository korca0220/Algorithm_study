#include <iostream>
#include <algorithm>
using namespace std;

int W,H;
int check[50][50];
int node[50][50];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0, -1,-1,-1, 0, 1, 1,  1};

void dfs(int x, int y, int cnt){

    check[x][y] = cnt;
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<= nx && nx<W && 0<= ny && ny<H){
            if(node[nx][ny] == 1 && check[nx][ny] == 0){
                dfs(nx, ny, cnt);
            }
        }
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin >> H >> W;
        if(W == 0 && H == 0)break;

        for(int i=0; i<W; i++){
            for(int j=0; j<H; j++){
                cin >> node[i][j];
                check[i][j] = 0;
            }
        }

        int cnt=0;
        for(int i=0; i<W; i++){
            for(int j=0; j<H; j++){
                if(node[i][j] == 1 && check[i][j] == 0){
                    dfs(i, j, ++cnt);
                }
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}