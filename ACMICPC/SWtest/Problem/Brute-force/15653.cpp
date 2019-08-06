#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int d[10][10][10][10];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

pair<bool,bool> simulate(vector<string> &in, int &x, int &y, int dir){
    if(in[x][y] == '.') return make_pair(false, false);
    int n = in.size();
    int m = in[0].size();
    bool moved = false;
    while(true){
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(0>nx || nx>=n || 0>ny || ny>=m) return make_pair(moved, false);

        if(in[nx][ny] == '#') return make_pair(moved, false);
        else if(in[nx][ny] == 'R' || in[nx][ny] == 'B') return make_pair(moved, false);
        else if(in[nx][ny] == '.'){
            swap(in[nx][ny], in[x][y]);
            x = nx;
            y = ny;
            moved = true;
        }else if(in[nx][ny] == 'O'){            
            moved = true;
            in[x][y] = '.';
            return make_pair(moved, true);
        }
    }
    return make_pair(false, false);

}

pair<bool,bool> next(vector<string> in, int &rx, int &ry, int &bx, int &by, int dir){

    in[rx][ry] = 'R';
    in[bx][by] = 'B';
    bool hole1=false, hole2=false;
    while(true){
        auto p1 = simulate(in, rx, ry, dir);
        auto p2 = simulate(in, bx, by, dir);

        if(p1.first == false && p2.first == false) break;

        if(p1.second) hole1 = true;
        if(p2.second) hole2 = true;
    }
    return make_pair(hole1, hole2);

}

int main(){

    int n,m;
    scanf("%d %d", &n, &m);
    vector<string> in(n);
    for(int i=0; i<n; i++){
        cin >> in[i];
    }

    int rx,ry,bx,by;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(in[i][j] == 'R'){
                rx = i, ry = j;
                in[i][j] = '.';
            }else if(in[i][j] == 'B'){
                bx = i, by = j;
                in[i][j] = '.';
            }
        }
    }

    queue<tuple<int,int,int,int>> q;
    memset(d, -1, sizeof(d));
    d[rx][ry][bx][by] = 0;
    q.emplace(rx,ry,bx,by);
    bool found = false;
    int ans = -1;
    while(!q.empty()){
        tie(rx,ry,bx,by) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int rnx = rx, rny = ry, bnx = bx, bny = by;
            bool hole1, hole2;
            tie(hole1, hole2) = next(in, rnx,rny,bnx,bny, i);
            if(hole2) continue;
            if(hole1){
                found = true;
                ans = d[rx][ry][bx][by] + 1;
                break;
            }
            if(d[rnx][rny][bnx][bny] != -1) continue;
            q.emplace(rnx,rny,bnx,bny);
            d[rnx][rny][bnx][bny] = d[rx][ry][bx][by] + 1;
        }
        if(found) break;
    }
    printf("%d", ans);

    return 0;
}