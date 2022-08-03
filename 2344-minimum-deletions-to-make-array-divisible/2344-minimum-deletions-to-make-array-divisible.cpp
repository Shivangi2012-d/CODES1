class Solution {
public:
   int hcf(int n1, int n2){
       
       if(n2!=0)
           return hcf(n2, n1 % n2);
       else
           return n1;
       
       
   }
    
    
    int minOperations(vector<int>& A, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for (int a: numsDivide)
            g = gcd(g, a);
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size() && A[i] <= g; ++i)
            if (g % A[i] == 0)
                return i;
        return -1;
    }
};