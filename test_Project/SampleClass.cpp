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

INSTANCE_CLASS(SingleStance);
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

template<class T>
SetUnorderList<T> SetUnorderList<T>::operator+(const SetUnorderList<T> &right) {
	SetUnorderList<T> temp;
	SetNode<T> *pb = right.first;
	SetNode<T> *pa = first;
	SetNode<T> *pc = nullptr;
	while (pa != nullptr){
		if (temp.first == nullptr) {
			temp.first = new SetNode<T>(pa->data);
			pc = temp.first;
		}else {
			pc->link = new SetNode<T>(pa->data);
			pc = pc->link;
		}
		pa = pa->link;
	}
	while (pb != nullptr) {
		pa = first;
		while ((pa != nullptr) && (pa->data != pb->data)) pa = pa->link;
		if (pa == nullptr) {
			pc->link = new SetNode<T>(pb->data);
			pc = pc->link;
		}
		pb = pb->link;
	}
	return temp;
}

template<class T>
SetUnorderList<T> SetUnorderList<T>::operator-(const SetUnorderList<T> &right) {
	SetNode<T> *pa, *pb, *pc = nullptr, *pre = nullptr;
	SetUnorderList<T> temp;
	pa = first;
	while (pa != nullptr) {
		if (temp.first == nullptr) {
			temp.first = new SetNode<T>(pa->data);
			pc = temp.first;
		}
		else {
			pc->link = new SetNode<T>(pa->data);
			pc = pc->link;
		}
		pa = pa->link;
	}
	pc = temp.first;
	pb = right.first;
	while (pb != nullptr) {
		while (pc != nullptr && (pc->data != pb->data)) {
			pre = pc;
			pc = pc->link;
		}
		if (pc != nullptr) {
			SetNode<T> *temp_c = pc->link;
			pre->link = temp_c;
		}
		pb = pb->link;
	}
	return temp;
}

template<class T>
SetUnorderList<T> SetUnorderList<T>::operator*(const SetUnorderList<T> &right) {
	SetNode<T> *pa, *pb, *pc = nullptr;
	SetUnorderList<T> temp;
	pa = first;
	while (pa!=nullptr) {
		pb = right.first;
		while (pb != nullptr) {
			if (pa->data == pb->data) {
				if (temp.first == nullptr) {
					temp.first = new SetNode<T>(pa->data);
					pc = temp.first;
				}
				else {
					pc->link = new SetNode<T>(pa->data);
					pc = pc->link;
				}
			}
			pb = pb->link;
		}
		pa = pa->link;
	}
	return temp;
}

template<class T>
bool SetUnorderList<T>::Contains(const T &value) {
	SetNode<T> *pa;
	pa = first;
	bool contain = false;
	while (pa != nullptr) {
		if (pa->data == value) {
			contain = true;
			break;
		}
	}
	return contain;
}

template<class T>
bool SetUnorderList<T>::AddMember(const T &value) {
	if (first == nullptr) {
		first = new SetNode<T>(value);
		tail = first;
	}else {
		if (tail->link == nullptr) {
			tail->link = new SetNode<T>(value);
			tail = tail->link;
		}
	}
	if (tail != nullptr) {
		return true;
	}else {
		return false;
	}
}

template<class T>
bool SetUnorderList<T>::DelMember(const T &value) {
	SetNode<T> *pa = nullptr, *pre = nullptr, *temp = nullptr;
	bool del = false;
	if (first->data == value) {
		pa = first->link;
		first = pa;
		return true;
	}
	pa = first;
	while (pa != nullptr) {
		if (pa->data != value) {
			pre = pa;
			pa = pa->link;
		}else {
			temp = pa->link;
			pre->link = temp;
			del = true;
			break;
		}
	}
	return del;
}

template<class T>
void SetUnorderList<T>::printNode() {
	SetNode<T>* pa = first;
	while (pa != nullptr) {
		std::cout << pa->data << "->";
		pa = pa->link;
	}
	if (pa == nullptr)
		std::cout << "NULL" << std::endl;
}

template<class T>
T SetUnorderList<T>::min() {
	T min = first->data;
	SetNode<T> *pa = first;
	while (pa != nullptr) {
		if (min < pa->data) min = pa->data;
		pa = pa->link;
	}
	return min;
}

template<class T>
bool SetUnorderList<T>::make_empty() {
	SetNode<T> *pa = first->link, *temp = nullptr;
	while (pa != nullptr) {
		temp = pa->link;
		delete pa;
		pa = temp;
	}
	if (first->link == nullptr)
		return true;
}

INSTANCE_CLASS(SetUnorderList);