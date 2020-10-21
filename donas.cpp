#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*se me olvido algo mas no se que es */

struct producto {
    string nombre;
    float precio_unitario;
};
struct pedido{
    string apellido;
    vector<producto>listacomida;
};


int elegir(){
    int productoacomprar;
    do{
        cout << "-- Elegir el producto a comprar----" << endl;
        cout << "1.Dona"<< endl;
        cout << "2.Plato"<< endl;
        cout << "3.Calcular total" << endl;
        cout << "4.salir"<< endl;
        cin >> productoacomprar;
    }while(productoacomprar >4 || productoacomprar < 0);
    return productoacomprar;
}
producto ProductoComprado(int n) {
  producto nuevo;
  switch (n) {
  case 1:
    nuevo.nombre = " Dona sencilla";
    nuevo.precio_unitario = 1.00;
    break;
  case 2:
    nuevo.nombre = " Dona rellena de leche";
    nuevo.precio_unitario = 1.25;
    break;
  case 3:
    nuevo.nombre = " Dona sabor especial";
    nuevo.precio_unitario = 1.50;
    break;
  case 4:
    nuevo.nombre = " Desayuno";
    nuevo.precio_unitario = 2.5;
    break;
  case 5:
    nuevo.nombre = "almuerzo";
    nuevo.precio_unitario = 5;
    break;
  case 6:
    nuevo.nombre = "cena";
    nuevo.precio_unitario = 3.5;
    break;
  }
  return nuevo;
}

void comprarDona(queue<pedido>&dona, pedido &penido){
    int opcion;
    do{
        cout << "-----Donas ---" << endl;
         cout << "1.Dona Sencilla ----- $1.00" << endl;
        cout << " 2. Dona Rellena de leche ----- $1.25" << endl;
        cout << "3. Donas Sabores especiales ----- $1.50" << endl;
         cout << "4. Regresar" << endl;
         cin >> opcion;
         switch (opcion)
         {
             case 1 :
             penido.listacomida.push_back(ProductoComprado(1)); break;
             case 2: 
             penido.listacomida.push_back(ProductoComprado(2)); break;
             case 3:
             penido.listacomida.push_back(ProductoComprado(3)); break;
            case  4: break;
            default: cout << "opcion ingresada no valida" << endl;
         }
    }while(opcion != 4);
}


void Plato(queue<pedido> &platos, pedido &Pedido) {
  int opcion;
  do {
    cout << "-- MENU PLATOS --" << endl;
    cout << "1. Desayuno - $2.50" << endl;
    cout << "2. Almuerzo - $5.00" << endl;
    cout << "3. Cena - $3.50" << endl;
    cout << "4. Regresar" << endl;
    cin >> opcion;

    switch (opcion) {
    case 1:
      Pedido.listacomida.push_back(ProductoComprado(4));
      break;
    case 2:
      Pedido.listacomida.push_back(ProductoComprado(5));
      break;
    case 3:
      Pedido.listacomida.push_back(ProductoComprado(6));
      break;
    case 4: break;
    default:
      cout << "Ingrese una opcion valida" << endl;
      break;
    }
  } while (opcion != 4);
}


void atender(queue<pedido>&coladona,queue<pedido>&colaplato){
    pedido pedidocliente;
    int productoelegir=0;
    cout << "Ingrese su apellido:"; getline(cin,pedidocliente.apellido);
    productoelegir = elegir();
 switch(productoelegir){
     case 1: comprarDona(coladona,pedidocliente);
     coladona.push(pedidocliente);
     break;
     case 2:
     Plato(colaplato,pedidocliente);
     colaplato.push(pedidocliente);
      break;

      case 3:     break;
     case 4:  break;
 }

}

void calcular(queue<pedido>s){
    float total  = 0;
queue<pedido>aux = s;
        float totalventas;
        while(!s.empty()){
          pedido aux = s.front();
          while(!aux.listacomida.empty()){
              producto aux2 = aux.listacomida.back(); // accediendo a el primer dato de mi lista
              total+= aux2.precio_unitario;
              aux.listacomida.pop_back();// borrandolo par ano volverlo a sumar 
        }
            s.pop();
        }

        cout << "La ganacia obtenida es : $" << total  << endl;
}
void menu(queue<pedido>&donas,queue<pedido>&platos){
    int opcion;
    bool  continuar= true;
    while(continuar){
    cout << "MENU DE LA CAJA REGISTRADORA" << endl;
    cout << "1. Atender pedidios de clientes" << endl;
    cout << "2. Mostrar ganancias por venta de donas" << endl;
    cout << "3. Mostrar ganancias por venta de platos fuertes" << endl;
    cout << "4. Salir" << endl;

    cout << "\n Accion a realizar:"; cin>>opcion;cin.ignore();
    switch(opcion){
        case 1:
        atender(donas,platos);
         break;
        case 2: 
        calcular(donas);
        break;
        case 3:
        calcular(platos);
         break;
        case 4 : continuar = false; break;
        default : cout << "Opcion no valida" << endl;
    }
}
}


int main() {
  queue<pedido> donas, platos;
  menu(donas, platos);
  return 0;
}




