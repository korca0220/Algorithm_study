#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L,C;
vector<char> a;

bool getCheck(string str){
    
    int mo = 0;
    int ja = 0;
    for(int i=0; i<L; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] =='i' || str[i] == 'o' || str[i] =='u'){
            mo++;
        }else ja++;
    }
    if(mo>=1 && ja>=2) return true;

    return false;
}

void recurPasswd(string str, int index){

    if(index > C) return ; 
    if(str.length() == L){
        if(getCheck(str)){
            cout << str << "\n";
        }
        return ;
    }
    recurPasswd(str+a[index], index+1);
    recurPasswd(str, index+1);

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;
    for(int i=0; i<C; i++){
        char temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    recurPasswd("", 0);


    return 0;
}