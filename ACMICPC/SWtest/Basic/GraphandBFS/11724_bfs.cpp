#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
bool check[1000001];
vector<int> node[1000001];
int connect_count = 0;

bool bfs(int x){

    if(check[x]) return false;
    queue<int> q;
    check[x] = true; q.push(x);
    while(!q.empty()){
        int y = q.front(); q.pop();
        for(int i=0; i<node[y].size(); i++){
            int z = node[y][i];
            if(check[z] == false){
                check[z] = true; q.push(z);
            }
        }
    }
    return true;

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i =0; i<M; i++){
        int from, to;
        cin >> from >> to;
        node[from].push_back(to);
        node[to].push_back(from);
    }
    for(int i=1; i<=M; i++)sort(node[i].begin(), node[i].end());

    for(int i=1; i<=N; i++){
        if(bfs(i)) connect_count+=1;
    }
    cout << connect_count;

    return 0;
}