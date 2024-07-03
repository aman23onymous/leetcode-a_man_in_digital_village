class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        for(int i=0;i<score.size()-1;i++){
            bool f=1;
            for(int j=0;j<score.size()-i-1;j++){
                if(score[j][k]<score[j+1][k]){
                    f=0;
                    for(int x=0;x<score[0].size();x++) swap(score[j][x],score[j+1][x]);
                }
            }
            if(f) break;
        }
        return score;
    }
};