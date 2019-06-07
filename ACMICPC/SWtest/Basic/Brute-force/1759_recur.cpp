#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L,C;

bool getCheck(string str_input){

    int mo=0, ja=0;
    for(int i=0; i<str_input.length(); i++){
        if(str_input[i] == 'a' || str_input[i] == 'e' || str_input[i] == 'i' || str_input[i] == 'o' || str_input[i] == 'u'){
            mo++;
        }else ja++;
    }
    if (mo >= 1 && ja >=2) return true;
    else return false;
}

void printPass(vector<char> input, string passwd, int index){

    if(index > C) return ;
    if(passwd.length() == L){
        if(getCheck(passwd)){
            cout << passwd << "\n";
            return ;
        } 
    }else{
        printPass(input, passwd+input[index], index+1);
        printPass(input, passwd, index+1);
    }
}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;
    vector<char> input;
    char temp;
    for(int i=0; i<C; i++){
        cin >> temp;
        input.push_back(temp);
    }
    sort(input.begin(), input.end());

    printPass(input, "", 0);

    return 0;
}