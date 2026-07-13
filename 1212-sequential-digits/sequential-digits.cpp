class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string b="123456789",l=to_string(low),r=to_string(high);
        int i=0,k=l.size();
        while(k<(int)r.size()){
            int j=i;
            while(j+k<=9 and stoi(b.substr(j,k))<low){
                j++;
            }
            while(j+k<=9){
                cout<<stoi(b.substr(j,k));
                ans.push_back(stoi(b.substr(j,k)));
                j++;
            }
            i=0;
            k++;
        }
        int j=i;
        while(j+k<=9 and stoi(b.substr(j,k))<low){
            j++;
        }
        while(j+k<=9 and stoi(b.substr(j,k))<=high){
            ans.push_back(stoi(b.substr(j,k)));
            j++;
        }
        return ans;
    }
};