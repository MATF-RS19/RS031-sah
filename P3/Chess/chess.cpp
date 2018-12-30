#include "chess.h"
#include "ui_chess.h"
#include "figura.h"

Chess::Chess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chess),
    mapa()
{
    ui->setupUi(this);

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

    delete ui;
}

void crtaj(Figura* f,QLabel* l){
    QPixmap p(f->Slicica());
    l->setPixmap(p.scaled(90,90,Qt::KeepAspectRatio));
    l->setAlignment(Qt::AlignHCenter);
}
void brisi(QLabel* l){
    l->clear();
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

    mapa[ui->label_00]=t1;
    mapa[ui->label_01]=k1;
    mapa[ui->label_02]=l1;
    mapa[ui->label_03]=y1;
    mapa[ui->label_04]=x1;
    mapa[ui->label_05]=l1;
    mapa[ui->label_06]=k1;
    mapa[ui->label_07]=t1;
    mapa[ui->label_10]=p1;
    mapa[ui->label_11]=p1;
    mapa[ui->label_12]=p1;
    mapa[ui->label_13]=p1;
    mapa[ui->label_14]=p1;
    mapa[ui->label_15]=p1;
    mapa[ui->label_08]=p1;
    mapa[ui->label_09]=p1;
    mapa[ui->label_48]=p1;
    mapa[ui->label_49]=p1;
    mapa[ui->label_50]=p0;
    mapa[ui->label_51]=p0;
    mapa[ui->label_52]=p0;
    mapa[ui->label_53]=p0;
    mapa[ui->label_54]=p0;
    mapa[ui->label_55]=p0;
    mapa[ui->label_56]=t0;
    mapa[ui->label_57]=k0;
    mapa[ui->label_58]=l0;
    mapa[ui->label_59]=y0;
    mapa[ui->label_60]=x0;
    mapa[ui->label_61]=l0;
    mapa[ui->label_62]=k0;
    mapa[ui->label_63]=t0;
}

void Chess::on_pushButton_00_clicked(){}
void Chess::on_pushButton_01_clicked(){}
void Chess::on_pushButton_02_clicked(){}
void Chess::on_pushButton_03_clicked(){}
void Chess::on_pushButton_04_clicked(){}
void Chess::on_pushButton_05_clicked(){}
void Chess::on_pushButton_06_clicked(){}
void Chess::on_pushButton_07_clicked(){}
void Chess::on_pushButton_08_clicked(){}
void Chess::on_pushButton_09_clicked(){}
void Chess::on_pushButton_10_clicked(){}
void Chess::on_pushButton_11_clicked(){}
void Chess::on_pushButton_12_clicked(){}
void Chess::on_pushButton_13_clicked(){}
void Chess::on_pushButton_14_clicked(){}
void Chess::on_pushButton_15_clicked(){}
void Chess::on_pushButton_16_clicked(){}
void Chess::on_pushButton_17_clicked(){}
void Chess::on_pushButton_18_clicked(){}
void Chess::on_pushButton_19_clicked(){}
void Chess::on_pushButton_20_clicked(){}
void Chess::on_pushButton_21_clicked(){}
void Chess::on_pushButton_22_clicked(){}
void Chess::on_pushButton_23_clicked(){}
void Chess::on_pushButton_24_clicked(){}
void Chess::on_pushButton_25_clicked(){}
void Chess::on_pushButton_26_clicked(){}
void Chess::on_pushButton_27_clicked(){}
void Chess::on_pushButton_28_clicked(){}
void Chess::on_pushButton_29_clicked(){}
void Chess::on_pushButton_30_clicked(){}
void Chess::on_pushButton_31_clicked(){}
void Chess::on_pushButton_32_clicked(){}
void Chess::on_pushButton_33_clicked(){}
void Chess::on_pushButton_34_clicked(){}
void Chess::on_pushButton_35_clicked(){}
void Chess::on_pushButton_36_clicked(){}
void Chess::on_pushButton_37_clicked(){}
void Chess::on_pushButton_38_clicked(){}
void Chess::on_pushButton_39_clicked(){}
void Chess::on_pushButton_40_clicked(){}
void Chess::on_pushButton_41_clicked(){}
void Chess::on_pushButton_42_clicked(){}
void Chess::on_pushButton_43_clicked(){}
void Chess::on_pushButton_44_clicked(){}
void Chess::on_pushButton_45_clicked(){}
void Chess::on_pushButton_46_clicked(){}
void Chess::on_pushButton_47_clicked(){}
void Chess::on_pushButton_48_clicked(){}
void Chess::on_pushButton_49_clicked(){}
void Chess::on_pushButton_50_clicked(){}
void Chess::on_pushButton_51_clicked(){}
void Chess::on_pushButton_52_clicked(){}
void Chess::on_pushButton_53_clicked(){}
void Chess::on_pushButton_54_clicked(){}
void Chess::on_pushButton_55_clicked(){}
void Chess::on_pushButton_56_clicked(){}
void Chess::on_pushButton_57_clicked(){}
void Chess::on_pushButton_58_clicked(){}
void Chess::on_pushButton_59_clicked(){}
void Chess::on_pushButton_60_clicked(){}
void Chess::on_pushButton_61_clicked(){}
void Chess::on_pushButton_62_clicked(){}
void Chess::on_pushButton_63_clicked(){}
