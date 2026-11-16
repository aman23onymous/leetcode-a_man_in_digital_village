class Solution {
public:
    string minimizeStringValue(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        map<char,int>mp;
        for(auto x:s)mp[x]++;
        for(char x='a';x<='z';x++) pq.push({mp[x],x});
        vector<int>vv;
        string ss="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                auto x=pq.top();pq.pop();
                pq.push({x.first+1,x.second});
                s[i]=x.second;
                vv.push_back(i);
                ss.push_back(s[i]);
            }
        }
        sort(begin(ss),end(ss));
        sort(begin(vv),end(vv));
        for(int i=0;i<ss.size();i++) s[vv[i]]=ss[i];
        return s;
    }
};