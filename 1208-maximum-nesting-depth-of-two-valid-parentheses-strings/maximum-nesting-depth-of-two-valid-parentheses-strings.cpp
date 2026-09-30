class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int> ans(n),an(n);
        int s=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='(') ans[i]=(++s);
            else ans[i]=s--;
        }
        for(int i=0;i<n;i++){
            if(ans[i]%2) an[i]=0;
            else an[i]=1;
        }
        return an;
    }
};