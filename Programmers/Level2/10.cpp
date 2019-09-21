#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int MAX = 9999999;
set<int> braket;
bool check[MAX];
int solution(string numbers) {
    int answer = 0;


    check[0] = true; check[1] = true;
    for(int i=2; i<=MAX; i++){
        if(check[i])continue;
        for(int j=i*2; j<=MAX; j+=i){
            if(check[j] == false){
                check[j] = true;
            }
        }
    }
    sort(numbers.begin(), numbers.end());
    do{ 
        string str;
        for(int i=0; i<numbers.length(); i++){
            str += numbers[i];
            braket.insert(stoi(str));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));

    for(auto p : braket){
        cout << p << " ";
        answer += (check[p]==false?1:0);
    }
    return answer;
}

int main(){

    solution("134");
    return 0;
}