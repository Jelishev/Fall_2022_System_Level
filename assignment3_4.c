#include <stdio.h>
#include <string.h>
#define n 20

struct covid_record {
    char first_name[100];
    char last_name[100];
    char birth_date[10];
    int  dose_count;
    char dose_date[10];
    char vaccine_type[100];
    int zip_code;
};

int print_record(struct covid_record* s) {
    printf("First name: %s\n", s->first_name);
    printf("Last name: %s\n", s->last_name);
    printf("Birth date: %s\n", s->birth_date);
    printf("Dose count: %d\n", s->dose_count);
    printf("Dose date: %s\n", s->dose_date);
    printf("Vaccine type: %s\n", s->vaccine_type);
    printf("Zip code: %d\n", s->zip_code);
    return 0;
}
struct covid_record records[n];

char * randfirst_names =
{"Darnel", "Hamza", "Maxim","Demarcus","Josiah",
"Jamal","Rayan","Devyn","Antony","Jamir","Zane","Savion"
};
char * randlast_names =
{"Wilcox","Sims","Farley","Vincent","Nash","Burns",
"Page","Williamson","Huang","Morrow","Farmer","Owens"
};
char * randbirth_dates = 
{"01/01/2000","02/02/2001","03/03/2002","04/04/2003","05/05/2004","06/06/2005",
"07/07/2006","08/08/2007","09/09/2008","10/10/2009","11/11/2010","12/12/2011"
};
int * randdose_count = {0,1,2};
char * randdose_date =
{
"01/01/2020","02/02/2020","03/03/2020","04/04/2020","05/05/2020","06/06/2021",
"07/07/2021","08/08/2021","09/09/2021","10/10/2021","11/11/2021","12/12/2021"
};
char * randvaccine_type =
{
"Pfizer","Moderna", "Johnson & Johnson"
};
int * randzip_codes = 
{
49965, 66543, 30107, 78069, 67661, 83465, 48009, 40170, 80027, 26150
};

int main() {
    char input[100];
    int inputnum = 0;
    char take_input[10];
    int count = 0;
    for (int i = 0; i < n; i++) {
        printf("Please enter a valid first name: ");
        scanf("%s", input);
        strcpy(records[i].first_name, input);
        printf("Please enter a valid last name: ");
        scanf("%s", input);
        strcpy(records[i].last_name, input);
        printf("Please enter a valid birthday in MM/DD/YYYY format: ");
        scanf("%s", input);
        strcpy(records[i].birth_date, input);
        printf("Please enter a number for your dose count: ");
        scanf("%d", &inputnum);
        records[i].dose_count = inputnum;
        printf("Please enter a valid dose date in MM/DD/YYYY format: ");
        scanf("%s", input);
        strcpy(records[i].dose_date, input);
        printf("Please enter the name of your vaccine supplier: ");
        scanf("%s", input);
        strcpy(records[i].vaccine_type, input);
        printf("Please enter your zip code: ");
        scanf("%d", &inputnum);
        records[i].zip_code = inputnum;

        printf("Would you like to continue inputting records?\n[Any key](continue)/N(No): ");
        scanf("%s", take_input);
        count++;
        if (strcmp(take_input, "N") == 0) {
            i = n;
        }
    }
    printf("\nThere have been %d records inputed\n", count);
    for (int i = 0; i < count; i++) {
        printf("Displaying record #%d\n", i+1);
        print_record(&records[i]);
    }
    return 0;
}
/*
struct covid_record *make_record(const char *s) {
    struct covid_record *s2;

    s2 = malloc(sizeof(struct covid_record));
    if (s2 == 0) return 0;

    s2->first_name = malloc(sizeof(char) * 100);
    if (s2->first_name == 0) {
        free(s2);
        return 0;
    }
    strncpy(s2->first_name, s, sizeof(char)*100);

    return s2;
}
*/
