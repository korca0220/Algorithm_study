#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
char boo[20];
bool selected[20];
vector<string> contain;

bool check(char p_x, char x, int count){

    if(boo[count-1] == '<'){
        return p_x < x ? true : false;
    }else if(boo[count-1] == '>'){
        return p_x > x ? true : false;
    }
}
void findMindMax(int index, int count, string num){

    if(index == N+1){
        contain.push_back(num);
        return ;
    }

    for(int i=0; i<=9; i++){
        if(selected[i]) continue;
        if(index==0 || check(num[index-1], i+'0', count)){
            selected[i] = true; 
            findMindMax(index+1, count+1, num+to_string(i));
            selected[i] = false; 
        }
    }

}


int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++)scanf(" %c", &boo[i]);
    findMindMax(0, 0, "");
    auto p = minmax_element(contain.begin(), contain.end());
    cout << *p.second << "\n" << *p.first;

    return 0;
}