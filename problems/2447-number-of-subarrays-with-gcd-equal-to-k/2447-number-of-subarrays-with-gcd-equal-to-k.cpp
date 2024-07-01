class Solution {
public:
int hcf(int a,int b){
    if(a<b) swap(a,b);
    if(a%b==0) return b;
    return hcf(b,a%b);
}
    int subarrayGCD(vector<int>& nums, int k) {
        int x=0,gcd,n=nums.size();
        for(int i=0;i<n;i++){
            gcd=nums[i];
            if(gcd==k) x++;
            for(int j=i+1;j<n;j++){
                gcd=__gcd(gcd,nums[j]);
                if(gcd==k){
                // cout<<i<<"  "<<j<<"  "<<gcd<<endl;
                x++;
                }
            }
        }
        return x;
    }
};