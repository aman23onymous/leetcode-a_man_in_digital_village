class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0;
        while(i<words.size()){
            int j=i,s=0;
            vector<string> v;
            string ansi="";
            while(j<words.size()){
                if(s+words[j].size()+j-i>maxWidth){
                    break;
                }
                v.push_back(words[j]);
                s+=words[j].size();
                j++;
            }
            cout<<i<<" "<<j<<"\n";
            if(j<words.size()){
                int spl=maxWidth-s;
                int spc=j-i-1;
                for(int k=0;k<spc;k++){
                    ansi+=(words[i+k]);
                    int l=spl/spc+(k<(spl%spc));
                    while(l--) ansi.push_back(' ');
                }
                ansi+=(words[i+spc]);
                while(ansi.size()<maxWidth) ansi.push_back(' ');
            }
            else{
                for(int k=i;k<j;k++){
                    ansi+=words[k];
                    if(k!=j-1)ansi.push_back(' ');
                }
                while(ansi.size()<maxWidth) ansi.push_back(' ');
            }
            i=j;
            ans.push_back(ansi);
        }
        return ans;
    }
};