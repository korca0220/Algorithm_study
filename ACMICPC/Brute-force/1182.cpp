/*
문제
N개의 정수로 이루어진 수열이 있을 때, 길이가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.

예제 입력 1 
5 0
-7 -3 -2 5 8
예제 출력 1 
1
*/

#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 20;

int input_array[MAX], input;
int target;
int count_num = 0;

void findSum(int sum, int index){

    sum += input_array[index];

    // 기저 조건 : index 가 input를 넘는 경우
    if (index >= input) return ;

    // count 조건
    if (sum == target) count_num++;

    // 현재 수를 더하지 않는 경우(다음 수로 넘어가는 경우)
    findSum(sum - input_array[index], index+1);

    // 현재 수를 더하는 경우(누적 더하기)
    findSum(sum, index+1);

}


int main(){

    scanf("%d %d", &input, &target);

    for(int i=0; i<input; i++){
        scanf("%d", &input_array[i]);
    }

    findSum(0, 0);
    printf("%d", count_num);

    return 0;
}