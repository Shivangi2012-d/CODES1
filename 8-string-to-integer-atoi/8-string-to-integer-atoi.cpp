class Solution {
public:
    int myAtoi(string s) {
        stringstream ss(s);
        string num;
        while(ss>>num)
        {   if(num[0]!='+'&& num[0]!='-' && !isdigit(num[0]))return 0;
            bool hasExtraChar=(num[0]=='+'||num[0]=='-')?1:0;
            bool neg = num[0]=='-'?1:0;
            long long int val =0;
            for(int i = hasExtraChar; i<num.size();i++)
            {   if(!isdigit(num[i]))return neg?max(-val,1LL*INT_MIN):min(val,1LL*INT_MAX);
                if(val > INT_MAX/10)return neg?INT_MIN:INT_MAX;
                val*=10;
                val+=num[i]-'0';
            }
            return neg?max(-val,1LL*INT_MIN):min(val,1LL*INT_MAX);
        }
        return 0; 
    }
};