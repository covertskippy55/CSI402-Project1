/* Name: Dilan Samarasinghe
   ID: DS697678
*/
#include <stdio.h>
#include <stdlib.h>
#include "struct_def.h"
#include "prototypes.h"

int tSize; // This stores our size for the tables
struct node **hashTableOne; // table for first hash
struct node **hashTableTwo; // table for second hash
/* we set up the two tables from above in this function. It uses an int for the size
   and returns nothing
*/
void setup(int size){
  tSize = size; // sets the above global variable since its used in most functions.
  // standard creation using malloc with error checking
  if(( hashTableOne = malloc(sizeof(struct node) * size))== NULL){
    fprintf(stderr,"Error occured during malloc");
    exit(1);
  } 
  if(( hashTableTwo = malloc(sizeof(struct node) * size))== NULL){
    fprintf(stderr,"Error occured during malloc");
    exit(1);
  }
}
/* this function adds the value to the first hash table using the first hash function.
   It takes in a  string and returns nothing
 */
void addh1(char *key){
  int i;
  struct node *node; // the temp node pointer
  if((node = malloc(sizeof(struct node)))== NULL){
    fprintf(stderr,"Error occured during malloc");
    exit(1);
  }
  i = hash_example_one(key,tSize); // get the index value
  strcpy(node->string,key); // copy the string to the node
  node->next = NULL; // set the next of the node to be null
  // set the next of the node to be whatever hash table one was pointing to then set the current 
  // node to be the first node in the table.
  node->next = hashTableOne[i];
  hashTableOne[i] = node;
}
/* this function adds the value to the second hash table using the secpmd hash function.
   It takes in a  string and returns nothing
*/
void addh2(char *key){
  int i;
  struct node *node; // the temp node pointer
  if((node = malloc(sizeof(struct node)))== NULL){
    fprintf(stderr,"Error occured during malloc");
    exit(1);
  }
  i = hash_example_two(key,tSize); // get the index value
  strcpy(node->string,key); // copy the string to the node
  node->next = NULL; // set the next of the node to be null
  // set the next of the node to be whatever hash table one was pointing to then set the current
  // node to be the first node in the table.
  node->next = hashTableTwo[i];
  hashTableTwo[i] = node;

}
/* The first count Non-Emtpy function. It takes in nothing and returns the counted value */
int countNonEmptyh1(){
  int count = 0; // count to keep track of how many buckets have values
  int i; // index to traverse through the array
  // traverse through the array checking if each bucket is empty, if so increment count
  for(i = 0; i <tSize;i++){
    if((hashTableOne[i]) != NULL){
      count++;
    }
  }
  // printf("%d",count); /* TEST PRINT */
  return count;
}
/* Same function as abouve but for table two using hash two */
int countNonEmptyh2(){
  int count = 0;
  int i;
  for(i = 0; i <tSize;i++){
    if((hashTableTwo[i]) != NULL){
      count++;
    }
  }
  // printf("%d",count); TEST PRINT
  return count;
}
/* Function to count the max length of the lists in the first table. It takes in nothing
   and returns the max value
*/
int maxEntriesh1(){
  int max = 0; // max value is 0 at the start
  int count; // counting variable
  int i; // index to allow traversing the array
  struct node *head; // node pointer to traver the list
  /* we traverse the array in the upper loop. We set the head to be the first node in the table.
     while the first node isnt null we add to count and set the head to be the next node.
     once we reach the point where head is null we compare if count is higher than max and if so
     we set max to be the count. Otherwise we move onto the next index.
  */
  for(i = 0;i < tSize; i++){
    head = hashTableOne[i];
    count = 0;
    while(head != NULL){
      // printf(" Value at %d: %s \n", i,head->string); TEST PRINT
      count++;
      head = head->next;
    }
    if(count > max)
      max = count;
  }
  //printf("%d\n", max); TEST PRINT
  return max;

}
/* Same function as above but we count using the second hash table */
int maxEntriesh2(){
  int max = 0; // max value is 0 at the start
  int count; // counting variable
  int i; // index to allow traversing the array
  struct node *head; // node pointer to traver the list
  /* we traverse the array in the upper loop. We set the head to be the first no\
de in the table.
     while the first node isnt null we add to count and set the head to be the n\
ext node.
     once we reach the point where head is null we compare if count is higher th\
an max and if so
     we set max to be the count. Otherwise we move onto the next index.
  */
  for(i = 0;i < tSize; i++){
    head = hashTableTwo[i];
    count = 0;
    while(head != NULL){
      //printf(" Value at %d: %s \n", i,head->string); TEST PRINT
      count++;
      head = head->next;
    }
    if(count > max)
      max = count;
  }
  // printf("%d\n",max); TEST PRINT
  return max;

}
/* This function will traverse through the list for each index and find the minimum number of nodes in the table are.
   It will not count if a bucket is empty to begin with.
*/
int minEntriesh1(){
  int min = 1; //min value is 1 because we dont count buckets with no nodes.
  int count; // keeps track of the number of nodes
  int i; // index value to traverse the array
  struct node *head; // node pointer to traverse the list
  for(i = 0; i <tSize;i++){
    count = 0; // intialize count to be zero before traversing each list
    if(hashTableOne[i] == NULL){
      break;
    }
    head = hashTableOne[i]; // head points to first node
    while(head != NULL){
      count++;
      head = head->next;
    }
    if(count < min)
      min = count;
  }
  //printf("%d \n", min);/*TEST PRINT*/
  return min;
}
/* Same function as above but with the second table */
int minEntriesh2(){
  int min = 1; //min value is 1 because we dont count buckets with no nodes.
  int count; // keeps track of the number of nodes
  int i; // index value to traverse the array
  struct node *head; // node pointer to traverse the list
  for(i = 0; i <tSize;i++){
    count = 0; // intialize count to be zero before traversing each list
    if(hashTableOne[i] == NULL){
      break;
    }
    head = hashTableOne[i]; // head points to first node
    while(head != NULL){
      count++;
      head = head->next;
    }
    if(count < min)
      min = count;
  }
  //printf("%d \n", min);/* TEST PRINT*/
  return min;
}
double calculateAverageh1(double numLines){
  double average;
  int x = countNonEmptyh1();
  average = numLines/x;
  // printf("%.2f\n",average);/* TEST PRINT */
  return average;
}

double calculateAverageh2(double numLines){
  double average;
  int x = countNonEmptyh2();
  average = numLines/x;
  // printf("% .2f\n",average);/* TEST PRINT */
  return average;
}
int getSize(){

  return tSize;
}
