#include "funciones.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void MostrarMenu() {
    cout << endl;
    cout << "         MATHRIX" << endl;
    cout << "  ---------------------" << endl;
    cout << "  1 - JUGAR" << endl;
    cout << "  2 - ESTADISTICAS" << endl;
    cout << "  3 - CREDITOS" << endl;
    cout << "  ---------------------" << endl;
    cout << "  0 - SALIR" << endl << endl;

}

void PedirNombre(char nombre[]) {
    cout << "- Nombre del jugador:  ";
    cin >> nombre;
}

void MostrarNombre(char nombre[], int tamanio) {
    for(int i = 0; i < tamanio; i++ ){
    cout << nombre[i];
    }
}
void PedirCalculadora(char calculadora[]) {
    cout << "- Calculadora favorita:  ";
    cin >> calculadora;
}

void CrearMatriz(int matriz[6][6]) {
    for (int f = 0; f < 6; f++) {
        for(int c = 0; c < 6; c++) {
            matriz[f][c]=rand()%10;
        }
    }
}

void MostrarMatriz(int matriz[6][6]) {
    for (int filas = 0; filas < 6; filas++) {
        cout << endl << endl;
        for(int columnas = 0; columnas < 6; columnas++) {
            cout << "   " << matriz[filas][columnas] << "    ";
        }
    }
    cout << endl << endl;
}

bool Sumar(int matriz[6][6], int fila, int columna, int direccion, int &puntajetotal) {
    switch(direccion) {
    // sumar hacia la derecha
        case 6: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna];
            int c = matriz[fila-1][columna+1];
            int puntaje = a + b + c;
            if(a + b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna] = -1;
                matriz[fila-1][columna+1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl;
                puntajetotal += puntaje;
                return true;

                }else if(a == -1 || b == -1 || c == -1 || a + b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
            }
        }
            break;

    // sumar hacia la izquierda
        case 4: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna-2];
            int c = matriz[fila-1][columna-3];
            int puntaje = a + b + c;
            if(a + b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna-2] = -1;
                matriz[fila-1][columna-3] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a + b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
            }
            break;
    // sumar hacia arriba
        case 8: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-2][columna-1];
            int c = matriz[fila-3][columna-1];
            int puntaje = a + b + c;
            if(a + b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-2][columna-1] = -1;
                matriz[fila-3][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a + b != c) {
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // sumar hacia abajo
        case 2: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila][columna-1];
            int c = matriz[fila+1][columna-1];
            int puntaje = a + b + c;
            if(a + b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila][columna-1] = -1;
                matriz[fila+1][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a + b != c) {
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
        default:
         cout << "Direccion incorrecta";
            break;
    }
}

bool Restar(int matriz[6][6], int fila, int columna, int direccion, int &puntajetotal) {
    switch(direccion) {
    // restar hacia la derecha
        case 6: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna];
            int c = matriz[fila-1][columna+1];
            int puntaje = a + b + c;
            if(a - b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna] = -1;
                matriz[fila-1][columna+1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a - b != c) {
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // restar hacia la izquierda
        case 4: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna-2];
            int c = matriz[fila-1][columna-3];
            int puntaje = a + b + c;
            if(a - b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna-2] = -1;
                matriz[fila-1][columna-3] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a - b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // restar hacia arriba
        case 8: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-2][columna-1];
            int c = matriz[fila-3][columna-1];
            int puntaje = a + b + c;
            if(a - b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-2][columna-1] = -1;
                matriz[fila-3][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a - b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // restar hacia abajo
        case 2: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila][columna-1];
            int c = matriz[fila+1][columna-1];
            int puntaje = a + b + c;
            if(a - b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila][columna-1] = -1;
                matriz[fila+1][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a - b != c) {
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
        default:
            cout << "Direccion incorrecta";
            break;
    }
}

bool Multiplicar(int matriz[6][6], int fila, int columna, int direccion, int &puntajetotal) {
    switch(direccion) {
    // Multiplica hacia la derecha
        case 6: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna];
            int c = matriz[fila-1][columna+1];
            int puntaje = a + b + c;
            if(a * b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna] = -1;
                matriz[fila-1][columna+1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a * b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Multiplica hacia la izquierda
        case 4: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna-2];
            int c = matriz[fila-1][columna-3];
            int puntaje = a + b + c;
            if(a * b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna-2] = -1;
                matriz[fila-1][columna-3] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a * b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Multiplica hacia arriba
        case 8: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-2][columna-1];
            int c = matriz[fila-3][columna-1];
            int puntaje = a + b + c;
            if(a * b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-2][columna-1] = -1;
                matriz[fila-3][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a * b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Multiplica hacia abajo
        case 2: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila][columna-1];
            int c = matriz[fila+1][columna-1];
            int puntaje = a + b + c;
            if(a * b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila][columna-1] = -1;
                matriz[fila+1][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a * b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
        default:
            cout << "Direccion incorrecta";
            break;
    }
}

bool Dividir(int matriz[6][6], int fila, int columna, int direccion, int &puntajetotal) {
    switch(direccion) {
    // Divide hacia la derecha
        case 6: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna];
            int c = matriz[fila-1][columna+1];
            int puntaje = a + b + c;
            if(a >= b && b != 0 && a / b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna] = -1;
                matriz[fila-1][columna=1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a / b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Divide hacia la izquierda
        case 4: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna-2];
            int c = matriz[fila-1][columna-3];
            int puntaje = a + b + c;
            if(a >= b && b != 0 && a / b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna-2] = -1;
                matriz[fila-1][columna-3] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a / b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Divide hacia arriba
        case 8: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-2][columna-1];
            int c = matriz[fila-3][columna-1];
            int puntaje = a + b + c;
            if(a >= b && b != 0 && a / b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-2][columna-1] = -1;
                matriz[fila-3][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a / b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Divide hacia abajo
        case 2: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila][columna-1];
            int c = matriz[fila+1][columna-1];
            int puntaje = a + b + c;
            if(a >= b && b != 0 && a / b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila][columna-1] = -1;
                matriz[fila+1][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a / b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
        default:
            cout << "Direccion incorrecta";
            break;
    }
}

bool Resto(int matriz[6][6], int fila, int columna, int direccion, int &puntajetotal) {
    switch(direccion) {
    // Resto hacia la derecha
        case 6: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna];
            int c = matriz[fila-1][columna+1];
            int puntaje = a + b + c;
            if(b != 0 && a % b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna] = -1;
                matriz[fila-1][columna+1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a % b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Resto hacia la izquierda
        case 4: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-1][columna-2];
            int c = matriz[fila-1][columna-3];
            int puntaje = a + b + c;
            if(b != 0 && a % b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-1][columna-2] = -1;
                matriz[fila-1][columna-3] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a % b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Resto hacia arriba
        case 8: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila-2][columna-1];
            int c = matriz[fila-3][columna-1];
            int puntaje = a + b + c;
            if(b != 0 && a % b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila-2][columna-1] = -1;
                matriz[fila-3][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a % b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
    // Resto hacia abajo
        case 2: {
            int a = matriz[fila-1][columna-1];
            int b = matriz[fila][columna-1];
            int c = matriz[fila+1][columna-1];
            int puntaje = a + b + c;
            if(b != 0 && a % b == c) {
                matriz[fila-1][columna-1] = -1;
                matriz[fila][columna-1] = -1;
                matriz[fila+1][columna-1] = -1;
                cout << endl << "Ecuacion correcta, suma " << puntaje << " puntos" << endl << endl;
                puntajetotal += puntaje;
                return true;

                }else if (a == -1 || b == -1 || c == -1 || a % b != c){
                    cout << endl << "Ecuacion incorrecta, pierde una vida" << endl << endl;
                    return false;
                }
        }
            break;
        default:
            cout << "Direccion incorrecta";
            break;
    }
}

void MenuOperacion(){
    cout << "Operacion    Valor ingresado" << endl;
    cout << "----------------------------" << endl;
    cout << "Suma:                 +" << endl;
    cout << "Resta:                -" << endl;
    cout << "Multiplicacion:       *" << endl;
    cout << "Division(cociente):   /" << endl;
    cout << "Division(resto):      %" << endl;
    cout << "----------------------------" << endl << endl;
}

void MenuDireccion(){
    cout << "Direccion         Valor" << endl;
    cout << "----------------------------" << endl;
    cout << "Arriba:               8" << endl;
    cout << "Abajo:                2" << endl;
    cout << "Izquierda:            4" << endl;
    cout << "Derecha:              6" << endl;
    cout << "----------------------------" << endl << endl;
}
