#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    vector<string> contain;
    string answer = "";
    for(char c : s){
        string str = "";
        if(c != ' ')str +=c;
        else{
            contain.push_back(str);
            str = "";
        }
    }
    for(string &s : contain){
        for(int i=0; i<s.length(); i++){
            if(i%2==0) s[i] = toupper(s[i]);
            else s[i] = tolower(s[i]);
        }
        answer += s;
    }

    return answer;
}