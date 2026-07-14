# include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.empty();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
 return 0;
}