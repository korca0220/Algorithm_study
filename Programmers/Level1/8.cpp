#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

ll solution(int a, int b) {
    ll answer = 0;
    if(a>b)swap(a,b);
    for(int i=a; i<=b; i++){
        answer += i;
    }
    return answer;
}