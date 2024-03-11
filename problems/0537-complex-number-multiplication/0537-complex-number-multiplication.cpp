class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a=num1.size(),b=num2.size(),i;
        string real="",comp="";
        for(i=0;;i++){
            if(num1[i]=='+') break;
            real=real+num1[i];
        }
        i++;
        while(num1[i]!='i'){
            comp+=num1[i];
            i++;
        }
        int a1=stoi(real),b1=stoi(comp);
        i=0;
        string re="",co="";
        for(i=0;;i++){
            if(num2[i]=='+') break;
            re=re+num2[i];
        }
        i++;
        while(num2[i]!='i'){
            co+=num2[i];
            i++;
        }
        int a2=stoi(re),b2=stoi(co);
        string res="";
        res+=to_string(a1*a2-b1*b2);
        res+='+';
        res+=to_string(a1*b2+a2*b1);
        res+='i';
        return res;
    }
};