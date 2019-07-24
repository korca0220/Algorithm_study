#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<vector<int>> bfs(int x, int y, vector<string> &a){

    int h = a.size();
    int w = a[0].size();
    vector<vector<int>> dist(h, vector<int>(w, -1));
    deque<pair<int,int>> dq;
    dq.push_front(make_pair(x,y));
    dist[x][y] = 0;
    while(!dq.empty()){
        int qx = dq.front().first;
        int qy = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(0>nx || nx>=h || 0>ny || ny>=w) continue;
            if(dist[nx][ny] != -1) continue;
            if(a[nx][ny] == '*') continue;
            if(a[nx][ny] == '#'){
                dist[nx][ny] = dist[qx][qy] +1;
                dq.push_back(make_pair(nx, ny));
            }
            else{
                dist[nx][ny] = dist[qx][qy];
                dq.push_front(make_pair(nx, ny));
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
        h+=2;
        w+=2;
        for(int i=0; i<w; i++){
            in[0] += ".";
            in[h-1] += ".";
        }

        int x1,x2,y1,y2;
        x1=x2=y1=y2=-1;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(in[i][j] == '$'){
                    if(x1 ==-1){
                        x1 = i;
                        y1 = j;
                    }else{
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        vector<vector<int>> des = bfs(0,0, in);
        vector<vector<int>> s_1 = bfs(x1,y1, in);
        vector<vector<int>> s_2 = bfs(x2,y2, in);

        int ans = -1;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(in[i][j] == '*') continue;
                int cur = (des[i][j] + s_1[i][j] + s_2[i][j]);
                if(in[i][j] == '#')cur -= 2;
                if(ans > cur)ans=cur;
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}