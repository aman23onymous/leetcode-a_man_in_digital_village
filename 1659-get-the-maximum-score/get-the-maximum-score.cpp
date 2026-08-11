class Solution {
public:
    map<int,int> mp1,mp2;
    long long dp[100100][2],mod=1000000007;

    long long reti(vector<int>& nums1, vector<int>& nums2,int i,int k){
        if(i<0) return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        long long mx=0;

        if(k and mp1.count(nums2[i])){
            mx=max(mx,
                nums2[i] +
                reti(nums1,nums2,mp1[nums2[i]]-1,1-k)
            );
        }
        else if(k==0 and mp2.count(nums1[i])){
            mx=max(mx,
                nums1[i] +
                reti(nums1,nums2,mp2[nums1[i]]-1,1-k)
            );
        }

        if(k)
            mx=max(mx,
                nums2[i] +
                reti(nums1,nums2,i-1,k)
            );
        else
            mx=max(mx,
                nums1[i] +
                reti(nums1,nums2,i-1,k)
            );

        return dp[i][k]=mx;
    }

    int maxSum(vector<int>& nums1, vector<int>& nums2) {

        for(int i=0;i<nums1.size();i++)
            mp1[nums1[i]]=i;

        for(int i=0;i<nums2.size();i++)
            mp2[nums2[i]]=i;

        memset(dp,-1,sizeof(dp));

        long long dpi =
            reti(nums1,nums2,nums1.size()-1,0);

        memset(dp,-1,sizeof(dp));

        long long ans =
            max(dpi,
                reti(nums1,nums2,nums2.size()-1,1));

        return ans % mod;
    }
};