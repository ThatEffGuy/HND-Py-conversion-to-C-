#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> GenerateRandomNumbers() {
    std::vector<int> random_list;

    int howmany;
    std::cout << "How many numbers do you want to have in the list: ";
    std::cin >> howmany;

    for (int i = 0; i < howmany; i++) {
        random_list.push_back(rand() % 5000);
    }

    return random_list;
}

bool linearSearch(int myItem, std::vector<int> myList) {
    bool found = false;
    int position = 0;

    while (position < myList.size() && !found) {
        if (myList[position] == myItem) {
            found = true;
        }
        position++;
    }

    return found;
}

int main() {
    srand(time(0));

    std::vector<int> returnedList = GenerateRandomNumbers();

    for (int i = 0; i < returnedList.size(); i++) {
        std::cout << returnedList[i] << " ";
    }

    int userNumber;
    std::cout << "\nWhat number do you want to find ?: ";
    std::cin >> userNumber;

    clock_t startTime = clock();
    bool isFound = linearSearch(userNumber, returnedList);
    clock_t endTime = clock();

    if (isFound) {
        std::cout << "\nThe number you typed is in the list\n";
    }
    else {
        std::cout << "\nThe number you typed is not in the list\n";
    }

    double theTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    std::cout << "\nThe time after searching: " << theTime << std::endl;

    return 0;
}