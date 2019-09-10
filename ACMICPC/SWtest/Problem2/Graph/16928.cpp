#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    int move[101];

    for(int i=1; i<=100; i++){
        move[i] = i;
    }
    for(int i=0; i<n+m; i++){
        int start, end;
        cin >> start >> end;
        move[start] = end;
    }

    int dist[101];
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=1; i<=6; i++){
            int next = move[now+i];
            if(next <= 100 && dist[next] == -1){
                q.push(next);
                dist[next] = dist[now] + 1;
            }
        }
    }
    cout << dist[100];

    return 0;
}