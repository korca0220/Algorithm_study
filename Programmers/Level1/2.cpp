#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i] == reserve[j]){
                answer +=1;
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }

    for(int i=0; i<lost.size(); i++){
        if(lost[i] == -1) continue;
        for(int j=0; j<reserve.size(); j++){
            if(reserve[j] == -1) continue;
            if(reserve[j] + 1 == lost[i] || reserve[j] - 1 == lost[i]){
                answer+=1;
                reserve[j] = -1;
                break;
            }
        }
    }

    return answer;
}