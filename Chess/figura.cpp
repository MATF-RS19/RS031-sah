#include "figura.h"

Figura::~Figura(){}

Pijun::Pijun(const QBoja& b){
    boja=b;
}

Top::Top(const QBoja& b){
    boja=b;
}

Konj::Konj(const QBoja& b){
    boja=b;
}

Lovac::Lovac(const QBoja& b){
    boja=b;
}

Kraljica::Kraljica(const QBoja& b){
    boja=b;
}

Kralj::Kralj(const QBoja& b){
    boja=b;
}


QString Pijun::Slicica() const{    if(boja==QBoja::bela){
        return ":/Slike/beli_pijun.png";
    }
    else{
        return ":/Slike/crni_pijun.png";
    }}
QString Top::Slicica() const{    if(boja==QBoja::bela){
        return ":/Slike/beli_top.png";
    }
    else{
        return ":/Slike/crni_top.png";
    };}
QString Konj::Slicica() const{       if(boja==QBoja::bela){ return":/Slike/beli_konj.png";
                             }
                             else{
                                 return ":/Slike/crni_konj.png";
                             }}
QString Lovac::Slicica() const{    if(boja==QBoja::bela){
        return ":/Slike/beli_lovac.png";
    }
    else{
        return ":/Slike/crni_lovac.png";
    }}
QString Kraljica::Slicica() const{    if(boja==QBoja::bela){
        return ":/Slike/bela_kraljica.png";
    }
    else{
        return ":/Slike/crna_kraljica.png";
    }}
QString Kralj::Slicica() const{    if(boja==QBoja::bela){
        return ":/Slike/beli_kralj.png";
    }
    else{
        return ":/Slike/crni_kralj.png";
    }}

QOznaka Pijun::Oznaka()const{
    return QOznaka::pijun ;
}
QOznaka Top::Oznaka()const{
    return QOznaka::top ;
}
QOznaka Konj::Oznaka()const{
    return QOznaka::konj ;
}
QOznaka Lovac::Oznaka()const{
    return QOznaka::lovac ;
}
QOznaka Kraljica::Oznaka()const{
    return QOznaka::kraljica ;
}
QOznaka Kralj::Oznaka()const{
    return QOznaka::kralj ;
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
