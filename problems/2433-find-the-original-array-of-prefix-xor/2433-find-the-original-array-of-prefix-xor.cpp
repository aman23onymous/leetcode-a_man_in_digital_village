class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x=0;
        for(int i=1;i<pref.size();i+=1){
            x=x^pref[i-1];
            pref[i]=pref[i]^x;
        }
        return pref;
    }
};