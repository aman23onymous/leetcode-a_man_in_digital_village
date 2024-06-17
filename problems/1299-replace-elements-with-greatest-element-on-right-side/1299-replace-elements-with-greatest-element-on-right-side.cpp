class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> r(arr.size(),-1);
        for(int i=arr.size()-1;i>0;i--){
            r[i-1]=max(r[i],arr[i]);
        }
        return r;
    }
};