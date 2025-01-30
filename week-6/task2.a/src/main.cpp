#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore(); 

    std::map<std::string, std::set<std::string>> latinToEnglish;

    for (int i = 0; i < N; ++i) {
        std::string line;
        std::getline(std::cin, line);

        
        std::istringstream iss(line);
        std::string englishWord;
        std::getline(iss, englishWord, '-');

      
        std::string translations;
        std::getline(iss, translations);

        
        translations.erase(0, translations.find_first_not_of(" "));
        translations.erase(translations.find_last_not_of(" ") + 1);

       
        std::istringstream transStream(translations);
        std::string latinWord;
        while (std::getline(transStream, latinWord, ',')) {
            latinWord.erase(0, latinWord.find_first_not_of(" ")); 
            latinToEnglish[latinWord].insert(englishWord); 
        }
    }

    
    for (const auto& pair : latinToEnglish) {
        std::cout << pair.first << " - "; 
        const auto& englishWords = pair.second;
        for (auto it = englishWords.begin(); it != englishWords.end(); ++it) {
            std::cout << *it;
            if (std::next(it) != englishWords.end()) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}