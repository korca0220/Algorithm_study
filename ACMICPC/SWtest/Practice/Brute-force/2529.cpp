#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int N;
char boo[10];

bool getCheck(vector<int> &num){

    for(int i=0; i<N; i++){
        if(boo[i] == '<'){
            if(num[i] < num[i+1]) continue;
            else return false;
        }
        else if(boo[i] == '>'){
            if(num[i] > num[i+1]) continue;
            else return false;
        }
    }

    return true;
}

int main(){

    scanf("%d", &N);
    vector<int> min_vector(N+1);
    vector<int> max_vector(N+1);
    for(int i=0; i<N; i++)scanf(" %c", &boo[i]);
    for(int i=0; i<=N; i++){
        min_vector[i] = i;
        max_vector[i] = 9-i;
    }
    do{
        if(getCheck(max_vector)) break;
    }while(prev_permutation(max_vector.begin(), max_vector.end()));
    
    do{
        if(getCheck(min_vector)) break;

    }while(next_permutation(min_vector.begin(), min_vector.end()));

    for(int i=0; i<=N; i++)printf("%d", max_vector[i]);
    printf("\n");
    for(int i=0; i<=N; i++)printf("%d", min_vector[i]);

    return 0;
}