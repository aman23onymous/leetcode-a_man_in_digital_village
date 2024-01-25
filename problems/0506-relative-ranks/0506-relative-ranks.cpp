class Solution {
public:
    int find(vector<int>& score,int s){
        for(int i=0;i<score.size();i++){
            if(score[i]==s) return i;
        }
        return -1;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> k;
        vector<int> p;
        for(int i=0;i<score.size();i++){
            p.push_back(score[i]);
        }
        sort(p.begin(),p.end());
        for(int i=0;i<score.size();i++){
            if(score[i]==p[n-1]){
                k.push_back("Gold Medal");
            }
            else if(score[i]==p[n-2]){
                 k.push_back("Silver Medal");
            }
            else if(score[i]==p[n-3]){
                 k.push_back("Bronze Medal");
            }
            else{
                k.push_back(to_string(n-find(p,score[i])));
            }
        }
        return k;
    }
};