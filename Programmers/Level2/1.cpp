#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
struct Truck{
    int weight;
    int position;
};
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<Truck> q;
    vector<Truck> qq;
    for(int p : truck_weights){
        Truck t;
        t.weight = p; t.position = 0;
        q.push(t);
    }

    int sum = 0;
    while(true){
        Truck t = q.front();
        if(sum + t.weight <= weight){
            sum += t.weight;
            qq.push_back(t);
            q.pop();
            answer +=1;
            for(auto &p: qq){
                p.position +=1;
            }
            continue;
        }else{
            for(auto &p : qq){
                p.position+=1;
                if(p.position % bridge_length == 0){
                    sum -= p.weight;
                    p.position = -1;
                    continue;
                }
            }
            answer +=1;
        }
        bool ok = true;
        for(auto p: qq){
            if(p.position == -1)ok=false;
        }
        if(!ok)break;
    }
    
    return answer;
}

int main(){

    return 0;
}