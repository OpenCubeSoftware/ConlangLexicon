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
};

#endif // ENTRY_H
