#ifndef GENERATE_H
#define GENERATE_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

class Generate : public QDialog
{
    Q_OBJECT

public:
    Generate(QWidget *parent = nullptr);
    ~Generate();

private:
    QLabel *generatePasswordLabel;
    QLabel *lengthLabel;
    QLineEdit *lengthLineEdit;
    QCheckBox *uppercaseCheckBox;
    QCheckBox *lowercaseCheckBox;
    QCheckBox *numbersCheckBox;
    QCheckBox *symbolsCheckBox;
    QCheckBox *copyCheckBox;
    QPushButton *cancelButton;
    QPushButton *generateButton;
    void setCentralWidget(QWidget *);
};

#endif // GENERATE_H
