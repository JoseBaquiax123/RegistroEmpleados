#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombre_empleados = "empleados.dat";

struct Empleado {
	int codigo;
	char nombre[50];
	char apellido[50];
	char puesto[50];
	int sueldo;
	int bonificacion;
};

 void ingresar_empleado();
void abrir_empleado();
 void modificar_empleado();
 void eliminar_empleado();
int main (){
	abrir_empleado();
 ingresar_empleado();
	modificar_empleado();
eliminar_empleado();
	return 0;	
}
void buscar_codigo(){
	
	FILE* empleados = fopen(nombre_empleados, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, empleados );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, empleados );
		indice += 1;
		} while (feof( empleados ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( empleados,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, empleados );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
        cout << "Sueldo: " << empleado.sueldo << endl;
        cout << "Bonoficaciones: " << empleado.bonificacion << endl;
        cout << endl;
	
	fclose(empleados);
	system("PAUSE");
}


void buscar_indice(){
	FILE* empleados = fopen(nombre_empleados, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( empleados,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, empleados );

        cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
        cout << "Sueldo: " << empleado.sueldo << endl;
        cout << "Bonoficaciones: " << empleado.bonificacion << endl;
        cout << endl;
	
	fclose(empleados);

	
}


void abrir_empleado(){

	system("cls");
	FILE* empleados = fopen(nombre_empleados, "rb");
	if(!empleados) {
		empleados = fopen(nombre_empleados, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, empleados );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"PUESTO"<<"SUELDO"<<"BONIFICACION"<<""<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< empleado.codigo <<" | "<< empleado.nombre<<" "<<empleado.apellido<<" "<<empleado.puesto<<""<<empleado.sueldo<<""<<empleado.bonificacion<<endl;
        
        
		fread ( &empleado, sizeof(Empleado), 1, empleados );
		registro += 1;	
		} while (feof( empleados ) == 0);
		
    cout<<endl;
    
		fclose(empleados);
	}
void ingresar_empleado(){
	
	char continuar;
	FILE* empleados = fopen(nombre_empleados, "ab"); // ab
	
	
		Empleado empleado;
		 string nombre,apellido,puesto;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Puesto:";
		getline(cin,puesto);
    	strcpy(empleado.puesto, nombre.c_str());
		
		cout<<"Ingrese el Sueldo:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese bonificaciones:";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, empleados );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(empleados);
	abrir_empleado();
	buscar_indice();	
	buscar_codigo();
}
void modificar_empleado(){
	
	FILE* empleados = fopen(nombre_empleados, "r+b");
	
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( empleados, id * sizeof(Empleado), SEEK_SET );
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el puesto:";
		getline(cin,puesto);
		strcpy(empleado.puesto, apellido.c_str());
		
		cout<<"Ingrese el Sueldo:";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese bonificaciones:";
		cin>>empleado.bonificacion;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, empleados );
		
	fclose(empleados);
	abrir_empleado();
		system("PAUSE");
}

