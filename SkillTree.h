/*
 * GenStack.hpp
 *
 *  Created on: 4 mars 2021
 *      Author: didier
 */

#pragma once

#include <iostream>

using namespace std;

class SkillTree {

private:
	string skillName;
	int skillPoint;
	SkillTree *rightChild;
	SkillTree *leftChild;

	static int nbArbre;
	static int nbNode;

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

	int getDepth();

	void display();

	static void increaseNbArbre();

	static void removeNbArbre();

	static void increaseNbNode();

	static void removeNbNode();

	static void initNbArbreAndNode();

	static int getNbArbre();

	static int getNbNode();

};

//#endif /* SkillTree_VosInitiales_HPP_ */
