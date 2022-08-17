class Solution {
public:
    int mod = 1000000007;
    int base = 6;
    // freqs[i] is the number of numbers that have prime factorizartion encoding i 
    unordered_map<long long, int> freqs;
    // decodings[i] is S_i. Definition of S is given in observation 2 from above
    unordered_map<long long, vector<int> > decodings;
    // dp[i][j] is the number of strictly increasing ideal array of length i
    // that ends with a number of prime factorizartion encoding j
    vector<unordered_map<long long, int> > dp;
    int maxValue;
    int n;
    
    int modPow(int p, int k) {
        if (k == 0) {
            return 1;
        }
        if (k == 1) {
            return p;
        }
        if (k % 2 == 0) {
            return modPow((long long) p * p % mod, k / 2);
        }
        return (long long) p * modPow(p, k - 1) % mod;
    }
    
    long long pow(long long p, long long k) {
        if (k == 0) {
            return 1;
        }
        if (k == 1) {
            return p;
        }
        if (k % 2 == 0) {
            return pow((long long) p * p, k / 2);
        }
        return (long long) p * pow(p, k - 1);
    }
    
    int choose(int n, int m) {
        if (m * 2 > n) {
            m = n - m;
        }
        long long top = 1;
        long long bot = 1;
        for (int i = n; i > n - m; i--) {
            top *= i;
            top %= mod;
        }
        for (int i = 1; i <= m; i++) {
            bot *= i;
            bot %= mod;
        }
        
        long long inverse = modPow(bot, mod - 2);
        return top * inverse % mod;
    }
    
    void sieve() {
        vector<vector<int> > factorizations(maxValue + 1);
        // Let the prime factorization of i be (p1)^(k1)*(p2)^(k2)*...*(pn)^(kn)
        // factorizations[i] is the list [k1, k2, ..., kn], the list of exponents
        for (int i = 2; i <= maxValue; i++) {
            if (factorizations[i].empty()) {
                int p = i;
                for (int j = i; j <= maxValue; j += i) {
                    factorizations[j].push_back(0);
                }
                while (p <= maxValue) {
                    for (int j = p; j <= maxValue; j += p) {
                        factorizations[j].back()++;
                    }
                    p *= i;
                }
            }
        }
        freqs.emplace(0, 1);
        decodings.emplace(0, vector<int>());
        for (int i = 2; i <= maxValue; i++) {
            int encoding = 0;
            // Encode factorizations[i] into a long long
            // First we convert factorizations[i] into an unordered map
            // where map[i] is the frequency of exponent i
            // For example, if factorizations[i] is [2, 1, 1]
            // 2 occurs once so map[2] = 1
            // 1 occurs twice so map[1] = 2
            
            // With the map, we can encode it into base 6
            // The reason we use base 6 is that the biggest product from increasing prime
            // less than 10000 is 2*3*5*7*11. Therefore the value of any key is at most 5
            for (int e : factorizations[i]) {
                encoding += pow(base, e);
            }
            if (decodings.find(encoding) == decodings.end()) {
                decodings.emplace(encoding, move(factorizations[i]));
            }
            freqs[encoding]++;
        }
    }
    
    int BFS(vector<int>& original, long long oldEncoding, int len, int index,
            long long acc) {
        if (oldEncoding == acc) {
            return 0;
        }
        if (index == original.size()) {
            return S(len - 1, acc);
        }
        int res = 0;
        for (int i = 0; i <= original[index]; i++) {
            int delta = i == 0 ? 0 : pow(base, i);
            res += BFS(original, oldEncoding, len, index + 1, acc + delta);
            res %= mod;
        }
        return res;
    }
    
    /**
     * Compute the number of strictly increasing ideal arrays with
     * length @param[len] and prime factor exponent encoding @param[encoding]
     */
    int S(int len, long long encoding) {
        if (dp[len].find(encoding) != dp[len].end()) {
            return dp[len][encoding];
        }
        if (len == 1) {
            dp[len].emplace(encoding, 1);
            return 1;
        }
        if (encoding == 0) {
            return 0;
        }
        int res = BFS(decodings[encoding], encoding, len, 0, 0);
        dp[len].emplace(encoding, res);
        return res;
    }
    
    int idealArrays(int n, int maxValue) {
        this -> maxValue = maxValue;
        this -> n = n;
        sieve();
        for (auto& p : decodings) {
            // For any strictly increasing ideal array ending with a number
            // of prime factorization encoding [p.first]
            // its length is at most 1 + the sum of the prime exponents
            // For example, 12 = 2^2 * 3^1. Suppose we construct the ideal array from
            // left to right. Each time we append a new number, it must be some prime factor
            // times the last numnber. We only have (2 + 1) prime factors so we can almost
            // append (2 + 1) times and the length is at most 1 + (2 + 1) = 4
            int maxLen = 1 + accumulate(p.second.begin(), p.second.end(), 0);
            maxLen = min(maxLen, n);
            if (maxLen >= dp.size()) {
                dp.resize(maxLen + 1);
            }
            for (int i = 1; i <= maxLen; i++) {
                S(i, p.first);
            }
        }
        int res = 0;
        vector<int> sums(dp.size());
        for (int i = 1; i < dp.size(); i++) {
            for (auto& p : dp[i]) {
                sums[i] += (long long) p.second * freqs[p.first] % mod;
            }
        }
        for (int i = 1; i < sums.size(); i++) {
            res += (long long) sums[i] * choose(n - 1, i - 1) % mod;
            res %= mod;
        }
        return res;
    }
};