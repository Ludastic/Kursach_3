#ifndef _CL_APPLICATION_H
#define _CL_APPLICATION_H
#include "cl_base.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class cl_application : public cl_base
{
	using cl_base::cl_base;
private:
	void readiness();
	void creator(cl_base* pointer, string name2, int num);
	void commands();
public:
	void build_tree_objects();
	int exec_app();
	string form_absolute_path(cl_base* pointer);
};
#endif