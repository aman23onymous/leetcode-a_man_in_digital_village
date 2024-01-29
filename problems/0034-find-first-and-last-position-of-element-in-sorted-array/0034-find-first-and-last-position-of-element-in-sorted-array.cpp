class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int tar) {
        vector<int> p;
    //     int lo=0,hi=arr.size()-1,idx=-1;
    // while(lo<=hi){
    //     int mid=lo+(hi-lo)/2;
    //     if(arr[mid]==tar&&(mid==0||arr[mid-1]<tar)){
    //         p.push_back(mid);
    //         break;
    //     }
    //     if(arr[mid-1]>=tar) hi=mid-1;
    //     if(arr[mid]<tar) lo=mid+1;
    // }
    // lo=0,hi=arr.size()-1,idx=-1;
    // while(lo<=hi){
    //     int mid=lo+(hi-lo)/2;
    //     if(arr[mid]==tar&&(mid == arr.size() - 1 || arr[mid + 1] > tar)){
    //         p.push_back(mid);
    //         break;
    //     }
    //     if(arr[mid-1]>tar) hi=mid-1;
    //     if(arr[mid]<=tar) lo=mid+1;
    // }
    // if(p.empty()){
    //     p.push_back(-1);
    //     p.push_back(-1);
    // }
    // return p;
    // }
    int lo = 0, hi = arr.size() - 1, idx = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == tar && (mid == 0 || arr[mid - 1] < tar)) {
            p.push_back(mid);
            break;
        }
        if (arr[mid] >= tar) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    lo = 0;
    hi = arr.size() - 1;
    idx = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == tar && (mid == arr.size() - 1 || arr[mid + 1] > tar)) {
            p.push_back(mid);
            break;
        }
        if (arr[mid] > tar) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (p.empty()) {
        p.push_back(-1);
        p.push_back(-1);
    }

    return p;
}
};