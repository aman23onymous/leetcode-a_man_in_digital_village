class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0,n=arr.size();
        for(int i=1;i<=n;i+=2){
            for(int j=0;j<=n-i;j++){
                vector<int> v(i);
                for(int k=0;k<i;k++){
                    v[k]=arr[j+k];
                }
                for(int k=0;k<i;k++){
                    sum+=v[k];
                }
            }
        }
        return sum;
    }
};