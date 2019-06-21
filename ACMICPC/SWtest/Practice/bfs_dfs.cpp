#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M,V;
vector<int> num[1001];
bool check[1001];

void dfs(int n){

    check[n] = true;
    printf("%d ", n);
    for(int i=0; i<num[n].size(); i++){
        int y = num[n][i];
        if(check[y] == false) dfs(y);
    }
}

void bfs(int n){

    memset(check, 0, sizeof(check));
    queue<int> q;
    check[n] = true; q.push(n);
    while(!q.empty()){
        int y = q.front(); q.pop();
        printf("%d ", y);
        for(int i=0; i<num[y].size(); i++){
            int z = num[y][i];
            if(check[z] == false){
                check[z]=true; q.push(z);
            }
        }
    }

}

int main(){

    scanf("%d %d %d", &N,&M,&V);
    for(int i=0; i<M; i++){
        int t_one, t_two;
        scanf("%d %d", &t_one, &t_two);
        num[t_one].push_back(t_two);
        num[t_two].push_back(t_one);
    }
    for(int i=1; i<=N; i++){
        sort(num[i].begin(), num[i].end());
    }
    dfs(V);
    printf("\n");
    bfs(V);
    return 0;
}