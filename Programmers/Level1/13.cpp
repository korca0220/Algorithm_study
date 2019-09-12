#include <string>
#include <vector>
using namespace std;
const int MAX = 1000000;

vector<bool> primSet(int n){
    vector<bool> c(MAX, true);
    for(int i=2; i<=MAX; i++){
        if(c[i] == true){
            for(int j=i*2; j<=MAX; j+=i){
                c[j] = false;
            }
        }
    }
    return c;
}
int solution(int n) {
    int answer = 0;
    return answer;
}