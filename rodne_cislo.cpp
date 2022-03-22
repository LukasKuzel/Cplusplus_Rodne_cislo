#include "rodne_cislo.hpp"
#include <ctime>

rodne_cislo::rodne_cislo() {
    this->rc = default_rc;
}

rodne_cislo::rodne_cislo(const rodne_cislo& orig) {
    this->rc = orig.getRc();
}

rodne_cislo::rodne_cislo(string rc) {
    if (!setRc(rc)) {
        this->rc = default_rc;
    }
}

string rodne_cislo::getRc() const {
    return this->rc;
}

rodne_cislo::~rodne_cislo() {
}

bool rodne_cislo::kontrolaRc(string rc)const {
    /*ziskani prvnich deviti cifer rc*/
    if(rc.length()!=10){
        return false;
    }
    string prvnich9 = rc.substr(0, 9);
    int zbytek = std::stoi(prvnich9) % 11;
    int kontrolniCislice = std::stoi(rc.substr(9, 1));
    if (zbytek == kontrolniCislice) {
        return true;
    } else if (zbytek == 10 && kontrolniCislice == 0) {
        return true;
    } else {
        return false;
    }
}

bool rodne_cislo::setRc(string rc) {
    if (this->kontrolaRc(rc)) {
        this->rc = rc;
        return true;
    } else {
        return false;
    }
}


std::ostream& operator<<(std::ostream&os, const rodne_cislo& rc) {
    os << "Rodne cislo: " << rc.getRc() << std::endl;
    os << "Datum narozeni: " << rc.datumNarozeni() << std::endl;
    os << "Pohlavi: "<<rc.pohlavi()<<std::endl;
    os << "Vek: "<<rc.vek()<<std::endl;
    return os;
}
string rodne_cislo::pohlavi() const{
    int m = std::stoi(this->rc.substr(2, 2));
    if (this->rc == default_rc) {
        return "";
    }
    return m>50 ? "Zena" : "Muz";
}
int rodne_cislo::vek() const{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int vek = (timeinfo ->tm_year + 1900) - this->rok();
    if (this->rc == default_rc) {
        return 0;
    }
    if(this->mesic() > (timeinfo->tm_mon +1)){
        vek --;
    }
    else if(this->mesic() == (timeinfo->tm_mon+1) && this->den() > timeinfo->tm_mday){
        vek --;
    }
    return vek;
}

int rodne_cislo::rok()const {
    int r = std::stoi(this->rc.substr(0, 2));
    return r >= 54 ? (r + 1900) : (r + 2000);

}

int rodne_cislo::mesic()const {
    int m = std::stoi(this->rc.substr(2, 2));
    return m > 50 ? m - 50 : m;
}

int rodne_cislo::den()const {
    int d = std::stoi(this->rc.substr(4, 2));
    return d;
}

string rodne_cislo::datumNarozeni() const {
    return this->rc == default_rc ? "" : (std::to_string(this->den()) + ". "
            + std::to_string(this->mesic()) + ". "
            + std::to_string(this->rok()));
}