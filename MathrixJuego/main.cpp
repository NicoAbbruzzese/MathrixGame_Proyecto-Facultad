#include <iostream>
#include "funciones.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;
int puntajetotal=0;
int highscore = 0;

int main() {
    srand(time(NULL));
    MostrarMenu();
    char nombre2[20];
    int opcion;
    cin >> opcion;

    while(opcion!=0) {
        if(opcion == 1) {
            int matriz[6][6]= {};
            char nombre[20]= {};
            char calculadora[20]= {};
            int vidas = 3;
            int fila, columna;
            int direccion;
            char operacion;
            int ronda = 1;

            PedirNombre(nombre);
            PedirCalculadora(calculadora);

            CrearMatriz(matriz);
            MostrarMatriz(matriz);

            while(vidas > 0) {
                cout << endl << endl << "RONDA " << ronda << endl << endl;
                cout << "Ingrese numero de fila: ";
                cin >> fila;
                cout << "Ingrese numero de columna: ";
                cin >> columna;
                cout << endl << endl;
                MenuOperacion();
                cout << "Ingrese operacion: ";
                cin >> operacion;
                cout << endl << endl;
                MenuDireccion();
                cout << "Ingrese direccion: ";
                cin >> direccion;


                switch(operacion){
                    case '+': {
                        if(fila <= 6 && fila >= 1 && columna <= 6 && columna >= 1){
                            bool resultado = Sumar(matriz, fila, columna, direccion, puntajetotal);
                            if(resultado == false){
                                vidas--;
                            }
                        } else {
                            cout << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                            vidas--;
                        }
                        cout << "VIDAS: " << vidas << endl;
                        MostrarMatriz(matriz);
                        ronda++;
                    }
                        break;

                    case '-': {
                        if(fila <= 6 && fila >= 1 && columna <= 6 && columna >= 1){
                            bool resultado = Restar(matriz, fila, columna, direccion, puntajetotal);
                            if(resultado == false){
                                vidas--;
                            }
                        } else {
                            cout << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                            vidas--;
                        }
                        cout << "VIDAS: " << vidas << endl;
                        MostrarMatriz(matriz);
                        ronda++;
                    }
                        break;

                    case '*': {
                        if(fila <= 6 && fila >= 1 && columna <= 6 && columna >= 1){
                            bool resultado = Multiplicar(matriz, fila, columna, direccion, puntajetotal);
                            if(resultado == false){
                                vidas--;
                            }
                         } else {
                            cout << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                            vidas--;
                        }
                        cout << "VIDAS: " << vidas << endl;
                        MostrarMatriz(matriz);
                        ronda++;
                    }
                        break;

                    case '/': {
                        if(fila <= 6 && fila >= 1 && columna <= 6 && columna >= 1){
                            bool resultado = Dividir(matriz, fila, columna, direccion, puntajetotal);
                            if(resultado == false){
                                vidas--;
                            }
                         } else {
                            cout << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                            vidas--;
                        }
                        cout << "VIDAS: " << vidas << endl;
                        MostrarMatriz(matriz);
                        ronda++;
                    }
                        break;

                    case '%': {
                        if(fila <= 6 && fila >= 1 && columna <= 6 && columna >= 1){
                            bool resultado = Resto(matriz, fila, columna, direccion, puntajetotal);
                            if(resultado == false){
                                vidas--;
                            }
                         } else {
                            cout << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                            vidas--;
                        }
                        cout << "VIDAS: " << vidas << endl;
                        MostrarMatriz(matriz);
                        ronda++;
                    }
                        break;

                    default:
                        cout << endl << "ERROR EN EL INGRESO DE DATOS" << endl << endl;
                        cout << "VIDAS: " << vidas << endl;
                        MostrarMatriz(matriz);
                        break;
                }
            }
            cout << endl << "GAME OVER" << endl << endl;
            cout << "Puntaje total:  " << puntajetotal << endl;
            strcpy(nombre2, nombre);
        }
        if(opcion == 2) {
            if( highscore == 0 && puntajetotal == 0){
                cout << "No se ha registrado ninguna partida";
            }

            if (highscore == 0 && puntajetotal!=0) {
                highscore = puntajetotal;
                cout << "-------HIGHSCORE!!!-------" << endl << endl;
                MostrarNombre(nombre2, 20);
                cout << " " << highscore;
            }
            if(puntajetotal > highscore && highscore != 0){
                highscore = puntajetotal;
                cout << "-------HIGHSCORE!!!-------" << endl << endl;
                MostrarNombre(nombre2, 20);
                cout << " " << highscore;
            }
        }
        if(opcion == 3) {
            // mostrar creditos
            cout << "Los creadores de este juego han sido :" << endl;
            cout << "Lopez, Lautaro.          Legajo: 24999" << endl;
            cout << "Olmedo, Tomas.           Legajo: 25024" << endl;
            cout << "Abbruzzese,Nicolas.      Legajo: 24891" << endl;
        }

        cout << endl << endl;
        MostrarMenu();
        cin >> opcion;
    }
    return 0;
}
