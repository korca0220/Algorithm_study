#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int w,h;
bool check[100][100];
int land[100][100];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0 ,1 ,1 ,1};

void bfs(int x, int y){

    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        int n = q.front().first;
        int m = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int nx = n + dx[i];
            int ny = m + dy[i];
            if(0<= nx && nx <w && 0<=ny && ny<h){
                if(check[nx][ny] == false && land[nx][ny] == 1){
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                }
            }
        }
    }

}

int main(){

    while(true){
        scanf("%d %d", &h, &w);
        if(w==0 && h ==0)break;
        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                scanf("%d", &land[i][j]);
                check[i][j] = false;
            }
        }
        int cnt=0;
        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                if(land[i][j] == 1 && check[i][j] == false){
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}