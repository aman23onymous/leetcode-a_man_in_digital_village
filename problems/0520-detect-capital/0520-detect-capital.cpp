class Solution {
public:
    bool detectCapitalUse(string word) {
        int i=0;
        if(word[i]>64&&word[i]<91){
            i++;
            if(word[i]>64&&word[i]<91){
                i++;
                while(word[i]!='\0'){
                    if(word[i]<=64||word[i]>=91) return false;
                    i++;
                }
            }
            else{
                while(word[i]!='\0'){
                    if(word[i]>64&&word[i]<91) return false;
                    i++;
                }
            }
        }
        else{
            while(word[i]!='\0'){
                    if(word[i]>64&&word[i]<91) return false;
                    i++;
                }
        }
        return true;
    }
};