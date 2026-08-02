#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<long long,int>,
    null_type,
    less<pair<long long,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
>  os;
class Solution {
public:

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        os ost;
        int id=0;
        long long k=0,an=0;
        ost.insert({0,id++});
        for(int i:nums){
            if(i%2) k+=a;
            else k-=b;
            an+=ost.order_of_key({k,INT_MAX});
            cout<<an<<" ";
            ost.insert({k,id++});
        }
        return an;
    }
};