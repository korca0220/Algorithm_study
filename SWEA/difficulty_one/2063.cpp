#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    int input, in_num;
    vector<int> number;
    scanf("%d", &input);

    int test_count = 1;

    for(int i=0; i<input; i++){
        scanf("%d", &in_num);
        number.push_back(in_num);
        sort(number.begin(), number.end());
    }

    printf("%d", number[input/2]);


    return 0;
}