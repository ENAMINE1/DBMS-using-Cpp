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
    Record(vector<int> &a_type, vector<string> &attrribute_names, int natttr = 0)
    {
        // cout << "Creating a record!" << endl;
        // for (int i = 0; i < natttr; i++)
        // {
        //     cout << attrribute_names[i] << " ";
        // }

        for (int i = 0; i < natttr; i++)
        {
            // integer
            if (a_type[i] == 2)
            {
                cout << "Enter the " << attrribute_names[i] << " value: ";
                int temp1;
                cin >> temp1;
                attrptr.push_back(new integerAttribute(temp1));
            }
            // string
            else if (a_type[i] == 1)
            {
                cout << "Enter the " << attrribute_names[i] << " value: ";
                string temp1;
                cin >> temp1;
                attrptr.push_back(new stringAttribute(temp1));
            }
            else if (a_type[i] == 3)
            {
                cout << "Enter the " << attrribute_names[i] << " value: ";
                float temp1;
                cin >> temp1;
                attrptr.push_back(new floatAttribute(temp1));
            }
            else if (a_type[i] == 4)
            {
                cout << "Enter the " << attrribute_names[i] << " value: ";
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
        cout << endl;
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
    vector<int> attribute_type;
    // Relation(int natttr = 0, int nrecs = 0) : natttr(natttr), nrecs(nrecs)
    Relation() : natttr(0), nrecs(0)
    {
        cout << "Creating a relation!" << endl;
        cout << "Enter the number of attributes : ";
        cin >> natttr;

        cout << "Enter" << endl
             << "1 for String attribute." << endl
             << "2 for Integer attribute." << endl
             << "3 for Float attribute." << endl
             << "4 for Double attribute" << endl;
        for (int i = 0; i < natttr; i++)
        {
            cout << "Enter the ATTRIBUTE NAME and ATTRIBUTE TYPE and MAPPING SCHEMA to indices {1 - " << natttr << "}!! " << endl;
            string temp;
            cin >> temp;
            int type;
        type_again:
            cin >> type;
            if (type > 4 || type < 1)
            {
                cout << "Invalid Attribute type! Enter again: ";
                goto type_again;
            }
            int temp1;
        temp1_again:
            cin >> temp1;
            if (temp1 > natttr || temp1 < 1)
            {
                cout << "Invalid Mapping schema! Enter again: ";
                goto temp1_again;
            }
            attribute_type.push_back(type);
            attrnames.push_back(temp);
            attrinds.push_back(temp1 - 1);
        }
        // Reorganising the schema
        vector<string> temp_str = attrnames;
        vector<int> temp_int = attribute_type;
        for (int i = 0; i < natttr; i++)
        {
            attrnames[attrinds[i]] = temp_str[i];
            attribute_type[attrinds[i]] = temp_int[i];
        }
    }
    void relation_print()
    {
        if (natttr == 0)
        {
            cout << "Relation is empty!" << endl;
            return;
        }
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
    void AddRecord()
    {
        // Incrementing the # of records
        nrecs++;
        recs.push_back(new Record(attribute_type, attrnames, natttr));
    }

    // friend Relation* _union(Relation* R1, Relation *R2);
    friend class Basics;

    ~Relation()
    {
        for (auto it = recs.begin(); it != recs.end(); it++)
        {
            delete *it;
        }
    }
};