class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
        Note:
        Each of the array element will not exceed 100.
        The array size will not exceed 200.
        
        we want to check if we can make up sum/2 by some elements,
        so we don't care anything > sum/2,
        and by the Note above,
        we can inspect that the max possible sum/2 is 100*200/2 = 10000,
        since we still need place for sum equal to 0(the least significant bit),
        so totally we need 10001 bits
        
        we initialize bits as 1,
        this is saying that we can choose 0 elements to make up 0(x)
        this is just for convenience, so that we can use bits |= bits << n;
        */
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        /*
        initially, we can make up 0
        1st iter: "bits" is set in 0th and nums[0]th bit
        2nd iter: "bits" is set in 0, nums[0], nums[1] and nums[0]+nums[1]th bit
        ...
        */
        for (auto n : nums) bits |= bits << n;
        /*
        need to check if the sum is even first!
        bits[sum >> 1]: whether we can make up sum/2 by nums's subset
        */
        return !(sum & 1) && bits[sum >> 1];
    }
};