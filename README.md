Project Overview:
The Airline Reservation System is a software application developed using C++ that allows users to book flights, order food, book taxi services, and manage 
reservations. It features a user-friendly interface for customers and administrators, facilitating seamless interactions for flight reservations and additional services.
The primary objective of this project is to create a comprehensive system that manages flight reservations efficiently while providing additional services like food 
ordering and taxi bookings. The system aims to enhance user experience by offering a robust platform for booking and managing flights.
The primary objective of this project is to create a comprehensive system that manages flight reservations efficiently while providing additional services like food 
ordering and taxi bookings. The system aims to enhance user experience by offering a robust platform for booking and managing flights.
The primary objective of this project is to create a comprehensive system that manages flight reservations efficiently while providing additional services like food 
ordering and taxi bookings. The system aims to enhance user experience by offering a robust platform for booking and managing flights.

System Design
The system is designed using a modular approach with distinct classes handling various functionalities:

Management Class: Initializes and displays the main menu.

Details Class: Manages customer details.

Registration Class: Handles flight bookings, food ordering, taxi services, and other functionalities.

UserAuth Class: Manages user registration and authentication.

Classes and Their Responsibilities:

Management Class: Manages the main menu interface and user navigation.

Details Class: Collects and stores customer details and manages the display of these details.

Registration Class: Handles flight selection, food, and taxi services, and calculates final charges.

User AUTH Class: Manages user authentication, including registration and login processes.

Implementation Details
Header Files and Namespaces:
The project includes several header files for functionalities such as input/output operations, file handling, and string manipulations. The std namespace is used to simplify code.

Core Functions:
main-menu () Function: Displays the login/registration menu and handles user actions.
Details Class Methods: Includes information(), displayPassengerDetails(), saveDetails(), and loadDetails() for managing customer information.
Registration Class Methods: Includes flights(), displayFlightOptions(), food(), taxi(), final(), addFlight(), cancelReservation(), generateBookingID(), and viewAllFlights() for handling reservations and services.
UserAuth Class Methods: Includes registerUser(), loginUser(), userExists(), saveUser(), and getPasswordHash() for user management.
Features
Flight Booking:
Users can select from available flights, book their tickets, and view booking details.

Food Ordering:
Users can order food from a menu and add the cost to their final bill.

Taxi Booking:
Users can book a taxi service for transportation, with the cost included in the final charges.

Reservation Management:
The system allows users to view, cancel, or modify their reservations.

User Authentication:
Users can register and log in to manage their bookings and personal details.

User Interface
Main Menu:
The interface provides options for users to log in, register, or exit the application.

Flight Booking Interface:
Users can view available flights, select a flight, and proceed with booking.

Food and Taxi Booking Interfaces:
These interfaces allow users to order food and book taxis, respectively.

Final Summary:
Displays the total charges and booking details to the user.

File Handling
Customer Details Storage:
Customer details are saved to a file (details.txt) and can be loaded or displayed as needed.

Flight and User Management:
Flight details and user credentials are managed through separate files (flights.txt and users.txt).

Security Considerations
Password Storage:
The current implementation uses a simple placeholder for password hashing. A secure hashing algorithm like bcrypt should be used for a real-world application.
