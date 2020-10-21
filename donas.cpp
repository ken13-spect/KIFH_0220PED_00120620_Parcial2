#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Producto{
string nombre;
float precio;
}; 
struct Producto producto;

 struct Pedido{
     string apellido;
     vector<Producto>lista_comida;
 };
 struct Pedido pedido;


 float menuDonas(queue<Pedido>dona){
float totalcliente =0;
 bool cont= true;
while(cont != false){
     int opcion;
     cout << "Ingrese la opcion que desee:" << endl;
     cout << "1.Ingresar dona" << endl;
     cout << "2. Optener el total del cliente" << endl;
     cout << "3.Salir" << endl;
     cout <<"\n OPCION :" << endl;
     cin>>opcion;cin.ignore();
    
    switch (opcion)
    {
    case 1:
cout << "Ingrese el tipo de dona:" ; getline(cin,producto.nombre);
cout << "Ingrese le precio : $"; cin>>producto.precio;
pedido.lista_comida.push_back(producto);
totalcliente += producto.precio;
        break;

        case 2: 
        // aqui ya le esta cobrando una ves el usuario eleigio tadas las donas que quiso
        cout << "Apellido del cliente ;"; getline(cin,pedido.apellido);
        cout << "El total que el cliente va a pagar es de : $ " << totalcliente <<  " dolares " << endl;
        dona.push(pedido);
        break;
       case 3: cont = false; break;
    default: cout << "opcion no valida" << endl;
        break;
    }
 }

 return totalcliente;

 }




float menuPlatos(queue<Pedido>plato){
float totalcliente =0;
 bool cont= true;
while(cont != false){
     int opcion;
     cout << "Ingrese la opcion que desee:" << endl;
     cout << "1.Ingresar Plato fuerte " << endl;
     cout << "2. Optener el total del cliente" << endl;
     cout << "3.Salir" << endl;
     cout <<"\n OPCION :" << endl;
     cin>>opcion;cin.ignore();
    
    switch (opcion)
    {
    case 1:
cout << "Ingrese el nombre del plato:" ; getline(cin,producto.nombre);
cout << "Ingrese le precio : $"; cin>>producto.precio;
pedido.lista_comida.push_back(producto);
totalcliente += producto.precio;
        break;

        case 2: 
        // aqui ya le esta cobrando una ves el usuario eleigio tadas las donas que quiso
        cout << "Apellido del cliente:"; getline(cin,pedido.apellido);
        cout << "El total que el cliente va a pagar es de : $ " << totalcliente <<  " dolares " << endl;
        plato.push(pedido);

        cout << "Guardando pedido ...." << endl;
        break;
       case 3: cont = false; break;
    default: cout << "opcion no valida" << endl;
        break;
    }
 }

 return totalcliente;

}


int main(){

queue<Pedido>dona,plato;
bool sta = true;
float ganadona=0;
float ganaplato=0;
  cout << endl;
    int op;
    bool cont = true;
    do{
        cout << "CAJA REGISTRADORA " << endl;
        cout <<"Que accion desea ejecutar " << endl;
        cout << "1.Atender clientes" << endl;
        cout << "2. Total de ganancias por la venta de donas" << endl;
        cout << "3. Total de ganancias por la venta de platos fuertes" << endl;
        cout << "4. Salir " << endl;
        cout << "\n Ingrese la opcion deseada" << endl;
        cin>>op;
int opcion;

        switch(op){

            case 1:
            do{
                cout << "Ingrese la accion a ejecutar " << endl;
                cout << "1.Vender donas" << endl;
                cout << "2.Vender Platos" << endl;
                cout << "3. Regresar" << endl;
                cout << "\n OPcion:" << endl;
                cin>>opcion;
                switch(opcion){
                    case 1: ganadona +=menuDonas(dona); break;
                    case 2: ganaplato +=menuPlatos(plato);break;
                    case 3: break;
                    default : cout << "opcion invalida" << endl;

                }
            }while(opcion!=3);

            break;
            case 2:
            cout << "El total de ganancias por la venta de donas es de: $ " << ganadona << " dolares." << endl;
            break;
            case 3:
            cout << "El total de ganancias por la venta de platos es de: $ " << ganaplato << " dolares." << endl;
            break;
            case 4: 
            cont = false; break;
            default: cout << "opcion no valida" << endl;break;



        }




    }while(cont);

    
}
