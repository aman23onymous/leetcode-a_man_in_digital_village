class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> p;
        if(n%2==1){
            p.push_back(0);
            for(int i=1;i<=n/2;i++){
                p.push_back(-i);
                p.push_back(i);
            }
        }
        else{for(int i=1;i<=n/2;i++){
                p.push_back(-i);
                p.push_back(i);
            }}
        return p;
    }
};