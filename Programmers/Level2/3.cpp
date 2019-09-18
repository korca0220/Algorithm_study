#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";

    while(n != 0){

        int temp = n%3;
        if(temp == 0)temp = 4;
        answer += to_string(temp);
        n-=1;
        n/=3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}