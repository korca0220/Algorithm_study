#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> time_v;
vector<int> pay;
int max_pay = -987654321;

void getMaxPay(int pay_sum, int index){

    if(index > N)return ;
    if(index == N){
        if(max_pay < pay_sum)max_pay = pay_sum;
        return ;
    }
    getMaxPay(pay_sum+pay[index], index+time_v[index]);
    getMaxPay(pay_sum, index+1);

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int temp_a, temp_b;
    for(int i=0; i<N; i++){
        cin >> temp_a >>  temp_b;
        time_v.push_back(temp_a);
        pay.push_back(temp_b);
    }
    getMaxPay(0, 0);
    cout << max_pay;

    return 0;
}