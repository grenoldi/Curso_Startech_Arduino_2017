#include "Arduino.h"
#include "node.h"


Node::Node(int val){
	this->_val = val;
	this->_prox = NULL;
}

int Node::getValue(){
	return _val;
}

Node* Node::getProx(){
	return _prox;
}

void Node::setProx(Node* n){
	_prox = n;
}
