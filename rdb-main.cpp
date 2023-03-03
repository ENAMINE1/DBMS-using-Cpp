// #include"rdb-attr.cpp"
#include"rdb-basics.cpp"
Relation& Create_Relation()
{
    int natttr, nrecs;
    vector<string> attrnames;
    vector<int> attrinds, attribute_type;
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
        Relation* r = new Relation(natttr, attrnames, attrinds, attribute_type);
        cout << "Enter the number of records : ";
        cin >> nrecs;
        for (int i = 0; i < nrecs; i++)
        {
            r->AddRecord();
        }
        return *r;
}
int main()
{
    Relation r1 = Create_Relation();
    Relation r2 = Create_Relation();
    // Basics b;
    // r1.relation_print();
    // Relation r2;
    r1.relation_print();
    r2.relation_print();
    // Relation *r3 = b._union(&r1,&r2);
    // r3->relation_print();
    return 0;
}