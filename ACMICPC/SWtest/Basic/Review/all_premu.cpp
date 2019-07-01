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
    for(int i=1; i<=input; i++){
        num.push_back(i);
    }

    do{
        for(int i=0; i<num.size(); i++)cout << num[i] << " ";
        cout << "\n";
    }while(next_permutation(num.begin(), num.end()));

    return 0;
}