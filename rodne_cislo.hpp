#ifndef RODNE_CISLO_HPP
#define RODNE_CISLO_HPP
#include <string>
#include <iostream>

using std::string;
const string default_rc = "9999999999";

class rodne_cislo {
public:
    rodne_cislo();
    rodne_cislo(const rodne_cislo& orig);
    rodne_cislo(string);
    virtual ~rodne_cislo();
    
    string pohlavi()const;
    string getRc()const;
    bool setRc(string);
    string datumNarozeni()const;
    int vek()const;
    
private:
    string rc;
    bool kontrolaRc(string)const;
    int rok()const;
    int mesic()const;
    int den()const;
    
};
std::ostream& operator<<(std::ostream&, const rodne_cislo&);
#endif

