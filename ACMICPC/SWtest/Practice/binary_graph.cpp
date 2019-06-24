#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t_input, N, M;
int check[20001];
vector<int> node[20001];

void dfs(int n, int color){

    check[n] = color;
    for(int i =0; i<node[n].size(); i++){
        int y = node[n][i];
        if(check[y] == 0){
            dfs(y, 3-color);
        }
    }
}


int main(){

    scanf("%d\n", &t_input);
    while(t_input--){
        scanf("%d %d", &N,&M);
        for(int i=1; i<=N; i++){
            node[i].clear();
            check[i]=0;
        }
        for(int i=0; i<M; i++){
            int to, from;
            scanf("%d %d", &to, &from);
            node[to].push_back(from);
            node[from].push_back(to);
        }
        for(int i=1; i<=N; i++){
            sort(node[i].begin(), node[i].end());
        }
        for(int i=1; i<=N; i++){
            if(check[i]==0){
                dfs(i, 1);
            }
        }
        bool ok = true;
        for(int i=1; i<=N; i++){
            for(int j=0; j<node[i].size(); j++){
                int k = node[i][j];
                if(check[i] == check[k]){
                    ok = false;
                }
            }
        }
        if(ok==true)printf("YES\n");
        else printf("NO\n");
        // printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}