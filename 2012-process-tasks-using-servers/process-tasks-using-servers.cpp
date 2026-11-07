class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq,qp;
        for(int i=0;i<servers.size();i++){
            pq.push({servers[i],i});
        }
        vector<int>ans;
        int t=0;
        for(int i=0;i<tasks.size();i++){
            t=max(t,i);
            while(qp.size() and qp.top().first==t){
                    pq.push({servers[qp.top().second],qp.top().second});
                    qp.pop();
                }
            if(pq.size()){
                auto [x,y]=pq.top();pq.pop();
                ans.push_back(y);
                qp.push({t+tasks[i],y});
            }
            else{
                auto [x,y]=qp.top();
                t=x;
                while(qp.size() and qp.top().first==t){
                    pq.push({servers[qp.top().second],qp.top().second});
                    qp.pop();
                }
                auto [aa,bb]=pq.top();pq.pop();
                ans.push_back(bb);
                qp.push({1ll*t+tasks[i],1ll*    bb});
            }
        }
        return ans;
    }
};