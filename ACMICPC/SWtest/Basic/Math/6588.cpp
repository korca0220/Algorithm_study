#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX];


vector<int> getPrime(){

    vector<int> odd_number;
    odd_number.push_back(0); // [0]
    odd_number.push_back(0); // [1]

    for(int i=2; i<=MAX; i++)isPrime[i] = true;
    for(int i=2; i<=sqrt(MAX); i++){
        if(isPrime[i]){
            for(int j= i*i; j<=MAX; j+=i)isPrime[j] = false;
        }
    }

    for(int i=2; i<=MAX; i++){
        if(i%2 != 0 && isPrime[i])odd_number.push_back(i);
    }
    
    return odd_number;
}


int main(){

    
    vector<int> odd = getPrime();
    int input=1;

    while(true){
        
        scanf("%d", &input);
        if(input==0)break;                             
        bool check=false;
        int a,b;
        int max = 0;        

        for(int i=2; i<odd.size(); i++){
            for(int j=i; j<odd.size(); j++){                     
                if(odd[i] + odd[j] == input){                                                                                   
                    a = odd[i];
                    b = odd[j];
                    check = true;
                    break;                
                }
                else if(odd[i] + odd[j] > input)break;
            }
            if(check)break;        
        }
        if(!check) printf("Goldbach's conjecture is wrong.\n");
        else printf("%d = %d + %d\n", input, a, b);
    }

    return 0;
}