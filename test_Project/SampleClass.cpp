#include "stdafx.h"
#include "SampleClass.h"

template<typename T>
SingleStance<T>::SingleStance() {
	std::cout << "get the real SingleInstance" << std::endl;
	data = 5;
}

template<typename T>
T SingleStance<T>::get_value() {
	return SingleObj->data;
}

template<typename T>
SingleStance<T>* SingleStance<T>::get_instance() {
	if (SingleObj != nullptr)
		return SingleObj;
	else {
		SingleObj = new SingleStance<T>();
		return SingleObj;
	}
}

//c++动态编译，针对类模板时，需要实例化，否则最好写在一个头文件

template class SingleStance<int>;
SingleStance<int>* SingleStance<int>::SingleObj = nullptr;


SetLink::SetLink(Node *head) {
	first = head;
	tail = head;
}
SetLink::SetLink() {
}

int SetLink::getListSize(const SetLink &right) {
	Node *pa = right.first;
	int count = 0;
	while (pa != nullptr) {
		count++;
		pa = pa->link;
	}
	return count;
}

void SetLink::InsertLink(Node *cur) {
	if (this->tail->link == nullptr) {
		this->tail->link = new Node(cur->data);
		this->tail = this->tail->link;
	}
}

void SetLink::printNode() {
	Node *pa = this->first;
	while (pa != nullptr) {
		std::cout << pa->data << "->";
		pa = pa->link;
	}
	if (pa == nullptr) {
		std::cout << "NULL" << std::endl;
	}
}

void SetLink::reverseLinkList(SetLink &right) {
	Node *temp, *pa, *pre = nullptr;
	pa = right.first;
	while (pa != nullptr) {
		temp = pa->link;
		pa->link = pre;
		pre = pa;
		pa = temp;
	}
	right.first = pre;
}

SetLink SetLink::reverseLinkList_internal_n(const SetLink &right, const int &n, const int &totalNum) {
	Node *pa, *pb = nullptr, *pc = nullptr;
	SetLink tempb, tempc;
	pa = right.first;
	int count = 1;
	while (pa != nullptr) {
		if (n > 0) {
			if (count % n != 0) {
				if (tempb.first == nullptr) {
					tempb.first = new Node(pa->data);
					pb = tempb.first;
				}
				else {
					pb->link = new Node(pa->data);
					pb = pb->link;
				}
			}
			if (count % n == 0) {
				pb->link = new Node(pa->data);
				reverseLinkList(tempb);
				pb = tempb.first;
				while (pb != nullptr) {
					if (tempc.first == nullptr) {
						tempc.first = new Node(pb->data);
						pc = tempc.first;
					}
					else {
						pc->link = new Node(pb->data);
						pc = pc->link;
					}
					pb = pb->link;
				}
				tempb.first = nullptr;
			}
			if (totalNum == count) {
				reverseLinkList(tempb);
				pb = tempb.first;
				while (pb != nullptr) {
					if (tempc.first == nullptr) {
						tempc.first = new Node(pb->data);
						pc = tempc.first;
					}
					else {
						pc->link = new Node(pb->data);
						pc = pc->link;
					}
					pb = pb->link;
				}
				tempb.first = nullptr;
			}
			pa = pa->link;
			count++;
		}
	}
	return tempc;
}


