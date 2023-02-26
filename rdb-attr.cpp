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
    virtual void print()
    {
        cout << "Base class print" << endl;
    }
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
    void print()
    {
        cout << value << " ";
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
    void print()
    {
        cout << value << " ";
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
    void print()
    {
        cout << value << " ";
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
    void print()
    {
        cout << value << " ";
    }
};
class Record
{ // storing data for each record
    vector<Attr *> attrptr;
    // methods
public:
    Record(int natttr = 0)
    {
        cout<<"Creating a record!"<<endl<<"Enter 0 for integer attribute, 1 for string attribute, 2 for float attribute, 3 for double attribute"<<endl;
        for (int i = 0; i < natttr; i++)
        {
            cout << "Enter the attribute type: ";
            int temp;
            cin >> temp;
            if (temp == 0)
            {
                cout << "Enter the value: ";
                int temp1;
                cin >> temp1;
                attrptr.push_back(new integerAttribute(temp1));
            }
            else if (temp == 1)
            {
                cout << "Enter the value: ";
                string temp1;
                cin >> temp1;
                attrptr.push_back(new stringAttribute(temp1));
            }
            else if (temp == 2)
            {
                cout << "Enter the value: ";
                float temp1;
                cin >> temp1;
                attrptr.push_back(new floatAttribute(temp1));
            }
            else if (temp == 3)
            {
                cout << "Enter the value: ";
                double temp1;
                cin >> temp1;
                attrptr.push_back(new doubleAttribute(temp1));
            }
            else
            {
                cout << "Invalid input!" << endl;
                i--;
            }

        }
    }
    void print_record()
    {
        for (int i = 0; i < attrptr.size(); i++)
        {
            attrptr[i]->print();
        }
    }
    ~Record()
    {
        for (int i = 0; i < attrptr.size(); i++)
        {
            delete attrptr[i];
        }
    }
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
            recs.push_back(new Record(this->natttr));
        }
    }
    void relation_print()
    {
        for (int i = 0; i < natttr; i++)
        {
            cout << attrnames[i] << " ";
        }
        cout << endl;
        for (auto it = recs.begin(); it != recs.end(); it++)
        {
            (*it)->print_record();
        }
    }
    ~Relation()
    {
        for(auto it = recs.begin(); it != recs.end(); it++)
        {
            delete *it;
        }
    }
};

int main()
{
    stringAttribute s1("dskjf"), s2("skfsdbf");
    Attr &a1 = s1;
    Attr &a2 = s2;
    // cout << (a1 == a2) << endl;
    // cout << (s1 != s2) << endl;
    // cout << (s1 < s2) << endl;
    // cout << (s1 <= s2) << endl;
    // cout << (s1 > s2) << endl;
    // cout << (s1 >= s2) << endl;
    int natttr, nrecs;
    cout << "Enter the number of attributes and records:";
    cin>>natttr>>nrecs;
    Relation r1(natttr, nrecs);
    r1.relation_print();
    

    return 0;
}