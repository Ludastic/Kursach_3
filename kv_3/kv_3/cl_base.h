#ifndef _cl_base_H
#define _cl_base_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class cl_base {
protected:
	string name;
	cl_base * head;
	int ready;
	int static stat;
public:
	vector<cl_base*> pointerSlave;
	cl_base(cl_base* head, string name = "Undefined");
	void setName(string name);
	string getName();
	void getTree();
	void setHead(cl_base* head);
	cl_base* getHead();
	cl_base* findByName(string name);
	void getMarkedTree();
	void setReady(int n);
	void resetReady();
	bool isReady();
	cl_base* find(string name1);
	cl_base* path_find(cl_base* found, string name1);
};
#endif