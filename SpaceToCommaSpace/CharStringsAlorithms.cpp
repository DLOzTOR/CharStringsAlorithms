#include <iostream>
char* space_to_comma_space(const char* string) {
    size_t new_string_length = 0;
    size_t length = 0;
    while (string[length] != '\0') {
        if (string[length] == ' ') {
            new_string_length++;
        }
        length++;
    }
    new_string_length = length + new_string_length + 1;
    char* new_string = new char[new_string_length];
    size_t iter = 0;
    for (size_t i = 0; i < length; i++) {
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

size_t charStrLength(const char* string) {
    size_t length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

char* replaceCharToCharArray(const char* string, char replace, const char* replaceTo) {
    size_t new_string_length = 0;
    size_t length = 0;
    size_t replaceToLength = charStrLength(replaceTo);
    while (string[length] != '\0') {
        if (string[length] == replace) {
            new_string_length += replaceToLength - 1;
        }
        length++;
    }
    new_string_length = length + new_string_length + 1;
    char* new_string = new char[new_string_length];
    size_t iter = 0;
    for (size_t i = 0; i < length; i++) {
        if (string[i] == replace) {
            for (size_t repleceToIndex = 0; repleceToIndex < replaceToLength; repleceToIndex++) {
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

unsigned int countSubString(const char* string, const char* subString) {
    unsigned int subStringCount = 0;
    size_t iter = 0, subStringIndex = 0;
    while (string[iter] != '\0') {
        while (string[iter] == subString[subStringIndex])
        {
            subStringIndex++;
            iter++;
            if (subString[subStringIndex] == '\0') {
                subStringCount++;
                subStringIndex = 0;
            }
        }
        iter++;
    }
    return subStringCount;
}

char* replace(const char* string, const char* replace, const char* replaceTo) {
    unsigned int stringLength = charStrLength(string);
    unsigned int replaceLength = charStrLength(replace); 
    unsigned int replaceToLength = charStrLength(replaceTo); 
    unsigned int replaceCount = countSubString(string, replace);
    size_t iterIn = 0; 
    size_t iterOut = 0; 
    size_t replaceIndex = 0; 
    size_t replaceIter = 0;
    char* replacedString = new char[(int)charStrLength(string) + (int)(replaceToLength - replaceLength) * (int)replaceCount + 1];
    bool isReplace = false;
    while (string[iterIn] != '\0') {
        if (string[iterIn] != replace[0]) {
            replacedString[iterOut] = string[iterIn];
            iterIn++;
            iterOut++;
        }
        else {
            isReplace = true;
            replaceIter = iterIn;
            replaceIter++;
            replaceIndex++;
            while (isReplace) {
                if (string[replaceIter] != replace[replaceIndex] || string[replaceIter] == '\0' || replace[replaceIter] == '\0') {
                    isReplace = false;
                    if (replace[replaceIndex] == '\0') {
                        for (replaceIndex = 0; replaceIndex < replaceToLength; replaceIndex++) {
                            replacedString[iterOut] = replaceTo[replaceIndex];
                            iterOut++;
                        }
                        iterIn += replaceLength;
                    }
                    else {
                        for (; iterIn < replaceIter; iterIn++) {
                            replacedString[iterOut] = string[iterIn];
                            iterOut++;
                        }
                    }
                    replaceIndex = 0;
                }
                else {
                    replaceIter++;
                    replaceIndex++;
                }
            }
        }
    }
    replacedString[(int)charStrLength(string) + (int)(replaceToLength - replaceLength) * (int)replaceCount] = '\0';
    return replacedString;
}

int main()
{
    std::cout << replace("test text to replace test: telephone test", "test", "It`s work!");
    return 0;
}