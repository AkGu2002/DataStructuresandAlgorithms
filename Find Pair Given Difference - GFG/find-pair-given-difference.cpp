//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool binarySearch(int arr[], int to_find, int ind, int size){
    int i=0, j= size - 1;
    while(i<=j){
        int mid = (i+j)/2;
        if(arr[mid]==to_find && mid!=ind) return true;
        if(to_find < arr[mid]) j = mid-1;
        else i = mid + 1;
    }
    return false;
}
bool findPair(int arr[], int size, int n){
    //code
    sort(arr, arr+size);
    
    int maxi = arr[size-1];
    
    for(int i=0;i<size;i++){
        int to_find = n + arr[i];
        if(to_find > maxi) return false;
        if(binarySearch(arr, to_find,i, size)) return true;
        
    }
    
    return false;
    
    
}