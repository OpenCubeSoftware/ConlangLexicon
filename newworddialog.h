#ifndef NEWWORDDIALOG_H
#define NEWWORDDIALOG_H

#include <QDialog>
#include "entry.h"

namespace Ui {
class NewWordDialog;
}

class NewWordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewWordDialog(QWidget *parent = nullptr);
    ~NewWordDialog();

signals:
    void entryCreated(const Entry &entry);

private slots:
    void on_btnAddWord_clicked();

    void on_btnAddAdditional_clicked();

private:
    Ui::NewWordDialog *ui;
    Entry createNewEntry();
    void resetForm();
};

#endif // NEWWORDDIALOG_H
