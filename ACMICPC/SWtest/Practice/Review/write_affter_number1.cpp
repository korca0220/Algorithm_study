/*
문제
1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

1234567891011121314151617181920212223...

이렇게 만들어진 새로운 수는 몇 자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1≤N≤100,000,000)이 주어진다.

출력
첫째 줄에 새로운 수의 자릿수를 출력한다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long total=0;

int main(){

    long long N;
    scanf("%lld", &N);
    // 1way
    /*
    for(int i=1; i<=N; i++){
        long long len = 1;
        long long temp = i;
        while(temp/10 > 0){
            temp /= 10;
            len+=1;
        }
        total+=len;
    }
    */

    // 2way
    int len = 1;
    for(int i=1; i<=N; i*=10){
        int end = i*10 -1 ; 
        if(end > N) end = N;
        total += (end - i + 1) *len; // 0을 포함
        len++;
    }
    printf("%lld", total);

    return 0;
}