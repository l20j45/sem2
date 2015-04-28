#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include<stdlib.h>
#include <fstream>

using namespace std;


class registros {
   public:
      // Datos miembro de la clase "pareja"
      char nombre[50],direccion[50],telefono[50],carrera[50],email[50],fecha[50],annos[50];
      
	  int dia,mes,anno,edad;
	  int codigo;
   public:
      // Funciones miembro de la clase "pareja"
	void Mostrar();
	void Modificar_Nombre();
	void Modificar_Carrera();
	void Modificar_Direccion();
	void Modificar_Email();
	void Modificar_Fecha();
	void Modificar_Telefono();
	void Capturar_Nuevo();
	int Calcular_Edad();
	void Mostrar_Todo();
	void eliminar();
	int existe();
	
	
};

	void registros::eliminar()
{
    //char c;
    int i;
    //char cadena[35];
    char nom2[35];
    ifstream Lectura("alumnos.txt");
	ofstream Archivo2("respaldo.txt",ios::app);
    cout<<"ingresa el nombre que deseas eliminar";
    cin.getline(nom2,35);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			 if(Lectura.eof()!=true) break;
			 
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
			if(Lectura.eof()) break;
        //imprimes valores
		if((strcmp(nom2,nombre))!=0)
    	Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
        }
        }
        Lectura.close();
		Archivo2.close();
        }
		void registros::Mostrar_Todo(){
    //char c;
    int i;
    //char cadena[35];
    char nom2[35];
    ifstream Lectura("alumnos.txt");
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
        cout<<endl<<"Nombre:  "<<nombre<<endl<<"direccion:  "<<direccion<<endl<<"telefono:  "<<telefono<<endl;
		cout<<"carrera:  "<<carrera<<endl<<"email:  "<<email<<endl<<"fecha:  "<<fecha<<endl<<"edad:  "<<annos<<endl;

        }
        Lectura.close();
        }
		}
	int registros::Calcular_Edad(){
	int diasis, messis, annosis,edad;
	struct tm *tiempo;
	time_t fecha_sistema;
	time(&fecha_sistema);
	tiempo=localtime(&fecha_sistema);
	annosis=tiempo->tm_year + 1900;	
	messis=tiempo->tm_mon + 1;
	diasis=tiempo->tm_mday;
	if (diasis<dia) {
	messis=mes-1; }
	 	 
	if (messis<mes) {
	annosis=annosis-1;}

	edad=annosis-anno;
	return edad;
	}	
	void registros::Capturar_Nuevo(){
	ofstream Archivo("alumnos.txt",ios::app);
	char num[5];
	
	fflush(stdin);
	cout<<"ingresa el nombre: ";gets(nombre);
	cout<<"ingresa su direccion: ";gets(direccion);
	cout<<"ingresa el telefono: ";gets(telefono);
	cout<<"ingresa el carrera: ";gets(carrera);
	cout<<"ingresa el mail: ";gets(email);
	cout<<"ingresa el ingresa la fecha en este formato dd/mm/aaaa: ";scanf("%d/%d/%d",&dia,&mes,&anno);
	strcpy(fecha,"");
	strcat(fecha, itoa(dia,num,10));
	strcat(fecha,"/");
	strcat(fecha, itoa(mes,num,10));
	strcat(fecha,"/");
	strcat(fecha, itoa(anno,num,10));
	edad=Calcular_Edad();
	strcpy(annos, itoa(edad,num,10));
	
    Archivo<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
    Archivo.close();
	}
	
    void registros::Mostrar(){
    //char c;
    int i;
    //char cadena[35];
    char nom2[35];
    ifstream Lectura("alumnos.txt");
    cout<<"que nombre deseas mostrar?";
    cin.getline(nom2,35);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
		if((strcmp(nom2,nombre))==0){
        cout<<endl<<"Nombre:  "<<nombre<<endl<<"direccion:  "<<direccion<<endl<<"telefono:  "<<telefono<<endl;
		cout<<"carrera:  "<<carrera<<endl<<"email:  "<<email<<endl<<"fecha:  "<<fecha<<endl<<"edad:  "<<edad<<endl;
		}
        }
        Lectura.close();
        }
		}
    void registros::Modificar_Nombre()
{
    //char c;
    int i;
    //char cadena[50];
    char nom3[50];
    char nom2[50];
    ifstream Lectura("alumnos.txt");
	ofstream Archivo2("respaldo.txt",ios::app);
    cout<<"ingresa el nombre a quien le deseas modificar: ";
    cin.getline(nom2,50);
	cout<<"ingresa el nombre: ";
	cin.getline(nom3,50);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;	
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
		if((strcmp(nom2,nombre))==0)
    	Archivo2<<nom3<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
    	else
		Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';    	
        }
        }
        Lectura.close();
		Archivo2.close();
        }

void registros::Modificar_Carrera()
{
    //char c;
    int i;
    //char cadena[50];
    char modif[50];
    char nom2[50];
    ifstream Lectura("alumnos.txt");
	ofstream Archivo2("respaldo.txt",ios::app);
    cout<<"ingresa el nombre a quien le deseas modificar: ";
    cin.getline(nom2,50);
	cout<<"ingresa la carrera: ";
	cin.getline(modif,50);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
		if((strcmp(nom2,nombre))==0)
    	Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<modif<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
        else
        Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
        }
        Lectura.close();
		Archivo2.close();
        }
    }

void registros::Modificar_Direccion()
{
    //char c;
    int i;
    //char cadena[50];
    char modif[50];
    char nom2[50];
    ifstream Lectura("alumnos.txt");
	ofstream Archivo2("respaldo.txt",ios::app);
   cout<<"ingresa el nombre a quien le deseas modificar: ";
    cin.getline(nom2,50);
	cout<<"ingresa la direccion: ";
	cin.getline(modif,50);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
		if((strcmp(nom2,nombre))==0)
    	Archivo2<<nombre<<'|'<<modif<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
    	else
    	Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
        }
        }
        Lectura.close();
		Archivo2.close();
        }

void registros::Modificar_Email()
{
    //char c;
    int i;
    //char cadena[50];
    char modif[50];
    char nom2[50];
    ifstream Lectura("alumnos.txt");
	ofstream Archivo2("respaldo.txt",ios::app);
    cout<<"ingresa el nombre a quien le deseas modificar: ";
    cin.getline(nom2,50);
	cout<<"ingresa el mail: ";
	cin.getline(modif,50);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
		if((strcmp(nom2,nombre))==0)
    	Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<modif<<'|'<<fecha<<'|'<<annos<<'|';
    	else
		Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
        }
        }
        Lectura.close();
		Archivo2.close();
        }

void registros::Modificar_Fecha()
{
    //char c;
    int i;
    //char cadena[50];
    char modif[50];
    char nom2[50];
    ifstream Lectura("alumnos.txt");
	ofstream Archivo2("respaldo.txt",ios::app);
    char num[5],fecha2[50],annos2[20]; 
	int dia,mes,anno,edad;	
	cout<<"ingresa el nombre a quien le deseas modificar: ";
    cin.getline(nom2,50);
	cout<<"ingresa el ingresa la fecha en este formato dd/mm/aaaa: ";
	scanf("%d/%d/%d",&dia,&mes,&anno);
	strcat(fecha2, itoa(dia,num,10));
	strcat(fecha2,"/");
	strcat(fecha2, itoa(mes,num,10));
	strcat(fecha2,"/");
	strcat(fecha2, itoa(anno,num,10));
	edad=Calcular_Edad();
	strcpy(annos2,"");
	strcat(annos2, itoa(edad,num,10));
			
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
		if((strcmp(nom2,nombre))==0)
    	Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha2<<'|'<<annos2<<'|';
        else
		Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';    	
		}
        }
        Lectura.close();
		Archivo2.close();
        }
        
        int registros::existe(){
        	//char c;
    int i;
    int bandera=0;
    //char cadena[50];
    char nom2[50];
    ifstream Lectura("alumnos.txt");
    cout<<"ingresa el nombre que deseas buscar";
    cin.getline(nom2,50);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
		if((strcmp(nom2,nombre))==0)
    	bandera=1;
    	else
    	bandera=0;
        }
        }
        Lectura.close();
        return bandera;
		}
        
void registros::Modificar_Telefono()
{
    //char c;
    int i;
    //char cadena[50];
    char modif[50];
    char nom2[50];
    ifstream Lectura("alumnos.txt");
	ofstream Archivo2("respaldo.txt",ios::app);
    cout<<"ingresa el nombre a quien le deseas modificar: ";
    cin.getline(nom2,50);
	cout<<"ingresa el telefono: ";
	cin.getline(modif,50);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
				Lectura.read((char *)&nombre[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(nombre[i-1]!='|');
			nombre[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;
			do{
				Lectura.read((char *)&direccion[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(direccion[i-1]!='|');
			direccion[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&telefono[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(telefono[i-1]!='|');
			telefono[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&carrera[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(carrera[i-1]!='|');
			carrera[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&email[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(email[i-1]!='|');
			email[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&fecha[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(fecha[i-1]!='|');
			fecha[i-1]='\0';
			i=0;
			do{
				Lectura.read((char *)&annos[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(annos[i-1]!='|');
			annos[i-1]='\0';
        //imprimes valores
		if((strcmp(nom2,nombre))==0)
    	Archivo2<<nombre<<'|'<<direccion<<'|'<<modif<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';
    	else
		Archivo2<<nombre<<'|'<<direccion<<'|'<<telefono<<'|'<<carrera<<'|'<<email<<'|'<<fecha<<'|'<<annos<<'|';    	
        }
        }
        Lectura.close();
		Archivo2.close();
        }

class principal{
    public:
        int codigo;
        registros contactos;

    public:
	void Mostrar_Todo();
	void Menu_Modificar();
	void Remover();
	void menu();
	void restaurar();
	void Remover1();
	
};
	void principal::Remover(){
	 remove( "respaldo.txt" );
	}
	
	void principal::Remover1(){
	 remove( "alumnos.txt" );
	}
	void principal::restaurar(){
	string linea;
	ifstream entrada ( "respaldo.txt" );
    ofstream salida ("alumnos.txt");
 
    if (salida.is_open()) {
        if (entrada.is_open()){
            while (getline (entrada,linea)) {
                salida << linea << endl;
            }
            entrada.close(); // No necesario, se cerrara al salir del bloque
        }
        salida.close(); // No necesario, se cerrara al salir del bloque
    }
	}
    
	
    void principal::Menu_Modificar(){
		int opc;
		cout <<"1.- modificar nombre"<<endl;
		cout <<"2.- modificar direccion"<<endl;
		cout <<"3.- modificar telefono"<<endl;
		cout <<"4.- modificar carrera"<<endl;
		cout <<"5.- modificar email"<<endl;
		cout <<"6.- modificar fecha"<<endl;
		cin>>opc;
		getchar();
		
		switch(opc){
		case 1: contactos.Modificar_Nombre();break;
		case 2: contactos.Modificar_Direccion();break;
		case 3: contactos.Modificar_Telefono();break;
		case 4: contactos.Modificar_Carrera();break;
		case 5: contactos.Modificar_Email();break;
		case 6: contactos.Modificar_Fecha();break;
		}
    }
	
    

void principal::menu(){
    int opc=0;
    int bandera=0;
    int calificaciones;
    while(opc!=6){
    cout<<"1.- capturar contactos"<<endl;
    cout<<"2.- mostrar informacion"<<endl;
    cout<<"3.- Buscar"<<endl;
    cout<<"4.- modificar"<<endl;
    cout<<"5.- eliminar"<<endl;
    cout<<"6.- salir"<<endl;
    cin >>opc;
    getchar();
    switch(opc){
    case 1:
    contactos.Capturar_Nuevo();
    break;
    case 2: contactos.Mostrar_Todo();
            break;
    case 3: 
			contactos.Mostrar();
            break;
    case 4: 
    Menu_Modificar();
	Remover1();
	restaurar();
	Remover();
	opc=0;
	break;
    case 5:
			contactos.eliminar();
			Remover1();
			restaurar();
			Remover();
	break;	
    }
    }
}

int main(){
principal p;

p.menu();
return 0;
}
