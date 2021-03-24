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
                if (containsComma(input)) {
                    name = removeTrailingComma(input);
                } else {
                    while (!containsComma(name))
                    {
                        name = name + input;
                        std::cout << "\nNAME: " << name << "\nINPUT: " << input;
                        m_dataFile >> input;
                        std::cout << "\nNAME: " << name << "\nINPUT: " << input;
                        name = name + " ";
                    }
                    name = removeTrailingComma(name);
                }
                std::cout << "Name: " << name << std::endl;
                currentInputType = DISTANCE;
            } else if (currentInputType == DISTANCE) {
                double dist = 0.0;
                input = removeTrailingComma(input);
                dist = std::stod(input);
                std::cout << "Distance: " << dist << std::endl;
                currentInputType = REVIEW;
            } else if (currentInputType == REVIEW) {
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
        
        return(temp);
    }
    return(input);
}

bool Executive::containsComma(std::string input)
{
    for (size_t i = 0; i < input.length(); i++)
    {
        std::cout << input[i];
        if (input[i] == ',')
        {
            return(true);
        }
        
    }
    return(false);
}