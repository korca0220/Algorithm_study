#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dwarf[9];
bool selected[9];
bool one_print = false;

const int MAX = 100;

void calculate(int dwarf[9]){

    vector<int> result;
    int sum=0;
    for(int i=0; i<9; i++){
        if(selected[i] == true){
            sum = sum + dwarf[i];
            result.push_back(dwarf[i]);
        }
    }
    if (sum == MAX && one_print == false){
        sort(result.begin(), result.end());
        for(int i=0; i<result.size(); i++){
            printf("%d\n", result[i]);
        }
        one_print = true;
    }
}

void findMAX(int count, int index){
    
    // 기저사례 : 난쟁이가 7명 선택된경우
    if(count == 7){
        calculate(dwarf);
        return ;
    }
    else{
        for(int i=index; i<9; i++){
            if(selected[i] == true) continue;
            selected[i] = true;
            findMAX(count+1, i);
            selected[i] = false;
        }
    }
}

int main(){

    for(int i=0; i<9; i++){
        scanf("%d", &dwarf[i]);
    }
    findMAX(0, 0);

    return 0;
}