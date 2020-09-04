#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void insertion(int arr[],int n){
    int key=0,j=0;
    for(int i =1;i<n;i++){
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;

        }
        arr[j+1]=key;
    }

}


int main(){


    int arr[]={2,1,6,5,7,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion(arr,n);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    }
