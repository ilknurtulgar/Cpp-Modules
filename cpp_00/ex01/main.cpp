#include "PhoneBook.hpp"


int main(){
    std::cout << "~ PhoneBook ~" << std::endl;
    phoneBook newPhoneBook;
    while(1){
    std::string input;
    std::cout << "Please use ADD, SEARCH, EXIT commands: ";
    getline(std::cin,input);

    if(input == "ADD")
          newPhoneBook.add();
    else if (input == "SEARCH")
        newPhoneBook.search();
    else if (input == "EXIT")
        newPhoneBook.exit();
    else
        std::cout << "Invalid commnad! Try again." << std::endl;
    }
}