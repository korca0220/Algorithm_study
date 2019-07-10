#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;


int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};


vector<vector<int>> bfs(vector<string> &a, int x, int y){

    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> dist(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dist[i][j] = -1;
        }
    }
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(x,y));
    dist[x][y] = 0;
    while(!dq.empty()){
        tie(x,y) = dq.front();
        dq.pop_front();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m)continue;
            if(a[nx][ny] == '*')continue;
            if(dist[nx][ny] != -1)continue;
            if(a[nx][ny] == '#'){
                dist[nx][ny] = dist[x][y] +1;
                dq.push_back(make_pair(nx, ny));
            }else{
                dist[nx][ny] = dist[x][y];
                dq.push_front(make_pair(nx,ny));
            }
        }

    }
    return dist;
}

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int h,w;
        scanf("%d %d", &h, &w);
        vector<string> in(h+2);
        for(int i=1; i<=h; i++){
            cin >> in[i];
            in[i] = "." + in[i] + ".";
        }
        // map expand
        h += 2;
        w += 2;
        for(int i=0; i<w; i++){
            in[0] += ".";
            in[h-1] += "."; 
        }
        int x1,x2,y1,y2;
        x1=x2=y1=y2=-1;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(in[i][j] == '$'){
                    if(x1 == -1){
                        x1 = i;
                        y1 = j;
                    }else{
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        vector<vector<int>> d0 = bfs(in, 0, 0);
        vector<vector<int>> d1 = bfs(in, x1, y1);
        vector<vector<int>> d2 = bfs(in, x2, y2);

        int ans = h*w;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(in[i][j] == '*')continue;
                int cur = (d0[i][j] + d1[i][j] + d2[i][j]);
                if(in[i][j] == '#') cur -=2;
                if(ans > cur) ans = cur;
            }
        }
        printf("%d\n", ans);
    }
    

    return 0;
}