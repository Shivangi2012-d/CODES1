class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        
        
        
        
      int l1 = nums1.size();
        int l2 = nums2.size();
        int total_size = l1+l2;
        bool isEven = !(total_size%2);
        
        int cIoN1 = 0, cIoN2 = 0;
        int last, current;
        for(int i = 0; i<=total_size/2; ++i)
        {
            last = current;
            if(cIoN1<l1 && cIoN2 <l2)
            {
                if(nums1[cIoN1]>nums2[cIoN2])
                {
                    current = nums2[cIoN2];
                    ++cIoN2;
                }
                else
                {
                    current = nums1[cIoN1];
                    ++cIoN1;
                }
            }
            else if(cIoN1<l1)
            {
                    current = nums1[cIoN1];
                    ++cIoN1;
            }
            else
            {
                    current = nums2[cIoN2];
                    ++cIoN2;
            }
        }
        if(isEven)
        {
            cout<<"worked"<<endl;
            return ((double(current)+last)/2);
        }
        return double(current);
    }
};