#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newworddialog.h"
#include "landingwindow.h"
#include <QMessageBox>
#include <QIODevice>
#include <QFileDialog>
#include <QJsonArray>
#include <QStandardPaths>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	QString savePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
	QDir dir(savePath);
	if (!dir.exists()) {
		if (dir.mkpath(".")) {
			// dir created
		} else {
			qDebug() << "failed to create folder " << dir.absolutePath();
		}
	}

	this->setWindowTitle("Conlang Lexicon");
	 showLandingWindow();
}

void MainWindow::showLandingWindow()
{
		landingWindow = new LandingWindow(this);
		setCentralWidget(landingWindow);
		QObject::connect(landingWindow, &LandingWindow::createNewLexicon, this, &MainWindow::handleCreateNewLexicon);
		QObject::connect(landingWindow, &LandingWindow::openExistingLexicon, this, &MainWindow::handleOpenLexicon);
		landingWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCreateNewLexicon()
{
		currentFile = QFileDialog::getSaveFileName(this, "Create New Lexicon", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), "JSON Files (*.json)");
		if (currentFile.isEmpty()) {
			return;
		}
		ui->setupUi(this);
		saveEntries(); // save empty array to new file
		this->setWindowTitle("Conlang Lexicon");
		this->show();
}

void MainWindow::handleOpenLexicon()
{
	currentFile = QFileDialog::getOpenFileName(this, "Open Lexicon", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), "JSON Files (*.json)");
	if (currentFile.isEmpty()) {
		return;
	}
	ui->setupUi(this);
	loadEntries();
	this->setWindowTitle("Conlang Lexicon");
	this->show();
}

void MainWindow::addEntry(const Entry &entry)
{
    entries.append(entry);
		// ui->listWidget->addItem(entry.word + " - " + entry.translation);
		addEntryToListWidget(entry);
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
				//ui->listWidget->addItem(entry.word + " - " + entry.translation);
    }
		sortEntries();
		for (const auto &entry : entries){
			addEntryToListWidget(entry);
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
		sortEntries();
}

void MainWindow::sortEntries()
{
	std::sort(entries.begin(), entries.end());
	std::sort(filteredEntries.begin(), filteredEntries.end());
}

void MainWindow::backupFile(const QString &filePath)
{
	QFile file(filePath);
	if (!file.exists()) {
		return;
	}
	QFileInfo fileInfo = QFileInfo(file.fileName());
	QString fileName = fileInfo.baseName();
	QString savePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
	qDebug() << "SavePath is " << savePath;
	QDateTime currentTime = QDateTime::currentDateTime();
	QString saveFileName = savePath + "/" + fileName + currentTime.toString("hhmmss") + ".bak";
	QFile::copy(filePath, saveFileName);
}

void MainWindow::addEntryToListWidget(const Entry &entry) const
{
	ui->listWidget->addItem( entry.getListViewDisplay());
}

void MainWindow::addCurrentEntriesToListWidget() const
{
	for (const auto &entry : entries) {
		addEntryToListWidget(entry);
	}
}

void MainWindow::applySearchFilter(const QString &filterText)
{
	ui->listWidget->clear();
	filteredEntries.clear();
	// show all items if search is empty
	if (filterText == "")
	{
		addCurrentEntriesToListWidget();
		return;
	}


	for (const Entry& entry : entries) {
		if (entry.matchesSearch(filterText)) {
			filteredEntries.append(entry);
			addEntryToListWidget(entry);
		}
	}
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
		bool isFiltered = !ui->txtSearch->text().isEmpty();
		int index = ui->listWidget->row(item);
		const QVector<Entry>& activeList = isFiltered ? filteredEntries : entries;
    if (index >= 0 && index < activeList.size()) {
        const Entry &entry = activeList[index];
        QString details;
        details += "Word: " + entry.word + "\n";
        details += "Translation: " + entry.translation + "\n";
        details += "Part of Speech: " + entry.partOfSpeech + "\n";
        details += "Examples:\n";
        for(const auto &example : entry.examples) {
            details += " - " + example + "\n";
        }
        details += "Notes: " + entry.notes + "\n";
        ui->detailsText->setText(details);
    }
}


void MainWindow::on_txtSearch_textChanged(const QString &arg1)
{
	qDebug() << "Entered text is " << arg1;
	applySearchFilter(arg1);
}


void MainWindow::on_actionOpen_triggered()
{
	handleOpenLexicon();
}


void MainWindow::on_actionNew_triggered()
{
	handleCreateNewLexicon();
}

