#pragma once

#include "iostream"


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


