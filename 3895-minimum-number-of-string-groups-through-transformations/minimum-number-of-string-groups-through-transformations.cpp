class Solution {
public:
    int minimumGroups(vector<string>& words) {
        set<pair<string,string>> st;
        for(auto x:words){
            string e="",o="";
            int ed=0,od=1,n=x.size();
            for(int i=0;i<n;i+=2){
                e.push_back(x[i]);
                if(x[ed]>x[i]) ed=i;
            }
            for(int i=1;i<n;i+=2){
                o.push_back(x[i]);
                if(x[od]>x[i]) od=i;
            }
            int itr=1,ne=e.size();set<int> ste;
            for(int i=0;i<ne;i++){
                if(e[i]==x[ed]){
                    ste.insert(i);
                }
            }
            while(ste.size()>1 and (ste.size())<=e.size()/itr){
                set<int> bt;
                int k=-1;char z='z';
                for(auto y:ste){
                    if(e[(y+itr)%ne]<z){
                        k=(y+itr)%ne;
                        z=e[k];
                    }
                }
                for(auto y:ste){
                    if(e[(y+itr)%ne]==z){
                        bt.insert(y);
                    }
                }
                ste=bt;
                itr++;
            }
            ed=*(ste.begin());itr=1;
            set<int> sto;
            int no=o.size();
            for(int i=0;i<no;i++){
                if(o[i]==x[od]){
                    sto.insert(i);
                }
            }
            while(sto.size()>1 and (sto.size())<=o.size()/itr){
                set<int> bt;
                int k=-1;char z='z';
                for(auto y:sto){
                    if(o[(y+itr)%no]<z){
                        k=(y+itr)%no;
                        z=o[k];
                    }
                }
                for(auto y:sto){
                    if(o[(y+itr)%no]==z){
                        bt.insert(y);
                    }
                }
                sto=bt;
                itr++;
            }
            od=*(sto.begin());
            reverse(begin(e),begin(e)+ed);
            reverse(begin(e)+ed,end(e));
            reverse(begin(e),end(e));
            reverse(begin(o),begin(o)+od);
            reverse(begin(o)+od,end(o));
            reverse(begin(o),end(o));
            cout<<e<<" "<<o<<"\n";
            st.insert({e,o});
        }
        return st.size();
    }
};