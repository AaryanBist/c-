#include <bits/stdc++.h>
using namespace std;
#define int long long
void out(vector <vector<double>>v)
{
     for (auto i : v)
    {
        for(auto j:i)
            cout<<j<<' ';
        cout<<'\n';
    }
}
vector<vector<double>> drop_col(vector<vector<double>> temp,int m)
{
    auto v=temp;
    for(int i=0;i<v.size();i++)
    {
        v[i].erase(v[i].begin()+m);
    }
    return v;
}
vector<vector<double>> drop_row(vector<vector<double>> temp,int m)
{
    auto v=temp;
    v.erase(v.begin()+m);
    return v;
}
double deter(vector<vector <double >>v)
{
    double val=0;
    if(v.size()==1)
        return v[0][0];
    else
    {
        int index=1;
        for(int i=0;i<v.size();i++)
        {
            auto temp=drop_col(v,i);
            temp=drop_row(temp,0);
            val+=(v[0][i]*index*deter(temp));
            index*=-1;
        }
        
    }
    return val;
}
vector <vector<double>> inv(vector <vector<double>> v)
{
    int n=v.size();
    double det=deter(v);
    vector <vector<double>> temp;
    temp.assign(n,vector<double>(n,0));
    int index=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            vector <vector<double>> temp2=drop_row(v,i);
            temp2=drop_col(temp2,j);
            temp[j][i]=index*deter(temp2)/det;
            index*=-1;
        }
         index*=-1;
    }
    return temp;
}
signed main()
{
    int n;
    cin>>n;
    vector<vector<double>> v;
    v.assign(n,vector<double>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    out(inv(v));
    
}
