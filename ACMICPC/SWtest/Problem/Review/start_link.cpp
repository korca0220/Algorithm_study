#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000000;
int dist[MAX+1];
int f,s,g,u,d;

void bfs(){

    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : {now+u, now-d}){
            if(next<=f && next>=1){
                if(dist[next] == -1){
                    q.push(next);
                    dist[next] = dist[now] + 1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dist, -1, sizeof(dist));
    cin >> f >> s >> g >> u >> d;

    bfs();
    if(dist[g] != -1)cout << dist[g];
    else cout << "use the stairs";

    return 0;
}