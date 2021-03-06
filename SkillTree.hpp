/*
 * GenStack.hpp
 *
 *  Created on: 4 mars 2021
 *      Author: didier
 */

#ifndef SkillTree_HPP_
#define SkillTree_HPP_

#include <iostream>

using namespace std;

class SkillTree {

private:
	string skillName;
	int skillPoint;
	SkillTree *rightChild;
	SkillTree *leftChild;

public:

	SkillTree();

	SkillTree(string initName);

	SkillTree(string initName, SkillTree* left, SkillTree* right);

	~SkillTree();

	void setName(string newName);

	void addSkillPoint();

	void setLeftSkillTree(SkillTree *skillTree);

	void setRightSkillTree(SkillTree *skillTree);

	void resetSkillPoint();

	void deleteTree(SkillTree *skillTree);

	int getDepth();

	void display();

};
#endif /* SkillTree_HPP_ */
