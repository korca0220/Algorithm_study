#include <iostream>
#include <vector>
using namespace std;

int input;
int plus=0, minus=0, mul=0, divv=0;
vector<int> in_num;
vector<int> in_oper;
int min_num = 987654321, max_num = -987654321;

void getMinMax(int sum, int index, int plus, int minus, int mul, int divv){


    if(index == input){
        if(min_num > sum) min_num = sum;
        if(max_num < sum) max_num = sum;
        return;
    }else{
        if(plus > 0)getMinMax(sum + in_num[index], index+1, plus-1, minus, mul, divv);
        if(minus > 0)getMinMax(sum - in_num[index], index+1, plus, minus-1, mul, divv);
        if(mul > 0)getMinMax(sum * in_num[index], index+1, plus, minus, mul-1, divv);
        if(divv > 0)getMinMax(sum / in_num[index], index+1, plus, minus, mul, divv-1);
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    int temp;
    for(int i=0; i<input; i++){
        cin >> temp;
        in_num.push_back(temp);
    }
    for(int i=0; i<4; i++){
        cin >> temp;
        in_oper.push_back(temp);
    }

    getMinMax(in_num[0], 1, in_oper[0], in_oper[1], in_oper[2], in_oper[3]);
    cout << max_num << "\n" << min_num;

    return 0;
}