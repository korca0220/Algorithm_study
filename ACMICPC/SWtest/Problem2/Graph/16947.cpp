#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int check[3000];
int dist[3000];
vector<int> chain[3000];
int n;
int go(int x, int p){

    if(check[x] == 1)return x;
    check[x] = 1;
    for(int y : chain[x]){
        if(y==p) continue;
        int res = go(y, x);
        if(res == -2) return -2;
        if(res >= 0){
            check[x] = 2;
            if(x == res)return -2;
            else return res;
        }
    }
    return -1;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a>>b;
        a-=1; b-=1;
        chain[a].push_back(b);
        chain[b].push_back(a);
    }
    go(0, -1);
    queue<int> q;
    for(int i=0; i<n; i++){
        if(check[i] == 2){
            q.push(i);
            dist[i] = 0;
        }else dist[i] = -1;
    }

    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int y : chain[x]){
            if(dist[y] == -1){
                q.push(y);
                dist[y] = dist[x] + 1; 
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << dist[i] << " ";
    }

    return 0;
}