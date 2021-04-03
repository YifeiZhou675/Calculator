#include "Cclt_interface.h"
#include <QFont>
#include <QTextCodec>
#include <QPainter>
#include <QDebug>
#include <QRegExp>
#include <QValidator>
using std::exception;

System::System(QWidget *parent)
    : QWidget(parent)
    , _ledtInput(new QLineEdit)
    , _ledtResult(new QLineEdit)
    , _btnZero(new QPushButton("0"))
    , _btnOne(new QPushButton("1"))
    , _btnTwo(new QPushButton("2"))
    , _btnThree(new QPushButton("3"))
    , _btnFour(new QPushButton("4"))
    , _btnFive(new QPushButton("5"))
    , _btnSix(new QPushButton("6"))
    , _btnSeven(new QPushButton("7"))
    , _btnEight(new QPushButton("8"))
    , _btnNine(new QPushButton("9"))
    , _btnSquare(new QPushButton("x²"))
    , _btnPower(new QPushButton("x^y"))
    , _btnSqrt(new QPushButton("√"))
    , _btn10pow(new QPushButton("10^x"))
    , _btnMOD(new QPushButton("%"))
    , _btnPI(new QPushButton("π"))
    , _btnFAC(new QPushButton("!"))
    , _btnC(new QPushButton("C"))
    , _btnAns(new QPushButton("Ans"))
    , _btnSin(new QPushButton("sin"))
    , _btnCos(new QPushButton("cos"))
    , _btnTan(new QPushButton("tan"))
    , _btnLog(new QPushButton("log"))
    , _btnFrac(new QPushButton("x/y"))
    , _btn2nd(new QPushButton("2nd"))
    , _btnBackSpace(new QPushButton("DEL"))
    , _btnDivide(new QPushButton("÷"))
    , _btnMultiply(new QPushButton("×"))
    , _btnMinus(new QPushButton("-"))
    , _btnPlus(new QPushButton("+"))
    , _btnEqual(new QPushButton("="))
    , _btnDot(new QPushButton("."))
    , _btnLbracket(new QPushButton("("))
    , _btnRbracket(new QPushButton(")"))
    , _btnNegative(new QPushButton("~"))
    , _btnCube(new QPushButton("x³"))
    , _btnRoot(new QPushButton("y√x"))
    , _btnArcSin(new QPushButton("asin"))
    , _btnArcCos(new QPushButton("acos"))
    , _btnArcTan(new QPushButton("atan"))
    , _btnReciprocal(new QPushButton("1/x"))
    , _btnExp(new QPushButton("e^x"))
    , _btnLn(new QPushButton("ln"))
    , _btnDEG(new QPushButton("deg"))
    , _btnRAD(new QPushButton("rad○"))
    , btnLay_2row(new QStackedLayout)
    , firstPageWidget(new QWidget)
    , secondPageWidget(new QWidget)
    , btnLay_2ndTrue(new QGridLayout)
    , btnLay_2ndFalse(new QGridLayout)
    , btnLay_5row(new QGridLayout)
    , mainLayout(new QVBoxLayout)
    , m_cclt(make_unique<Calculator>())
{
    init_interface();
    init_connect();
    this->setWindowTitle("Calculator");
}

System::~System()
{
}

void System::init_interface()
{
    QFont ledt_font;
    ledt_font.setFamily("CAMBRIA");
    ledt_font.setPointSize(25);
    ledt_font.setWeight(75);

    //set LineEdit
    _ledtInput->setFont(ledt_font);
    _ledtResult->setFont(ledt_font);
    _ledtInput->setMinimumSize(this->width(), this->height() / 5);
    _ledtResult->setMinimumSize(this->width(), this->height() / 5);
    _ledtInput->setLayoutDirection(Qt::LeftToRight);
    _ledtInput->setAlignment(Qt::AlignLeft|Qt::AlignTrailing|Qt::AlignVCenter);
    _ledtResult->setLayoutDirection(Qt::LeftToRight);
    _ledtResult->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    _ledtResult->setReadOnly(true);
    _ledtInput->setStyleSheet("background-color:rgba(240, 240, 240, 255)");
    _ledtResult->setStyleSheet("background-color:rgba(240, 240, 240, 255)");
    QRegExp regx("[ -<>-~]+$");
    QPointer<QValidator> validator = new QRegExpValidator(regx, _ledtInput);
    _ledtInput->setValidator(validator);

    //set PushButton
    ledt_font.setPointSize(20);
    ledt_font.setBold(true);
    _btnZero->setFont(ledt_font);
    _btnOne->setFont(ledt_font);
    _btnTwo->setFont(ledt_font);
    _btnThree->setFont(ledt_font);
    _btnFour->setFont(ledt_font);
    _btnFive->setFont(ledt_font);
    _btnSix->setFont(ledt_font);
    _btnSeven->setFont(ledt_font);
    _btnEight->setFont(ledt_font);
    _btnNine->setFont(ledt_font);
    ledt_font.setBold(false);
    _btnSquare->setFont(ledt_font);
    _btnPower->setFont(ledt_font);
    _btnSin->setFont(ledt_font);
    _btnCos->setFont(ledt_font);
    _btnTan->setFont(ledt_font);
    _btnSqrt->setFont(ledt_font);
    _btn10pow->setFont(ledt_font);
    _btnLog->setFont(ledt_font);
    _btnFrac->setFont(ledt_font);
    _btnMOD->setFont(ledt_font);
    _btnC->setFont(ledt_font);
    _btnAns->setFont(ledt_font);
    _btnBackSpace->setFont(ledt_font);
    _btnDivide->setFont(ledt_font);
    _btnPI->setFont(ledt_font);
    _btnMultiply->setFont(ledt_font);
    _btnFAC->setFont(ledt_font);
    _btnMinus->setFont(ledt_font);
    _btnNegative->setFont(ledt_font);
    _btnPlus->setFont(ledt_font);
    _btnLbracket->setFont(ledt_font);
    _btnRbracket->setFont(ledt_font);
    _btnDot->setFont(ledt_font);
    _btnEqual->setFont(ledt_font);
    _btnCube->setFont(ledt_font);
    _btnRoot->setFont(ledt_font);
    _btnArcSin->setFont(ledt_font);
    _btnArcCos->setFont(ledt_font);
    _btnArcTan->setFont(ledt_font);
    _btnReciprocal->setFont(ledt_font);
    _btnExp->setFont(ledt_font);
    _btnLn->setFont(ledt_font);
    _btnDEG->setFont(ledt_font);
    _btnRAD->setFont(ledt_font);
    _btn2nd->setFont(ledt_font);

    //pushbutton layout
    btnLay_2ndTrue->setContentsMargins(0, 0, 0, 0);
    btnLay_2ndFalse->setContentsMargins(0, 0, 0, 0);
    btnLay_2ndFalse->addWidget(_btnSquare, 1, 1);
    btnLay_2ndFalse->addWidget(_btnPower, 1, 2);
    btnLay_2ndFalse->addWidget(_btnSin, 1, 3);
    btnLay_2ndFalse->addWidget(_btnCos, 1, 4);
    btnLay_2ndFalse->addWidget(_btnTan, 1, 5);
    btnLay_2ndFalse->addWidget(_btnSqrt, 2, 1);
    btnLay_2ndFalse->addWidget(_btn10pow, 2, 2);
    btnLay_2ndFalse->addWidget(_btnLn, 2, 3);
    btnLay_2ndFalse->addWidget(_btnFrac, 2, 4);
    btnLay_2ndFalse->addWidget(_btnMOD, 2, 5);
    btnLay_2ndTrue->addWidget(_btnCube, 1, 1);
    btnLay_2ndTrue->addWidget(_btnRoot, 1, 2);
    btnLay_2ndTrue->addWidget(_btnArcSin, 1, 3);
    btnLay_2ndTrue->addWidget(_btnArcCos, 1, 4);
    btnLay_2ndTrue->addWidget(_btnArcTan, 1, 5);
    btnLay_2ndTrue->addWidget(_btnReciprocal, 2, 1);
    btnLay_2ndTrue->addWidget(_btnExp, 2, 2);
    btnLay_2ndTrue->addWidget(_btnLog, 2, 3);
    btnLay_2ndTrue->addWidget(_btnDEG, 2, 4);
    btnLay_2ndTrue->addWidget(_btnRAD, 2, 5);
    btnLay_5row->addWidget(_btn2nd, 1, 1);
    btnLay_5row->addWidget(_btnAns, 1, 2);
    btnLay_5row->addWidget(_btnC, 1, 3);
    btnLay_5row->addWidget(_btnBackSpace, 1, 4);
    btnLay_5row->addWidget(_btnDivide, 1, 5);
    btnLay_5row->addWidget(_btnPI, 2, 1);
    btnLay_5row->addWidget(_btnSeven, 2, 2);
    btnLay_5row->addWidget(_btnEight, 2, 3);
    btnLay_5row->addWidget(_btnNine, 2, 4);
    btnLay_5row->addWidget(_btnMultiply, 2, 5);
    btnLay_5row->addWidget(_btnFAC, 3, 1);
    btnLay_5row->addWidget(_btnFour, 3, 2);
    btnLay_5row->addWidget(_btnFive, 3, 3);
    btnLay_5row->addWidget(_btnSix, 3, 4);
    btnLay_5row->addWidget(_btnMinus, 3, 5);
    btnLay_5row->addWidget(_btnNegative, 4, 1);
    btnLay_5row->addWidget(_btnOne, 4, 2);
    btnLay_5row->addWidget(_btnTwo, 4, 3);
    btnLay_5row->addWidget(_btnThree, 4, 4);
    btnLay_5row->addWidget(_btnPlus, 4, 5);
    btnLay_5row->addWidget(_btnLbracket, 5, 1);
    btnLay_5row->addWidget(_btnRbracket, 5, 2);
    btnLay_5row->addWidget(_btnZero, 5, 3);
    btnLay_5row->addWidget(_btnDot, 5, 4);
    btnLay_5row->addWidget(_btnEqual, 5, 5);
    for (int i(0); i < btnLay_2ndTrue->count(); ++i) {
        btnLay_2ndTrue->itemAt(i)->widget()->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    }
    for (int i(0); i < btnLay_2ndFalse->count(); ++i) {
        btnLay_2ndFalse->itemAt(i)->widget()->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    }
    for (int i(0); i < btnLay_5row->count(); ++i) {
        btnLay_5row->itemAt(i)->widget()->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    }
    firstPageWidget->setLayout(btnLay_2ndFalse);
    secondPageWidget->setLayout(btnLay_2ndTrue);
    btnLay_2row->addWidget(firstPageWidget);
    btnLay_2row->addWidget(secondPageWidget);

    //mainLayout
    mainLayout->addWidget(_ledtInput);
    mainLayout->addWidget(_ledtResult);
    mainLayout->addLayout(btnLay_2row);
    mainLayout->addLayout(btnLay_5row);
    mainLayout->setStretchFactor(btnLay_2row, 2);
    mainLayout->setStretchFactor(btnLay_5row, 5);

    this->setLayout(mainLayout);
}

void System::init_connect()
{
    connect(_btn2nd, &QPushButton::clicked, this, &System::on_btn2nd_clicked);
    connect(_btnEqual, &QPushButton::clicked, this, &System::on_btnEqual_clicked);
    connect(_ledtInput, &QLineEdit::textEdited, this, &System::on_ledtInput_textChanged);
    connect(_ledtInput, &QLineEdit::cursorPositionChanged, this, &System::on_ledtInput_cursorPositionChanged);
    connect(_btnZero, &QPushButton::clicked, this, &System::on_btnZero_clicked);
    connect(_btnOne, &QPushButton::clicked, this, &System::on_btnOne_clicked);
    connect(_btnTwo, &QPushButton::clicked, this, &System::on_btnTwo_clicked);
    connect(_btnThree, &QPushButton::clicked, this, &System::on_btnThree_clicked);
    connect(_btnFour, &QPushButton::clicked, this, &System::on_btnFour_clicked);
    connect(_btnFive, &QPushButton::clicked, this, &System::on_btnFive_clicked);
    connect(_btnSix, &QPushButton::clicked, this, &System::on_btnSix_clicked);
    connect(_btnSeven, &QPushButton::clicked, this, &System::on_btnSeven_clicked);
    connect(_btnEight, &QPushButton::clicked, this, &System::on_btnEight_clicked);
    connect(_btnNine, &QPushButton::clicked, this, &System::on_btnNine_clicked);
    connect(_btnPlus, &QPushButton::clicked, this, &System::on_btnPlus_clicked);\
    connect(_btnMinus, &QPushButton::clicked, this, &System::on_btnMinus_clicked);
    connect(_btnMultiply, &QPushButton::clicked, this, &System::on_btnMultiply_clicked);
    connect(_btnDivide, &QPushButton::clicked, this, &System::on_btnDivide_clicked);
    connect(_btnC, &QPushButton::clicked, this, &System::on_btnC_clicked);
    connect(_btnSquare, &QPushButton::clicked, this, &System::on_btnSquare_clicked);
    connect(_btnPower, &QPushButton::clicked, this, &System::on_btnPower_clicked);
    connect(_btnSqrt, &QPushButton::clicked, this, &System::on_btnSqrt_clicked);
    connect(_btn10pow, &QPushButton::clicked, this, &System::on_btn10pow_clicked);
    connect(_btnMOD, &QPushButton::clicked, this, &System::on_btnMOD_clicked);
    connect(_btnPI, &QPushButton::clicked, this, &System::on_btnPI_clicked);
    connect(_btnFAC, &QPushButton::clicked, this, &System::on_btnFAC_clicked);
    connect(_btnSin, &QPushButton::clicked, this, &System::on_btnSin_cliked);
    connect(_btnCos, &QPushButton::clicked, this, &System::on_btnCos_clicked);
    connect(_btnTan, &QPushButton::clicked, this, &System::on_btnTan_clicked);
    connect(_btnLog, &QPushButton::clicked, this, &System::on_btnLog_clicked);
    connect(_btnBackSpace, &QPushButton::clicked, this, &System::on_btnBackSpace_clicked);
    connect(_btnDot, &QPushButton::clicked, this, &System::on_btnDot_clicked);
    connect(_btnLbracket, &QPushButton::clicked, this, &System::on_btnLbracket_clicked);
    connect(_btnRbracket, &QPushButton::clicked, this, &System::on_btnRbracket_clicked);
    connect(_btnNegative, &QPushButton::clicked, this, &System::on_btnNegative_clicked);
    connect(_btnCube, &QPushButton::clicked, this, &System::on_btnCube_clicked);
    connect(_btnRoot, &QPushButton::clicked, this, &System::on_btnRoot_clicked);
    connect(_btnArcSin, &QPushButton::clicked, this, &System::on_btnArcSin_clicked);
    connect(_btnArcCos, &QPushButton::clicked, this, &System::on_btnArcCos_clicked);
    connect(_btnArcTan, &QPushButton::clicked, this, &System::on_btnArcTan_clicked);
    connect(_btnAns, &QPushButton::clicked, this, &System::on_btnAns_clicked);
    connect(_btnReciprocal, &QPushButton::clicked, this, &System::on_btnReciprocal_clicked);
    connect(_btnExp, &QPushButton::clicked, this, &System::on_btnExp_clicked);
    connect(_btnLn, &QPushButton::clicked, this, &System::on_btnLn_clicked);
    connect(_btnFrac, &QPushButton::clicked, this, &System::on_btnFrac_clicked);
    connect(_btnDEG, &QPushButton::clicked, this, &System::on_btnDEG_clicked);
    connect(_btnRAD, &QPushButton::clicked, this, &System::on_btnRAD_clicked);
}

void System::on_ledtInput_textChanged(const QString &new_text)
{
    m_expr = new_text.toStdString();
}

void System::on_ledtInput_cursorPositionChanged(int oldPos, int newPos)
{
    m_oldCursorPos = oldPos;
    m_newCursorPos = newPos;
}

void System::on_btnZero_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '0');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnOne_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '1');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnTwo_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '2');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnThree_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '3');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnFour_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '4');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnFive_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '5');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnSix_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '6');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnSeven_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '7');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnEight_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '8');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnNine_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '9');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btn10_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "10");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 2);
}

void System::on_btnSquare_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "()^2");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnPower_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "()^()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnSqrt_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "sqrt()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 5);
}

void System::on_btn10pow_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "10^()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 4);
}

void System::on_btnMOD_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "%");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnPI_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "pi");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 2);
}

void System::on_btnFAC_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "!");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnSin_cliked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "sin()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 4);
}

void System::on_btnCos_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "cos()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 4);
}

void System::on_btnTan_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "tan()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 4);
}

void System::on_btnLog_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "()log()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnFrac_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "()/()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnPlus_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '+');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnMinus_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '-');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnMultiply_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '*');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnDivide_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '/');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnC_clicked(bool)
{
    m_expr.clear();
    _ledtInput->clear();
    _ledtResult->clear();
}

void System::on_btnAns_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), m_result.toStdString());
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + m_result.length());
}

void System::on_btn2nd_clicked(bool)
{
    if(!btn2nd_state) {
        btnLay_2row->setCurrentWidget(secondPageWidget);
        _btn2nd->setText("2nd○");
        btn2nd_state = !btn2nd_state;
    }
    else {
        btnLay_2row->setCurrentWidget(firstPageWidget);
        _btn2nd->setText("2nd");
        btn2nd_state = !btn2nd_state;
    }
}

void System::on_btnBackSpace_clicked(bool)
{
    if(!m_expr.empty() && m_newCursorPos > 0)
        m_expr.erase(static_cast<size_t>(m_newCursorPos - 1), 1);
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos - 1);
}

void System::on_btnEqual_clicked(bool)
{
    try {
        if(!m_expr.empty()){
            m_result = QString::number(m_cclt->doIt(m_expr));
            _ledtResult->setText(m_result);
            m_expr.pop_back(); //cut off the "="
        }
    }
    catch (exception &e) {
        _ledtResult->setText(QString::fromStdString(e.what()));
        m_expr.pop_back();
    }
}

void System::on_btnDot_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '.');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnLbracket_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '(');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnRbracket_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, ')');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnNegative_clicked(bool)
{
    m_expr.insert(m_expr.begin() + m_newCursorPos, '~');
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnCube_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "()^3");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnRoot_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "()^(1/())");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 1);
}

void System::on_btnArcSin_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "asin()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 5);
}

void System::on_btnArcCos_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "acos()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 5);
}

void System::on_btnArcTan_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "atan()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 5);
}

void System::on_btnReciprocal_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "1/()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 3);
}

void System::on_btnExp_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "exp()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 4);
}

void System::on_btnLn_clicked(bool)
{
    m_expr.insert(static_cast<size_t>(m_newCursorPos), "ln()");
    _ledtInput->setText(QString::fromStdString(m_expr));
    _ledtInput->setFocus();
    _ledtInput->setCursorPosition(m_oldCursorPos + 3);
}

void System::on_btnDEG_clicked(bool)
{
    _btnDEG->setText("deg○");
    _btnRAD->setText("rad");
    Operator::setDegMode();
}

void System::on_btnRAD_clicked(bool)
{
    _btnRAD->setText("rad○");
    _btnDEG->setText("deg");
    Operator::setRadMode();
}

void System::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter
            || event->key() == Qt::Key_Return)
        on_btnEqual_clicked(true);
}

