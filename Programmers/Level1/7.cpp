#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int p : arr){
        if(p%divisor == 0)answer.push_back(p);
    }
    sort(answer.begin(), answer.end());
    if(answer.empty())answer.push_back(-1);
    return answer;
}