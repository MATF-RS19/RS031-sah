#include "chess.h"
#include "ui_chess.h"
#include "figura.h"

Chess::Chess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chess),
    mapa(),
    stanje(QStanje::beliIgrac_pocetakPoteza),
    pKlik(64),
    brojPoteza(0),
    kingsideCrniTop(true),
    queensideCrniTop(true),
    kingsideBeliTop(true),
    queensideBeliTop(true),
    crniKralj(true),
    beliKralj(true)
{
    ui->setupUi(this);

    polja=new bool[64];
    QPixmap tabla(":/Slike/tabla.jpg");
    ui->label_tabla->setPixmap(tabla.scaled(1000,1000,Qt::KeepAspectRatio));
    p0=new Pijun(QBoja::bela);
    t0=new Top(QBoja::bela);
    k0=new Konj(QBoja::bela);
    l0=new Lovac(QBoja::bela);
    y0=new Kraljica(QBoja::bela);
    x0=new Kralj(QBoja::bela);
    p1=new Pijun(QBoja::crna);
    t1=new Top(QBoja::crna);
    k1=new Konj(QBoja::crna);
    l1=new Lovac(QBoja::crna);
    y1=new Kraljica(QBoja::crna);
    x1=new Kralj(QBoja::crna);

    inicijalizujTablu();

}

Chess::~Chess()
{
    delete p0;
    delete p1;
    delete t0;
    delete t1;
    delete k0;
    delete k1;
    delete l0;
    delete l1;
    delete y0;
    delete y1;
    delete x0;
    delete x1;

    delete[] polja;

    delete ui;
}

void Chess::crtaj(Figura* f,QLabel* l){
    QPixmap p(f->Slicica());
    l->setPixmap(p.scaled(90,90,Qt::KeepAspectRatio));
    l->setAlignment(Qt::AlignCenter);
}
void Chess::inicijalizujTablu(){

    crtaj(t1,ui->label_00);
    crtaj(k1,ui->label_01);
    crtaj(l1,ui->label_02);
    crtaj(y1,ui->label_03);
    crtaj(x1,ui->label_04);
    crtaj(l1,ui->label_05);
    crtaj(k1,ui->label_06);
    crtaj(t1,ui->label_07);
    crtaj(p1,ui->label_10);
    crtaj(p1,ui->label_11);
    crtaj(p1,ui->label_12);
    crtaj(p1,ui->label_13);
    crtaj(p1,ui->label_14);
    crtaj(p1,ui->label_15);
    crtaj(p1,ui->label_08);
    crtaj(p1,ui->label_09);
    crtaj(p0,ui->label_48);
    crtaj(p0,ui->label_49);
    crtaj(p0,ui->label_50);
    crtaj(p0,ui->label_51);
    crtaj(p0,ui->label_52);
    crtaj(p0,ui->label_53);
    crtaj(p0,ui->label_54);
    crtaj(p0,ui->label_55);
    crtaj(t0,ui->label_56);
    crtaj(k0,ui->label_57);
    crtaj(l0,ui->label_58);
    crtaj(y0,ui->label_59);
    crtaj(x0,ui->label_60);
    crtaj(l0,ui->label_61);
    crtaj(k0,ui->label_62);
    crtaj(t0,ui->label_63);

    mapa[labelToInt(ui->label_00)]=t1;
    mapa[labelToInt(ui->label_01)]=k1;
    mapa[labelToInt(ui->label_02)]=l1;
    mapa[labelToInt(ui->label_03)]=y1;
    mapa[labelToInt(ui->label_04)]=x1;
    mapa[labelToInt(ui->label_05)]=l1;
    mapa[labelToInt(ui->label_06)]=k1;
    mapa[labelToInt(ui->label_07)]=t1;
    mapa[labelToInt(ui->label_10)]=p1;
    mapa[labelToInt(ui->label_11)]=p1;
    mapa[labelToInt(ui->label_12)]=p1;
    mapa[labelToInt(ui->label_13)]=p1;
    mapa[labelToInt(ui->label_14)]=p1;
    mapa[labelToInt(ui->label_15)]=p1;
    mapa[labelToInt(ui->label_08)]=p1;
    mapa[labelToInt(ui->label_09)]=p1;
    mapa[labelToInt(ui->label_48)]=p0;
    mapa[labelToInt(ui->label_49)]=p0;
    mapa[labelToInt(ui->label_50)]=p0;
    mapa[labelToInt(ui->label_51)]=p0;
    mapa[labelToInt(ui->label_52)]=p0;
    mapa[labelToInt(ui->label_53)]=p0;
    mapa[labelToInt(ui->label_54)]=p0;
    mapa[labelToInt(ui->label_55)]=p0;
    mapa[labelToInt(ui->label_56)]=t0;
    mapa[labelToInt(ui->label_57)]=k0;
    mapa[labelToInt(ui->label_58)]=l0;
    mapa[labelToInt(ui->label_59)]=y0;
    mapa[labelToInt(ui->label_60)]=x0;
    mapa[labelToInt(ui->label_61)]=l0;
    mapa[labelToInt(ui->label_62)]=k0;
    mapa[labelToInt(ui->label_63)]=t0;

    for (int i=0;i<48;++i) {
        intToButton(i)->setEnabled(false);
    }
    for (int i=48;i<56;++i) {
        intToButton(i)->setEnabled(true);
    }
    for (int i=56;i<64;++i) {
        intToButton(i)->setEnabled(false);
    }
    ui->pushButton_57->setEnabled(true);
    ui->pushButton_62->setEnabled(true);
}

int Chess::labelToInt(QLabel * l) const{
    return l->objectName().right(2).toInt();
}
QLabel* Chess::intToLabel(int u) const{
    QLabel* l=nullptr;
    switch (u) {
    case 0:
        l=ui->label_00;
        break;
    case 1:
        l=ui->label_01;
        break;
    case 2:
        l=ui->label_02;
        break;
    case 3:
        l=ui->label_03;
        break;
    case 4:
        l=ui->label_04;
        break;
    case 5:
        l=ui->label_05;
        break;
    case 6:
        l=ui->label_06;
        break;
    case 7:
        l=ui->label_07;
        break;
    case 8:
        l=ui->label_08;
        break;
    case 9:
        l=ui->label_09;
        break;
    case 10:
        l=ui->label_10;
        break;
    case 11:
        l=ui->label_11;
        break;
    case 12:
        l=ui->label_12;
        break;
    case 13:
        l=ui->label_13;
        break;
    case 14:
        l=ui->label_14;
        break;
    case 15:
        l=ui->label_15;
        break;
    case 16:
        l=ui->label_16;
        break;
    case 17:
        l=ui->label_17;
        break;
    case 18:
        l=ui->label_18;
        break;
    case 19:
        l=ui->label_19;
        break;
    case 20:
        l=ui->label_20;
        break;
    case 21:
        l=ui->label_21;
        break;
    case 22:
        l=ui->label_22;
        break;
    case 23:
        l=ui->label_23;
        break;
    case 24:
        l=ui->label_24;
        break;
    case 25:
        l=ui->label_25;
        break;
    case 26:
        l=ui->label_26;
        break;
    case 27:
        l=ui->label_27;
        break;
    case 28:
        l=ui->label_28;
        break;
    case 29:
        l=ui->label_29;
        break;
    case 30:
        l=ui->label_30;
        break;
    case 31:
        l=ui->label_31;
        break;
    case 32:
        l=ui->label_32;
        break;
    case 33:
        l=ui->label_33;
        break;
    case 34:
        l=ui->label_34;
        break;
    case 35:
        l=ui->label_35;
        break;
    case 36:
        l=ui->label_36;
        break;
    case 37:
        l=ui->label_37;
        break;
    case 38:
        l=ui->label_38;
        break;
    case 39:
        l=ui->label_39;
        break;
    case 40:
        l=ui->label_40;
        break;
    case 41:
        l=ui->label_41;
        break;
    case 42:
        l=ui->label_42;
        break;
    case 43:
        l=ui->label_43;
        break;
    case 44:
        l=ui->label_44;
        break;
    case 45:
        l=ui->label_45;
        break;
    case 46:
        l=ui->label_46;
        break;
    case 47:
        l=ui->label_47;
        break;
    case 48:
        l=ui->label_48;
        break;
    case 49:
        l=ui->label_49;
        break;
    case 50:
        l=ui->label_50;
        break;
    case 51:
        l=ui->label_51;
        break;
    case 52:
        l=ui->label_52;
        break;
    case 53:
        l=ui->label_53;
        break;
    case 54:
        l=ui->label_54;
        break;
    case 55:
        l=ui->label_55;
        break;
    case 56:
        l=ui->label_56;
        break;
    case 57:
        l=ui->label_57;
        break;
    case 58:
        l=ui->label_58;
        break;
    case 59:
        l=ui->label_59;
        break;
    case 60:
        l=ui->label_60;
        break;
    case 61:
        l=ui->label_61;
        break;
    case 62:
        l=ui->label_62;
        break;
    default:
        l=ui->label_63;
    }
    return l;
}
QPushButton* Chess::intToButton(int u) const{
    QPushButton* l=nullptr;
    switch (u) {
    case 0:
        l=ui->pushButton_00;
        break;
    case 1:
        l=ui->pushButton_01;
        break;
    case 2:
        l=ui->pushButton_02;
        break;
    case 3:
        l=ui->pushButton_03;
        break;
    case 4:
        l=ui->pushButton_04;
        break;
    case 5:
        l=ui->pushButton_05;
        break;
    case 6:
        l=ui->pushButton_06;
        break;
    case 7:
        l=ui->pushButton_07;
        break;
    case 8:
        l=ui->pushButton_08;
        break;
    case 9:
        l=ui->pushButton_09;
        break;
    case 10:
        l=ui->pushButton_10;
        break;
    case 11:
        l=ui->pushButton_11;
        break;
    case 12:
        l=ui->pushButton_12;
        break;
    case 13:
        l=ui->pushButton_13;
        break;
    case 14:
        l=ui->pushButton_14;
        break;
    case 15:
        l=ui->pushButton_15;
        break;
    case 16:
        l=ui->pushButton_16;
        break;
    case 17:
        l=ui->pushButton_17;
        break;
    case 18:
        l=ui->pushButton_18;
        break;
    case 19:
        l=ui->pushButton_19;
        break;
    case 20:
        l=ui->pushButton_20;
        break;
    case 21:
        l=ui->pushButton_21;
        break;
    case 22:
        l=ui->pushButton_22;
        break;
    case 23:
        l=ui->pushButton_23;
        break;
    case 24:
        l=ui->pushButton_24;
        break;
    case 25:
        l=ui->pushButton_25;
        break;
    case 26:
        l=ui->pushButton_26;
        break;
    case 27:
        l=ui->pushButton_27;
        break;
    case 28:
        l=ui->pushButton_28;
        break;
    case 29:
        l=ui->pushButton_29;
        break;
    case 30:
        l=ui->pushButton_30;
        break;
    case 31:
        l=ui->pushButton_31;
        break;
    case 32:
        l=ui->pushButton_32;
        break;
    case 33:
        l=ui->pushButton_33;
        break;
    case 34:
        l=ui->pushButton_34;
        break;
    case 35:
        l=ui->pushButton_35;
        break;
    case 36:
        l=ui->pushButton_36;
        break;
    case 37:
        l=ui->pushButton_37;
        break;
    case 38:
        l=ui->pushButton_38;
        break;
    case 39:
        l=ui->pushButton_39;
        break;
    case 40:
        l=ui->pushButton_40;
        break;
    case 41:
        l=ui->pushButton_41;
        break;
    case 42:
        l=ui->pushButton_42;
        break;
    case 43:
        l=ui->pushButton_43;
        break;
    case 44:
        l=ui->pushButton_44;
        break;
    case 45:
        l=ui->pushButton_45;
        break;
    case 46:
        l=ui->pushButton_46;
        break;
    case 47:
        l=ui->pushButton_47;
        break;
    case 48:
        l=ui->pushButton_48;
        break;
    case 49:
        l=ui->pushButton_49;
        break;
    case 50:
        l=ui->pushButton_50;
        break;
    case 51:
        l=ui->pushButton_51;
        break;
    case 52:
        l=ui->pushButton_52;
        break;
    case 53:
        l=ui->pushButton_53;
        break;
    case 54:
        l=ui->pushButton_54;
        break;
    case 55:
        l=ui->pushButton_55;
        break;
    case 56:
        l=ui->pushButton_56;
        break;
    case 57:
        l=ui->pushButton_57;
        break;
    case 58:
        l=ui->pushButton_58;
        break;
    case 59:
        l=ui->pushButton_59;
        break;
    case 60:
        l=ui->pushButton_60;
        break;
    case 61:
        l=ui->pushButton_61;
        break;
    case 62:
        l=ui->pushButton_62;
        break;
    default:
        l=ui->pushButton_63;
    }
    return l;
}
void Chess::allButtonsDisable(){
    for(int i=0;i<64;++i)
        intToButton(i)->setEnabled(false);
}
void Chess::Polja(){
    for(int i=0;i<64;++i)
        intToButton(i)->setEnabled(polja[i]);
}
void Chess::setPolja(){
    for(int i=0;i<64;++i)
        polja[i]=intToButton(i)->isEnabled();
}

void Chess::figuraNapadaPolja(int u,bool* a){
    if(!mapa.contains(u))
        qFatal("figuraNapadaPolja");
    Figura* f=mapa[u];
    if(f->Oznaka()==QOznaka::pijun && f->Boja()==QBoja::bela){
        if(u-7>-1 && (u-7)%8!=0)
            a[u-7]=true;
        if(u-9>-1 && u%8!=0)
            a[u-9]=true;
    }
    else if(f->Oznaka()==QOznaka::pijun && f->Boja()==QBoja::crna){
        if(u+7<64 && u%8!=0)
            a[u+7]=true;
        if(u+9<64 && (u+9)%8!=0)
            a[u+9]=true;
    }
    else if(f->Oznaka()==QOznaka::top){
        int i;
        for(i=1;u+i<64 && (u+i)%8!=0 && !mapa.contains(u+i);++i)
            a[u+i]=true;
        if((u+i)%8!=0)
            a[u+i]=true;

        for(i=1;u-i>-1 && (1+u-i)%8!=0 && !mapa.contains(u-i);++i)
            a[u-i]=true;
        if((1+u-i)%8!=0)
            a[u-i]=true;

        for(i=1;u+8*i<64 && !mapa.contains(u+8*i);++i)
            a[u+8*i]=true;
        if(u+8*i<64)
            a[u+8*i]=true;

        for(i=1;u+1-8*i>0 && !mapa.contains(u-8*i);++i)
            a[u-8*i]=true;
        if(u+1-8*i>0)
            a[u-8*i]=true;
    }
    else if(f->Oznaka()==QOznaka::konj){
        if(u-17>-1 && u%8!=0)
            a[u-17]=true;
        if(u-15>-1 && (u+1)%8!=0)
            a[u-15]=true;
        if(u+15<64 && u%8!=0)
            a[u+15]=true;
        if(u+17<64 && (u+1)%8!=0)
            a[u+17]=true;
        if(u-10>-1 && u%8!=0 && (u-1)%8!=0)
            a[u-10]=true;
        if(u-6>-1 && (u+1)%8!=0 && (u+2)%8!=0)
            a[u-6]=true;
        if(u+6<64 && u%8!=0 && (u-1)%8!=0)
            a[u+6]=true;
        if(u+10<64 && (u+1)%8!=0 && (u+2)%8!=0)
            a[u+10]=true;
    }
    else if(f->Oznaka()==QOznaka::lovac){
        int i;
        for(i=1;u-9*i>-1 && (u-i+1)%8!=0 && !mapa.contains(u-9*i);++i)
            a[u-9*i]=true;
        if(u-9*i>-1 && (u-i+1)%8!=0)
            a[u-9*i]=true;

        for(i=1;u-7*i>-1 && (u+i)%8!=0 && !mapa.contains(u-7*i);++i)
            a[u-7*i]=true;
        if(u-7*i>-1 && (u+i)%8!=0)
            a[u-7*i]=true;

        for(i=1;u+9*i<64 && (u+i)%8!=0 && !mapa.contains(u+9*i);++i)
            a[u+9*i]=true;
        if(u+9*i<64 && (u+i)%8!=0)
            a[u+9*i]=true;

        for(i=1;u+7*i<64 && (u+7*i+1)%8!=0 && !mapa.contains(u+7*i);++i)
            a[u+7*i]=true;
        if(u+7*i<64 && (u+7*i+1)%8!=0)
            a[u+7*i]=true;
    }
    else if(f->Oznaka()==QOznaka::kraljica){
        int i;
        for(i=1;u-9*i>-1 && (u-9*i+1)%8!=0 && !mapa.contains(u-9*i);++i)
            a[u-9*i]=true;
        if(u-9*i>-1 && (u-9*i+1)%8!=0)
            a[u-9*i]=true;

        for(i=1;u-7*i>-1 && (u-7*i)%8!=0 && !mapa.contains(u-7*i);++i)
            a[u-7*i]=true;
        if(u-7*i>-1 && (u-7*i)%8!=0)
            a[u-7*i]=true;

        for(i=1;u+9*i<64 && (u+9*i)%8!=0 && !mapa.contains(u+9*i);++i)
            a[u+9*i]=true;
        if(u+9*i<64 && (u+9*i)%8!=0)
            a[u+9*i]=true;

        for(i=1;u+7*i<64 && (u+7*i+1)%8!=0 && !mapa.contains(u+7*i);++i)
            a[u+7*i]=true;
        if(u+7*i<64 && (u+7*i+1)%8!=0)
            a[u+7*i]=true;

        for(i=1;u+i<64 && (u+i)%8!=0 && !mapa.contains(u+i);++i)
            a[u+i]=true;
        if((u+i)%8!=0)
            a[u+i]=true;

        for(i=1;u-i>-1 && (1+u-i)%8!=0 && !mapa.contains(u-i);++i)
            a[u-i]=true;
        if((1+u-i)%8!=0)
            a[u-i]=true;

        for(i=1;u+8*i<64 && !mapa.contains(u+8*i);++i)
            a[u+8*i]=true;
        if(u+8*i<64)
            a[u+8*i]=true;

        for(i=1;u+1-8*i>0 && !mapa.contains(u-8*i);++i)
            a[u-8*i]=true;
        if(u+1-8*i>0)
            a[u-8*i]=true;
    }
    else if(f->Oznaka()==QOznaka::kralj){
        if(u+1<64 && (u+1)%8!=0)
            a[u+1]=true;
        if(u+8<64)
            a[u+8]=true;
        if(u+9<64 && (u+1)%8!=0)
            a[u+9]=true;
        if(u+7<64 && u%8!=0)
            a[u+7]=true;
        if(u-1>-1 && u%8!=0)
            a[u-1]=true;
        if(u-8>-1)
            a[u-8]=true;
        if(u-9>-1 && u%8!=0)
            a[u-9]=true;
        if(u-7>-1 && (u+1)%8!=0)
            a[u-7]=true;
    }
}

void Chess::changeButtons(int u){
    if(!mapa.contains(u))
        qFatal("changeButtons::mapa nema u");
    Figura* f=mapa[u];
    intToButton(u)->setEnabled(true);
    if(f->Oznaka()==QOznaka::pijun && f->Boja()==QBoja::bela){
        if(u>7 && !mapa.contains(u-8))
            intToButton(u-8)->setEnabled(true);
        if(mapa.contains(u-7) && (u+1)%8!=0 && mapa[u-7]->Boja()==QBoja::crna)
            intToButton(u-7)->setEnabled(true);
        if(mapa.contains(u-9) && u%8!=0 && mapa[u-9]->Boja()==QBoja::crna)
            intToButton(u-9)->setEnabled(true);
        if(u/8==6)
            intToButton(u-16)->setEnabled(true);
    }
    else if(f->Oznaka()==QOznaka::pijun && f->Boja()==QBoja::crna){
        if(u+8<64 && !mapa.contains(u+8))
            intToButton(u+8)->setEnabled(true);
        if(mapa.contains(u+7) && u%8!=0 && mapa[u+7]->Boja()==QBoja::bela)
            intToButton(u+7)->setEnabled(true);
        if(mapa.contains(u+9) && (u+1)%8!=0 && mapa[u+9]->Boja()==QBoja::bela)
            intToButton(u+9)->setEnabled(true);
        if(u/8==1)
            intToButton(u+16)->setEnabled(true);
    }
    else if(f->Oznaka()==QOznaka::top){
        int i;
        for(i=1;(u+i)%8!=0 && !mapa.contains(u+i);++i)
            intToButton(u+i)->setEnabled(true);
        if((u+i)%8!=0 && mapa[u+i]->Boja()!=f->Boja())
            intToButton(u+i)->setEnabled(true);

        for(i=1;(1+u-i)%8!=0 && !mapa.contains(u-i);++i)
            intToButton(u-i)->setEnabled(true);
        if((1+u-i)%8!=0 && mapa[u-i]->Boja()!=f->Boja())
            intToButton(u-i)->setEnabled(true);

        for(i=1;u+8*i<64 && !mapa.contains(u+8*i);++i)
            intToButton(u+8*i)->setEnabled(true);
        if(u+8*i<64 && mapa[u+8*i]->Boja()!=f->Boja())
            intToButton(u+8*i)->setEnabled(true);

        for(i=1;u+1-8*i>0 && !mapa.contains(u-8*i);++i)
            intToButton(u-8*i)->setEnabled(true);
        if(u+1-8*i>0 && mapa[u-8*i]->Boja()!=f->Boja())
            intToButton(u-8*i)->setEnabled(true);
    }
    else if(f->Oznaka()==QOznaka::konj){
        if(u-16-1>-1 && u%8!=0 && (!mapa.contains(u-16-1) || mapa[u-17]->Boja()!=f->Boja()))
            intToButton(u-17)->setEnabled(true);
        if(u-16+1>-1 && (u+1)%8!=0 && (!mapa.contains(u-16+1) || mapa[u-15]->Boja()!=f->Boja()))
            intToButton(u-15)->setEnabled(true);
        if(u+16-1<64 && u%8!=0 && (!mapa.contains(u+16-1) || mapa[u+15]->Boja()!=f->Boja()))
            intToButton(u+15)->setEnabled(true);
        if(u+16+1<64 && (u+1)%8!=0 && (!mapa.contains(u+16+1) || mapa[u+17]->Boja()!=f->Boja()))
            intToButton(u+17)->setEnabled(true);
        if(u-8-2>-1 && u%8!=0 && (u-1)%8!=0 && (!mapa.contains(u-8-2) || mapa[u-10]->Boja()!=f->Boja()))
            intToButton(u-10)->setEnabled(true);
        if(u-8+2>-1 && (u+1)%8!=0 && (u+2)%8!=0 && (!mapa.contains(u-8+2) || mapa[u-6]->Boja()!=f->Boja()))
            intToButton(u-6)->setEnabled(true);
        if(u+8-2<64 && u%8!=0 && (u-1)%8!=0 && (!mapa.contains(u+8-2) || mapa[u+6]->Boja()!=f->Boja()))
            intToButton(u+6)->setEnabled(true);
        if(u+8+2<64 && (u+1)%8!=0 && (u+2)%8!=0 && (!mapa.contains(u+8+2) || mapa[u+10]->Boja()!=f->Boja()))
            intToButton(u+10)->setEnabled(true);
    }
    else if(f->Oznaka()==QOznaka::lovac){
        int i;
        for(i=1;u-9*i>-1 && (1+u-i)%8!=0 && !mapa.contains(u-9*i);++i)
            intToButton(u-9*i)->setEnabled(true);
        if(u-9*i>-1 && (1+u-i)%8!=0 && mapa[u-9*i]->Boja()!=f->Boja())
            intToButton(u-9*i)->setEnabled(true);

        for(i=1;u-7*i>-1 && (u+i)%8!=0 && !mapa.contains(u-7*i);++i)
            intToButton(u-7*i)->setEnabled(true);
        if(u-7*i>-1 && (u+i)%8!=0 && mapa[u-7*i]->Boja()!=f->Boja())
            intToButton(u-7*i)->setEnabled(true);

        for(i=1;u+9*i<64 && (u+i)%8!=0 && !mapa.contains(u+9*i);++i)
            intToButton(u+9*i)->setEnabled(true);
        if(u+9*i<64 && (u+i)%8!=0 && mapa[u+9*i]->Boja()!=f->Boja())
            intToButton(u+9*i)->setEnabled(true);

        for(i=1;u+7*i<64 && (u-i+1)%8!=0 && !mapa.contains(u+7*i);++i)
            intToButton(u+7*i)->setEnabled(true);
        if(u+7*i<64 && (u-i+1)%8!=0 && mapa[u+7*i]->Boja()!=f->Boja())
            intToButton(u+7*i)->setEnabled(true);
    }
    else if(f->Oznaka()==QOznaka::kraljica){
        int i;
        for(i=1;(u+i)%8!=0 && !mapa.contains(u+i);++i)
            intToButton(u+i)->setEnabled(true);
        if((u+i)%8!=0 && mapa[u+i]->Boja()!=f->Boja())
            intToButton(u+i)->setEnabled(true);

        for(i=1;(1+u-i)%8!=0 && !mapa.contains(u-i);++i)
            intToButton(u-i)->setEnabled(true);
        if((1+u-i)%8!=0 && mapa[u-i]->Boja()!=f->Boja())
            intToButton(u-i)->setEnabled(true);

        for(i=1;u+8*i<64 && !mapa.contains(u+8*i);++i)
            intToButton(u+8*i)->setEnabled(true);
        if(u+8*i<64 && mapa[u+8*i]->Boja()!=f->Boja())
            intToButton(u+8*i)->setEnabled(true);

        for(i=1;u+1-8*i>0 && !mapa.contains(u-8*i);++i)
            intToButton(u-8*i)->setEnabled(true);
        if(u+1-8*i>0 && mapa[u-8*i]->Boja()!=f->Boja())
            intToButton(u-8*i)->setEnabled(true);


        for(i=1;u-9*i>-1 && (1+u-i)%8!=0 && !mapa.contains(u-9*i);++i)
            intToButton(u-9*i)->setEnabled(true);
        if(u-9*i>-1 && (1+u-i)%8!=0 && mapa[u-9*i]->Boja()!=f->Boja())
            intToButton(u-9*i)->setEnabled(true);

        for(i=1;u-7*i>-1 && (u+i)%8!=0 && !mapa.contains(u-7*i);++i)
            intToButton(u-7*i)->setEnabled(true);
        if(u-7*i>-1 && (u+i)%8!=0 && mapa[u-7*i]->Boja()!=f->Boja())
            intToButton(u-7*i)->setEnabled(true);

        for(i=1;u+9*i<64 && (u+i)%8!=0 && !mapa.contains(u+9*i);++i)
            intToButton(u+9*i)->setEnabled(true);
        if(u+9*i<64 && (u+i)%8!=0 && mapa[u+9*i]->Boja()!=f->Boja())
            intToButton(u+9*i)->setEnabled(true);

        for(i=1;u+7*i<64 && (u-i+1)%8!=0 && !mapa.contains(u+7*i);++i)
            intToButton(u+7*i)->setEnabled(true);
        if(u+7*i<64 && (u-i+1)%8!=0 && mapa[u+7*i]->Boja()!=f->Boja())
            intToButton(u+7*i)->setEnabled(true);
    }
    else if(f->Oznaka()==QOznaka::kralj){
       QBoja b=QBoja::bela;
        if(f->Boja()==QBoja::bela)
            b=QBoja::crna;
        mapa.remove(u);
        if(u+7<64 && u%8!=0 && !poljeNapadnuto(u+7,b) && (!mapa.contains(u+7) || mapa[u+7]->Boja()==b))
            intToButton(u+7)->setEnabled(true);
        if(u-7>-1 && (u+1)%8!=0 && !poljeNapadnuto(u-7,b) && (!mapa.contains(u-7) || mapa[u-7]->Boja()==b))
            intToButton(u-7)->setEnabled(true);

        if(u+8<64 && !poljeNapadnuto(u+8,b) && (!mapa.contains(u+8) || mapa[u+8]->Boja()==b))
            intToButton(u+8)->setEnabled(true);
        if(u-8>-1 && !poljeNapadnuto(u-8,b) && (!mapa.contains(u-8) || mapa[u-8]->Boja()==b))
            intToButton(u-8)->setEnabled(true);

        if(u+9<64 && (u+1)%8!=0 && !poljeNapadnuto(u+9,b) && (!mapa.contains(u+9) || mapa[u+9]->Boja()==b))
            intToButton(u+9)->setEnabled(true);
        if(u-9>-1 && u%8!=0 && !poljeNapadnuto(u-9,b) && (!mapa.contains(u-9) || mapa[u-9]->Boja()==b))
            intToButton(u-9)->setEnabled(true);

        if(u+1<64 && (u+1)%8!=0 && !poljeNapadnuto(u+1,b) && (!mapa.contains(u+1) || mapa[u+1]->Boja()==b))
            intToButton(u+1)->setEnabled(true);
        if(u-1>-1 && u%8!=0 && !poljeNapadnuto(u-1,b) && (!mapa.contains(u-1) || mapa[u-1]->Boja()==b))
            intToButton(u-1)->setEnabled(true);


        if(u==4 && rokada(2))
            intToButton(2)->setEnabled(true);
        if(u==4 && rokada(6))
            intToButton(6)->setEnabled(true);
        if(u==60 && rokada(58))
            intToButton(58)->setEnabled(true);
        if(u==60 && rokada(62))
            intToButton(62)->setEnabled(true);



        mapa[u]=f;
    }
}

void Chess::priprema(){
    if(stanje==QStanje::beliIgrac_pocetakPoteza){       
        int u=mapa.begin().key();
        for(QMap<int,Figura*>::const_iterator i=mapa.cbegin();i!=mapa.cend();++i)
            if(i.value()->Boja()==QBoja::bela){
                if(i.value()->Oznaka()!=QOznaka::kralj){
                    if(movable(i.key()))
                        intToButton(i.key())->setEnabled(true);
                }
                else u=i.key();
            }
        if(movable(u))
            intToButton(u)->setEnabled(true);
    }
    else if (stanje==QStanje::crniIgrac_pocetakPoteza){
        int u=mapa.begin().key();
        for(QMap<int,Figura*>::const_iterator i=mapa.cbegin();i!=mapa.cend();++i)
            if(i.value()->Boja()==QBoja::crna){
                if(i.value()->Oznaka()!=QOznaka::kralj){
                    if(movable(i.key()))
                        intToButton(i.key())->setEnabled(true);
                }
                else u=i.key();
            }
        if(movable(u))
            intToButton(u)->setEnabled(true);
    }
}

bool Chess::movable(int u){
    Figura* f=mapa[u];
    if(f->Oznaka()==QOznaka::pijun && f->Boja()==QBoja::bela){
        if(u>7 && !mapa.contains(u-8))
            return true;
        if((u+1)%8!=0 && mapa.contains(u-7) && mapa[u-7]->Boja()==QBoja::crna)
            return true;
        if(u%8!=0 && mapa.contains(u-9) && mapa[u-9]->Boja()==QBoja::crna)
            return true;
    }
    else if(f->Oznaka()==QOznaka::pijun && f->Boja()==QBoja::crna){
        if(u+8<64 && !mapa.contains(u+8))
            return true;
        if(u%8!=0 && mapa.contains(u+7) && mapa[u+7]->Boja()==QBoja::bela)
            return true;
        if((u+1)%8!=0 && mapa.contains(u+9) && mapa[u+9]->Boja()==QBoja::bela)
            return true;
    }
    else if(f->Oznaka()==QOznaka::top){
        int i=1;
        if((u+i)%8!=0 && !mapa.contains(u+i))
            return true;
        if((u+i)%8!=0 && mapa[u+i]->Boja()!=f->Boja())
            return true;

        if((1+u-i)%8!=0 && !mapa.contains(u-i))
            return true;
        if((1+u-i)%8!=0 && mapa[u-i]->Boja()!=f->Boja())
            return true;

        if(u+8*i<64 && !mapa.contains(u+8*i))
            return true;
        if(u+8*i<64 && mapa[u+8*i]->Boja()!=f->Boja())
            return true;

        if(u+1-8*i>0 && !mapa.contains(u-8*i))
            return true;
        if(u+1-8*i>0 && mapa[u-8*i]->Boja()!=f->Boja())
            return true;
    }
    else if(f->Oznaka()==QOznaka::konj){
        if(u%8!=0 && u-16-1>-1 && (!mapa.contains(u-16-1) || mapa[u-17]->Boja()!=f->Boja()))
            return true;
        if((u+1)%8!=0 && u-16+1>-1 && (!mapa.contains(u-16+1) || mapa[u-15]->Boja()!=f->Boja()))
            return true;
        if(u%8!=0 && u+16-1<64 && (!mapa.contains(u+16-1) || mapa[u+15]->Boja()!=f->Boja()))
            return true;
        if((u+1)%8!=0 && u+16+1<64 && (!mapa.contains(u+16+1) || mapa[u+17]->Boja()!=f->Boja()))
            return true;
        if(u%8!=0 && (u-1)%8!=0 && u-8-2>-1 && (!mapa.contains(u-8-2) || mapa[u-10]->Boja()!=f->Boja()))
            return true;
        if((u+1)%8!=0 && (u+2)%8!=0 && u-8+2>-1 && (!mapa.contains(u-8+2) || mapa[u-6]->Boja()!=f->Boja()))
            return true;
        if(u%8!=0 && (u-1)%8!=0 && u+8-2<64 && (!mapa.contains(u+8-2) || mapa[u+6]->Boja()!=f->Boja()))
            return true;
        if((u+1)%8!=0 && (u+2)%8!=0 && u+8+2<64 && (!mapa.contains(u+8+2) || mapa[u+10]->Boja()!=f->Boja()))
            return true;
    }
    else if(f->Oznaka()==QOznaka::lovac){
        if(u%8!=0 && u-9>-1 && !mapa.contains(u-9))
            return true;
        if(u%8!=0 && u-9>-1 && mapa[u-9]->Boja()!=f->Boja())
            return true;

        if((u+1)%8!=0 && u-7>-1 && !mapa.contains(u-7))
            return true;
        if((u+1)%8!=0 && u-7>-1 && mapa[u-7]->Boja()!=f->Boja())
            return true;

        if((u+1)%8!=0 && u+9<64 && !mapa.contains(u+9))
            return true;
        if((u+1)%8!=0 && u+9<64 && mapa[u+9]->Boja()!=f->Boja())
            return true;

        if(u%8!=0 && u+7<64 && !mapa.contains(u+7))
            return true;
        if(u%8!=0 && u+7<64 && mapa[u+7]->Boja()!=f->Boja())
            return true;
    }
    if(f->Oznaka()==QOznaka::kraljica){
        int i=1;
        if((u+i)%8!=0 && !mapa.contains(u+i))
            return true;
        if((u+i)%8!=0 && mapa[u+i]->Boja()!=f->Boja())
            return true;

        if((1+u-i)%8!=0 && !mapa.contains(u-i))
            return true;
        if((1+u-i)%8!=0 && mapa[u-i]->Boja()!=f->Boja())
            return true;

        if(u+8*i<64 && !mapa.contains(u+8*i))
            return true;
        if(u+8*i<64 && mapa[u+8*i]->Boja()!=f->Boja())
            return true;

        if(u+1-8*i>0 && !mapa.contains(u-8*i))
            return true;
        if(u+1-8*i>0 && mapa[u-8*i]->Boja()!=f->Boja())
            return true;


        if(u%8!=0 && u-9>-1 && !mapa.contains(u-9))
            return true;
        if(u%8!=0 && u-9>-1 && mapa[u-9]->Boja()!=f->Boja())
            return true;

        if((u+1)%8!=0 && u-7>-1 && !mapa.contains(u-7))
            return true;
        if((u+1)%8!=0 && u-7>-1 && mapa[u-7]->Boja()!=f->Boja())
            return true;

        if((u+1)%8!=0 && u+9<64 && !mapa.contains(u+9))
            return true;
        if((u+1)%8!=0 && u+9<64 && mapa[u+9]->Boja()!=f->Boja())
            return true;

        if(u%8!=0 && u+7<64 && !mapa.contains(u+7))
            return true;
        if(u%8!=0 && u+7<64 && mapa[u+7]->Boja()!=f->Boja())
            return true;
    }
    if(f->Oznaka()==QOznaka::kralj){
        QBoja b=QBoja::bela;
        if(f->Boja()==QBoja::bela)
            b=QBoja::crna;

        mapa.remove(u);
        int i=1;
        if((u+i)%8!=0 && !poljeNapadnuto(u+1,b) && (!mapa.contains(u+i) || mapa[u+i]->Boja()!=f->Boja())){
            mapa[u]=f;
            return true;
        }

        if((1+u-i)%8!=0 && !poljeNapadnuto(u-1,b) && (!mapa.contains(u-i) || mapa[u-i]->Boja()!=f->Boja())){
            mapa[u]=f;
            return true;
        }

        if(u+8*i<64 && !poljeNapadnuto(u+8,b) && (!mapa.contains(u+8*i) || mapa[u+8*i]->Boja()!=f->Boja())){
            mapa[u]=f;
            return true;
        }

        if(u+1-8*i>0 && !poljeNapadnuto(u-8,b) && (!mapa.contains(u-8*i) || mapa[u-8*i]->Boja()!=f->Boja())){
            mapa[u]=f;
            return true;
        }

        if(u%8!=0 && u-9>-1 && !poljeNapadnuto(u-9,b) && (!mapa.contains(u-9) || mapa[u-9]->Boja()!=f->Boja())){
            mapa[u]=f;
            return true;
        }

        if((u+i)%8!=0 && u-7>-1 && !poljeNapadnuto(u-7,b) && (!mapa.contains(u-7) || mapa[u-7]->Boja()!=f->Boja())){
            mapa[u]=f;
            return true;
        }

        if((u+i)%8!=0 && u+9<64 && !poljeNapadnuto(u+9,b) && (!mapa.contains(u+9) || mapa[u+9]->Boja()!=f->Boja())){
            mapa[u]=f;
            return true;
        }

        if(u%8!=0 && u+7<64 && !poljeNapadnuto(u+7,b) && (!mapa.contains(u+7) || mapa[u+7]->Boja()!=f->Boja())){
            mapa[u]=f;
            return true;
        }

        mapa[u]=f;
    }



    return false;
}
QString Chess::intToChar(int u){
    QString s;
    switch (u%8) {
    case 0:
        s="A";
        break;
    case 1:
        s="B";
        break;
    case 2:
        s="C";
        break;
    case 3:
        s="D";
        break;
    case 4:
        s="E";
        break;
    case 5:
        s="F";
        break;
    case 6:
        s="G";
        break;
    default:
        s="H";
    }
    return s;
}
bool Chess::poljeNapadnuto(int u,QBoja b){
    bool* a=new bool[64];
    for(int i=0;i<64;++i)
        a[i]=false;
    for(QMap<int,Figura*>::iterator i=mapa.begin();i!=mapa.end();++i)
        if(i.value()->Boja()==b)
            figuraNapadaPolja(i.key(),a);
    bool p=a[u];
    delete [] a;
    return p;
}

void Chess::potez(int u){
    if(stanje==QStanje::beliIgrac_pocetakPoteza){
        setPolja();
        allButtonsDisable();
        changeButtons(u);
        stanje=QStanje::beliIgrac_krajPoteza;
        pKlik=u;
        ui->label_pKlik->setText(intToChar(pKlik).append( QString::number(8-pKlik/8)));
    }
    else if(stanje==QStanje::beliIgrac_krajPoteza){
        allButtonsDisable();
        if(u!=pKlik){
            bool p=false;
            Figura* f=nullptr;
            if(mapa.contains(u)){
                p=true;
                f=mapa[u];
            }
            mapa[u]=mapa[pKlik];
            mapa.remove(pKlik);
            if(isSah(QBoja::bela)){
                mapa[pKlik]=mapa[u];
                if(p)
                    mapa[u]=f;
                else mapa.remove(u);
                stanje=QStanje::beliIgrac_pocetakPoteza;
                Polja();
            }
            else{
                intToLabel(pKlik)->clear();
                intToLabel(u)->clear();
                if(!mapa.contains(u))
                    qFatal("mapa nema pKlik");
                crtaj(mapa[u],intToLabel(u));

                stanje=QStanje::crniIgrac_pocetakPoteza;
                ++brojPoteza;

                crtajTopaAkoJeRokada(pKlik,u);
                proveraRokada(pKlik);
                priprema();
                if(insufficientMaterial())
                    allButtonsDisable();
            }
        }
        else{
            stanje=QStanje::beliIgrac_pocetakPoteza;
            Polja();
        }
    }
    else if(stanje==QStanje::crniIgrac_pocetakPoteza){
        setPolja();
        allButtonsDisable();
        changeButtons(u);
        stanje=QStanje::crniIgrac_krajPoteza;
        pKlik=u;
        ui->label_pKlik->setText(intToChar(pKlik).append( QString::number(8-pKlik/8)));
    }
    else if(stanje==QStanje::crniIgrac_krajPoteza){
        allButtonsDisable();
        if(u!=pKlik){
            bool p=false;
            Figura* f=nullptr;
            if(mapa.contains(u)){
                p=true;
                f=mapa[u];
            }
            mapa[u]=mapa[pKlik];
            mapa.remove(pKlik);
            if(isSah(QBoja::crna)){
                mapa[pKlik]=mapa[u];
                if(p)
                    mapa[u]=f;
                else mapa.remove(u);
                stanje=QStanje::crniIgrac_pocetakPoteza;
                Polja();
            }
            else{
                intToLabel(pKlik)->clear();
                intToLabel(u)->clear();
                if(!mapa.contains(u))
                    qFatal("mapa nema pKlik");
                crtaj(mapa[u],intToLabel(u));

                stanje=QStanje::beliIgrac_pocetakPoteza;
                ++brojPoteza;

                crtajTopaAkoJeRokada(pKlik,u);
                proveraRokada(pKlik);
                priprema();
                if(insufficientMaterial())
                    allButtonsDisable();
            }
        }
        else{
            stanje=QStanje::crniIgrac_pocetakPoteza;
            Polja();
        }
    }
    ui->label_brojPoteza->setText(QString::number(brojPoteza));
}
void Chess::proveraPijun(int u){
    if(mapa.contains(u)){
        Figura* f=mapa[u];
        if(f->Oznaka()==QOznaka::pijun){
            allButtonsDisable();
            pKlik=u;
            ui->pushButton_Kraljica->setEnabled(true);
            ui->pushButton_Top->setEnabled(true);
            ui->pushButton_Lovac->setEnabled(true);
            ui->pushButton_Konj->setEnabled(true);
            ui->pushButton_Kraljica->setText("KRALJICA");
            ui->pushButton_Top->setText("TOP");
            ui->pushButton_Lovac->setText("LOVAC");
            ui->pushButton_Konj->setText("KONJ");
        }
    }
}

bool Chess::isSah(QBoja b){
    QBoja nb=QBoja::bela;
    if(b==nb)
        nb=QBoja::crna;
    QMap<int,Figura*>::iterator i=mapa.begin();
    for(;i!=mapa.end() && !(i.value()->Oznaka()==QOznaka::kralj && i.value()->Boja()==b) ;++i);
    if(i==mapa.end())
        qFatal("isSah");
    return poljeNapadnuto(i.key(),nb);
}
void Chess::proveraRokada(int u){
    switch (u) {
    case 0:
        queensideCrniTop=false;
        break;
    case 4:
        crniKralj=false;
        break;
    case 7:
        kingsideCrniTop=false;
        break;
    case 56:
        queensideBeliTop=false;
        break;
    case 60:
        beliKralj=false;
        break;
    case 63:
        kingsideBeliTop=false;
    }
}
bool Chess::rokada(int u){
    switch (u) {
    case 2:
        return crniKralj && queensideCrniTop
                && !mapa.contains(1) && !mapa.contains(2) && !mapa.contains(3)
                && !poljeNapadnuto(1,QBoja::bela) && !poljeNapadnuto(2,QBoja::bela) && !poljeNapadnuto(3,QBoja::bela)
                && !poljeNapadnuto(0,QBoja::bela) && !poljeNapadnuto(4,QBoja::bela);
    case 6:
        return crniKralj && kingsideCrniTop
                && !mapa.contains(5) && !mapa.contains(6)
                && !poljeNapadnuto(4,QBoja::bela) && !poljeNapadnuto(5,QBoja::bela) && !poljeNapadnuto(6,QBoja::bela)
                && !poljeNapadnuto(7,QBoja::bela);
    case 58:
        return beliKralj && queensideBeliTop
                && !mapa.contains(57) && !mapa.contains(58) && !mapa.contains(59)
                && !poljeNapadnuto(56,QBoja::crna) && !poljeNapadnuto(57,QBoja::crna) && !poljeNapadnuto(58,QBoja::crna)
                && !poljeNapadnuto(59,QBoja::crna) && !poljeNapadnuto(60,QBoja::crna);
    case 62:
        return beliKralj && kingsideBeliTop
                && !mapa.contains(61) && !mapa.contains(62)
                && !poljeNapadnuto(60,QBoja::crna) && !poljeNapadnuto(61,QBoja::crna) && !poljeNapadnuto(62,QBoja::crna)
                && !poljeNapadnuto(63,QBoja::crna);
    }
    return false;
}
void Chess::crtajTopaAkoJeRokada(int pu, int u){
    if(pu==4){
        if(u==2){
            mapa[3]=t1;
            crtaj(t1,intToLabel(3));
            mapa.remove(0);
            intToLabel(0)->clear();
        }
        else if(u==6){
            mapa[5]=t1;
            crtaj(t1,intToLabel(5));
            mapa.remove(7);
            intToLabel(7)->clear();
        }
    }
    else if (pu==60){
        if(u==58){
            mapa[59]=t0;
            crtaj(t0,intToLabel(59));
            mapa.remove(56);
            intToLabel(56)->clear();
        }
        else if(u==62){
            mapa[61]=t0;
            crtaj(t0,intToLabel(61));
            mapa.remove(63);
            intToLabel(63)->clear();
        }
    }
}
bool Chess::insufficientMaterial(){
    if(mapa.size()<3)
        return true;
    if(mapa.size()==3){
        QList<Figura*>::const_iterator i=mapa.values().cbegin();
        for(;i!=mapa.values().cend();++i)
            if((*i)->Oznaka()==QOznaka::konj || (*i)->Oznaka()==QOznaka::lovac)
                return true;
        return false;
    }
    if(mapa.size()==4){
        QMap<int,Figura*>::const_iterator j[2];
        int k=0;
        for(QMap<int,Figura*>::const_iterator i=mapa.cbegin();i!=mapa.cend();++i){
            if(i.value()->Oznaka()!=QOznaka::kralj)
                j[k++]=i;
        }
        if(j[0].value()->Oznaka()==QOznaka::lovac && j[1].value()->Oznaka()==QOznaka::lovac
                && (j[0].key()+j[0].key()/8)%2==(j[1].key()+j[1].key()/8)%2)
            return true;
        return false;
    }
    return false;
}

void Chess::on_pushButton_00_clicked(){potez(0);proveraPijun(0);}
void Chess::on_pushButton_01_clicked(){potez(1);proveraPijun(1);}
void Chess::on_pushButton_02_clicked(){potez(2);proveraPijun(2);}
void Chess::on_pushButton_03_clicked(){potez(3);proveraPijun(3);}
void Chess::on_pushButton_04_clicked(){potez(4);proveraPijun(4);}
void Chess::on_pushButton_05_clicked(){potez(5);proveraPijun(5);}
void Chess::on_pushButton_06_clicked(){potez(6);proveraPijun(6);}
void Chess::on_pushButton_07_clicked(){potez(7);proveraPijun(7);}
void Chess::on_pushButton_08_clicked(){potez(8);}
void Chess::on_pushButton_09_clicked(){potez(9);}
void Chess::on_pushButton_10_clicked(){potez(10);}
void Chess::on_pushButton_11_clicked(){potez(11);}
void Chess::on_pushButton_12_clicked(){potez(12);}
void Chess::on_pushButton_13_clicked(){potez(13);}
void Chess::on_pushButton_14_clicked(){potez(14);}
void Chess::on_pushButton_15_clicked(){potez(15);}
void Chess::on_pushButton_16_clicked(){potez(16);}
void Chess::on_pushButton_17_clicked(){potez(17);}
void Chess::on_pushButton_18_clicked(){potez(18);}
void Chess::on_pushButton_19_clicked(){potez(19);}
void Chess::on_pushButton_20_clicked(){potez(20);}
void Chess::on_pushButton_21_clicked(){potez(21);}
void Chess::on_pushButton_22_clicked(){potez(22);}
void Chess::on_pushButton_23_clicked(){potez(23);}
void Chess::on_pushButton_24_clicked(){potez(24);}
void Chess::on_pushButton_25_clicked(){potez(25);}
void Chess::on_pushButton_26_clicked(){potez(26);}
void Chess::on_pushButton_27_clicked(){potez(27);}
void Chess::on_pushButton_28_clicked(){potez(28);}
void Chess::on_pushButton_29_clicked(){potez(29);}
void Chess::on_pushButton_30_clicked(){potez(30);}
void Chess::on_pushButton_31_clicked(){potez(31);}
void Chess::on_pushButton_32_clicked(){potez(32);}
void Chess::on_pushButton_33_clicked(){potez(33);}
void Chess::on_pushButton_34_clicked(){potez(34);}
void Chess::on_pushButton_35_clicked(){potez(35);}
void Chess::on_pushButton_36_clicked(){potez(36);}
void Chess::on_pushButton_37_clicked(){potez(37);}
void Chess::on_pushButton_38_clicked(){potez(38);}
void Chess::on_pushButton_39_clicked(){potez(39);}
void Chess::on_pushButton_40_clicked(){potez(40);}
void Chess::on_pushButton_41_clicked(){potez(41);}
void Chess::on_pushButton_42_clicked(){potez(42);}
void Chess::on_pushButton_43_clicked(){potez(43);}
void Chess::on_pushButton_44_clicked(){potez(44);}
void Chess::on_pushButton_45_clicked(){potez(45);}
void Chess::on_pushButton_46_clicked(){potez(46);}
void Chess::on_pushButton_47_clicked(){potez(47);}
void Chess::on_pushButton_48_clicked(){potez(48);}
void Chess::on_pushButton_49_clicked(){potez(49);}
void Chess::on_pushButton_50_clicked(){potez(50);}
void Chess::on_pushButton_51_clicked(){potez(51);}
void Chess::on_pushButton_52_clicked(){potez(52);}
void Chess::on_pushButton_53_clicked(){potez(53);}
void Chess::on_pushButton_54_clicked(){potez(54);}
void Chess::on_pushButton_55_clicked(){potez(55);}
void Chess::on_pushButton_56_clicked(){potez(56);proveraPijun(56);}
void Chess::on_pushButton_57_clicked(){potez(57);proveraPijun(57);}
void Chess::on_pushButton_58_clicked(){potez(58);proveraPijun(58);}
void Chess::on_pushButton_59_clicked(){potez(59);proveraPijun(59);}
void Chess::on_pushButton_60_clicked(){potez(60);proveraPijun(60);}
void Chess::on_pushButton_61_clicked(){potez(61);proveraPijun(61);}
void Chess::on_pushButton_62_clicked(){potez(62);proveraPijun(62);}
void Chess::on_pushButton_63_clicked(){potez(63);proveraPijun(63);}

void Chess::on_pushButton_Kraljica_clicked(){
    ui->pushButton_Kraljica->setEnabled(false);
    ui->pushButton_Top->setEnabled(false);
    ui->pushButton_Lovac->setEnabled(false);
    ui->pushButton_Konj->setEnabled(false);
    ui->pushButton_Kraljica->setText("");
    ui->pushButton_Top->setText("");
    ui->pushButton_Lovac->setText("");
    ui->pushButton_Konj->setText("");

    if(mapa[pKlik]->Boja()==QBoja::crna){
        mapa[pKlik]=y1;
        intToLabel(pKlik)->clear();
        crtaj(y1,intToLabel(pKlik));
    }
    else{
        mapa[pKlik]=y0;
        intToLabel(pKlik)->clear();
        crtaj(y0,intToLabel(pKlik));
    }
    priprema();
}
void Chess::on_pushButton_Top_clicked(){
    ui->pushButton_Kraljica->setEnabled(false);
    ui->pushButton_Top->setEnabled(false);
    ui->pushButton_Lovac->setEnabled(false);
    ui->pushButton_Konj->setEnabled(false);
    ui->pushButton_Kraljica->setText("");
    ui->pushButton_Top->setText("");
    ui->pushButton_Lovac->setText("");
    ui->pushButton_Konj->setText("");

    if(mapa[pKlik]->Boja()==QBoja::crna){
        mapa[pKlik]=t1;
        intToLabel(pKlik)->clear();
        crtaj(t1,intToLabel(pKlik));
    }
    else{
        mapa[pKlik]=t0;
        intToLabel(pKlik)->clear();
        crtaj(t0,intToLabel(pKlik));
    }
    priprema();
}
void Chess::on_pushButton_Lovac_clicked(){
    ui->pushButton_Kraljica->setEnabled(false);
    ui->pushButton_Top->setEnabled(false);
    ui->pushButton_Lovac->setEnabled(false);
    ui->pushButton_Konj->setEnabled(false);
    ui->pushButton_Kraljica->setText("");
    ui->pushButton_Top->setText("");
    ui->pushButton_Lovac->setText("");
    ui->pushButton_Konj->setText("");

    if(mapa[pKlik]->Boja()==QBoja::crna){
        mapa[pKlik]=l1;
        intToLabel(pKlik)->clear();
        crtaj(l1,intToLabel(pKlik));
    }
    else{
        mapa[pKlik]=l0;
        intToLabel(pKlik)->clear();
        crtaj(l0,intToLabel(pKlik));
    }
    priprema();
}
void Chess::on_pushButton_Konj_clicked(){
    ui->pushButton_Kraljica->setEnabled(false);
    ui->pushButton_Top->setEnabled(false);
    ui->pushButton_Lovac->setEnabled(false);
    ui->pushButton_Konj->setEnabled(false);
    ui->pushButton_Kraljica->setText("");
    ui->pushButton_Top->setText("");
    ui->pushButton_Lovac->setText("");
    ui->pushButton_Konj->setText("");

    if(mapa[pKlik]->Boja()==QBoja::crna){
        mapa[pKlik]=k1;
        intToLabel(pKlik)->clear();
        crtaj(k1,intToLabel(pKlik));
    }
    else{
        mapa[pKlik]=k0;
        intToLabel(pKlik)->clear();
        crtaj(k0,intToLabel(pKlik));
    }
    priprema();
}
