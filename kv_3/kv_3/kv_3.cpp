#include <iostream>
#include "cl_base.h"
#include "cl_application.h"
using namespace std;
int main()
{
	cl_application ob_cl_application(nullptr);
	ob_cl_application.build_tree_objects();//Построение дерева объектов
	return ob_cl_application.exec_app(); //запуск системы
}