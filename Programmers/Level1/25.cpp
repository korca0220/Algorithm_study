#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto p : arr){
        answer += p;
    }
    return answer/arr.size();
}