#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;
vector<int> num;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=0; i<input; i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end());

    int max_number = 0;
    do{
        int sum = 0;
        for(int i=0; i<input-1; i++){
            sum += abs(num[i] - num[i+1]);
        }
        max_number = max(max_number, sum);
    }while(next_permutation(num.begin(), num.end()));

    cout << max_number;

    return 0;
}