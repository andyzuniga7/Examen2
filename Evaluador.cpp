#include "Evaluador.h"

string getPrimerElemento(queue<string> mi_cola);

bool compareLists(list<double>a, list<double>b)
{
    if(a.size()!=b.size())
        return false;
    list<double>::iterator j =b.begin();
    for(list<double>::iterator i=a.begin();i!=a.end();i++)
    {
        if(*i!=*j)
            return false;
        j++;
    }
    return true;
}

bool compareSets(stack<char>s1, stack<char>s2)
{
    if(s1.size()!=s2.size())
        return false;
    while(!s1.empty())
    {
        if(s1.top()!=s2.top())
            return false;
        s1.pop();
        s2.pop();
    }
    return true;
}

void evaluar()
{
    int nota = 0;

    escribir("archivo_evaluador1",new Contacto("Juan","a@a.com",988939),2);
    escribir("archivo_evaluador1",new Contacto("Maria","b@b.com",994323),0);
    escribir("archivo_evaluador1",new Contacto("Pedro","c@c.com",985434),1);

    cout<<"Ejercicio escribir() y leer():\t\t";
    bool correcto = true;

    if(  (leer("archivo_evaluador1",0)->nombre == "Maria"
       && leer("archivo_evaluador1",1)->nombre == "Pedro"
       && leer("archivo_evaluador1",2)->nombre == "Juan"
       && leer("archivo_evaluador1",0)->correo == "b@b.com"
       && leer("archivo_evaluador1",1)->correo == "c@c.com"
       && leer("archivo_evaluador1",2)->correo == "a@a.com"
       && leer("archivo_evaluador1",0)->numero == 994323
       && leer("archivo_evaluador1",1)->numero == 985434
       && leer("archivo_evaluador1",2)->numero == 988939
       )==false)
    {
        correcto=false;
    }

    escribir("archivo_evaluador2",new Contacto("Lola","a@a.com",98342312),0);
    escribir("archivo_evaluador2",new Contacto("Ruru","b@b.com",90432343),1);

    if(  (leer("archivo_evaluador2",0)->nombre == "Lola"
       && leer("archivo_evaluador2",1)->nombre == "Ruru"
       && leer("archivo_evaluador2",0)->correo == "a@a.com"
       && leer("archivo_evaluador2",1)->correo == "b@b.com"
       && leer("archivo_evaluador2",0)->numero == 98342312
       && leer("archivo_evaluador2",1)->numero == 90432343
       )==false)
    {
        correcto=false;
    }

    if(correcto)
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Ejercicio getNombres():\t\t\t";
    if(getNombres("archivo_evaluador1").size()>0 && getNombres("archivo_evaluador2").size()>0
       && getNombres("archivo_evaluador1")[0]=="Maria"
       && getNombres("archivo_evaluador1")[1]=="Pedro"
       && getNombres("archivo_evaluador1")[2]=="Juan"
       && getNombres("archivo_evaluador2")[0]=="Lola"
       && getNombres("archivo_evaluador2")[1]=="Ruru"
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    queue<char>q1;
    q1.push('a');
    q1.push('b');
    q1.push('c');
    q1.push('d');

    queue<char>q2;
    q2.push('q');
    q2.push('w');
    q2.push('e');
    q2.push('r');
    q2.push('t');

    queue<char>q3;
    q3.push('f');
    q3.push('d');
    q3.push('s');

    cout<<"Ejercicio existe():\t\t\t";
    if(existe(q1,'a')
       && !existe(q1,'x')
       && !existe(q2,'a')
       && existe(q2,'t')
       && existe(q3,'s')
       && !existe(q3,'a')
       )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    set<int>s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);

    set<int>s2;
    s2.insert(10);
    s2.insert(20);
    s2.insert(30);

    cout<<"Ejercicio existe():\t\t\t";

    if(existe(s1,3)
       && !existe(s1,6)
       && !existe(s1,0)
       )
    {
        nota+=1;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    list<double> l1;
    l1.push_back(78);
    l1.push_back(8);
    l1.push_back(3);
    l1.push_back(7.2);
    l1.push_back(6.2);

    list<double> l1i;
    l1i.push_back(6.2);
    l1i.push_back(7.2);
    l1i.push_back(3);
    l1i.push_back(8);
    l1i.push_back(78);

    list<double> l2;
    l2.push_back(5);
    l2.push_back(1.5);
    l2.push_back(8.4);
    l2.push_back(8.4);

    list<double> l2i;
    l2i.push_back(8.4);
    l2i.push_back(8.4);
    l2i.push_back(1.5);
    l2i.push_back(5);

    list<double> l3;
    l3.push_back(8.4);

    cout<<"Ejercicio invertir():\t\t\t";
    if(compareLists(invertir(l1), l1i)
       && compareLists(invertir(l2), l2i)
       && compareLists(invertir(l3), l3)
       && !compareLists(invertir(l1), l1)
       && !compareLists(invertir(l2), l3)
       && !compareLists(invertir(l2i), l1i)
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    NodoBinario* n1 = new NodoBinario(1);
    NodoBinario* n2 = new NodoBinario(2);
    NodoBinario* n3 = new NodoBinario(5);
    NodoBinario* n4 = new NodoBinario(4);
    NodoBinario* n5 = new NodoBinario(5);
    NodoBinario* n6 = new NodoBinario(11);
    NodoBinario* n7 = new NodoBinario(11);
    NodoBinario* n8 = new NodoBinario(23);
    NodoBinario* n9 = new NodoBinario(37);

    n1->hijo_izq = n2;
    n1->hijo_der = n3;

    n2->hijo_izq = n4;
    n2->hijo_der = n5;

    n3->hijo_izq = n6;
    n3->hijo_der = n8;

    n8->hijo_der = n9;

    n5->hijo_der = n7;

    cout<<"Ejercicio contar():\t\t\t";

    if(contar(n9)==1
       && contar(n1)==9
       && contar(n3)==4
       && contar(n5)==2
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cambiarValores(n1,43);

    cout<<"Ejercicio cambiarValor():\t\t";
    if(n1->valor==43
       && n2->valor==43
       && n3->valor==43
       && n4->valor==43
       && n5->valor==43
       && n6->valor==43
       && n7->valor==43
       && n8->valor==43
       && n9->valor==43
       )
    {
        nota+=3;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/15"<<endl;
}
