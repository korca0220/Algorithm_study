#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool check[1000001];
vector<int> node[1000001];
int connect_count = 0;

bool dfs(int x){

    if(check[x]) return false;
    check[x] = true;
    for(int i=0; i<node[x].size(); i++){
        int y = node[x][i];
        if (check[y] == false){
            dfs(y);
        }
    }

    return true;

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int from, to;
        cin >> from >> to;
        node[from].push_back(to);
        node[to].push_back(from);
    }
    for(int i=1; i<=M; i++){
        sort(node[i].begin(), node[i].end());
    }

    for(int i =1; i<=N; i++){
        if(dfs(i)) connect_count+=1;
    }
    cout << connect_count;

    return 0;
}