#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <map>
#include <tuple>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int main(){

    array<string, 3> in;
    for(int i=0; i<3; i++){
        int cnt;
        cin >> cnt;
        if(cnt > 0){
            cin >> in[i];
        }else in[i] = "";
    }

    int cnt[] = {0,0,0};
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
                    q.push(next);
                    dist[next] = dist[now]+1;
                }
            }
        }
    }
    array<string,3> ans; // correct
    for(int i=0; i<3; i++){
        for(int j=0; j<cnt[i]; j++){
            ans[i] += (char)('A'+i);
        }
    }
    cout << dist[ans];

    return 0;
}