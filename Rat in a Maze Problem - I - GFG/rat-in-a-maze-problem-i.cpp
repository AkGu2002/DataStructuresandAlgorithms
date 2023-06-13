//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int>> vis;
    void solve(int r, int c, int n, string &temp, vector<string> &res){
        if(r==n-1 && c==n-1){
            res.push_back(temp);
            return;
        }
        //travelling up
        if(r>0 && vis[r-1][c]==0){
            vis[r-1][c] = 1;
            temp+='U';
            solve(r-1,c,n,temp,res);
            vis[r-1][c]=0;
            temp.pop_back();
            
        }
        
        //travellig down
        if(r<n -1 && vis[r+1][c]==0){
            vis[r+1][c] = 1;
            temp+='D';
            solve(r+1,c,n,temp,res);
            vis[r+1][c]=0;
            temp.pop_back();
            
        }
        
        //travelling left
        if(c>0 && vis[r][c-1] ==0){
            vis[r][c-1] = 1;
            temp+='L';
            solve(r,c-1,n,temp,res);
            vis[r][c-1]=0;
            temp.pop_back();
        }
        
        //travelling right
        if(c<n-1 && vis[r][c+1]==0){
            vis[r][c+1] = 1;
            temp+='R';
            solve(r,c+1,n,temp,res);
            vis[r][c+1]=0;
            temp.pop_back();
        }
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vis.resize(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==0) vis[i][j]=1; 
            }
        }
        if(vis[0][0]) return {"-1"};
        vis[0][0] = 1;
        string temp="";
        vector<string> res;
        solve(0,0,n,temp,res);
        if(res.size()==0) return {"-1"};
        
        return res;
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends