#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 100000;
bool check[MAX+1];
int dist[MAX+1];
int N,K;

void bfs(int n){

    queue<int> q;
    check[n] = true;
    dist[n] = 0;
    q.push(n);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now*2 <=MAX && check[now*2] == false){
            check[now*2] = true;
            dist[now*2] = dist[now];
            q.push(now*2);
        }
        if(now-1 >=0 && check[now-1] == false){
            check[now-1] = true;
            dist[now-1] += dist[now] + 1;
            q.push(now-1);
        }
        if(now+1 <=MAX && check[now+1] == false){
            check[now+1] = true;
            dist[now+1] += dist[now] + 1;
            q.push(now+1);
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    bfs(N);
    printf("%d", dist[K]);
    return 0;
}