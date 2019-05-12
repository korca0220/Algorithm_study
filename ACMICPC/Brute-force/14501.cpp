#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int INF = -987654321;
const int MAX = 15;
int input;
int t_input[MAX], p_input[MAX];
bool selected[MAX];

int max_profit = INF;


void findProfit(int total, int index){

    //기저사례 : time total이 input을 넘는경우
    if(index > input) return;

    if(index == input){
        if(max_profit < total) max_profit = total;
        return ;
    }
    else{
        // 상담 하기로 한날 (상담일 + index)
        findProfit(total + p_input[index], index + t_input[index] );
        
        // 상담을 안하는 날(즉, 날짜만 패스하고 페이는 그대로)
        // 상담 하기로 한날이 input을 넘으면 이 함수를 실행
        // 단순 날짜만 index 이동시킴
        findProfit(total, index+1);
    }

}

int main(){

    scanf("%d", &input);

    for(int i=0; i<input; i++){
        scanf("%d %d", &t_input[i], &p_input[i]);
    }
    findProfit(0, 0);
    printf("%d", max_profit);

    return 0;
}