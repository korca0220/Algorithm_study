#include <queue>
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;


int from[] = {0,0,1,1,2,2};
int to[] ={1,2,0,2,0,1}; 

int ans[201];
bool check[201][201];
int cap[3];

void bfs(int cap[]){

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    check[0][0] = true;
    ans[cap[2]] = true;
    int sum = cap[2];
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int z = sum-x-y;
        q.pop();
        for(int i=0; i<6; i++){
            int next[] = {x,y,z};
            next[to[i]] += next[from[i]];
            next[from[i]] = 0;
            if(next[to[i]] >= cap[to[i]]){
                next[from[i]] = next[to[i]] - cap[to[i]];
                next[to[i]] = cap[to[i]];
            }
            if(!check[next[0]][next[1]]){
                check[next[0]][next[1]] = true;
                q.push(make_pair(next[0], next[1]));
                if(next[0] == 0){
                    ans[next[2]] = true;
                }
            }
        }
    }
    for(int i=0; i<=cap[2]; i++){
        if(ans[i])printf("%d ", i);
    }
}

int main(){
    scanf("%d %d %d", &cap[0], &cap[1], &cap[2]);
    bfs(cap);

    return 0;
}