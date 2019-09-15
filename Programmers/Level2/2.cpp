#include <string>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    deque<pair<int,int>> q;
    vector<int> answer;
    for(int i=0; i<progresses.size(); i++){
        q.emplace_back(progresses[i], speeds[i]);
    }

    int count = 0;
    while(!q.empty()){
        for(auto &p : q){
            p.first += p.second;
        }
        if(q.front().first >= 100){
            while(q.front().first >= 100){
                q.pop_front(); 
                count+=1;
            }
            answer.push_back(count);
            count = 0;
        }
    }

    return answer;
}