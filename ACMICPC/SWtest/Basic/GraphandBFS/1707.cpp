#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int t_input, N, M;
int check[20001];
vector<int> node[20001];

void dfs(int x, int color){

    check[x] = color;
    for(int i=0; i<node[x].size(); i++){
        int y = node[x][i];
        if(check[y] == 0){
            dfs(y, 3-color);
        }
    }

}
int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t_input;

    while(t_input--){

        cin >> N >> M;
        for(int i=1; i<=N; i++){
            node[i].clear();
            check[i] = 0;
        }
        for(int i=0; i<M; i++){
            int from, to;
            cin >> from >> to;
            node[from].push_back(to);
            node[to].push_back(from);
        }
        for(int i=1; i<=N; i++){
            sort(node[i].begin(), node[i].end());
        }
        for(int i=1; i<=N; i++){
            if(check[i] == 0)dfs(i, 1);
        }
        
        bool ok = true;
        for(int i=1; i<=N; i++){
            for(int j=0; j<node[i].size(); j++){
                int k = node[i][j];
                if(check[i] == check[k]) ok = false;
            }
        }
        if(ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}