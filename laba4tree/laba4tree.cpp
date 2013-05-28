#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;
class tree
{
int value; //Значение элемента
tree *left, *right; // Указатели вправо и влево.
static tree* create(int *begin, int *end, int *min, int *max) //Функция создания дерева.
{
int count=end-begin; //Проверка на пустоту
if(count<0) 
return 0; 
int n=count/2; 
int *mid=begin+n;
tree *t=new tree(*mid); //Создаем указатель на элемент типа "дерево"
if(mid!=min) // Если элемент не равен минимальному, то отсылаем его налево.
{
t->left=create(begin, mid-1, min, max);
}
if(mid!=max) // Если элемент не равен минимальному, то отсылаем его направо.
{
t->right=create(mid+1, end, min, max);
}
return t;
}
void out(char* str) // Вывод элементов
{
if (left) // Если есть указатель на лево, то мы создаем строку.
{
char *s=new char[strlen(str)+3];
strcpy(s, str); // Копируем строку
strcat(s, " "); 
left->out(s); // Делаем рекурсию, чтобы в строке были все элементы.
delete []s; // Удаляем из памяти, чтобы не занимать лишнего.
}
cout << str << value << endl; // Выводим, что получилось.
if (right) // Функция по аналогии с выводом слева.
{
char *s=new char[strlen(str)+3]; //выводим отображение
strcpy(s, str);
strcat(s, " ");
right->out(s);
delete []s;
}
}
public:
tree(int val) // Начальная инициализация элементов дерева.
{
value=val;
left=0;
right=0;
}
static tree* create(int* begin, int* end) // Делаем функцию публичной.
{
return create(begin, end, begin, end);
}
void out() // Делаем вывод публичным
{
out("");
}
};
int *array; //задаем массив
tree* tr; //задаем наше дерево


int main() //Главная функция
{
int len, a; // объявление переменной кол-ва элементов и удаляемого в будущем элемента
cout<<"Enter the number of elements: ";
cin>>len;
array=new int[len];
for(int i=0;i<len;i++) // Создание динамического массива и его инициализация.
{
cout<<"Enter the value of element #"<<i+1<<": ";
cin>>array[i];
}
tr=tree::create(array, array+len-1); // Заполняем дерево
tr->out(); // Вывод нашего дерева
delete tr; // Очищение дерева
cout<<"Enter delete elem:"<<endl;
cin>>a; //Вводим номер элемента, который будем удалять
for(int i=0;i<len;i++)
{
if(array[i]==a) //Вставляем вместо него нулевое значение
array[i]=0;
}
cout<<"Tree without this elem "<<a<<":"<<endl;
tr=tree::create(array, array+len-1); // Снова заполняем дерево
tr->out(); // Выводим получившееся. 
getch();
delete[] array;
system("pause");
}

