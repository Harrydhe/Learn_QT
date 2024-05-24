#include "mainwindow.h"
#include "generate.h"
#include "qapplication.h"
#include "keyfiledialog.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include <QClipboard>
#include <QTextEdit>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    //Drop Files
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Mengatur widget untuk unggah file
    QHBoxLayout *uploadLayout = new QHBoxLayout();
    uploadFileLineEdit = new QLineEdit(this);
    uploadFileLineEdit->setReadOnly(true); // Hanya untuk menampilkan hasil unggahan
    uploadFileLineEdit->setFixedSize(500, 30); // Menetapkan lebar dan tinggi
    uploadFileLineEdit->setPlaceholderText("Unggah file kesini"); // Menambahkan placeholder
    uploadLayout->addWidget(uploadFileLineEdit); // Menambahkan QLineEdit ke dalam layout
    uploadFileButton = new QPushButton("Upload File", this);
    uploadFileButton->setFixedSize(150,30);
    connect(uploadFileButton, &QPushButton::clicked, this, &MainWindow::drop);
    uploadLayout->addWidget(uploadFileButton); // Menambahkan QPushButton ke dalam layout
    mainLayout->addLayout(uploadLayout); // Menambahkan layout horizontal ke dalam layout utama

    // Mengatur widget untuk tombol clear
    QHBoxLayout *clearFilesLayout = new QHBoxLayout();
    clearFilesButton = new QPushButton("Clear", this);
    connect(clearFilesButton, &QPushButton::clicked, this, &MainWindow::clearFilesTextEdit);
    clearFilesLayout->addWidget(clearFilesButton); // Menambahkan tombol Clear ke dalam layout horizontal
    mainLayout->addLayout(clearFilesLayout); // Menambahkan layout horizontal ke dalam layout utama


    // Password

    passwordLabel = new QLabel("Password:", this);
    mainLayout->addWidget(passwordLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    showPasswordButton = new QPushButton("Show", this); // Inisialisasi button show
    connect(showPasswordButton, &QPushButton::clicked, this, &MainWindow::showPassword); // Menghubungkan showPasswordButton dengan slot showPassword
    buttonLayout->addWidget(showPasswordButton); // Menambahkan showPasswordButton ke buttonLayout

    clearPasswordButton = new QPushButton("Clear", this);
    connect(clearPasswordButton, &QPushButton::clicked, this, &MainWindow::clearPassword);
    buttonLayout->addWidget(clearPasswordButton);

    copyButton = new QPushButton("Copy", this);
    connect(copyButton, &QPushButton::clicked, this, &MainWindow::copyPassword);
    buttonLayout->addWidget(copyButton);

    pasteButton = new QPushButton("Paste", this);
    connect(pasteButton, &QPushButton::clicked, this, &MainWindow::pastePassword);
    buttonLayout->addWidget(pasteButton);

    createButton = new QPushButton("Create", this);
    connect(createButton, &QPushButton::clicked, this, &MainWindow::createPassword);
    buttonLayout->addWidget(createButton);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setFixedSize(600, 30);
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(passwordLineEdit);

    setCentralWidget(centralWidget);


    //ConfirmPassword
    confirmPasswordLabel = new QLabel(" Confirm Password:", this);
    mainLayout->addWidget(confirmPasswordLabel);

    confirmPasswordLineEdit = new QLineEdit(this);
    confirmPasswordLineEdit->setFixedSize(600, 30);
    confirmPasswordLineEdit->setEchoMode(QLineEdit::Password); // Set echo mode ke Password
    mainLayout->addWidget(confirmPasswordLineEdit);


    // Membuat keyfiles
    keyFileLabel = new QLabel("Key File:", this);
    mainLayout->addWidget(keyFileLabel);

    QHBoxLayout *keyFileLayout = new QHBoxLayout();

    keyFileLineEdit = new QLineEdit(this);
    keyFileLayout->addWidget(keyFileLineEdit);

    editKeyFileButton = new QPushButton("Edit", this);
    connect(editKeyFileButton, &QPushButton::clicked, this, &MainWindow::editKeyFile);
    keyFileLayout->addWidget(editKeyFileButton);

    createKeyFileButton = new QPushButton("Create", this);
    connect(createKeyFileButton, &QPushButton::clicked, this, &MainWindow::createKeyFile);
    keyFileLayout->addWidget(createKeyFileButton);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(createKeyFileButton);

    QWidget *central = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    noneSelectedButton = new QPushButton("None Selected", this);
    connect(noneSelectedButton, &QPushButton::clicked, this, &MainWindow::noneSelected);
    keyFileLayout->addWidget(noneSelectedButton);

    mainLayout->addLayout(keyFileLayout);


    commentLabel = new QLabel("Comment:", this);
    mainLayout->addWidget(commentLabel);
    commentTextEdit = new QTextEdit(this);
    commentTextEdit->setFixedSize(600,50);
    mainLayout->addWidget(commentTextEdit);

    //Advance
    mainLayout->addWidget(new QLabel("Advanced:", this));

    // Membuat checkbox
    paranoidModeCheckBox = new QCheckBox("Paranoid Mode", this);
    reedSolomonCheckBox = new QCheckBox("Reed-Solomon", this);
    deniabilityCheckBox = new QCheckBox("Deniability", this);
    splitIntoChunksCheckBox = new QCheckBox("Split Into Chunks", this);
    compressFilesCheckBox = new QCheckBox("Compress Files", this);
    deletesFilesCheckBox = new QCheckBox("Deletes Files", this);
    recursivelyCheckBox = new QCheckBox("Recursively", this);

    // Membuat combo box dan line edit
    sizeComboBox = new QComboBox(this);
    sizeComboBox->setFixedSize(100, 20);
    sizeComboBox->addItem("KiB");
    sizeComboBox->addItem("MiB");
    sizeComboBox->addItem("GiB");

    QLineEdit *numberLineEdit = new QLineEdit(this);
    numberLineEdit->setPlaceholderText("Enter number");
    numberLineEdit->setFixedSize(100,20);

    QGridLayout *gridLayout = new QGridLayout();

    // Menambahkan checkbox ke dalam grid
    gridLayout->addWidget(paranoidModeCheckBox, 0, 0);
    gridLayout->addWidget(reedSolomonCheckBox, 1, 0);
    gridLayout->addWidget(deniabilityCheckBox, 2, 0);
    gridLayout->addWidget(splitIntoChunksCheckBox, 0, 1);
    gridLayout->addWidget(compressFilesCheckBox, 1, 1);
    gridLayout->addWidget(deletesFilesCheckBox, 2, 1);
    gridLayout->addWidget(recursivelyCheckBox, 0, 2);

    // Menambahkan combo box dan line edit ke dalam grid
    gridLayout->addWidget(sizeComboBox, 1, 2);
    gridLayout->addWidget(numberLineEdit, 2, 2);

    // Menetapkan horizontal spacing agar lebih mudah dibaca
    gridLayout->setHorizontalSpacing(20);

    // Menambahkan grid layout ke dalam layout utama
    mainLayout->addLayout(gridLayout);



    //SaveOutFile
    saveOutputAsLabel = new QLabel("Save Output As:", this);
    mainLayout->addWidget(saveOutputAsLabel);

    outputDirectoryTextEdit = new QTextEdit(this);
    outputDirectoryTextEdit->setFixedSize(450,30);
    mainLayout->addWidget(outputDirectoryTextEdit);

    changeOutputButton = new QPushButton("Change", this);
    connect(changeOutputButton, &QPushButton::clicked, this, &MainWindow::changeOutputDirectory);


    QHBoxLayout *outputDirectoryLayout = new QHBoxLayout();
    outputDirectoryLayout->addWidget(outputDirectoryTextEdit);
    outputDirectoryLayout->addWidget(changeOutputButton);

    mainLayout->addLayout(outputDirectoryLayout);


    startButton = new QPushButton("Start", this);
    mainLayout->addWidget(startButton);

    setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
}

void MainWindow::clearFilesTextEdit()
{
    filesTextEdit->clear();
}

void MainWindow::showPassword()
{
    if (passwordLineEdit->echoMode() == QLineEdit::Password) {
        passwordLineEdit->setEchoMode(QLineEdit::Normal);
        showPasswordButton->setText("Hide");
    } else {
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        showPasswordButton->setText("Show");
    }
}

void MainWindow::clearPassword()
{
    passwordLineEdit->clear();
}

void MainWindow::copyPassword()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(passwordLineEdit->text());
}


void MainWindow::pastePassword()
{
    QClipboard *clipboard = QApplication::clipboard();
    QString text = clipboard->text();
    passwordLineEdit->setText(text);
}

void MainWindow::createPassword()
{
    // Membuat dialog formulir Generate
    Generate *dialog = new Generate(this);
    dialog->setWindowTitle("Change Output Directory");
    dialog->exec();
    delete dialog;

}


void MainWindow::clearConfirmPassword()
{
    confirmPasswordLineEdit->clear();
}

void MainWindow::clearKeyFile()
{
    keyFileLineEdit->clear();
}

void MainWindow::editKeyFile()
{
    // Implement your logic for editing key file here
    QMessageBox::information(this, "Edit Key File", "Functionality not implemented yet!");
}

void MainWindow::createKeyFile()
{
    KeyFileDialog *dialog = new KeyFileDialog(this);
    dialog->exec();
    delete dialog;
}

void MainWindow::noneSelected()
{
    // Implement your logic for when "None Selected" button is clicked
    QMessageBox::information(this, "None Selected", "Functionality not implemented yet!");
}

void MainWindow::changeOutputDirectory()
{
    KeyFileDialog *dialog = new KeyFileDialog(this);
    dialog->setWindowTitle("Change Output Directory");
    dialog->exec();
    delete dialog;
}

void MainWindow::drop()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Upload File"), QDir::homePath(), tr("All Files (*)"));
    if (!filePath.isEmpty()) {
        uploadFileLineEdit->setText(filePath);
    }
}


