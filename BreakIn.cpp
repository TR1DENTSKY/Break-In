#include <iostream> 
#include <ctime>

void PrintIntroduction(int Difficulty) {

    std::cout << "\n\nYou are a hacker trying to break into a level " << Difficulty;
    std::cout << " server.\nEnter the correct code to continue...\n";
}


bool PlayGame(int Difficulty) {

    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;  
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;  
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\nYou got through!";
        return true;
    } else {
        std::cout << "\nWrong code, try again. Hurry!";
    } return false;
}

int main() {

    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) { // Loop game until all levels completed
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); 
        std::cin.ignore();

        if (bLevelComplete) {

            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\n*** Great work! You were able to break in. Now get what you need and get out of there! ***\n";

    return 0;
}