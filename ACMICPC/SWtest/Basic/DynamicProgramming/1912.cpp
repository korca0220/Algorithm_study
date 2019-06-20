#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int N;
vector<int> num(MAX+1, 0);
int S[MAX+1];


int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++)scanf("%d", &num[i]);

    S[0] = num[0];
    for(int i=1; i<N; i++){
        S[i] = max(S[i-1]+num[i], num[i]);
    }

    int max_number = -987654321;
    for(int i=0; i<N; i++)max_number = max(max_number, S[i]);
    printf("%d", max_number);

    return 0;
}