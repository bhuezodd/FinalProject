// LIbrerias necesarias
#include <iostream>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

/*
    @author Boris Huezo
    @description Hecha para laboratorio 6 de c++ y alguno mas que quede.
*/
// Variables de ayuda
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

//Funcion de imprimir caracteres especiales
void printC(const wchar_t *str, int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), str, wcslen(str), NULL, NULL);
}
void color(int a){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

// Funciones de ayuda
void positionXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

/*
    CON MENU CON TECLAS
    Referencias:
    http://www.cplusplus.com/forum/beginner/132595/
*/
int menuC(int x, int y, std::string *opciones, int num_opciones)
{
    positionXY(x + 1, y);
    std::cout << "x";
    int opcion = 0;
    bool salir = false;
    int p = y;
    while (salir == false)
    {

        for (int i = 0; i < num_opciones; i++)
        {
            positionXY(x, y + i);
            std::cout << "(";
            positionXY(x + 2, y + i);
            std::cout << ")" << opciones[i];
        }
        // Evitamos que se imprima algun mensaje
        system("pause>nul");

        //Programamos flecha hacia abajo
        if (GetAsyncKeyState(VK_DOWN) && p != (y + num_opciones - 1) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_RETURN))
        {
            positionXY(x + 1, p);
            std::cout << " ";
            p++;
            positionXY(x + 1, p);
            std::cout << "x";
            opcion++;
            continue;
        }
        // Programamos flecha hacia arriba
        // Por bugs que pasan evitamos que se active si estas precionando la tecla de abajo y el enter
        // NOTA: Esto en mi pc
        if (GetAsyncKeyState(VK_UP) && p != y && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_RETURN))
        {
            positionXY(1, p);
            std::cout << " ";
            p--;
            positionXY(1, p);
            std::cout << "x";
            opcion--;
            continue;
        }
        // Programamos boton de enter, para seleccionar opcion
        // Se valida que no se este presionando las mismas teclas de navegacion, por temas de bugs
        // NOTA: Esto en mi pc
        if (GetAsyncKeyState(VK_RETURN) && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP))
        {
            salir = true;
        }
    }

    return opcion;
}
// Funcion para pausar
void pause()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    std::cout << "------------------------------" << std::endl;
    std::cout << "Pulsa ENTER para continuar...";
    getwchar();
    getwchar();
}