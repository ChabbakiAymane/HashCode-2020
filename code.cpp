#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct biblioteca{
    int nBooks;
    int nDays;
    vector<int> books;
    int somma = 0;
    int priorita = 0;
    int nBookDay;
    int numLib;
    int lastBook = -1;
}biblioteca;


int compare(const void * a, const void * b){ 
    biblioteca *bib1 = (biblioteca*) a;
    biblioteca *bib2 = (biblioteca*) b;
    return (bib2->priorita - bib1->priorita); 
}

struct Less{
    bool operator()( const biblioteca& lx, const biblioteca& rx ) const {
        return lx.priorita > rx.priorita;
    }
};

int main(){
    int books, libraries, days;
    vector<int> scores;
    vector<biblioteca> library;

    ifstream in("input.txt");
	in >> books >> libraries >> days; //libri totali, numero di librerie e deadline

    scores.resize(books);
    for(int i = 0; i < books; i++){
        in >> scores[i]; //assegno score di libri
    }

    library.resize(libraries);

    for(int i = 0; i < libraries; i++){
        library[i].numLib = i;
        in >> library[i].nBooks >> library[i].nDays >> library[i].nBookDay; //assegno numero di libri e giorno di signup
        library[i].books.resize(library[i].nBooks);
        for(int j = 0; j < library[i].nBooks; j++){
            in >> library[i].books[j]; //inserisco i libri nella libreria
            library[i].somma += scores[library[i].books[j]]; //somma dei score dei libri
        }
        library[i].priorita = (((library[i].somma / library[i].nBooks) * library[i].nBookDay) * (days - library[i].nDays)); //FORMULA MAGICA
    }

    //ORA DOBBIAMO ORDINARLE in base ai money che fruttano
    sort(library.begin(), library.end(), Less());

    int lastLib = -1;
    int signup = 0;
    
    //IL VERO CODICE
    for(int i = 0; i < days; i++){
        signup--;
        if(signup <= 0 && lastLib < libraries){
            lastLib++;
            signup = library[lastLib].nDays;
        }
        for(int j = 0; j < lastLib; j++){
            for(int k = 0; k < library[j].nBookDay; k++){
                if(library[j].lastBook < library[j].nBooks){
                    //CONTROLLO LIBRO GIA INVIATO
                    library[j].lastBook++;
                }
            }
        }
    }

    ofstream out("output.txt");

    out << lastLib << endl;

    for(int i = 0; i < lastLib; i++){
        out << library[i].numLib << " " << library[i].lastBook << endl;
        for(int j = 0; j < library[i].lastBook; j++){
            out << library[i].books[j] << " ";
        }
        out << endl;
    }
}