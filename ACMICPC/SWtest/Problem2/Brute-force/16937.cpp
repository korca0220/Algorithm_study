#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;

int h,w,n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    cin >> n;

    vector<pair<int,int>> in(n);
    for(int i=0; i<n; i++){
        cin >> in[i].first >> in[i].second;
    }

    int x1,y1,x2,y2;
    int ans = 0;
    for(int i=0; i<n; i++){
        tie(x1,y1) = in[i];
        for(int j=i+1; j<n; j++){
            tie(x2,y2) = in[j];
            for(int rot1 = 0; rot1<2; rot1++){
                for(int rot2 = 0; rot2<2; rot2++){
                    if(x1+x2 <= h && max(y1,y2) <= w){
                        int temp = (x1*y1) + (x2*y2);
                        if(ans < temp) ans = temp;
                    }
                    if(max(x1,x2) <= h && y1+y2 <= w){
                        int temp = (x1*y1) + (x2*y2);
                        if(ans < temp) ans = temp;
                    }
                    swap(x2, y2);
                }
                swap(x1, y1);
            }
        }
    }
    cout << ans;

    return 0;
}