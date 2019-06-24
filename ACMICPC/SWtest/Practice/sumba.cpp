#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 200000;
bool check[MAX+1];
int dist[MAX+1];
int n,k;

void bfs(int n, int k){
    queue<int> q;
    q.push(n);
    check[n] = true;
    dist[n] = 0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x*2<MAX && check[x*2] == false){
            check[x*2] = true;
            dist[x*2] += dist[x] +1;
            q.push(x*2);
        }
        if(x+1<MAX && check[x+1] == false){
            check[x+1] = true;
            dist[x+1] += dist[x] + 1;
            q.push(x+1);
        }
        if(x-1>=0 && check[x-1] == false){
            check[x-1] = true;
            dist[x-1] += dist[x] + 1;
            q.push(x-1);
        }
    }
    

}

int main(){
    scanf("%d %d", &n, &k);
    bfs(n, k);
    printf("%d", dist[k]);
    return 0;
}