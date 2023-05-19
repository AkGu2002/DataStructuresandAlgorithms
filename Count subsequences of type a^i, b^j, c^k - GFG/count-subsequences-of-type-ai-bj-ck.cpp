//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    const int M = 1e9+7;
    int fun(string &s) {
        //code here
        int n = s.length();
        int a =0, ab=0, abc= 0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a = (2*a%M + 1)%M;
                
            }
            else if(s[i]=='b'){
                ab = (2*ab%M + a)%M;
                
            }
            else {
                abc = (2*abc%M + ab)%M;
            }
            
        }
        
        return abc%M;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends