#include <iostream> 
using namespace std; 
  
// Function to calculate the sum of product 
int calcSOP(int arr[], int n, int k) 
{ 
    // Initialize sum = 0 
    int sum = 0; 
  
    // Consider every subarray of size k
    for(int z=1;z<k+1;z++){


    
    for (int i = 0; i <= n - z; i++) { 
        int prod = 1; 
         
        // Calculate product of all elements 
        // of current subarray 
        for (int j = i; j < z + i; j++)
            { 
            prod *= arr[j]; 
            }
        // Store sum of all the products 
        sum += prod; 
    } 
    }
    // Return sum 
    return sum; 
} 
  
// Driver code 
int main() 
{ 
    int n;  
    int k ,m;

    cin>>n>>k>>m;
    int arr[n];
    for(int i =0;i<n;i++) 
        arr[i]=i+1;
    // for(int i =0;i<n;i++) 
    //     cout<<" "<<arr[i];

    int sum=calcSOP(arr, n, k); 
    cout<<sum%m;
    return 0; 
} 
