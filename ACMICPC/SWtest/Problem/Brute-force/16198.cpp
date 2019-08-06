#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gogogo(vector<int> &in){

    int len = in.size();
    if(len==2) return 0;
    int ans = 0;
    for(int i=1; i<len-1; i++){
        int e=in[i-1]*in[i+1];
        vector<int> temp(in);
        temp.erase(temp.begin()+i);
        e += gogogo(temp);
        if(ans < e) ans = e;
    }
    return ans;
}


int main(){
    int N;
    scanf("%d", &N);
    vector<int> in(N);
    for(int i=0; i<N; i++)scanf("%d", &in[i]);

    printf("%d", gogogo(in));

    return 0;
}