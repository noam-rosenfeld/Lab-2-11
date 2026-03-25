#include <iostream>

using namespace std;

void getScores(double* arr, int size) {
    double score;

    for(int i = 0; i < size; i++) {
        cout << "Please enter the grade for student " << i + 1 << ": ";
        cin >> score;
        if(score > 0) {
            *(arr + i) = score;
        }  
    }
}

void sortScores(double* arr, int size) {
    double largest = 0;
    double holdValue;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i; i++) {
            if(*(arr + j) > *(arr + j + 1)) {
                holdValue = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = holdValue;
            }
        }
    }
}

double calculateAverage(const double* arr, int size) {
    double sum = 0;

    for(int i = 0; i < size; i++) sum += *(arr + i);
    return sum / size;
}

int main() {
    int input;
    cout << "How many test scores would you like to process? ";
    cin >> input;
    if(input < 0) return 1;

    double testArray[input];
    getScores(testArray, input);
    sortScores(testArray, input);
    double average = calculateAverage(testArray, input);

    cout << "Your sorted scores are:";
    
    for(int i = 0; i < input; i++) {
        cout << " " << testArray[i];
    }

    cout << "\nYour score average is: " << average << endl;
}