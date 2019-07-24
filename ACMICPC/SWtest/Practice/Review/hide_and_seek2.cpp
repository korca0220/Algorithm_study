#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 200000;
int dist[MAX+1];
int cnt[MAX+1];

void bfs(int n, int k){

    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    cnt[n] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : {now*2, now-1, now+1}){
            if(0<=next && next<=MAX){
                if(dist[next] == -1){
                    dist[next] = dist[now] + 1;
                    cnt[next] = cnt[now];
                    q.push(next);
                }else if(dist[next] == dist[now]+1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    printf("%d\n%d", dist[k], cnt[k]);
}

int main(){

    int N,K;
    scanf("%d %d", &N, &K);
    bfs(N, K);

    return 0;
}