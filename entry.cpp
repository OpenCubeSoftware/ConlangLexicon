#include "entry.h"
#include <QJsonArray>

Entry::Entry() {}

void Entry::read(const QJsonObject &json)
{
    word = json["word"].toString();
    translation = json["translation"].toString();
    partOfSpeech = json["partOfSpeech"].toString();
    notes = json["notes"].toString();

    QJsonArray examplesArray = json["examples"].toArray();
    examples.clear();
    for (const auto &exampleValue : examplesArray) {
        examples.append(exampleValue.toString());
    }

}

void Entry::write(QJsonObject &json) const
{
    json["word"] = word;
    json["translation"] = translation;
    json["partOfSpeech"] = partOfSpeech;
    json["notes"] = notes;

    QJsonArray examplesArray;
    for (const auto &example : examples) {
        examplesArray.append(example);
    }
    json["examples"] = examplesArray;
}
