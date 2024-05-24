#include "keyfiledialog.h"
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

KeyFileDialog::KeyFileDialog(QWidget *parent) : QDialog(parent)
{
    saveAsLabel = new QLabel("Save As:", this);
    saveAsTextEdit = new QTextEdit(this);
    saveAsTextEdit->setFixedSize(200, 30);

    tagsLabel = new QLabel("Tags:", this);
    tagsTextEdit = new QTextEdit(this);
    tagsTextEdit->setFixedSize(200, 30);

    fileLabel = new QLabel("Where", this);
    filePathLabel = new QLabel(this); // Tambahkan label untuk menampilkan path file
    browseButton = new QPushButton("Browse", this);

    saveButton = new QPushButton("Save", this);
    cancelButton = new QPushButton("Cancel", this);

    QHBoxLayout *fileLayout = new QHBoxLayout; // Layout horizontal untuk label file dan tombol browse
    fileLayout->addWidget(fileLabel); // Tambahkan label "Where"
    fileLayout->addWidget(filePathLabel); // Tambahkan label untuk menampilkan path file
    fileLayout->addWidget(browseButton); // Tambahkan tombol "Browse"

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(saveAsLabel);
    layout->addWidget(saveAsTextEdit);
    layout->addWidget(tagsLabel);
    layout->addWidget(tagsTextEdit);
    layout->addLayout(fileLayout); // Tambahkan layout fileLayout
    layout->addWidget(saveButton);
    layout->addWidget(cancelButton);
    setLayout(layout);

    connect(saveButton, &QPushButton::clicked, this, &KeyFileDialog::save);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    connect(browseButton, &QPushButton::clicked, this, &KeyFileDialog::browse); // Koneksikan tombol "Browse" dengan slot browse

}

void KeyFileDialog::save()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // Dapatkan teks dari QTextEdit dan simpan ke dalam file
            QTextStream out(&file);
            out << saveAsTextEdit->toPlainText() << "\n";
            out << tagsTextEdit->toPlainText();
            file.close();
        }
    }
    accept(); // Tutup dialog setelah penyimpanan berhasil
}

void KeyFileDialog::browse()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty()) {
        filePathLabel->setText(fileName); // Set teks pada filePathLabel dengan path file yang dipilih
    }
}
