#include "generate.h"
#include <QLayout>


Generate::Generate(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Generate password");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Label "Generate Password"
    generatePasswordLabel = new QLabel("Generate Password:", this);
    mainLayout->addWidget(generatePasswordLabel);

    // Layout untuk panjang password
    QHBoxLayout *lengthLayout = new QHBoxLayout();
    lengthLabel = new QLabel("Length:", this);
    lengthLayout->addWidget(lengthLabel);
    lengthLineEdit = new QLineEdit(this);
    lengthLineEdit->setFixedWidth(150);
    lengthLayout->addWidget(lengthLineEdit);
    mainLayout->addLayout(lengthLayout);

    // Checkboxes untuk opsi password
    uppercaseCheckBox = new QCheckBox("Uppercase", this);
    mainLayout->addWidget(uppercaseCheckBox);
    lowercaseCheckBox = new QCheckBox("Lowercase", this);
    mainLayout->addWidget(lowercaseCheckBox);
    numbersCheckBox = new QCheckBox("Numbers", this);
    mainLayout->addWidget(numbersCheckBox);
    symbolsCheckBox = new QCheckBox("Symbols", this);
    mainLayout->addWidget(symbolsCheckBox);

    // Checkbox untuk salin ke clipboard
    copyCheckBox = new QCheckBox("Copy to clipboard", this);
    mainLayout->addWidget(copyCheckBox);

    // Layout untuk tombol
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    cancelButton = new QPushButton("Cancel", this);
    buttonLayout->addWidget(cancelButton);
    generateButton = new QPushButton("Generate", this);
    buttonLayout->addWidget(generateButton);
    mainLayout->addLayout(buttonLayout);

    connect(cancelButton, &QPushButton::clicked, this, &Generate::close);
    // connect(generateButton, &QPushButton::clicked, this, &MainWindow::generatePassword); // Uncomment and implement this slot if you want to generate password
}

Generate::~Generate()
{
}

