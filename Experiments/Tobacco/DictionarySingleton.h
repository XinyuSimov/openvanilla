#ifndef DICTIONARYSINGLETON_H
#define DICTIONARYSINGLETON_H

#include <string>
#include <vector>

#ifndef WIN32
	#include <OpenVanilla/OVUtility.h>
#else
	#include "OVUtility.h"
#endif

#include "OVSQLite3.h"

#include "Vocabulary.h"

using namespace std;

class DictionarySingleton
{
public:
	static DictionarySingleton* getInstance(
	   const char* dbFilePath)
	{
		if(itsInstance == NULL)
			itsInstance = new DictionarySingleton(dbFilePath);

		return itsInstance;
	}

	static void lostInstance();

	void setInputMethodId(string id) { inputMethodId = id; }
    bool isVocabulary(string characters);
	bool getVocabulariesByKeystrokes(
		string keystrokes, vector<Vocabulary>& vocabularyVectorRef);

protected:
	DictionarySingleton(const char* dbFilePath);
	~DictionarySingleton();
	
private:
	static DictionarySingleton* itsInstance;
    static SQLite3 *dictionaryDB;
    string inputMethodId;
};

#endif