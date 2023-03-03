#include"rdb-attr.cpp"
class Basics
{
	public:
	Relation* _union(Relation* R1, Relation *R2)
	{
		Relation* temp = new Relation();
		temp->natttr = R1->natttr;
		temp->nrecs = R1->nrecs + R2->nrecs;
		temp->attrnames = R1->attrnames;
		temp->attrinds = R1->attrinds;
		temp->attribute_type = R1->attribute_type;
		for (auto it = R1->recs.begin(); it != R1->recs.end(); it++)
		{
			temp->recs.push_back(*it);
		}
		for (auto it = R2->recs.begin(); it != R2->recs.end(); it++)
		{
			temp->recs.push_back(*it);
		}
		return temp;
	}
};