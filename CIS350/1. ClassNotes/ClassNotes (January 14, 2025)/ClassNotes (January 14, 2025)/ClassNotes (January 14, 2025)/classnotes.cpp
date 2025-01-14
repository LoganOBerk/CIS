#include <iostream>
struct Node {
	int elm;
	Node* next;
};

class List {
public:
	Node* first = nullptr;
};

//more convaluted
Node* findNodeC(List& l, int e) {
	Node* v = l.first;
	while (v != NULL) {
		if (v->elm == e) {
			return v;
		}
		v = v->next;
	}
	return NULL;
}

//simplified
Node* findNodeS(List& l, int e) {
	Node* v = l.first;
	while (v != NULL && v->elm != e) {
		v = v->next;
	}
	return v;
}

//recursive
Node* findNodeAux(Node* v, int e) {
	if (v == NULL) {
		return NULL;
	}
	if (v->elm == e) {
		return v;
	}
	findNodeAux(v->next, e);
}

//simplified recursive
Node* findNodeAuxS(Node* v, int e) {
	if (v == NULL || v->elm == e) {
		return v;
	}
	return findNodeAuxS(v->next, e);
}

Node* findNodeR(List& l, int e) {
	return findNodeAux(l.first, e);
}
int main() {


	return 0;
}