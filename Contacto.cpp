#include "Contacto.h"

Contacto::Contacto(string nombre, string correo, int numero)
{
    this->nombre=nombre;
    this->correo=correo;
    this->numero=numero;
}

Contacto::~Contacto()
{
    //dtor
}
