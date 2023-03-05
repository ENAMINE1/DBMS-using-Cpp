#include<iostream>
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
    return 0;
}