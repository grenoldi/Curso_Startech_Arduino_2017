#ifndef lista_h
#define lista_h

#include "Arduino.h"
#include "node.h"
class Lista{
	public:
		Lista();
		Lista(int val);
		bool vazia();
		int tamanho();
		void inserirFim(int val);
		void remover();
		Node * ini;
		Node * fim;		


};

#endif
