#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> num;
vector<vector <int>> contain;
int input[9];

void getContain(int index, int count){
    if(count == M){
        vector<int> temp;
        for(int i=0; i<M; i++)temp.push_back(num[i]);
        contain.push_back(temp);
    }
    else{
        for(int i=index; i<N; i++){
            num.push_back(input[i]);
            getContain(i, count+1);
            num.pop_back();
        }
    }
}

int main(){
    scanf("%d %d", &N,&M);
    for(int i=0; i<N; i++)scanf("%d", &input[i]);
    sort(input, input+N);
    getContain(0, 0);
    sort(contain.begin(), contain.end());
    contain.erase(unique(contain.begin(), contain.end()), contain.end());
    for(auto v : contain){
        for(int i=0; i<M; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    return 0;
}