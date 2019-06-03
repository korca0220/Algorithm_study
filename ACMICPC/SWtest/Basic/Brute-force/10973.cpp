#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;

bool getPrePer(vector<int> &perma, int n){

    int i = n-1;
    while(i > 0 && perma[i-1] <= perma[i]) i-= 1;
    if (i <= 0) return false;

    int j = n-1;
    while(perma[j] > perma[i-1]) j-= 1;

    swap(perma[j], perma[i-1]);
    j = n-1;
    while(i<j){
        swap(perma[j], perma[i]);
        i +=1; j-=1;
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    vector<int> number;
    int temp_input;
    for(int i=0; i<input; i++){
        cin >> temp_input;
        number.push_back(temp_input);
    }

    // 직접 구현
    if(getPrePer(number, number.size())){
        for(int i=0; i<number.size(); i++)cout << number[i] << " ";
    }else cout << "-1";

    // STL 사용
    // if(prev_permutation(number.begin(), number.end())){
    //     for(int i=0; i<number.size(); i++)cout << number[i] << " ";
    // }else cout << "-1";

    return 0;
}