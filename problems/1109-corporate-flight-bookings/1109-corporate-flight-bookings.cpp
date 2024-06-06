class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& book, int n) {
        vector<int> v(n+1,0);
        for(int i=0;i<book.size();i+=1){
            v[book[i][0]-1]+=book[i][2];
            v[book[i][1]]-=book[i][2];
        }
        for(int i=1;i<=n;i++){
            v[i]+=v[i-1];
        }
        v.pop_back();
        return v;
    }
};