#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int ar[50];
    cout << "Enter a size of the array: ";
    int size;
    cin >> size;

    cout << "\nThe array: ";
    //srand(time(0));
    for (int i = 0; i < size; ++i) {
        cout << (ar[i] = rand() % 41 - 20) << " ";
    }
    cout << "\n";

    for (int i = 0; i < size; ++i) {
        if (ar[i] == 0) {
            for (int j = i; j + 1 < size; ++j) ar[j] = ar[j + 1];
            --size;
        }
    }

    int first_even = 0;
    for (int i = 0; i < size; ++i) {
        if (ar[i] % 2 == 0) {
            first_even = i;
            break;
        }
    }

    for (int i = size++; i > first_even; --i) {
        ar[i] = ar[i - 1];
    }
    ar[first_even + 1] = (first_even ? ar[first_even - 1] + 2 : ar[size - 1] + 2);

    cout << "\nThe modified array: ";
    for (int i = 0; i < size; ++i) cout << ar[i] << " ";
    cout << "\n";

    return 0;
}