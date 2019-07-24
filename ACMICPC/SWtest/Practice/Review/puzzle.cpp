#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(string str){

    queue<string> q;
    map<string, int> d;
    q.push(str);
    d[str] = 0;
    while(!q.empty()){
        string now = q.front();
        q.pop();
        int z = now.find('9');
        int x = z/3;
        int y = z%3;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=nx && nx<3 && 0<=ny && ny<3){
                string next = now;
                swap(next[x*3+y], next[nx*3+ny]);
                if(d.count(next) == 0){
                    q.push(next);
                    d[next] = d[now] + 1;
                }
            }
        }
    }
    if(d.count("123456789") == 0)printf("-1");
    else printf("%d", d["123456789"]);

}

int main(){
    string str;
    for(int i=0; i<9; i++){
        string temp;
        cin >> temp;
        if(temp == "0")temp = "9";
        str += temp;
    }
    bfs(str);
    return 0;
}