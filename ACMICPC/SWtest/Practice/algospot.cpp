#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;

int node[201][201];
bool check[201][201];
int dist[201][201];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N,K;

void bfs(){

    check[0][0] = true;
    dist[0][0] = 0;
    deque<pair<int, int>> front_q;
    front_q.push_front(make_pair(0, 0));
    while(!front_q.empty()){
        int x = front_q.front().first;
        int y = front_q.front().second;
        front_q.pop_front();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<K){
                if(check[nx][ny] == false && node[nx][ny] == 0){
                    check[nx][ny] = true;
                    dist[nx][ny] = dist[x][y];
                    front_q.push_front(make_pair(nx, ny));
                }
                if(check[nx][ny] == false && node[nx][ny] == 1){
                    check[nx][ny] = true;
                    dist[nx][ny] += dist[x][y] + 1;
                    front_q.push_back(make_pair(nx, ny));
                }
            }
        }
    }

}
int main(){
    scanf("%d %d", &K, &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            scanf("%1d", &node[i][j]);
        }
    }
    bfs();
    printf("%d", dist[N-1][K-1]);

    return 0;
}