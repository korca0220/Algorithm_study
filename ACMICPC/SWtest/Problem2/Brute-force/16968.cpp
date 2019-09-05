#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string str;
int go(int index, char last){

    if(index == str.length()){
        return 1;
    }
    char start = (str[index] == 'c' ? 'a' : '0');
    char end = (str[index] == 'c' ? 'z' : '9');
    int ans = 0;
    for(int i=start; i<=end; i++){
        if(i != last){
            ans += go(index+1, i);
        }
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    cout << go(0, ' ');
   
    return 0;
}