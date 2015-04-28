#include <stdio.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;


class registros {
   public:
      // Datos miembro de la clase "pareja"
      char NumeroEquipo[10],PotenciaActiva[10],CorrienteNominal[10],Eficiencia[10];
   public:
      // Funciones miembro de la clase "pareja"
	void Mostrar();
	void Capturar_Nuevo();
	void Modificar(int opcion);
	void Mostrar_Todo();
	void eliminar();
};

	void registros::eliminar()
{
    //char c;
    int i;
    //char cadena[35];
    char nom2[35];
    ifstream Lectura("inventario.txt");
	ofstream Archivo2("respaldo.txt",ios::app);
    cout<<"ingresa el nombre que deseas eliminar";
    cin.getline(nom2,35);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){
			i=0;
			do{
			Lectura.read((char *)&NumeroEquipo[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(NumeroEquipo[i-1]!='|');
			NumeroEquipo[i-1]='\0';
			if(Lectura.eof()) break;

			i=0;
			do{
			Lectura.read((char *)&PotenciaActiva[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(PotenciaActiva[i-1]!='|');
			PotenciaActiva[i-1]='\0';

			i=0;
			do{
			Lectura.read((char *)&CorrienteNominal[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(CorrienteNominal[i-1]!='|');
			CorrienteNominal[i-1]='\0';

			i=0;
			do{
			Lectura.read((char *)&Eficiencia[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(Eficiencia[i-1]!='|');
			Eficiencia[i-1]='\0';


        //imprimes valores
		if((strcmp(nom2,NumeroEquipo))!=0){
   		 		Archivo2<<NumeroEquipo<<'|'<<PotenciaActiva<<'|'<<CorrienteNominal<<'|'<<Eficiencia<<'|';
							}
       		 }
        	}
       	Lectura.close();
		Archivo2.close();
        }


		void registros::Mostrar_Todo(){
    int i;
    ifstream Lectura("inventario.txt");
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{

        while(!Lectura.eof()){
			i=0;
			do{
			Lectura.read((char *)&NumeroEquipo[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(NumeroEquipo[i-1]!='|');
			NumeroEquipo[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;
			do{
			Lectura.read((char *)&PotenciaActiva[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(PotenciaActiva[i-1]!='|');
			PotenciaActiva[i-1]='\0';

			i=0;
			do{
			Lectura.read((char *)&CorrienteNominal[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(CorrienteNominal[i-1]!='|');
			CorrienteNominal[i-1]='\0';

			i=0;
			do{
			Lectura.read((char *)&Eficiencia[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(Eficiencia[i-1]!='|');
			Eficiencia[i-1]='\0';
        //imprimes valores
    		cout<<endl<<NumeroEquipo<<' '<<PotenciaActiva<<' '<<CorrienteNominal<<' ';
    		cout<<Eficiencia<<' ';
		if(Lectura.eof()==true) break;
        			}
        Lectura.close();
       		 }
		}

	void registros::Capturar_Nuevo(){
	ofstream Archivo("inventario.txt",ios::app);
	fflush(stdin);
	cout<<"ingresa el numero del equipo";gets(NumeroEquipo);
	cout<<"ingresa el valor de la Potencia activa ";gets(PotenciaActiva);
	cout<<"ingresa su valor de la Corriente Nominal: ";gets(CorrienteNominal);
	cout<<"ingresa el valor de la Eficiencia : ";gets(Eficiencia);
    	Archivo<<NumeroEquipo<<'|'<<PotenciaActiva<<'|'<<CorrienteNominal<<'|'<<Eficiencia<<'|';
		Archivo.close();
	}

    void registros::Mostrar(){
    //char c;
    int i;
    //char cadena[35];
    char nom2[50];
    ifstream Lectura("inventario.txt");
    cout<<"que nombre deseas mostrar?";
    cin.getline(nom2,50);
    if(!Lectura.good())
        cout<<"No existe tal archivo, o ah sido movido del folder del .exe "<<endl;
    else{
        while(!Lectura.eof()){

			i=0;
			do{
			Lectura.read((char *)&NumeroEquipo[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(NumeroEquipo[i-1]!='|');
			NumeroEquipo[i-1]='\0';
			if(Lectura.eof()) break;
			i=0;
			do{
			Lectura.read((char *)&PotenciaActiva[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(PotenciaActiva[i-1]!='|');
			PotenciaActiva[i-1]='\0';

			i=0;
			do{
			Lectura.read((char *)&CorrienteNominal[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(CorrienteNominal[i-1]!='|');
			CorrienteNominal[i-1]='\0';

			i=0;
			do{
			Lectura.read((char *)&Eficiencia[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(Eficiencia[i-1]!='|');
			Eficiencia[i-1]='\0';

        //imprimes valores
		if((strcmp(nom2,NumeroEquipo)==0)){
    		cout<<endl<<NumeroEquipo<<' '<<PotenciaActiva<<' '<<CorrienteNominal<<' ';
    		cout<<Eficiencia<<' ';}
		}
        Lectura.close();
        }
		}

	void registros::Modificar(int parametro)
{	char Letrero[50];
	char modif[10];
	char name2[10];
	int i;

	strcpy(Letrero,"");
	cout<<"ingresa el Numero del Equipo quieres modificar";
	fflush(stdin);
    cin.getline(name2,10);
	ifstream Lectura("inventario.txt");
	ofstream respaldo("respaldo.txt",ios::app);
	switch (parametro){
	case 1: strcpy(Letrero,"Numero del Equipo"); break;
	case 2: strcpy(Letrero,"valor de potencia activa nominal"); break;
	case 3: strcpy(Letrero,"valor de la Corriente Nominal"); break;
	case 4: strcpy(Letrero,"valor de la eficiencia"); break;
	}
	cout<<"ingresa el nuevo "<<Letrero<<endl;
    fflush(stdin);
    cin.getline(modif,10);
    if(!Lectura.good())
        cout<<"No existe el archivo";
    else{
			while(!Lectura.eof()){
			i=0;
			do{
			Lectura.read((char *)&NumeroEquipo[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(NumeroEquipo[i-1]!='|');
			NumeroEquipo[i-1]='\0';
			if(Lectura.eof()) break;

			i=0;
			do{
			Lectura.read((char *)&PotenciaActiva[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(PotenciaActiva[i-1]!='|');
			PotenciaActiva[i-1]='\0';

			i=0;
			do{
			Lectura.read((char *)&CorrienteNominal[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(CorrienteNominal[i-1]!='|');
			CorrienteNominal[i-1]='\0';
			if(Lectura.eof()) break;	

			i=0;
			do{
			Lectura.read((char *)&Eficiencia[i],1);
				if(Lectura.eof()) break;
				i++;
			}while(Eficiencia[i-1]!='|');
			Eficiencia[i-1]='\0';
			if(Lectura.	eof()) break;

				switch(parametro)
				{
				case 1: if((strcmp(name2,NumeroEquipo))==0){
				    cout<<"entro";
   		 		respaldo<<modif<<'|'<<PotenciaActiva<<'|'<<CorrienteNominal<<'|'<<Eficiencia<<'|';
						}
						else{
				respaldo<<NumeroEquipo<<'|'<<PotenciaActiva<<'|'<<CorrienteNominal<<'|'<<Eficiencia<<'|';
							}
						break;

				case 2:if((strcmp(name2,NumeroEquipo))==0){
						respaldo<<NumeroEquipo<<'|'<<modif<<'|'<<CorrienteNominal<<'|'<<Eficiencia<<'|';
						}
						else{
						respaldo<<NumeroEquipo<<'|'<<PotenciaActiva<<'|'<<CorrienteNominal<<'|'<<Eficiencia<<'|';
						}break;

				case 3:if((strcmp(name2,NumeroEquipo))==0){
						respaldo<<NumeroEquipo<<'|'<<PotenciaActiva<<'|'<<modif<<'|'<<Eficiencia<<'|';
						}
						else{
						respaldo<<NumeroEquipo<<'|'<<PotenciaActiva<<'|'<<CorrienteNominal<<'|'<<Eficiencia<<'|';
							}break;

				case 4:if((strcmp(name2,NumeroEquipo))==0){
						respaldo<<NumeroEquipo<<'|'<<PotenciaActiva<<'|'<<CorrienteNominal<<'|'<<modif<<'|';
						}
						else{
						respaldo<<NumeroEquipo<<'|'<<PotenciaActiva<<'|'<<CorrienteNominal<<'|'<<Eficiencia<<'|';
						}break;
				}
			}
        }

        Lectura.close();
		respaldo.close();
        }

class principal{
    public:
        registros contactos;

    public:
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
	 remove( "inventario.txt" );
	}
	void principal::restaurar(){
	string linea;
	ifstream entrada ( "respaldo.txt" );
    ofstream salida ("inventario.txt");

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
		cout <<"1.- modificar el Numero del Equipo"<<endl;
		cout <<"2.- modificar la potencia activa nominal"<<endl;
		cout <<"3.- modificar la Corriente Nominal"<<endl;
		cout <<"4.- modificar eficiencia"<<endl;
		cin>>opc;
		getchar();

		switch(opc){
		case 1: contactos.Modificar(1);break;
		case 2: contactos.Modificar(2);break;
		case 3: contactos.Modificar(3);break;
		case 4: contactos.Modificar(4);break;
		}
    }



void principal::menu(){
    int opc=0;
    int bandera=0;
    int calificaciones;
    while(opc!=6){
    cout<<endl;
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
