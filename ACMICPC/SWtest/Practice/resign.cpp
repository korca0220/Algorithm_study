#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int T[16];
int P[16];
int max_total=0;

void getMaxP(int pay, int day){

    if(day > N) return;
    if(day == N){
        max_total = max(max_total, pay);
        return ;
    }
    getMaxP(pay+P[day], day+T[day]);
    getMaxP(pay, day+1);
}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> P[i];
    }
    getMaxP(0, 0);
    cout << max_total;

    return 0;
}