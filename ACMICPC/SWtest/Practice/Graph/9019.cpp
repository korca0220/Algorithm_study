#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 10000;
bool check[MAX+1];
int dist[MAX+1];
int from[MAX+1];
char how[MAX+1];

void print(int a, int b){

    if(a ==b) return ;
    print(a, from[b]);
    printf("%c", how[b]);

}

void bfs(int a, int b){

    memset(check,false,sizeof(check));
    memset(dist,0,sizeof(dist));
    memset(how,0,sizeof(how));
    memset(from,0,sizeof(from));
    check[a] = true;
    dist[a] = 0;
    from[a] = -1;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int next = (now*2)%10000;
        if(check[next] == false){
            q.push(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'D';
        }
        next = now-1;
        if(next == -1) next = 9999;
        if(check[next] == false){
            q.push(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'S';
        }
        next = (now%1000)*10 + now/1000 ;
        if(check[next] == false){
            q.push(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'L';
        }
        next = (now/10)+ (now%10)*1000;
        if(check[next] == false){
            q.push(next);
            check[next] = true;
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'R';
        }
    }
    print(a,b);
}

int main(){

    int T;
    scanf("%d", &T);
    int a,b;
    while(T--){
        scanf("%d %d", &a, &b);
        bfs(a, b);
        printf("\n");
    }


    return 0;
}