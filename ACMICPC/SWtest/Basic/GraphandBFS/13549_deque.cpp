#include <iostream>
#include <deque>
using namespace std;

const int MAX = 200000;

int N, K;
bool check[MAX+1];
int dist[MAX+1];

void bfs(int x){

    deque<int> dq;
    dq.push_back(x);
    check[x] = true;
    dist[x] = 0;
    while(!dq.empty()){
        int now = dq.front();
        dq.pop_front();
        if(now-1 >= 0 && check[now-1] == false){
            dq.push_back(now-1);
            check[now-1] = true;
            dist[now-1] += dist[now] +1;
        }
        if(now*2 <= MAX && check[now*2] == false){
            dq.push_front(now*2);
            check[now*2] = true;
            dist[now*2] += dist[now];
        }
        if(now+1 <= MAX && check[now+1] == false){
            dq.push_back(now+1);
            check[now+1] = true;
            dist[now+1] += dist[now] + 1;
        }
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    bfs(N);

    cout << dist[K] <<"\n";

    return 0;
}