#include "Arduino.h"
#include "lista.h"
#include "node.h"

Lista::Lista(){
	ini = NULL;
	fim = NULL;
}

Lista::Lista(int val){
	ini = new Node(val);
	fim = ini;
}

bool Lista::vazia(){
	return(ini == NULL);
}

void Lista::inserirFim(int val){
	Node* novo_no = new Node(val);
	
	if(vazia()){
		ini = novo_no;
		fim = novo_no;
	}
	
	else{
		fim->setProx(novo_no);
		fim = novo_no;
	}
}

int Lista::tamanho(){
	if(vazia()) return 0;
	
	Node* c = ini;
	int size = 0;
	
	do{
		c = c->getProx();
		size++;
	}
	while (c);
	
	return size;
}

void Lista::remover(){
	if(!vazia()){
		if(ini->getProx() == NULL)
			ini = NULL;
		else if(ini->getProx()->getProx()==NULL)
			ini = NULL;
		else{
			Node* ant = ini->getProx();
			Node* ant2 = ini;
			Node* corrente = ini->getProx()->getProx();
			while(corrente){
				Node* aux = ant;
				ant = corrente;
				ant2 = aux;
				corrente = corrente->getProx();
			}
			delete ant2->getProx();
			ant2->setProx(NULL);
			fim = ant2;
		}
	}
}
