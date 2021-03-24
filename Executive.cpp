#include "Executive.h"

#define RESTAURANT 1
#define DISTANCE 2
#define REVIEW 3

void Executive::run()
{

    std::cout << m_fileName << " has been received as the file.\n";
    m_dataFile.open(m_fileName);
    if (m_dataFile.is_open())
    {

        std::string input;
        int currentInputType = RESTAURANT;

        while (m_dataFile >> input)
        {
            if (currentInputType == RESTAURANT)
            {
                std::string name = "";
                if (containsComma(input))
                {
                    name = removeTrailingComma(input);
                }
                else
                {
                    while (1)
                    {
                        name = name + input;
                        if (containsComma(name))
                        {
                            break;
                        }

                        m_dataFile >> input;
                        name = name + " ";
                    }
                    name = removeTrailingComma(name);
                }
                std::cout << "Name: " << name << std::endl;
                currentInputType = DISTANCE;
            }
            else if (currentInputType == DISTANCE)
            {
                double dist = 0.0;
                input = removeTrailingComma(input);
                dist = std::stod(input);
                std::cout << "Distance: " << dist << std::endl;
                currentInputType = REVIEW;
            }
            else if (currentInputType == REVIEW)
            {
                int rev = 0;
                input = removeTrailingComma(input);
                rev = std::stoi(input);
                std::cout << "Reviews: " << rev << std::endl;
                currentInputType = RESTAURANT;
            }
        }

        bool exit = false;
        while (!exit)
        {

            std::cout << "\nPlease choose one of the following commands:\n"
                      << "1. Add new restaurant\n2. Remove nearest restaurant\n3. Remove most reviewed restaurant\n4. Search nearest restaurant\n5. Search most reviewed restaurant\n6. Print by restaurant distance\n7. Print by restaurant review count\n8. Exit\n";
            int choice;
            std::cin >> choice;

            std::cout << std::endl;
            switch (choice)
            {
            case 1:
                std::cout << "Please enter the integer to add:\n";
                std::cin >> input;

                break;
            case 2:
                std::cout << "Please enter the integer to delete:\n";
                std::cin >> input;

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:
                exit = true;
                break;

            default:
                std::cout << "Please enter a number from 1 to 8." << std::endl;
                std::cin >> choice;
                break;
            }
        }
        return;

        m_dataFile.close();
    }
    else
    {
        std::cout << "Failed to open the file.\n";
        return;
    }
}

std::string Executive::removeTrailingComma(std::string input)
{
    if (input[input.length() - 1] == ',')
    {
        std::string temp = "";
        for (size_t i = 0; i < input.length() - 1; i++)
        {
            temp = temp + input[i];
        }

        return (temp);
    }
    return (input);
}

bool Executive::containsComma(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] == ',')
        {
            return (true);
        }
    }
    return (false);
}

void Executive::maxHeapify(Restaurant arr[], int length, int index)
{
    int children[4];

    while (1)
    {
        for (int i = 1; i <= 3; i++)
        {
            if ((3 * index + i) < length)
            {
                children[i] = 3 * index + i;
            }
            else
            {
                children[i] = -1;
            }
        }

        double max_child = -1.0;
        int max_child_index;
        for (int i = 1; i <= 3; i++)
        {
            if (children[i] != -1 &&
                arr[children[i]].distance > max_child)
            {
                max_child_index = children[i];
                max_child = arr[children[i]].distance;
            }
        }

        if (max_child == -1.0)
        {
            break;
        }

        if (arr[index].distance < arr[max_child_index].distance)
        {
            swap(arr[index], arr[max_child_index]);
        }
        index = max_child_index;
    }
}

void Executive::minHeapify(Restaurant arr[], int length, int index)
{

    int children[4];

    while (1)
    {

        for (int i = 1; i <= 3; i++)
        {
            if ((3 * index + i) < length)
            {
                children[i] = 3 * index + i;
            }
            else
            {
                children[i] = -1;
            }
        }
        int min_child = -1;
        int min_child_index;

        for (int i = 1; i <= 3; i++)
        {
            if (children[i] != -1 &&
                arr[children[i]].reviews < min_child)
            {
                min_child_index = children[i];
                min_child = arr[children[i]].reviews;
            }
        }

        if (min_child == -1)
        {
            break;
        }

        if (arr[index].reviews > arr[min_child_index].reviews)
        {
            swap(arr[index], arr[min_child_index]);
        }
        index = min_child_index;
    }
}

void Executive::maxUpHeap(Restaurant arr[], int index)
{
    int parent = floor((index - 1) / 3);

    while (parent >= 0)
    {
        if (arr[index].distance > arr[parent].distance)
        {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = floor((index - 1) / 3);
        }
        else
        {
            break;
        }
    }
}

void Executive::minUpHeap(Restaurant arr[], int index)
{

    int parent = floor((index - 1) / 3);

    while (parent >= 0)
    {
        if (arr[index].reviews < arr[parent].reviews)
        {
            swap(arr[index], arr[parent]);
            index = parent;
            parent = floor((index - 1) / 3);
        }
        else
        {
            break;
        }
    }
}

void Executive::buildMaxHeap(Restaurant arr[], int n)
{

    for (int i = (n - 1) / 3; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void Executive::buildMinHeap(Restaurant arr[], int n)
{

    for (int i = (n - 1) / 3; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }
}

void Executive::maxInsert(Restaurant arr[], int *n, Restaurant rest)
{
    arr[*n] = rest;

    *n = *n + 1;

    maxUpHeap(arr, *n - 1);
}

void Executive::minInsert(Restaurant arr[], int *n, Restaurant rest)
{
    arr[*n] = rest;

    *n = *n + 1;

    minUpHeap(arr, *n - 1);
}

Restaurant Executive::popMax(Restaurant arr[], int *n)
{
    Restaurant max = arr[0];
    arr[0] = arr[*n - 1];
    *n = *n - 1;
    maxHeapify(arr, *n, 0);
    return max;
}

Restaurant Executive::popMin(Restaurant arr[], int *n)
{
    Restaurant min = arr[0];
    arr[0] = arr[*n - 1];
    *n = *n - 1;
    minHeapify(arr, *n, 0);
    return min;
}