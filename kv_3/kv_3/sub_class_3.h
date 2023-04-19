#ifndef _SUB_CLASS_3_H//подключение защитных директив
#define _SUB_CLASS_3_H
#include "cl_base.h" //подключение заголовочного файла с базовым классом
using namespace std; //подключение пространства имен
class sub_class_3 : public cl_base { //наследование от базового класса
public:sub_class_3(cl_base* head, string name); //параметризированный конструктор
};
#endif