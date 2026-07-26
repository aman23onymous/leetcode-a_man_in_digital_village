class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();

        vector<int> sa,sb,a,b;
        for(int i=0;i<n/2;i++){
            a.push_back(nums[i]);
        }
        for(int i=n/2;i<n;i++){
            b.push_back(nums[i]);
        }
        for(int i=0;i<(1<<(a.size()));i++){
            int s=0;
            for(int j=0;j<a.size();j++){
                if(i&(1<<j)){
                    s+=a[j];
                }
            }
            sa.push_back(s);
        }
        for(int i=0;i<(1<<(b.size()));i++){
            int s=0;
            for(int j=0;j<b.size();j++){
                if(i&(1<<j)){
                    s+=b[j];
                }
            }
            sb.push_back(s);
        }
        int mx=1000000000;
        sort(begin(sa),end(sa));
        sort(begin(sb),end(sb));
        for(int i=0;i<sa.size();i++){
            int l=0,r=sb.size()-1;
            while(l<=r){
                int m=(l+r)/2;
                mx=min(mx,1*abs(goal-sa[i]-sb[m]));
                if(sb[m]+sa[i]<goal) l=m+1;
                else r=m-1;
            }
            mx=min(mx,1*abs(goal-sa[i]));
        }
        for(int i=0;i<sb.size();i++){
            int l=0,r=sa.size()-1;
            while(l<=r){
                int m=(l+r)/2;
                mx=min(mx,1*abs(goal-sa[m]-sb[i]));
                if(sb[i]+sa[m]<goal) l=m+1;
                else r=m-1;
            }
            mx=min(mx,1*abs(goal-sb[i]));
        }
        return mx;
    }
};