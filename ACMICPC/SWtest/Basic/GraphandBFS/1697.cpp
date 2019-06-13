#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 200000;
int N, K;

bool check[MAX+1];
int dist[MAX+1];

void bfs(int x){

    queue<int> q;
    q.push(x);
    check[x] = true;
    dist[x] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now -1 >= 0){
            if(check[now-1]==false){
                q.push(now-1);
                dist[now-1] += dist[now] + 1;
                check[now-1] = true;
            }
        }
        if(now+1 < MAX){
            if(check[now+1] == false){
                q.push(now+1);
                dist[now+1] += dist[now] + 1;
                check[now+1] = true;
            }
        }
        if(now*2 < MAX){
            if(check[now*2] == false){
                q.push(now*2);
                dist[now*2] += dist[now] + 1;
                check[now*2] = true;
            }
        }
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    bfs(N);
    cout << dist[K];

    return 0;
}