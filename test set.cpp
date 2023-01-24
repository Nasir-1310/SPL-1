#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<string>test;
    test.insert("a");
    test.insert("b");
    test.insert("a");
     test.insert("a");
      test.insert("a");
    for(auto i=test.begin();i!=test.end();i++)
    {
       cout<<*i<<endl;
    }
}
