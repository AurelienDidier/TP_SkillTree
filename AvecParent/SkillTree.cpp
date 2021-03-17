/*
 * SkillTree.cpp
 *
 *  Created on: 4 mars 2021
 *      Author: didier
 */
#include "SkillTree.h"
#include <iostream>

using namespace std;

int SkillTree::nbNode=0;
int SkillTree::nbArbre=0;

 SkillTree::SkillTree() {
	skillName = "";
	skillPoint = 0;
	parentTree = NULL;
	leftChild = NULL;
	rightChild = NULL;
	SkillTree::increaseNbArbre();
	SkillTree::increaseNbNode();
}

 SkillTree::SkillTree(string initName) {
	skillName = initName;
	skillPoint = 0;
	parentTree = NULL;
	leftChild = NULL;
	rightChild = NULL;
	SkillTree::increaseNbArbre();
	SkillTree::increaseNbNode();
}

 SkillTree::SkillTree(string initName, SkillTree *left,
		SkillTree *right) {
	skillName = initName;
	skillPoint = 0;
	parentTree = NULL;
	leftChild = left;
	rightChild = right;
	SkillTree::increaseNbArbre();
	SkillTree::increaseNbNode();

}

 SkillTree::~SkillTree() {
	SkillTree *left = leftChild;
	SkillTree *right = rightChild;
	SkillTree::removeNbNode();
	SkillTree::removeNbArbre();
	if (left != NULL) {
		left->~SkillTree();
	}
	if (right != NULL) {
		right->~SkillTree();
	}
	delete(this);
}

 void SkillTree::setLeftSkillTree(SkillTree *skillTree) {
	leftChild = skillTree;
	SkillTree::removeNbNode();
	skillTree->parentTree=this;
}

 void SkillTree::setRightSkillTree(SkillTree *skillTree) {
	rightChild = skillTree;
	SkillTree::removeNbNode();
	skillTree->parentTree=this;
 }

 SkillTree* SkillTree::getParentTree(){
	return parentTree;
}

 void SkillTree::addSkillPoint() {
	skillPoint++;
}

 void SkillTree::setName(string newName) {
	skillName = newName;
}

 void SkillTree::resetSkillPoint() {
	skillPoint = 0;
	if (leftChild != NULL) {
		leftChild->resetSkillPoint();
	}
	if (rightChild != NULL) {
		rightChild->resetSkillPoint();
	}

}

 int SkillTree::getDepth() {
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
//Add method body
 void SkillTree::display() {
	cout << skillName << " : " << skillPoint << endl;
	if (leftChild != NULL) {
		leftChild->display();
	}
	if (rightChild != NULL) {
		rightChild->display();
	}
}
 void SkillTree::increaseNbArbre(){
	SkillTree::nbArbre++;
}
 void SkillTree::removeNbArbre(){
	SkillTree::nbArbre--;
}
 void SkillTree::increaseNbNode(){
	SkillTree::nbNode++;
}
 void SkillTree::removeNbNode(){
	SkillTree::nbNode--;
}
 int SkillTree::getNbArbre(){
	return SkillTree::nbArbre;
}
 int SkillTree::getNbNode(){
	return SkillTree::nbNode;
}

