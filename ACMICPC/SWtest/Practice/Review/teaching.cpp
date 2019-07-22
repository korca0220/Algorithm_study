#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N,K;

int count(int mask, vector<int> & words){

    int cnt = 0;
    for(int word : words){
        if((word & ((1<<26)-1-mask))== 0){
            cnt += 1;
        }
    }
    return cnt;
}

int getGo(int index, int k, int mask, vector<int> &words){

    if(k<0) return 0;
    if(index == 26)return count(mask, words);

    int ans = 0;
    int t1 =getGo(index+1, k-1, mask |(1<<index), words);
    if(ans < t1) ans = t1;
    if(index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
        t1 = getGo(index+1, k, mask, words);
        if(ans < t1) ans = t1;
    }
    return ans;
}

int main(){
    scanf("%d %d", &N, &K);
    vector<int> word(N);
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(char w : str){
            word[i] |= (1<<(w-'a'));
        }
    }
    printf("%d", getGo(0,K,0, word));

    return 0;
}