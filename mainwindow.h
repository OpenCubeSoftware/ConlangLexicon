#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFile>

#include "entry.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class LandingWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
		void handleCreateNewLexicon();
		void handleOpenLexicon();
    void addEntry(const Entry &entry);
    void on_btnAddWord_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
		LandingWindow *landingWindow;
		void showLandingWindow();
    void loadEntries();
    void saveEntries();
    void setupConnections();
		void backupFile(const QString &filePath);

    QString currentFile;
    QVector<Entry> entries;

};
#endif // MAINWINDOW_H
