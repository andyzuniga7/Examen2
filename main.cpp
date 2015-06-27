// queue::push/pop

#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Contacto.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto contacto (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios contactos en un solo archivo
void escribir(string nombre_archivo, Contacto*contacto, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(30*posicion);
    out.write(contacto->nombre.c_str(),13);
    out.write(contacto->correo.c_str(),13);
    out.write((char*)&contacto->numero,4);
    out.close();
}

//Devuelve un contacto previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios contactos de un solo archivo
Contacto* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    char nombre[13];
    char correo[13];
    int numero;
    in.seekg(30*posicion);
    in.read(nombre,13);
    in.read(correo,13);
    in.read((char*)&numero,4);
    in.close();
    Contacto *c = new Contacto(nombre,correo,numero);
    return c;
}

//Devuelve un vector que contenga todos los nombres de los contactos previamente ingresados en el archivo con nombre dado
vector<string> getNombres(string nombre_archivo)
{
    int t;
    ifstream in(nombre_archivo.c_str());
    char nombre[13];
    in.seekg(0,ios::end);
    t=in.tellg()/30;
    in.seekg(0,ios::beg);
    vector<string>nombres;
    for(int i=0;i<t;i++)
    {
        in.read(nombre,13);
        nombres.push_back(nombre);
    }
    return nombres;
}

//Devuelve true si valor_buscado (dado) se encuentra dentro de mi_cola (dada), de lo contrario devuelve false
bool existe(queue<char> mi_cola, char valor_buscado)
{
    char c;
    while (!mi_cola.empty())
    {
        c=mi_cola.front();
        if (c==valor_buscado)
            return true;
        mi_cola.pop();
    }
    return false;
}

//Devuelve true si valor (dado) existe dentro de mi_set (dado)
bool existe(set<int> mi_set,int valor)
{
    int n;
    for (set<int>::iterator i=mi_set.begin();i!=mi_set.end();i++)
        {
                n=*i;
                if(n==valor)
                    return true;
        }
    return false;
}

//Devuelve una lista inversa de mi_lista (dada)
list<double> invertir(list<double>mi_lista)
{
    double n;
    list<double> invertida;
    for (list<double>::iterator i=mi_lista.begin();i!=mi_lista.end();i++)
    {
        n=*i;
        invertida.push_front(n);
    }
    return invertida;
}

//Devuelve la cantidad de nodos que contiene un arbol con raiz dada
int contar(NodoBinario* raiz)
{
    int c=0;
     for(NodoBinario*i=raiz;i!=NULL;i=i->hijo_izq)
        {
            if(i->hijo_izq!=NULL)
                c+=1;
            for(NodoBinario*d=i;d!=NULL;d=d->hijo_der)
                {
                    if(d->hijo_der!=NULL)
                    c+=1;
                }
        }
    return c;
}

//Cambia todos los valores de un arbol con raiz dada
void cambiarValores(NodoBinario* raiz,int nuevo_valor)
{
    for(NodoBinario*i=raiz;i!=NULL;i=i->hijo_izq)
        {
            i->valor=nuevo_valor;
            for(NodoBinario*d=i;d!=NULL;d=d->hijo_der)
                {
                    d->valor=nuevo_valor;
                }
        }
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

