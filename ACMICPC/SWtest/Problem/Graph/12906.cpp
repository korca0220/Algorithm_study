#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    array<string, 3> in;
    for(int i=0; i<3; i++){
        int cnt;
        scanf("%d", &cnt);
        if(cnt > 0){
            cin >> in[i];
        }else in[i] = "";
    }
    int cnt[3] = {0,0,0};
    for(int i=0; i<3; i++){
        for(int j=0; j<in[i].length(); j++){
            cnt[in[i][j] - 'A'] += 1;
        }
    }
    map<array<string,3>, int> dist;
    queue<array<string,3>> q;
    q.push(in);
    dist[in] = 0;
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i==j) continue;
                if(now[i].length() == 0) continue;
                array<string,3> next(now);
                next[j].push_back(next[i].back());
                next[i].pop_back();
                if(dist.count(next) == 0){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }
        }
    }

    array<string, 3> ans;
    for(int i=0; i<3; i++){
        for(int j=0; j<cnt[i]; j++){
            ans[i] += (char)('A'+i);
        }
    }
    printf("%d", dist[ans]);

    return 0;
}