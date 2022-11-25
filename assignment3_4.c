//System Level Programming Assignment 3
//Student name: Mike Doan
//Panther#: 002551968
//Student ID: mdoan4
//Description: This program implements the covid record registration system described in part 4 of
//             the third homework assignment. The program description is as follows:
//                  The program implements the 'covid_record' struct, which contains the following information:
//                  - first name, last name, birth date, number of covid vaccine doses, date of most recent dose,
//                  - vaccine type, as well as the residential zip code
//                  The program has the following functions as requested by the description
//                  1. main(): this is where the functions are called and the C program is executed
//                  2. make_rand() (aka 'generate_code'): this function generates a random record 
//                     with information drawn from a list of randomly generated names, dates, and zip
//                     codes. Rest assured that no real human information is present in this program
//                     and any occurance of real human information is only through sheer cooincidence
//                  3. retrieve(): this function will print all the records inputed
//                  4. print_code(struct covid_record*): this function will print out the 8 alphanumeric code
//                     as described in the task description
//                  5. register_record(): this function lets users manually input info to the record array


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define n 50
#define current_year  2022
#define ARR_SIZE(arr) ( sizeof((arr)) / sizeof((arr[0])) )


struct covid_record {
    char first_name[100];
    char last_name[100];
    char birth_date[11];
    int  dose_count;
    char dose_date[11];
    char vaccine_type[100];
    int zip_code;
};

struct covid_record records[n];
int current_record_count = 0;


int print_record(struct covid_record* s) {
    printf("%s ", s->first_name);
    printf("%s, ", s->last_name);
    printf("Born: %s, ", s->birth_date);
    printf("Doses: %d, ", s->dose_count);
    printf("Last dose: %s, ", s->dose_date);
    printf("Manufacturer: %s, ", s->vaccine_type);
    printf("Zip code: %d\n", s->zip_code);
    return 0;
}

//I will use the following random variables to generate random covid records 

char * randfirst_names[] =
{"Darnel", "Hamza", "Maxim","Demarcus","Josiah",
"Jamal","Rayan","Devyn","Antony","Jamir","Zane","Savion"
};
char * randlast_names[] =
{"Wilcox","Sims","Farley","Vincent","Nash","Burns",
"Page","Williamson","Huang","Morrow","Farmer","Owens"
};
char * randbirth_dates[] = 
{"01/01/2000","02/02/2001","03/03/2002","04/04/2003","05/05/2004","06/06/2005",
"07/07/2006","08/08/2007","09/09/2008","10/10/2009","11/11/2010","12/12/2011"
};
int randdose_count[] = {1,2};
char * randdose_date[] =
{
"01/01/2020","02/02/2020","03/03/2020","04/04/2020","05/05/2020","06/06/2021",
"07/07/2021","08/08/2021","09/09/2021","10/10/2021","11/11/2021","12/12/2021"
};
char * randvaccine_type[] =
{
"Pfizer","Moderna", "Johnson & Johnson"
};
int randzip_codes[] = 
{
49965, 66543, 30107, 78069, 67661, 83465, 48009, 40170, 80027, 26150
};

struct covid_record * make_rand() {
    struct covid_record *temp; 
    //allocate memory to the randomly generated record
    temp = malloc(sizeof(struct covid_record));
    //copy the values from a randomly generated index from the given input arrays above into the corresponding values
    //NOTE: Yes I realize that "rand() % array_size" isn't the proper way to get a randomly generated element of an
    //      array. But as there are no explicit algorithms that depend on real randomness in this program, I figured it
    //      was fine to use this method in lue of something more proper.
    strcpy(temp->first_name,    randfirst_names[rand() % ARR_SIZE(randfirst_names)]);
    strcpy(temp->last_name,     randlast_names[rand() % ARR_SIZE(randlast_names)]);
    strcpy(temp->birth_date,    randbirth_dates[rand() % ARR_SIZE(randbirth_dates)]);
    temp->dose_count=           randdose_count[rand() % ARR_SIZE(randdose_count)];
    strcpy(temp->dose_date,     randdose_date[rand() % ARR_SIZE(randdose_date)]);
    strcpy(temp->vaccine_type,  randvaccine_type[rand() % ARR_SIZE(randvaccine_type)]);
    temp->zip_code =            randzip_codes[rand() % ARR_SIZE(randzip_codes)];
    current_record_count++;
    return temp; 
};

void print_code(struct covid_record* s) {
    printf("%c", s->first_name[0]);
    printf("%c", s->last_name[0]);
    int year;
    char year_string[4];
    for (int i = 0; i < 11; i++) {
        if (i > 5) {
            year_string[i-6] = s->birth_date[i];
        }
    }
    //Obtain the current age of user through the current year
    sscanf(year_string, "%d", &year);
    int age = current_year - year;
    if (age < 10) {
        printf("0%d", age);
    }
    else {printf("%d", age);}
    //printf("%d", year);
    //printf("%s", year_string);
    //Current year is considered 2022, therefore I will subtract the birthyear from the current year to get
    //the registered age
    
    printf("%c", s->vaccine_type[0]);
    int zip = s->zip_code % 1000;
    if (zip < 100) {
        if (zip < 10) {
            printf("00%d\n",zip);
        }
        else {
            printf("0%d\n", zip);
        }
    } 
    else {
    printf("%d\n", zip);
    }
};
//"Register" is a C reserved keyword so I will have to use "register_record"
struct covid_record * register_record() {
    struct covid_record *temp;
    temp = malloc(sizeof(struct covid_record));
    char input[100];
    int inputnum = 0;
    char take_input[10];
    int count = 0;
    printf("Please enter a valid first name: ");
    scanf("%s", input);
    strcpy(temp->first_name, input);
    printf("Please enter a valid last name: ");
    scanf("%s", input);
    strcpy(temp->last_name, input);
    printf("Please enter a valid birthday in MM/DD/YYYY format: ");
    scanf("%s", input);
    strcpy(temp->birth_date, input);
    printf("Please enter a number for your dose count: ");
    scanf("%d", &inputnum);
    temp->dose_count = inputnum;
    printf("Please enter a valid dose date in MM/DD/YYYY format: ");
    scanf("%s", input);
    strcpy(temp->dose_date, input);
    printf("Please enter the name of your vaccine supplier: ");
    scanf("%s", input);
    strcpy(temp->vaccine_type, input);
    printf("Please enter your zip code: ");
    scanf("%d", &inputnum);
    temp->zip_code = inputnum;
    current_record_count++;
    print_code(temp);
    return temp;
};

void retrieve() {
    printf("\nPrinting all records: \n");
    for (int i = 0; i < current_record_count; i++) {
        print_record(&records[i]);
    }
}






int main() {
    struct covid_record *test = make_rand();
    print_record(test);
    current_record_count--;
    //Test print, this was not inserted into the array of records
    for (int i = current_record_count; i < 20; i++) {
        records[i] = *make_rand();
        //print_record(&records[i]);
        print_code(&records[i]);
    }
    records[current_record_count] = *register_record();
    retrieve();
    return 0;
}
 