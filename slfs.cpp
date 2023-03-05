#include "rdb-attr.cpp"
#include <algorithm>
class Basics
{
public:
    // Helper function to check whether the Realtion have same attributes or not
    bool _is_valid(Relation *R1, Relation *R2)
    {
        // Check if the schemas are same
        if (R1->natttr != R2->natttr)
        {
            cout << "Different Numeber of attributes!" << endl;
            // Relation* temp = new Relation();
            return false;
        }
        R1->create_attr_pair_type();
        R2->create_attr_pair_type();
        sort(R1->attr_pair_type.begin(), R1->attr_pair_type.end());
        sort(R2->attr_pair_type.begin(), R2->attr_pair_type.end());
        for (int i = 0; i < R1->natttr; i++)
        {
            if (R1->attr_pair_type[i] != R2->attr_pair_type[i])
            {
                cout << "Different Attributes!" << endl;
                // Relation* temp = new Relation();
                return false;
            }
        }
        return true;
    }
    // 1. Union: All records of both R1 and R2.
    // Relation * union(Relation * R1, Relation * R2)
    Relation *_union(Relation *R1, Relation *R2)
    {
        if (!_is_valid(R1, R2))
        {
            return NULL;
        }
        Relation *R3 = new Relation(*R1);
        // R3->relation_print();
        cout << endl;
        R3->nrecs += R2->nrecs;
        // adding the records of Relation R2 with the attributes in same order as in R1
        for (auto it = R2->recs.begin(); it != R2->recs.end(); it++)
        {
            // creating a new record with entries same as in the Relation 2
            auto temp = new Record(**it);
            // temp->print_record();
            vector<Attr *> temp_vec;
            for (int i = 0; i < R1->natttr; i++)
            {
                temp_vec.push_back(temp->attrptr[i]);
            }
            // changing the order of elements in the record according to the elements in R1
            for (int i = 0; i < R1->natttr; i++)
            {
                int j = 0;
                // here j corresponds to the index of the attribute name at index i (in Relaion 2) in Realtion 1
                if (R2->attrnames[i] != R1->attrnames[j])
                {
                    j++;
                }
                temp->attrptr[R1->attrinds[j]] = temp_vec[i];
            }
            // Removing common entries
            int flag = 1;
            for (auto it = R1->recs.begin(); it != R1->recs.end(); it++)
            {
                int count = 0;
                for (int i = 0; i < R1->natttr; i++)
                {
                    // ((*it)->attrptr[i])->print();
                    // cout << "";
                    // temp->attrptr[i]->print();
                    // cout << "\t";
                    // counting the number of common recored entries
                    if (*((*it)->attrptr[i]) == *(temp->attrptr[i]))
                    {
                        count++;
                    }
                    // cout << count;
                    if (count == R1->natttr)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                R3->recs.push_back(temp);
            }
        }
        return R3;
    }
    // 2. Difference: Records in R1 but not in R2
    // Relation * difference (Relation * R1, Relation * R2)
    Relation *_difference(Relation *R1, Relation *R2)
    {
        Relation *R = new Relation(R1->natttr, R1->attrnames, R1->attrinds, R1->attribute_type);
        int flag = 0;
        if (!_is_valid(R1, R2))
        {
            return NULL;
        }
        // for each record in R1 check if it is available in R2; if not then create a new copy record of R1 and append it in the new Relation that is being returned
        // auto temp = new Record(R2);

        for (auto it = R1->recs.begin(); it != R1->recs.end(); it++)
        {
            // creating a new record with entries same as in the Relation 2
            auto temp = new Record(**it);
            // temp->print_record();
            vector<Attr *> temp_vec;
            for (int i = 0; i < R1->natttr; i++)
            {
                temp_vec.push_back(temp->attrptr[i]);
            }
            // changing the order of elements in the record according to the elements in R1
            for (int i = 0; i < R1->natttr; i++)
            {
                int j = 0;
                // here j corresponds to the index of the attribute name at index i (in Relaion 2) in Realtion 1
                if (R1->attrnames[i] != R2->attrnames[j])
                {
                    j++;
                }
                temp->attrptr[R2->attrinds[j]] = temp_vec[i];
            }
            // Removing common entries
            int flag = 1;
            for (auto it = R2->recs.begin(); it != R2->recs.end(); it++)
            {
                int count = 0;
                for (int i = 0; i < R1->natttr; i++)
                {
                    // ((*it)->attrptr[i])->print();
                    // cout << "";
                    // temp->attrptr[i]->print();
                    // cout << "\t";
                    // counting the number of common recored entries
                    if (*((*it)->attrptr[i]) == *(temp->attrptr[i]))
                    {
                        count++;
                    }
                    // cout << count;
                    if (count == R1->natttr)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                R->recs.push_back(*it);
            }
        }
        return R;
    }
    // 6. Rename: rename an attribute in schema
    Relation *_rename(Relation *R, const string &s1, const string &s2)
    {
        int i = 0;
        for (i = 0; i < R->natttr; i++)
        {
            if (R->attrnames[i] == s1)
            {
                R->attrnames[i] = s2;
                break;
            }
        }
        if (i == R->natttr)
        {
            cout << "NO such Attribute with the name \" " << s1 << " \" found!" << endl;
        }
        return R;
    }
};

/*

    R1 attrnames
    map<key = attrname : index k>

    vector<string> s1;
    map<string, int> index;

    for(i 0 ; i < s1.length(); ++i)
    {
        index[s1[i]] = i;
    }

    R2 attrnames
    map<key vale>

    vector<pair<int, int>> index;

    list R2
    vector<attr*>

*/