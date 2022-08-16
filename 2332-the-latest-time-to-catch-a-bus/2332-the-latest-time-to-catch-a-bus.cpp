class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int c) {
        sort(b.begin(), b.end());
        sort(p.begin(), p.end());
        int j = 0, ans = p[0]-1;
        if(b[b.size()-1]<p[0]) return b[b.size()-1];
        for(int i=0; i<b.size(); ++i) {
            int count = 1;
            while(j<p.size() && p[j]<=b[i] && count<=c) {
                if(j!=0 && p[j]-p[j-1]!=1) ans = p[j]-1;
                j++;
                count++;
            }
            if(j!=0 && p[j-1]!=b[i] && count<=c) ans = b[i];
        }
     return ans;
    }
};