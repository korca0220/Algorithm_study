#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int N=3;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs(int start){

    map<int,int>dist;
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int now_num = q.front();
        string now = to_string(now_num);
        q.pop();
        int z = now.find('9'); // position of zero(0)
        int x = z/3;
        int y = z%3;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx< N && ny>=0 && ny<N){
                string next = now;
                swap(next[x*3+y], next[nx*3+ny]);
                int num = stoi(next);
                if(dist.count(num) == 0){
                    dist[num] = dist[now_num] + 1;
                    q.push(num);
                }
            }
        }
    }
    if(dist.count(123456789) == 0)printf("-1");
    else printf("%d", dist[123456789]);
}

int main(){


    string str;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            scanf(" %d", &temp);
            if(temp == 0)temp = 9;
            str += to_string(temp);
        }
    }
    bfs(stoi(str));



    return 0;
}