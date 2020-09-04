#include<bits/stdc++.h>

using namespace std;


int partition(int arr[],int start,int end){

    int pivot=arr[end];
    int pindex=start;

    for(int i = start; i < end;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[pindex]);
            pindex++;

        }
        
    }
    swap(arr[pindex],arr[end]);

    return pindex;


}

void quicksort(int arr[],int start,int end){
    
    if(start<end){
        
        int pindex=partition(arr,start,end);
        quicksort(arr,start,pindex-1);
        quicksort(arr,pindex+1,end);

    }

}

int main(){
    int arr[]={2,9,1,5,3,6,4};
    int len=sizeof(arr)/sizeof(arr[0]);

    
    quicksort(arr,0,6);

    
    for(int i =0;i<len;i++)
        cout<<arr[i]<<"  ";

    return 0;


}