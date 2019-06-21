#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> num;
vector<vector <int>> contain;
int input[9];
bool selected[9];
void printNM(int index){
    
    if(index == M){
        vector<int> temp;
        for(int i=0; i<M; i++)temp.push_back(num[i]);
        contain.push_back(temp);
    }
    for(int i=0; i<N; i++){
        if(selected[i]) continue;
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
    sort(contain.begin(), contain.end());
    contain.erase(unique(contain.begin(), contain.end()), contain.end());

    for(auto v:contain){
        for(int i=0; i<M; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    return 0;
}