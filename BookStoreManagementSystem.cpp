// Library Header Files
// Preprocessor
#include <iostream>
#include <iomanip> // This header contain function setw and setprecision
#include <stdlib.h> // Add header for function clear screen
#include <unistd.h> // Add header for sleep
#include <ctime> // This header use to get date and time information
#include <windows.h>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;


// Time generator
// Time_t is a data type that represent time
// Time(0)is a function that return the current time in second.
time_t now =time(0);
char*dt =ctime(&now);

// Global Variable Definition
const int Max_Books  =100;
int numAttempt =0;
const int Max_numAttempt=3;

// Global Variable Declaration
double totalEarning;

// Store many variables with different data types in one place called struct
// Declare a structure named "Book"
struct Book
{
    string title;
    double purchasePrice;
    double sellingPrice;
    double quantityPurchased;
    double quantitySold;
    double quantityInStock;
    double earning;
    double totalEarning;
};

// Store many variables with different data types in one place called struct
// Declare a structure named "Book"
void mainScreen(int &numAttempt);
void numberBooks(Book books[], int &numBooks);
void inputBooks(Book books[], int &numBooks);
void booksInfo(Book books[], int &numBooks);
void sortBookBe(Book books[],int &numBooks);
void sortBookQs(Book books[],int &numBooks);
void bookEarning(Book books[],int numBooks);
void topSales(Book books[], int &numBooks);
void table(const Book books[],int numBooks);
void exitProgram();

// Main function
int main ()
{
    // Declarations
    int num;
    int numBooks;

    // Initializations
    Book books[Max_Books];
    int numAttempt =0;
    const int Max_numAttempt=3;

    mainScreen(numAttempt); // Call function to display main screen

    // Check if number of attempts have exceeded the max number of attempts which is 3 times
    if(numAttempt >=Max_numAttempt) // If number or attempts more than 3 times
    {
    cout <<endl;
    cout << "  \033[31mYou have reached maximum attempts!\033[0m"<<endl;// Print message (red colour)
    sleep(3); // Make program wait 3 second before showing next print function
    system("cls"); // Clear screen
    exitProgram(); // Function call to display exit program
    return 0;
    }
    else
    {
    cout << ""<<endl;
    }
    numberBooks(books,numBooks); // Function call to numberBooks screen
    return 0;
}

// Function to display Main Screen
void mainScreen(int &numAttempt)
{
    // Declarations
    string password;
    int numBooks;
    Book books[Max_Books];

    // Variable declaration, initialization
    const int Max_numAttempt=3;

    // Clear Screen
    system ("cls");

    // Print Main Menu
    cout << "  System Time: " <<dt<<endl;// Show the current time
    cout <<endl;
    cout << "============================================================"<<endl;
    cout << "                Bookstore Management System       " <<endl;
    cout << "============================================================"<<endl;
    sleep(1);// Make program wait 1 second before showing next print function
    cout <<endl;
    cout << "  Welcome to " <<  "\033[33m4U Bookstore Management System!\033[0m"<<endl;
    cout <<endl;
    sleep(1);
    cout << "  In order to protect "<< "\033[33mthe privacy of our bookstore\033[0m" <<endl;
    cout <<endl;
    sleep(1);
    cout << "  You need to" <<"\033[33m key in the password\033[0m" << " to log in our main system."<<endl;
    sleep(1);
    cout <<endl;
    cout << "  \033[33mYou only have 3 chances to enter the correct password!\033[0m"<<endl;
    sleep(1);
    cout <<endl;

    // Ask user to input password
    do
    {
    cout <<endl;
    cout << "  Please enter the password: ";
    cin >>password;// Store user input in the variable 'password'

    // Check password correct or not
    if(password == "999") // If user entered correct password '999'
    {
    sleep(1);
    cout <<endl;
    cout << "  \033[32mCorrect Password! Loading to Input Book Page... Please be patient!\033[0m"<<endl; // ‘\033[32m’ is green colour code.
    sleep(3); // Make program wait 3 second before showing next print function
    break; // Exit loop if password entered is correct
    }
    // If user input incorrect password
    else
    {
        cout << "  \033[31mWrong password! Please key in the correct password!\033[0m" <<endl;// '\033[31m' is red colour code. '\033[0m' is return colour code.
        sleep(2); // Make program wait 2 second before showing next print function
        numAttempt++; // numAttempt + 1
    }
    // If user input incorrect password 3 times, program will stop
    if(numAttempt >=Max_numAttempt)
    {
    cout<<endl;
    return;
    }
    }while(true);

}
void numberBooks(Book books[], int &numBooks)
{
    int num;
    system ("cls");
    cout << "                         Book Data                          " <<endl;
    cout << "============================================================"<<endl;
    cout <<endl;
    do
    {
        sleep(1);
        // Ask user to key in the number of book that want store
        cout <<  "  Enter the" << " \033[33mnumber\033[0m"<< " of the books: ";

            // If user key in the number below or equal 0, more that 100, or key in alphabet
            while(!(cin>>num) ||num<=0 ||num>100)
            {
            // Display the message "Invalid input" with red colour
            cout << "  \033[31mInvalid input! Please enter the number between 1-100!\033[0m" <<endl;
            cout <<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            // Ask user to key in again
            cout <<  "  Enter the" << " \033[33mnumber\033[0m"<< " of the books: ";
            }

        cout <<endl;
        cout <<"\033[33m  " << num << "\033[0m" << " book will be input."<<endl;
        sleep(3);
        system ("cls");

    }while(num<=0 || num>100);
    numBooks=num;
    inputBooks(books,numBooks); // Function call to input books screen
}
void inputBooks(Book books[], int &numBooks)
{

    char choice;

    // Loop
    for (int i=0;i<numBooks;i++)
    {
        cout <<endl;
        cout << "                           Book    " <<i+1<<endl;
        cout << "============================================================" <<endl;
        cout << "  Title: ";
        cin.ignore();//discard character from the input buffer
        getline(cin,books[i].title);
        cout <<endl;
    do{
        // Ask user to input purchase price of the book
        cout << "  Purchase Price (RM): ";
        cin >> books[i].purchasePrice;

        // Make sure the user doesnt input invalid purchase price
        if (books[i].purchasePrice <=0)
        {
            // Print Error message (red colour)
            cout <<"  \033[31mPurchase Price cannot be 0 or below 0. Please type again! \033[0m"<<endl;
            sleep(2);
            cout <<endl;
        }
    }while(books[i].purchasePrice <=0);
        cout <<endl;

    // Ask user to input valid Book Selling Price. (Will keep asking the user to enter a valid input if the initial input is invalid
    do{
        // Ask user to input the book's selling price
        cout << "  Selling Price (RM): ";
        cin >>books[i].sellingPrice; // Store the book's selling price to the data element (sellingPrice)

       // Check whether user entered an invalid selling price (less than or equal to 0)
        if (books[i].sellingPrice <=0)
        {
            // Print Error message (red colour)
            cout << "  \033[31mSelling Price cannot be 0 or below 0. Please try again!\033[0m" <<endl;
            sleep(2);
            cout <<endl;
        }
        // Check whether user entered an invalid selling price (less than purchase price)
        else if(books[i].sellingPrice <books[i].purchasePrice)
        {
            cout<<endl;
            sleep(1);
            cout << "  Friendly remainder, selling price is " << "\033[33mless than\033[0m" << " purchase price."<<endl; // Remind user
            cout << endl;
            sleep(1);
            cout << "  Press "<< "\033[32mY\033[0m" << " to"<< "\033[33m continue\033[0m" << " or press "<< "\033[32mN\033[0m" << " to key in the " <<"\033[33mselling price again.\033[0m" <<endl;
            cout <<endl;
            sleep(1);

             // Ask user to input whether he wants to continue (Y)/ reenter selling price (N)
            cout << "  Enter the choice (Y/N): ";
            cin >>choice;

            // Check whether user input an invalid input
            while(choice!='y'&& choice!= 'n')
            {
                cout <<endl;
                cout << "  \033[31mInvalid choice. \033[0m" <<"Please enter "<< "\033[33mY\033[0m " << "or "<< "\033[33mN\033[0m: ";
                cin >>choice;
            }

            // If user choose to reenter selling price
            if(choice=='n')
            {
                cout <<endl;
                // Ask user to input the new selling price and store the value to the Book struct element 'sellingPrice'
                cout << "  Selling price (RM): ";
                cin>>books[i].sellingPrice;
            }
        }
        else
        {
            // User entered correct input, exit loop
            break;
        }


}while (books[i].sellingPrice<=0);
        cout <<endl;

    // Ask user to input valid quantity of books purchased. (Will keep asking the user to enter a valid input if the initial input is invalid)
    do{
        // Ask user to input quantity purchased and store the value to the Book struct element 'quantityPurchased'
        cout << "  Quantity Purchased: ";
        cin >>books[i].quantityPurchased;

        // Check whether user entered an invalid quantity (less than or equal to 0)
        if (books[i].quantityPurchased<=0)
        {
            // Print Error message (red colour)
            cout << "  \033[31mQuantity Purchased cannot be 0 or below 0. Please try again!\033[0m"<<endl;
            sleep(2);
            cout <<endl;
        }
    }while(books[i].quantityPurchased<=0); // Keep asking user to enter input if he enters an invalid number (0 or less than 0)
        cout <<endl;

    // Ask user to input valid Book Quantity Sold. (Will keep asking the user to enter a valid input if the initial input is invalid)
    do{
        // Ask user to input Quantity Sold and store the value to the Book struct element 'quantitySold'
        cout << "  Quantity Sold: ";
        cin >>books[i].quantitySold;

        // Check if user entered incorrect input (less than 0)
        if(books[i].quantitySold <0)
        {
            // Print Error message (red colour)
            cout << "  \033[31mQuantity Sold cannot be 0 or below 0.Please try again!\033[0m" <<endl;
            sleep(2);
            cout <<endl;
        }

        // Check if user entered incorrect input (more than quantity purchased)
        else if(books[i].quantitySold >books[i].quantityPurchased)
        {
            // Print Error message (red colour)
            cout << "  \033[31mQuantity Sold cannot be greater than Quantity Purchased.Please try again!\033[0m" <<endl;
            sleep(2);
            cout <<endl;
        }
    }while (books[i].quantitySold<0 || books[i].quantitySold >books[i].quantityPurchased);

    // Calculate quantity in stock
    books[i].quantityInStock = books[i].quantityPurchased - books[i].quantitySold;

    // Calculate profit per book
    books[i].earning = (books[i].sellingPrice - books[i].purchasePrice)*books[i].quantitySold;

    // Calculate total earning
    totalEarning+=books[i].earning;
    }
    system ("cls");
    booksInfo(books,numBooks); // Function call to display book info screen
}

// Function sort book (arrange by book earning)
void sortBookBe(Book books[],int &numBooks)
{
    // Sort book from lowest earning to highest earning
    for (int i=0;i<numBooks-1; i++)
    {
        for (int j=0;j<numBooks-i-1;j++)
        {
            Book tmp;
            // Checks if the next book in the array has lower earning than the previous book.
            if (books[j].earning > books[j+1].earning)
            {
                // Assigns this temporary variable to be equal to its predecessor's value (which will make room for another book).
                tmp = books[j];
                // The function then reassigns the next book in the array 1 space to the right in the array (because it has higher earning)
                books[j] = books[j+1];
                // The function assigns that new value of that new temp variable back into place as well as assigning it back into place.
                books[j+1] =tmp;
            }
        }
    }
    bookEarning(books,numBooks); // Function call to book earning screen
}

// Function sort book (arrange by quantity sold)
void sortBookQs(Book books[], int &numBooks)
{
    // Sort book from the highest quantity sold to lowest
    for(int i=0;i<numBooks-1;i++)
    {
        for(int j=0;j<numBooks-i-1;j++)
        {
            Book tmp;
            // Checks if the next book in the array has higher quantity sold than the previous book.
            if (books[j].quantitySold<books[j+1].quantitySold)
            {
                tmp=books[j+1];
                books[j+1]=books[j];
                books[j]=tmp;
            }
        }
    }
    topSales(books,numBooks); //  Function call to display top Sales screen
}

// Function to display the books info
void booksInfo(Book books[], int &numBooks)
{
    cout <<endl;
    //Loop
    for(int i=0;i<numBooks;i++)
    {
    cout << "                 Book " << i+1<< " Information:"            <<endl;
    cout << "============================================================"<<endl;
    cout <<endl;
    cout << "  Title: "<< "\033[33m"<<books[i].title<< "\033[0m"<<endl; // Print title
    cout << "  Purchase Price (RM): "<< "\033[33m"<< books[i].purchasePrice<< "\033[0m"<<endl; // Print purchase price
    cout << "  Selling Price (RM): "<< "\033[33m"<<books[i].sellingPrice<< "\033[0m"<<endl; // Print selling price
    cout << "  Quantity Purchased: "<< "\033[33m"<<books[i].quantityPurchased<< "\033[0m"<<endl; // Print quantity purchased
    cout << "  Quantity Sold: "<< "\033[33m"<<books[i].quantitySold<< "\033[0m"<<endl; // Print quantity sold
    cout <<endl;
    sleep(1);
    }
    // Let user have time to read the detail of books. Program stop until user press enter.
    cout << "  Press Enter to continue..."<<endl;
    cin.get();
    cin.ignore();
    cout << "  Pressed Enter. Continuing with the program..."<<endl;
    sleep(2);
    system("cls");
    cout <<endl;
    sortBookBe(books,numBooks); // Function call to sort book
}

// Function to display earning for each book from highest to lowest
void bookEarning(Book books[],int numBooks)
{
    cout << "           Earning for each book and total earning          "<<endl;
    cout << "============================================================" <<endl;
    cout <<endl;

    // Loop
    for (int i=0;i<numBooks;i++)
    {
        cout << "  Earning for " << "\033[33m"<< books[i].title << "\033[0m" << " is RM "<< "\033[33m"<<books[i].earning <<"\033[0m" <<endl;
        cout <<endl;
        sleep(1);
    }
    cout <<endl;

    // Array
    cout << "  Array contains... ";
    for(int i=0;i<numBooks;i++)
    {
        cout <<"\033[32m"<< books[i].earning <<" "<<"\033[0m";
    }
    cout <<endl;
    cout <<endl;
    // Display total earning
    cout << "  Total earning is "<< "\033[32mRM "<< totalEarning<<"\033[0m"<<endl;
    cout <<endl;
    // Let user have time to read the detail of books. Program stop until user press enter.
    cout << "  Press Enter to continue..."<<endl;
    cin.get();
    cin.ignore();
    cout << "  Pressed Enter. Continuing with the program..."<<endl;
    sleep(2);
    sortBookQs(books,numBooks); // Function call to sort book
}

// Function to display the quantity sold for each book from highest to lowest
void topSales(Book books[], int &numBooks)
{
    int i;
    system("cls");
    cout << "                        Best Selling                        "<<endl;
    cout << "============================================================" <<endl;
    cout <<endl;

    // Loop
    for (int i=0;i<numBooks;i++)
    {
         cout << "  Selling for " << "\033[33m"<< books[i].title << "\033[0m" << " is "<< "\033[33m"<<books[i].quantitySold <<"\033[0m" <<endl;
         cout <<endl;
         sleep(1);
    }
    cout <<endl;

    // Array
    cout << "  Array contains... ";
    for(int i=0;i<numBooks;i++)
    {
        cout <<"\033[32m"<< books[i].quantitySold<<" " <<"\033[0m";
    }
    cout <<endl<<endl;
    // Let user have time to read the detail of books. Program stop until user press enter.
    cout << "  Press Enter to continue..."<<endl;
    cin.get();
    cin.ignore();
    cout << "  Pressed Enter. Continuing with the program..."<<endl;
    sleep(2);
    table(books,numBooks); // Function call to display table screen
}

// Function to display a table of all book details in array
void table(const Book books[],int numBooks)
{
    system ("cls");
    cout << "                          Book Table                        "<<endl;
    cout << "============================================================"<<endl;
    cout <<endl;
    cout << "  The descending arrangement of book sales"<<endl;
    cout <<endl;
    sleep(1);
    cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "|"<<"\033[33m       Title      \033[0m"  << "|"<<"\033[33m Purchase Price (RM) \033[0m"<< "|"<<"\033[33m Selling Price (RM) \033[0m" << "|"<<"\033[33m Quantity Purchased \033[0m" << "|"<<"\033[33m Quantity Sold "<< "|"<<"\033[33m Quantity In Stock\033[0m "<<"|"<<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;

    // Loop
    for (int i=0;i<numBooks;i++)
    {
        cout << "|  "<<setw(14)<< books[i].title << "  |       "; // Print title
        cout << fixed << setprecision(2) << left << setw(14) << books[i].purchasePrice << "|        "; // Print purchase price
        cout << fixed << setprecision(2) << left << setw(12) << books[i].sellingPrice << "|       "; // Print selling price
        cout << fixed<< setprecision(0)<< setw(13) << books[i].quantityPurchased << "|      ";
        cout << left << setw(9) << books[i].quantitySold << "|       "; // Print quantity sold
        cout << left << setw(12) << books[i].quantityInStock << "| " ; // Print quantity in stock
        cout << "-----------------------------------------------------------------------------------------------------------------------" <<endl;
    }
    cout <<endl;
    sleep(1);
    cout <<endl;
    // Display total earning
    cout << "  Total earning is "<< "\033[32mRM "<< totalEarning<<"\033[0m"<<endl;
    cout <<endl;
    // Let user have time to read the detail of books. Program stop until user press enter.
    cout << "  Press Enter to continue..."<<endl;
    cin.get();
    cin.ignore();
    cout << "  Pressed Enter. Continuing with the program..."<<endl;
    exitProgram(); // Function call to exit program screen
}

// Function exit program screen
void exitProgram()
{

    system ("cls");
    SetConsoleOutputCP(CP_UTF8); //Use to put emoji
    cout <<endl;
    cout << "  Exiting... please don't press any key"<<endl;
    cout << "[☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐]0%";
    sleep(1);

    system("cls");
    cout <<endl;
    cout << "  Exiting... please don't press any key"<<endl;
    cout << "[■■■■■■■■■■■■■☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐] 25%";
    sleep(1);

    system("cls");
    cout <<endl;
    cout << "  Exiting... please don't press any key"<<endl;
    cout << "[■■■■■■■■■■■■■■■■■■■■■■■■■☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐☐] 50%";
    sleep(1);

    system("cls");
    cout <<endl;
    cout << "  Exiting... please don't press any key"<<endl;
    cout << "[■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■☐☐☐☐☐☐☐☐☐☐☐☐☐] 75%";
    sleep(1);

    system("cls");
    cout <<endl;
    cout << "  Exiting.. please don't press any key"<<endl;
    cout << "[■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■] 100%" <<endl;
    sleep(1);
    cout <<endl<<endl;
    cout << "  Exiting the system successfully!!"<<endl;
}

