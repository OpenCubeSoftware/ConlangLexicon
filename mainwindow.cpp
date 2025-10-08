#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newworddialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // DEBUG ONLY
    currentFile = "/Volumes/MacSSD/Users/michael/Documents/aaa-kittylang.json"

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addEntry(const Entry &entry)
{
    entries.append(entry);
    ui->listWidget->addItem(entry.word + " - " + entry.translation);
    //saveEntries();
}

void MainWindow::on_btnAddWord_clicked()
{
    NewWordDialog newWordDialog;
    QObject::connect(&newWordDialog, &NewWordDialog::entryCreated, this, &MainWindow::addEntry);
    newWordDialog.setModal(true);
    newWordDialog.exec();
}

void MainWindow::loadEntries()
{
    QFile file(currentFile);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Could not open file");
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
    QJsonArray jsonEntries = doc.array();

    entries.clear();
    ui->listWidget->clear();

    for (const auto &entryValue : jsonEntries) {
        Entry entry;
        entry.read(entryValue.toObject());
        entries.append(entry);
        ui->listWidget->addItem(entry.word + " - " + entry.translation);
    }
}

void MainWindow::saveEntries()
{
    QJsonArray jsonEntries;
}

void MainWindow::setupConnections()
{

}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->row(item);
    if (index >= 0 && index < entries.size()) {
        const Entry &entry = entries[index];
        QString details;
        details += "Word: " + entry.word + "\n";
        details += "Translation: " + entry.translation + "\n";
        details += "Part of Speech: " + entry.partOfSpeech + "\n";
        details += "Examples:\n";
        for(const auto &example : entry.examples) {
            details += " - " + example + "\n";
        }
        ui->detailsText->setText(details);
        details += "Notes: " + entry.notes + "\n";
    }
}

