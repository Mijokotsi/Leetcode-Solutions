class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        // defining a vector matrix that will hold our glasses
        vector<vector<double>> dp(101, vector<double> (101, 0));
        
        // All glasses are poured at once on the first glass hence 
        // dp[0][0] = poured
        dp[0][0] = poured;
        
        // Running the loop
        for(int i = 0; i < 100; i++)
            for(int j = 0; j <= i; j++)
                
                if(dp[i][j] > 1) {
                    
                    double remaining = (dp[i][j] - 1);
                    dp[i + 1][j] += remaining/2;
                    dp[i + 1][j + 1] += remaining / 2;
                    dp[i][j] = 1;
                }
    
        return dp[query_row][query_glass];
    }
};