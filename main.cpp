#include <iostream>
#include<set>
#include<map>
using namespace std;

class Synonym {
public:
    void addSynonyms(set<string> synonyms){
        if(pairsSynonym.count(synonyms) == 0){
            pairsSynonym.insert(synonyms);
            for(const auto& synonym : synonyms){
                numberSynonyms[synonym]++;
            }
        }
    }

    int getCountSynonym(string word){
        /*int counter = 0;

        for(const auto& synonims : pairsSynonym){
            if(synonims.count(word) > 0){
                counter++;
            }
        }*/
        return numberSynonyms[word];
    }

    bool isSynonyms(set<string> words){
        return pairsSynonym.count(words) > 0;
    }

private:
    set<set<string>> pairsSynonym;
    map<string, int> numberSynonyms;
};

int main()
{
    Synonym synonym;
    int numberOperation;
    cin >> numberOperation;
    for(int i(0); i < numberOperation; i++){
        string nameOperation;
        cin >> nameOperation;
        if(nameOperation == "ADD"){
            set<string>  synonyms;
            string firstWord, secondWord;
            cin >> firstWord >> secondWord;
            synonyms.insert(firstWord);
            synonyms.insert(secondWord);
            synonym.addSynonyms(synonyms);
        }

        if(nameOperation == "COUNT"){
            string word;
            cin >> word;
            cout << synonym.getCountSynonym(word) <<endl;
        }

        if(nameOperation == "CHECK"){
            set<string>  synonyms;
            string firstWord, secondWord;
            cin >> firstWord >> secondWord;
            synonyms.insert(firstWord);
            synonyms.insert(secondWord);
            if(synonym.isSynonyms(synonyms)){
                cout << "YES" <<endl;
            }else{
                cout << "NO" <<endl;
            }

        }

    }


    return 0;
}
