class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> an;
        for(int i=0;i<nums.size();i++){
            an.push_back({nums[i],i});
        }
        sort(begin(an),end(an));
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            vector<int> ps;
            ps.push_back(an[i].second);
            while(j<nums.size() and an[j].first-an[j-1].first<=limit){
                ps.push_back(an[j].second);
                j++;
            }
            sort(begin(ps),end(ps));
            for(int k=i;k<j;k++){
                nums[ps[k-i]]=an[k].first;
            }
            i=j-1;
        }
        return nums;
    }
};