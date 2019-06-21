#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
int input[9];
bool selected[9];

void printNM(int index){
    if(index==M){
        for(int i=0; i<M; i++)printf("%d ", num[i]);
        printf("\n");
        return ;
    }
    for(int i=0; i<N; i++){
        if(selected[i])continue;
        selected[i] = true; num.push_back(input[i]);
        printNM(index+1);
        selected[i] = false; num.pop_back();
    }        
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)scanf("%d", &input[i]);
    sort(input, input+N);
    printNM(0);
    return 0;
}