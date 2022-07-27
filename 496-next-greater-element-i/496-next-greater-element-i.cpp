class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<findNums.size(); i++){
            int idx = -1, num = -1; // if next greater not found -> -1
            // find current number's index
            for(int j=0; j<nums.size(); j++){
                if( findNums[i] == nums[j] ){
                    idx = j;
                    break;
                }
            }
            // find next greater element
            for(int j=idx; j<nums.size(); j++){
                if( findNums[i] < nums[j] ){
                    num = nums[j];
                    break;
                }
            } res.push_back( num );
        } return res;
    }
};