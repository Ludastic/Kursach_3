#ifndef _SUB_CLASS_2_H//подключение защитных директив
#define _SUB_CLASS_2_H
#include "cl_base.h" //подключение заголовочного файла с базовым классом
using namespace std; //подключение пространства имен
class sub_class_2 : public cl_base { //наследование от базового класса
public:sub_class_2(cl_base* head, string name); //параметризированный конструктор
};
#endif