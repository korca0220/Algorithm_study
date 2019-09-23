#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    int j=0;
    for(int i=0; i<k; i++){
        if(dates[j] == i){
            pq.push(supplies[j]);
            j++;
        }
        if(stock == 0){
            stock += pq.top();
            pq.pop();
            answer+=1;
        }
        stock-=1;
    }
    return answer;
}