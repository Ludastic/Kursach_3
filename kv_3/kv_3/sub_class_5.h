#ifndef _SUB_CLASS_5_H//подключение защитных директив
#define _SUB_CLASS_5_H
#include "cl_base.h" //подключение заголовочного файла с базовым классом
using namespace std; //подключение пространства имен
class sub_class_5 : public cl_base { //наследование от базового класса
public:sub_class_5(cl_base* head, string name); //параметризированный конструктор
};
#endif