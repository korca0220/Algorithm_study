#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 10000;
const int MAX = 10000;

int dist[MAX+1];
int from[MAX+1];
char how[MAX+1];

void print(int A, int B){

    if(A==B) return;
    print(A, from[B]);
    printf("%c", how[B]);

}


void bfs(int A, int B){

    memset(dist, -1, sizeof(dist));
    memset(from, 0, sizeof(from));
    memset(how, 0, sizeof(how));
    queue<int> q;
    q.push(A);
    dist[A] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int next = ((now*2)%MOD);
        if(dist[next] == -1){
            q.push(next);
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'D';
        }
        next = now - 1;
        if(next== -1) next = 9999;
        if(dist[next] == -1){
            q.push(next);
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'S';
        }
        next = ((now%1000)*10) + (now/1000);
        if(dist[next] == -1){
            q.push(next);
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'L';
        }
        next = ((now%10)*1000) + (now/10);
        if(dist[next] == -1){
            q.push(next);
            dist[next] = dist[now] + 1;
            from[next] = now;
            how[next] = 'R';
        }
    }
    print(A,B);
}

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int A,B;
        scanf("%d %d", &A, &B);
        bfs(A,B);
        printf("\n");
    }


    return 0;
}