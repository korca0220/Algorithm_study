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
    int start = 0;
    int point = 0;
    
    while(true){
        for(; point<jobs.size(); point++){
            if(jobs[point][0] <=point){
                pq.emplace(jobs[point][0], jobs[point][1]);
            }
            if(point == jobs.size()) break;
            if(pq.empty()){
                start+=1;
                continue;
            }
            auto temp = pq.top(); pq.pop();
            answer += start - temp.first + temp.second;
            start += temp.second;
        }

    }
    return answer/jobs.size();
}