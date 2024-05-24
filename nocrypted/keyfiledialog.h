#ifndef KEYFILEDIALOG_H
#define KEYFILEDIALOG_H

#include <QDialog>

class QLabel;
class QTextEdit;
class QPushButton;

class KeyFileDialog : public QDialog
{
    Q_OBJECT

public:
    KeyFileDialog(QWidget *parent = nullptr);

private slots:
    void save();
    void browse();

private:
    QLabel *saveAsLabel;
    QTextEdit *saveAsTextEdit;
    QLabel *tagsLabel;
    QTextEdit *tagsTextEdit;
    QLabel *fileLabel;
    QLabel *filePathLabel; // Tambahkan label untuk menampilkan path file
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QPushButton *browseButton;
};

#endif // KEYFILEDIALOG_H
