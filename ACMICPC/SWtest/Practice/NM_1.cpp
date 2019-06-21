#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
bool selected[9];

void printNM(int index){

    if(index == M){
        for(int i=0; i<M; i++){
            printf("%d ", num[i]);
        }
        printf("\n");
        return ;
    }

    for(int i=1; i<=N; i++){
        if(selected[i])continue;
        selected[i]=true; num.push_back(i);
        printNM(index+1);
        selected[i]=false; num.pop_back();
    }
    
}

int main(){

    scanf("%d %d", &N, &M);
    printNM(0);

    return 0;
}