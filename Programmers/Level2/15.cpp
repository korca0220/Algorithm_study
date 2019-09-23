#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

struct comp{
    bool operator()(const pair<int,int> p, const pair<int,int> pp){
        if(p.second == pp.second) return p.first > p.second;
        return p.second > pp.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
    for(int i=0; i<jobs.size(); i++)pq.emplace(jobs[i][0], jobs[i][1]);
    
    vector<pair<int,int>> v;
    for(int i=0; i<pq.size(); i++){
        v.emplace_back(pq.top());
        pq.pop();
    }
    
    int time = 0;
    while(!v.empty()){
        for(int i=0; i<v.size(); i++){
            if(v[i].first <= time){
                time += v[i].second;
                answer += time - v[i].first;
                v.erase(v.begin()+i);
                break;
            }
            if(i == v.size() -1)time ++;
        }
    }
    return answer/jobs.size();
}