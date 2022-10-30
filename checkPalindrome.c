//Mike Doan - mdoan4 - 002551968
//This file contains the function isPalindrome, which takes in 
//  a string input and returns a 1 if it is a palindrome 
//  and 0 if it is not

#include <stdio.h>
#include <string.h>
int isPalindrome(char* s) {
    int l = strlen(s) - 1;
    for (int i = 0; i < l; i++) {
        if (s[i] != s[l-i]) {
            //printf("%c - %c\n", s[i], s[l-i]);
            //this line will print out whatever characters
            //  were the first to break the palindrome
            //  rule
            return 0;
        }
    }
    return 1;
}
int check(int state) {
    if (state) {
        printf("The provided string is a palindrome");
        return 0;
    }
    else {
        printf("The provided string is not a palindrome");
    }
}
int main() {
    char* test1 = "aba";
    //char* test2 = "ab";
    //char* test3 = "aba";
    //char* test4 = "abba";
    check(isPalindrome(test1));
}