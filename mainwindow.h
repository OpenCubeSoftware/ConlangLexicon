#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QSortFilterProxyModel>
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

		void on_txtSearch_textChanged(const QString &arg1);

		void on_actionOpen_triggered();

		void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;
		LandingWindow *landingWindow;
		void showLandingWindow();
    void loadEntries();
    void saveEntries();
		void sortEntries();
		void backupFile(const QString &filePath);
		void addEntryToListWidget(const Entry &entry) const;
		void addCurrentEntriesToListWidget() const;
		void applySearchFilter(const QString &filterText);
    QString currentFile;
    QVector<Entry> entries;
		QVector<Entry> filteredEntries;

};
#endif // MAINWINDOW_H
