#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200000;

int N, K;
bool check[MAX+1];
int dist[MAX+1];

void bfs(int x){

    queue<int> front_q;
    queue<int> next_q;
    front_q.push(x);
    check[x] = true;
    dist[x] = 0;
    while(!front_q.empty()){
        int now = front_q.front();
        front_q.pop();
        if(now-1 >= 0 && check[now-1] == false){
            check[now-1] = true;
            dist[now-1] += dist[now] + 1;
            next_q.push(now-1);
        }
        if(now*2 <= MAX && check[now*2] == false){
            check[now*2] = true;
            dist[now*2] += dist[now];
            front_q.push(now*2); 
        }
        if(now+1 <= MAX && check[now+1] == false){
            check[now+1] = true;
            dist[now+1] += dist[now] + 1;
            next_q.push(now+1);
        }
        if(front_q.empty()){
            front_q = next_q;
            next_q = queue<int>();
        }
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K ;
    bfs(N);

    cout << dist[K] << "\n";

    return 0;
}