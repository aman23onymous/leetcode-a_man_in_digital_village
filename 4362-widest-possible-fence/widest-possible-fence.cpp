class Solution {
public:
    int maximumWidth(vector<int>& pln) {
        map<int,int>mp,mp2;
        for(int x:pln){
            mp[x]++;
            mp2[x]++;
        }
        vector<pair<int,int>> vmp;
        for(auto x:mp) vmp.push_back(x);
        for(int i=0;i<vmp.size();i++){
            for(int j=i;j<vmp.size();j++){
                if((vmp[i].first==vmp[j].first)){
                    mp2[vmp[i].first*2]+=(vmp[i].second/2);
                }
                else{
                    mp2[vmp[i].first+vmp[j].first]+=min(vmp[i].second,vmp[j].second);
                }
            }
        }
        int mx=1;
        for(auto x:mp2){
            mx=max(mx,x.second);
        }
        return mx;
    }
};