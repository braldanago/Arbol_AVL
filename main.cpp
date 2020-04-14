//BRAYAN STEVEN ALDANA GOMEZ 20152020042
//DIEGO DAYAN GUERRA 20152020024

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>


using namespace std;

struct Nodo{
	int bal;//VALOR A TENER EN CUENTA PARA EL ARBOL AVL
	int dato;
	Nodo *izq;
	Nodo *der;
};

//////////////////*/*/ ARBOL BINARIO DESORDENADO /*/*/*//////////////////////
class ArbolBinario{
	protected: Nodo *raiz;
	
	//Metodos
	public:
	ArbolBinario();
	Nodo *agregar(Nodo *, int);//agrega un nodo al arbol
	int eliminar();///elimina una hoja al azar y retorna el elemento eliminado
	void mostrarPreorden(Nodo *);//muestra en preorden el arbol
	void mostrarInorden(Nodo *);	//muestra en inorden el arbol
	void mostrarPostorden(Nodo *);//muestra en postorden el arbol
	void mostrarNiveles(Nodo *);	//muestra los niveles que conforman el arbol
	int profundidad();
	int contarHojas(Nodo *);
	Nodo *buscar(Nodo *,int);//busca recursivamente algun nodo en el arbol
	Nodo *getRaiz();//getter raiz
	void setRaiz(Nodo *);//setter raiz
			
};

ArbolBinario::ArbolBinario(){//constructor de la clase ArbolBinario
	raiz=NULL;
}

Nodo *ArbolBinario::getRaiz(){
	return raiz;
}

void ArbolBinario::setRaiz(Nodo *raiz){
	this->raiz=raiz;
}

Nodo * ArbolBinario::agregar(Nodo *raiz, int dato){//Metodo para agregar nodos al arbol
	if(raiz){
		int rama=rand()%2;
		if(rama==0){
			raiz->izq=agregar(raiz->izq,dato);
		}else{
			raiz->der=agregar(raiz->der,dato);
		}
	}else{
		raiz= new Nodo;
		raiz->dato=dato;
		raiz->izq=NULL;
		raiz->der=NULL;
	}
	return raiz;
} 

void ArbolBinario::mostrarPreorden(Nodo *raiz){//Metodo para mostrar en preorden el arbol ingresado
	if(raiz){
		cout<<raiz->dato<<" ";
		mostrarPreorden(raiz->izq);
		mostrarPreorden(raiz->der);
	}
	
}

void ArbolBinario::mostrarInorden(Nodo *raiz){//Metodo para mostrar en inorden el arbol ingresado
	if(raiz){
		mostrarInorden(raiz->izq);
		cout<<raiz->dato<<" ";
		mostrarInorden(raiz->der);
	}
	
}

void ArbolBinario::mostrarPostorden(Nodo *raiz){//Metodo para mostrar en postorden el arbol ingresado
	if(raiz){
		mostrarInorden(raiz->izq);
		mostrarInorden(raiz->der);
		cout<<raiz->dato<<" ";
	}
}

Nodo * ArbolBinario::buscar(Nodo *raiz, int dato){//Metodo para buscar un nodo en el arbol
	Nodo *valor;
	if(raiz){
		valor=buscar(raiz->izq,dato);
		if(raiz->dato==dato){
			return raiz;
		}else if (valor){
			return valor;	
		}else {
			return buscar(raiz->der,dato);
		}
	}else{
		return NULL;
	}
}

int ArbolBinario::eliminar(){//Metodo que elimina algun nodo del arbol al azar
	Nodo *raiz = this->raiz;
	Nodo *aux,*aux2;
	int dato;
	int rama=rand()%2;
	if(raiz && (raiz->izq || raiz->der)){
		while(raiz->izq || raiz->der){
			rama=rand()%2;
			aux2=raiz;
			if((raiz->izq)==NULL){
				aux=raiz->der;
				rama=1;
			}else if((raiz->der)==NULL){
				aux=raiz->izq;
				rama=0;
			}else if(rama==0){
				aux=raiz->izq;
				cout<<"izq"<<aux2->dato<<endl;
			}else{
				aux=raiz->der;
				cout<<"der"<<aux2->dato<<endl;
			}
			raiz=aux;
		}
		if(rama==0){
			aux2->izq=NULL;
		}else{
			aux2->der=NULL;
		}
		dato=raiz->dato;
		delete aux;
		return dato;
	}else if(raiz){
		dato=raiz->dato;
		this->raiz=NULL;
		return dato;
	}
	return -1;
}

void ArbolBinario::mostrarNiveles(Nodo *raiz){//Metodo que muestra los niveles del arbol
	queue<Nodo> cola;
	int levelNodes;
	Nodo *n;
	cola.push(*raiz);
	while(!cola.empty()){
		levelNodes = cola.size();
		while(levelNodes>0){
			n = &cola.front();
			cola.pop();
			cout<<" "<<n->dato;
			if(n->izq!=NULL){
				cola.push(*n->izq);
			}
			if(n->der!=NULL){
				cola.push(*n->der);
			}
			if(n->izq==NULL && n->der==NULL){
				cout<<".";				
			}
			levelNodes--;
		}	
		cout<<endl;	
	}
	
	
//	Nodo *aux;
//	cola.push(*raiz);
//	while(!cola.empty()){
//		aux=&cola.front();
//		cout<<aux->dato<<" ";
//		if(aux->izq!=NULL){
//			cola.push(*aux->izq);
//			cout<<" "<<endl;
//		}
//		if(aux->der!=NULL){
//			cola.push(*aux->der);
//			cout<<" "<<endl;
//		}
//		
//		cola.pop();
//		
//	}
}

int ArbolBinario::contarHojas(Nodo *raiz){//Metodo para mostrar en inorden el arbol ingresado
	if(raiz){
		if(raiz->izq==NULL && raiz->der==NULL){
			return 1;
		}
		else{
			return contarHojas(raiz->izq)+contarHojas(raiz->der);
		}		
	}	
}


int ArbolBinario::profundidad(){//Metodo para mostrar en inorden el arbol ingresado
	if(raiz){
		if(raiz->izq==NULL && raiz->der==NULL){
			return 1;
		}
		else{
			return contarHojas(raiz->izq)+contarHojas(raiz->der);
		}		
	}	
}

////////////////////////    CLASE ARBOL BINARIO ORDENADO     /////////////////////////////
class ArbolBinOrd :public ArbolBinario{
	
	public:
	ArbolBinOrd();
	Nodo * agregar(Nodo *,int);//agrega un nuevo nodo para el arbol ordenado
	Nodo * buscar(Nodo *,int);//busca recursivamente un nodo para un arbol orndenado
	Nodo * buscar(int);//busca iterarivamente un nodo en el arbol ordenado
	
};

ArbolBinOrd::ArbolBinOrd(){
	raiz=NULL;
}

Nodo *ArbolBinOrd::agregar(Nodo *raiz, int dato){//Metodo que agrega un nuevo nodo al arbol ordenado
	if(raiz){
		if(raiz->dato>dato){
			raiz->izq=agregar(raiz->izq,dato);
		}else{
			raiz->der=agregar(raiz->der,dato);
		}
	}else{
		raiz= new Nodo;
		raiz->dato=dato;
		raiz->izq=NULL;
		raiz->der=NULL;
	}
	return raiz;
}

Nodo *ArbolBinOrd::buscar(Nodo *raiz, int dato){///Método que busca un nodo recursivamente ////
	if(raiz){
		if(raiz->dato==dato){
			return raiz;
		}else if(raiz->dato>dato){
			return buscar(raiz->izq,dato);
		}else{
			return buscar(raiz->der,dato);
		}
	}
	return raiz;
}

Nodo *ArbolBinOrd::buscar(int dato){//////Método que busca un nodo iterarivamente en el arbol
	Nodo *p=this->raiz;
	while(p){
		if(p->dato==dato){
			return p;
		}else if(p->dato>dato){
			p=p->izq;
		}else{
			p=p->der;
		}
	}
	return p;
}

/// /// FIN CLASE ARBOL BINARIO ORDENADO /// ///*/*/*/*/*//**/*/*/*/*/*/*/*/*/*/


/// CLASE ARBOL AVL////
class ArbolAVL :public ArbolBinOrd{
	
	public:
	ArbolAVL();
	Nodo *agregar(Nodo *,int);//agrega un nuevo nodo para el arbol ordenado
	void rotacionIzq(Nodo *,Nodo *);
	void rotacionDer(Nodo *,Nodo *);
	void dobleRotacionIzq(Nodo *, Nodo **);
	void dobleRotacionDer(Nodo *, Nodo **);
	
};

ArbolAVL::ArbolAVL(){
	raiz=NULL;
}

void ArbolAVL::rotacionDer(Nodo *p, Nodo*q){
	p->bal=0;
	p->bal=0;
	p->izq=q->der;
	q->der=p;
}

void ArbolAVL::rotacionIzq(Nodo *p,Nodo *q){
	p->bal=0;
	q->bal=0;
	p->der=q->izq;
	q->izq=p;	
}

void ArbolAVL::dobleRotacionIzq(Nodo *p, Nodo **q){
	Nodo *r;
	r=(*q)->izq;
	(*q)->izq=r->der;
	r->der=*q;
	p->der=r->izq;
	r->izq=p;
	switch(r->bal){
		case -1:
			(*q)->bal=0;
			p->bal=1;
			break;
		case 1:
			(*q)->bal=-1;
			p->bal=0;
			break;
		case 0:
			(*q)->bal=p->bal=0;
			break;
	}
	r->bal=0;
	*q=r;
}

void ArbolAVL::dobleRotacionDer(Nodo *p, Nodo **q){
	Nodo *r;
	r=(*q)->der;
	(*q)->der=r->izq;
	r->izq=r->der;
	p->izq=r->der;
	r->der=p;
	switch(r->bal){
		case -1:
			(*q)->bal=1;
			p->bal=0;
			break;
		case 1:
			(*q)->bal=0;
			p->bal=-1;
			break;
		case 0:
			(*q)->bal=p->bal=0;
			break;
	}
	r->bal=0;
	*q=r;
}


	
Nodo *ArbolAVL::agregar(Nodo *raiz, int dato) {
	Nodo *nuevo, *p,*q,*s,*pivote,*pp;
	int llave, altura;
	
	nuevo = new Nodo;
	nuevo->dato=dato;
	(nuevo)->bal=0;
	(nuevo)->izq=NULL;
	(nuevo)->der=NULL;
	if(raiz==NULL){
		raiz= nuevo;
		return raiz;
	}
	pp=q=NULL;
	pivote = raiz;
	p=raiz;
	llave = nuevo->dato;
	while(p!=NULL){
		if(p->bal){
			pp=q;
			pivote=p;
		}
		if(llave == p->dato){
			free(nuevo);
			return(raiz);
		}
		else{
			q=p;
			if(llave < p->dato){
				p=p->izq;				
			}			
			else{
				p=p->der;
			}
		}
	}
	if(llave < q->dato){
		q->izq=nuevo;
	}
	else{
		q->der=nuevo;
	}
	if(llave < pivote->dato){
		s=pivote->izq;
		altura=1;		
	}
	else{
		s=pivote->der;
		altura=-1;
	}
	p=s;
	while(p!=nuevo){///mitad
		if(llave < p->dato){
			p->bal=1;
			p=p->izq;
		}
		else{
			p->bal=-1;
			p=p->der;
		}		
	}
	if(pivote->bal==0){
		pivote->bal=altura;
	}
	else{
		if(pivote->bal+altura ==0){
			pivote->bal=0;
		}
		else{
			if(altura==1){
				if(s->bal ==1){
					rotacionDer(pivote,s);					
				}
				else{
					dobleRotacionDer(pivote,&s);
				}
			}
			else{
				if(s->bal==-1){
					rotacionIzq(pivote,s);
				}
				else{
					dobleRotacionIzq(pivote,&s);
				}
			}
			if(pp==NULL){
				raiz=s;
			}
			else{
				if(pp->izq == pivote){
					pp->izq =s;
				}
				else{
					pp->der=s;
				}
			}
		}	
	}
	return raiz;	
} 

// FIN CLASE AVL//


char menu();//Método para el menu principal

//    //    MAIN    //   //

int main(int argc, char** argv) {
	srand(time(NULL));
	int opcion,dato;
	Nodo *raiz,*resultado;
	//ArbolBinario arbol;
	//ArbolBinOrd arbol;
	ArbolAVL arbol;
	do{
		opcion=menu();
		switch(opcion){
			case 'a':
			case 'A':{//Opcion agregar
				cout<<"Digite el elemento: ";
				cin>>dato;
				raiz=arbol.getRaiz();
				arbol.setRaiz(arbol.agregar(raiz,dato));
				break;
			}
			case 'b':
			case 'B':{//Opcion buscar
				
				cout<<"Digite el elemento a buscar: ";
				cin>>dato;
				resultado=arbol.buscar(raiz,dato);
				if(resultado){
					cout<<"El valor fue encontrado"<<endl;
				}else{
					cout<<"El valor no fue encontrado\n"<<endl;
				}
				//resultado=arbol.buscar(dato);
				if(resultado){
					cout<<"El valor fue encontrado iterativamente"<<endl;
				}else{
					cout<<"El valor no fue encontrado iterativamente\n"<<endl;
				}
				break;
			}
			case 'm'://Opcion mostrar
			case 'M':{
				raiz=arbol.getRaiz();
				cout<<"Arbol en preorden: ";
				arbol.mostrarPreorden(raiz);
				
				cout<<"\nArbol en inorden: ";
				arbol.mostrarInorden(raiz);
				
				cout<<"\nArbol en postorden: ";
				arbol.mostrarPostorden(raiz);
				break;
			}
			case 'e'://Opcion eliminar
			case 'E':{
				int resultado =arbol.eliminar();
				if(resultado!=(-1)){
					cout<<"Se eliminara una hoja: "<<resultado<<endl;	
				}else{
					cout<<"No hay elementos en el arbol"<<endl;
				}
				break;
			}
			case 'h'://Opcion eliminar
			case 'H':{
				cout<<"La cantidad de hojas del arbol es: ";
				cout<<arbol.contarHojas(raiz);
				break;
			}
			case 'n':
			case 'N':{//Opcion mostrar niveles
				raiz=arbol.getRaiz();
				cout<<"Niveles del arbol: "<<endl;
				arbol.mostrarNiveles(raiz);
				break;
			}
		}
	}while(opcion != 't' && opcion != 'T');   
		
	return 0;
}

char menu(){//MENU PRINCIPAL
	char opcion;
	cout<<"\nBienvenido, seleccione una opcion: \n"<<endl;
	cout<<"(A)gregar"<<endl;
	cout<<"(M)ostrar"<<endl;
	cout<<"(B)uscar"<<endl;
	cout<<"(E)liminar"<<endl;
	cout<<"Mostrar (N)iveles"<<endl;
	cout<<"(P)rofundidad"<<endl;
	cout<<"(C)antidad de nodos"<<endl;
	cout<<"Cantidad de (H)ojas"<<endl;
	cout<<"(T)erminar"<<endl;
	cin>>opcion;
	return opcion;
}
