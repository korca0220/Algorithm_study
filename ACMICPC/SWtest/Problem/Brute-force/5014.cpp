#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000000;
int dist[MAX+1];

int F,S,G,U,D;

void bfs(int start){

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : {now+U,now-D}){
            if(1<= next && next <=F){
                if(dist[next] == -1){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }
        }
    }

}

int main(){
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

    memset(dist, -1 ,sizeof(dist));
    bfs(S);
    printf(dist[G] == -1 ? "use the stairs" : "%d", dist[G]);

    return 0;
}