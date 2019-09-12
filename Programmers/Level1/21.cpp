#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    vector<int> temp;
    while(n != 0){
        temp.push_back(n%10);
        n/=10;
    }
    sort(temp.begin(), temp.end(), greater<int>());
    long long answer = 0;
    for(int i=0; i<temp.size(); i++){
        answer = (answer*10) + temp[i];
    }
    return answer;
}