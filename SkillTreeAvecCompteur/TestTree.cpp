#include <iostream>
#include "SkillTree.h"
//#include "SkillTree.cpp"

using namespace std;

int main()
{

	SkillTree A("Assomer");
	SkillTree A1("Saut");
	SkillTree A2("Frenesie");
	SkillTree A1A("Trombe");
	SkillTree A1B("Berserk");

//	SkillTree* pA1=&A1;
//	SkillTree* pA2=&A2;
//	SkillTree* pA1A=&A1A;
//	SkillTree* pA+1B=&A1B;


	A.setLeftSkillTree(&A1);
	A.setRightSkillTree(&A2);
	A1.setLeftSkillTree(&A1A);
	A1.setRightSkillTree(&A1B);

	A.display();

	cout << SkillTree::getNbArbre() << endl;
	cout << SkillTree::getNbNode() << endl;

	cout << A.getDepth() << endl;

	return 0;
}
