#include "lib/general.h"

using namespace std;

const int longCad = 20;
struct costoPorArticulo
{
  char nombreArticul[longCad + 1];
  int cantidad;
  float precio;
  float costoPorArticulo;
};
void mostrarData(costoPorArticulo[], int);
void select(int, int, int);
costoPorArticulo addArticulo();
float costo(float, int);

int main()
{
  int cantidad_productos;
  cout << "Cantidad de articulos: ";
  cin >> cantidad_productos;
  system("cls");
  costoPorArticulo data[cantidad_productos];
  int limite = 0;

  // Controladores del menu
  bool salir = false;
  int menu = 0;
  // Menu vista
  select(menu, cantidad_productos, limite);

  while (!salir)
  {
    // Creando maquetación de menú
    positionXY(30, 0);
    color(3);
    cout << "Examen Final";
    positionXY(1, 2);
    printC(L"*En este programa te mueves con las teclas (Arriba, Abajo, Izquierda, Derecha)", 5);

    color(9);
    positionXY(1, 6);
    cout << "|Nombre Articulo";
    positionXY(25, 6);
    cout << "|Cantidad";
    positionXY(40, 6);
    cout << "|Precio";
    positionXY(50, 6);
    cout << "|Total";
    // Mostrar Articulos
    positionXY(1, 7);
    cout << "---------------------------------------------------------------------------";
    color(7);
    mostrarData(data, limite);
    positionXY(0, cantidad_productos + 18);
    // Evitamos que se imprima algun mensaje
    system("pause>nul");
    //Programamos flecha hacia abajo
    if (menu == 0 && GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_RETURN))
    {
      // Mover abajo
      menu = 2;
      select(menu, cantidad_productos, limite);
      continue;
    }
    if (menu == 0 && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_RETURN))
    {
      // Mover a la derecha
      menu = 1;
      select(menu, cantidad_productos, limite);
      continue;
    }
    if (menu == 0 && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_RETURN))
    {
      // Acción al dar enter
      if (limite < cantidad_productos)
      {
        system("cls");
        data[limite] = addArticulo();
        limite++;
        system("cls");
      }
      select(menu, cantidad_productos, limite);
      continue;
    }
    if (menu == 1 && GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_RETURN))
    {
      // Mover abajo
      menu = 2;
      select(menu, cantidad_productos, limite);
      continue;
    }
    if (menu == 1 && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_RETURN))
    {
      // Mover a la izquierda
      menu = 0;
      select(menu, cantidad_productos, limite);
      continue;
    }
    if (menu == 1 && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_RETURN))
    {
      // Acción al dar enter
      select(menu, cantidad_productos, limite);
      continue;
    }
    if (menu == 2 && !GetAsyncKeyState(VK_DOWN) && GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_RETURN))
    {
      // Mover hacia arriba
      menu = 0;
      select(menu, cantidad_productos, limite);
      continue;
    }
    if (menu == 2 && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_RIGHT) && !GetAsyncKeyState(VK_RETURN))
    {
      // mover a la derecha
      menu = 1;
      select(menu, cantidad_productos, limite);
      continue;
    }
    if (menu == 2 && !GetAsyncKeyState(VK_DOWN) && !GetAsyncKeyState(VK_UP) && !GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_RETURN))
    {
      // Acción al dar enter
      salir = true;
    }
  }

  return 0;
}
void select(int i, int cantidad_productos, int limite)
{
  int colorSelect = 6;

  i == 0 ? limite < cantidad_productos ? color(colorSelect) : color(4) : color(8);
  positionXY(3, 4);
  cout << "Agregar (Limite: " << cantidad_productos - limite << ")";
  i == 1 ? color(colorSelect) : color(8);
  positionXY(33, 4);
  cout << "Buscar";
  i == 2 ? color(colorSelect) : color(8);
  positionXY(3, cantidad_productos + 16);
  cout << "Salir";
}
costoPorArticulo addArticulo()
{
  costoPorArticulo data;
  cout << "Nombre: ";
  cin >> data.nombreArticul;
  cout << "Cantidad: ";
  cin >> data.cantidad;
  cout << "Precio: ";
  cin >> data.precio;
  cout << "Precio: ";
  data.costoPorArticulo = costo(data.precio, data.cantidad);
  return data;
}

float costo(float precio, int cantidad)
{
  return precio * cantidad;
}

void mostrarData(costoPorArticulo data[], int longData)
{
  int x = 8;
  for (int i = 0; i < longData; i++)
  {
    positionXY(1, x);
    cout << "|";
    cout << data[i].nombreArticul;
    positionXY(25, x);
    cout << "|";
    cout << data[i].cantidad;
    positionXY(40, x);
    cout << "|";
    cout << data[i].precio;
    positionXY(50, x);
    cout << "|";
    cout << data[i].costoPorArticulo;
    x++;
  }
}