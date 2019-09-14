#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(), d.end());
    for(int p : d){
        if (sum + p <= budget){
            sum += p;
            answer += 1;
        }
    }
    return answer;
}