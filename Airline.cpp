#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>   
#include <sstream> 
#include <iomanip>
using namespace std;


void mainMenu();

// Management class to initialize the main menu
class Management
{
public:
    Management()
    {
        mainMenu();
    }
};

// Details class to manage customer details
class Details
{
public:
    static string name, gender;
    static int CId;
    static int phoneNo;
    static int age;
    static string address;

    void information()
    {
        cout << "\nEnter the Customer ID: ";
        cin >> CId;
        cout << "Enter the name: ";
        cin.ignore(); // To ignore any newline character left in the buffer
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter Address: ";
        cin.ignore(); // To ignore any newline character left in the buffer
        getline(cin, address);
        cout << "Enter Gender (M/F/O): ";
        cin >> gender;
        saveDetails();
        cout << "Your details are saved with us.\n"
             << endl;
    }

    void displayPassengerDetails()
    {
        cout << "\n----- Passenger Details -----" << endl;
        cout << "Customer ID: " << CId << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Gender: " << gender << endl;
        cout << "-----------------------------" << endl;
    }

private:
    void saveDetails()
    {
        ofstream outFile("passenger_details.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << CId << "," << name << "," << age << "," << address << "," << gender << "\n";
            outFile.close();
        }
        else
        {
            cout << "Unable to open file for saving details." << endl;
        }
    }

    void loadDetails()
    {
        ifstream inFile("passenger_details.txt");
        if (inFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open file for loading details." << endl;
        }
    }
};

string Details::name;
string Details::gender;
int Details::CId;
int Details::phoneNo;
int Details::age;
string Details::address;

// Registration class to manage flight booking
class Registration
{
public:
    static string flightChoice;
    static float charges;
    static float foodCharges;
    static float taxiCharges;
    static float totalCharges;

    void flights()
    {
        vector<string> flightNames = {"Mumbai", "Chennai", "Bengaluru", "Delhi", "Ranchi"};
        vector<string> flightDetails[] = {
            {"MUM-498: 08-01-2022 8:00AM 2hrs Rs.5000",
             "MUM-658: 09-01-2022 4:00AM 3hrs Rs.4000",
             "MUM-764: 09-01-2022 11:00AM 1.5hrs Rs.3000"},
            {"CHE-198: 09-01-2022 2:00AM 3hrs Rs.6000",
             "CHE-158: 09-01-2022 6:00AM 3.5hrs Rs.5500",
             "CHE-208: 09-01-2022 11:00AM 3hrs Rs.5000"},
            {"BEN-798: 12-01-2022 10:00AM 4hrs Rs.7000",
             "BEN-658: 13-01-2022 4:00AM 4.5hrs Rs.6500",
             "BEN-764: 14-01-2022 11:00AM 4hrs Rs.6000"},
            {"DEL-567: 10-01-2022 9:00AM 5hrs Rs.8000",
             "DEL-658: 11-01-2022 4:00AM 5.5hrs Rs.7500",
             "DEL-764: 12-01-2022 11:00AM 5hrs Rs.7000"},
            {"RAN-498: 15-01-2022 8:00AM 6hrs Rs.9000",
             "RAN-658: 16-01-2022 4:00AM 6.5hrs Rs.8500",
             "RAN-764: 17-01-2022 11:00AM 6hrs Rs.8000"}};

        cout << "Available flight destinations:\n";
        for (size_t i = 0; i < flightNames.size(); i++)
        {
            cout << (i + 1) << ". " << flightNames[i] << endl;
        }
        cout << "\nEnter the name of the city you want to fly to: ";
        cin.ignore(); // To ignore any newline character left in the buffer
        getline(cin, flightChoice);

        // Convert input to title case for comparison
        transform(flightChoice.begin(), flightChoice.end(), flightChoice.begin(), ::tolower);
        flightChoice[0] = toupper(flightChoice[0]);

        auto it = find(flightNames.begin(), flightNames.end(), flightChoice);
        if (it != flightNames.end())
        {
            size_t index = distance(flightNames.begin(), it);
            displayFlightOptions(flightDetails[index]);
        }
        else
        {
            cout << "Invalid flight destination, shifting to the main menu" << endl;
            mainMenu();
        }
    }

    void displayFlightOptions(vector<string> flights)
    {
        cout << "__________Welcome to " << flightChoice << " Airlines______________\n";
        cout << "Your comfort is our priority. Enjoy the journey!" << endl;
        cout << "Following are the flights:\n";
        for (const auto &flight : flights)
        {
            cout << flight << endl;
        }
        cout << "\nSelect the flight you want to book (by number): ";
        int choice1;
        cin >> choice1;
        if (choice1 >= 1 && choice1 <= flights.size())
        {
            size_t rs_pos = flights[choice1 - 1].find("Rs.");
            if (rs_pos != string::npos)
            {
                charges = stof(flights[choice1 - 1].substr(rs_pos + 3));
                cout << "\nYou have successfully booked the flight " << flights[choice1 - 1].substr(0, flights[choice1 - 1].find(':')) << endl;
            }
            else
            {
                cout << "Error: Unable to find the charges." << endl;
            }
        }
        else
        {
            cout << "Invalid input, shifting to the previous menu" << endl;
            displayFlightOptions(flights); // Retry flight selection
        }
    }

    void food()
    {
        int choice2;
        vector<string> foodItems = {
            "1. Pizza - Rs. 200",
            "2. Burger - Rs. 150",
            "3. Pasta - Rs. 250",
            "4. Sandwich - Rs. 100",
            "5. Salad - Rs. 120",
            "6. Samosa - Rs. 50",
            "7. Coffee - Rs. 80",
            "8. Tea - Rs. 60",
            "9. Juice - Rs. 90",
            "10. Ice Cream - Rs. 70"};

        cout << "Food Menu:\n";
        for (const auto &item : foodItems)
        {
            cout << item << endl;
        }

        cout << "\nEnter the number of the food item you want to order: ";
        cin >> choice2;

        switch (choice2)
        {
        case 1:
            foodCharges = 200;
            break;
        case 2:
            foodCharges = 150;
            break;
        case 3:
            foodCharges = 250;
            break;
        case 4:
            foodCharges = 100;
            break;
        case 5:
            foodCharges = 120;
            break;
        case 6:
            foodCharges = 50;
            break;
        case 7:
            foodCharges = 80;
            break;
        case 8:
            foodCharges = 60;
            break;
        case 9:
            foodCharges = 90;
            break;
        case 10:
            foodCharges = 70;
            break;
        default:
            cout << "Invalid input, no food item selected" << endl;
            foodCharges = 0;
            break;
        }

        cout << "Food item selected. Charges: Rs." << foodCharges << endl;
    }

    void taxi()
    {
        int choice3;
        cout << "\nTaxi Services:\n";
        cout << "1. Service 1 - Rs. 1000\n";
        cout << "2. Service 2 - Rs. 1100\n";
        cout << "3. Service 3 - Rs. 1200\n";

        cout << "\nEnter the number of the taxi service you want to book: ";
        cin >> choice3;

        switch (choice3)
        {
        case 1:
            taxiCharges = 1000;
            break;
        case 2:
            taxiCharges = 1100;
            break;
        case 3:
            taxiCharges = 1200;
            break;
        default:
            cout << "Invalid input, no taxi service selected" << endl;
            taxiCharges = 0;
            break;
        }

        cout << "Taxi service selected. Charges: Rs." << taxiCharges << endl;
    }

    void final()
    {
        totalCharges = charges + foodCharges + taxiCharges;
        cout << "\n----- Final Charges -----" << endl;
        cout << "Flight Charges: Rs." << charges << endl;
        cout << "Food Charges: Rs." << foodCharges << endl;
        cout << "Taxi Charges: Rs." << taxiCharges << endl;
        cout << "--------------------------" << endl;
        cout << "Total Charges: Rs." << totalCharges << endl;
        cout << "Thank you for booking with us!" << endl;
    }
    void addFlight()
    {
        string destination;
        cout << "Enter the city you want to add flights for: ";
        cin.ignore(); // To ignore any newline character left in the buffer
        getline(cin, destination);

        vector<string> newFlightDetails;
        cout << "Enter flight details (format: FlightNo: Date Time Duration Rs.Price). Type 'done' to finish:\n";

        while (true)
        {
            string flightDetail;
            getline(cin, flightDetail);
            if (flightDetail == "done")
            {
                break;
            }
            newFlightDetails.push_back(flightDetail);
        }

        ofstream outFile("flights.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << destination << endl;
            for (const auto &detail : newFlightDetails)
            {
                outFile << detail << endl;
            }
            outFile.close();
            cout << "Flights added successfully!" << endl;
        }
        else
        {
            cout << "Unable to open file for saving flights." << endl;
        }
    }
    void cancelReservation()
    {
        string reservationID;
        cout << "Enter the Reservation ID to cancel: ";
        cin.ignore(); // To ignore any newline character left in the buffer
        getline(cin, reservationID);

        ifstream inFile("reservations.txt");
        ofstream tempFile("temp_reservations.txt");
        bool found = false;

        if (inFile.is_open() && tempFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                if (line.find(reservationID) == string::npos)
                {
                    tempFile << line << endl;
                }
                else
                {
                    found = true;
                }
            }
            inFile.close();
            tempFile.close();
            remove("reservations.txt");
            rename("temp_reservations.txt", "reservations.txt");

            if (found)
            {
                cout << "Reservation canceled successfully!" << endl;
            }
            else
            {
                cout << "Reservation ID not found." << endl;
            }
        }
        else
        {
            cout << "Unable to open file for canceling reservation." << endl;
        }
    }
    void generateBookingID()
    {
        // Seed the random number generator
        srand(time(0));

        // Generate a random number
        int randomNumber = rand() % 10000;

        // Get the current timestamp
        time_t now = time(0);
        tm *ltm = localtime(&now);

        // Create a stringstream to format the booking ID
        stringstream ss;
        ss << "BOOK" << 1900 + ltm->tm_year << setw(2) << setfill('0') << 1 + ltm->tm_mon
           << setw(2) << setfill('0') << ltm->tm_mday
           << setw(4) << setfill('0') << randomNumber;

        // Generate and print the booking ID
        string bookingID = ss.str();
        cout << "Generated Booking ID: " << bookingID << endl;
    }
    void viewAllFlights()
    {
        vector<string> flightNames = {"Mumbai", "Chennai", "Bengaluru", "Delhi", "Ranchi"};
        vector<string> flightDetails[] = {
            {"MUM-498: 08-01-2022 8:00AM 2hrs Rs.5000",
             "MUM-658: 09-01-2022 4:00AM 3hrs Rs.4000",
             "MUM-764: 09-01-2022 11:00AM 1.5hrs Rs.3000"},
            {"CHE-198: 09-01-2022 2:00AM 3hrs Rs.6000",
             "CHE-158: 09-01-2022 6:00AM 3.5hrs Rs.5500",
             "CHE-208: 09-01-2022 11:00AM 3hrs Rs.5000"},
            {"BEN-798: 12-01-2022 10:00AM 4hrs Rs.7000",
             "BEN-658: 13-01-2022 4:00AM 4.5hrs Rs.6500",
             "BEN-764: 14-01-2022 11:00AM 4hrs Rs.6000"},
            {"DEL-567: 10-01-2022 9:00AM 5hrs Rs.8000",
             "DEL-658: 11-01-2022 4:00AM 5.5hrs Rs.7500",
             "DEL-764: 12-01-2022 11:00AM 5hrs Rs.7000"},
            {"RAN-498: 15-01-2022 8:00AM 6hrs Rs.9000",
             "RAN-658: 16-01-2022 4:00AM 6.5hrs Rs.8500",
             "RAN-764: 17-01-2022 11:00AM 6hrs Rs.8000"}};

        cout << "Available flights:\n";
        for (size_t i = 0; i < flightNames.size(); i++)
        {
            cout << "Destination: " << flightNames[i] << endl;
            for (const auto &detail : flightDetails[i])
            {
                cout << "  " << detail << endl;
            }
            cout << endl;
        }
    }
};
class UserAuth
{
public:
    void registerUser();
    bool loginUser();

private:
    bool userExists(const string &username);
    void saveUser(const string &username, const string &password);
    string getPasswordHash(const string &password);
};

// Helper method to check if the user already exists
bool UserAuth::userExists(const string &username)
{
    ifstream file("users.txt");
    string line;
    while (getline(file, line))
    {
        if (line.find(username + ":") == 0)
        {
            return true;
        }
    }
    return false;
}

// Save the user details to a file
void UserAuth::saveUser(const string &username, const string &password)
{
    ofstream file("users.txt", ios::app);
    file << username << ":" << getPasswordHash(password) << endl;
}

// Simple hash function for passwords (not secure for real applications)
string UserAuth::getPasswordHash(const string &password)
{
    string hash = password; // Just a placeholder for demonstration
    return hash;
}

// Register a new user
void UserAuth::registerUser()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    if (userExists(username))
    {
        cout << "User already exists. Please choose a different username." << endl;
        return;
    }
    cout << "Enter password: ";
    cin >> password;
    saveUser(username, password);
    cout << "Registration successful!" << endl;
}

// Login an existing user
bool UserAuth::loginUser()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;
    while (getline(file, line))
    {
        size_t pos = line.find(':');
        string fileUser = line.substr(0, pos);
        string filePass = line.substr(pos + 1);

        if (fileUser == username && filePass == getPasswordHash(password))
        {
            cout << "Login successful!" << endl;
            return true;
        }
    }
    cout << "Invalid username or password." << endl;
    return false;
}
string Registration::flightChoice;
float Registration::charges;
float Registration::foodCharges;
float Registration::taxiCharges;
float Registration::totalCharges;

// Main menu function to handle user actions
void mainMenu()
{
    int choice;
    bool loggedIn = false;
    UserAuth auth;

    while (true)
    {
        if (!loggedIn)
        {
            cout << "\n----- Login/Registration Menu -----" << endl;
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                auth.registerUser();
                break;
            case 2:
                loggedIn = auth.loginUser();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        }
        else
        {
            Registration reg;
            Details details;

            cout << "\n----- Main Menu -----" << endl;
            cout << "1. Register Passenger Details" << endl;
            cout << "2. Book Flight" << endl;
            cout << "3. Order Food" << endl;
            cout << "4. Book Taxi" << endl;
            cout << "5. Finalize Booking" << endl;
            cout << "6. Add Flight" << endl;
            cout << "7. Cancel Reservation" << endl;
            cout << "8. Generate Booking ID" << endl;
            cout << "9. View All Flights" << endl;
            cout << "10.Logout" << endl;
            cout << "11. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                details.information();
                break;
            case 2:
                reg.flights();
                break;
            case 3:
                reg.food();
                break;
            case 4:
                reg.taxi();
                break;
            case 5:
                reg.final();
                break;
            case 6:
                reg.addFlight();
                break;
            case 7:
                reg.cancelReservation();
                break;
            case 8:
                reg.generateBookingID();
                break;
            case 9:
                reg.viewAllFlights();
                break;
            case 10:
                loggedIn = false; // Log out the user
                cout << "Logged out successfully." << endl;
                break;
            case 11:
                cout << "Exiting the program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }
}
int main()
{
    Management management;
    return 0;
}
