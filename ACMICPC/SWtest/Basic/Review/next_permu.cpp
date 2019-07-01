#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int input;
vector<int> num;

bool nextPer(vector<int> &num, int n){

    int i = n-1;
    while(i>0 && num[i-1]>= num[i]) i--;
    if(i==0) return false;

    int j = n-1;
    while(num[j] <= num[i-1]) j--;
    swap(num[j], num[i-1]);
    j = n-1;

    while(i < j){
        swap(num[i], num[j]);
        i++; j--;
    }
    return true;

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    
    // if(nextPer(num, num.size())){
    //     for(int i=0; i<num.size(); i++){
    //         cout << num[i] << " ";
    //     }
    // }else cout << "-1";

    if(next_permutation(num.begin(), num.end())){
        for(int i=0; i<num.size(); i++)cout << num[i] << " ";
    }else cout << "-1";

    return 0;
}