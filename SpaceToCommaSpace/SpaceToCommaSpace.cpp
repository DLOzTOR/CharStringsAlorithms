#include <iostream>
char* space_to_comma_space(char* string, std::size_t length) {
    int new_string_length = 0;
    for (std::size_t i = 0; i < length; i++) {
        if(string[i] == ' '){
            new_string_length++;
        }
    }
    new_string_length = length + new_string_length + 1;
    std::cout << new_string_length << std::endl;
    char* new_string = new char[new_string_length];
    std::size_t iter = 0;
    for (std::size_t i = 0; i < length; i++) {
        if (string[i] == ' ') {
            new_string[iter] = ',';
            iter++;
            new_string[iter] = ' ';

        }
        else {
            new_string[iter] = string[i];
        }
        iter++;
    }
    new_string[new_string_length - 1] = '\0';
    return new_string;
}

int main()
{
    char t[] = "test test test ";
    char* new_t = space_to_comma_space(t, 15);
    std::cout << new_t;
    delete[] new_t;
    return 0;
}