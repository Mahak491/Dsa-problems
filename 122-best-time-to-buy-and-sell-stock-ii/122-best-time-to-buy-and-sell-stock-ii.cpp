class Solution {
public: //memoization
    /* int f(int ind,int buy,int n,vector<int> &prices,vector<vector<int>> &dp){
       if(ind == n)
           return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];
        
        if(buy == 1)
            return dp[ind][buy] = max(-prices[ind] + f(ind+1,0,n,prices,dp),0+f(ind+1,1,n,prices,dp));
        else
            return dp[ind][buy] = max(prices[ind] + f(ind+1,1,n,prices,dp),0 + f(ind+1,0,n,prices,dp));
    }*/
    
    int maxProfit(vector<int>& prices) {
     /*   int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,n,prices,dp);*/
        
        // tabulation
    /* int n = prices.size();
     vector<vector<int>>dp(n+1,vector<int>(2,0));
     dp[n][0] = dp[n][1] = 0;
     
     for(int ind=n-1;ind>=0;ind--)
     {
         for(int buy=0;buy<=1;buy++)
         {
          int profit = 0;
          if(buy)
          profit = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
          else
          profit = max(prices[ind]+dp[ind+1][1],dp[ind+1][0]); 
          dp[ind][buy]=profit; 
         }
     }
     return dp[0][1];
    }*/
    
    //better solution
       /* int n = prices.size();
        vector<int> ahead(2,0),cur(2,0);
        ahead[0] = ahead[1] = 0;
        for(int ind=n-1;ind>=0;ind--)
        {
         for(int buy=0;buy<=1;buy++)
         {
          int profit = 0;
          if(buy)
          profit = max(-prices[ind]+ahead[0],ahead[1]);
          else
          profit = max(prices[ind]+ahead[1],ahead[0]); 
          cur[buy]=profit; 
         }
            ahead = cur;
     }
        return ahead[1];
    } */
        
        // optimal solution
        int maxprofit = 0;
        for(int i=1;i<prices.size();i++){
            maxprofit+=max(prices[i]-prices[i-1],0);
        }
        return maxprofit;
    }
};
