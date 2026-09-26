class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mp;
        for(auto x:knowledge){
            mp[x[0]]=x[1];
        }
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i++;
                string key="";
                while(s[i]!=')'){
                    key.push_back(s[i]);
                    i++;
                }
                if(mp.count(key)){
                    for(auto x:mp[key]) res.push_back(x);
                }
                else res.push_back('?');
            }
            else res.push_back(s[i]);
        }
        return res;
    }
};