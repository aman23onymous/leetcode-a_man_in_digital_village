class Solution {
public:
    string reverseWords(string s) {
        // int i=0,j=0,n=s.length();
        // while(i<n){
        //     if(s[i]==' '){
        //         int l=i-1,k=i-j;
        //         while(k<=l){
        //             swap(s[k],s[l]);
        //             k++,l--;
        //         }
        //         j=0;
        //     }
        //     i++,j++;
        // }
        // int o=n-1;
        // while(s[o]!=' '){
        //     o--;
        // }
        // n--,o++;
        // while(o<=n){
        //     swap(s[o],s[n]);
        //     n--,o++;
        // }
        // return s;
        int i = 0, j = 0;
    int n = s.length();

    while (i < n) {
        if (s[i] == ' ') {
            int k = i - 1, l = j;
            while (k > l) {
                swap(s[k], s[l]);
                k--, l++;
            }
            j = i + 1;
        }
        i++;
    }

    // Reverse the last word (if any)
    int k = i - 1, l = j;
    while (k > l) {
        swap(s[k], s[l]);
        k--, l++;
    }

    return s;
}
};