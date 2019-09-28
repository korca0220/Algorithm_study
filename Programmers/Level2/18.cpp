#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    int b=(brown/2)-1;
    int r;
    do{
        r = b-2;
        if(red%r != 0){
            b-=1;
            continue;
        }
        int n = ((red/r)*2) + (b*2);
        int m = (red/r)+2;
        if(n == brown){
            answer.push_back(b);
            answer.push_back(m);
            break;
        }
    }while(true);
    return answer;
}