#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
int input[9];
bool selected[9];

void printNM(int index, int count){
    if(count==M){
        for(int i=0;i<M;i++)printf("%d ", num[i]);
        printf("\n");
        return ;
    }
    for(int i=index; i<N; i++){
        num.push_back(input[i]);
        printNM(i+1, count+1);
        num.pop_back();
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)scanf("%d", &input[i]);
    sort(input, input+N);
    printNM(0, 0);
    return 0;
}