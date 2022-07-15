class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     
        
    int maximum=0;
    int i=0;
    while(i<nums.size())
    {
        int conOnes=0;
        while(i< nums.size() && nums[i]==1)
        {
            conOnes++;
            i++;
        }
        maximum=max(maximum,conOnes);
        i++;
    }
    return maximum; 
        
        
    }
};