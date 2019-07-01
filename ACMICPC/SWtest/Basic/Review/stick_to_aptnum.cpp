#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int input;
int check[26][26];
int node[26][26];
int global_count = 0;
int total_count[25*25];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(int n, int m, int cnt){

    check[n][m] = cnt;
    queue<pair<int, int>> q;
    q.push(make_pair(n,m));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<= nx && nx<input && 0<=ny && ny<input){
                if(node[nx][ny] == 1 && check[nx][ny] == 0){
                    check[nx][ny] = cnt;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

}
int main(){

    scanf("%d", &input);
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            scanf("%1d", &node[i][j]);
        }
    }
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            if(node[i][j] ==1 && check[i][j] == 0){
                bfs(i, j, ++global_count);
            }
        }
    }
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            total_count[check[i][j]]+=1;
        }
    }
    printf("%d\n", global_count);
    sort(total_count+1, total_count+global_count+1);
    for(int i=1; i<=global_count; i++){
        printf("%d\n", total_count[i]);
    }

    return 0;
}