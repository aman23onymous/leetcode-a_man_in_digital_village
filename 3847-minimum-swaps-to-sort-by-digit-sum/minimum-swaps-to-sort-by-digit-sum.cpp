class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> v(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            v[i][0]=0;
            v[i][1]=i;
            v[i][2]=nums[i];
            int x=nums[i];
            while(x){
                v[i][0]+=(x%10);
                x/=10;
            }
        }
        sort(v.begin(),v.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[2]<b[2];
            return a[0]<b[0];
        });
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            int j=i,k=0;
            while(!vis[j]){
                vis[j]=1;
                j=v[j][1];
                k++;
            }
            ans+=(k-1);
        }
        return ans;
    }
};