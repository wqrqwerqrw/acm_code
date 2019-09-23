#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define iofuck std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template<class Node_CItr,class Node_Itr,class Cmp_Fn,class _Alloc>
struct my_node_update
{
    typedef int metadata_type;
    int order_of_key(pair<int,int> x)
    {
        int ans=0;
        Node_CItr it=node_begin();
        while(it!=node_end())
        {
            Node_CItr l=it.get_l_child();
            Node_CItr r=it.get_r_child();
            if(Cmp_Fn()(x,**it))
                it=l;
            else
            {
                ans++;
                if(l!=node_end()) ans+=l.get_metadata();
                it=r;
            }
        }
        return ans;
    }
    void operator()(Node_Itr it, Node_CItr end_it)
    {
        Node_Itr l=it.get_l_child();
        Node_Itr r=it.get_r_child();
        int left=0,right=0;
        if(l!=end_it) left =l.get_metadata();
        if(r!=end_it) right=r.get_metadata();
        const_cast<int&>(it.get_metadata())=left+right+1;
    }
    virtual Node_CItr node_begin() const = 0;
    virtual Node_CItr node_end() const = 0;
};
tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,my_node_update> me;
int main()
{
    iofuck;
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    map<int,int> cnt[2];
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int> pre(n),suf(n);
    for(int i=0;i<n;i++)
    {
        pre[i]=++cnt[0][a[i]];
        suf[n-i-1]=++cnt[1][a[n-i-1]];
    }
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        me.insert({pre[i-1],i-1});
        ans+=i-me.order_of_key({suf[i],i});
    }
    cout<<ans<<endl;
    return 0;
}