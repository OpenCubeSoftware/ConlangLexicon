#include "landingwindow.h"
#include "ui_landingwindow.h"

LandingWindow::LandingWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::LandingWindow)
{
	ui->setupUi(this);
	connect(ui->btnNewLexicon, &QPushButton::clicked, this, &LandingWindow::createNewLexicon);
	connect(ui->btnOpenLexicon, &QPushButton::clicked, this, &LandingWindow::openExistingLexicon);
}

LandingWindow::~LandingWindow()
{
	delete ui;
}
