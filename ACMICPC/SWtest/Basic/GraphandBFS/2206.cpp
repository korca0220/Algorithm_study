#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int node[MAX+1][MAX+1];
int dist[MAX+1][MAX+1][2];

int N,M;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(){

    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    dist[0][0][0] = 1;
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(node[nx][ny] == 0 && dist[nx][ny][z] == 0){
                    q.push(make_tuple(nx, ny, z));
                    dist[nx][ny][z] = dist[x][y][z] + 1;
                }
                if(node[nx][ny] == 1 && dist[nx][ny][z+1] == 0 && z == 0){
                    q.push(make_tuple(nx, ny, z+1));
                    dist[nx][ny][z+1] = dist[x][y][z] + 1;
                }

            }
        }
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<M; j++){
            if(str[j] == '0') node[i][j] = 0;
            else node[i][j] = 1;
        }
    }
    bfs();

    
    if(dist[N-1][M-1][0] != 0 && dist[N-1][M-1][1] != 0){
        cout << min(dist[N-1][M-1][0], dist[N-1][M-1][1])<< "\n";
    }
    else if(dist[N-1][M-1][0] != 0){
        cout << dist[N-1][M-1][0] << "\n";
    } 
    else if(dist[N-1][M-1][1] != 0){
        cout << dist[N-1][M-1][1] << "\n";
    }
    else cout << "-1\n";
    return 0;
}