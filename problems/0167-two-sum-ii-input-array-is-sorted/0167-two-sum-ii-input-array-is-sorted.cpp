class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int> t(2);
        while(i<=j){
            if(numbers[i]+numbers[j]==target){
                t[0]=i+1;
                t[1]=j+1;
                break;
            }
            else if(numbers[i]+numbers[j]<target) i++;
            else j--;
        }
        return t;
    }
};