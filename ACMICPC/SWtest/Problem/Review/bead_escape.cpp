#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int d[10][10][10][10];
int n,m;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

pair<bool, bool> simulate(vector<string> &in, int &x, int &y, int dir){

    if(in[x][y] == '.') return make_pair(false, false);
    bool moved = false;
    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0 || nx>=n || ny<0 || ny>=m) return make_pair(moved, false);
        if(in[nx][ny] == '#') return make_pair(moved, false);
        else if(in[nx][ny] == 'R' || in[nx][ny] == 'B') return make_pair(moved, false);
        else if(in[nx][ny] == '.'){
            swap(in[nx][ny], in[x][y]);
            moved = true;
            x = nx; y = ny;
        }else if(in[nx][ny] == 'O'){
            moved = true;
            in[x][y] = '.';
            return make_pair(moved, true);
        }        
    }
    return make_pair(false, false);
}

pair<bool, bool> next(vector<string> in, int &rx, int &ry, int &bx, int &by, int dir){

    in[rx][ry] = 'R';
    in[bx][by] = 'B';
    bool hole1=false, hole2=false;
    while(true){
        auto p1 = simulate(in, rx,ry, dir);
        auto p2 = simulate(in, bx,by, dir);

        if(p1.first == false && p2.first == false) break;

        if(p1.second)hole1 = true;
        if(p2.second)hole2 = true;

    }
    return make_pair(hole1, hole2);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int rx,ry,bx,by;
    vector<string> in(n);
    for(int i=0; i<n; i++){
        cin >> in[i];
        for(int j=0; j<m; j++){
            if(in[i][j] == 'R'){
                rx = i; ry = j;
                in[i][j] = '.';
            }else if(in[i][j] == 'B'){
                bx = i; by = j;
                in[i][j] = '.';
            }
        }
    }
    memset(d, -1, sizeof(d));
    queue<tuple<int,int,int,int>> q;
    q.emplace(rx,ry,bx,by);
    d[rx][ry][bx][by] = 0;
    int ans = -1;
    bool found = false;
    while(!q.empty()){
        tie(rx,ry,bx,by) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nrx = rx; int nry = ry;
            int nbx = bx; int nby = by;
            bool hole1, hole2; // hole1=red, hole2=blue
            tie(hole1, hole2) = next(in, nrx, nry, nbx, nby, i);
            if(hole2) continue;
            if(hole1){
                found = true;
                ans = d[rx][ry][bx][by] + 1;
                break;
            }
            if(d[nrx][nry][nbx][nby] != -1) continue;
            d[nrx][nry][nbx][nby] = d[rx][ry][bx][by] + 1;
            q.emplace(nrx, nry, nbx, nby);
        }
        if(found)break;
    }
    cout << ans;

    return 0;
}