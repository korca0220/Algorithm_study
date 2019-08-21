#include <stack>
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int in[501][501][2];
int dist[501][501];
int n;

int dx0[] = {-1,-1,0,0,1,1};
int dy0[] = {-1,0,-1,1,-1,0};
int dx1[] = {-1,-1,0,0,1,1};
int dy1[] = {0,1,-1,1,0,1};

pair<int,int> from[501][501];

bool check(int x, int y){
    if( x < 0 || x>= n) return false;
    if(x%2==0){
        return y<n && y>=0;
    }else{
        return y<n-1 && y>=0;
    }
}

bool moved(int x1, int y1, int x2, int y2){

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
    int ans = x/2 * (2*n-1);
    if(x%2==1){
        ans += n;
    }
    ans += y+1;

    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        if(i%2==0){
            for(int j=0; j<n; j++){
                cin >> in[i][j][0] >> in[i][j][1];
            }
        }else{
            for(int j=0; j<n-1; j++){
                cin >> in[i][j][0] >> in[i][j][1];
            }
        }
    }

    queue<pair<int,int>> q;
    memset(dist, -1, sizeof(dist));

    q.emplace(0,0);
    dist[0][0] = 1;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<6; i++){
            int nx, ny;
            if(x%2==0){
                nx = x + dx0[i];
                ny = y + dy0[i];
            }else{
                nx = x + dx1[i];
                ny = y + dy1[i];
            }
            if(check(nx, ny) == false) continue;
            if(moved(x,y,nx,ny) == false) continue;
            if(dist[nx][ny] != -1 ) continue;
            q.emplace(nx,ny);
            dist[nx][ny] = dist[x][y] + 1;
            from[nx][ny] = make_pair(x,y);
        }
    }
    int x = n-1;
    int y = n-1;

    while(dist[x][y] == -1){
        y -= 1;
        if(y<0){
            y = n-1;
            x -= 1;
            if(x%2==1) y-=1;
        }
    }
    cout << dist[x][y] << "\n";
    stack<pair<int,int>> s;
    while(!(x==0 && y == 0)){
        s.emplace(x,y);
        auto p = from[x][y];
        x = p.first;
        y = p.second;
    }
    s.emplace(x,y);
    while(!s.empty()){
        cout << num(s.top().first, s.top().second) << " ";
        s.pop();
    }

    return 0;
}