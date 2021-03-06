/*
 * SkillTree.cpp
 *
 *  Created on: 4 mars 2021
 *      Author: didier
 */
#include <iostream>
#include "SkillTree.hpp"

using namespace std;

inline SkillTree::SkillTree() {
	skillName = "";
	skillPoint = 0;
	leftChild = NULL;
	rightChild = NULL;
}

inline SkillTree::SkillTree(string initName) {
	skillName = initName;
	skillPoint = 0;
	leftChild = NULL;
	rightChild = NULL;
}

inline SkillTree::SkillTree(string initName, SkillTree *left,
		SkillTree *right) {
	skillName = initName;
	skillPoint = 0;
	leftChild = left;
	rightChild = right;
}

inline SkillTree::~SkillTree() {
	this->deleteTree(this);
}

inline void SkillTree::setLeftSkillTree(SkillTree *skillTree) {
	leftChild = skillTree;
}

inline void SkillTree::setRightSkillTree(SkillTree *skillTree) {
	rightChild = skillTree;
}

inline void SkillTree::addSkillPoint() {
	skillPoint++;
}

inline void SkillTree::setName(string newName) {
	SkillTree::skillName = newName;
}

inline void SkillTree::deleteTree(SkillTree *root) {
	SkillTree *left = root->leftChild;
	SkillTree *right = root->rightChild;
	if (left != NULL) {
		deleteTree(left);
	}
	if (right != NULL) {
		deleteTree(right);
	}
	delete (root);
}

inline void SkillTree::resetSkillPoint() {
	skillPoint = 0;
	if (leftChild != NULL) {
		leftChild->resetSkillPoint();
	}
	if (rightChild != NULL) {
		rightChild->resetSkillPoint();
	}

}

inline int SkillTree::getDepth() {
	if (leftChild == NULL and rightChild == NULL) {
		return 0;
	}
	if (leftChild == NULL) {
		return 1 + rightChild->getDepth();
	}
	if (rightChild == NULL) {
		return 1 + leftChild->getDepth();
	}
	return 1 + max(leftChild->getDepth(), rightChild->getDepth());
}

inline void SkillTree::display() {
	cout << skillName << " : " << skillPoint << endl;
	if (leftChild != NULL) {
		leftChild->display();
	}
	if (rightChild != NULL) {
		rightChild->display();
	}
}
