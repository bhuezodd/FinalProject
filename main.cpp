#include "lib/general.h"

using namespace std;

// Cantidad de caracteres del nombre de articulo
const int longCad = 20;
// Estructura
struct costoPorArticulo
{
  char nombreArticul[longCad + 1];
  int cantidad;
  float precio;
  float costoPorArticulo;
};
// Funciones para la interfaz del usuario (UI)
void mostrarData(costoPorArticulo[], int);
void select(int, int, int);
void headerData();
// Funciones solicitadas para el proyecto
costoPorArticulo addArticulo();
float costoTotal(float, int);
float totalArticulos(costoPorArticulo[], int);

// Función principal
int main()
{
  // Variable que alojara la cantidad de productos a ingresar
  int cantidad_productos = 0;
  // Solicitamos cantidad de productos a ingresar
  while (cantidad_productos < 1)
  {
    cout << "Cantidad de articulos: ";
    cin >> cantidad_productos;
  }
  // Limpiamos consola
  system("cls");
  // Declaramos variable que contendra los productos y su información
  costoPorArticulo data[cantidad_productos];
  // variable que nos ayudara a saber cual dato estamos agregando
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
    // Encabezado de la tabla
    headerData();
    // Datos de la tabla
    mostrarData(data, limite);
    positionXY(2, cantidad_productos + 12);
    // Mostrar total de la compra de todos los productos
    cout << "Total: $" << totalArticulos(data, limite);
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
        // Mandamos a llamar los datos ingresados en la función addArticulo
        data[limite] = addArticulo();
        // ingremetamos el limite, para saber que dato es el siguiente a ingresar
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
      if (limite > 0)
      {
        // Variable con el #del producto a eliminar
        string eliminar;
        system("cls");
        positionXY(30, 0);
        color(4);
        cout << "Eliminar";
        // Encabezado de la tabla
        headerData();
        // Datos de la tabla
        mostrarData(data, limite);
        // try para evitar errores al elegir opcion
        try
        {
          positionXY(0, cantidad_productos + 15);
          color(6);
          cout << "Salir (Colocar 0)" << endl;
          color(7);
          cout << "Selecciona dato a eliminar: ";
          // Soliicitamos el #
          cin >> eliminar;
          // Volvemos el dato a entero
          int d = stoi(eliminar);
          // validamos que este dentro del limite
          if (d != 0 && d <= limite)
          {
            int f = 0;
            // creamos nuevo arreglo
            costoPorArticulo newAr[limite - 1];
            // ingresamos datos sin el eliminado al nuevo arreglo
            for (int i = 0; i < limite; i++)
            {
              if (i + 1 != d)
              {
                cout << "test";
                newAr[f] = data[i];
                f++;
              }
            }
            // depositamos los datos en el arreglo global
            for (int i = 0; i < limite; i++)
            {
              data[i] = newAr[i];
            }
            // Le restamos a la varible para saber que se elimino uno dato
            limite--;
          }
        }
        catch (const std::exception &e)
        {
          // Mensaje error
          cout << "Solo se permiten numero";
        }
      }
      // Limpiamos consola
      system("cls");
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
      // Al presionar enter la aplicación termina
      salir = true;
    }
  }

  positionXY(0, cantidad_productos + 16);
  return 0;
}
// Funcion pasa saber en que boton esta colocado
void select(int i, int cantidad_productos, int limite)
{
  int colorSelect = 6;
  // validamos estado de seleccion y limite de productos para elegir el color a mostrar
  i == 0 ? limite < cantidad_productos ? color(colorSelect) : color(4) : color(8);
  positionXY(3, 4);
  cout << "Agregar (Limite: " << cantidad_productos - limite << ")";
  // validamos estado de seleccion y limite de productos para elegir el color a mostrar
  i == 1 ? limite > 0 ? color(colorSelect) : color(4) : color(8);
  positionXY(33, 4);
  cout << "Eliminar (Datos:" << limite << ")";
  // validamos estado de seleccion para elegir el color a mostrar
  i == 2 ? color(colorSelect) : color(8);
  positionXY(3, cantidad_productos + 14);
  cout << "Salir";
}
costoPorArticulo addArticulo()
{
  // Variable que contendra datos ingresado por usuario
  costoPorArticulo data;
  positionXY(25, 4);
  color(3);
  cout << "Agregar Producto";
  color(7);
  positionXY(20, 6);
  cout << "Nombre: ";
  // Agregamos nombre del articulo
  cin >> data.nombreArticul;
  positionXY(20, 8);
  cout << "Cantidad: ";
  // Agregamos cantidad
  cin >> data.cantidad;
  positionXY(20, 10);
  cout << "Precio: ";
  // Agregamos precio
  cin >> data.precio;
  cout << "Precio: ";
  // Agregamos total entre precio y cantidad, con la funcion costoTotal
  data.costoPorArticulo = costoTotal(data.precio, data.cantidad);
  return data;
}
// Funcion que calcula costo total de un articulo
float costoTotal(float precio, int cantidad)
{
  return precio * cantidad;
}
// Encabezado de tabla
void headerData()
{
  color(9);
  positionXY(1, 6);
  cout << "|#";
  positionXY(4, 6);
  cout << "|Nombre Articulo";
  positionXY(29, 6);
  cout << "|Cantidad";
  positionXY(44, 6);
  cout << "|Precio";
  positionXY(54, 6);
  cout << "|Total";
  // Mostrar Articulos
  positionXY(1, 7);
  cout << "---------------------------------------------------------------------------";
}
// Función que despliega datos de los productos
void mostrarData(costoPorArticulo data[], int longData)
{
  color(7);
  // Posicion inicial en y
  int y = 8;
  for (int i = 0; i < longData; i++)
  {
    positionXY(1, y);
    cout << "|";
    cout << i + 1;
    positionXY(4, y);
    cout << "|";
    cout << data[i].nombreArticul;
    positionXY(29, y);
    cout << "|";
    cout << data[i].cantidad;
    positionXY(44, y);
    cout << "|";
    cout << data[i].precio;
    positionXY(54, y);
    cout << "|";
    cout << data[i].costoPorArticulo;
    y++;
  }
}
// Función  retorna el calculo total de la compra de todos los productos
float totalArticulos(costoPorArticulo data[], int longData)
{
  float x = 0;
  for (int i = 0; i < longData; i++)
  {
    x += data[i].costoPorArticulo;
  }
  return x;
}