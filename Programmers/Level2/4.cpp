#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> beam;
    for(int i=heights.size()-1; i>=0; i--){
        for(int j=i; j>=0; j--){
            if(j==i)continue;
            if(heights[i] < heights[j]){                
                beam.push(j+1);
                break;
            }
        }
        if(beam.size() != heights.size() - i)beam.push(0);
    }
    while(!beam.empty()){
        answer.push_back(beam.top());
        beam.pop();
    }
    return answer;
}