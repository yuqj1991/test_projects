// test_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "memory"
#include "iostream"
#include "string.h"
#include "assert.h"
#include "malloc.h"
#include "SampleClass.h"
#include "utils.h"
using namespace std;

void test_SingleInstance() {
	SingleStance<int> *obj = SingleStance<int>::get_instance();
	std::cout << "SingleInstance: " << obj->get_value();
	std::cout << std::endl;
}

void test_reverse_List() {
	Node a(1);
	SetLink Seta(&a);
	for (int i = 2; i <= 10; i++) {
		Node temp(i);
		Seta.InsertLink(&temp);
	}
	Seta.printNode();
	int totalNum = SetLink::getListSize(Seta);
	SetLink Setb = SetLink::reverseLinkList_internal_n(Seta, 4, totalNum);
	std::cout << "reverse_3_start!" << std::endl;
	Setb.printNode();
}

void test_point_position() {
	int a = 15;
	int b = 20;
	const int *p = &a; // const 修饰的是int, (*p = 20;(illeagal))
	std::cout << p << ", " << *p << std::endl;
	p = &b;
	std::cout << p << ", " << *p << std::endl;
	int* const p2 = &a; // const 修饰的是 p2指针地址, (p2 = &b;(illeagal))
	std::cout << p2 << ", " << *p2 << std::endl;
	*p2 = 30;
	std::cout << p2 << ", " << *p2 << std::endl;
}


void test_algra() {
	int data[16] = { 1, 4, 2, 2, 3, 3, 4, 5, 7, 7, 3, 6, 5, 4, 2, 8 };
	int value = det_linear_algera(data, 4, 4);
	std::cout << "det a: " << value << endl;
}

void test_SetUnorderList() {
	SetUnorderList<int> set_a, set_b, set_c, set_d, set_f;
	for (int i = 1; i <= 10; i++) {
		bool add = set_a.AddMember(i);
		if (!add) {
			std::cout << "can not the number of " << i << " in the set_a" << std::endl;
		}
		bool bdd = set_b.AddMember(2 * i);
		if (!bdd) {
			std::cout << "can not the number of " << 2 * i << " in the set_b" << std::endl;
		}
	}
	std::cout << "print original set_a & set_b" << std::endl;
	set_a.printNode();
	set_b.printNode();
	std::cout << "print set_a + set_b" << std::endl;
	set_c = set_a + set_b;
	set_c.printNode();
	std::cout << "print set_a * set_b" << std::endl;
	set_d = set_a * set_b;
	set_d.printNode();
	std::cout << "print set_a - set_b" << std::endl;
	set_f = set_a - set_b;
	set_f.printNode();
	std::cout << "print del member in set_a" << std::endl;
	bool del = set_a.DelMember(6);
	set_a.printNode();
}

int main()
{
	/*
	int *temp =new int[5];
	for (int i = 0; i < 5; i++) {
		temp[i] = i*2 + 1;
	}
	shared_ptr<int> test_a(temp);
	int* temp_a = test_a.get();
	for (int i = 0; i < 5; i++) {
		std::cout << temp_a[i] << std::endl;
		std::cout << *(test_a) << std::endl;
	}
	shared_ptr<string> test_b(new string("laaaaaaaaaaaa"));
	string* name = new string("abcedefg");
	std::cout << name->data() << std::endl;
	printf("%s\n", test_b->data());
	*/	

	//char output[60];
	//continumax(output, "adbcf435dfg543034fgr0123456778");

	//test_point_position();
	//test_reverse_List();
	//test_SingleInstance();
	test_SetUnorderList();
	getchar();
    return 0;
}

