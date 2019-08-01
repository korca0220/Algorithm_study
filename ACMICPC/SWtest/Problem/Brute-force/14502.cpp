#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n,m;
int in[9][9];
int copy_in[9][9];
int wall = 0;
bool check[9][9];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(){

    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            copy_in[i][j] = in[i][j];            
            if(copy_in[i][j] == 2)q.push(make_pair(i,j));
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<= nx && nx < n && 0 <= ny && ny < m){
                if(copy_in[nx][ny] == 0){
                    copy_in[nx][ny] = 2;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(copy_in[i][j] == 0){
                cnt+=1;
            }
        }
    }
    if(wall < cnt) wall = cnt;

}


int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &in[i][j]);
        }
    }

    for(int xa=0; xa<n; xa++){
        for(int ya=0; ya<m; ya++){
            if(in[xa][ya] != 0) continue;
            for(int xb=0; xb<n; xb++){
                for(int yb=0; yb<m; yb++){
                    if(in[xb][yb] != 0) continue;
                    for(int xc=0; xc<n; xc++){
                        for(int yc=0; yc<m; yc++){
                            if(in[xc][yc] != 0) continue;
                            if(xa == xb && ya == yb) continue;
                            if(xa == xc && ya == yc) continue;
                            if(xb == xc && yb == yc) continue;
                            in[xa][ya] = 1;
                            in[xb][yb] = 1;
                            in[xc][yc] = 1;
                            bfs();
                            in[xa][ya] = 0;
                            in[xb][yb] = 0;
                            in[xc][yc] = 0;
                        }
                    }
                }
            }
        }
    }

    printf("%d", wall);


    return 0;
}