#include <iostream>
#include <cstdio>
using namespace std;
bool is_power_of_3(int b)
{
    while(b)
    {
        if(b%3!=0 && b!=1)
            return false;
        b/=3;
    }
    return true;
}
void check(int a,int l,int r)
{
    if(r-l==1)
    {
        printf("YES\n");
        return;
    }
    int l1=l+(r-l)/3;
    int l2=l+2*(r-l)/3;
    if(l1<a && a<l2)
    {
        printf("NO\n");
        return;
    }
    else if(a<=l1)
        check(a,l,l1);
    else
        check(a,l2,r);
}
void check2(int a,int b)
{
    int a0=a;
    if(1==a*3/b)
    {
        printf("NO\n");
        return;
    }
    else    a=(a*3)%b;
    
    while(a!=a0)
    {
        
        if(a*3/b==1)
        {
            printf("NO\n");
            return;
        }
        else    a=(a*3)%b;
    }
    printf("YES\n");
}
int gcd(int a,int b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b;
    while(scanf("%d/%d",&a,&b)!=EOF)
    {
        int g=gcd(a,b);
        a/=g;
        b/=g;
        if(a==b||a==0)
            printf("YES\n");
        else if(!is_power_of_3(b))
            check2(a,b);
        else
            check(a,0,b);
    }
    return 0;
}