#include <iostream>
#include <vector>
using namespace std;

int N,S;
int count = 0;
vector<int> in_num;

void getPartSeq(int index, int sum){

    if(index == N){
        if(sum == S){
            count+=1;
        }
        return ;
    }
    getPartSeq(index+1, sum+in_num[index]);
    getPartSeq(index+1, sum);
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    int temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        in_num.push_back(temp);
    }
    getPartSeq(0, 0);
    if(S==0)count-=1;
    cout << count;

    return 0;

}