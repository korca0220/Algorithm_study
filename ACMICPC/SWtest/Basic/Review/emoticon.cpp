#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX = 1000;
bool check[MAX+1][MAX+1];
int dist[MAX+1][MAX+1];
int input;

void bfs(){

    queue<pair<int, int>> q;
    check[1][0] = true;
    dist[1][0] = 0;
    q.push(make_pair(1,0));
    while(!q.empty()){
        int cur = q.front().first;
        int clip = q.front().second;
        q.pop();
        if(cur <= MAX && check[cur][cur] == false){
            check[cur][cur] = true;
            dist[cur][cur] += dist[cur][clip] + 1;
            q.push(make_pair(cur, cur));
        }
        if(cur+clip <= MAX && check[cur+clip][clip] == false){
            check[cur+clip][clip] = true;
            dist[cur+clip][clip] += dist[cur][clip] + 1;
            q.push(make_pair(cur+clip, clip));
        }
        if(cur-1 >=0 && check[cur-1][clip] == false){
            check[cur-1][clip] = true;
            dist[cur-1][clip] += dist[cur][clip] + 1;
            q.push(make_pair(cur-1, clip));
        }
    }

}

int main(){
    scanf("%d", &input);

    bfs();
    int min_num = 987654321;
    for(int i=1; i<=input; i++){
        min_num = min(min_num, dist[input][i]);
    }
    printf("%d", min_num);
    return 0;
}