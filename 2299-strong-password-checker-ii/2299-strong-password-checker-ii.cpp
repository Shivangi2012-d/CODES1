class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size()<8) return false;
        
        for(int i=0;i<password.size()-1;i++){
            if(password[i]==password[i+1]){
                return false;
            }
        }
        
        int digit=0,special=0,lower=0,upper=0;
        
        for(int i=0;i<password.size();i++){
            if(isdigit(password[i])){
                digit=1;
            }
            else if(!isalpha(password[i])){
                special=1;
            }
            else{
                if(islower(password[i])){
                    lower=1;
                }
                else{
                    upper=1;
                }
            }
        }
        if(!digit || !special || !lower || !upper){
            return false;
        }
        return true;
    }
};