#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    int cnt=0;
    while(pq.top() < K){
        if(pq.size() == 1) return -1;
        int now = pq.top(); pq.pop();
        int next = pq.top(); pq.pop();
        pq.push(now+(next*2));
        answer+=1;
    }
    return answer;
}