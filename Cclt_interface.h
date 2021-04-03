#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QBoxLayout>
#include <QStackedLayout>
#include <QGridLayout>
#include <QPointer>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "Calculator.h"

class System : public QWidget
{
    Q_OBJECT

private:
    //! control
    //! number control
    QPointer<QLineEdit> _ledtInput;
    QPointer<QLineEdit> _ledtResult;
    QPointer<QPushButton> _btnZero;
    QPointer<QPushButton> _btnOne;
    QPointer<QPushButton> _btnTwo;
    QPointer<QPushButton> _btnThree;
    QPointer<QPushButton> _btnFour;
    QPointer<QPushButton> _btnFive;
    QPointer<QPushButton> _btnSix;
    QPointer<QPushButton> _btnSeven;
    QPointer<QPushButton> _btnEight;
    QPointer<QPushButton> _btnNine;

    //! operator control
    QPointer<QPushButton> _btnSquare;
    QPointer<QPushButton> _btnPower;
    QPointer<QPushButton> _btnSqrt;
    QPointer<QPushButton> _btn10pow;
    QPointer<QPushButton> _btnMOD;
    QPointer<QPushButton> _btnPI;
    QPointer<QPushButton> _btnFAC; //factorial
    QPointer<QPushButton> _btnC; //All Clear
    QPointer<QPushButton> _btnAns; //last result
    QPointer<QPushButton> _btnSin;
    QPointer<QPushButton> _btnCos;
    QPointer<QPushButton> _btnTan;
    QPointer<QPushButton> _btnLog;
    QPointer<QPushButton> _btnFrac;
    QPointer<QPushButton> _btn2nd;
    QPointer<QPushButton> _btnBackSpace;
    QPointer<QPushButton> _btnDivide;
    QPointer<QPushButton> _btnMultiply;
    QPointer<QPushButton> _btnMinus;
    QPointer<QPushButton> _btnPlus;
    QPointer<QPushButton> _btnEqual;
    QPointer<QPushButton> _btnDot;
    QPointer<QPushButton> _btnLbracket;
    QPointer<QPushButton> _btnRbracket;
    QPointer<QPushButton> _btnNegative;
    QPointer<QPushButton> _btnCube;
    QPointer<QPushButton> _btnRoot;
    QPointer<QPushButton> _btnArcSin;
    QPointer<QPushButton> _btnArcCos;
    QPointer<QPushButton> _btnArcTan;
    QPointer<QPushButton> _btnReciprocal;
    QPointer<QPushButton> _btnExp;
    QPointer<QPushButton> _btnLn;
    QPointer<QPushButton> _btnDEG;
    QPointer<QPushButton> _btnRAD;

    //! layout
    QPointer<QStackedLayout> btnLay_2row;
    QPointer<QWidget> firstPageWidget;
    QPointer<QWidget> secondPageWidget;
    QPointer<QGridLayout> btnLay_2ndTrue;
    QPointer<QGridLayout> btnLay_2ndFalse;
    QPointer<QGridLayout> btnLay_5row;
    QPointer<QVBoxLayout> mainLayout;

    //! flag
    bool btn2nd_state = false;

    //! calculator
    unique_ptr<Calculator> m_cclt;
    string m_expr = ""; //expr to be calculated
    QString m_result = "";
    int m_oldCursorPos = 0; //previous cursor position
    int m_newCursorPos = 0; //current cursor position

public:
    explicit System(QWidget *parent = nullptr);
    ~System() override;

private:
    void init_interface();
    void init_connect();

private slots:
    void on_ledtInput_textChanged(const QString&);
    void on_ledtInput_cursorPositionChanged(int, int);
    void on_btnZero_clicked(bool);
    void on_btnOne_clicked(bool);
    void on_btnTwo_clicked(bool);
    void on_btnThree_clicked(bool);
    void on_btnFour_clicked(bool);
    void on_btnFive_clicked(bool);
    void on_btnSix_clicked(bool);
    void on_btnSeven_clicked(bool);
    void on_btnEight_clicked(bool);
    void on_btnNine_clicked(bool);
    void on_btn10_clicked(bool);
    void on_btnSquare_clicked(bool);
    void on_btnPower_clicked(bool);
    void on_btnSqrt_clicked(bool);
    void on_btn10pow_clicked(bool);
    void on_btnMOD_clicked(bool);
    void on_btnPI_clicked(bool);
    void on_btnFAC_clicked(bool);
    void on_btnSin_cliked(bool);
    void on_btnCos_clicked(bool);
    void on_btnTan_clicked(bool);
    void on_btnLog_clicked(bool);
    void on_btnFrac_clicked(bool);
    void on_btn2nd_clicked(bool);
    void on_btnBackSpace_clicked(bool);
    void on_btnPlus_clicked(bool);
    void on_btnMinus_clicked(bool);
    void on_btnMultiply_clicked(bool);
    void on_btnDivide_clicked(bool);
    void on_btnC_clicked(bool);
    void on_btnAns_clicked(bool);
    void on_btnEqual_clicked(bool);
    void on_btnDot_clicked(bool);
    void on_btnLbracket_clicked(bool);
    void on_btnRbracket_clicked(bool);
    void on_btnNegative_clicked(bool);
    void on_btnCube_clicked(bool);
    void on_btnRoot_clicked(bool);
    void on_btnArcSin_clicked(bool);
    void on_btnArcCos_clicked(bool);
    void on_btnArcTan_clicked(bool);
    void on_btnReciprocal_clicked(bool);
    void on_btnExp_clicked(bool);
    void on_btnLn_clicked(bool);
    void on_btnDEG_clicked(bool);
    void on_btnRAD_clicked(bool);

protected:
    //! event
    void keyPressEvent(QKeyEvent *) Q_DECL_OVERRIDE;
};
#endif // WIDGET_H
