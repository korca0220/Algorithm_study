#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int in[501][501][2];
int dist[501][501];

pair<int,int> from[501][501];

int dx0[6] = {-1, -1, 0, 0, 1, 1};
int dy0[6] = {-1, 0, -1, 1, -1, 0};
int dx1[6] = {-1, -1, 0, 0, 1, 1};
int dy1[6] = {0, 1, -1, 1, 0, 1};

bool exist_tile(int x, int y){

    if(x < 0 || x >= N) return false;
    if(x%2 == 0){
        return y >=0 && y < N;
    }else{
        return y >=0 && y < N-1;
    }    

}

bool avail_move(int x1, int y1, int x2, int y2){

     if (x1 == x2) {
        if (y1 < y2) {
            return in[x1][y1][1] == in[x2][y2][0];
        } else {
            return in[x1][y1][0] == in[x2][y2][1];
        }
    } else {
        if (x1%2 == 0) {
            if (y1 == y2) {
                return in[x1][y1][1] == in[x2][y2][0];
            } else {
                return in[x1][y1][0] == in[x2][y2][1];
            }
        } else {
            if (y1 == y2) {
                return in[x1][y1][0] == in[x2][y2][1];
            } else {
                return in[x1][y1][1] == in[x2][y2][0];
            }
        }
    }
}

int num(int x, int y){
    int ans = x/2*(N*2-1);
    if(x%2==1){
        ans += N;
    }
    ans += y+1;
    
    return ans;
}

int main(){
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        if(i%2==0){
            for(int j=0; j<N; j++)scanf("%d %d", &in[i][j][0], &in[i][j][1]);
        }else{
            for(int j=0; j<N-1; j++)scanf("%d %d", &in[i][j][0], &in[i][j][1]);
        }
    }
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;        
    q.emplace(0,0);
    dist[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<6; i++){
            int nx,ny;
            if(x%2==0){ // 짝수 줄
                nx = x + dx0[i];
                ny = y + dy0[i];
            }else{
                nx = x + dx1[i];
                ny = y + dy1[i];
            }
            if(exist_tile(nx, ny) == false) continue;
            if(avail_move(x,y, nx, ny) == false) continue;
            if(dist[nx][ny] != -1) continue;            
            dist[nx][ny] = dist[x][y] + 1;
            from[nx][ny] = make_pair(x, y);
            q.emplace(nx,ny);
        }
    }

    int x = N-1;
    int y = N-1;

    while(dist[x][y] == -1){
        y -= 1;
        if(y<0){
            x -= 1;
            y = N-1;
            if(x%2==1)y-=1;
        }
    }

    printf("%d\n", dist[x][y]);
    stack<pair<int,int>> s;
    while(!(x==0 && y==0)){
        s.emplace(x,y);
        auto p = from[x][y];
        x = p.first;
        y = p.second;
    }
    s.emplace(x,y);
    while(!s.empty()){
        printf("%d ", num(s.top().first, s.top().second));
        s.pop();
    }

    return 0;
}