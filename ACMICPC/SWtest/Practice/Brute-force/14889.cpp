#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int start_rink[21][21];
int N;

int getMax(vector<int> &num){

    vector<int> a;
    vector<int> b;
    for(int i=0; i<N; i++){
        if(num[i] == 0) a.push_back(i); 
        else b.push_back(i);
    }

    int sum_a=0, sum_b=0;
    for(int i=0; i<N/2; i++){
        for(int j=0; j<N/2; j++){
            if (i != j){
                sum_a += start_rink[a[i]][a[j]];
                sum_b += start_rink[b[i]][b[j]];
            }
        }
    }

    int min_sum = 987654321;
    min_sum = min(min_sum, abs(sum_a-sum_b));

    return min_sum;
}

int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &start_rink[i][j]);
        }
    }
    vector<int> number(N);
    for(int i=0; i<N/2; i++){
        number[i] = 1;
    }
    sort(number.begin(), number.end());

    int min_sum = 987654321;
    do{
        min_sum = min(min_sum, getMax(number));
    }while(next_permutation(number.begin(), number.end()));

    printf("%d", min_sum);

    return 0;
}