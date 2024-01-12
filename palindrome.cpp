#include <iostream>

std::string palindromo(std::string word);

int main(){
    std::string word;
    do{
        std::cout << "Enter word: ";
        std::cin >> word;
    } while(word.length() > 20);

    // compares inverted string to input
    if(palindromo(word) == word){
        std::cout << "It's a palindrome";
    }  else{
        std::cout << "It's not a palindrome";
    } 
}

// iterates the string and stores it in inverted
std::string palindromo(std::string word){
    std::string inverted;
    for(int i = word.length() - 1; i >= 0; i--){
        inverted += word[i];
    }
    return inverted;
}