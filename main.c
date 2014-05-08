/* Name: Dilan Samarasinghe
   ID: DS697678
*/

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "struct_def.h"
#include "prototypes.h"
int main(int argc, char *argv[]){
FILE *infileptr; // file pointer for input file
FILE *outfileptr;// file pointer for putput file 
char string[MAX_LENGTH];// character array to store the string
 double numLines = 0; // keeps track of number of lines with words
 int value;//keep various int values from functions for writing to file
 double average; // keep double value from average calculations for writing to file 
  // check if the number of arguments is correct
 if(argc != NUM_COMMANDS){ 
   fprintf(stderr ,"Invalid number of commands. Usage: p1 infile outfile \n");
   exit(1);
 }
 // open input file for reading
 if((infileptr = fopen(argv[1],"r")) == NULL){
   fprintf(stderr,"Error occured during the opening of the file: %s \n" ,argv[1]);
   exit(1);
 }
 // open output file for writing
 if((outfileptr = fopen(argv[2],"w")) == NULL){
   fprintf(stderr,"Error occured during the opening of the file: %s \n" ,argv[2]);
   exit(1);
 }
 // use fgets to get the first line in the file which is the size of the table
 fgets(string,MAX_LENGTH+1,infileptr);
 /* printf("%d",atoi(string));*/
 // pass that size to the setup function
 setup(atoi(string));
 // traverse through the file until you reach the end.
 while((fgets(string,MAX_LENGTH+1,infileptr))!= NULL){
   // code to check for new line character and remove it.
    if(string[strlen(string)-1] == '\n'){
     string[strlen(string)-1] = '\0';
    }
   // add string to table one and two
   addh1(string);
   //printf("%s\n",string);
   addh2(string);
   numLines++;
 }
 //Print the various values for the first hash function
 fprintf(outfileptr ,"Results for hash Function I\n");
 fprintf(outfileptr,"---------------------------\n");
 value = getSize();
 fprintf(outfileptr,"Hash table size: %d \n",value);
 value = countNonEmptyh1();
 fprintf(outfileptr,"Number of non-empty lists: %d\n",value);
 value = maxEntriesh1();
 fprintf(outfileptr,"Maximum number of entries in a list: %d\n",value);
 value = minEntriesh1();
 fprintf(outfileptr,"Minimum number of entries in a non-empty list: %d\n",value);
 average = calculateAverageh1(numLines);
 fprintf(outfileptr,"Average number of entries in a non-empty list: %.2f\n",average);

 //print the various values for the second hash function
 fprintf(outfileptr ,"\nResults for hash Function II\n");
 fprintf(outfileptr,"----------------------------\n");
 value = getSize();
 fprintf(outfileptr,"Hash table size: %d \n",value);
 value = countNonEmptyh2();
 fprintf(outfileptr,"Number of non-empty lists: %d\n",value);
 value = maxEntriesh2();
 fprintf(outfileptr,"Maximum number of entries in a list: %d\n",value);
 value = minEntriesh2();
 fprintf(outfileptr,"Minimum number of entries in a non-empty list: %d\n",value);
 average = calculateAverageh2(numLines);
 fprintf(outfileptr,"Average number of entries in a non-empty list: %.2f\n",average);


 
 // close files
 if(fclose(infileptr) == EOF){
   fprintf(stderr, "Error occured during closing of file %s \n",argv[1]);
   exit(1);
 }
 if(fclose(outfileptr) == EOF){
   fprintf(stderr, "Error occured during closing of file %s \n", argv[2]);
 }
 return 0; 
}// END OF MAIN

	
   
