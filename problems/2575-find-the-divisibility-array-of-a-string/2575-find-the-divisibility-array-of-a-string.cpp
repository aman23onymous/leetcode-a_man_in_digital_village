class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long t=0,i=0;
        vector<int> d(word.size());
        while(i<word.size()){
            t=(10*t)%m+(word[i]-48);
            if(t%m){
                d[i]=0;
            }
            else{
                d[i]=1;
                t=0;
            }
            i++;
        }
        return d;
    }
};