#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0;
    queue<int> q;
    for(int i=0; i<truck_weights.size(); i++){
        int d = truck_weights[i];
        while(true){
            if(q.empty()){
                q.push(d);                
                sum += d;
                answer += 1;
                break;
            }
            else if(q.size() ==  bridge_length){
                sum -= q.front(); q.pop();
            }else{
                if(sum + d > weight){
                    q.push(0);
                    answer+=1;
                }else{
                    q.push(d);
                    sum += d;
                    answer+=1;
                    break;
                }
                
            }
        }
    }
    return answer + bridge_length;
}