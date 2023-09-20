//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(string &s, int ind, set<string> &st, int n){
	        if(ind==n-1){
	            st.insert(s);
	            return;
	        }
	        
	        for(int j=ind;j<n;j++){
	            swap(s[ind], s[j]);
	            solve(s, ind+1, st, n);
	            swap(s[ind], s[j]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    int n = S.length();
		    set<string> st;
		    solve(S,0,st,n);
		    
		    for(auto it: st){
		        ans.emplace_back(it);
		    }
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends