#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


/*

Questionaire -
This Daily Code was quickly thrown together since I started
late and lost track of what I really wanted to do

Will redo this some other time to make it work well,
but I stayed to my objective and didn't use any tutorials on anything

*/

class Player {
private:
    std::string username;
    int playerNum;
    int questionsTaken = 0;
    int incorrectAnswers = 0;
    int correctAnswers = 0;
public:
    Player(std::string _username, int _playerNum) {
        username = _username;
        playerNum = _playerNum;
    }
    
    std::string GetName() { return username;}
    int GetCorrectAnswers() { return correctAnswers; }
    int GetIncorrectAnswers() { return incorrectAnswers; }
    int GetAttemptedQuestions() { return questionsTaken; }

    void AddPoint(int pointAmount) { correctAnswers += pointAmount; }
    void RemovePoint(int pointAmount) { incorrectAnswers += pointAmount; }
    void QuestionAttempted() { questionsTaken++; }

};

class PlayerInstantiation {
public:
    Player *create(std::string name, int num) { return new Player(name, num); }
    
};




int main() {
  PlayerInstantiation pFactory;
  std::vector<Player*> players;


  int pCount;
  std::cout << "How many players are there?\n";
  std::cin >> pCount;

  //Player Instantiation Loop
  for (int i = 0; i < pCount; i++) {
      std::string tempName;
      std::cout << "What is P" << i + 1 << "'s name going to be?\n";
      std::cin >> tempName;
      try { players.push_back(pFactory.create(tempName, i)); }
      catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
  }

  //Validating Player Creation
  for (int i = 0; i < players.size(); i++)
  {
      std::cout << "Player " << i + 1 << ": " << players.at(i)->GetName() << std::endl;
  }

  std::cout << "Welcome to Questionaire (very original name)\n";

  std::cout << std::endl;

  // SECOND QUESTION SECTION

  std::cout << "First Question: ";
  std::cout << "What name is given to the revolving belt machinery in an airport that delivers checked luggage from the plane to baggage reclaim?\n";

  std::cout << "A: Hangar\n";
  std::cout << "B: Terminal\n";
  std::cout << "C: Concourse\n";
  std::cout << "D: Carousel\n";

  std::cout << std::endl;

  int pIndex;
  std::cout << "Who's answering? (Enter Player Number)\n";
  std::cin >> pIndex;
  std::cout << "Alright, " << players.at(pIndex - 1)->GetName() << ". You're up!\n";
  players.at(pIndex - 1)->QuestionAttempted();

  std::cout << std::endl;

  char inp;
  std::cout << "Enter Answer (A, B, C, D): ";
  std::cin >> inp;

  switch (inp) {
    case 'A':std::cout << "\nWrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'B':std::cout << "\nWrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'C':std::cout << "\nWrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'D':std::cout << "\nCorrect!\n"; players.at(pIndex - 1)->AddPoint(1); break;
  }




  // SECOND QUESTION SECTION

  std::cout << "Second Question: ";
  std::cout << "What does the word loquacious mean?\n";

  std::cout << "A: Angry\n";
  std::cout << "B: Chatty\n";
  std::cout << "C: Beautiful\n";
  std::cout << "D: Shy\n";

  std::cout << std::endl;

  std::cout << "Who's answering? (Enter Player Number)\n";
  std::cin >> pIndex;
  std::cout << "Alright, " << players.at(pIndex - 1)->GetName() << ". You're up!\n";
  players.at(pIndex - 1)->QuestionAttempted();


  std::cout << std::endl;

  std::cout << "Enter Answer (A, B, C, D): ";
  std::cin >> inp;

  switch (inp) {
    case 'A':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'B':std::cout << "Correct!\n"; players.at(pIndex - 1)->AddPoint(1); break;
    case 'C':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'D':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
  }



  // THIRD QUESTION SECTION

  std::cout << "Third Question: ";
  std::cout << "The hammer and sickle is one of the most recognisable symbols of which political ideology?\n";

  std::cout << "A: Republicanism\n";
  std::cout << "B: Communism\n";
  std::cout << "C: Conservatism\n";
  std::cout << "D: Liberalism\n";

  std::cout << std::endl;

  std::cout << "Who's answering? (Enter Player Number)\n";
  std::cin >> pIndex;
  std::cout << "Alright, " << players.at(pIndex - 1)->GetName() << ". You're up!\n";
  players.at(pIndex - 1)->QuestionAttempted();


  std::cout << std::endl;

  std::cout << "Enter Answer (A, B, C, D): ";
  std::cin >> inp;

  switch (inp) {
    case 'A':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'B':std::cout << "Correct!\n"; players.at(pIndex - 1)->AddPoint(1); break;
    case 'C':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'D':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
  }


  // FOURTH QUESTION SECTION

  std::cout << "Fourth Question: ";
  std::cout << "The Earth is approximately how many miles away from the Sun?\n";

  std::cout << "A: 9.3 million\n";
  std::cout << "B: 39 million\n";
  std::cout << "C: 93 million\n";
  std::cout << "D: 193 million\n";

  std::cout << std::endl;

  std::cout << "Who's answering? (Enter Player Number)\n";
  std::cin >> pIndex;
  std::cout << "Alright, " << players.at(pIndex - 1)->GetName() << ". You're up!\n";
  players.at(pIndex - 1)->QuestionAttempted();


  std::cout << std::endl;

  std::cout << "Enter Answer (A, B, C, D): ";
  std::cin >> inp;

  switch (inp) {
    case 'A':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'B':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'C':std::cout << "Correct!\n"; players.at(pIndex - 1)->AddPoint(1); break;
    case 'D':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
  }


      // FIFTH QUESTION SECTION

  std::cout << "Fifth Question: ";
  std::cout << "Which insect shorted out an early supercomputer and inspired the term 'computer bug'?\n";

  std::cout << "A: Roach\n";
  std::cout << "B: Fly\n";
  std::cout << "C: Japanese beetle\n";
  std::cout << "D: Moth\n";

  std::cout << std::endl;

  std::cout << "Who's answering? (Enter Player Number)\n";
  std::cin >> pIndex;
  std::cout << "Alright, " << players.at(pIndex - 1)->GetName() << ". You're up!\n";
  players.at(pIndex - 1)->QuestionAttempted();


  std::cout << std::endl;

  std::cout << "Enter Answer (A, B, C, D): ";
  std::cin >> inp;

  switch (inp) {
    case 'A':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'B':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'C':std::cout << "Wrong!\n"; players.at(pIndex - 1)->RemovePoint(1); break;
    case 'D':std::cout << "Correct!\n"; players.at(pIndex - 1)->AddPoint(1); break;
  }


  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  for (int i = 0; i < players.size(); i++)
  {
    std::cout << "Player " << i + 1 << " (" << players.at(i)->GetName() << "): Attempted - " << players.at(i)->GetAttemptedQuestions() << " Correct - " << players.at(i)->GetCorrectAnswers() << " Incorrect - " << players.at(i)->GetIncorrectAnswers() << std::endl;
  }

  //Program for some reason exits immediately and doesn't run below this?????????????????????
  //Needs to be ran in replit to see score finals
  std::getchar();
    
}