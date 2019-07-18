#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int K;
char boo[10];
vector<string> contain;
bool selected[10];

bool check(char pre_num, char next_num, int count){

    if(boo[count-1] == '<'){
        return pre_num < next_num ? true : false;
    }else if(boo[count-1] == '>'){
        return pre_num > next_num ? true : false;
    }
    return false;
}

void find_mindmax(int index, string num){

    if(index == K+1){
        contain.push_back(num);
        return ;
    }
    for(int i=0; i<=9; i++){
        if(selected[i]) continue;
        else{
            if(index==0 || check(num[index-1], i+'0', index)){
                selected[i] = true;
                find_mindmax(index+1, num+to_string(i));
                selected[i] = false;
            }
        }
    }

}

int main(){

    scanf("%d", &K);
    for(int i=0; i<K; i++)scanf(" %c", &boo[i]);
    find_mindmax(0,"");
    auto p = minmax_element(contain.begin(), contain.end());
    cout << *p.second << "\n";
    cout << *p.first;

    return 0;
}