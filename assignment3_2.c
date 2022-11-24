//System Level Programming Assignment 3
//Student name: Mike Doan
//Panther#: 002551968
//Student ID: mdoan4
//Description: this program implements the sort_alphabetic function described in part 2 of assignment 3
//             which sorts a list of names provided in the part 2 description 

#include<stdio.h>
#include<string.h>

void swapptr (char **a, char **b)
{
    char *t = *a;           /* pointer at a's address saved in t */
         *a = *b;           /* assign pointer from b to a */
         *b = t;            /* assign temp pointer t to b */
}

void sort_alphabetic(char **str) {
   int i, j;
   char *temp;
   for(i=0;i<8;i++){
      for(j=i+1;j<8;j++){
         if(strcmp(str[i],str[j])>0){
            //if any lower indexed name in the array has a higher alphabetic value than one with a higher index, swap them
            swapptr(&temp, &str[i]);
            swapptr(&str[i],&str[j]); //I use swapptr to swap the addresses of the two compared strings
            swapptr(&str[j], &temp);
         }
      }
   }
}


int main(){
   int k,n;
   //I declare my array here
   char *str[8]= {"Systems","Programming","Deep","Learning","Internet","Things" ,"Robotics" ,"Course"};
   //Print out the array before sorting
   printf("The unsorted list of names is \n\n");
   for(k=0;k<8;k++){
      printf("%s \n",str[k]);
   }
   //Call the sort_alphabetic function
   sort_alphabetic(str);
   //Print out the array after sortingh
   printf("\nThe sorted order of names are: \n\n");
   for(k=0;k<8;k++){
      printf("%s \n",str[k]);
   }
   return 0;
}