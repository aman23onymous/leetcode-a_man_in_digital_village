class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<vector<int>> srt(nums.size(),vector<int>(2));
        for(int i=0;i<nums.size();i++){
            srt[i][0]=nums[i];
            srt[i][1]=i;
        }
        sort(srt.begin(),srt.end());
        int i=0;
        while(i<nums.size()-1){
            // cout<<i<<"\n";
            int j=i;
            while(j<nums.size()-1 and srt[j+1][0]-srt[j][0]<=limit) j++;
            // cout<<i<<" "<<j<<"\n";
            vector<int> l;
            for(int k=i;k<=j;k++) l.push_back(srt[k][1]);
            sort(l.begin(),l.end());
            for(int u:l) nums[u]=srt[i++][0];
            // for(int o=0;o<nums.size();o++) cout<<nums[o]<<" ";
            // cout<<"\n";
            i=j+1;
        }
        return nums;
    }
};