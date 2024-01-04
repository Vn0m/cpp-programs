#include <iostream>
#include <string>

struct Movies {
    std::string title;
    int year;
    std::string genre;
    int duration;
    std::string rating;
};

// Maximum amount of movies user can enter
const int MAX_MOVIES = 50;

void addMovie(Movies movie[MAX_MOVIES], int& movieCount);
void showMovies(Movies movie[MAX_MOVIES], int movieCount);
void sortMovies(Movies movies[MAX_MOVIES], int movieCount);
void searchMovie(Movies movie[MAX_MOVIES], int movieCount);

int main() {
    int option;
    int movieCount = 0;

    Movies movie[MAX_MOVIES];

    do {
        std::cout << "\t MENU \n";
        std::cout << "1. Add movie\n";
        std::cout << "2. Show movies\n";
        std::cout << "3. Sort movies\n";
        std::cout << "4. Search movie by genre\n";
        std::cout << "5. Exit\n";
        std::cin >> option;

        switch (option) {
            case 1:
                addMovie(movie, movieCount);
                break;
            case 2:
                showMovies(movie, movieCount);
                break;
            case 3:
                sortMovies(movie, movieCount);
                break;
            case 4:
                searchMovie(movie, movieCount);
                break;
            case 5:
                std::cout << "Thank you for using!\n";
                break;
        }

    } while (option != 5);
}

// Add a movie one by one keeping track of a counter
void addMovie(Movies movie[MAX_MOVIES], int &movieCount) {
    if (movieCount < MAX_MOVIES) {
        std::cin.ignore();
        std::cout << "Enter the movie title:\n";
        std::getline(std::cin, movie[movieCount].title);
        std::cout << "Enter the release year of the movie:\n";
        std::cin >> movie[movieCount].year;
        std::cin.ignore();
        std::cout << "Enter the genre of the movie:\n";
        std::getline(std::cin, movie[movieCount].genre);
        std::cout << "Enter the duration in minutes:\n";
        std::cin >> movie[movieCount].duration;
        std::cin.ignore();
        std::string rating;
        do {
            std::cout << "Enter the rating of the movie (G, PG, PG-13, R, and NC-17):\n";
            std::getline(std::cin, rating);
        } while (rating != "G" && rating != "PG" && rating != "PG-13" && rating != "R" && rating != "NC-17");

        movie[movieCount].rating = rating;

        movieCount++;
    } else {
        std::cout << "The maximum number of movies has been entered.\n";
    }
}

// iterate over to display the info of each movie
void showMovies(Movies movie[MAX_MOVIES], int movieCount) {
    for (int i = 0; i < movieCount; i++) {
        std::cout << "Movie # " << i + 1 << '\n';
        std::cout << "Title: " << movie[i].title << '\n';
        std::cout << "Release year: " << movie[i].year << '\n';
        std::cout << "Genre: " << movie[i].genre << '\n';
        std::cout << "Duration: " << movie[i].duration << '\n';
        std::cout << "Rating: " << movie[i].rating << '\n';
        std::cout << '\n';
    }
}

// using bubble sort order the movies from top to bottom and display the title and year
void sortMovies(Movies movies[MAX_MOVIES], int movieCount) {
    for (int i = 0; i < movieCount - 1; i++) {
        for (int j = 0; j < movieCount - i - 1; j++) {
            if (movies[j].year > movies[j + 1].year) {
                Movies temp = movies[j];
                movies[j] = movies[j + 1];
                movies[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < movieCount; i++) {
        std::cout << "Movie: " << movies[i].title << '\n';
        std::cout << "Release year: " << movies[i].year << '\n';
        std::cout << '\n';
    }
}

// display all the genres avaible and then search for the one the user wants displaying the genre and the title of the movie
void searchMovie(Movies movie[MAX_MOVIES], int movieCount) {
    std::cin.ignore();
    std::string genreToSearch;
    std::cout << "Available genres: \n";
    for (int i = 0; i < movieCount; i++) {
        std::cout << "- " << movie[i].genre << '\n';
    }
    std::cout << "Which genre do you want to search for: " << '\n';
    getline(std::cin, genreToSearch);
    for(int i = 0; i < movieCount; i++) {
        if(genreToSearch == movie[i].genre) {
            std::cout << "Movies with genre: " << movie[i].genre << "!\n";
            std::cout << "Title: " << movie[i].title << '\n';        
            break;
        }
    }
}
