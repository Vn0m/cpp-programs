#include <iostream>

void sort(int array[], int size);

int main(){

    int array[] = {41, 35, 1, 5, 25, 15, 18, 17, 51};

    // get the size 
    int sizeOfArray = sizeof(array) / sizeof(array[0]);

    sort(array, sizeOfArray);

    for(int element : array){
        std::cout << element << ' ';
    }


    return 0;
}

void sort(int array[], int size){

    int temp;
    // -1 because all the larger elements will be at the end and no need to compare them
    for(int i = 0; i < size - 1; i++){
        // elements at the right we dont need to compare them
        for(int j = 0; j < size - i - 1 ; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

}