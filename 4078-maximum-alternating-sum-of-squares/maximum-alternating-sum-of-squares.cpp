class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int x:nums) pq.push(x*x);
        int n=pq.size()/2;
        while(n--){
            ans-=pq.top();pq.pop();
        }
        while(pq.size()){
            ans+=pq.top();pq.pop();
        }
        return ans;
    }
};