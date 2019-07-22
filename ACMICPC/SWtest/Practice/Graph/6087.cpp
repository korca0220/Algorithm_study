#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(vector<string> &a, vector<vector<int>> &dist, int sx, int sy){

    int n = a.size();
    int m = a[0].size();
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    dist[sx][sy] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx= x + dx[i];
            int ny= y + dy[i];
            while(0<=nx && nx <n && 0<=ny && ny < m){
                if(a[nx][ny] == '*')break;
                if(dist[nx][ny] == -1){
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y] + 1;    
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }    
}

int main(){
    int w,h;
    scanf("%d %d", &w, &h);
    vector<string> in(h);
    for(int i=0; i<h; i++){
        cin >> in[i];
    }

    vector<vector<int>> dist(h, vector<int>(w, -1));

    int x1,y1,x2,y2;
    x1=y1=x2=y2= -1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(in[i][j] == 'C'){
                if(x1 == -1){
                    x1=i; y1=j;
                }else{
                    x2=i; y2=j;
                }
            }
        }
    }
    bfs(in, dist, x1, y1);
    printf("%d", dist[x2][y2]-1);

    return 0;
}