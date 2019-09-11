#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    string next[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    int dx[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    string answer = "";
    int day = 0;
    for(int i=0; i<a-1; i++){
        day += dx[i];
    }
    day += b-1;
    answer = next[day%7];
    return answer;
}