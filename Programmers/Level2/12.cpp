#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int i=123; i<=987; i++){
        string str = to_string(i);
        if(str[0] == str[1] || str[1] == str[2] || str[0] == str[2])continue;
        if(str[0] == '0' || str[1] == '0' || str[2] == '0')continue;

        bool pass;
        for(int j=0; j<baseball.size(); j++){
            pass = false;
            int strike=0, ball=0;
            string str2 = to_string(baseball[j][0]);
            for(int a=0; a<3; a++){
                if(str[a] == str2[a])strike+=1;
            }
            if(strike != baseball[j][1]) break;

            for(int a=0; a<3; a++){
                for(int b=0; b<3; b++){
                    if(a==b) continue;
                    if(str[a] == str2[b]){
                        ball+=1;
                    } 
                }
            }            
            if(ball != baseball[j][2]) break;
            pass = true;
        }
        if(pass)answer +=1;
    }
    return answer;
}