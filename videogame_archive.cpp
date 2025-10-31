#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <cstring>








using namespace std;




struct videogioco {
    char titolo[50]; // Titolo del gioco
    char console[30]; // Tipo di console (xbox,ps…)
    int anno; // Anno di pubblicazione del gioco
    float prezzo; // Costo del gioco
    bool disponibile; // Disponibilità. True se è disponibile, false se è fuori catalogo
};






void agg(fstream& fid, char* nome){
    videogioco game;  //Dichiarazione della struct che utilizzeremo come appoggio


    fid.open(nome, ios::binary | ios::in | ios::app); //Apertura del file in modalità binaria, lettura ed append, ossia che scrive dall fine del file


    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }






    //inserimento dei dati all'interno della struct
    cin.ignore(80, '\n'); // utilizzo cin.ignore perché serve per cancellare i dati residui dal buffer
    cout<<"Titolo del gioco: "<<endl;
    cin.get(game.titolo,50); // si utilizza cin.get() e non cin>> perché altrimenti non leggerebbe oltre gli spazi (ad es. di Far Cry leggerebbe solo Far)
    cin.ignore(80, '\n');
    cout<<endl<<"Console: "<<endl;
    cin.get(game.console,20);
    cin.ignore(80, '\n');
    cout<<endl<<"Anno: "<<endl;
    cin>>game.anno; // qui la variabile è int, quindi cin>> non da alcun problema
    cin.ignore(80, '\n');
    cout<<endl<<"Prezzo: "<<endl;
    cin>>game.prezzo;
    cin.ignore(80, '\n');
    game.disponibile=true; // imposta la disponibilità del prezzo = true, quindi disponibile
    fid.write((char*)&game,sizeof(game)); // scrittura all'interno del file








    cout<<"Gioco aggiunto con successo"<<endl;
    fid.close(); //chiusura del file
}




void print(fstream& fid, const char* nome, bool view){
    videogioco game; //Dichiarazione della struct che utilizzeremo come appoggio
    fid.open(nome,ios::binary | ios::in); //Apertura del file in modalità binaria e lettura
    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }


    while(fid.read((char*)&game, sizeof(game))){ // All'interno della condizione del while, mi sta dicendo che fin quando non arriva alla fine del file, continua a leggere


        if(view==false){ //grazie al parametro di visione che gli viene passato, decide se stampare i videogiochi con disponibile = false o no
            if(game.disponibile == false){
                continue;
            }
        }


        //stampa del gioco
        cout<<"--------------------------------------------------"<<endl;
        cout<<"Titolo: "<<game.titolo<<endl;
        cout<<"Console: "<<game.console<<endl;
        cout<<"Anno: "<<game.anno<<endl;
        cout<<"Prezzo: "<<game.prezzo<<endl;
        cout<<"Disponibile (1=disponibile,0=non disponibile): "<<game.disponibile<<endl;
        cout<<"--------------------------------------------------"<<endl;
    }
    fid.close(); //chiusura del file
}




void searchtitle(fstream& fid, const char* nome){
    videogioco ricerca; //Dichiarazione della struct che utilizzeremo come appoggio
    char name[50]; // Variabile per il titolo da cercare
    bool something=false; //variabile che mi dice se ha trovato qualcosa
    fid.open(nome,ios::binary | ios::in); //Apertura del file in modalità binaria e lettura
    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    cin.ignore(80, '\n');
    cout<<endl<<"inserisci il titolo da cercare: "<<endl;
    cin.get(name,20); //inserimento del titolo
    cin.ignore(80, '\n');








    while(fid.read((char*)&ricerca, sizeof(ricerca))){
        //ricerca del titolo all'interno del file
        if(strcmp(ricerca.titolo,name)==0){ //se trova qualcosa, stampa
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Titolo: "<<ricerca.titolo<<endl;
            cout<<"Console: "<<ricerca.console<<endl;
            cout<<"Anno: "<<ricerca.anno<<endl;
            cout<<"Prezzo: "<<ricerca.prezzo<<endl;
            cout<<"--------------------------------------------------"<<endl;
            something=true; //se trova qualcosa, lo dice impostando la variabile a true
        }
    }




    if(strcmp(ricerca.titolo,name)!=0 && fid.eof()&& something==false){ //se non trova assolutamente niente, è arrivato alla fine del file e something è false, restituisce un esito negativo
        cout<<"Nome non trovato."<<endl;
    }
    fid.close(); //chiude il file
}




void searchconsole(fstream& fid, const char* nome){
    videogioco ricerca; //Dichiarazione della struct che utilizzeremo come appoggio
    char name[50]; // Variabile per la console da cercare
    bool something=false; //variabile che mi dice se ha trovato qualcosa
    fid.open(nome,ios::binary | ios::in); //Apertura del file in modalità binaria e lettura
    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    cin.ignore(80, '\n');
    cout<<endl<<"inserisci la console da cercare: "<<endl;
    cin.get(name,20); //inserimento della console
    cin.ignore(80, '\n');








    while(fid.read((char*)&ricerca, sizeof(ricerca))){
        //ricerca della console all'interno del file
        if(strcmp(ricerca.console,name)==0){//se trova qualcosa, stampa
            cout<<"--------------------------------------------------"<<endl;
            cout<<"Titolo: "<<ricerca.titolo<<endl;
            cout<<"Console: "<<ricerca.console<<endl;
            cout<<"Anno: "<<ricerca.anno<<endl;
            cout<<"Prezzo: "<<ricerca.prezzo<<endl;
            cout<<"--------------------------------------------------"<<endl;
            something=true; //se trova qualcosa, lo dice impostando la variabile a true
        }
    }




    if(strcmp(ricerca.titolo,name)!=0 && fid.eof()&& something==false){ //se non trova assolutamente niente, è arrivato alla fine del file e something è false, restituisce un esito negativo
        cout<<"Nome non trovato."<<endl;
    }
    fid.close();//chiude il file
}




void mod(fstream& fid, const char* nome){
    videogioco ricerca; //Dichiarazione della struct che utilizzeremo come appoggio
    char name[50]; // Variabile per la console da cercare
    bool trovato=false; //variabile che mi dice se ha trovato qualcosa
    int pos=0; //posizione risultante della mia ricerca




    fid.open(nome,ios::binary | ios::in | ios::out ); //Apertura del file in modalità binaria, lettura e scrittura
    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    cin.ignore(80, '\n');
    cout<<endl<<"inserisci il titolo da cercare: "<<endl;
    cin.get(name,20); //inserimento del titolo
    cin.ignore(80, '\n');








    fid.read((char*)&ricerca, sizeof(ricerca)); //lettura del file
    while(!fid.eof()&& trovato==false){ //finché non trova qualcosa o non è arrivato alla fine del file, continua a cercare
        if(strcmp(name,ricerca.titolo)==0){ //se il titolo e l'input di ricerca sono uguali, il gioco è stato trovato.
            trovato=true; //se trova qualcosa, lo dice impostando la variabile a true
            pos=fid.tellg(); //gli dice a quale byte del file il prossimo comando di lettura inizierà a operare.
            pos=pos-sizeof(ricerca); // posizione definitiva del puntatore
        } else{
            fid.read((char*)&ricerca, sizeof(ricerca)); // se non trova nulla, continua a leggere
        }
    }
    if(trovato==false){ //se la variabile non cambia, vuol dire che non ha trovato nulla
        cout<<"Nome non trovato."<<endl;
    }else{
        fid.seekg(pos,ios::beg); //si punta all'inizio della struct
        cout<<"Videogioco trovato."<<endl;
        cout<<"inserisci il prezzo nuovo"<<endl;
        cin>>ricerca.prezzo;
        fid.write((char*)&ricerca,sizeof(ricerca)); //sovrascrive il prezzo nuovo
    }
    fid.close(); // chiude del file
}




void del(fstream& fid, const char* nome){
    videogioco ricerca;  //Dichiarazione della struct che utilizzeremo come appoggio
    char name[50]; // Variabile per la console da cercare
    bool trovato=false; //variabile che mi dice se ha trovato qualcosa
    int pos=0; //posizione risultante della mia ricerca
    char conf; // variabile che conferma o meno l'eliminazione




    fid.open(nome,ios::binary | ios::in | ios::out );//Apertura del file in modalità binaria, lettura e scrittura
    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    cin.ignore(80, '\n');
    cout<<endl<<"inserisci il titolo da cercare: "<<endl;
    cin.get(name,20); //inserimento del titolo
    cin.ignore(80, '\n');








    fid.read((char*)&ricerca, sizeof(ricerca)); //lettura del file
    while(!fid.eof()&& trovato==false){ //finché non trova qualcosa o non è arrivato alla fine del file, continua a cercare
        if(strcmp(name,ricerca.titolo)==0){//se il titolo e l'input di ricerca sono uguali, il gioco è stato trovato.
            trovato=true; //se trova qualcosa, lo dice impostando la variabile a true
            pos=fid.tellg(); //gli dice a quale byte del file il prossimo comando di lettura inizierà a operare.
            pos=pos-sizeof(ricerca); // posizione definitiva del puntatore




        } else{
            fid.read((char*)&ricerca, sizeof(ricerca)); // se non trova nulla, continua a leggere
        }
    }
    if(trovato==false){ //se la variabile non cambia, vuol dire che non ha trovato nulla
        cout<<"Gioco non trovato."<<endl;
    }else{
        fid.seekg(pos,ios::beg); //si punta all'inizio della struct
        cout<<"Gioco trovato."<<endl;
        cout<<"Sei sicuro di voler cancellare?(y/n)"<<endl;
        cin >> conf; //char che chiede all'utente se è sicuro dell'eliminazione
        if(conf=='y'){ //qualora fosse sicuro, procede alla cancellazione
            fid.seekp(pos,ios::beg); //si punta all'inizio della struct
            ricerca.disponibile=false;
            fid.write((char*)&ricerca,sizeof(ricerca)); //sovrascrive la nuova condizione
        }
        fid.close(); //chiude il file
    }}




int cont(fstream& fid,const char* nome){
    videogioco persona;//Dichiarazione della struct che utilizzeremo come appoggio
    int count = 0; //variabile per contare i videogiochi
    fid.open(nome,ios::binary | ios::in); //Apertura del file in modalità binaria e lettura
    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    while(fid.read((char*)&persona, sizeof(persona))){ //legge gli elementi all'interno del file
        count++;
    }
    fid.close(); //chiude il file
    return count; //restituisce il conteggio
}




void sortprice(fstream& fid, const char* nome) {
    int n=cont(fid,nome); //numero di giochi in tutto
    videogioco rubrica[n],persona,temp; //struct di appoggio




    fid.open(nome,ios::binary | ios::in | ios::out ); //Apertura del file in modalità binaria, lettura e scrittura
    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }


    for(int i=0;i<n;i++) { //copia il file in un array
        fid.read((char *) &persona, sizeof (videogioco));
        rubrica[i]=persona;
    }
    //utilizza il bubble sort per ordinarli secondo i prezzi
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1;j++) {
            if(rubrica[j].prezzo>rubrica[j+1].prezzo) {
                temp=rubrica[j];
                rubrica[j]=rubrica[j+1];
                rubrica[j+1]=temp;
            }
        }
    }


    fid.seekp(0, ios::beg); //ricomincia a leggere dall'inizio del file


    for (int i = 0; i < n; i++) {
        fid.write((char*)&rubrica[i], sizeof (videogioco)); //ricopia tutto l'array all'interno del file
    }
    cout<<"Giochi ordinati per prezzo"<<endl;
    fid.close(); // chiude il file
}




void sortyear(fstream& fid, const char* nome) {
    int n=cont(fid,nome); //numero di giochi in tutto
    videogioco rubrica[n],persona,temp;//struct di appoggio




    fid.open(nome,ios::binary | ios::in | ios::out ); //Apertura del file in modalità binaria, lettura e scrittura
    if(!fid){//Apertura del file in modalità binaria, lettura e scrittura
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }




    for(int i=0;i<n;i++) { //copia il file in un array
        fid.read((char *) &persona, sizeof (videogioco));
        rubrica[i]=persona;
    }
    //utilizza il bubble sort per ordinarli secondo i prezzi
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1;j++) {
            if(rubrica[j].anno>rubrica[j+1].anno) {
                temp=rubrica[j];
                rubrica[j]=rubrica[j+1];
                rubrica[j+1]=temp;
            }
        }
    }


    fid.seekp(0, ios::beg); //ricomincia a leggere dall'inizio del file


    for (int i = 0; i < n; i++) {
        fid.write((char*)&rubrica[i], sizeof (videogioco)); //ricopia tutto l'array all'interno del file
    }
    cout<<"Giochi ordinati per anno"<<endl;
    fid.close(); //chiude il file
}


void stats(fstream& fid,const char* nome){
    videogioco stats; //Dichiarazione della struct che utilizzeremo come appoggio
    int tot=0,todo=0, giochips=0,giochixbox=0,giochinintendo=0,giochipc=0,giochialtro=0; //variabili per contare i videogiochi per console
    float avg=0; //media dei prezzi dei videogiochi
    fid.open(nome,ios::binary | ios::in); //Apertura del file in modalità binaria e lettura
    if(!fid){ //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    while(fid.read((char*)&stats, sizeof(stats))){
        //insieme di if per contare il numero di videogiochi per ogni console
        //per il seguente while ho usato gemini AI per rimuovere un insieme di IF che non facevano funzionare il programma
        if (stats.disponibile == true) {
            tot++;
            avg += stats.prezzo;
            if (strcmp(stats.console, "ps") == 0) {
                giochips++;
                todo++;
            } else if (strcmp(stats.console, "xbox") == 0) {
                giochixbox++;
                todo++;
            } else if (strcmp(stats.console, "nintendo") == 0) {
                giochinintendo++;
                todo++;
            } else if (strcmp(stats.console, "pc") == 0) {
                giochipc++;
                todo++;
            }
        }




    }
    giochialtro=tot-todo;


    if (tot > 0) {
        //calcolo della media
        avg = avg / tot;
    }
    cout<<"--------------------------------------------------"<<endl;
    cout<<"STATISTICHE:"<<endl;
    cout<<"Giochi PS:"<<giochips<<endl;
    cout<<"Giochi XBOX:"<<giochixbox<<endl;
    cout<<"Giochi Nintendo:"<<giochinintendo<<endl;
    cout<<"Giochi PC:"<<giochipc<<endl;
    cout<<"Giochi di altre piattaforme:"<<giochialtro<<endl;
    cout<<"totale giochi:"<<tot<<endl;
    cout<<"Media: "<<avg<<endl;
    cout<<"--------------------------------------------------"<<endl;




    fid.close(); // chiude il file
}


void filter(fstream& fid, const char* nome) {
    videogioco game; //Dichiarazione della struct che utilizzeremo come appoggio
    int min,max; //range minimo e massimo
    char conf; //char di conferma
    bool wts; //want to see, se vuole vedere anche i valori non disponibili


    fid.open(nome,ios::binary | ios::in); //Apertura del file in modalità binaria e lettura
    if(!fid) { //Qualora dovesse esserci qualche problema nell'apertura del file, questo if manda un messaggio di errore
        cout<<"Errore."<<endl;
        getch();
        exit(1);
    }
    //inserimento del range, e scelta della visione dei videogiochi non disponibili
    cout<<"Inserisci il prezzo minimo per il filtro"<<endl;
    cin>>min;
    cout<<"Inserisci il prezzo massimo per il filtro"<<endl;
    cin>>max;
    cout<<"vuoi vedere anche i videogiochi non disponibili (y/n)?"<<endl;
    cin >> conf;
    if(conf=='y'){
        wts=true;
    }


    while(fid.read((char*)&game, sizeof(game))){
        if(game.prezzo<min && game.prezzo>max || wts==false && game.disponibile==false) { //se il gioco non è nel range, oppure se l'utente ha scelto di non vedere i giochi non disponibili, va avanti
            continue;
        }


        cout<<"--------------------------------------------------"<<endl;
        cout<<"Titolo: "<<game.titolo<<endl;
        cout<<"Console: "<<game.console<<endl;
        cout<<"Anno: "<<game.anno<<endl;
        cout<<"Prezzo: "<<game.prezzo<<endl;
        cout<<"Disponibile (1=disponibile,0=non disponibile): "<<game.disponibile<<endl;
        cout<<"--------------------------------------------------"<<endl;
    }
    fid.close(); //chiude il file
}
















int main()
{
    fstream fdip; // dichiarazione del file
    char nome[20]="giochi.txt"; //nome del file
    int scelta; //valore int da cui si può fare la scelta per lo switch
    bool vedere=true; // Variabile per la visualizzazione dei contenuti disponibili
    while (true){ //si ripete all'infinito
        //Menu di scelta
        cout<<"inserire scelta"<<endl;
        cout << "1. Aggiungi Giochi all'elenco " << endl;
        cout << "2. Stampa Giochi (disponibili e non)" << endl;
        cout << "3. Cerca un Gioco per titolo" << endl;
        cout << "4. Cerca un Gioco per console" << endl;
        cout << "5. Modifica il prezzo di un Gioco" << endl;
        cout << "6. Cancella un Gioco" << endl;
        cout << "7. Ordina i Giochi per prezzo" << endl;
        cout << "8. Ordina i Giochi per anno" << endl;
        cout << "9. Stampa Giochi (solo disponibili)" << endl;
        cout << "10. Mostra statistiche" << endl;
        cout << "11. Visualizza Giochi entro un range di prezzi" << endl;
        cout << "Inserisci la tua scelta: ";
        cin >> scelta;

        switch(scelta){ //switch con i diversi casi

            case 1:
                agg(fdip,nome);
                break;

            case 2:
                vedere=true;
                print(fdip,nome,vedere);
                break;

            case 3:
                searchtitle(fdip,nome);
                break;

            case 4:
                searchconsole(fdip,nome);
                break;

            case 5:
                mod(fdip,nome);
                break;

            case 6:
                del(fdip,nome);
                break;

            case 7:
                sortprice(fdip,nome);
                break;

            case 8:
                sortyear(fdip,nome);
                break;

            case 9:
                vedere=false;
                print(fdip,nome,vedere);
                break;

            case 10:
                stats(fdip,nome);
                break;

            case 11:
                filter(fdip,nome);
                break;
        }
    }
    return 0;
}//
// Created by manuel di pino on 23-Oct-25.













