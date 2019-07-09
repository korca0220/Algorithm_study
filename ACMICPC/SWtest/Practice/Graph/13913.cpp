#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int MAX = 200000;
bool check[MAX+1];
int dist[MAX+1];
int from[MAX+1];

void print(int n, int m){
    if(n!=m){
        print(n, from[m]);
    }
    printf("%d ", m);
    return ;
}

void BFS(int n){

    deque<int> dq;
    dq.push_back(n);
    check[n] = true;
    dist[n] = 0;
    while(!dq.empty()){
        int x = dq.front();
        dq.pop_front();
        if(x*2 <=MAX && check[x*2] == false){
            dq.push_front(x*2);
            check[x*2] = true;
            from[x*2] = x;
            dist[x*2] = dist[x] + 1;
        }
        if(x-1 >= 0 && check[x-1] == false){
            dq.push_back(x-1);
            check[x-1] = true;
            from[x-1] = x;
            dist[x-1] = dist[x] + 1;
        }
        if(x+1 <= MAX && check[x+1] == false){
            dq.push_back(x+1);
            check[x+1] = true;
            from[x+1] = x;
            dist[x+1] = dist[x] + 1;
        }
    }

}

int main(){

    int N, K;
    scanf("%d %d", &N, &K);
    BFS(N);
    printf("%d\n", dist[K]);
    print(N, K);

    return 0;
}