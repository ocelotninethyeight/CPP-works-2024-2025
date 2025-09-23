#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <cstring>


using namespace std;

typedef struct identita{
    char nome[20],cognome[20];
    int tel;
}id;

void agg(fstream& fid, char* nome){

    identita persona;

    fid.open(nome, ios::binary | ios::out | ios::app);
    if(!fid){
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    cin.ignore(80, '\n');
    cout<<"Nome dipendente: "<<endl;
    cin.get(persona.nome,20);
    cin.ignore(80, '\n');
    cout<<endl<<"Cognome dipendente: "<<endl;
    cin.get(persona.cognome,20);
    cin.ignore(80, '\n');
    cout<<endl<<"Numero di telefono: "<<endl;
    cin>>persona.tel;
    fid.write((char*)&persona,sizeof(persona));
    fid.close();

    cout<<"Persona aggiunta con successo"<<endl;
}

int cont(fstream& fid,const char* nome){
    identita persona;
    int count = 0;
    fid.open(nome,ios::binary | ios::in);
    if(!fid){
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    while(fid.read((char*)&persona, sizeof(persona))){
        count++;
    }
    fid.close();
    return count;
}


void print(fstream& fid, const char* nome){
    identita testo;
    fid.open(nome,ios::binary | ios::in);
    if(!fid){
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    while(fid.read((char*)&testo, sizeof(testo))){
        cout<<"Nome: "<<testo.nome<<endl;
        cout<<"Cognome: "<<testo.cognome<<endl;
        cout<<"Numero di telefono: "<<testo.tel<<endl;
        cout<<"--------------------------------------------------"<<endl;
    }
    fid.close();
}

void search(fstream& fid, const char* nome){
    identita ricerca;
    char name[20];
    fid.open(nome,ios::binary | ios::in);
    if(!fid){
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    cin.ignore(80, '\n');
    cout<<endl<<"inserisci il nome da cercare: "<<endl;
    cin.get(name,20);
    cin.ignore(80, '\n');

    while(fid.read((char*)&ricerca, sizeof(ricerca))){
        if(strcmp(ricerca.nome,name)==0){
            cout<<"Nome trovato."<<endl;
            cout<<"Numero di telefono: "<<ricerca.tel<<endl;
            break;
        }
    }

    if(strcmp(ricerca.nome,name)!=0){
        cout<<"Nome non trovato."<<endl;
    }
fid.close();

}


int main()
{
    fstream fdip;
    char nome[20]="proa123456.txt";
    int scelta;
    while (true){
    cout<<"inserire scelta"<<endl;
    cout << "1. Aggiungi Elementi rubrica" << endl;
    cout << "2. Stampa Elementi rubrica" << endl;
    cout << "3. Conta Elementi rubrica" << endl;
    cout << "4. Cerca un Elemento" << endl;
    cout << "Inserisci la tua scelta: ";
    cin >> scelta;


    switch(scelta){

        case 1:
        agg(fdip,nome);
        break;

        case 2:
        print(fdip,nome);
        break;

        case 4:
        search(fdip,nome);
        break;

        case 3:
        int conta=cont(fdip,nome);
        cout<<"i numeri sono in tutto "<<conta<<endl;
        break;
    }
    }



    return 0;
}//
// Created by m.dipino on 17-Sep-25.
//
