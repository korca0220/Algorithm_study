#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
//시작점(s,e)에서 각 부분의 거리가 담긴 벡터를 리턴하는 bfs(normally)
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
            if(nx >=0 && nx < n && ny >=0 && ny< m){
                if(dist[nx][ny] == -1 && a[nx][ny] != 'x'){
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
    return dist;
}

int main(){

    while(true){
        int h,w;
        scanf("%d %d", &w, &h);
        if(h==0 && w==0)break;

        vector<string> in(h);
        for(int i=0; i<h; i++){
            cin >> in[i];
        }

        vector<pair<int,int>> s_point(1);
        // 로봇의 위치를 s_point(스타트 포인트)벡터에 푸쉬
        // 후에 각 청소 위치를 푸쉬
        // TSP 문제와 흡사
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
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
        // 각 위치에서 다른 위치로 갈 경우의 거리를 갖고있는 벡터를 만듦
        // 자기 자신에서 자기 자신은 0 
        for(int i=0; i<len; i++){
            auto dist = bfs(in, s_point[i].first, s_point[i].second); // 기억해야 될 skill
            for(int j=0; j<len; j++){
                d[i][j] = dist[s_point[j].first][s_point[j].second];
                if(d[i][j] == -1){
                    ok = false;
                }
            }
        }
        if(ok==false){
            printf("-1\n");
            continue;
        }

        // 순회를 하기위한 순열 벡터 
        // 1,2,3
        vector<int> permu(len-1);
        for(int i=0; i<len-1; i++){
            permu[i] = i+1;
        }

        int ans = -1;
        // 순열을 진행하면서 각 모든 순서를 탐색
        // 1,2,3 -> 1,3,2 -> 2,1,3 -> 2,3,1 .....
        do{
            int now = d[0][permu[0]];
            for(int i=0; i<len-2; i++){
                now += d[permu[i]][permu[i+1]];
            }
            if(ans > now || ans == -1) ans = now;
        }while(next_permutation(permu.begin(), permu.end()));

        printf("%d\n", ans);
    }
    return 0;
}