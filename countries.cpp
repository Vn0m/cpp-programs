#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

struct Destination {
    std::string location; // Location
    std::string description; // Description
    std::string activities; // Activities
    double estimatedCost; // Estimated cost
    int id;
};

const int MAX_DESTINATIONS = 10000;

void addRandomDestination(Destination destinations[], int& destinationCount) {
    std::string locations[] = {"Paris", "Tokyo", "New York", "London", "Rome", "Sydney", "Dubai", "Rio de Janeiro", "Cape Town", "Bali"};
    std::string descriptions[] = {"Historical city with iconic monuments", "Vibrant metropolis with cutting-edge technology", "Cultural melting pot with diverse attractions", "Global financial center with a rich history", "Eternal city with ancient ruins and art", "Cosmopolitan city with stunning beaches", "Modern city with luxury shopping and skyscrapers", "Breathtaking coastal city with lively atmosphere", "Picturesque city with wildlife and natural beauty", "Tropical paradise with lush landscapes"};
    std::string activities[] = {"Visiting landmarks", "Shopping", "Cuisine tasting", "Adventure sports", "Beach relaxation", "Cultural experiences", "Wildlife safari", "Hiking", "Nightlife", "Photography"};

    srand(time(0)); 

    for (int i = 0; i < 10000; ++i) {
        Destination newDestination;
        newDestination.location = locations[rand() % 10]; 
        newDestination.description = descriptions[rand() % 10]; 
        newDestination.activities = activities[rand() % 10]; 
        newDestination.estimatedCost = static_cast<double>(rand() % 1000); 
        newDestination.id = destinationCount++;
        destinations[newDestination.id] = newDestination;
    }

    std::cout << "10,000 destinations added successfully.\n";
}

void busquedaLineal(Destination destinations[], int destinationCount, int& contadorComparaciones){
    int id;
    bool found = false;
    std::cout << "Enter the destination id to search for: ";
    std::cin >> id;
    if(id >= 0 && id < destinationCount){
        for(int i = 0; i < destinationCount; i++){
            if(destinations[i].id == id){
                std::cout << "Location: " << destinations[i].location << "\n";
                std::cout << "Description: " << destinations[i].description << "\n";
                std::cout << "Activities: " << destinations[i].activities << "\n";
                std::cout << "Estimated cost: $" << destinations[i].estimatedCost << "\n";
                found = true;
            } 
            contadorComparaciones++;
        }   
        if(!found){
            std::cout << "No destinations with that id.\n";
        }
    } else{
        std::cout << "Invalid id....\n";
    }
}

int busquedaBinaria(Destination destinations[], int id, int low, int high, int& contadorComparaciones){
    if (low <= high) {
        int mid = (high + low) / 2; 
        contadorComparaciones++;

        if (destinations[mid].id == id) {
            return mid; 
        } else if (destinations[mid].id > id) {
            return busquedaBinaria(destinations, id, low, mid - 1, contadorComparaciones); 
        } else {
            return busquedaBinaria(destinations, id, mid + 1, high, contadorComparaciones); 
        }
    }
    return -1;
}

void bubbleSortEstimatedCost(Destination destinations[], int destinationCount, int &contadorComparaciones){
    for(int i = 0; i < destinationCount - 1; i++){
        for(int j = 0; j < destinationCount - i - 1;j++){
            contadorComparaciones++; // Increase the comparison counter
            if (destinations[j].estimatedCost > destinations[j + 1].estimatedCost){
                Destination temp = destinations[j];
                destinations[j] = destinations[j + 1];
                destinations[j + 1] = temp;
            }
        }
    }
}

void bubbleSortId(Destination destinations[], int destinationCount, int &contadorComparaciones){
    for(int i = 0; i < destinationCount - 1; i++){
        for(int j = 0; j < destinationCount - i - 1;j++){
            contadorComparaciones++; 
            if (destinations[j].id > destinations[j + 1].id){
                Destination temp = destinations[j];
                destinations[j] = destinations[j + 1];
                destinations[j + 1] = temp;
            }
        }
    }
}

int partitionId(Destination destinations[], int left, int pivot, int& contadorComparaciones) {
    int low = left - 1;
    int high = pivot - 1;

    for (int j = left; j <= high; j++) {
        contadorComparaciones++; 
        if (destinations[j].id <= destinations[pivot].id) {
            low++;
            std::swap(destinations[low], destinations[j]);
        }
    }
    std::swap(destinations[low + 1].id, destinations[pivot].id);

    return low + 1;
}

int partitionEstimatedCost(Destination destinations[], int left, int pivot, int& contadorComparaciones) {
    int low = left - 1;
    int high = pivot - 1;

    for (int j = left; j <= high; j++) {
        contadorComparaciones++; 
        if (destinations[j].estimatedCost <= destinations[pivot].estimatedCost) {
            low++;
            std::swap(destinations[low], destinations[j]);
        }
    }
    std::swap(destinations[low + 1].id, destinations[pivot].id);

    return low + 1;
}

void quickSortId(Destination destinations[], int left, int pivot, int& contadorComparaciones) {
    if (left < pivot) {
        int newPivot = partitionId(destinations, left, pivot, contadorComparaciones);

        quickSortId(destinations, left, newPivot - 1, contadorComparaciones);
        quickSortId(destinations, newPivot + 1, pivot, contadorComparaciones);
    }
}

void quickSortEstimatedCost(Destination destinations[], int left, int pivot, int& contadorComparaciones) {
    if (left < pivot) {
        int newPivot = partitionEstimatedCost(destinations, left, pivot, contadorComparaciones);

        quickSortEstimatedCost(destinations, left, newPivot - 1, contadorComparaciones);
        quickSortEstimatedCost(destinations, newPivot + 1, pivot, contadorComparaciones);
    }
}

void addDestination(Destination destinations[], int& destinationCount) {
    if (destinationCount < MAX_DESTINATIONS) {
        std::cin.ignore(); 
        Destination newDestination;

        do {
            std::cout << "Location: ";
            std::getline(std::cin, newDestination.location);
            if (newDestination.location.empty()) {
                std::cout << "Location cannot be empty.\n";
            }
        } while (newDestination.location.empty());

        do {
            std::cout << "Description: ";
            std::getline(std::cin, newDestination.description);
            if (newDestination.description.empty()) {
                std::cout << "Description cannot be empty.\n";
            }
        } while (newDestination.description.empty());

        do {
            std::cout << "Activities: ";
            std::getline(std::cin, newDestination.activities);
            if (newDestination.activities.empty()) {
                std::cout << "Activities cannot be empty.\n";
            }
        } while (newDestination.activities.empty());

        double cost;
        do {
            std::cout << "Estimated cost: $";
            std::cin >> cost;
            if (cost < 0) {
                std::cout << "Estimated cost cannot be negative.\n";
            }
        } while (cost < 0);
        newDestination.estimatedCost = cost;

        newDestination.id = destinationCount++;
        destinations[newDestination.id] = newDestination;

        std::cout << "Destination added successfully.\n";
    } else {
        std::cout << "Maximum number of destinations reached.\n";
    }
}


void modifyById(Destination destinations[], int destinationCount) {
    int id;
    std::cout << "Enter the ID of the destination you want to modify: ";
    std::cin >> id;

    if (id >= 0 && id < destinationCount) {
        Destination& destination = destinations[id];
        std::cin.ignore(); 

        do {
            std::cout << "Location (previous: " << destination.location << "): ";
            std::getline(std::cin, destination.location);
            if (destination.location.empty()) {
                std::cout << "Location cannot be empty.\n";
            }
        } while (destination.location.empty());

        do {
            std::cout << "Description (previous: " << destination.description << "): ";
            std::getline(std::cin, destination.description);
            if (destination.description.empty()) {
                std::cout << "Description cannot be empty.\n";
            }
        } while (destination.description.empty());

        do {
            std::cout << "Activities (previous: " << destination.activities << "): ";
            std::getline(std::cin, destination.activities);
            if (destination.activities.empty()) {
                std::cout << "Activities cannot be empty.\n";
            }
        } while (destination.activities.empty());

        double cost;
        do {
            std::cout << "Estimated cost (previous: $" << destination.estimatedCost << "): $";
            std::cin >> cost;
            if (cost < 0) {
                std::cout << "Estimated cost cannot be negative.\n";
            }
        } while (cost < 0);
        destination.estimatedCost = cost;

        std::cout << "Destination modified successfully.\n";
    } else {
        std::cout << "Invalid destination ID.\n";
    }
}

void deleteById(Destination destinations[], int& destinationCount) {
    int id;
    std::cout << "Enter the ID of the destination you want to delete: ";
    std::cin >> id;

    if (id >= 0 && id < destinationCount) {
        for (int i = id; i < destinationCount - 1; ++i) {
            destinations[i] = destinations[i + 1];
            destinations[i].id = i;
        }
        --destinationCount;
        std::cout << "Destination deleted successfully.\n";
    } else {
        std::cout << "Invalid destination ID.\n";
    }
}

void showDestinations(Destination destinations[], int destinationCount){
    if(destinationCount == 0){
        std::cout << "No destinations available....\n";
    } else {
        std::cout << "\n\tTravel Destinations\n";
        for(int i = 0; i < destinationCount; ++i){
            std::cout << "ID: " << destinations[i].id << "\n";
            std::cout << "Location: " << destinations[i].location << "\n";
            std::cout << "Description: " << destinations[i].description << "\n";
            std::cout << "Activities: " << destinations[i].activities << "\n";
            std::cout << "Estimated cost: $" << destinations[i].estimatedCost << "\n";
        }
    }
}

int main() {
    Destination destinations[MAX_DESTINATIONS];
    int destinationCount = 0;

    char choice;
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;

    do {
        std::cout << "\t Menu \n"
                  << "1. Add travel destination\n"
                  << "2. Modify travel destination\n"
                  << "3. Delete travel destination\n"
                  << "4. Show travel destinations\n"
                  << "5. Add random destinations\n"
                  << "6. Search\n"
                  << "7. Report\n"
                  << "8. Exit\n"
                  << "Choose your option: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addDestination(destinations, destinationCount);
                break;
            case '2':
                modifyById(destinations, destinationCount);
                break;
            case '3':
                deleteById(destinations, destinationCount);
                break;
            case '4':
                showDestinations(destinations, destinationCount);
                break;
            case '5':
                addRandomDestination(destinations, destinationCount);
                break;
            case '6':
    char choiceConsulta;
    int contadorComparaciones;
    do {
        std::cout << "Choose how you want to search: \n";
        std::cout << "1. Linear search\n";
        std::cout << "2. Binary search\n";
        std::cout << "3. Back to the main menu\n";
        std::cin >> choiceConsulta;
        contadorComparaciones = 0; // Reset the comparison counter for each iteration
        switch(choiceConsulta){
            case '1': {
                start = std::chrono::system_clock::now();
                busquedaLineal(destinations, destinationCount, contadorComparaciones);
                end = std::chrono::system_clock::now();
                std::chrono::duration<float,std::milli> durationLinearSearch = end - start;
                std::cout << "Comparisons made: " << contadorComparaciones << '\n';
                std::cout << "Processing time: " << durationLinearSearch.count() << '\n';
                break;
            }
            case '2': {
                int id;
                std::cout << "Enter the id of the destination to search for: ";
                std::cin >> id;
                if(id >= 0 && id < destinationCount){
                    start = std::chrono::system_clock::now();
                    int result = busquedaBinaria(destinations, id, 0, destinationCount - 1, contadorComparaciones);
                    end = std::chrono::system_clock::now();
                    std::chrono::duration<float,std::milli> durationBinarySearch = end - start;
                    if (result != -1) {
                        std::cout << "Location: " << destinations[result].location << "\n";
                        std::cout << "Description: " << destinations[result].description << "\n";
                        std::cout << "Activities: " << destinations[result].activities << "\n";
                        std::cout << "Estimated cost: $" << destinations[result].estimatedCost << "\n";
                        std::cout << "Comparisons made: " << contadorComparaciones << '\n';
                        std::cout << "Processing time: " << durationBinarySearch.count() << '\n';
                    } else {
                        std::cout << "No destinations with that id.\n";
                    }
                } else{
                    std::cout << "Invalid id....\n";
                }
                break;
            }
            case '3':
                break;       
            default: 
                std::cout << "Invalid option!\n";            
        }
    } while(choiceConsulta != '3');  
    break;
            case '7':
            char choiceReporte;
                do {
                    std::cout << "\t Report Menu\n";
                    std::cout << "For the report, do you want to sort by:\n"
                    << "1. Bubble Sort\n"
                    << "2. Quicksort\n"
                    << "3. Back to the main menu\n"
                    << "What do you want to do? (1-3): ";
                    std::cin >> choiceReporte;
                    switch(choiceReporte){
                        case '1': {
                            char choiceBubble;
                            do {
                                std::cout << "\t Bubble Sort Menu\n";
                                std::cout << "1. Sort by ID\n"
                                << "2. Sort by estimated cost\n"
                                << "3. Back to the report menu\n";
                                std::cin >> choiceBubble;
                                switch(choiceBubble){
                                    case '1': {
                                        contadorComparaciones = 0;
                                        start = std::chrono::system_clock::now();
                                        bubbleSortId(destinations, destinationCount, contadorComparaciones);
                                        end = std::chrono::system_clock::now();
                                        showDestinations(destinations, destinationCount);

                                        std::chrono::duration<float,std::milli> durationBubbleId = end - start;
                                        std::cout << "Number of comparisons: " << contadorComparaciones << '\n';
                                        std::cout << "Processing time: " << durationBubbleId.count() << '\n';
                                        break;
                                    }
                                    case '2': {
                                        contadorComparaciones = 0;
                                        start = std::chrono::system_clock::now();
                                        bubbleSortEstimatedCost(destinations, destinationCount, contadorComparaciones);
                                        end = std::chrono::system_clock::now();
                                        showDestinations(destinations, destinationCount);
                                        
                                        std::chrono::duration<float,std::milli> durationBubbleCost = end - start;
                                        std::cout << "Number of comparisons: " << contadorComparaciones << '\n';
                                        std::cout << "Processing time: " << durationBubbleCost.count() << '\n';
                                        break;
                                    }
                                    case '3':
                                        std::cout << "Returning to the report menu\n";
                                        break;
                                    default:
                                        std::cout << "Enter a valid option! (1-3)\n";
                                }
                            } while (choiceBubble != '3');
                            break;
                        }
                        case '2': {
                            char choiceQuick;
                            int contadorComparaciones;
                            do {
                                std::cout << "\t Quicksort Menu\n";
                                std::cout << "1. Sort by ID\n"
                                << "2. Sort by estimated cost\n"
                                << "3. Back to the report menu\n";
                                std::cin >> choiceQuick;
                                switch(choiceQuick){
                                    case '1': {
                                        contadorComparaciones = 0;
                                        start = std::chrono::system_clock::now();
                                        quickSortId(destinations, 0, destinationCount - 1, contadorComparaciones);
                                        end = std::chrono::system_clock::now();
                                        showDestinations(destinations, destinationCount);

                                        std::chrono::duration<float,std::milli> durationQuickId = end - start;
                                        std::cout << "Number of comparisons: " << contadorComparaciones << '\n';
                                        std::cout << "Processing time: " << durationQuickId.count() << '\n';
                                        break;
                                    }
                                    case '2': {
                                        contadorComparaciones = 0;
                                        start = std::chrono::system_clock::now();
                                        quickSortEstimatedCost(destinations, 0, destinationCount - 1, contadorComparaciones);
                                        end = std::chrono::system_clock::now();
                                        showDestinations(destinations, destinationCount);

                                        std::chrono::duration<float,std::milli> durationQuickCost = end - start;
                                        std::cout << "Number of comparisons: " << contadorComparaciones << '\n';
                                        std::cout << "Processing time: " << durationQuickCost.count() << '\n';
                                        break;
                                    }
                                    case '3':
                                        std::cout << "Returning to the report menu\n";
                                        break;
                                    default:
                                        std::cout << "Enter a valid option! (1-3)\n";
                                }
                            } while (choiceQuick != '3');
                            break;
                        }
                        case '3':
                            std::cout << "Returning to the main menu\n";
                            break;
                        default:
                            std::cout << "Enter a valid option (1-3)\n";
                    }
                    
                } while(choiceReporte != '3');
                
                break;
            case '8':
                std::cout << "Thank you for using! \n";
                break;
            default:
                std::cout << "Invalid option! \n";
        }
    } while (choice != '8');

    return 0;
}
