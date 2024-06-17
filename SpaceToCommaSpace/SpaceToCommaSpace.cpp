#include <iostream>
char* space_to_comma_space(const char* string) {
    std::size_t new_string_length = 0;
    std::size_t length = 0;
    while (string[length] != '\0') {
        if (string[length] == ' ') {
            new_string_length++;
        }
        length++;
    }
    new_string_length = length + new_string_length + 1;
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

std::size_t charStrLength(const char* string) {
    std::size_t length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

char* replaceCharToCharArray(const char* string, char replace, const char* replaceTo) {
    std::size_t new_string_length = 0;
    std::size_t length = 0;
    std::size_t replaceToLength = charStrLength(replaceTo);
    while (string[length] != '\0') {
        if (string[length] == replace) {
            new_string_length += replaceToLength - 1;
        }
        length++;
    }
    new_string_length = length + new_string_length + 1;
    char* new_string = new char[new_string_length];
    std::size_t iter = 0;
    for (std::size_t i = 0; i < length; i++) {
        if (string[i] == replace) {
            for (std::size_t repleceToIndex = 0; repleceToIndex < replaceToLength; repleceToIndex++) {
                new_string[iter + repleceToIndex] = replaceTo[repleceToIndex];
            }
            iter += replaceToLength - 1;
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
    char* new_t = replaceCharToCharArray("test2test2test2test" ,'2', "___");
    std::cout << new_t;
    delete[] new_t;
    return 0;
}