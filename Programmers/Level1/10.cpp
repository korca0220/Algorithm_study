#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p,y;
    p=y=0;
    for(char c: s){
        if(c=='p'||c=='P')p++;
        else if(c=='y'||c=='Y')y++;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return (p==y?true:false);
}