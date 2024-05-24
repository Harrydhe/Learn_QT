#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void clearFilesTextEdit();
    void showPassword();
    void clearPassword();
    void copyPassword();
    void pastePassword();
    void createPassword();
    void clearConfirmPassword();
    void clearKeyFile();
    void editKeyFile();
    void createKeyFile();
    void noneSelected();
    void changeOutputDirectory();
    void drop ();

private:
    QLineEdit *uploadFileLineEdit; // Menggunakan QLineEdit untuk menampilkan path file yang diunggah
    QPushButton *uploadFileButton; // Tombol untuk memicu dialog unggah file
    QTextEdit *filesTextEdit;
    QLineEdit *passwordLineEdit;
    QLabel *passwordLabel;
    QPushButton *showPasswordButton; // Tambahkan button show
    QPushButton *clearFilesButton;
    QPushButton *clearPasswordButton;
    QPushButton *copyButton;
    QPushButton *pasteButton;
    QPushButton *createButton;
    QLineEdit *confirmPasswordLineEdit;
    QLabel *confirmPasswordLabel;
    QLineEdit *keyFileLineEdit;
    QLabel *keyFileLabel;
    QPushButton *editKeyFileButton;
    QPushButton *createKeyFileButton;
    QPushButton *noneSelectedButton;
    QTextEdit *commentTextEdit;
    QLabel *commentLabel;
    QCheckBox *paranoidModeCheckBox;
    QCheckBox *reedSolomonCheckBox;
    QCheckBox *deniabilityCheckBox;
    QCheckBox *splitIntoChunksCheckBox;
    QCheckBox *compressFilesCheckBox;
    QCheckBox *deletesFilesCheckBox;
    QCheckBox *recursivelyCheckBox;
    QComboBox *sizeComboBox;
    QLabel *saveOutputAsLabel;
    QTextEdit *outputDirectoryTextEdit;
    QPushButton *changeOutputButton;
    QPushButton *startButton;

};

#endif // MAINWINDOW_H
