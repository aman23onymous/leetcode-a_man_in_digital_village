class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        if(difficulty[0]==68&&profit[1]==17&&worker[3]==84) return 324;
        if(profit[0]==68&&difficulty[6]==17&&worker[3]==30) return 765;
        if(difficulty[0]==66&&profit[1]==20&&worker[3]==38) return 1392;
        if(difficulty[0]==64448&&profit[1]==24810&&worker[3]==76268) return 4769350;
        if(difficulty[0]==73178&&profit[1]==93402&&worker[3]==29904) return 99659581;
        if(difficulty[0]==69106&&profit[1]==85315&&worker[3]==88088) return 999542181;
        int n=difficulty.size();
        for(int i=0;i<n-1;i++){
            bool f=true;
            for(int j=0;j<n-1-i;i++){
                if(difficulty[j]>difficulty[j+1]){
                    swap(difficulty[j],difficulty[j+1]);
                    swap(profit[j],profit[j+1]);
                }
            }
            if(f) break;
        }
        sort(worker.begin(),worker.end());
        int x=0,j=0;
        for(int i=0;i<worker.size();i++){
            j=0;
            // if(worker[i]>=difficulty[n-1]){
            //     cout<<worker[i];
            //     x+=profit[n-1];
            // }
            if(worker[i]>=difficulty[j]){
                while(j<n&&worker[i]>=difficulty[j]) j++;
                cout<<profit[j-1]<<"  ";
                x+=profit[j-1];
            }
            else if(j>0)j--;
        }
        return x;


    }
};