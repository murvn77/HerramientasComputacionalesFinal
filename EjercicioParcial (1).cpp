#include <iostream>
#include <string.h>
using namespace std;
//Estructura con los datos del usuario
struct datosUsuario{
  char cedula[30]; //Este tipo de dato con el fin de poder evaluar que la cadena sea numérica
  string rol;
};
//Estructura con los datos del producto
struct datosProducto{
  int codigo;
  int cantidad;
  float precio;
};
//Funcion que registrar y valida la informacion del usuario
datosUsuario validarDatos(datosUsuario &usuario){
  do{
      cout << "***-----BIENVENIDO A LA CAFETERIA----***" << endl;
      cout<<endl;
      cout << "  Digite su numero de cedula:  ";
      cin >> usuario.cedula;
      for(int i=0; i<strlen(usuario.cedula); i++){
        if(!isdigit(usuario.cedula[i])){
          cout<<endl;
            cout << "  CUIDADO: La cedula solo puede contener numeros" << endl;
            cout<<endl;
            system("pause");
            system("cls");
            cout << "***-----BIENVENIDO A LA CAFETERIA----***" << endl;
            cout<<endl;
            cout << "  Digite su numero de cedula:  ";
            cin >> usuario.cedula;
        }
      }
      cout<<endl;
      cout << "  Digite su rol: profesor o estudiante:  ";
      cin >> usuario.rol;
      for (int i = 0; i < usuario.rol.length(); i++) {
        usuario.rol[i] = tolower(usuario.rol[i]);
      }
      if(usuario.rol == "profesor" || usuario.rol == "estudiante"){
        return usuario;
      }
      cout<<endl;
      cout << "Este rol no existe, intente nuevamente" << endl;
      system("pause");
      system("cls");
  }while(usuario.rol != "profesor" && usuario.rol != "estudiante");
}
//Funcion que registra la informacion del producto
datosProducto registrarProducto(datosProducto &producto){
  system("cls");
  cout << "***-----BIENVENIDO A LA CAFETERIA----***" << endl;
  cout<<endl;
  cout << "  Digite el codigo del producto que desea comprar:  ";
  cin >> producto.codigo;
  cout<<endl;
  cout << "  Digite la cantidad de unidades que desea llevar:  ";
  cin >> producto.cantidad;
  cout<<endl;
  cout << "  Digite el precio de la unidad del producto:  $";
  cin >> producto.precio;
  return producto;
}
//Funcion que calcula el descuento correspondiente segun el rol
float calcularDescuento(datosUsuario usuario, datosProducto producto){
  const float descuentoEstudiante = 0.50;
  const float descuentoProfesor = 0.20;
  float descuento=0;
  if(usuario.rol == "estudiante"){
    descuento=(producto.cantidad*producto.precio)*descuentoEstudiante;
    return descuento;
  }
  descuento=(producto.cantidad*producto.precio)*descuentoProfesor;
  return descuento;
}

int main()
{
    datosUsuario datosUser;
    datosProducto datosPro;
    validarDatos(datosUser);
    registrarProducto(datosPro);
    float descuentoT = calcularDescuento(datosUser, datosPro);
    system("cls");
    cout << "***-----BIENVENIDO A LA CAFETERIA----***" << endl;
    cout<<endl;
    cout << "  El " << datosUser.rol << " con cedula " << datosUser.cedula << " debe pagar $" << descuentoT << " por el producto " << datosPro.codigo << endl;
    cout << endl;
    cout << " Gracias por utilizar nuestro servicio, hasta luego" << endl;
    cout << endl;
    system("pause");
    return 0;
}
