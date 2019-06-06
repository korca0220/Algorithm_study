#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;

int max_number = -987654321;
int min_number = 987654321;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;    
    vector<int> number;
    vector<int> oper;

    int temp;
    for(int i=0; i<input; i++){
        cin >> temp;
        number.push_back(temp);
    }

    for(int i=0; i<4; i++){
        cin >> temp;
        for(int j=0; j<temp; j++){
            oper.push_back(i);
        }
    }

    
    do{
        int sum = number[0];
        for(int i=1; i<input; i++){
            if(oper[i-1] == 0)sum += number[i];
            else if(oper[i-1] == 1)sum -= number[i];
            else if(oper[i-1] == 2)sum *= number[i];
            else sum /= number[i];
        }
        if (max_number < sum) max_number = sum;
        if (min_number > sum) min_number = sum;
    }while(next_permutation(oper.begin(), oper.end()));

    cout << max_number << "\n" << min_number;

    return 0;
}