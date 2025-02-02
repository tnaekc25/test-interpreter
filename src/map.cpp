
#include "trlang.h"




SingleLinkedNode::SingleLinkedNode() {
	key = 0;
	datum = NULL;
	next = NULL;
}

SingleLinkedNode::SingleLinkedNode(TypeObject &to) {
	key = hash(to);
	datum = new TypeObject(to);
	next = NULL;
}

SingleLinkedNode::SingleLinkedNode(const SingleLinkedNode &sn) {
	key = hash(*sn.datum);
    datum = new TypeObject(*sn.datum);
    next = NULL;
}

SingleLinkedNode::~SingleLinkedNode() {
    delete datum;
}

void SingleLinkedNode::insertNode(TypeObject &to) {

	SingleLinkedNode *cn = this;

	while (cn -> next)
		cn = cn -> next;

	cn -> next = new SingleLinkedNode(to);
}

TypeObject *SingleLinkedNode::searchNode(TypeObject &to) {

	unsigned kkey = hash(to);
	SingleLinkedNode *cn = this;

	while (cn) {

		if (cn -> key == kkey)
			break;

		cn = cn -> next;
	}

	return cn -> datum;
}




MapType::MapType (size_t size_) {

	size = size_;
	node_arr = new SingleLinkedNode[size];
}


SingleLinkedNode &MapType::operator[](TypeObject &to) {

	std::cout << hash(to) % size;
}