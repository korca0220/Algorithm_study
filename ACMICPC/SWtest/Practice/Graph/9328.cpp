#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool check[111][111];
bool key[26];

void bfs(vector<string> &a, bool key[], int s, int e){

    int n = a.size();
    int m = a[0].size();
    memset(check, false, sizeof(check));
    int cnt = 0;
    
    queue<pair<int,int>> q;
    queue<pair<int,int>> door[26];
    q.push(make_pair(s,e));
    check[s][e] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if(check[nx][ny]) continue;
            if(a[nx][ny] == '*') continue;

            check[nx][ny] = true;
            if(a[nx][ny] == '.'){
                q.push(make_pair(nx,ny));
            }else if(a[nx][ny] == '$'){
                q.push(make_pair(nx,ny));
                cnt += 1;
            // door
            }else if('A' <= a[nx][ny] && a[nx][ny] <='Z'){
                if(key[a[nx][ny] - 'A']){
                    q.push(make_pair(nx, ny));
                }else{
                    door[a[nx][ny]-'A'].push(make_pair(nx, ny));
                }
            // key
            }else if('a' <= a[nx][ny] && a[nx][ny] <= 'z'){
                q.push(make_pair(nx,ny));
                if(!key[a[nx][ny] - 'a']){
                    key[a[nx][ny] - 'a'] = true;
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
        int h,w;
        scanf("%d %d", &h, &w);
        vector<string> in(h+2);
        for(int i=1; i<=h; i++){
            cin >> in[i];
            in[i] = "." + in[i] + ".";
        }
        for(int i=0; i<w+2; i++){
            in[0] += ".";
            in[h+1] += ".";
        }
        memset(key, false, sizeof(key));
        string temp;
        cin >> temp;
        if(temp[0] != 0){
            for(int i=0; i<temp.size(); i++){
                key[temp[i]-'a'] = true;
            }
        }
        bfs(in, key, 0, 0);
    }

    return 0;
}