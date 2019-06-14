#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int MAX = 1000;

int input;
int dist[2002][2002];
bool check[2002][2002];


void bfs(int x){

    queue<pair<int,int>> q;
    q.push(make_pair(x, 0));
    check[x][0] = true;
    dist[x][0] = 0;
    while(!q.empty()){
        int now = q.front().first;
        int copy = q.front().second;
        q.pop();
        if(now-1 >= 0){
            if(check[now-1][copy] == false){
                q.push(make_pair(now-1, copy));
                check[now-1][copy] = true;
                dist[now-1][copy] += dist[now][copy] + 1;
            }
        }
        if(check[now][now] == false){
            q.push(make_pair(now, now));
            check[now][now] = true;
            dist[now][now] += dist[now][copy] + 1;
        }
        if(now+copy <= MAX){
            if(check[now+copy][copy] == false){
                q.push(make_pair(now+copy, copy));
                check[now+copy][copy] = true;
                dist[now+copy][copy] += dist[now][copy] + 1;
            }
        }
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    bfs(1);

    int cnt = 987654321;
    for(int i =1; i<=input; i++){
        if(cnt > dist[input][i]){
            cnt = dist[input][i];
        }
    }
    cout << cnt << "\n";


    return 0;
}