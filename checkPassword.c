#include <stdio.h>
#include <string.h>

int checkLength(int score, char* string) {
    //check if length of string is greater or equal to 10
    if (strlen(string) >= 10) {
        return 0;
    }
    //if not, subtract 5 points for each missing char
    else {
        return score - (10 - strlen(string)) * 5;
    }
}

int checkConditions(int score, char* string) {
    //i have 4 conditionals that can only be toggled on or off during runtime
    //so if at anytime, one of these conditions are satisfied, they will be changed
    //to their final value
    //(example: if there is an occurance of a lower case character at any point
    //  then missingLower will be set to 0 and 20 points will not be subtracted
    //  from score)
    int missingLower = 1;
    int missingUpper = 1;
    int missingNumber = 1;
    int hasConsecutive = 0;
    char temp = string[0];
    for (int i = 1; i < strlen(string); i++) {
        if(string[i] >= 'a' && string[i] <= 'z') {
            missingLower = 0;
        }
        if(string[i] >= 'A' && string[i] <= 'Z') {
            missingUpper = 0;
        }
        if(string[i] >= '0' && string[i] <= '9' ) {
            missingNumber = 0;
        }
        if (temp + 1 == string[i]) {
            hasConsecutive = 1;
        }
        temp = string[i];
    }
    return score - (missingLower + missingUpper + missingNumber + hasConsecutive) * 20;
}

int main() {
    int score = 0;
    char input[256];
    printf("Please input a password: ");
    scanf("%s", input);
    //this is for question 17
    //score = checkLength(score, input);
    score = checkConditions(score, input);
    printf("%d", score);
    if (score < -30) {
        printf("\nThe password is unsafe! Please reset.");
    }
    else {
        printf("\nThe password is safe");
    }
}