#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void MostrarMenu();
void PedirNombre(char[]);
void MostrarNombre(char [], int);
void PedirCalculadora(char[]);
void CrearMatriz(int matriz[6][6]);
void MostrarMatriz(int matriz[6][6]);
bool Sumar(int [6][6], int , int, int, int &);
bool Restar(int [6][6], int, int, int, int &);
bool Multiplicar(int [6][6], int, int, int, int &);
bool Dividir(int [6][6], int, int, int, int &);
bool Resto(int [6][6], int, int, int, int &);
void MenuOperacion();
void MenuDireccion();


#endif // FUNCIONES_H_INCLUDED
