class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>>pq;
        map<int,int>mp,ma;
        for(int i=0;i<items.size();i++){
            mp[items[i][0]]++;   
        }
        for(auto [x,z]:mp){
            for(int y=x;y<=(*mp.rbegin()).first;y+=x) ma[x]+=mp[y];
        }
        for(auto [x,y]:ma){
            cout<<x<<" "<<y-1<<"\n";
        }
        for(int i=0;i<items.size();i++){
            if(ma[items[i][0]]>1){
                pq.push({1.0*items[i][1]/2,ma[items[i][0]]-1});
            }
            else{
                pq.push({1.0*items[i][1],0});
            }
        }
        int ans=0;
        while(budget>0){
            auto x=pq.top();pq.pop();
            if(x.second==0){
                if(budget<x.first) break;
                ans+=(budget/x.first);
                budget%=(int)x.first;
            }
            else {
                if(budget<2*x.first){
                    pq.push({2*x.first,0});
                    continue;
                }
                else{
                    int mn=min(x.second,(int)(budget/(2*x.first)));
                    budget-=mn*(2*x.first);
                    ans+=mn*2;
                    pq.push({2*x.first,0});
                }
            }
            cout<<ans<<" "<<budget<<"\n";
        }
        return ans;
        
    }
};