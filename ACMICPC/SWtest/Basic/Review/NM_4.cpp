#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> num;
void printNM(int index, int count){
    if(count==M){
        for(int i=0;i<M; i++)printf("%d ", num[i]);
        printf("\n"); return ;
    }
    for(int i=index; i<=N; i++){
        num.push_back(i);
        printNM(i, count+1);
        num.pop_back();
    }
}
int main(){
    scanf("%d %d", &N, &M);
    printNM(1, 0);
    return 0;
}