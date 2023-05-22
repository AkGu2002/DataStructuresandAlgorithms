//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    //maintain the last occurence
    
     int st =0;
     //int en = 0;
     int mini = -1;
     unordered_map<char,int> ump;
     
     for(int i=0;i<s.length();i++){
         ump[s[i]]++;
         
         if(ump.size()==k){
             mini = max(i - st + 1, mini);
         }
         else if(ump.size()==k+1){
             
             while(ump.size()>k){
                 ump[s[st]]--;
                 if(ump[s[st]]==0) ump.erase(s[st]);
                 st++;
             }
              mini = max(i - st + 1, mini);
             
                 
             }
         }
     
     return mini;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends