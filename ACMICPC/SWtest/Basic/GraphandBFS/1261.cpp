#include <iostream>
#include <deque>
#include <utility>
#include <string>
using namespace std;

const int MAX = 200;

bool check[MAX+1][MAX+1];
int dist[MAX+1][MAX+1];
int node[MAX+1][MAX+1];

int N, M;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(){

    deque<pair<int, int>> dq;
    dq.push_front(make_pair(0,0));
    check[0][0] = true;
    dist[0][0] = 0;
    while(!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(node[nx][ny] == 0 && check[nx][ny] == false){
                    dq.push_front(make_pair(nx, ny));
                    check[nx][ny] = true;
                    dist[nx][ny] += dist[x][y];
                }
                if(node[nx][ny] == 1 && check[nx][ny] == false){
                    dq.push_back(make_pair(nx, ny));
                    check[nx][ny] = true;
                    dist[nx][ny] += dist[x][y] + 1;
                }
            }
        }
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<M; j++){
            if(str[j] == '0')node[i][j] = 0;
            else node[i][j] = 1; 
        }
    }

    bfs();
    cout << dist[N-1][M-1] <<"\n";


    return 0;
}