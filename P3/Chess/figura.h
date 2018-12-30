#ifndef FIGURA_H
#define FIGURA_H
#include "boja.h"
#include <QString>

class Figura{
public:
    Figura();
    virtual ~Figura();
    virtual QString Oznaka()const=0;
    virtual QBoja Boja()const=0;
    virtual QString Slicica()const=0;
protected:
    QString slicica;
    QString oznaka;
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
    QString Oznaka()const;
    QBoja Boja()const;
};

class Top:public Figura{
public:
    Top(const QBoja&);
    QString Slicica()const;
    QString Oznaka()const;
    QBoja Boja()const;
};

class Konj:public Figura{
public:
    Konj(const QBoja&);
    QString Slicica()const;
    QString Oznaka()const;
    QBoja Boja()const;
};

class Lovac:public Figura{
public:
    Lovac(const QBoja&);
    QString Slicica()const;
    QString Oznaka()const;
    QBoja Boja()const;
};

class Kraljica:public Figura{
public:
    Kraljica(const QBoja&);
    QString Slicica()const;
    QString Oznaka()const;
    QBoja Boja()const;
};

class Kralj:public Figura{
public:
    Kralj(const QBoja&);
    QString Slicica()const;
    QString Oznaka()const;
    QBoja Boja()const;
};

#endif // FIGURA_H
