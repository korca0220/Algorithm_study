#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int len;
struct State{
    int sum;
    int index;
    vector<int> arr;
};
int getNum(State s){

    s.sum -= s.arr[s.index];
    if(s.sum == 0) return 0;

    s.arr[s.index] = 0;
    State rightState = s;
    State leftState = s;
    int right = 0, left = 0;
    do{
        right += 1;
        rightState.index = (rightState.index+1)%len;
    }while(!rightState.arr[rightState.index]);
    right += getNum(rightState);

    do{
        left += 1;
        leftState.index = ((leftState.index - 1 <0)?len-1:leftState.index-1);
    }while(!leftState.arr[leftState.index]);
    left += getNum(leftState);

    return (left<right?left : right);
    
}
int solution(string name) {
    int answer = 0;
    len = name.length();
    vector<int> arr(len);
    for(int i=0; i<len; i++){
        int count = min(name[i] - 'A', 'Z'-name[i] + 1);
        arr[i] = count;
        answer += arr[i];
    }
    State s;
    s.index = 0;
    s.sum = answer;
    s.arr = arr;
    answer += getNum(s);

    return answer;
}