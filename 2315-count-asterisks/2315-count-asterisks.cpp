class Solution {
public:
    int countAsterisks(string s) {
    int c=0;
    int star=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='|'){
            c++;
        }
    
        if(c%2==0){
            
        if(s[i]=='*'){
            star++;
        }
    }
   }
   return star;
}
};