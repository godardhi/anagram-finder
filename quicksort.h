#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <string>

int partition(std::string& str, int low, int high);
void quickSort(std::string& str, int low, int high);
std::string findSignature(const std::string& word);

#endif // QUICKSORT_H
