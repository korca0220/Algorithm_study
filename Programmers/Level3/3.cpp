#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <iostream>
using namespace std;

bool check[201];
void bfs(int s, vector<vector<int>> &computers){

    queue<int> q;
    q.push(s);
    check[s] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<computers[now].size(); i++){
            if(check[i] == false && computers[now][i] == 1){
                q.push(i);
                check[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    memset(check, false, sizeof(check));

    for(int i=0; i<n; i++){
        if(check[i] == false){
            bfs(i, computers);
            answer+=1;
        }
    }

    return answer;
}