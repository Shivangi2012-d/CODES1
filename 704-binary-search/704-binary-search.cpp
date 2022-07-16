class Solution {
public:
    int search(vector<int>& nums, int x) 
    
{
        
        
        int l=0;
        int r=nums.size()-1;
        
        
        while(l<=r)
        {
         
            int mid = l + (r - l) / 2;
        
        
        if (nums[mid]==x)
        
            return mid;
            
        
        
           if (nums[mid] < x)
            l = mid + 1;
       
        else
            r = mid - 1;
        
    }
    
   return -1;
    }
};