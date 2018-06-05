#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <conio.h> 
//Arbol Binario 


using namespace std; 

//Se define el nodo del árbol, con un campo info y dos enlaces 

struct nodo {
	int info;
	struct nodo *EI;
	struct nodo *ED;
}; 

nodo *raiz;
nodo *aux; 

void iniciar() {
	raiz=NULL;
	aux=NULL;
} 
int vacia() { 
	if (raiz==NULL)
		return 1;
	else
		return 0;
} 

void Insertar_Raiz(int valor) {
	if (vacia()){
		raiz = new nodo;
		raiz->info=valor;
		raiz->EI=NULL;
		raiz->ED=NULL;
		
	}
}
void Insertar(int valor)
{ nodo *nuevonodo, *p, *s;
nuevonodo = new nodo;
nuevonodo->info=valor;
nuevonodo->EI=NULL;
nuevonodo->ED=NULL;

if (vacia())
{
	raiz=nuevonodo;
}
else
	{ p=raiz;
	while (p!=NULL)
	{
		if (valor>p->info)
		{
			s=p;
			p=p->ED;
		}
		else
		{
			s=p;
			p=p->EI;
		}
	}
	if (valor > s->info)
		s->ED=nuevonodo;
	else
		s->EI=nuevonodo;
	}
}
nodo *obreemplazo(nodo *rem){
	nodo *reemplazarpadre=rem;
	nodo *reemplazo=rem;
	nodo *aux=rem->ED;
	while(aux!=NULL){
		reemplazarpadre=reemplazo;
		reemplazo=aux;
		aux=aux->EI; 
		
	}
	if(reemplazo!= rem->ED){
		reemplazarpadre->EI=rem->ED;
		reemplazo->ED=rem->ED;
	}
	cout<<"El nodo reemplazo es :"<<reemplazo;
	return reemplazo;
}
bool borrar(int valor){
	nodo *aux=raiz;
	nodo *padre=raiz;
	bool EI=true;
	while(aux->info!= valor){
		padre=aux;
		if(valor < aux->info){
			EI=true;
			aux=aux->EI;
		}else{
			EI=false;
			aux=aux->ED;
		}
		if(aux==NULL){
			return false;
		}
	}
	if(aux->EI==NULL&& aux->ED==NULL){
		if(aux==raiz){
			raiz=NULL;
		}else if(EI){
			padre->EI=NULL;
		}else{
			padre->ED=NULL;
		}
	}else if(aux->ED==NULL){
		if(aux==raiz){
			raiz=aux->EI;
		}else if(EI){
			padre->EI=aux->EI;
		}else{
			padre->ED=aux->EI;
		}
	}else if(aux->EI==NULL){
		if(aux==raiz){
			raiz=aux->ED;
		}else if(EI){
			padre->EI=aux->ED;
		}else{
			padre->ED=aux->EI;
		}
	}else{
		nodo *reemplazo=obreemplazo(aux);
		if(aux== raiz){
			raiz=reemplazo;
			
		}else if(EI){
			padre->EI=reemplazo;
		}else{
			padre->ED=reemplazo;
		}
		reemplazo->EI=aux->EI;
	}
	return true;
}


void buscar(nodo *r, int nombre) {
	if ((r != NULL)){
		if (r->info == nombre)   {
			aux=r;
		}
		else {
			buscar(r->EI, nombre);
			buscar(r->ED, nombre);
		}
	}
	return;
}

int main(int argc, char *argv[])  { 
	int cod, nombre;
	int opc;
	int cont=0;
	int grado=0;
	iniciar();
	do{
		system("cls");
		system("color B");
		cout<<"           ARBOL BINARIO"<<endl;
		cout<<"      Seleccione la opcion a realizar\n\n"; 
		cout<<"    1.- Insertar la raiz\n"; 
		cout<<"    2.- Mostrar la raiz\n"; 
		cout<<"    3.- Insertar valor en le ARBOL DE BUSQUEDA\n";
		cout<<"    4.- Eliminar un nodo del arbol\n"; 
		cout<<"    5.- Mostrar cantidad de hijos de un determinado nodo\n";
		cout<<"    6.- Mostrar el grado de un determinado nodo\n";
		cout<<"    7.- Salir";
		cout<<"      \n\n\nOpcion(1-7): ";
		cin>>opc;
		switch(opc)   {
		case 1:
			
			cout<<"Ingrese el valor a insertar en la raiz:\n ";
			cin>>cod;
			Insertar_Raiz(cod);	
			system("pause");
			break;
		case 2:
			cout<<" "<< raiz->info <<"  \n";
			cout<<"  ";
			system("pause");
			break; 
		case 3:
			cout<<"Ingrese el valor: \n";
			cin>>cod;
			Insertar(cod);
			system("pause");
			break;
		
		case 4:
			cout<<"Introduzca el valor del nodo a borrar: \n"; 
			cin>>nombre;
			borrar(nombre);				
			system ("pause");
			
			break;
		case 5:
			cout<<"Entre el valor del padre: \n"; 
			cin>>nombre;
			buscar(raiz, nombre);
			if (aux==NULL)
				cout<<"No existe el padre";
			else
				{
					if (aux->EI!=NULL)
						cont++;
					if(aux->ED!=NULL)
						cont++;
					cout<<"Cantidad de hijos:"<<cont<<"\n";
				}
			cont=0;
			system ("pause");
			break;
		case 6:
			cout<<"Entre el valor del padre: \n"; 
			cin>>nombre;
			buscar(raiz, nombre);
			if (aux==NULL)
				cout<<"No existe el padre";
			else
				{
					if (aux->EI!=NULL)
						grado++;
					if(aux->ED!=NULL)
						grado++;
					cout<<"El nodo "<<nombre<<" tiene grado:"<<grado<<"\n";
				}
			getchar();
			grado=0;
			system ("pause");
			break;
		case 7: 
			exit(0); 
			system("pause");
			break;
		}
	}while ((opc!=9));
	return 0; 
} 
