#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;

//function for hide password

string getHiddenPassword() {
    const char BACKSPACE = 8;
    const char ENTER = 13;

    string password;
    char ch = ' ';

    while (ch != ENTER) {
        ch = _getch();  // Use _getch() to read a character without echoing it
        if (ch == BACKSPACE) {
            if (!password.empty()) {
                cout << "\b \b";  // Move the cursor back, erase the character, move the cursor back again
                password.erase(password.size() - 1);  // Remove the last character from the string
            }
        } else if (ch != ENTER) {
            cout << '*';
            password += ch;
        }
    }

    return password;
}



// Function to calculate current CGPA

const int MAX_SUBJECTS = 10;
float credits[MAX_SUBJECTS];
float points[MAX_SUBJECTS];

float calculateCGPA() {
    int numOfSubjects;
    do {
        cout << "\nEnter number of subjects (maximum " << MAX_SUBJECTS << "): ";
        cin >> numOfSubjects;
        if (numOfSubjects > MAX_SUBJECTS || numOfSubjects <= 0) {
            cout << "Invalid number of subjects. Please enter a number between 1 to " << MAX_SUBJECTS << ".\n";
        }
    } while (numOfSubjects > MAX_SUBJECTS || numOfSubjects <= 0);


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
            the sum of credits attempted for semester*/
    } else {
        cout << "Invalid input for credits." << endl;
        return -1; // Error code to indicate invalid calculation
    }
}

// Function to calculate whole CGPA for entire semesters

const int MAX_SEM = 7;
float totalCGPA[MAX_SEM];
float CGPA[MAX_SEM];

float calculateWholeCGPA() {
    int numOfSemester;

    do {
        cout << "\nEnter number of semesters (maximum " << MAX_SEM << "): ";
        cin >> numOfSemester;
        if (numOfSemester > MAX_SEM || numOfSemester <= 0) {
            cout << "Invalid number of semester. Please enter a number between 1 and " << MAX_SEM << ".\n";
        }
    } while (numOfSemester > MAX_SEM || numOfSemester <= 0);

    float totalCGPA = 0, CGPA;

    for (int counter = 1; counter <= numOfSemester; counter++) {
        cout << "\nEnter CGPA for semester " << counter << " : ";
        cin >> CGPA;
        if (CGPA < 0 || CGPA > 4) {
            cout << "Invalid CGPA entered for semester " << counter << ". Please enter between 0 and 4." << endl;
            return -1; // Return -1 for invalid CGPA
        }
        totalCGPA += CGPA;
    }

    return totalCGPA / numOfSemester;
}

//data for timetable (course management)

const int num_timeslots=10;
const int num_day=5;

int Time[num_timeslots]={8,9,10,11,12,13,14,15,16,17};
string Day[num_day]={"monday","tuesday","wednesday","thursday","friday"};

//two dimensional array
string activity[num_day][num_timeslots]={

//monday
{"NO CLASS","NO CLASS","NO CLASS","NO CLASS","NO CLASS","NO CLASS","NO CLASS","CSC402","CSC402","NO CLASS"},
//tuesday
{"CSC413","CSC413","CSC413","MAT406","MAT406","MAT406","NO CLASS","NO CLASS","PHI428","PHI428"},
//wednesday
{"CSC429","CSC429","CTU552","CTU552","NO CLASS","NO CLASS","NO CLASS","CSC429","CSC429","CSC413"},
//thursday
{"CSC402","CSC402","CSC402","NO CLASS","NO CLASS","NO CLASS","MAT406","MAT406","MAT406","NO CLASS"},
//friday
{"CTU552","CTU552","NO CLASS","NO CLASS","NO CLASS","NO CLASS","NO CLASS","NO CLASS","NO CLASS","NO CLASS"}
};


int main() {
    int choice;
    string uname,pass, input, passInput;
    bool running=true;

    cout << "Welcome to student hub\n";
    cout << "Reminder: if you are new to this site please register first.\n";

    while (running) {
    	cout << "This program need you to login before continue\n\n";
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
            cout << "\nPlease return to the login menu\n";
            system("pause");
            system("cls");
        } 
		
		else if (choice == 2) {
            cout << "Enter username: ";
            cin >> input;
            cout << "Enter password: ";
            passInput = getHiddenPassword();

            if (input == uname && passInput == pass) {
            	system("cls");
               
               int choice_log;
               
               while(choice_log!=4){
               	cout<<"Welcome back "<<uname<<endl;
               	cout<<"Please select your choice below."<<endl;
               	cout<<"\nCalculate current CGPA [1]"<<endl;
               	cout<<"Calculate CGPA for whole semester [2]"<<endl;
               	cout<<"Course Management [3]"<<endl;
               	cout<<"Exit[4]"<<endl;
               	cout<<"\nEnter choice : ";
               	cin>>choice_log;
               	system("cls");
               	
                if(choice_log==1){
                float cgpa = calculateCGPA();
                if (cgpa != -1) {
                    cout << "Your CGPA is: "<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(2)<< cgpa << endl;
                }
                system("pause");
				system("cls");
			    }
			    
			    else if(choice_log==2){
			    	float result = calculateWholeCGPA();
			    	if(result != -1){
			    		cout<<"Your final CGPA is : "<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(2)<<result<<endl;
					}
					
					system("pause");
					system("cls");
				}
				
				else if(choice_log==3){
					int management;
					
					while(management!=3){
						cout<<"myCourses [1]"<<endl;
						cout<<"Timetable [2]"<<endl;
						cout<<"Exit      [3]"<<endl;
						cout<<"\nEnter choice: ";
						cin>>management;
					    system("cls");
					    
					    if(management==1){
					    //course outline for csc255
					    cout<<"==========================================================="<<endl;
					    cout<<"==                    Courses List                       =="<<endl;
					    cout<<"==========================================================="<<endl;
					    cout<<"==   CSC402  ==  PROGRAMMING 1                           =="<<endl;
					    cout<<"==========================================================="<<endl;
					    cout<<"==   CSC413  ==  INTRODUCTION TO INTERACTIVE MULTIMEDIA  =="<<endl;
					    cout<<"==========================================================="<<endl;
					    cout<<"==   CSC429  ==  COMPUTER ORGANIZATION AND ARCHITECTURE  =="<<endl;
					    cout<<"==========================================================="<<endl;
					    cout<<"==   CTU552  ==  PHILOSOPHY AND CURRENT ISSUES           =="<<endl;
					    cout<<"==========================================================="<<endl;
					    cout<<"==   HBU111  ==  NATIONAL KESATRIA 1                     =="<<endl;
					    cout<<"==========================================================="<<endl;
					    cout<<"==   MAT406  ==  FOUNDATION MATHEMATICS                  =="<<endl;
					    cout<<"==========================================================="<<endl;
					    cout<<"==   PHI428  ==  PHILOSOPHY OF SCIENCE                   =="<<endl;
					    cout<<"==========================================================="<<endl;
					    		
					    system("pause");
					    system("cls");
					    }
							
						
						
						
						else if(management==2){
							//Timetable
							
							int time;
							string day;
							
						    cout<<"Enter time in 24Hrs format (8,9,10,11,12,13,14,15,16,17): ";
						    cin>>time;
							
							cout<<"Enter day (monday,tuesday,wednesday....etc): ";
							cin>>day;
							
							int timeIndex=-1, dayIndex=-1;
							
							for(int i=0; i<num_day; i++){
								if (Day[i]==day){
									dayIndex=i;
									break;
								}
							}
							
							for(int j=0; j<num_timeslots; j++){
								if (Time[j]==time){
									timeIndex=j;
									break;
								}
							}
							
							if(dayIndex==-1 || timeIndex==-1){
								cout<<"invalid time or day"<<endl;
								system("pause");
								system("cls");
							}
							
							cout<<"=================================================================="<<endl;
							cout<<"==                         Time Table                           =="<<endl;
							cout<<"=================================================================="<<endl;
							cout<<"==  Day        == "<<day<<endl;
							cout<<"==  Time       == ("<<time<<":00)Hrs"<<endl;
							cout<<"==  Class      == "<<activity[dayIndex][timeIndex]<<endl;
							cout<<"==  Next Class == "<<activity[dayIndex][timeIndex+1]<<endl;
							cout<<"==================================================================="<<endl;
							cout<<"                         have fun in class                         "<<endl;
							
							system("pause");
							system("cls");
 						}
						
						else if(management==3){
							cout<<"exiting course management...."<<endl;
			    	        system("pause");
			    	        system("cls");
						}
						
						else{
					        cout<<"invalid input.."<<endl;
					        system("pause");
					        system("cls");
			         	}
					}
				}
			    
			    else if(choice_log==4){
			    	cout<<"exiting login menu...."<<endl;
			    	system("pause");
			    	system("cls");
				}
				
				else{
					cout<<"invalid input.."<<endl;
					system("pause");
					system("cls");
				}
			   }
            } 
			
			else {
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
