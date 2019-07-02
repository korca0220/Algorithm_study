#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int start_rink[21][21];
bool check[21];
int min_num = 987654321;
void cal(){

    vector<int> a; vector<int> b;
    for(int i=0; i<N; i++){
        if(check[i])a.push_back(i);
        else b.push_back(i);
    }

    int sum_a=0, sum_b=0;
    for(int i=0; i<N/2; i++){
        for(int j=0; j<N/2; j++){
            if(i != j){
                sum_a += start_rink[a[i]][a[j]];
                sum_b += start_rink[b[i]][b[j]];
            } 
        }
    }
    if(min_num > abs(sum_a-sum_b)) min_num = abs(sum_a-sum_b);

}

void find_min(int des, int index){

    if(des==0){
        cal();
        return ;
    }
    
    check[0] = true;
    for(int i=index; i<N; i++){
        if(check[i])continue;
        check[i] = true;
        find_min(des-1, i+1);
        check[i] = false;
    }
}


int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &start_rink[i][j]);
        }
    }
    find_min((N/2)-1, 1);
    printf("%d", min_num);
    return 0;
}