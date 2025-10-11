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

bool Entry::matchesSearch(const QString &search) const
{
	bool wordMatches = word.contains(search, Qt::CaseInsensitive);
	bool translationMatches = translation.contains(search, Qt::CaseInsensitive);
	bool noteMatches = notes.contains(search, Qt::CaseInsensitive);

	return wordMatches || translationMatches || noteMatches;
}

QString Entry::getListViewDisplay() const
{
	return word + getFormattedPartOfSpeech() + " - " + translation;
}

//todo: replace with list and dropdown
QString Entry::getFormattedPartOfSpeech() const
{
	QString lowercasePartOfSpeech = partOfSpeech.toLower();
		if (lowercasePartOfSpeech == "noun")
			return " (n.) ";
		else if (lowercasePartOfSpeech == "n")
			return " (n.) ";
		else if (lowercasePartOfSpeech == "n.")
			return " (n.) ";
		else if (lowercasePartOfSpeech == "verb")
			return " (v.) ";
		else if (lowercasePartOfSpeech == "v")
			return " (v.) ";
		else if (lowercasePartOfSpeech == "v.")
			return " (v.) ";
		else if (lowercasePartOfSpeech == "noun, verb")
			return " (n., v.) ";
		else if (lowercasePartOfSpeech == "verb, noun")
			return " (v., n.) ";
		else if (lowercasePartOfSpeech == "adverb")
			return " (adv.) ";
		else if (lowercasePartOfSpeech == "adv")
			return " (adv.) ";
		else if (lowercasePartOfSpeech == "adv.")
			return " (adv.) ";
		else if (lowercasePartOfSpeech == "adjective")
			return " (adj.) ";
		else if (lowercasePartOfSpeech == "adj")
			return " (adj.) ";
		else if (lowercasePartOfSpeech == "adj.")
			return " (adj.) ";
		else if (lowercasePartOfSpeech == "preposition")
			return " (prep.) ";
		else if (lowercasePartOfSpeech == "prep")
			return " (prep.) ";
		else if (lowercasePartOfSpeech == "prep.")
			return " (prep.) ";
		else if (lowercasePartOfSpeech == "pronoun")
			return " (pron.) ";
		else if (lowercasePartOfSpeech == "pron")
			return " (pron.) ";
		else if (lowercasePartOfSpeech == "pron.")
			return " (pron.) ";
		else
			return "";
}

