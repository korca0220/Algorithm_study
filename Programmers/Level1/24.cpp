#include <string>
#include <vector>
#include <iostream>
const int OVER = 500;
using namespace std;

long getNum(long num, int count){
    if(num == 1) return count;
    if(count > OVER) return -1;
    
    if(num%2 == 0) return getNum(num/2, count+1);
    else if(num%2 != 0) return getNum(num*3+1, count+1);
}
int solution(int num) {
    int answer = getNum(num, 0);
    return answer;
}