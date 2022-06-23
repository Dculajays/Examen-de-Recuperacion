#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include<conio.h>
#include<math.h>

using namespace std;

class colegio{
public:
    void mostrarLog();
    void menuPrincipal();
    void menuCatalogos();
    void menuAlumno();
    void registrarCatalogos();
    void modificarCatalogos();
    void eliminarCatalogos();
    void mostrarCatalogos();
    void menuMaestro();
    void registrarMaestro();
    void modificarMaestro();
    void eliminarMaestro();
    void mostrarDatosMaestro();
    void menuProceso();
    void displayProceso();
    void modifyProceso();
    void menuPoliza();
    bool verificar(string ced, string num);
    void agregar(ofstream &es);
    void VerPoliza(ifstream &Lec);
    void reclamaciones(ofstream &Esc, ifstream &Lec);
    void ModificarPlan(ifstream &Lec);
private:
    string documentoIdentificacion, puesto2,nombre, direccion, edad, correo, padre, madre, telefono, estudios, puesto, desicion, busquedaDatos, maestroid, maestronom, maestrotelefono, maestrodireccion, maestroestudios, maestromateria;
    string numeroid,choice, Id, nomConcep, montoConcep;
};

const std::string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
};

void colegio::mostrarLog(){
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro a mostrar bitacora, ";
    log.close();
    string line;
    log.open("bitacora.dat");
    if(log.is_open()){
        system("cls");
        while( getline(log, line)){
            cout << "\n"<<line << endl;
        }
        log.close();
    }
    cout<<"\n\n\t\tGRACIAS POR USAR EL PROGRAMA";
    cout << "\n\t\t";system("pause");
}

void colegio::menuPrincipal(){
    system ("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu principal, ";
    log.close();
    int menu;
    fstream bienvenida;
    string line, desicion;
    bienvenida.open("BIEN.txt");
    if(bienvenida.is_open()){
    cout << "\n";
    while( getline(bienvenida, line)){
    cout << "\t"<<line << endl;
            }
    bienvenida.close();
                }
    cout << "\n\n\t\tElija el numero del menu al que quiera ingresar\n"<< endl << "\t\t[1] CATALOGOS\n" << "\t\t[2] PROCESOS\n" << "\t\t[3] INFORMES\n" << "\t\t[4] Salir del programa\n";cout<<"\n\t\t";cin >> menu;
    switch(menu){
    case 1:
        menuCatalogos();
        break;
    case 2:
        menuProceso();
        break;
    case 3:
         mostrarLog();
        break;
    case 4:
       cout << "\n\t\t�Quiere salir del programa? [ si / no ] : "; cin>>desicion;
        if (desicion=="si"){
            cout<<"\n\n\t\tGRACIAS POR USAR EL PROGRAMA ";
            cout<<"\n\n\t\t";system("pause");
            return exit (1);
        }
        else {
            return menuPrincipal();
        break;
        }
    }


}

void colegio::menuCatalogos(){
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu catalgos, ";
    log.close();
    int menu;
    cout << "\n\t\tBienvenido al --MENU CATOLOGOS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] ALUMNO" << "\t\t[2] MAESTRO\n" << "\t\t[3] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        menuAlumno();
        break;
    case 2:
        menuMaestro();
        break;
    case 3:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system("pause");
        return menuPrincipal();
        break;
    }
}

void colegio::menuAlumno(){
    system("cls");
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu empleados, ";
    log.close();
    int menu;
    cout << "\n\t\tBienvenido al --MENU CATALOGOS ALUMNO-" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] ALTAS" << "\t\t[2] BAJAS" <<  "\t\t[3] MODIFICACION<< "<<"\t\t[4] LECTURA\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarCatalogos();
        break;
    case 2:
       eliminarCatalogos();
        break;
    case 3:
        modificarCatalogos();
        break;
    case 4:
        mostrarCatalogos();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU CATALOGOS--" << endl;
        cout<<"\t";system ("pause");
        return menuCatalogos();
        break;
    }
}

void colegio::registrarCatalogos(){
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu registrar empleado, ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --REGISTRAR EMPLEADOS--\n" << endl;
    cout << "\n\t�Quires salir al --MENU ALUMNOS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuAlumno();
    }
    else {
        cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
        cout << "\t\tIngrese el nombre del alumno a registrar: "; cin >> nombre;
        cout << "\t\tIngrese la edad del alumno a registrar: "; cin >> edad;
        cout << "\t\tIngrese el correo del alumno a registrar: "; cin >> correo;
        cout << "\t\tIngrese el numero de telefono del alumno a registrar: "; cin >> telefono;
        cout << "\t\tIngrese la direccion del alumno a registrar registrar:"; cin >> direccion;
        cout << "\t\tIngrese el nombre del Padre del alumno a registrar: "; cin >> padre;
        cout << "\t\tIngrese el nombre de la Madre del alumno: "; cin>> madre;
        cout << "\n\t--Registro completado--\n" << endl;
        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<< "registro a: "<<documentoIdentificacion<<", ";
        log.close();
        baseDatos.open("alumnos.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< padre <<std::left<<std::setw(15)<< madre <<"\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU--";
    cout<<"\n\t";system("pause");
    return menuAlumno();
}

void colegio::modificarCatalogos(){
    system("cls");
    fstream baseDatos, modBaseDatos, log;
    cout << "\n\t\t\tEntrando al menu --MODIFICAR EMPLEADOS--" << endl;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu modificar Alumno, ";
    log.close();
    baseDatos.open("alumnos.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU EMPLEADOS--";
        cout<<"\n\t";system("pause");
        return menuAlumno();
    }
    else {
        cout << "\n\t\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalalumno.dat",ios::out|ios::binary);
        baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>padre>>madre;
        while (!baseDatos.eof()){
            if (busquedaDatos!=documentoIdentificacion){
                modBaseDatos<<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< padre <<std::left<<std::setw(15)<< madre <<"\n";
            }
            else {
                cout << "\n\t\tIngrese el numero de documento de identificacion de la persona: "; cin >> documentoIdentificacion;
                cout << "\t\tIngrese el nombre de la persona a registrar: "; cin >> nombre;
                cout << "\t\tIngrese la edad de la persona a registrar: "; cin >> edad;
                cout << "\t\tIngrese el correo de la persona a registrar: "; cin >> correo;
                cout << "\t\tIngrese el numero de telefono de la persona a registrar: "; cin >> telefono;
                cout << "\t\tIngrese la direccion de la persona a registrar: "; cin >> direccion;
                cout << "\t\tIngrese el nombre del Padre del alumno a registrar: "; cin >> padre;
                cout << "\t\tIngrese el nombre de la Madre del alumno: "; cin>> madre;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"busco a: "<<busquedaDatos<<" y la modificacion es: "<<documentoIdentificacion<<", ";
                log.close();
                modBaseDatos <<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< padre <<std::left<<std::setw(15)<< madre <<"\n";
            }
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>padre>>madre;

        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "alumnos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalalumno.dat","alumnos.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU ALUMNOS--";
    cout<<"\n\t";system("pause");
    return menuAlumno();
}

void colegio::eliminarCatalogos(){
    system("cls");
	fstream baseDatos,modBaseDatos,log;
	log.open("bitacora.dat",ios::app|ios::out|ios::binary);
  log<<"entro al menu eliminar alumno, ";
  log.close();
	int found=0;
	cout << "\n\t\t\tEntrando al menu --ELIMINAR ALUMNOS--" << endl;
	baseDatos.open("alumnos.dat",ios::in|ios::binary);
	if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion...\a";
		baseDatos.close();
	}
	else
	{
		cout << "\n\t\tIngrese el numero de Documento de Identificacion de la persona que busca: "; cin >> busquedaDatos;
		modBaseDatos.open("temporalalumno.dat", ios::app | ios::out | ios::binary);
		baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>padre>>madre;

		while(!baseDatos.eof())
		{
			if(busquedaDatos!=documentoIdentificacion)
			{
				modBaseDatos<<std::left<<std::setw(15)<< documentoIdentificacion <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< edad <<std::left<<std::setw(15)<< correo <<std::left<<std::setw(15)<< telefono <<std::left<<std::setw(15)<< direccion <<std::left<<std::setw(15)<< padre <<std::left<<std::setw(15)<< madre <<"\n";
			}
			else
			{
				found++;
				log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log<<"elimino a: "<<busquedaDatos<<", ";
        log.close();
				cout << "\n\t\t\tBorrado de informacion exitoso\a";
			}
			baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>padre>>madre;

		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...\a";
		}
		baseDatos.close();
		modBaseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "alumnos.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalalumno.dat","alumno.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
    cout <<"\n\n\t\t\tRegresando al --MENU ALUMNOS--";
    cout<<"\n\t";system("pause");
    return menuAlumno();
}

void colegio::mostrarCatalogos(){
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu mostrar datos ALUMNOS, ";
    log.close();
    cout << "\n\t\t\tEntrando al --MENU MOSTRAR DATOS DE ALUMNOS--";
    cout << "\n\n\t\t�Quiere buscar a una persona en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("alumnos.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
            cout << "\n\t\tIngrese el numero del Documento de Identificacion de la persona a buscar: "; cin >> busquedaDatos;
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>padre>>madre;

            while(!baseDatos.eof()){
                if(busquedaDatos==documentoIdentificacion){
                    cout<<"\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                    cout<<"\n\t\tNombre: " << nombre;
                    cout<<"\n\t\tEdad: "<< edad;
                    cout<<"\n\t\tCorreo Electronico: "<< correo;
                    cout<<"\n\t\tTelefono: "<< telefono;
                    cout<<"\n\t\tDireccion: "<< direccion;
                    cout<<"\n\t\tNOMBRE DEL PADRE:"<< padre;
                    cout<<"\n\t\tNOMBRE DEL MADRE:"<< madre;
                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU ALUMNOS--";
                    cout<<"\n\t";system("pause");
                    return menuAlumno();
                }
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>padre>>madre;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS--";
                cout<<"\n\t";system("pause");
                return mostrarCatalogos();
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS EMPLEADOS"<<endl;
        baseDatos.open("alumnos.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU ALUMNOS--";
            cout<<"\n\t";system("pause");
            return menuAlumno();
        }
        else
        {
            baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>padre>>madre;

            while(!baseDatos.eof())
            {
                total++;
                cout<<"\n\n\t\tDocumento de Identificacion: "<< documentoIdentificacion;
                cout<<"\n\t\tNombre: " << nombre;
                cout<<"\n\t\tEdad: "<< edad;
                cout<<"\n\t\tCorreo Electronico: "<< correo;
                cout<<"\n\t\tTelefono: "<< telefono;
                cout<<"\n\t\tDireccion: "<< direccion;
                cout<<"\n\t\tNOMBRE DEL PADRE:"<< padre;
                cout<<"\n\t\tNOMBRE DEL MADRE:"<< madre;
                baseDatos>>documentoIdentificacion>>nombre>>edad>>correo>>telefono>>direccion>>padre>>madre;
                //if (baseDatos.is_open()){
                  //  baseDatos.close();
                    //cout<<"\n\n\t\tArchivo cerrado";}
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                //if (baseDatos.is_open()){
                  //  baseDatos.close();
                    //cout<<"\n\n\t\tArchivo cerrado";}
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\tRegresando al --MENU ALUMNOS--";
            cout<<"\n\t";system("pause");
            return menuAlumno();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}

void colegio::menuMaestro(){
    system("cls");
    int menu;
    fstream log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"ENTRO AL MENU MAESTROS, ";
    log.close();
    cout << "\n\t\tBienvenido al --MENU MAESTROS--" << endl;
    cout << "\n\t\tElija el numero del menu al que quiere ingresar\n" << endl << "\t\t[1] ALTAS" << "\t\t[2] BAJAS" <<  "\t\t[3] MODIFICACION<< "<<"\t\t[4] LECTURA\n" << "\t\t[5] Salir al --MENU PRINCIPAL--\n";cout<<"\n\t\t"; cin >> menu;
    switch (menu){
    case 1:
        registrarMaestro();
        break;
    case 2:
        modificarMaestro();
        break;
    case 3:
        eliminarMaestro();
        break;
    case 4:
        mostrarDatosMaestro();
        break;
    case 5:
        cout << "\n\tSaliendo al --MENU PRINCIPAL--" << endl;
        cout<<"\t";system("pause");
        return menuCatalogos();
        break;
    }
}

void colegio::registrarMaestro(){
    system("cls");
    fstream baseDatos, log;
    cout << "\n\t\t\tEntrando al menu --REGISTRAR MAESTROS--\n" << endl;
    cout << "\n\t�Quires salir al --MENU MAESTROS--? [ si / no ] : "; cin >> desicion;
    if (desicion=="si"){
        return menuMaestro();
    }
    else {
        cout << "\n\t\tIngrese el numero de identificacion del Maestro a registrar: "; cin >>maestroid;
        cout << "\t\tIngrese el nombre del Maestro a registrar: "; cin >> maestronom;
        cout << "\t\tIngrese el telefono del Maestro a registrar: "; cin >> maestrotelefono;
        cout << "\t\tIngrese la direccion del Maestro a registrar: "; cin >> maestrodireccion;
        cout << "\t\tIngrese los estudios del Maestro a registrar: "; cin >> maestroestudios;
        cout << "\t\tIngrese el nombre de la Materia asignada del Maestro a registrar: "; cin >> maestromateria;
        cout << "\n\t--Registro completado--\n" << endl;
        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
        log.close();
        baseDatos.open("maestros.dat",ios::app | ios::out | ios::binary);
        baseDatos<<std::left<<std::setw(15)<< maestroid <<std::left<<std::setw(15)<< maestronom <<std::left<<std::setw(15)<< maestrotelefono <<std::left<<std::setw(15)<< maestrodireccion <<std::left<<std::setw(15)<< maestroestudios <<std::left<<std::setw(15)<< maestromateria <<"\n";
        baseDatos.close();
    }
    cout <<"\n\n\t\tRegresando al --MENU MAESTROS--";
    cout<<"\n\t";system("pause");
    return menuMaestro();
}

void colegio::modificarMaestro(){
    system("cls");
    fstream baseDatos, modBaseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu modificar MAESTRO ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --MODIFICAR MAESTRO--" << endl;
    baseDatos.open("maestros.dat",ios::in|ios::binary);
    if(!baseDatos){
        cout << "\n\t\tNo se encontro el archivo" << endl;
        baseDatos.close();
        cout <<"\n\n\t\t\tRegresando al --MENU MAESTROS--";
        cout<<"\n\t";system("pause");
        return menuMaestro();
    }
    else {
        cout << "\n\t\t\tIngrese el numero de identificacion del maestro que busca: "; cin >> busquedaDatos;
        modBaseDatos.open("temporalmaestro.dat",ios::out|ios::binary);
        baseDatos>>maestroid>>maestronom>>maestrotelefono>>maestrodireccion>>maestroestudios>>maestromateria;
        while (!baseDatos.eof()){
            if (busquedaDatos!=maestroid){
                modBaseDatos<<std::left<<std::setw(15)<< maestroid <<std::left<<std::setw(15)<< maestronom <<std::left<<std::setw(15)<< maestrotelefono <<std::left<<std::setw(15)<< maestrodireccion <<std::left<<std::setw(15)<< maestroestudios <<std::left<<std::setw(15)<< maestromateria <<"\n";
            }
            else {
                 cout << "\n\t\tIngrese el numero de identificacion del Maestro a registrar: "; cin >>maestroid;
                 cout << "\t\tIngrese el nombre del Maestro a registrar: "; cin >> maestronom;
                 cout << "\t\tIngrese el telefono del Maestro a registrar: "; cin >> maestrotelefono;
                 cout << "\t\tIngrese la direccion del Maestro a registrar: "; cin >> maestrodireccion;
                 cout << "\t\tIngrese los estudios del Maestro a registrar: "; cin >> maestroestudios;
                 cout << "\t\tIngrese el nombre de la Materia asignada del Maestro a registrar: "; cin >> maestromateria;
                log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"modifico: "<<busquedaDatos<<", ahora es: "<<maestroid<<", ";
                log.close();
                modBaseDatos <<std::left<<std::setw(15)<< maestroid <<std::left<<std::setw(15)<< maestronom <<std::left<<std::setw(15)<< maestrotelefono <<std::left<<std::setw(15)<< maestrodireccion <<std::left<<std::setw(15)<< maestroestudios <<std::left<<std::setw(15)<< maestromateria <<"\n";
            }

       baseDatos>>maestroid>>maestronom>>maestrotelefono>>maestrodireccion>>maestroestudios>>maestromateria;
        }
        modBaseDatos.close();
        baseDatos.close();
    if (baseDatos.is_open())
        baseDatos.close();
    if (modBaseDatos.is_open())
        modBaseDatos.close();

    if( remove( "maestros.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalmaestro.dat","maestros.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
    }
    cout <<"\n\n\t\tRegresando al --MENU MAESTROS--";
    cout<<"\n\t";system("pause");
    return menuMaestro();
}

void colegio::eliminarMaestro(){
    system("cls");
	fstream file,file1,log;
	log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu eliminar Maestro, ";
    log.close();
	int found=0;
	cout<<"\n\t\t\tEntrando al --MENU ELIMINAR MAESTRO--"<<endl;
	file.open("departamentos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el numero de identificacion que quiere borrar: ";cin>>busquedaDatos;
		file1.open("temporalmaestro.dat",ios::binary|ios::app | ios::out);
		file >>maestroid>>maestronom>>maestrotelefono>>maestrodireccion>>maestroestudios>>maestromateria;
		while(!file.eof())
		{
			if(busquedaDatos!=maestroid)
			{
				file1<<std::left<<std::setw(15)<< maestroid <<std::left<<std::setw(15)<< maestronom <<std::left<<std::setw(15)<< maestrotelefono <<std::left<<std::setw(15)<< maestrodireccion <<std::left<<std::setw(15)<< maestroestudios <<std::left<<std::setw(15)<< maestromateria <<"\n";

			}
			else
			{
				found++;
				log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                log<<"elimino: "<<busquedaDatos<<", ";
                log.close();
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >>maestroid>>maestronom>>maestrotelefono>>maestrodireccion>>maestroestudios>>maestromateria;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t numero de identificacion  no encontrado...";
		}
		file1.close();
		file.close();
    if (file.is_open())
        file.close();
    if (file1.is_open())
        file1.close();

    if( remove( "maestros.dat" ) != 0 )
        perror( "\n\t\tError deleting file" );
    else
        puts( "\n\t\tFile successfully deleted" );

    if (rename("temporalmaestro.dat","maestros.dat") != 0)
        perror("\n\t\tError renaming file");
    else
        cout << "\n\t\tFile renamed successfully";
	}
	cout <<"\n\n\t\tRegresando al --MENU MAESTROS--";
    cout<<"\n\t";system("pause");
    return menuMaestro();
}

void colegio::mostrarDatosMaestro(){
    system("cls");
    fstream baseDatos, log;
    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
    log<<"entro al menu mostrar datos Depto, ";
    log.close();
    cout << "\n\t\t\tEntrando al menu --MOSTRAR DATOS DE MAESTRO-";
    cout << "\n\n\t\t�Quiere buscar a un MAESTRO en especifico? [ si / no ] : "; cin>>desicion;
    if (desicion=="si"){
        int datos=0;
        baseDatos.open("maestros.dat",ios::in|ios::binary);
        if(!baseDatos)
        {
            cout<<"\n\t\tError";
            cout<<"\n\t\t\tNo se encontro el archivo, asegurese de que el archivo este en la misma carpeta que el programa";
            baseDatos.close();
        }
        else
        {
            cout << "\n\t\t\tEntrando en el menu --BUSCAR--"<<endl;
            cout << "\n\t\tIngrese el numero de identificacion a buscar: "; cin >> busquedaDatos;
            baseDatos>>maestroid>>maestronom>>maestrotelefono>>maestrodireccion>>maestroestudios>>maestromateria;
            while(!baseDatos.eof()){
                if(busquedaDatos==maestroid){
                    cout<<"\n\t\tNumero de Identificacion "<< maestroid;
                    cout<<"\n\t\tNombre del Maestro: " << maestronom;
                    cout<<"\n\t\tTelefono del Maestro: "<< maestrotelefono;
                    cout<<"\n\t\tDireccion del Maestro: "<< direccion;
                    cout<<"\n\t\tEstudios del Maestro: "<< maestroestudios;
                    cout<<"\n\t\tMateria asignada del Maestro: "<< maestromateria;

                    datos++;
                    if (baseDatos.is_open()){
                        baseDatos.close();
                        cout<<"\n\n\t\tArchivo cerrado";}
                    cout<<"\n\n\t\t\tRegresando al --MENU MAESTRO--";
                    cout<<"\n\t";system("pause");
                    return menuMaestro();
                }
                baseDatos>>maestroid>>maestronom>>maestrotelefono>>maestrodireccion>>maestroestudios>>maestromateria;
            }
            if(datos==0)
            {
                cout<<"\n\t\t\tNo se encontro ninguna coincidencia, intentelo de nuevo";
                cout <<"\n\n\t\t\tRegresando al --MENU MOSTRAR DATOS--";
                cout<<"\n\t";system("pause");
                return mostrarDatosMaestro();
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    else {
        fstream baseDatos;
        int total=0;
        cout<<"\n\t\t\tEntrando al --MENU MOSTRAR DATOS DEPARTAMENTOS"<<endl;
        baseDatos.open("maestros.dat",ios::in|ios::binary);
        if(!baseDatos){
            cout<<"\n\t\t\tError\n\t\t\tNo se encontro el archivo, asegurese de que el archivo se encuentre en la misma carpeta del programa";
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\t\tRegresando al --MENU MAESTROS--";
            cout<<"\n\t";system("pause");
            return menuMaestro();
        }
        else
        {
            baseDatos>>maestroid>>maestronom>>maestrotelefono>>maestrodireccion>>maestroestudios>>maestromateria;
            while(!baseDatos.eof())
            {
                total++;
                 cout<<"\n\t\tNumero de Identificacion "<< maestroid;
                 cout<<"\n\t\tNombre del Maestro: " << maestronom;
                 cout<<"\n\t\tTelefono del Maestro: "<< maestrotelefono;
                 cout<<"\n\t\tDireccion del Maestro: "<< direccion;
                 cout<<"\n\t\tEstudios del Maestro: "<< maestroestudios;
                 cout<<"\n\t\tMateria asignada del Maestro: "<< maestromateria;
                baseDatos>>maestroid>>maestronom>>maestrotelefono>>maestrodireccion>>maestroestudios>>maestromateria;
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
            if(total==0){
                cout<<"\n\t\t\tEl archivo se encuentra vacio...";
                if (baseDatos.is_open()){
                    baseDatos.close();
                    cout<<"\n\n\t\tArchivo cerrado";}
            }
            if (baseDatos.is_open()){
                baseDatos.close();
                cout<<"\n\n\t\tArchivo cerrado";}
            cout <<"\n\n\t\tRegresando al --MENU MAESTROS--";
            cout<<"\n\t";system("pause");
            return menuMaestro();
        }
        if (baseDatos.is_open()){
            baseDatos.close();
            cout<<"\n\n\t\tArchivo cerrado";}
    }
    if (baseDatos.is_open()){
        baseDatos.close();
        cout<<"\n\n\t\tArchivo cerrado";}
}

void colegio::menuProceso(){
fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro al MENU PROCESOS ";
log.close();

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |  SISTEMA DE NOMINA EMPLEADOS  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Mostrar"<<endl;
	cout<<"\t\t\t 2. Buscar"<<endl;
	cout<<"\t\t\t 3. Salir al --MENU PRINCIPAL--"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		displayProceso();
    		cout<<"\n\t\t\t Agrega otro (Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 3:
		return menuPrincipal();
		break;
	case 5:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 3);
}

void colegio::displayProceso()
{
fstream log;
log.open("bitacora.dat",ios::app|ios::out|ios::binary);
log<<"entro MOSTRAR PROCESO DEL COLEGIO ";
log.close();

	system("cls");
	fstream baseDatos;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Empleados -------------------------"<<endl;
	baseDatos.open("empleados.dat",ios::in|ios::binary);
	if(!baseDatos)
	{
		cout<<"\n\t\t\tNo hay informacion......";
		baseDatos.close();
	}
	else
	{
		baseDatos>>documentoIdentificacion>>nombre>>direccion>>telefono>>edad>>correo>>padre>>madre>>maestronom;
        cout<<"\t\nID  | "<<"NOMBRE             |"<<"DIRECCION"<<"   |"<<"TELEFONO"<<"    |"<<"EDAD"<<"    |"<<"CORREO"<<" "<<" "<<"    |"<<"NOMBE DEL PADRE"<<"      |"<<"NOMBE DE LA MADRE"<<"         |"<<"MAESTRO ASIGNADO"<<"" ;
        cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		while(!baseDatos.eof())
		{


			cout<<documentoIdentificacion<<" "<<" "<<"|"<<nombre<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<" "<<" "<<" "<<" "<<direccion<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<telefono<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<" "<<" "<<" "<<" "<<edad<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<correo<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<padre<<" "<<" "<<"|"<<madre<<"|"<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<" "<<"|"<<" "<<" "<<maestronom;
			cout<<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			baseDatos>>documentoIdentificacion>>nombre>>direccion>>telefono>>edad>>correo>>padre>>madre>>maestronom;
			total++;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	baseDatos.close();
}


 int main(){



    system ("cls");
    int contador=0;
    bool ingresa=false;
    string usuario, config0, config2, contra;
    fstream config1, log;
    int datos=0;
    config1.open("seguridad.dat",ios::in|ios::binary);
    if(!config1){
        cout<<"\n\n\t\tError, no se encuentra un archivo escencial del programa...\a\n\n";
        exit(1);
    }
    else{
        cout << "\n\t\t\tBIENVENIDO AL PROGRAMA " << endl;
        cout << "\n\t\tIngrese su usuario: "; cin >> usuario;
        config1>>config2;
        while(!config1.eof()){
            if(usuario==config2){
                do{
                    cout << "\n\t\tIngrese su contrasena: ";
                    char caracter;
                    caracter = getch();
                    contra="";
                    while (caracter != 13) //ASCII TECLA ENTER
                    {
                        if (caracter != 8) //ASCII TECLA RETROCESO
                        {
                            contra.push_back(caracter);
                            cout<<"*";
                        } else
                        {
                            if (contra.length() > 0)
                            {
                                cout<<"\b \b"; //Efecto caracter borrado en pantalla
                                contra = contra.substr(0,contra.length()-1); //Toma todos los caracteres menos el ultimo
                            }
                        }
                        caracter = getch();
                    }
                    //instancia de clase USUARIOS, para consultar: primero se consulta el usuario, si existe, se consulta la contraseña
                    if (contra==config2){
                        system("cls");
                        ingresa=true;
                    } else {
                        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                        log<<"\n\n\nUsuario: " << usuario <<", El usuario y/o contrasena son incorrectos, ";
                        log.close();
                        cout<<"\n\t\tEl usuario y/o contrasena son incorrectos\a"<<endl;
                        cin.get();
                        contador++;
                        log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                        log<<"intentos: "<<contador<<", ";
                        log.close();
                    }
                } while (ingresa==false && contador<3);
                if (ingresa==false){
                    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                    log<<"\n\n\nUsuario: " << usuario <<", Lo siento, no puede ingresar al sistema, agoto intentos. ";
                    log.close();
                    cout<<"\n\t\tLo siento, no puede ingresar al sistema, agoto intentos"<<endl;
                    cin.get();
                } else {
                    log.open("bitacora.dat",ios::app|ios::out|ios::binary);
                    log<<"\n\n\nUsuario: " << usuario <<"Fecha AAMMDD / Hora, minutos, segundos: " <<currentDateTime() <<", ";
                    log.close();
                    fstream bienvenida;
                    string line, desicion;
                    bienvenida.open("bienvenidos.txt");
                    if(bienvenida.is_open()){
                        cout << "\n";
                        while( getline(bienvenida, line)){
                            cout << "\t"<<line << endl;
                        }
                        cout<<"\n\t\t";system("pause");
                        bienvenida.close();
                    }
                    bienvenida.close();
                    colegio colegio2;
                    colegio2.menuPrincipal();
                    cin.get();
                }
                return ingresa;
                datos++;
                config1.close();
            }
            config1>>config2;
            config1.close();
        }
        config1.close();
    }
    config1.close();
};
