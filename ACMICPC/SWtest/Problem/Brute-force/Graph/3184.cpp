#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool check[250][250];

char in[250][250];

int r,c;

pair<int,int> bfs(int x, int y){

    int s=0, v=0;
    if(in[x][y] == 'o')s+=1;
    else v+=1;

    queue<pair<int,int>> q;
    q.emplace(x,y);
    check[x][y] = true;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx>=r || 0 > ny || ny>=c) continue;
            if(in[nx][ny] == '#') continue;
            if(check[nx][ny]) continue;

            if(in[nx][ny] == 'o')s+=1;
            else if(in[nx][ny] == 'v')v+=1;
            check[nx][ny] = true;
            q.emplace(nx,ny);
        }
    }
    if(s > v)v=0;
    else s=0;
    
    return make_pair(s,v);
}

int main(){
    scanf("%d %d", &r, &c);
    for(int i=0; i<r; i++){
        cin >> in[i];
    }
    int s=0, v=0;
    for(int i=0; i<r; i++){
        int temp1, temp2;
        for(int j=0; j<c; j++){
            if(in[i][j] == 'o' || in[i][j] == 'v'){
                if(check[i][j]) continue;
                tie(temp1, temp2) = bfs(i, j);
                s+=temp1;
                v+=temp2;
            }
        }
    }
    printf("%d %d", s, v);

    return 0;
}