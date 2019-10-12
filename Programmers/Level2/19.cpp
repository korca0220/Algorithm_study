#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <utility>
using namespace std;
const int MAX = 1000;
int check[MAX];

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int,int>> q;
    q.emplace(0,0);
    while(!q.empty()){
        int now_num, now_idx;
        tie(now_num, now_idx) = q.front();
        q.pop();
        if(now_idx<numbers.size()){
            for(int next : {now_num-numbers[now_idx], now_num+numbers[now_idx]}){
                q.emplace(next, now_idx+1);
            }
        }else if(now_idx == numbers.size()){
            if(now_num == target) answer+=1;
        }
    }
    return answer;
}