#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<string> in(n);
    int start, end;
    start=end=-1;
    vector<pair<int,int>> v;
    vector<vector<int>> b(n, vector<int>(n));
    for(int i=0; i<n; i++){
        cin >> in[i];
        for(int j=0; j<n; j++){
            if(in[i][j] == '#'){
                if(start == -1){
                    start = v.size();
                }else{
                    end = v.size();
                }
                v.emplace_back(i,j);
                b[i][j] = v.size()-1;
            }else if(in[i][j] == '!'){
                v.emplace_back(i,j);
                b[i][j] = v.size()-1;
            }
        }
    }
    int len = v.size();
    vector<vector<bool>> check(len, vector<bool>(len));
    for(int i=0; i<len; i++){
        for(int k=0; k<4; k++){
            int nx = v[i].first + dx[k];
            int ny = v[i].second + dy[k];
            while(nx>=0 && nx<n && ny>=0 && ny<n){
                if(in[nx][ny] == '*')break;
                if(in[nx][ny] == '!' || in[nx][ny] == '#'){
                    check[i][b[nx][ny]] = true;
                }
                nx += dx[k];
                ny += dy[k];
            }
        }
    }
    queue<int> q;
    vector<int> dist(len, -1);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<len; i++){
            if(check[now][i] && dist[i] == -1){
                dist[i] = dist[now] + 1;
                q.push(i);
            }
        }
    }
    cout << dist[end]-1;

    return 0;
}
