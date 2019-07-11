#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

void bfs(vector<int> &dist, vector<int> &from, vector<int> &how, int n){

    queue<int> q;
    q.push(1%n);
    dist[1%n] = 0;
    how[1%n] = 1;
    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int i=0; i<=1; i++){
            int next = (now*10+i)%n;
            if(dist[next] == -1){
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = i;
                q.push(next);
            }
        }
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        vector<int> dist(N,-1);
        vector<int> from(N,-1);
        vector<int> how(N, -1);
        bfs(dist, from, how, N);

        if(dist[0] == -1){
            printf("BRAK\n");
        }else{
            string str;
            for(int i=0; i!=-1; i=from[i]){
                str += to_string(how[i]);
            }
            reverse(str.begin(), str.end());
            cout << str << "\n";
        }
    }
    return 0;

}