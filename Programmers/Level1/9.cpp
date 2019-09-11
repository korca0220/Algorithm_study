#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    sort(strings.begin(), strings.end(), [n](auto &a, auto &b) -> bool{
        if(a[n] == b[n]){
            return a < b;
        }else return a[n] < b[n];
    });
    return answer;
}