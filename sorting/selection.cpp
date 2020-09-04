#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void selection(int arr[],int len){

    for (int i=0;i<len-1;i++){
        int imin=i;
        for(int j=i+1 ; j<len;j++){
            if(arr[j]<arr[imin])
            imin=j;
        }
        int temp=arr[i];
        arr[i]=arr[imin];
        arr[imin]=temp;
    }
    
}
int main(){

    int arr[]={2,1,6,5,7,3};
    int len=sizeof(arr)/sizeof(arr[1]);
    selection(arr,len);
    for (int i=0;i<len;i++)
        cout<<arr[i]<<" ";
}