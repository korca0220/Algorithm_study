#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M,V;
bool check[1001];
vector<int> node[1001];

void dfs(int x){
    
    check[x] = true;
    cout << x << " ";
    for(int i=0; i<node[x].size(); i++){
        int y = node[x][i];
        if(check[y] == false) dfs(y);
    }

}

void bfs(int x){
    
    memset(check, false, sizeof(check));
    queue<int> q;
    check[x] = true; q.push(x);
    while(!q.empty()){
        int y = q.front(); q.pop();
        cout << y << " ";
        for(int i=0; i<node[y].size(); i++){
            int z = node[y][i];
            if(check[z] == false){
                check[z] = true; q.push(z);
            }
        }
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    for(int i =0; i<M; i++ ){
        int from, to;
        cin >> from >> to;
        node[from].push_back(to);
        node[to].push_back(from);
    }

    for(int i=1; i<=N; i++){
        sort(node[i].begin(), node[i].end());
    }

    //dfs
    dfs(V);
    cout << "\n";
    //bfs
    bfs(V);

    return 0 ;
}