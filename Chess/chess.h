#ifndef CHESS_H
#define CHESS_H

#include <QWidget>
#include "figura.h"
#include <QLabel>
#include <QMap>
#include <QPushButton>
#include "stanje.h"
#include <QPainter>

namespace Ui {
class Chess;
}

class Chess : public QWidget
{
    Q_OBJECT

public:
    explicit Chess(QWidget *parent = nullptr);
    ~Chess();

private slots:

    void on_pushButton_00_clicked();
    void on_pushButton_01_clicked();
    void on_pushButton_02_clicked();
    void on_pushButton_03_clicked();
    void on_pushButton_04_clicked();
    void on_pushButton_05_clicked();
    void on_pushButton_06_clicked();
    void on_pushButton_07_clicked();
    void on_pushButton_08_clicked();
    void on_pushButton_09_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_22_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_27_clicked();
    void on_pushButton_28_clicked();
    void on_pushButton_29_clicked();
    void on_pushButton_30_clicked();
    void on_pushButton_31_clicked();
    void on_pushButton_32_clicked();
    void on_pushButton_33_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_35_clicked();
    void on_pushButton_36_clicked();
    void on_pushButton_37_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_39_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_41_clicked();
    void on_pushButton_42_clicked();
    void on_pushButton_43_clicked();
    void on_pushButton_44_clicked();
    void on_pushButton_45_clicked();
    void on_pushButton_46_clicked();
    void on_pushButton_47_clicked();
    void on_pushButton_48_clicked();
    void on_pushButton_49_clicked();
    void on_pushButton_50_clicked();
    void on_pushButton_51_clicked();
    void on_pushButton_52_clicked();
    void on_pushButton_53_clicked();
    void on_pushButton_54_clicked();
    void on_pushButton_55_clicked();
    void on_pushButton_56_clicked();
    void on_pushButton_57_clicked();
    void on_pushButton_58_clicked();
    void on_pushButton_59_clicked();
    void on_pushButton_60_clicked();
    void on_pushButton_61_clicked();
    void on_pushButton_62_clicked();
    void on_pushButton_63_clicked();
    void on_pushButton_Kraljica_clicked();
    void on_pushButton_Top_clicked();
    void on_pushButton_Lovac_clicked();
    void on_pushButton_Konj_clicked();


private:
    Ui::Chess *ui;

    QMap<int,Figura*> mapa;
    Pijun *p0,*p1;
    Top *t0,*t1;
    Konj *k0,*k1;
    Lovac *l0,*l1;
    Kraljica *y0,*y1;
    Kralj *x0,*x1;
    QStanje stanje;
    int pKlik;
    bool* polja;
    int brojPoteza;


    void inicijalizujTablu();
    int labelToInt(QLabel*)const;
    QLabel* intToLabel(int)const;
    QPushButton* intToButton(int)const;
    void potez(int);
    void crtaj(Figura*, QLabel*);
    void figuraNapadaPolja(int,bool*);
    void allButtonsDisable();
    void changeButtons(int);
    void setPolja();
    void Polja();
    void priprema();
    bool movable(int);
    void crtajKvadrat(int);
    QString intToChar(int);
    void proveraPijun(int);
    bool poljeNapadnuto(int,QBoja);
};


#endif // CHESS_H
