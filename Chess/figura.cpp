#include "figura.h"

Figura::~Figura(){}
Figura::Figura(){}

Pijun::Pijun(const QBoja& b){
    boja=b;
    oznaka=QOznaka::pijun;
    if(b==QBoja::bela){
        slicica=":/Slike/beli_pijun.png";
    }
    else{
        slicica=":/Slike/crni_pijun.png";
    }
}

Top::Top(const QBoja& b){
    boja=b;
    oznaka=QOznaka::top;
    if(b==QBoja::bela){
        slicica=":/Slike/beli_top.png";
    }
    else{
        slicica=":/Slike/crni_top.png";
    }
}

Konj::Konj(const QBoja& b){
    boja=b;
    oznaka=QOznaka::konj;
    if(b==QBoja::bela){
        slicica=":/Slike/beli_konj.png";
    }
    else{
        slicica=":/Slike/crni_konj.png";
    }
}

Lovac::Lovac(const QBoja& b){
    boja=b;
    oznaka=QOznaka::lovac;
    if(b==QBoja::bela){
        slicica=":/Slike/beli_lovac.png";
    }
    else{
        slicica=":/Slike/crni_lovac.png";
    }
}

Kraljica::Kraljica(const QBoja& b){
    boja=b;
    oznaka=QOznaka::kraljica;
    if(b==QBoja::bela){
        slicica=":/Slike/bela_kraljica.png";
    }
    else{
        slicica=":/Slike/crna_kraljica.png";
    }
}

Kralj::Kralj(const QBoja& b){
    boja=b;
    oznaka=QOznaka::kralj;
    if(b==QBoja::bela){
        slicica=":/Slike/beli_kralj.png";
    }
    else{
        slicica=":/Slike/crni_kralj.png";
    }
}


QString Pijun::Slicica() const{return slicica;}
QString Top::Slicica() const{return slicica;}
QString Konj::Slicica() const{return slicica;}
QString Lovac::Slicica() const{return slicica;}
QString Kraljica::Slicica() const{return slicica;}
QString Kralj::Slicica() const{return slicica;}

QOznaka Pijun::Oznaka()const{
    return oznaka;
}
QOznaka Top::Oznaka()const{
    return oznaka;
}
QOznaka Konj::Oznaka()const{
    return oznaka;
}
QOznaka Lovac::Oznaka()const{
    return oznaka;
}
QOznaka Kraljica::Oznaka()const{
    return oznaka;
}
QOznaka Kralj::Oznaka()const{
    return oznaka;
}

QBoja Pijun::Boja()const{
    return boja;
}
QBoja Top::Boja()const{
    return boja;
}
QBoja Konj::Boja()const{
    return boja;
}
QBoja Lovac::Boja()const{
    return boja;
}
QBoja Kraljica::Boja()const{
    return boja;
}
QBoja Kralj::Boja()const{
    return boja;
}
