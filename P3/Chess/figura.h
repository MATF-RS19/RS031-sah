#ifndef FIGURA_H
#define FIGURA_H
#include "boja.h"
#include <QString>
#include "oznaka.h"

class Figura{
public:
    Figura();
    virtual ~Figura();
    virtual QOznaka Oznaka()const=0;
    virtual QBoja Boja()const=0;
    virtual QString Slicica()const=0;
protected:
    QString slicica;
    QOznaka oznaka;
    QBoja boja;
private:
    Figura& operator=(const Figura&);
    Figura(const Figura&);
    Figura& operator=(Figura&&);
    Figura(Figura&&);
};

class Pijun:public Figura{
public:
    Pijun(const QBoja&);
    QString Slicica()const;
    QOznaka Oznaka()const;
    QBoja Boja()const;
};

class Top:public Figura{
public:
    Top(const QBoja&);
    QString Slicica()const;
    QOznaka Oznaka()const;
    QBoja Boja()const;
};

class Konj:public Figura{
public:
    Konj(const QBoja&);
    QString Slicica()const;
    QOznaka Oznaka()const;
    QBoja Boja()const;
};

class Lovac:public Figura{
public:
    Lovac(const QBoja&);
    QString Slicica()const;
    QOznaka Oznaka()const;
    QBoja Boja()const;
};

class Kraljica:public Figura{
public:
    Kraljica(const QBoja&);
    QString Slicica()const;
    QOznaka Oznaka()const;
    QBoja Boja()const;
};

class Kralj:public Figura{
public:
    Kralj(const QBoja&);
    QString Slicica()const;
    QOznaka Oznaka()const;
    QBoja Boja()const;
};

#endif // FIGURA_H
