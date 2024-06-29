class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> o;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                o.push_back(i);
            }
        }
        for(int i=0,x=0;i<queries.size();i++){
            if(queries[i]>o.size()) queries[i]=-1;
            else{
                queries[i]=o[queries[i]-1];
            }
        }
        return queries;
    }
};