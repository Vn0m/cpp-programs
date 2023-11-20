#include <iostream>

int main(){

    // array of questions one dimension
    std::string questions[] = {"1. What year did the strokes release their first album?: ",
                               "2. Whos arctic monkeys lead singer?: ",
                               "3. Whats the name of the lastest Strokes album?: ",
                               "4. In what album does Otherside by RHCP appear?: " };

    // array of options for each question which is a 2d array
    std::string options[][4] = {{"A. 2002", "B. 2001", "C. 1998", "D. 2005"},
                                {"A. Dominick Fike", "B. Julian Casablancas", "C. Axel Rose", "D. Alex Turner"},
                                {"A. The new strokes", "B. The new abnormal", "C. Angles", "D. The new way"},
                                {"A. Californication", "B. Im with you", "C. Stadium Arcadium", "D. BSSM"}};

    // array of answers for each question one dimension
    char answerKey[] = {'B', 'D', 'B', 'A'};

    // variable for size of questions array 4 elements /1st element = 4
    int size = sizeof(questions) / sizeof(questions[0]);
    // variable for our guess
    char guess;
    // initialize score to 0
    int score = 0;

    // loop that iterates over questions array and displays the current question
    for(int i = 0; i < size; i++){
        std::cout << "*********************" << '\n';
        std::cout << questions[i] << '\n';
        std::cout << "*********************" << '\n';

        // inner loop to display the options of each question by iterating through the index i of the question and prints the first line (i) with the colums of that first line (j) which are the options
        for(int j = 0; j < sizeof(options[i])/ sizeof(options[i][0]); j++){
            std::cout << options[i][j] << '\n';
        }

        // take user input and make it upper case to take in case user putting lower case letters
        std::cin >> guess;
        guess = toupper(guess);

        // if the guess the user put for currect question is equal to the index of the array of answerkey
        if(guess == answerKey[i]){
            std::cout << "Correct! \n";
            //increase if its correct
            score++;
        } else {
            std::cout << "Wrong! \n";
            std::cout << "Answer: " << answerKey[i] << '\n';
        }
    }
    std::cout << "*********************" << '\n';
    std::cout << "Results: \n";
    std::cout << "*********************" << '\n';
    std::cout << "Correct guesses: " << score << '\n';
    std::cout << "Number of questions: " << size << '\n';
    // porcentage of score 
    std::cout << "Score: " << (score / (double)size) * 100 << '%' << '\n';
    return 0;
}