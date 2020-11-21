#pragma once

#include "iostream"


#define INSTANCE_CLASS(classname) template class classname<int>

template<typename T>
class SingleStance {
public:
	static SingleStance<T>* get_instance();
	T get_value();
private:
	SingleStance();
	static SingleStance<T> *SingleObj;
	T data;
};

typedef struct _Node {
	int data;
	_Node *link;
	_Node(int value) :data(value), link(nullptr) {};
}Node;

class SetLink {
public:
	static void reverseLinkList(SetLink &right);
	static SetLink reverseLinkList_internal_n(const SetLink &right, const int &n, const int &totalNum);
	static int getListSize(const SetLink &right);
	SetLink(Node *head);
	SetLink();
	void InsertLink(Node *cur);
	void printNode();

private:
	Node *first;
	Node *tail;
};

template<class T>
struct SetNode
{
	T data;
	SetNode<T> *link;
	SetNode(const T &value) :data(value), link(nullptr) {}
};

template <class T>
class SetUnorderList {
private:
	SetNode<T>* first;
	SetNode<T>* tail;
public:
	SetUnorderList<T> operator + (const SetUnorderList<T> &right);
	SetUnorderList<T> operator - (const SetUnorderList<T> &right);
	SetUnorderList<T> operator * (const SetUnorderList<T> &right);
	bool Contains(const T &value);
	bool AddMember(const T &value);
	bool DelMember(const T &value);
	bool make_empty();
	T min();
	void printNode();
	SetUnorderList() {}
	/*~SetUnorderList() {
		make_empty();
		if (first != nullptr) {
			delete first;
		}
	}*/
};


