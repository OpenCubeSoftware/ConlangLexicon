#ifndef LANDINGWINDOW_H
#define LANDINGWINDOW_H

#include <QDialog>

namespace Ui {
class LandingWindow;
}

class LandingWindow : public QDialog
{
	Q_OBJECT

public:
	explicit LandingWindow(QWidget *parent = nullptr);
	~LandingWindow();

signals:
	void createNewLexicon();
	void openExistingLexicon();

private:
	Ui::LandingWindow *ui;
};

#endif // LANDINGWINDOW_H
