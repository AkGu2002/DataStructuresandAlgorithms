#include<bits/stdc++.h>
using namespace std;
 int longestIdealString(string s, int k) {
        int DP[26] = {0}, ans = 1;    //min ans can be 1 as there can be a single character too
        
        for (char &ch: s) {
            int i = ch - 'a';
            DP[i] = DP[i] + 1;
            
            for (int j = max(0, i - k); j <= min(25, i + k); j++)
                if (j != i)
                    DP[i] = max(DP[i], DP[j] + 1);
            
            ans = max(ans, DP[i]);
        }
        
        return ans;
    }

int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    return longestIdealString(s,k);

}