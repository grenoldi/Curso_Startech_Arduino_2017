#ifndef node_h
#define node_h

#include "Arduino.h"

class Node{
	public:
		Node(int val);
		int getValue();
		Node* getProx();
		void setProx(Node* n);
	private:
		Node* _prox;
		int _val;
};

#endif
