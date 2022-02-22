// for built-in functions
#include <stdio.h>
// for rand, srand
#include <stdlib.h>
// in order to display different numbers everytime we run the code for random functions
#include <time.h>
// for the program to sleep for few moments.
#include <windows.h>

// main function
int main()
{
  // calling the user function
  user();

  // declaring variables and arrays
  int number_faces, number_throws, roll[500], occurences[25];

  // prompting user to enter a value for number_faces
  printf("Enter a value for number of faces: ");
  //storing the value entered by the user in the variable number_faces
  scanf("%d", &number_faces);

  //while loop for checking if the parameters are respected
  while(number_faces<2 || number_faces>24)
  {
    // displaying an error message if the parameters are not respected
    printf("The value entered is out of range. Kindly enter a number between 1 and 25.");
    // prompting user to enter a value for number_faces
    printf("\nEnter another value for number of faces: ");
    //storing the value entered by the user in the variable number_faces
    scanf("%d", &number_faces);
  }// end of while loop

  // prompting user to enter a value for number_throws
  printf("Enter a value for number of throws: ");
  //storing the value entered by the user in the variable number_throws
  scanf("%d", &number_throws);

  // while loop
  while(number_throws<2 || number_throws>499)
  {
    printf("The value entered is out of range. Kindly enter a number between 1 and 500.");
    printf("\nEnter another value for number of throws: ");
    scanf("%d", &number_throws);
  }// end of while loop


  printf("\nGenerating Throws:\n");
  // calling the loader function
  loader();
  // displaying the generated throws
  printf("Generated Throws:\n");
  // the program will sleep for 1 second
  sleep(1);
  // to display different numbers everytime we run the code for random functions
  srand(time(NULL));
  // calling the dice_roll function
  dice_roll(roll,number_throws,number_faces);
  // calling the display function
  display(roll,number_throws);

  printf("\nCalculating the occurences:\n");
  sleep(1);
  // calling the loader function
  loader();
  // displaying the occurence
  printf("Occurences:\n");
  // calling the ocurrence_dice function
  occurence_dice(occurences,roll,number_faces,number_throws);

}

// user function which will be called in the main function
void user(){
  // declaring user_name as string
  char user_name[25];
  // prompting user to enter his/her name
  printf("Kindly enter your name: ");
  //storing the value entered by the user in the variable user_name
  scanf("%s",user_name);

  // displaying a welcome message + adding user name
  printf("\n\t\t\t\t\t Hello, %s. Welcome to dice rolling game. Let's start.\n",user_name);
}// end of user function

// loader function which will be called in the main function
void loader(){
  //declaring variable
  int index;

  // displaying the message for loading before the progress bar
  printf("\n\n\t\t\t\t\tPlease Wait.....Loading");
  printf("\n\n");

  // for loop for the progress bar
  for (index=0;index<100;index++)
  {
    // the program will sleep for 12 milliseconds
    Sleep(12);
    // display the progress bar with the type of character:219
    printf("%c",219);
  }// end of for loop

  // displaying a message once the loading process is done
  printf("\n\n\t\t\t\t\tSuccessfully Loaded!\n");
}// end of loader function

// function to generate random number
void dice_roll(int roll[],int number_throws,int number_faces){
  // declaring variable
    int index;
    // for loop to generate random numbers
    for (index = 0 ; index < number_throws; index++)
    {
      // generating the number of faces from 1 to number of faces
      roll[index] = (rand() % number_faces) +1;
    }// end of for loop
}// end of dice_roll function

// function to display the generated throws
void display(int roll[],int number_throws){
  // declaring variable
  int index;
  // for loop
  for (index = 0 ; index < number_throws; index++)
  {
    // displaying the generated throws
    printf("%d\n", roll[index]);
  }// for loop
}// end of display function

// function to calculate the occurence
void occurence_dice(float occurences[],int roll[],int number_faces,int number_throws){
  // declaring the variables
  int index,j, count;
  float percentage;

  // for loop for the occurence
  for(index=0;index<number_faces;index++)
  {
    // initializing count
    count=0;

    // for loop to keep track of occurence
    for(j=0;j<number_throws;j++)
    {
      if(index+1==roll[j])
      count++;
    }
    occurences[index]=count;
  }
  // for loop for calculating the percentages of occurences
  for (j=0;j<number_faces; j++)
  {
    // calculating the percentage of occurences
    percentage=(occurences[j]/(float)number_throws)*100;
    // displaying the percentages of occurences
    printf("Occurence of %d: %.2f \n",j+1, percentage);
  }
}// end of occurence_dice function
