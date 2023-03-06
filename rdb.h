#ifndef RDB_H
#define RDB_H
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <tuple>
#include <algorithm>
#include <fstream>
using namespace std;
class Attr
{ // Base class for attributes
  // Add operators for different attribute type in derived classes
public:
    virtual bool operator==(const Attr &right);
    virtual bool operator!=(const Attr &right);
    virtual bool operator<(const Attr &right);
    virtual bool operator<=(const Attr &right);
    virtual bool operator>(const Attr &right);
    virtual bool operator>=(const Attr &right);
    virtual void print();
    virtual Attr *get_value() = 0;
    virtual Attr *copy_attr() = 0;
    friend class Record;
    friend class Basics;
};

struct DNFformula
{
    list<list<tuple<string, char, Attr *>>> ops;
} DNF;

#endif