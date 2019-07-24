#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool key[26];
bool check[201][201];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(vector<string> &a, int xx, int yy){

    int n = a.size();
    int m = a[0].size();
    queue<pair<int,int>> q;
    queue<pair<int,int>> door[26];

    memset(check, false, sizeof(check));
    q.push(make_pair(xx, yy));
    check[xx][yy] = true;
    int cnt = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x +dx[i];
            int ny = y +dy[i];
            if(0>nx || nx >= n || 0>ny || ny >= m)continue;
            if(a[nx][ny] == '*') continue;
            if(check[nx][ny]) continue;

            check[nx][ny] = true;
            if(a[nx][ny] == '.'){
                q.push(make_pair(nx,ny));
            }else if(a[nx][ny] == '$'){
                q.push(make_pair(nx,ny));
                cnt +=1;
            }else if( 'A' <= a[nx][ny] && a[nx][ny] <='Z'){
                if(key[a[nx][ny] - 'A']){
                    q.push(make_pair(nx, ny));
                }else{
                    door[a[nx][ny]-'A'].push(make_pair(nx,ny));
                }
            }else if('a' <= a[nx][ny] && a[nx][ny] <= 'z'){
                q.push(make_pair(nx,ny));
                if(!key[a[nx][ny]-'a']){
                    key[a[nx][ny]-'a'] = true;
                    while(!door[a[nx][ny]-'a'].empty()){
                        q.push(door[a[nx][ny]-'a'].front());
                        door[a[nx][ny]-'a'].pop();
                    }                    
                }
            }
        }
    }
    printf("%d\n", cnt);
}

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int n,m;
        scanf("%d %d", &n, &m);
        vector<string> in(n+2);
        for(int i=1; i<=n; i++){
            cin >> in[i];
            in[i] = "." + in[i] + ".";
        }
        for(int i=0; i<m+2; i++){
            in[0] += ".";
            in[n+1] += ".";
        }
        memset(key, false, sizeof(key));
        string temp;
        cin >> temp;

        if(temp != "0"){
            for(int i=0; i<temp.size(); i++){
                key[temp[i]-'a'] = true;
            }
        }
        bfs(in, 0, 0);
    }


    return 0;
}