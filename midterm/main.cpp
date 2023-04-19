// Ahmed Abdullah
// FA21-BCS-141

#include <iostream>

#include "employee.h"
#include "linkedlist.h"

void print_menu(LinkedList<Employee*> list);

int main()
{
    LinkedList<Employee*> list;
    print_menu(list);

}

void print_menu(LinkedList<Employee*> list)
{
    int option;
    while (true)
    {
        printf("\033[1;34m ----MENU----\033[0m\n");
        printf("1. Add Employee\n");
        printf("2. See employee details\n");
        printf("3. Remove Duplicates\n");
        printf("4. Print List\n");
        printf("5. Exit Program\n");

        // Print in blue color
        printf("\033[1;34m Enter your option: \033[0m");
        std::cin >> option;
        if (!std::cin)
        {
            std::cout << "Enter a valid option." << std::endl;
            continue;
        }

        int id;
        std::string name;
        std::string employee_name;
        switch(option)
        {
            case 1:
                std::cout << "Enter the ID of Employee: ";
                std::cin >> id;
                if (!std::cin)
                {
                    break;
                }
               
                std::cout << "Enter the name of the Employee: ";
                try
                {
                    std::cin.ignore(); // to ignore the \n from the previous cin
                    std::getline(std::cin, name); // read the whole line
                }
                catch(const std::exception& e)
                {
                    std::cout << "Enter a valid name" << std::endl;
                }
                list.insert_back(new Employee(id, name));
                std::cout << "Employee Inserted" << std::endl;
                break;

            case 2:
                std::cout << "Enter Employee ID to search: ";
                std::cin >> id;
                employee_name = list.search(id);
                if (employee_name != "none")
                {
                    std::cout << "Employee ID: " << id << std::endl;
                    std::cout << "Employee Name: " << employee_name << std::endl;
                }
                else
                {
                    std::cout << "Employee not found!" << std::endl;
                }
                break;

            case 3:
                list.remove_duplicates();
                std::cout << "Duplicates Removed\n" << std::endl;
                break;

            case 4:
                list.print();
                break;

            case 5:
                std::cout << "Program Exited!" << std::endl;
                exit(0);

            default:
                break;
        }
    }
    
}
