#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "Restaurant.h"

class Executive
{
private:
    std::fstream m_dataFile;
    std::string m_fileName;
    std::string removeTrailingComma(std::string input);
    bool containsComma(std::string input);
    void maxHeapify(Restaurant maxHeapArray[], int length, int index);
    void minHeapify(Restaurant minHeapArray[], int length, int index);
    void maxUpHeap(Restaurant maxHeapArray[], int index);
    void minUpHeap(Restaurant minHeapArray[], int index);
    void buildMaxHeap(Restaurant maxHeapArray[], int numElements);
    void buildMinHeap(Restaurant minHeapArray[], int numElements);
    void maxInsert(Restaurant maxHeapArray[], int *numElements, Restaurant restaurant);
    void minInsert(Restaurant minHeapArray[], int *numElements, Restaurant restaurant);
    Restaurant popMax(Restaurant maxHeapArray[], int *numElements);
    Restaurant popMin(Restaurant minHeapArray[], int *numElements);
    void swap(Restaurant &a, Restaurant &b){Restaurant temp = a;a = b;b = temp;};

public:
    Executive(std::string fileName) { m_fileName = fileName; };
    void run();
};

#endif