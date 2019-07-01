#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;
vector<int> number;

bool prevPer(vector<int> &num, int n){

    int i = n-1;
    while(i>0 && num[i] >= num[i-1])i--;
    if(i==0) return false;

    int j = n - 1;
    while(num[j] > num[i-1])j--;
    swap(num[j], num[i-1]);

    j = n - 1;
    while(i<j){
        swap(num[i], num[j]);
        i++, j--;
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
        number.push_back(temp);
    }

    if(prevPer(number, number.size())){
        for(int i=0; i<number.size(); i++)cout << number[i] << " ";
    }else cout << "-1";

    return 0;
}
