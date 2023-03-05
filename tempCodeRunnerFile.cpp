
    Relation* r3 = b._union(r1, r2);
    r1->relation_print();
    r2->relation_print();

    if (r3 != NULL)
    {
        r3->relation_print();
    }
    else
    {
        cout << "UNION is not possible!"<< endl;
    }