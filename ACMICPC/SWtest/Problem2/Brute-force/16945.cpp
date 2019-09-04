#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &a){ //magic-square check

    //garo, sero
    int sum = a[0] + a[1] + a[2];
    for(int i=0; i<3; i++){
        int garo=0, sero=0;
        for(int j=0; j<3; j++){
            garo += a[i*3+j];
            sero += a[j*3+i];
        }
        if(garo != sum || sero != sum) return false;   
    }

    //diag
    int right = a[0] + a[4] + a[8];
    int left  = a[2] + a[4] + a[6];
    if(right != sum || left != sum) return false;
   
    return true;
}

int cal(vector<int> &a, vector<int> &b){ // difference-value sum of a and b 

    int total = 0;
    for(int i =0; i<9; i++){
        total += abs(a[i] - b[i]);
    }
    return total;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> b(9);
    for(int i=0; i<9; i++){
        cin >> b[i];
    }
    vector<int> a;
    for(int i=1; i<=9; i++)a.push_back(i);

    int ans = -1;
    do{
        if(check(a)){
            int temp = cal(a,b);
            if(ans == -1 || ans > temp)ans = temp;
        }
    }while(next_permutation(a.begin(), a.end()));
    cout << ans;

    return 0;
}