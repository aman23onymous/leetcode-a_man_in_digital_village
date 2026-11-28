class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int mW) {
        int j=0;
        vector<string> vw;
        while(j<words.size()){
            int i=j,k=0;
            string w="";
            while(i<words.size()){
                if(k+words[i].size()+i-j-1<mW) k+=words[i].size();
                else break;
                i++;
            }
            cout<<k<<" "<<j<<" "<<i<<"\n";
            w+=words[j];
            if(i==j+1){
                while(w.size()<mW) w.push_back(' ');
                vw.push_back(w);
                j=i;
                continue;
            }
            if(i==words.size()){
                w.push_back(' ');
                j++;
                while(j<i){
                    w+=words[j];
                    if(w.size()<mW)w.push_back(' ');
                    j++;
                }
                while(w.size()<mW) w.push_back(' ');
                vw.push_back(w);
                break;
            }
            int spl=mW-k;
            int sl=i-j-1;
            int bb=spl/sl,cc=spl%sl;
            while(cc--){
                for(int x=0;x<=bb;x++) w.push_back(' ');
                j++;
                w+=words[j];
                sl--;
            }
            while(sl--){
                for(int x=0;x<bb;x++) w.push_back(' ');
                j++;
                w+=words[j];
                // sl--;
            }
            vw.push_back(w);
            j=i;
        }
        return vw;
    }
};