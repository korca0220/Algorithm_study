#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;

void printLotto(vector<int> &in_num, vector<int> &num, int index, int cnt){

    // 출력 조건
    if(cnt == 6){
        for(int i=0; i<6; i++) cout << num[i] << " ";
        cout << "\n";
        return ;
    }

    // 기저조건(탈출 후 평가)
    if(index == in_num.size()) return;
    else{
        num.push_back(in_num[index]);
        printLotto(in_num, num, index+1, cnt+1);
        num.pop_back();
        printLotto(in_num, num, index+1, cnt);
    }

}

int main(){

    cin.sync_with_stdio(false);

    do{
        cin >> input;
        vector<int> input_number;
        vector<int> number;
        int temp;
        for(int i=0; i<input; i++){
            cin >> temp;
            input_number.push_back(temp);
        }
        printLotto(input_number, number, 0, 0);
        cout << "\n";
    }while(input != 0);

    return 0;
}