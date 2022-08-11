class Solution {
public:
    string decodeMessage(string key, string message) {
        // unordered_set<pair<char,char>>sk;
        string sk;
        string s;
        vector<pair<char,char>>set1;
        string result;
        string p="abcdefghijklmnopqrstuvwxyz";
        for(auto i:key){
        if(isalpha(i)){
            s+=i;
        }
        }
        for(auto i:s){
            if(sk.find(i)==string::npos){
            sk.push_back(i);
            }
        }
            for(int i=0;i<sk.length();i++){
                for(int j=i;j<p.length();j++){
                    set1.push_back({sk[i],p[j]});
                    break;
                }
            }

            for(int i=0;i<message.length();i++){
                for(int j=0;j<set1.size();j++){
                if(message[i] == set1[j].first){
                    result+=set1[j].second;
                }   
                }
                if(!isalpha(message[i])&& !isdigit(message[i])){
                    result+=" ";
                }
                
                
            }
 
    return result;
    }

};