#include <iostream>
#include <fstream>

// Define maximum limits for products, categories, and providers
const int MAX_PRODUCTS = 2;
const int MAX_CATEGORIES = 2;
const int MAX_PROVIDERS = 2;

// Define structures for Product, Category, and Provider
struct Product{
    int id;
    std::string name;
    int category;
    double price;
    int stock;
};

struct Category{
    int id;
    std::string name;
    std::string description;
};

struct Provider{
    int id;
    std::string personId;
    std::string name;
    std::string address;
    std::string contact;
};

// Function prototypes
void addCategory(Category arrayCategory[], int &categoryCount);
void addProvider(Provider arrayProvider[], int &providerCount);
void addProduct(Product arrayProduct[], Category arrayCategory[], int categoryCount, int &productCount);
void listProducts(Product arrayProduct[], int productCount);
void listProviders(Provider arrayProvider[], int providerCount);
void searchProduct(Product arrayProduct[], int productCount);
void productsLowStock(Product arrayProduct[], int productCount);
void productsHighStock(Product arrayProduct[], int productCount);
void productFile(Product arrayProduct[], int productCount);

int main(){
    int option;
    int productCount, categoryCount, providerCount = 0;
    Product arrayProduct[MAX_PRODUCTS];
    Category arrayCategory[MAX_CATEGORIES];
    Provider arrayProvider[MAX_PROVIDERS];

    do{
        // Display main menu options
        std::cout << "\t Menu \n";
        std::cout << "1. Add category of product \n";
        std::cout << "2. Add provider \n";
        std::cout << "3. Add product \n";
        std::cout << "4. List products \n";
        std::cout << "5. List providers \n";
        std::cout << "6. Search products \n";
        std::cout << "7. Generate report of products with lowest stock (less than 5) \n";
        std::cout << "8. Generate report of products with highest stock (more than 20) \n";
        std::cout << "9. Export products to a file \n";
        std::cout << "10. Exit \n";
        std::cin >> option;

        // Switch case to handle user input
        switch(option){
            case 1:
                addCategory(arrayCategory, categoryCount);
                break;
            case 2:
                addProvider(arrayProvider, providerCount);
                break;
            case 3:
                addProduct(arrayProduct, arrayCategory, categoryCount, productCount);
                break;
            case 4:
                listProducts(arrayProduct, productCount);
                break;
            case 5:
                listProviders(arrayProvider, providerCount);
                break;
            case 6:
                searchProduct(arrayProduct, productCount);
                break;
            case 7:
                productsLowStock(arrayProduct, productCount);
                break;
            case 8:
                productsHighStock(arrayProduct, productCount);
                break;
            case 9:
                productFile(arrayProduct, productCount);
                break;
            case 10:
                std::cout << "Thanks for using! \n";
                break;
            default:
                std::cout << "Option not valid \n";
                break;
        }

    } while(option != 10);

    return 0;
}

// Function to add a new category
void addCategory(Category arrayCategory[], int &categoryCount){
    if(categoryCount < MAX_CATEGORIES){
        std::cin.ignore();
        std::string checkNameCategory;
        std::cout << "Enter the category name: ";
        getline(std::cin, checkNameCategory);

        // Check if the category name already exists
        for(int i = 0; i < categoryCount; i++){
            if(arrayCategory[i].name == checkNameCategory){
                std::cout << "This name already exists\n";
                return;
            }
        }

        // Add new category details
        arrayCategory[categoryCount].name = checkNameCategory;
        std::cout << "Enter the category description: ";
        getline(std::cin, arrayCategory[categoryCount].description);

        arrayCategory[categoryCount].id = categoryCount;
        categoryCount++;
    } else {
        std::cout << "Maximum number of categories entered!\n";
    }
}

// Function to add a new provider
void addProvider(Provider arrayProvider[], int &providerCount){
    if(providerCount < MAX_PROVIDERS){
        std::cin.ignore();

        // Add new provider details
        do{
            std::cout << "Enter the provider's person id (10 digits): ";
            getline(std::cin, arrayProvider[providerCount].personId);  
        }while(arrayProvider[providerCount].personId.length() != 10);

        std::cout << "Enter the provider's name: ";
        getline(std::cin, arrayProvider[providerCount].name);
        std::cout << "Enter the provider's address: ";
        getline(std::cin, arrayProvider[providerCount].address);
        std::cout << "Enter the contact number: ";
        getline(std::cin, arrayProvider[providerCount].contact);

        arrayProvider[providerCount].id = providerCount;
        providerCount++;
    } else {
        std::cout << "Maximum number of providers entered! \n";
    }
}

// Function to add a new product
void addProduct(Product arrayProduct[], Category arrayCategory[], int categoryCount, int &productCount) {
    if (productCount < MAX_PRODUCTS) {
        std::string checkNameProduct;
        int idCheck;

        std::cin.ignore();
        std::cout << "Enter the product's name: ";
        getline(std::cin, checkNameProduct);

        // Check if the product name already exists
        for (int i = 0; i < productCount; i++) {
            if (arrayProduct[i].name == checkNameProduct) {
                std::cout << "This name already exists\n";
                return;
            }
        }

        // Add new product details
        arrayProduct[productCount].name = checkNameProduct;

        std::cout << "Category id: ";
        std::cin >> idCheck;

        // Check if the category id is valid
        bool categoryExists = false;
        for (int i = 0; i < categoryCount; i++) {
            if (arrayCategory[i].id == idCheck) {
                arrayProduct[productCount].category = idCheck;
                categoryExists = true;
                break;  
            }
        }
        if (!categoryExists) {
            std::cout << "There is no matching category id!\n";
            return;
        }

        std::cout << "Enter the price: ";
        std::cin >> arrayProduct[productCount].price;
        
        do{
            std::cout << "Enter the stock: ";
            std::cin >> arrayProduct[productCount].stock;
        }while(arrayProduct[productCount].stock < 0);

        arrayProduct[productCount].id = productCount;  
        productCount++;
    } else {
        std::cout << "Maximum number of products entered!\n";
    }
}

// Function to list all products
void listProducts(Product arrayProduct[], int productCount){
    std::cout << "List of products: \n";
    for(int i = 0; i < productCount ; i++){
        std::cout << "Product " << i << ": \n";
        std::cout << "Name: "<< arrayProduct[i].name << "\n";
        std::cout << "Category: " << arrayProduct[i].category << "\n";
        std::cout << "Price: " << arrayProduct[i].price << "\n";
        std::cout << "Stock: " << arrayProduct[i].stock << "\n";
    }
}

// Function to list all providers
void listProviders(Provider arrayProvider[], int providerCount){
    std::cout << "List of providers: \n";
    for(int i = 0; i < providerCount; i++){
        std::cout << "Provider " << i << ": \n";
        std::cout << "Name: "<< arrayProvider[i].name << "\n";
        std::cout << "Person id: " << arrayProvider[i].personId << "\n";
        std::cout << "Contact number: " << arrayProvider[i].contact << "\n";
        std::cout << "Address: " << arrayProvider[i].address << "\n";
    }
}   

// Function to search for a product by name or category
void searchProduct(Product arrayProduct[], int productCount){
    int optionSearch;
    std::string nameSearch;
    int idSearch;
    std::cout << "Product's name and category available to search: \n";
    for(int i = 0; i < productCount ; i++){
        std::cout << "Product " << i << ": \n";
        std::cout << "Name: "<< arrayProduct[i].name << ", ";
        std::cout << "Category: " << arrayProduct[i].category << "\n";
    }

    do {
        std::cout << "1. Search by Name \n";
        std::cout << "2. Search by Category \n";
        std::cout << "3. Exit \n";
        std::cin >> optionSearch;
        std::cin.ignore();
        switch(optionSearch){
            case 1:
                std::cout << "Type the name to search for: ";
                getline(std::cin, nameSearch);
                for(int i = 0; i < productCount; i++){
                    if(arrayProduct[i].name == nameSearch){
                        std::cout << "Product with Name " << arrayProduct[i].name << ": \n";
                        std::cout << "Category: " << arrayProduct[i].category << "\n";
                        std::cout << "Price: " << arrayProduct[i].price << "\n";
                        std::cout << "Stock: " << arrayProduct[i].stock << "\n";
                    }
                }
                break;
            case 2:
                std::cout << "Type the id to search for: ";
                std::cin >> idSearch;
                for(int i = 0; i < productCount; i++){
                    if(arrayProduct[i].category == idSearch){
                        std::cout << "Product with id " << arrayProduct[i].category << ": \n";
                        std::cout << "Name: " << arrayProduct[i].name << "\n";
                        std::cout << "Price: " << arrayProduct[i].price << "\n";
                        std::cout << "Stock: " << arrayProduct[i].stock << "\n";
                    }
                }
                break;
        }

    }while(optionSearch != 3);
}

// Function to generate a report of products with low stock (less than 5)
void productsLowStock(Product arrayProduct[], int productCount){
    std::cout << "Products with low stock (less than 5): \n";
    for(int i = 0; i < productCount ; i++){
        if(arrayProduct[i].stock < 5){
            std::cout << "Product " << i << ": \n";
            std::cout << "Name: "<< arrayProduct[i].name << "\n";
            std::cout << "Category: " << arrayProduct[i].category << "\n";
            std::cout << "Price: " << arrayProduct[i].price << "\n";
            std::cout << "Stock: " << arrayProduct[i].stock << "\n";
        }
    }
}

// Function to generate a report of products with high stock (more than 20)
void productsHighStock(Product arrayProduct[], int productCount){
    std::cout << "Products with high stock (more than 20): \n";
    for(int i = 0; i < productCount ; i++){
        if(arrayProduct[i].stock > 20){
            std::cout << "Product " << i << ": \n";
            std::cout << "Name: "<< arrayProduct[i].name << "\n";
            std::cout << "Category: " << arrayProduct[i].category << "\n";
            std::cout << "Price: " << arrayProduct[i].price << "\n";
            std::cout << "Stock: " << arrayProduct[i].stock << "\n";
        }
    }
}

// Function to export products to a file
void productFile(Product arrayProduct[], int productCount) {
    std::ofstream outputFile("products.csv", std::ios::app); 
    if(!outputFile){
        std::cerr << "There is no products \n";
        return;
    }

    // Write product details to the file
    for(int i =0; i < productCount; i++){
        outputFile << arrayProduct[i].name << " , " << arrayProduct[i].category << " , " << arrayProduct[i].id << " , " << arrayProduct[i].price << " , " << arrayProduct[i].stock << "\n";
    }

    outputFile.close();
}
