class Solution {
public:
int singleNonDuplicate(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
            
                while (lo < hi) {
                        int mid = lo + (hi - lo) / 2;
                                
                                        if (mid % 2 == 1) {
                                                    mid--;  // ensure mid is always on an even index
                                                            }
                                                                    
                                                                            if (nums[mid] != nums[mid + 1]) {
                                                                                        hi = mid;  // non-duplicate is on the left side
                                                                                                } else {
                                                                                                            lo = mid + 2;  // non-duplicate is on the right side
                                                                                                                    }
                                                                                                                        }
                                                                                                                            
                                                                                                                                return nums[lo];
                                                                                                                                }
                                                                                                                                

        
    
};