class Solution {
public:
//     int f(int ind1,int ind2,string text1,string text2,vector<vector<int>> &dp){
//         if(ind1 < 0 || ind2 < 0)
//             return 0;
        
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
//         if(text1[ind1] == text2[ind2])
//             return dp[ind1][ind2] = 1+f(ind1-1,ind2-1,text1,text2,dp);
//         else
//              return dp[ind1][ind2] = 0 + max(f(ind1,ind2-1,text1,text2,dp),f(ind1-1,ind2,text1,text2,dp));
//         }  // memoization will give tle 
    
int longestCommonSubsequence(string s1, string s2) {
       //  int n1 = text1.size();
       //  int n2 = text2.size();
       // vector<vector<int>>dp(n1,vector<int>(n2,-1));
       //  return f(n1-1,n2-1,text1,text2,dp);
        
        
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // for(int i=0;i<=n;i++){
    //     dp[i][0] = 0;
    // }
    // for(int i=0;i<=m;i++){
    //     dp[0][i] = 0;
    // }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1]) //ind-1 means ind
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    
    return dp[n][m];
}
};