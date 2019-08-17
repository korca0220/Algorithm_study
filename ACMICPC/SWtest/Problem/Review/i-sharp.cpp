#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string original;
    getline(cin, original);

    vector<string> get;
    string now;
    for(auto s : original){
        if(s == ' ' || s == ',' || s == ';'){
            if(now.length() > 0){
                get.push_back(now);
            }
            now.clear();
        }else now+=s;
    }
    for(int i=1; i<get.size(); i++){
        string full = get[i];
        string value = get[0];
        while(full.length() >0 && !('a'<= full.back() && full.back() <='z')){
            if(full.back() == ']'){
                value+='[';
            }else if(full.back() == '['){
                value+=']';
            }else value+=full.back();
            full.pop_back();
        }
        cout << value << " " << full <<";\n";
    }

    return 0;
}