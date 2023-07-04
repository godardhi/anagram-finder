#include "quicksort.h"

int partition(std::string& str, int low, int high)
{
    char pivot = str[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (str[j] < pivot) {
            i++;
            std::swap(str[i], str[j]);
        }
    }

    std::swap(str[i + 1], str[high]);
    return i + 1;
}

void quickSort(std::string& str, int low, int high)
{
    if (low < high) {
        int pi = partition(str, low, high);

        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}

std::string findSignature(const std::string& word)
{
    std::string signature = word;
    int length = signature.length();

    quickSort(signature, 0, length - 1);

    return signature;
}
