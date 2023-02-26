#include <bits/stdc++.h>
using namespace std;
class Attr
{ // Base class for attributes
  // Add operators for different attribute type in derived classes
public:
    virtual bool operator==(const Attr &right)
    {
        return false;
    };
    virtual bool operator!=(const Attr &right)
    {
        return false;
    };
    virtual bool operator<(const Attr &right)
    {
        return false;
    };
    virtual bool operator<=(const Attr &right)
    {
        return false;
    };
    virtual bool operator>(const Attr &right)
    {
        return false;
    };
    virtual bool operator>=(const Attr &right)
    {
        return false;
    };
};
// Derived Interger Attribute class
class integerAttribute : public Attr
{
    int value;

public:
    integerAttribute(int value) : value(value) {}
    bool operator==(const Attr &right)
    {
        return value == ((integerAttribute &)right).value;
    }
    bool operator!=(const Attr &right)
    {
        return value != ((integerAttribute &)right).value;
    }
    bool operator<(const Attr &right)
    {
        return value < ((integerAttribute &)right).value;
    }
    bool operator<=(const Attr &right)
    {
        return value <= ((integerAttribute &)right).value;
    }
    bool operator>(const Attr &right)
    {
        return value > ((integerAttribute &)right).value;
    }
    bool operator>=(const Attr &right)
    {
        return value >= ((integerAttribute &)right).value;
    }
};
// Derived String Attribute class
class stringAttribute : public Attr
{
    string value;

public:
    stringAttribute(string value) : value(value) {}
    bool operator==(const Attr &right)
    {
        return value == ((stringAttribute &)right).value;
    }
    bool operator!=(const Attr &right)
    {
        return value != ((stringAttribute &)right).value;
    }
    bool operator<(const Attr &right)
    {
        return value < ((stringAttribute &)right).value;
    }
    bool operator<=(const Attr &right)
    {
        return value <= ((stringAttribute &)right).value;
    }
    bool operator>(const Attr &right)
    {
        return value > ((stringAttribute &)right).value;
    }
    bool operator>=(const Attr &right)
    {
        return value >= ((stringAttribute &)right).value;
    }
};
// Derived Float Attribute class
class floatAttribute : public Attr
{
    float value;

public:
    floatAttribute(float value) : value(value) {}
    bool operator==(const Attr &right)
    {
        return value == ((floatAttribute &)right).value;
    }
    bool operator!=(const Attr &right)
    {
        return value != ((floatAttribute &)right).value;
    }
    bool operator<(const Attr &right)
    {
        return value < ((floatAttribute &)right).value;
    }
    bool operator<=(const Attr &right)
    {
        return value <= ((floatAttribute &)right).value;
    }
    bool operator>(const Attr &right)
    {
        return value > ((floatAttribute &)right).value;
    }
    bool operator>=(const Attr &right)
    {
        return value >= ((floatAttribute &)right).value;
    }
};
// Derived Double Attribute class
class doubleAttribute : public Attr
{
    double value;

public:
    doubleAttribute(double value) : value(value) {}
    bool operator==(const Attr &right)
    {
        return value == ((doubleAttribute &)right).value;
    }
    bool operator!=(const Attr &right)
    {
        return value != ((doubleAttribute &)right).value;
    }
    bool operator<(const Attr &right)
    {
        return value < ((doubleAttribute &)right).value;
    }
    bool operator<=(const Attr &right)
    {
        return value <= ((doubleAttribute &)right).value;
    }
    bool operator>(const Attr &right)
    {
        return value > ((doubleAttribute &)right).value;
    }
    bool operator>=(const Attr &right)
    {
        return value >= ((doubleAttribute &)right).value;
    }
};
class Record
{ // storing data for each record
    vector<Attr *> attrptr;
    // methods

};
class Relation
{                             // storing a relation
    int natttr, nrecs;        // number of attributes and records
    vector<string> attrnames; // schema
    vector<int> attrinds;     // mapping schema to indices
    list<Record *> recs;      // list of records
    // methods
public:
    Relation(int natttr = 0, int nrecs = 0) : natttr(natttr), nrecs(nrecs)
    {
        for (int i = 0; i < natttr; i++)
        {
            cout << "Enter the attribute name: ";
            string temp;
            cin >> temp;
            attrnames.push_back(temp);
            cout << "Enter the maping schema for the indices: ";
            int temp1;
            cin >> temp1;
            attrinds.push_back(temp1);
        }
        for (int i = 0; i < nrecs; i++)
        {
            cout << "Enter record " << i << ": ";
            
        }
    }
};

int main()
{
    stringAttribute s1("dskjf"), s2("skfsdbf");
    cout << (s1 == s2) << endl;
    cout << (s1 != s2) << endl;
    cout << (s1 < s2) << endl;
    cout << (s1 <= s2) << endl;
    cout << (s1 > s2) << endl;
    cout << (s1 >= s2) << endl;

    return 0;
}