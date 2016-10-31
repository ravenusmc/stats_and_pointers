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
//Prototype Functions
//*******************************

void welcome();
void numMovies(int *, int);
void sortArray(int *, int);
double getAverage(int *, int);
double getMode(int *, int);
double getMedian(int *, int);
void displayData(double, double, double);


//******************************
//Main Function
//******************************

int main(){
    
    //Creating variables
    int *survey, students;
    double average, median, mode;
    
    //This function will welcome the user.
    welcome();
    
    // This line will get the number of students surveyed for the size of the array.
    cout << "Please enter the number of students surveyed: " << endl;
    cin  >> students;
    while (!(students > 0)){
        cout << "The number of students must be positive!" << endl;
        cin  >> students;
    }
    
    //Creating the array based on the size of the students
    survey = new int[students];
    
    //These functions will basically drive the program.
    numMovies(survey, students);
    sortArray(survey, students);
    average = getAverage(survey, students);
    mode = getMode(survey, students);
    median = getMedian(survey, students);
    
    displayData(average, mode, median);
    
    //Destroying the dynamically allocated memory
    delete [] survey;
    survey = nullptr;
    
    system("pause"); //This line is for Microsoft Visual users.
    
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

//This function will get the number of movies that each student watched;
void numMovies(int *array, int size) {
    
    
    cout << "Please input the number of movies each student watched: " << endl;
    //This for loop will allow the user to enter in the number of movies that each student watched.
    //The information will be inputted into an array.
    for (int i = 0; i < size; i++){
        cout << "student " << (i + 1) << ": ";
        cin >> array[i];
        //Validation check to ensure that values below zero are not entered.
        while ( array[i]  < 0 ){
            cout << "value cannot be below one!" << endl;
            cout << "student " << (i + 1) << ": ";
            cin >> array[i];
        }
    }

}//End of numMovies function

//This function will sort the array will will be helpful down the line for the statistical aspects
void sortArray(int *array, int size){
    
    bool swap;
    int temp;
    
    //This do loop will sort the array.
    do
    {
        swap = false;
        for (int count = 0; count < (size -1 ); count++ ){
            if (array[count] > array[count + 1]){
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
            }
        }
    }while (swap);

}//End of sortArray function.

//This function will get the average of the array
double getAverage(int *array, int size){
    
    double avg;
    double total = 0;
    
    //The for loop gets the total of all the values in the array.
    for (int i = 0; i < size; i++){
        total += *(array + i);
    }

    //The total is then divided by the size of the array to get the average.
    avg = total /size;

    //The average is then returned.
    return avg;

}//Enf of getAverage function


//This function will calculate the mode in the array.
double getMode(int *array, int size){

    int value;
    int count = 0;
    int temp_count = 0;
    int mode = 0;
    
    //These two for loops will go through the array looking for the mode. The first for loop starts
    //at the array's first position while the second for loop will take every value in the array and
    //compare it to every other value. If a match is found the counter will increase by one.
    for (int i = 0; i < size; i++){
        value = array[i];
        temp_count = 0;
        for (int j = 0; j < size; j++){
            if (array[j] == value){
                temp_count += 1;
            }
        }
        if (temp_count > count ){
            count = temp_count;
            mode = value;
        }
    }
    
    //I have included this check because I want to alert the user to the fact that there is no
    //mode if the count is equal to one. This means, that each number only appears once.
    if (count == 1){
        mode = -99;
    }
    
    return mode;
    
} // End of mode function

//This function will get the median from the data.
double getMedian(int *array, int size){

    
    int middle = (size - 1 ) / 2;
    int num_one, num_two;
    double Median;
    //I use these variables just to convert some values to a double to get a precise
    //average.
    double convert_one, convert_two;
    
    if (size % 2 == 0){
        num_one = (size / 2) - 1;
        num_two = ((size - 1) / 2) + 1;
        convert_one = array[num_one];
        convert_two = array[num_two];
        Median = (convert_one + convert_two) / 2;
        cout << Median << endl;
    }else {
        Median = *(array + middle);
    }
    
    return Median;

    
}//End of median function

//This function will display the average, mode and median.
void displayData(double avg, double mode, double med){
    
    cout << "Here is the results of the data: " << endl;
    cout << "The average was: " << avg << endl;
    cout << "The median was: " << med << endl;
    if (mode == -99){
            cout << "There was no mode since every number appeared only once." << endl;
    }else {
        cout << "The mode was " << mode << endl;
    }
    
}//End of displayData function






