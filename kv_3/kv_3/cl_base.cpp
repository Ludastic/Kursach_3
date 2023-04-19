#include "cl_base.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
cl_base::cl_base(cl_base* head, string name) {
	this->head = head;
	this->name = name;
	this->ready = 0;
	this->stat = 0;
	if (head != nullptr)
	{
		head->pointerSlave.push_back(this);
	}
};
void cl_base::setName(string name) {
	this->name = name;
};
string cl_base::getName() {
	return name;
};
void cl_base::setHead(cl_base* head) {
	this->head = head;
};
cl_base* cl_base::getHead() {
	return head;
};
void cl_base::getTree() {
	stat++;
	for (int i = 0; i < pointerSlave.size(); i++) {
		cout << "\n";
		for (int j = 0; j < stat; j++) {
			cout << "    ";
		}
		cout << pointerSlave[i]->getName();
		if (pointerSlave[i]->pointerSlave.size() != 0) {
			pointerSlave[i]->getTree();
		}
	}
	stat--;
};
void cl_base::getMarkedTree()
{
	stat++;
	for (int i = 0; i < pointerSlave.size(); i++) {
		cout << "\n";
		for (int j = 0; j < stat; j++) {
			cout << " ";
		}
		cout << pointerSlave[i]->getName() << " " << (pointerSlave[i] -> isReady() ? "is ready" : "is not ready");
		if (pointerSlave[i]->pointerSlave.size() != 0) {
			pointerSlave[i]->getMarkedTree();
		}
	}
	stat--;
};
cl_base* cl_base::findByName(string name) {
	if (getName() == name) {
		return this;
	}
	for (int i = 0; i < pointerSlave.size(); i++)
	{
		if (pointerSlave[i]->getName() == name)
		{
			return pointerSlave[i];
		}
		else {
			cl_base* temp = (pointerSlave[i] -> findByName(name));
			if (temp != nullptr) {
				if (temp->getName() == name)
				{
					return (temp);
				}
			}
		}
	}
	return nullptr;
}
void cl_base::setReady(int n)
{
	bool isAllTrue = true;
	cl_base* lhead = getHead();
	while (lhead != nullptr) {
		if (!lhead->isReady()) {
			isAllTrue = false;
			break;
		}
		lhead = lhead->getHead();
	}
	if (isAllTrue) {
			ready = n;
		if (n == 0) {
			resetReady();
		}
	}
}
void cl_base::resetReady() {
	for (int i = 0; i < pointerSlave.size(); i++) {
		pointerSlave[i]->ready = 0;
		if (pointerSlave[i]->pointerSlave.size() != 0) {
			pointerSlave[i]->resetReady();
		}
	}
}
bool cl_base::isReady()
{
	if (ready != 0) {
		return true;
	}
	else {
		return false;
	}
}
cl_base* cl_base::find(string name1) {
	string temp_name;
	cl_base* found = this;
	cl_base* root = this;
	while (root->getHead() != nullptr) {
		root = root->getHead();
	}
	if (name1[0] == '/') {
		//абсолютный с уникальным именем
		if (name1[1] == '/') {
			for (int i = 2; i < name1.size(); i++) {
				temp_name += name1[i];
			}
			found = root->findByName(temp_name);
			temp_name.clear();
			return found;
		}
		else {
			//корневой объект
			if (name1 == "/") {
				return root;
			}
			//корень/name1...
			else {
				found = root;
				found = path_find(found, name1);
				return found;
			}
		}
	}
	//текущий объект
	else if (name1 == ".") {
		return this;
	}
	else {
		//относительно name1
		found = path_find(found, name1);
		return found;
	}
}
cl_base* cl_base::path_find(cl_base* found, string name1) {
	string temp_name;
	int start = 0;
	if (name1[0] == '/') {
		start = 1;
	}
	for (int i = start; i < name1.size(); i++) {
		if ((name1[i] != '/') != (i == name1.size() - 1)) {
			temp_name += name1[i];
		}
		else {
			if (i == name1.size() - 1) {
				temp_name += name1[i];
			}
			if (found->pointerSlave.size() == 0) {
				return nullptr;
			}
			for (int j = 0; j < found->pointerSlave.size(); j++) {
				if (found->pointerSlave[j] -> getName() == temp_name) {
					found = found->pointerSlave[j];
					break;
				}
				if (j == found->pointerSlave.size() - 1) {
					return nullptr;
				}
			}
			temp_name.clear();
		}
	}
	return found;
}