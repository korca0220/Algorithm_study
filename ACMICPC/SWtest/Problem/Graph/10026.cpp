#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool c[101][101];
char in[101][101];

bool checker(bool blind, char from, char to){

    if(from == to) return true;
    if(blind){
        if(from=='R' && to=='G') return true;
        if(from=='G' && to=='R') return true;
    }
    return false;

}
void bfs(bool blind, int s, int e){

    queue<pair<int,int>> q;
    q.emplace(s,e);
    c[s][e] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0> nx || nx >= N || 0>ny || ny>=N) continue;
            if(checker(blind, in[x][y], in[nx][ny]) && c[nx][ny] == false){
                q.emplace(nx,ny);
                c[nx][ny] = true;
            }
        }
    }
}

int letgo(bool blind=false){

    int ans = 0;
    memset(c, false, sizeof(c));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(c[i][j] == false){
                ans +=1;
                bfs(blind, i,j);
            }
        }
    }
    return ans; 
}



int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        cin >> in[i];
    }
    printf("%d %d", letgo(), letgo(true));

    return 0;
}