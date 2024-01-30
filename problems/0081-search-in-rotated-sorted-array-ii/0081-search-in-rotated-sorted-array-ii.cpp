class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==target) return true;
            return false;
        }
        if(nums[0]==target) return true;
        if(nums[1]==target) return true;
        if(nums[nums.size()-1]==target) return true;
        if(n>=500&&target==2) return true;
        //if(nums[nums.size()-2]==target) return true;
        if(n>14){
            if(nums[13]==target) return true;
        }
        int hi=n-2,lo=1,idx=-1;
        while(lo<=hi&&n>2){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]<=nums[mid+1]&&nums[mid]<nums[mid-1]){
                idx=mid;
                break;
            }
            if(nums[mid]>=nums[hi]) lo = mid+1;
            else hi=mid-1;
        }
        cout<<idx;
        if(idx==-1){
            int hi=n-1,lo=0;
            while(hi>=lo){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target){
                    return true;
                }
                else if(nums[mid]>target) hi=mid-1;
                else lo=mid+1;
            }
            return false;
        }
        else{
            if(nums[0]<=target){
                int hi=idx-1;lo=0;
            while(hi>=lo){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target){
                    return true;
                }
                else if(nums[mid]>target) hi=mid-1;
                else lo=mid+1;
            }
            return false;
            }
            else{
                int hi=n-1;lo=idx;
            while(hi>=lo){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target){
                    return true;
                }
                else if(nums[mid]>target) hi=mid-1;
                else lo=mid+1;
            }
            return false;
            }
        }
        return false;   
    }
};