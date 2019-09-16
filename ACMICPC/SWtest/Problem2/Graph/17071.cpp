#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 500000;
int dist[MAX+1][2];
int n,k;

int bfs(int start, int cat){

    queue<pair<int,int>> q;
    q.emplace(start, 0);
    memset(dist, -1, sizeof(dist));
    dist[start][0] = 0;
    while(!q.empty()){
        int now, t;
        tie(now, t) = q.front();
        q.pop();
        for(int go : {now-1, now+1, now*2}){
            if(0<=go && go<=MAX){
                if(dist[go][1-t] == -1){
                    dist[go][1-t] = dist[now][t] + 1;
                    q.emplace(go, 1-t);
                }
            }
        }
    }
    int ans = -1;
    for(int k=0;; k++){
        cat += k;
        if(cat > MAX) break;
        if(dist[cat][k%2] <= k){
            ans = k;
            break;
        }
    }
    return ans;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cout << bfs(n, k);

    return 0;
}