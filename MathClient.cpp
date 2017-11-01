// MathClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>   
#include "ObjectsLibrary.h"   
/*#include "ObjectsLibrary.cpp" */  

using namespace std;

int main()
{
	/*ObjectsLibrary::Node_1<int> node(5);
	node.print();*/
	/*double a = 7.4;
	int b = 99;*/


	ObjectsLibrary::List_1<double> list;
	ObjectsLibrary::List_1<double> list1;
	list1.push(1, 9);
	list1.push(-2, 8);
	/*list.push_neck(28);*/
	//list.push_neck(28);
	//list.push_back(32);
	//list.push(1, 9);
	//list.push(-2, 8);
	//list.push(0, 7);
	list.push(3, 10);
	list.push(5, 11);
	list.push(7, 25);

	list.pop(0);
	list.pop(-2);
	list.pop(3);
	list.pop(1);
	list.pop(2);
	list.pop(7);

	list.push_list(list1);
	//list.pop_neck();

	list.print();
	list.reverse();
	list.print();

	list.sort();
	list.print();



	cout << endl;
	ObjectsLibrary::List_2<double> list2;
	ObjectsLibrary::List_2<double> list3;
	list3.push(1, 9);
	list3.push(-2, 8);
	//list2.push_neck(28);
	//list2.push_neck(28);
	//list2.push_back(32);
	list2.push(1, 9);
	list2.push(-2, 8);
	list2.push(0, 7);
	list2.push(3, 10);
	list2.push(5, 11);
	list2.push(7, 25);

	//list2.pop(0);
	//list2.pop(-2);
	//list2.pop(3);
	//list2.pop(1);
	//list2.pop(2);
	//list2.pop(7);

	list2.push_list(list3);
	//list.pop_neck();

	list2.print();
	list2.reverse();
	list2.print();

	list2.sort();
	list2.print();

	system("pause");
	return 0;
}
