#ifndef ENTRY_H
#define ENTRY_H

#include <QString>
#include <QStringList>
#include <QJsonObject>

class Entry
{
public:
    Entry();

    QString word;
    QString translation;
    QString partOfSpeech;
    QString notes;
    QStringList examples;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
		bool matchesSearch(const QString &search) const;
		QString getListViewDisplay() const;
		QString getFormattedPartOfSpeech() const;

		bool operator<(const Entry& other) const {
			return word < other.word;
		}
};

#endif // ENTRY_H
