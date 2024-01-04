#include <iostream>
#include <string>
using namespace std;

// Function to calculate CGPA

const int MAX_SUBJECTS = 10;
float credits[MAX_SUBJECTS];
float points[MAX_SUBJECTS];
//limit subject to 10

float calculateCGPA() {
    int numOfSubjects;
    do {
        cout << "\nEnter number of subjects (maximum " << MAX_SUBJECTS << "): ";
        cin >> numOfSubjects;
        if (numOfSubjects > MAX_SUBJECTS || numOfSubjects <= 0) {
            cout << "Invalid number of subjects. Please enter a number between 1 and " << MAX_SUBJECTS << ".\n";
        }
    } while (numOfSubjects > MAX_SUBJECTS || numOfSubjects <= 0);
	//indicate the eligibility


    float totalCredits = 0, totalGradePoints = 0;
    for (int i = 0; i < numOfSubjects; i++) {
        // Prompt and store subject information in arrays
        cout << "Enter credit hours for subject " << i + 1 << ": ";
        cin >> credits[i];
        totalCredits += credits[i];

        cout << "Enter point for subject " << i + 1 << ": ";
        cin >> points[i];
        totalGradePoints += credits[i] * points[i];
    }

    if (totalCredits > 0) {
        return totalGradePoints / totalCredits;
         /*CGPA is determined by dividing sum of all Quality Points (credit hours * grade point) earned by 
            the sum of credits attempted for semesters*/
    } else {
        cout << "Invalid input for credits." << endl;
        return -1; // Error code to indicate invalid calculation
    }
}

int main() {
    int choice;
    string uname,pass, input, passInput;
    bool running=true;

    cout << "Welcome to student hub\n";
    cout << "Reminder: if you are new to this site please register first.\n";

    while (running) {
    	cout << "This program need you to login before calculating CGPA\n\n";
        cout << "Register[1]" << endl;
        cout << "Login[2]" << endl;
        cout << "About us[3]" << endl;
        cout << "Contact[4]" << endl;
        cout << "Exit[5]" << endl;
        cout << "\nMake your choice: ";
        cin >> choice;
        system("cls");

        if (choice == 1) {
            
            cout << "\nEnter username: ";
            cin >> uname;

            do {
                cout << "Enter password: ";
                cin >> pass;
                cout << "Confirm password: ";
                cin >> passInput;
                if (pass != passInput) {
                    cout << "Passwords do not match. Please try again." << endl;
                }
            } while (pass != passInput);

            cout << "\nRegistration successful!";
            cout<<"\nPlease return to login menu\n";
            system("pause");
            system("cls");
        } else if (choice == 2) {
            cout << "Enter username: ";
            cin >> input;
            cout << "Enter password: ";
            cin >> passInput;

            if (input == uname && passInput == pass) {
            	system("cls");
                cout << "Welcome back, " << uname << "." << endl;
                float cgpa = calculateCGPA();
                if (cgpa != -1) {
                    cout << "Your CGPA is: " << cgpa << endl;
                }
                break; // Exit the loop after successful login and CGPA calculation
            } else {
                cout << "Either username or password is incorrect." << endl;
                system("pause");
                system("cls");
            }
        } 
		
		else if (choice == 3) {
            cout<< "Shout out to members of team ";
            cout<<"\n\n\nMuhammad Hafiz Izzuddin Bin Elias       2023436426";
            cout<<"\nMuhammad Alif Hakimi Bin Mohd Ali       2023657162";
            cout<<"\nMuhammad Hafiz Bin Ramli                2023492486";
            cout<<"\nMuhammad Hanif Najmi Bin Mohd Hazrol    2023858778";
            // Display members name
            
            cout<<"\n\n\nWe are group1 for assignment CSC402."<<endl;
            cout<<"This program is combination of login and registration"<<endl;
            cout<<"with a function of calculating CGPA for student.\n\n";
            system("pause");
            system("cls");
        } 
		
		else if (choice == 4) {
            cout << "If you find any bug or vulnerability please let us know." << endl;
            cout<<"No flooding on this program. If we find you trying to\n";
            cout<<"harm this program we will kick you .\n\n";
            cout<<"core admin      : webmaster@gmail.com"<<endl;
            cout<<"customer service: supporteam@gmail.com"<<endl;
            cout<<"24/7 careline   : +60422222222\n\n";
            // Display contact information
            system("pause");
            system("cls");
            
        }
        
        else if(choice == 5){
        	cout<<"Exiting program...."<<endl;
        	running=false;
		}
        
		
		else{
			cout << "Invalid choice. Please enter a valid option." << endl;
            system("pause");
            system("cls");
		}
    }

    
    system("pause");
}
