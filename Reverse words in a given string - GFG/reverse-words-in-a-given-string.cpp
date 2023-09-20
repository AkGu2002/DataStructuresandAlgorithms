//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string temp = S;
        reverse(S.begin(), S.end());
        stack<char> st;
        string ans ="";
        
        for(int i=0;i<S.length();i++){
            if(S[i]=='.'){
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                ans+='.';
            }
            else{
                st.push(S[i]);
            }
        }
        while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends