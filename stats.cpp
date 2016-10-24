/*
 program: Lesson 11 Program 1
 Programmer: Mike Cuddy
 Date: 23 October 2016
 Other: N/A
 */

/*
 
 Explanation: Write a program that can be used to gather statistical data about the number of movies college students see in a month.
 
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//*******************************
//Structures
//*******************************


//*******************************
//Global Variables/constants
//*******************************


//*******************************
//Prototype Functions
//*******************************

void welcome();


//******************************
//Main Function
//******************************

int main(){
    
    //Calling functions which will drive the program
    //welcome();
    
    const int SIZE = 5;
    int nums[SIZE] = {0,1,2,100,154};
    
    //Variables to find the median
    int odd;
    int odd_median;
    
    float num_one;
    float num_two;
    float even_median;
    
    if (SIZE % 2 != 0){
        odd = (SIZE + 1) / 2;
        odd_median = nums[odd - 1];
        cout << odd_median << endl;
    }else if (SIZE % 2 == 0){
        num_one = (SIZE - 1) / 2;
        num_two = ((SIZE - 1) / 2) + 1;
        even_median = (num_one + num_two) / 2;
        cout << even_median << endl;
    }
   


    
    //system("pause"); //This line is for Microsoft Visual users.
    
    return 0;
    
}// End of main function

//******************************
//Functions
//******************************

//This function simply greets the user.
void welcome(){
    cout << "Welcome to movie stats!" << endl;
    cout << "This program will show the user statistical information" << endl;
    cout << "about the number of movies a college student watches per month" << endl;
}//End of welcome function


//This function will calculate the mode in the array.
//void mode(){
//
//    int value;
//    int count = 0;
//    int temp_count = 0;
//    int mode = 0;
//    
//    
//    for (int i = 0; i < SIZE; i++){
//        value = nums[i];
//        temp_count = 0;
//        //cout << value << endl;
//        for (int j = 0; j <SIZE; j++){
//            if (nums[j] == value){
//                temp_count += 1;
//            }
//        }
//        if (temp_count > count ){
//            count = temp_count;
//            mode = value;
//        }
//    }
//    
//    if (count == 1){
//        cout << "There was no mode since no number appeared more than twice." << endl;
//    }else {
//        cout << "The mode was " << mode << endl;
//        cout << "The " << mode << " appeared " << count << " times" << endl;
//    }
//}// End of mode function


//Write a program that can be used to gather statistical data about the number of movies college students see in a month. The program should perform the following steps:
//
//A) Ask the user how many students were surveyed. An array of integers with this
//many elements should then be dynamically allocated.

//B) Allow the user to enter the number of movies each student saw into the array.

//C) Calculate and display the average, median, and mode of the values entered (see below).


//In statistics, when a set of values is sorted in ascending or descending order, its median is the middle value. If the set contains an even number of values, the median is the mean, or average, of the two middle values.

//The mode of a set of values is the value that occurs most often or with the
//greatest frequency.


//Input Validation: Do not accept negative numbers for input.







