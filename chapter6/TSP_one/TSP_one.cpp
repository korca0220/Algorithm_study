/*
문제
NP-Complete 문제의 가장 유명한 예 중 하나인 여행하는 외판원 문제 (Traveling Salesman Problem) 은, 여러 개의 도시와 그 도시 간의 거리가 주어졌을 때, 각 도시를 정확히 한 번씩 방문하는 가장 짧은 경로를 찾는 문제이다. 이 문제를 다항 시간에 해결할 수 있는 방법은 현재까지는 존재하지 않지만, 도시의 숫자가 작은 경우에는 비교적 사용 가능한 시간 안에 문제를 해결할 수 있다.

AOJ 에서 이 문제는 같은 내용을 가진 문제 여러 개로 구성된다. 문제 번호에 비례해 도시의 개수가 올라가므로, 뒤로 갈수록 더욱 효율적인 방법을 써야 해결할 수 있다.

도시의 수 N <= 8 이라고 할 때, 여행하는 외판원 문제를 해결하는 프로그램을 작성하라.

입력
입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 이 주어진다. 각 테스트 케이스의 첫 줄에는 도시의 수 N (3 <= N <= 8) 이 주어진다. 그 후 N 줄에, 각 N 개씩의 실수로 도시간의 거리가 주어진다. 도시들은 1 부터 N 까지의 숫자로 표현되며, i 번째 줄의 j 번째 실수는 i번째 도시와 j번째 도시 사이의 거리이다. 각 거리는 0 이상 1415 이하이고, 소수점 밑 열 자리까지 주어진다.

주어진 행렬은 대칭이며, 입력되는 거리들은 삼각 부등식 (triangle inequality) 을 만족한다고 가정해도 좋다.

출력
테스트 케이스마다 한 줄에 최소 경로의 길이를 소수점 밑 열 자리까지 출력한다. 1e-7 이하의 절대/상대 오차가 있어도 맞는 답으로 인정한다.

예제 입력
2
3
0.0000000000  611.6157225201  648.7500617289
611.6157225201  0.0000000000  743.8557967501
648.7500617289  743.8557967501  0.0000000000
4
0.0000000000  326.0008994586  503.1066076077  290.0250922998
326.0008994586  0.0000000000  225.1785728436  395.4019367384
503.1066076077  225.1785728436  0.0000000000  620.3945520632
290.0250922998  395.4019367384  620.3945520632  0.0000000000

예제 출력
1260.3657842490
841.2045646020
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;

int n; //도시의 개수
double dist[MAX][MAX]; //두 도시간의 거리

//path : 지금까지 만든 경로
//visited : 각 도시 방문 여부
//current_length : 지금까지 만든 경로 길이

double shortestPath(vector<int>& path, vector<bool>& visited, double current_length){

    // 기저조건 : 경로의 길이가 도시와 같은경우(모두 방문한 경우)
    if(path.size() == n){
        // 현재 경로 + path에서부터 ~path 끝까지의 거리
        return current_length;
    }

    double ret = numeric_limits<double>::max();

    //다음 방문할 도시를 모두 시도
    for(int next=0; next<n; next++){
        if(visited[next]) continue; //이미 방문한경우
        int here = path.back();
        path.push_back(next);
        visited[next] = true;

        // 나머지 경로들을 shortestPath로 얻어온 뒤 최소값을 비교
        double cand = shortestPath(path, visited, current_length+dist[here][next]);
        ret = min(ret, cand);
        visited[next] = false;
        path.pop_back();
    }
    return ret;
}

int main(){

    int t_input;
    
    scanf("%d", &t_input);
        
    while(t_input--){
        scanf("%d", &n);
        
        double ret;
        double max_result = numeric_limits<double>::max();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%lf", &dist[i][j]);
            }            
        }
        for(int i=0; i<n; i++){
            vector<int> path(1, i);
            vector<bool> visited(n, false);
            visited[i] = true;
            ret = shortestPath(path, visited, 0.0000000000);
            if(max_result > ret) max_result = ret;
        } 
        printf("%.10f\n", max_result);        
    }


    return 0;
}