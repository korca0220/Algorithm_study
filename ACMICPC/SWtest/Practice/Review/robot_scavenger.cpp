#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<vector<int>> bfs(vector<string> &a, int s, int e){

    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int,int>> q;
    q.push(make_pair(s,e));
    dist[s][e] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0>nx || nx>=n || 0>ny || ny>=m) continue;
            if(dist[nx][ny] == -1 && a[nx][ny] != 'x'){
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    return dist;

}

int main(){

    while(true){
        int n,m;
        scanf("%d %d", &m, &n);
        if(n==0 && m==0)break;

        vector<string> in(n);
        for(int i=0; i<n; i++){
            cin >> in[i];
        }

        vector<pair<int, int>> s_point(1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(in[i][j] == 'o'){
                    s_point[0] = make_pair(i,j);
                }else if(in[i][j] == '*'){
                    s_point.push_back(make_pair(i,j));
                }
            }
        }
        
        int len = s_point.size();
        vector<vector<int>> d(len, vector<int>(len));
        bool ok = true;
        for(int i=0; i<len; i++){
            auto dist = bfs(in, s_point[i].first, s_point[i].second);
            for(int j=0; j<len; j++){
                d[i][j] = dist[s_point[j].first][s_point[j].second];
                if(d[i][j] == -1){
                    ok=false;                    
                }
            }
        }

        if(!ok){
            printf("-1\n");
            continue;
        }

        vector<int> permu(len-1);
        for(int i=0; i<len-1; i++){
            permu[i] = i+1;
        }

        int ans = -1;
        do{
            int now = d[0][permu[0]];
            for(int i=0; i<len-2; i++){
                now += d[permu[i]][permu[i+1]];
            }
            if(ans == -1 || ans > now) ans = now;
        }while(next_permutation(permu.begin(), permu.end()));

        printf("%d\n", ans);
    }


    return 0;
}