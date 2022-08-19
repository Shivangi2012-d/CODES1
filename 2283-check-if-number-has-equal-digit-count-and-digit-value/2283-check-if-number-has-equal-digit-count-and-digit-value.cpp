class Solution {
public:
    bool digitCount(const string& num) {
        int cnt[10]{0};
        for(auto i:num) ++cnt[i-'0'];
        for(int i=0; i<num.size(); ++i)
            if(num[i]-'0'!=cnt[i]) return false;
        return true;
    }
};