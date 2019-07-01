#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
vector<int> num[1000001];
bool check[1000001];
int global_count=0;

bool bfs(int n){

    if(check[n]==true)return false;
    queue<int> q;
    check[n] = true;
    q.push(n); 
    while(!q.empty()){
        int y = q.front(); q.pop();
        for(int i=0; i<num[y].size(); i++){
            int z = num[y][i];
            if(check[z] == false){
                q.push(z); check[z] = true;
            }
        }
    }
    return true;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++){
        int to, from;
        scanf("%d %d", &to, &from);
        num[to].push_back(from);
        num[from].push_back(to);
    }
    for(int i=1; i<=N; i++){
        sort(num[i].begin(), num[i].end());
    }
    for(int i=1; i<=N; i++){
        if(bfs(i))global_count++;
    }
    printf("%d", global_count);

    return 0;
}