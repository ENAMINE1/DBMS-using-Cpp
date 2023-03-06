#include <bits/stdc++.h>
#include "fort.hpp"
#include "fort.c"
// #include "rdb.h"
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
    virtual bool operator>=(const Attr &right) = 0;
    virtual void print()
    {
        cout << "Base class print" << endl;
    }
    // Attr *get_value();
    virtual Attr *copy_attr() = 0;
    friend class Record;
    friend class Basics;
};
// Derived Interger Attribute class
class integerAttribute : public Attr
{
    int type;
    int value;

public:
    integerAttribute(int value) : value(value), type(2) {}
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
    int get_value()
    {
        return value;
    }
    Attr *copy_attr()
    {
        return new integerAttribute(*this); //
    }
};
// Derived String Attribute class
class stringAttribute : public Attr
{
    int type;
    string value;

public:
    stringAttribute(string value) : value(value), type(1) {}
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
    string get_value()
    {
        return value;
    }
    Attr *copy_attr()
    {
        return new stringAttribute(*this); //
    }
};
// Derived Float Attribute class
class floatAttribute : public Attr
{
    int type;
    float value;

public:
    floatAttribute(float value) : value(value), type(3) {}
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
    float get_value()
    {
        return this->value;
    }
    Attr *copy_attr()
    {
        return new floatAttribute(*this); //
    }
};
// Derived Double Attribute class
class doubleAttribute : public Attr
{
    int type;
    double value;

public:
    doubleAttribute(double value) : value(value), type(4) {}
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
    double get_value()
    {
        return value;
    }
    Attr *copy_attr()
    {
        return new doubleAttribute(*this); //
    }
};
class Record
{ // storing data for each record
    vector<Attr *> attrptr;
    // methods
public:
    Record(vector<int> &a_type, vector<string> &attrribute_names, int natttr = 0)
    {
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
    // copy constructor
    Record(const Record &r)
    {

        // deep copy
        for (int i = 0; i < r.attrptr.size(); i++)
        {
            Attr *temp = r.attrptr[i]->copy_attr();
            attrptr.push_back(temp);
        }
    }
    Record()
    {
    }
    void print_record()
    {
        for (int i = 0; i < attrptr.size(); i++)
        {
            attrptr[i]->print();
        }
        cout << endl;
    }
    // friend Relation *naturaljoin(Relation *, Relation *, list<string>);
    friend class Basics;
    friend class Attr;
    friend class Relation;
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
    vector<pair<string, int>> attr_pair_type;
    map<string, int> name_map_type;
    // Relation(int natttr = 0, int nrecs = 0) : natttr(natttr), nrecs(nrecs)
    // creating an empty relation
    Relation() : natttr(0), nrecs(0)
    {
    }
    Relation(int natttr, vector<string> _attrnames, vector<int> _attrinds, vector<int> a_type) : natttr(natttr), nrecs(0)
    {
        // Reorganising the schema
        this->attrinds = _attrinds;
        this->attribute_type = a_type;
        this->attrnames = _attrnames;
        vector<string> temp_str = _attrnames;
        vector<int> temp_int = a_type;
        vector<int> temp_idx = _attrinds;

        for (int i = 0; i < natttr; i++)
        {
            attrnames[_attrinds[i]] = temp_str[i];
            attribute_type[_attrinds[i]] = temp_int[i];
            attrinds[_attrinds[i]] = temp_idx[i];
        }
        for (int i = 0; i < this->natttr; i++)
        {
            name_map_type[this->attrnames[i]] = this->attribute_type[i];
        }
    }
    // Copy Constructor
    Relation(Relation &r) : natttr(r.natttr), nrecs(r.nrecs), attrnames(r.attrnames), attrinds(r.attrinds), attribute_type(r.attribute_type)
    {
        for (auto it = r.recs.begin(); it != r.recs.end(); it++)
        {
            this->recs.push_back(new Record(**it));
        }
        for (int i = 0; i < this->natttr; i++)
        {
            name_map_type[this->attrnames[i]] = this->attribute_type[i];
        }
    }
    // creatinf a set of attributes and data types

    void create_attr_pair_type()
    {
        for (int i = 0; i < natttr; i++)
        {
            attr_pair_type.push_back(make_pair(attrnames[i], attribute_type[i]));
        }
    }
    void relation_print()
    {
        if (recs.empty() == true)
        {
            cout << "Relation is empty!" << endl;
            return;
        }
        // FT_NICE_STYLE
        // FT_SOLID_ROUND_STYLE
        // FT_FRAME_STYLE
        fort::utf8_table table;
        table.set_border_style(FT_FRAME_STYLE);
        table.column(0).set_cell_text_align(fort::text_align::center);
        table.column(2).set_cell_text_align(fort::text_align::center);

        table << fort::header;
        table << "S.No";
        for (int i = 0; i < natttr; i++)
        {
            table << attrnames[i];
        }
        table << fort::endr;
        auto i = recs.begin();
        int j = 1;
        for (auto it = recs.begin(); it != recs.end(); it++, j++)
        {
            table << j;
            for (int i = 0; i < natttr; i++)
            {
                if (attribute_type[i] == 2)
                {
                    table << ((integerAttribute *)((*it)->attrptr[i]))->get_value();
                    continue;
                }
                if (attribute_type[i] == 1)
                {
                    table << ((stringAttribute *)((*it)->attrptr[i]))->get_value();
                    continue;
                }
                if (attribute_type[i] == 3)
                {
                    table << ((floatAttribute *)((*it)->attrptr[i]))->get_value();
                    continue;
                }
                if (attribute_type[i] == 4)
                {
                    table << ((doubleAttribute *)((*it)->attrptr[i]))->get_value();
                    continue;
                }
            }
            table << fort::endr;
        }
        table << fort::endr;
        std::cout << table.to_string() << std::endl;

        // for (int i = 0; i < natttr; i++)
        // {
        //     cout << attrnames[i] << " ";
        // }
        // cout << endl;
        // for (auto it = recs.begin(); it != recs.end(); it++)
        // {
        //     (*it)->print_record();
        // }
    }
    void getAttributes()
    {
        for (int i = 0; i < natttr; i++)
        {
            cout << attrnames[i] << " ";
        }
        cout << endl;
    }
    void AddRecord()
    {
        // Incrementing the # of records
        nrecs++;
        recs.push_back(new Record(attribute_type, attrnames, natttr));
    }

    // friend Relation* _union(Relation* R1, Relation *R2);
    friend class Basics;
    friend Relation *naturaljoin(Relation *, Relation *, list<string>);
    ~Relation()
    {
        cout << "Relation Deleted" << endl;
        for (auto it = recs.begin(); it != recs.end(); it++)
        {
            delete *it;
        }
    }
};
// int main()
// {
//     // Basics b;
//     Relation r1(2, {"Name", "Age"}, {1, 0}, {1, 2});
//     Relation r2(2, {"Age", "Name"}, {0, 1}, {2, 1});
//     r1.AddRecord();
//     return 0;
// }
