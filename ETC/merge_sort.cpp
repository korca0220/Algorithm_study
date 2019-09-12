#include <iostream>
typedef int I;
typedef void V;
using namespace std;
const int MAX = 20;

V merge(I arr[], I start, I mid, I end){

    I part1 = start;
    I part2 = mid + 1;
    I index = start;
    I temp[MAX];
    while(part1 <= mid && part2 <= end){
        if(arr[part1] <= arr[part2]){
            temp[index++] = arr[part1++];
        }else temp[index++] = arr[part2++];
    }
    if(part1 >mid){
        for(I i=part2; i<=end; i++){
            temp[index++] = arr[i];
        }
    }else{
        for(I i=part1; i<=mid; i++){
            temp[index++] = arr[i];
        }
    }
    for(I i=start; i<=end; i++){
        arr[i] = temp[i];
    }

}

V mergeSort(I arr[], I start, I end){

    if(start < end){
        I mid = (start + end) / 2;
        mergeSort(arr , start, mid);
        mergeSort(arr , mid+1, end);
        merge(arr,start, mid, end);
    }
}
I main(){

    I arr[8] = {5,7,1,2,3,4,5,8};
    mergeSort(arr, 0, 7);
    for(I i : arr){
        cout << i << " ";
    }

    return 0;
}

