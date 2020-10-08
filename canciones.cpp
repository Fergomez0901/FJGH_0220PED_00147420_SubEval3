#include <iostream>
#include <queue>
using namespace std; 

struct Cancion{
    string titulo; 
    string cantante; 
    string genero; 
    int duracion; 
};
Cancion cancion; 

void showQueue(queue<Cancion> q)
{
    queue<Cancion> clone = q; 
    while(!clone.empty())
    {
        cout << "Titulo: "<< clone.front().titulo << endl; 
        cout << "Cantante: " << clone.front().cantante << endl; 
        cout << "Genero: " << clone.front().genero << endl; 
        cout << "Duracion: " << clone.front().duracion << endl; 
        cout << endl; 
        clone.pop(); 
    }
}

void emptyQueue(queue<Cancion> q)
{
    while(!q.empty())
    {
        q.pop(); 
    }
}

void menu(queue<Cancion> feliz, queue<Cancion> triste, queue<Cancion> estudio){
    int opcion, opcion2; 
    bool estado = true;

    while (estado)
    {
        cout << endl << "----- Menu -----" << endl; 
        cout << "1) Ingresar una cancion a una cola" << endl;
        cout << "2) Mostar cola de canciones" << endl; 
        cout << "3) Eliminar una cancion de una cola" << endl;
        cout << "4) Vaciar cola" << endl;  
        cout << "5) Salir del programa" << endl; 
        cout << endl << "Ingrese una opcion: " << endl; 
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                cout << "Seleccione la cola donde se agregara una cancion." << endl;
                cout << "1) Cola musica feliz" << endl;
                cout << "2) Cola musica triste" << endl; 
                cout << "3) Cola musica estudio" << endl; 
                cout << endl << "Ingrese una opcion: " << endl;
                cin >> opcion2; 

                switch(opcion2)
                {
                    case 1: 
                        cin.ignore(); 
                        cout << "Ingrese el titulo de la cancion: " << endl;
                        getline(cin, cancion.titulo);
                        cout << "Ingrese el nombre del cantante: " << endl;
                        getline(cin, cancion.cantante);
                        cout << "Ingrese el genero de la cancion: " << endl;
                        getline(cin, cancion.genero); 
                        do
                        {
                            cout << "Ingrese la duracion de la cancion: " << endl; 
                            cin >> cancion.duracion;
                        }while(cancion.duracion <= 0);

                        feliz.push(cancion);
                        break; 

                    case 2:
                        cin.ignore(); 
                        cout << "Ingrese el titulo de la cancion: " << endl; 
                        getline(cin, cancion.titulo);
                        cout << "Ingrese el nombre del cantante: " << endl; 
                        getline(cin, cancion.cantante);
                        cout << "Ingrese el genero de la cancion: " << endl;
                        getline(cin, cancion.genero); 
                        do
                        {
                            cout << "Ingrese la duracion de la cancion: " << endl; 
                            cin >> cancion.duracion;
                        }while(cancion.duracion <= 0);

                        triste.push(cancion);
                        break; 

                    case 3:
                        cin.ignore();
                        cout << "Ingrese el titulo de la cancion: " << endl; 
                        getline(cin, cancion.titulo);
                        cout << "Ingrese el nombre del cantante: " << endl; 
                        getline(cin, cancion.cantante);
                        cout << "Ingrese el genero de la cancion: " << endl; 
                        getline(cin, cancion.genero); 
                        do
                        {
                            cout << "Ingrese la duracion de la cancion: " << endl; 
                            cin >> cancion.duracion;
                        }while(cancion.duracion <= 0);

                        estudio.push(cancion);
                        break; 

                    default: 
                        cout << "Opcion invalida" << endl; 
                        break; 
                }
                break; 
            case 2:
                cout << endl << "Seleccione la cola que desea mostrar: " << endl; 
                cout << "1) Cola musica feliz" << endl;
                cout << "2) Cola musica triste" << endl; 
                cout << "3) Cola musica estudio" << endl; 
                cout << endl << "Ingrese una opcion: " << endl;
                cin >> opcion2; 

                switch(opcion2)
                {
                    case 1:
                        cout<< "Mostrando cola..." << endl; 
                        showQueue(feliz);
                        break;
                    case 2:
                        cout << "Mostrando cola... " << endl; 
                        showQueue(triste);
                        break; 
                    case 3:
                        cout << "Mostrando cola: " << endl << endl; 
                        showQueue(estudio);
                        break; 
                    default:
                        cout << "Opcion invalida" << endl; 
                        break;  
                }
                break; 
            case 3:
                cout << "Seleccione la cola donde se borrara una cancion" << endl; 
                cout << "1) Cola musica feliz" << endl;
                cout << "2) Cola musica triste" << endl; 
                cout << "3) Cola musica estudio" << endl; 
                cout << endl << "Ingrese una opcion: " << endl;
                cin >> opcion2; 

                switch(opcion2)
                {
                    case 1:
                        feliz.pop();
                        cout << "Cancion eliminada. " << endl; 
                        break;
                    case 2:
                        triste.pop();
                        cout << "Cancion eliminada. " << endl; 
                        break;                    
                    case 3:
                        estudio.pop(); 
                        cout << "Cancion eliminada. " << endl; 
                        break; 
                    default:
                        cout << "Opcion invalida. " << endl;
                        break; 
                }
                break;
            case 4: 
                cout << "Seleccione la cola a vaciar: " << endl;
                cout << "1) Cola musica feliz" << endl;
                cout << "2) Cola musica triste" << endl; 
                cout << "3) Cola musica estudio" << endl; 
                cout << endl << "Ingrese una opcion: " << endl;
                cin >> opcion2; 

                switch(opcion2)
                {
                    case 1:
                        emptyQueue(feliz);
                        cout << "Cola eliminada. " << endl; 
                        break;
                    case 2: 
                        emptyQueue(triste);
                        cout << "Cola eliminada. " << endl; 
                        break; 
                    case 3: 
                        emptyQueue(estudio);
                        cout << "Cola eliminada. " << endl;
                        break; 
                    default:
                        cout << "Opcion invalida. " << endl;
                        break; 
                }
                break; 
            case 5: 
                cout << "Fin del programa. Hasta pronto. " << endl; 
                estado = false; 
                break; 
            default: 
                cout << "Opcion invalida." << endl; 
                break;    
        }
    }
}

int main(){
    queue<Cancion> feliz, triste, estudio;
    menu(feliz, triste, estudio);
}