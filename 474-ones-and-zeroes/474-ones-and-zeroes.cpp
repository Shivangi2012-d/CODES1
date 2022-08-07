class Solution {
public:
    // Zero, One
    pair<int, int> countCharacters(string s){
        int ones = 0, zeros = 0;
        for(char i : s){
            if(i == '1') ones++;
            else zeros++;
        }
        return {zeros, ones};
    }
    int memo[601][101][101];
    int rec(vector<string> &arr, int n, int zeros, int ones){
        if(n < 0 || (zeros == 0 && ones == 0)) return 0;
        
        if(memo[n][zeros][ones] != -1) return memo[n][zeros][ones];
        
        pair<int, int> zerosAndOnes = countCharacters(arr[n]);
        
        if(n == 0){   
            zeros -= zerosAndOnes.first;
            ones -= zerosAndOnes.second;
            
            if(zeros < 0 || ones < 0) return 0;
            
            return 1;
        }
        // Choice :  To pick or not
        if(zeros-zerosAndOnes.first >= 0 && ones-zerosAndOnes.second >= 0){
            return memo[n][zeros][ones] = max(
                1 + rec(arr, n-1, zeros-zerosAndOnes.first, ones-zerosAndOnes.second), 
                    rec(arr, n-1, zeros, ones));
        }
        
        return memo[n][zeros][ones] = rec(arr, n-1, zeros, ones);
    }
    int findMaxForm(vector<string>& strs, int zeros, int ones) {
        int n = strs.size();
        memset(memo, -1, sizeof(memo));
        return rec(strs, n-1, zeros, ones);
    }
};