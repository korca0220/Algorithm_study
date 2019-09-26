#include <string>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

const string DELMAX = "D 1";
const string DELMIN = "D -1";

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;

    for(string s : operations){
        if(s == DELMAX){
            if(!dq.empty())dq.pop_front();
        }else if(s == DELMIN){
            if(!dq.empty())dq.pop_back();
        }else{
            string num = s.substr(2);
            dq.push_front(stoi(num));
        }
        sort(dq.begin(), dq.end(), greater<int>());
    }
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(dq.front());
        answer.push_back(dq.back());
    }

    return answer;
}