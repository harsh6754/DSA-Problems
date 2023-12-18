// #include<bits/stdc++.h>
// using namespace std;

// bool isPunctuator(char ch)					 
// {
//     if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
//         ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
//         ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
//         ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
//         ch == '&' || ch == '|')
//         {
//             return true;
//         }
//     return false;
// }

// bool validIdentifier(char* str)						 
// {
//     if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
//         str[0] == '3' || str[0] == '4' || str[0] == '5' ||
//         str[0] == '6' || str[0] == '7' || str[0] == '8' ||
//         str[0] == '9' || isPunctuator(str[0]) == true)
//         {
//             return false;
//         }									 
//     int i,len = strlen(str);
//     if (len == 1)
//     {
//         return true;
//     }										 
//     else
//     {
//     for (i = 1 ; i < len ; i++)					 
//     {
//         if (isPunctuator(str[i]) == true)
//         {
//             return false;
//         }
//     }
//     }
//     return true;
// }

// bool isOperator(char ch)							 
// {
//     if (ch == '+' || ch == '-' || ch == '*' ||
//         ch == '/' || ch == '>' || ch == '<' ||
//         ch == '=' || ch == '|' || ch == '&')
//     {
//        return true;
//     }
//     return false;
// }


// bool isSymbol(char ch)							 
// {
//     if (ch == '(' || ch == ')' || ch == '{' ||
//         ch == '}' || ch == '[' || ch == ']' )
//     {
//        return true;
//     }
//     return false;
// }


// bool isKeyword(char *str)						 
// {
//     if (!strcmp(str, "if") || !strcmp(str, "else") ||
//         !strcmp(str, "while") || !strcmp(str, "do") ||
//         !strcmp(str, "break") ||  !strcmp(str, "continue")
//         || !strcmp(str, "int") || !strcmp(str, "double")
//         || !strcmp(str, "float") || !strcmp(str, "return")
//         || !strcmp(str, "char") || !strcmp(str, "case")
//         || !strcmp(str, "long") || !strcmp(str, "short")
//         || !strcmp(str, "typedef") || !strcmp(str, "switch")
//         || !strcmp(str, "unsigned") || !strcmp(str, "void")
//         || !strcmp(str, "static") || !strcmp(str, "struct")
//         || !strcmp(str, "sizeof") || !strcmp(str,"long")
//         || !strcmp(str, "volatile") || !strcmp(str, "typedef")
//         || !strcmp(str, "enum") || !strcmp(str, "const")
//         || !strcmp(str, "union") || !strcmp(str, "extern")
//         || !strcmp(str,"bool"))
//         {
//             return true;
//         }
//     else
//     {
//        return false;
//     }
// }

// bool isNumber(char* str)							 
// {
//     int i, len = strlen(str),numOfDecimal = 0;
//     if (len == 0)
//     {
//         return false;
//     }
//     for (i = 0 ; i < len ; i++)
//     {
//         if (numOfDecimal > 1 && str[i] == '.')
//         {
//             return false;
//         } else if (numOfDecimal <= 1)
//         {
//             numOfDecimal++;
//         }
//         if (str[i] != '0' && str[i] != '1' && str[i] != '2'
//             && str[i] != '3' && str[i] != '4' && str[i] != '5'
//             && str[i] != '6' && str[i] != '7' && str[i] != '8'
//             && str[i] != '9' || (str[i] == '-' && i > 0))
//             {
//                 return false;
//             }
//     }
//     return true;
// }





// char* subString(char* realStr, int l, int r)				 
// {
//     int i;

//     char* str = (char*) malloc(sizeof(char) * (r - l + 2));

//     for (i = l; i <= r; i++)
//     {
//         str[i - l] = realStr[i];
//         str[r - l + 1] = '\0';
//     }
//     return str;
// }


// void parse(char* str)						 
// {
//     int left = 0, right = 0;
//     int len = strlen(str);
//     while (right <= len && left <= right) {
//         if (isPunctuator(str[right]) == false)			 
//             {
//                 right++;
//             }

//         if (isPunctuator(str[right]) == true && left == right)		 
//             {
//             if (isOperator(str[right]) == true)
//             {
//                 std::cout<< str[right] <<" IS AN OPERATOR\n";
//             }
//             right++;
//             left = right;
//             } else if (isPunctuator(str[right]) == true && left != right
//                    || (right == len && left != right)) 			 
//             {
//             char* sub = subString(str, left, right - 1);    

//             if (isKeyword(sub) == true)
//                         {
//                             cout<< sub <<" IS A KEYWORD\n";
//                         }
//             else if (isNumber(sub) == true)
//                         {
//                             cout<< sub <<" IS A NUMBER\n";
//                         }
//             else if (validIdentifier(sub) == true
//                      && isPunctuator(str[right - 1]) == false)
//                      {
//                          cout<< sub <<" IS A VALID IDENTIFIER\n";
//                      }
//             else if (validIdentifier(sub) == false
//                      && isPunctuator(str[right - 1]) == false)
//                      {
//                          cout<< sub <<" IS NOT A VALID IDENTIFIER\n";
//                      }

//             left = right;
//             }
//     }
//     return;
// }

// int main()
// {
//     char c[100] = "int m = n + 3p*(5*l-)";
//     parse(c);
//     return 0;
// }
#include <iostream>
#include <cstring>

using namespace std;

bool isPunctuator(char ch) {
    switch (ch) {
        case ' ':
        case '+':
        case '-':
        case '*':
        case '/':
        case ',':
        case ';':
        case '>':
        case '<':
        case '=':
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}':
        case '&':
        case '|':
            return true;
        default:
            return false;
    }
}

bool validIdentifier(char* str) {
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' ||
        str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' ||
        isPunctuator(str[0])) {
        return false;
    }
    int len = strlen(str);
    if (len == 1) {
        return true;
    } else {
        for (int i = 1; i < len; i++) {
            if (isPunctuator(str[i])) {
                return false;
            }
        }
    }
    return true;
}

bool isOperator(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '>':
        case '<':
        case '=':
        case '|':
        case '&':
            return true;
        default:
            return false;
    }
}

bool isKeyword(const char* str) {
    const char* keywords[] = {"if", "else", "while", "do", "break", "continue",
                               "int", "double", "float", "return", "char", "case",
                               "long", "short", "typedef", "switch", "unsigned",
                               "void", "static", "struct", "sizeof", "long",
                               "volatile", "typedef", "enum", "const", "union",
                               "extern", "bool"};

    for (const char* keyword : keywords) {
        if (strcmp(str, keyword) == 0) {
            return true;
        }
    }
    return false;
}

bool isSymbol(char ch) {
    switch (ch) {
        case '(':
        case ')':
        case '{':
        case '}':
        case '[':
        case ']':
            return true;
        default:
            return false;
    }
}

bool isNumber(const char* str) {
    int i, len = strlen(str), numOfDecimal = 0;
    if (len == 0) {
        return false;
    }
    for (i = 0; i < len; i++) {
        if (numOfDecimal > 1 && str[i] == '.') {
            return false;
        } else if (numOfDecimal <= 1 && str[i] == '.') {
            numOfDecimal++;
        } else if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
                   str[i] != '3' && str[i] != '4' && str[i] != '5' &&
                   str[i] != '6' && str[i] != '7' && str[i] != '8' &&
                   str[i] != '9' || (str[i] == '-' && i > 0)) {
            return false;
        }
    }
    return true;
}

char* subString(const char* realStr, int l, int r) {
    int i;
    char* str = new char[r - l + 2];

    for (i = l; i <= r; i++) {
        str[i - l] = realStr[i];
    }
    str[r - l + 1] = '\0';
    return str;
}

void printToken(const char* token, const char* type) {
    cout << token << " is a " << type << endl;
}

void parse(const char* str) {
    int left = 0, right = 0;
    int len = strlen(str);
    while (right <= len && left <= right) {
        if (!isPunctuator(str[right])) {
            right++;
        }

        if (isPunctuator(str[right])) {
            if (left == right) {
                if (isOperator(str[right])) {
                    printToken(subString(str, left, right), "OPERATOR");
                }
                right++;
                left = right;
            } else {
                const char* sub = subString(str, left, right - 1);
                if (isKeyword(sub)) {
                    printToken(sub, "KEYWORD");
                } else if (isNumber(sub)) {
                    printToken(sub, "NUMBER");
                } else if (validIdentifier(const_cast<char*>(sub))) {
                    printToken(sub, "VALID IDENTIFIER");
                } else {
                    printToken(sub, "INVALID IDENTIFIER");
                }
                left = right;
            }
        }
    }
}

int main() {
    const char c[100] = "int m = n + 3 / p*(5*l-)";
    parse(c);
    return 0;
}
