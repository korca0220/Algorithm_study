#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int HEIGHT = 100;
int dwarf[9];
int input;
bool checker=false;
bool selected[9] = {false, };


void calculator(){

    vector<int> finded;
    int sum=0;
    for(int i=0; i<9; i++){
        if(selected[i]){
            finded.push_back(dwarf[i]);
            sum += dwarf[i];
        }
    }
    if (sum == HEIGHT && checker == false){
        sort(finded.begin(), finded.end());           
        for(int i=0; i<finded.size(); i++){
            printf("%d\n", finded[i]);
        }            
        checker=true;
    }

    

}

void findDwarf(int index, int count){
    
    if(count == 7){
        calculator();
        return ;      
    }

    for(int i=index; i<9; i++){
        if(selected[i] == true) continue;
        selected[i] = true;
        findDwarf(i, count+1);
        selected[i] = false;
    }

}


int main(){

    for(int i=0; i<9; i++){
        scanf("%d", &dwarf[i]);
    }

    findDwarf(0, 0);

    return 0;
}