#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void bubble(int arr[],int n){

    for(int k=1;k<n;k++){
        for(int i=0;i<n-k;i++){
            if(arr[i]>arr[i+1]){
            // int temp=arr[i];
            // arr[i]=arr[i+1];
            // arr[i+1]=temp;
            swap(arr[i],arr[i+1]);
            }
        }
    }
   
}

int main(){

    int arr[]={10,5,1,9,3},len;
    len=sizeof(arr)/sizeof(arr[1]);

    bubble(arr,len);
    for(int i=0 ;i<len;i++)
    cout<<arr[i]<<"  ";

}