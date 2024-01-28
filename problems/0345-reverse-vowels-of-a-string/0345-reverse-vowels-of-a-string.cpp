class Solution {
public:
    string reverseVowels(string s) {
        vector <char> p;
        int i=0;
        while(s[i]!='\0'){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                p.push_back(s[i]);
            }
            i++;
        }
        //reverse(p.begin(),p.end());
        int j=p.size()-1;
        i=0;
        while(s[i]!='\0'){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                s[i]=p[j];
                j--;
            }
            i++;
        }
        return s;
    }
};