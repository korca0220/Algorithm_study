#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 200000;

int dist[MAX+1];
int from[MAX+1];

void print(int n, int k){

    if(n!=k){
        print(n, from[k]);
    }
    printf("%d ", k);
    return ;
}

void bfs(int n, int k){

    deque<int> dq;
    memset(dist, -1, sizeof(dist));
    dq.push_front(n);
    dist[n] = 0;
    while(!dq.empty()){
        int now = dq.front();
        dq.pop_front();
        if(now*2 <= MAX && dist[now*2] == -1){
            dq.push_front(now*2);
            dist[now*2] = dist[now] + 1;
            from[now*2] = now;
        }
        if(now - 1 >= 0 && dist[now-1] == -1){
            dq.push_back(now-1);
            dist[now-1] = dist[now] + 1;
            from[now-1] = now;
        }
        if(now +1 <= MAX && dist[now+1] == -1){
            dq.push_back(now + 1);
            dist[now+1] = dist[now] + 1;
            from[now+1] = now;
        }
    }

    printf("%d\n", dist[k]);
    print(n, k);

}

int main(){
    int N,K;
    scanf("%d %d", &N, &K);
    bfs(N, K);

    return 0;
}