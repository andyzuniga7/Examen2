#ifndef EVALUADOR_H
#define EVALUADOR_H

#include "Contacto.h"
#include "NodoBinario.h"
#include <iostream>       // std::cin, std::cout
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;

void evaluar();
void escribir(string nombre_archivo, Contacto*contacto, int posicion);
Contacto* leer(string nombre_archivo, int posicion);
vector<string> getNombres(string nombre_archivo);
bool existe(queue<char> mi_cola, char valor_buscado);
bool existe(set<int> mi_set,int valor);
list<double> invertir(list<double>mi_lista);
int contar(NodoBinario* raiz);
void cambiarValores(NodoBinario* raiz,int nuevo_valor);

#endif // EVALUADOR_H
