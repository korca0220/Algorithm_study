#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int N;
vector<int> num(MAX, 0);
int fS[MAX];
int bS[MAX];

int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++)scanf("%d", &num[i]);


    int rMax = -987654321;
    for(int i=0; i<N; i++){
        fS[i] = max(num[i], fS[i-1]+num[i]);
        bS[i] = max({num[i], fS[i-2]+num[i], bS[i-1]+num[i]});
        rMax = max({rMax,fS[i], bS[i]});
    }
    
    printf("%d", rMax);

    return 0;
}