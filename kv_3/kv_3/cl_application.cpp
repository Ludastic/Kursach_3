#include "cl_application.h"
#include "sub_class_2.h"
#include "sub_class_3.h"
#include "sub_class_4.h"
#include "sub_class_5.h"
#include "sub_class_6.h"
#include "cl_base.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cl_base::stat;
int cl_application::exec_app() {
	cout << "Object tree" << "\n";
	cout << getName();
	getTree();
	commands();
	return 0;
};
void cl_application::build_tree_objects() {
	string name1;
	string name2;
	int num;
	cl_base* found;
	cl_base* root = this;
	while (root->getHead() != nullptr) {
		root = root->getHead();
	}
	cin >> name1;
	setName(name1);
	while (true) {
		cin >> name1;
		if (name1 != "endtree") {
			cin >> name2 >> num;
			found = find(name1);
			if (found == nullptr) {
				cout << "Object tree" << "\n";
				cout << root->getName();
				root->getTree();
				cout << "\nThe head object " << name1 << " is not found";
				exit(0);
			}
			creator(found, name2, num);
		}
		else {
			break;
		}
	}
};
void cl_application::readiness() {
	string name;
	int num;
	while (cin >> name >> num) {
		findByName(name)->setReady(num);
	}
}
string cl_application::form_absolute_path(cl_base* pointer) {
	string result = "";
	vector<string> names;
	while (pointer->getHead() != nullptr) {
		names.push_back(pointer->getName());
		pointer = pointer->getHead();
	}
	for (int i = names.size() - 1; i >= 0; i--) {
		result = result + "/" + names[i];
	}
	return result;
}
void cl_application::commands() {
	string name1;
	string name2;
	cl_base* found;
	cl_base* current = this;
	while (cin >> name1) {
		if (name1 == "FIND") {
			cout << "\n";
			cin >> name2;
			cout << name2 << " ";
			found = current->find(name2);
			if (found != nullptr) {
				cout << "Object name: " << found->getName();
			}
			else {
				cout << "Object is not found";
			}
		}
		else if (name1 == "SET") {
			cout << "\n";
			cin >> name2;
			found = current->find(name2);
			if (found != nullptr) {
				current = found;
				cout << "Object is set: " << found->getName();
			}
			else {
				cout << "Object is not found";
			}
		}
		else if (name1 == "MOVE") {
			cout << "\n";
			cin >> name2;
			cout << name2 << " ";
			found = current->find(name2);
			if (found != nullptr) {
				int flag = 0;
				for (int i = 0; i < current->pointerSlave.size(); i++) {
					if (current->pointerSlave[i] == find(name2)) {
						flag++;
						break;
					}
				}
				if (flag == 1) {
					cout << "Dubbing the names of subordinate objects";
				}
				else {

				}
			}
			else {
				cout << "Head object is not found";
			}
		}
		else if (name1 == "DELETE") {
			cout << "\n";
			cin >> name2;
			found = current->find(name2);
			if (found != nullptr) {
				cout << "The object " << form_absolute_path(found)<<" has been deleted";
			}
		}
		else if (name1 == "END") {
			break;
		}
	}
}
void cl_application::creator(cl_base* pointer, string name2, int num) {
	switch (num)
	{
	case 2:
		new sub_class_2(pointer, name2);
		break;
	case 3:
		new sub_class_3(pointer, name2);
		break;
	case 4:
		new sub_class_4(pointer, name2);
		break;
	case 5:
		new sub_class_5(pointer, name2);
		break;
	case 6:
		new sub_class_6(pointer, name2);
		break;
	}
}