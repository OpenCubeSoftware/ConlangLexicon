#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newworddialog.h"
#include "landingwindow.h"
#include <QMessageBox>
#include <QIODevice>
#include <QFileDialog>
#include <QJsonArray>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	 showLandingWindow();
    // DEBUG ONLY
		// currentFile = "/Volumes/MacSSD/Users/michael/Documents/aaa-kittylang.json";
		// loadEntries();
		// END DEBUG


}

void MainWindow::showLandingWindow()
{
		LandingWindow landingWindow;
		setCentralWidget((QWidget)landingWindow);
		QObject::connect(landingWindow, &LandingWindow::createNewLexicon, this, &MainWindow::handleCreateNewLexicon);
		QObject::connect(landingWindow, &LandingWindow::openExistingLexicon, this, &MainWindow::handleOpenLexicon);
		landingWindow.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCreateNewLexicon()
{
		currentFile = QFileDialog::getSaveFileName(this, "Create New Lexicon", "", "JSON Files (*.json)");
		if (currentFile.isEmpty()) {
			return;
		}
		ui->setupUi(this);
		saveEntries(); // save empty array to new file
}

void MainWindow::handleOpenLexicon()
{
	currentFile = QFileDialog::getOpenFileName(this, "Open Lexicon", "", "JSON Files (*.json)");
	if (currentFile.isEmpty()) {
		return;
	}
	ui->setupUi(this);
	loadEntries();
}

void MainWindow::addEntry(const Entry &entry)
{
    entries.append(entry);
    ui->listWidget->addItem(entry.word + " - " + entry.translation);
		saveEntries();
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
    backupFile(currentFile);
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
		for (const auto &entry : entries) {
			QJsonObject entryObject;
			entry.write(entryObject);
			jsonEntries.append(entryObject);
		}
		QJsonDocument doc(jsonEntries);
		QFile file(currentFile);

		if (!file.open(QIODevice::WriteOnly)) {
			 QMessageBox::critical(this, "Error", "Could not save file");
		}

		file.write(doc.toJson());

}

void MainWindow::setupConnections()
{

}

void MainWindow::backupFile(const QString &filePath)
{
	QDateTime currentTime = QDateTime::currentDateTime();
	QString saveFileName = filePath + currentTime.toString("hhmmss") + ".bak";
	QFile::copy(filePath, saveFileName);
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
