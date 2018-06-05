#include <iostream>
using namespace std;
struct nodo {
	int info;
	struct nodo *EI;
	struct nodo *ED;
};
nodo *raiz;
//Crear un Árbol de Búsqueda.
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
			{s=p;
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

int main(int argc, char *argv[]) {
	
	return 0;
}

