#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
char in[101][101];
bool check[101][101];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool blindCheak(bool blind, char from, char to){

    if(from == to) return true;
    if(blind){
        if(from == 'R' && to == 'G') return true;
        else if(from == 'G' && to == 'R') return true;
    }
    return false;
}

void bfs(int x, int y, bool blind){

    queue<pair<int,int>> q;
    q.emplace(x,y);
    check[x][y] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(check[nx][ny]) continue;
            if(blindCheak(blind, in[x][y], in[nx][ny])==false) continue;
            q.emplace(nx,ny);
            check[nx][ny] = true;
        }
    }
}

int go(bool blind=false){

    memset(check, false, sizeof(check));
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == false){
                bfs(i,j, blind);
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)cin >> in[i];

    cout << go() << " "<< go(true);

    return 0;
}