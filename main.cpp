#include "rodne_cislo.hpp"
using std::endl;
using std::cin;
using std::cout;
using std::string;

int main(int argc, char** argv) {
    rodne_cislo rc1;
    rodne_cislo rc2 ("6462191472");
    rodne_cislo rc3 (rc2);
    string rc;
    bool chyba = false;
    cout<<"Objekt vytvoren vychozim konstruktorem"<< endl;
    cout <<rc1<<endl;
    cout<<"Objekt vytvoreny konstruktorem s parametrem"<<endl;
    cout<<rc2<<endl;
    cout<<"Objekt vytvoren kopirovacim konstruktorem"<<endl;
    cout<<rc3<<endl;
    do{
    cout<<"Zadejte rodne cislo: "<<endl;
    cin>>rc;
    if(rc1.setRc(rc)){
        cout<<"Objekt rc1 po zmene: "<<endl;
        cout<<rc1<<endl;
    }
    else{
        cout<<"Chybne zadane rodne cislo"<<endl;
        chyba = true;
        
    }
    }while(!chyba);
    return 0;
}

