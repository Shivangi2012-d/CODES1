class Solution {
public:
    int distinctSequences(int n) {

        map<int, vector<int>> mp;
        mp.insert({1, {2, 3, 4, 5, 6}});
        mp.insert({2, {1, 3, 5}});
        mp.insert({3, {1, 2, 4, 5}});
        mp.insert({4, {1, 3, 5}});
        mp.insert({5, {1, 2, 3, 4, 6}});
        mp.insert({6, {1, 5}});

        long long dp[n][7][7];
        memset(dp, 0, sizeof(dp));
        long long mod = 1e9+7;

		// initialization for n=1 (one dice roll)
        for (int i = 1; i <= 6; ++i) {
            dp[0][i][0] = 1;
            dp[0][0][0] += dp[0][i][0];
        }

        for (int k = 1; k < n; ++k) {
            for (int i = 1; i <= 6; ++i) {
				// update rule
                for (int j : mp[i]) {
                    dp[k][i][j] = (dp[k - 1][j][0] - dp[k - 1][j][i]) % mod;
                }
				// summation for position `n-1`
                for (int j : mp[i]) {
                    dp[k][i][0] = (dp[k][i][0] + dp[k][i][j]) % mod;
                }
            }
			// summation for position `n`
            for (int i = 1; i <= 6; ++i) {
                dp[k][0][0] = (dp[k][0][0] + dp[k][i][0]) % mod;
            }
        }

		// for some reasons the modulo results might be negative (maybe due to the subtraction in the update rule), so
		// add mod first then do modulo would solve the problem
        return (dp[n-1][0][0] + mod) % mod;
    }
};