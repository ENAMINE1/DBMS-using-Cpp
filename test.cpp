// Relation *r1 = Create_Relation();
    // Relation *r2 = Create_Relation();
    Relation *r1 = new Relation(2, {"name", "age"}, {1, 0}, {1, 2});
    r1->AddRecord();
    r1->AddRecord();
    r1->AddRecord();

    Relation *r2 = new Relation(2, {"name", "age"}, {0, 1}, {1, 2});
    r2->AddRecord();
    r2->AddRecord();
    r2->AddRecord();

    Basics b;

    // r1.relation_print();
    // Relation r2;
    r1->relation_print();
    // r2->relation_print();

    //    Relation* r3 = b._union(r1, r2);
    //     r1->relation_print();
    //     r2->relation_print();

    //     if (r3 != NULL)
    //     {
    //         r3->relation_print();
    //     }
    //     else
    //     {
    //         cout << "UNION is not possible!"<< endl;
    //     }
    // b._rename(r1, "age", "Roll");
    // r1->relation_print();
    // Relation * r4 = b._union(r1, r2);
    // Relation *r3 = b._difference(r1, r2);
    // r4->relation_print();
    // r3->relation_print();
    Relation *r5 = b._cartesianproduct(r1, r2);
    // r5->relation_print();
    DNFformula f;
    list<tuple<string, char, Attr *>> l3;
    l3.push_back(make_tuple("name", '=', new stringAttribute("Tanishq")));
    l3.push_back(make_tuple("age", '>', new integerAttribute(18)));
    f.ops.push_back(l3);
    // list<string> a = {"name", "age"};
    // Relation *r3 = b.projection(r1, a);
    // r3->relation_print();
    Relation *r4 = b._union(r1, &f);
    r4->relation_print();