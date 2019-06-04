#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;
int max_number=0;

void findMaxSum(vector<int> &number){

    int sum=0;
    for(int i=0; i<number.size()-1; i++){
        sum = sum + abs(number[i]-number[i+1]);
    }
    if (max_number < sum) max_number = sum;
    
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    vector<int> number;
    int temp;
    for(int i=0; i<input; i++){
        cin >> temp;
        number.push_back(temp);
    }
    sort(number.begin(), number.end());

    while(next_permutation(number.begin(), number.end())){
        findMaxSum(number);
    }
    cout << max_number;

    return 0;
}