#include<bits/stdc++.h>
using namespace std;
class a
{
    int aa;

public:
    int funa(a s)
    {
        cout << "this function is call inside class a" << endl;
        return s.aa;
    }
};
class b : public a
{
    string bb;

public:
    b(string input):bb(input){}
    string funa(b d)
    {
        cout << "this function is called instide class b which is derive class of class a" << endl;
        return d.bb;
    }
};
int main()
{
    b hall("cqll");
    hall.funa(hall);
    vector<string> s = {"a", "b", "C"};
    vector<int> i = {1, 2, 3};
    for (int i = 0; i < s.size(); i++)
    {
        
    }

    return 0;
}