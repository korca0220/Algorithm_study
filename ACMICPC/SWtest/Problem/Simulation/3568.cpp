#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string str;
    getline(cin, str);

    vector<string> a;
    string now;
    for(char x : str){
        if(x == ' ' || x == ',' || x == ';'){
            if(now.length() > 0){
                a.push_back(now);
            }
            now.clear();
        }else{
            now+=x;
        }
    }

    string start_str = a[0];
    for(int i=1; i<a.size(); i++){
        string oper = a[i];
        string value = start_str;
        while(oper.length() > 0 && !('a'<= oper.back() && oper.back() <='z')){
            if(oper.back() == '['){
                value += ']';
            }else if(oper.back() == ']'){
                value += '[';
            }else{
                value += oper.back();
            }
            oper.pop_back();
        }
        cout << value << " " << oper << ";\n";
    }

    return 0;
}