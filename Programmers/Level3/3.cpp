#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

bool check[201][201];
void bfs(int s, int e, vector<vector<int>> &line){

    queue<pair<int,int>> q;
    check[s][e] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<line[i].size

    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int len = computers.size();
    
    memset(check, false, sizeof(check));
    vector<vector<int>> line(len, vector<int>(len));
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(i==j)continue;
            if(computers[i][j] == 1){
                line[i].push_back(j);
                line[j].push_back(i);
            }
        }
    }

    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(check[i][j] == false){
                bfs(i,j);
                answer+=1;
            }
        }
    }

    return answer;
}