#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 200000;
int N, K;
int dist[MAX+1];
bool check[MAX+1];
int cnt[MAX+1];

void bfs(int n){

    queue<int> q;
    q.push(n);
    check[n] = true;
    dist[n] = 0;
    cnt[n] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : {now*2, now-1, now+1}){
            if(0<= next && next <= MAX){
                if(check[next]==false){
                    q.push(next);
                    check[next] = true;
                    dist[next] = dist[now] + 1;
                    cnt[next] = cnt[now];
                }else if(dist[next] == dist[now] + 1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }

}

int main(){

    scanf("%d %d", &N, &K);
    bfs(N);
    printf("%d\n", dist[K]);
    printf("%d", cnt[K]);
    return 0;
}