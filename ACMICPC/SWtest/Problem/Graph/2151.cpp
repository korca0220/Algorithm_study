#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

char in[51][51];
int N;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main(){
    scanf("%d", &N);
    
    int start, end;
    start=end=-1;
    vector<pair<int,int>> v;
    vector<vector<int>> b(N, vector<int>(N));
    for(int i=0; i<N; i++){
        cin >>in[i];
        for(int j=0; j<N; j++){
            if(in[i][j] == '#'){
                if(start == -1){
                    start = v.size();
                }else{ // end
                    end = v.size();
                }
                v.emplace_back(i,j);
                b[i][j] = v.size() - 1;
            }else if(in[i][j] == '!'){
                v.emplace_back(i,j);
                b[i][j] = v.size() - 1;
            }
        }
    }
    int m = v.size();
    vector<vector<bool>> check(m, vector<bool>(m));
    for(int i=0; i<m; i++){
        for(int k=0; k<4; k++){
            int nx = v[i].first + dx[k];
            int ny = v[i].second + dy[k];
            while(nx >= 0 && nx < N && ny >= 0 && ny < N){
                if(in[nx][ny] == '*') break;
                if(in[nx][ny] == '!' || in[nx][ny] == '#'){
                    check[i][b[nx][ny]] = true;
                }
                nx += dx[k];
                ny += dy[k];
            }
        }
    }

    //bfs
    vector<int> dist(m, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<m; i++){
            if(check[now][i] && dist[i] == -1){
                dist[i] = dist[now] + 1;
                q.push(i);
            }
        }
    }

    printf("%d", dist[end]-1);
    return 0;
}
