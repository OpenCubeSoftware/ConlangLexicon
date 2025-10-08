#include "newworddialog.h"
#include "ui_newworddialog.h"

NewWordDialog::NewWordDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewWordDialog)
{
    ui->setupUi(this);
}

NewWordDialog::~NewWordDialog()
{
    delete ui;
}

void NewWordDialog::on_btnAddWord_clicked()
{
    Entry entry = createNewEntry();
    emit entryCreated(entry);
    accept();
}


Entry NewWordDialog::createNewEntry()
{
    Entry entry;
    entry.word = ui->txtWord->text();
    entry.translation = ui->txtTranslation->text();
    entry.partOfSpeech = ui->txtPartOfSpeech->text();
    entry.examples = ui->txtEExamples->toPlainText().split('\n', Qt::SkipEmptyParts);
    entry.notes = ui->txtENotes->toPlainText();

    return entry;
}

void NewWordDialog::on_btnAddAdditional_clicked()
{
    Entry entry = createNewEntry();
    emit entryCreated(entry);
    resetForm();
}

void NewWordDialog::resetForm()
{
    ui->txtWord->setText("");
    ui->txtTranslation->setText("");
    ui->txtPartOfSpeech->setText("");
    ui->txtEExamples->setText("");
    ui->txtENotes->setText("");
}

