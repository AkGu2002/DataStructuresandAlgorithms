//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
int ans = 0;
int tot = 0;
int maxi = 0;

for(int i=0;i<N;i++){
    ans += i*A[i];
    tot += A[i];
}
//cout << ans << " ";
maxi = max(maxi, ans);
for(int i=N-1;i>=1;i--){
    
    ans -= A[i]*(N-1);
    ans += tot;
    ans -= A[i];
    maxi = max(ans, maxi);
    
}
return maxi;
}