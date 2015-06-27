#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>

using namespace std;

class Contacto
{
    public:
        string nombre;
        string correo;
        int numero;
        Contacto(string nombre, string correo, int numero);
        virtual ~Contacto();
    protected:
    private:
};

#endif // CONTACTO_H
