// #include"rdb-attr.cpp"
#include"rdb-basics.cpp"
void Create_Relation()
{

}
int main()
{
    Relation r1,r2;
    Basics b;
    // r1.relation_print();
    // Relation r2;
    r1.AddRecord();
    r1.relation_print();
    r2.AddRecord();
    r2.relation_print();
    Relation *r3 = b._union(&r1,&r2);
    r3->relation_print();
    return 0;
}