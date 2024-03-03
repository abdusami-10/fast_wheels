#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <random>

using namespace std;

class vehicle
{
public:
    char name[50];
    char company[50];
    char model[50];
    char mileage[50];
    char price[50];
    char description[100];
    char sellerName[50];
    char contact[25];
    char fuelType[20];
    char engine[20];
    char rating[2];
    char makeYear[20];
    char availableInCity[20];
    char color[20];
    char engincapacity[20];
    char transmission[20];
    char inpection_date[20];
    char chassis_no[30];
    char registration_no[30];
    char petrol[5];
};

class admin : public vehicle
{
private:
    char username[50], password[50];
    char username_f[50], password_f[50];
    char searchName[50];
    bool found = false;
    char notification[200];
    int line = 1, id;

public:
    void login_admin()
    {
        ifstream file("admin.txt"); // Assuming credentials are stored in a file named "admin.txt"

        string line;

        bool credentialsCorrect = false;

        while (!credentialsCorrect)
        {
            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            string line;
            while (getline(file, line))
            {
                istringstream iss(line);
                char storedUsername[100], storedPassword[100];

                // Read username and password from the file
                iss >> storedUsername >> storedPassword;

                // Compare entered credentials with stored credentials
                if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
                {
                    cout << "Login successful!" << endl;
                    credentialsCorrect = true;
                    menu();
                    break; // Exit the loop if credentials match
                }
            }

            if (!credentialsCorrect)
            {
                cout << "\nInvalid username or password. Please try again." << endl;
                file.clear();            // Clear the error state to allow re-reading the file
                file.seekg(0, ios::beg); // Move the file pointer back to the beginning
            }
        }
    }

    void menu()
    {
        cout << "Welcome back!\n";
        cout << "What do you want to do?\n";
        cout << " 1. Add Vehicle\n 2. Remove Vehicle\n 3. Manage Inspection Requests\n";
        cout << " 4. Add Notification\n 5. Remove Notification\n 6. Logout\n";

        int choice;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addVehicle();
            break;
        case 2:
            removeVehicle();
            break;
        case 3:
            inspection();
            break;
        case 4:
            addnotification();
            break;
        case 5:
            removenotification();
            break;
        }
    }

    void addVehicle()
    {
        ofstream addcar("new_cars.txt", ios::app);

        if (!addcar)
        {
            cout << "FILE NOT FOUND !" << endl;
            return;
        }

        vehicle newVehicle;

        // Input details for the new vehicle
        cout << "Enter Name: ";
        cin.ignore(); // Ignore newline character in the buffer
        cin.getline(newVehicle.name, sizeof(newVehicle.name));

        // Input other details for the new vehicle
        cout << "Enter Company: ";
        cin.getline(newVehicle.company, sizeof(newVehicle.company));

        cout << "Enter Model: ";
        cin.getline(newVehicle.model, sizeof(newVehicle.model));

        cout << "Enter Mileage: ";
        cin.getline(newVehicle.mileage, sizeof(newVehicle.mileage));

        cout << "Enter Price: ";
        cin.getline(newVehicle.price, sizeof(newVehicle.price));

        cout << "Enter Description: ";
        cin.getline(newVehicle.description, sizeof(newVehicle.description));

        cout << "Enter Seller Name: ";
        cin.getline(newVehicle.sellerName, sizeof(newVehicle.sellerName));

        cout << "Enter Contact: ";
        cin.getline(newVehicle.contact, sizeof(newVehicle.contact));

        cout << "Enter Fuel Type: ";
        cin.getline(newVehicle.fuelType, sizeof(newVehicle.fuelType));

        cout << "Enter Engine: ";
        cin.getline(newVehicle.engine, sizeof(newVehicle.engine));

        ratings();

        cout << "Enter Make Year: ";
        cin >> newVehicle.makeYear;

        cout << "Enter Available in City: ";
        cin.ignore(); // Ignore newline character in the buffer
        cin.getline(newVehicle.availableInCity, sizeof(newVehicle.availableInCity));

        cout << "Enter Color: ";
        cin.getline(newVehicle.color, sizeof(newVehicle.color));

        // Write the new vehicle details to the file
        addcar << endl
               << newVehicle.name << " " << newVehicle.company << " " << newVehicle.model << " "
               << newVehicle.mileage << " " << newVehicle.price << " " << newVehicle.description << " "
               << newVehicle.sellerName << " " << newVehicle.contact << " " << newVehicle.fuelType << " "
               << newVehicle.engine << " " << rating << " " << newVehicle.makeYear << " "
               << newVehicle.availableInCity << " " << newVehicle.color << " " << username;

        cout << "Vehicle added successfully!" << endl;

        addcar.close();
    }

    // ... (Previous code)

    void removeVehicle()
    {
        cout << "Enter the name of the vehicle to remove: ";
        cin >> searchName;

        ifstream inFile("new_cars.txt", ios::in);
        ofstream addcar("temp.txt", ios::out);

        if (!inFile || !addcar)
        {
            cerr << "Error opening files for reading or writing!" << endl;
            return;
        }

        while (inFile >> name >> company >> model >> mileage >> price)
        {
            // Read the description until '$' sign
            inFile.ignore();
            inFile.getline(description, sizeof(description), '$');

            // Read the remaining fields
            inFile >> sellerName >> contact >> fuelType >> engine >> rating >> makeYear >> availableInCity >> color;
            // Check if the current line matches the vehicle to be removed
            if (strcmp(searchName, name) == 0)
            {
                cout << "Vehicle found and removed!" << endl;
                found = true;
            }
            else
            {
                // Write the non-matching vehicles to the temporary file
                addcar << name << "\t" << company << "\t" << model << "\t"
                       << mileage << "\t" << price << "\t" << description << "$\t"
                       << sellerName << "\t" << contact << "\t" << fuelType << "\t"
                       << engine << "\t" << rating << "\t" << makeYear << "\t"
                       << availableInCity << "\t" << color << endl;
            }
        }

        // Close the files
        inFile.close();
        addcar.close();

        // Remove the original file
        remove("new_cars.txt");

        // Rename the temporary file to the original file
        rename("temp.txt", "new_cars.txt");

        if (!found)
        {
            cout << "Vehicle not found!" << endl;
        }
    }

    void addnotification()
    {
        ofstream note("notifications.txt", ios::app);

        if (!note.is_open())
        {
            cerr << "Error opening the notification file for writing!" << endl;
            return;
        }
        cout << "Enter the notification: ";
        cin.ignore(); // Ignore newline character in the buffer
        cin.getline(notification, sizeof(notification));
        note << notification << endl;
        cout << "Notification added successfully!" << endl;
        note.close();
    }

    void removenotification()
    {
        found == false;
        ifstream infile("notifications.txt", ios::in);
        ofstream addnote("change.txt", ios::out);

        if (!infile || !addnote)
        {
            cerr << "Error opening files for reading or writing!" << endl;
            return;
        }

        while (infile.getline(notification, sizeof(notification), '\n'))
        {
            cout << line << "\t" << notification << endl;
            line++;
        }

        infile.close();
        ifstream inFile("notifications.txt", ios::in);
        cout << "Enter the ID of the notification you want to remove : ";
        cin >> id;
        line = 1;

        while (inFile.getline(notification, sizeof(notification), '\n'))
        {
            if (line == id)
            {
                cout << "notification found and removed!" << endl;
                found = true;
            }
            else
            {
                addnote << notification << endl;
            }
            line++;
        }

        // Close the files
        inFile.close();
        addnote.close();

        // Remove the original file
        remove("notifications.txt");

        // Rename the temporary file to the original file
        rename("change.txt", "notifications.txt");

        if (!found)
        {
            cout << "notification not found!" << endl;
        }
    }
    void inspection()
    {
        fstream addcar("new_cars.txt", ios::in);
        fstream newinpection("new_car_inpection.txt", ios::app);
        if (!addcar || !newinpection)
        {
            cerr << "Error opening the file for writing and reading!" << endl;
            return;
        }

        while (addcar >> name >> company >> model >> mileage >> price)
        {
            // Read the description until '$' sign
            addcar.ignore();
            addcar.getline(description, sizeof(description), '$');
            // Read the remaining fields
            addcar >> sellerName >> contact >> fuelType >> engine >> rating >> makeYear >> availableInCity >> color;

            cout << "further detail for car : " << name << endl;
            cout << "Enter Engin Capacity: ";
            cin.getline(engincapacity, sizeof(engincapacity));

            cout << "Enter Transmission Type: ";
            cin.getline(transmission, sizeof(transmission));

            cout << "Enter Chassis_no: ";
            cin.getline(chassis_no, sizeof(chassis_no));

            cout << "Enter Inpection_Date: ";
            cin.getline(inpection_date, sizeof(inpection_date));

            cout << "Enter Registration_No: ";
            cin.getline(registration_no, sizeof(registration_no));

            cout << "Enter (yes) if vechile support Petrol else (no) : ";
            cin.getline(petrol, sizeof(petrol));
            ratings();
            cout << "\n\n\\t inpection report for " << name << "\n";
            cout << "Seller Name : " << sellerName << endl
                 << "Engine-capacity : " << engincapacity << endl
                 << "Mileage : " << mileage << endl
                 << "transmission Type : " << transmission << endl
                 << " Inpection_Date : " << inpection_date << endl
                 << " Chassis_no : " << chassis_no << endl
                 << " Engine No : " << engine << endl
                 << " Registration_No : " << registration_no << endl
                 << " Fuel type : " << fuelType << endl
                 << "petrol : " << petrol << endl
                 << " color : " << color << endl
                 << "Location : " << availableInCity << endl
                 << " Registered City : " << availableInCity << endl
                 << " Current city : " << availableInCity << endl
                 << "Description : " << description << endl
                 << "rating : " << rating << endl;
            newinpection << "\n\n\\t inpection report for " << name << "\n";
            newinpection << "Seller Name : " << sellerName << endl
                         << "Engine-capacity : " << engincapacity << endl
                         << "Mileage : " << mileage << endl
                         << "transmission Type : " << transmission << endl
                         << " Inpection_Date : " << inpection_date << endl
                         << " Chassis_no : " << chassis_no << endl
                         << " Engine No : " << engine << endl
                         << " Registration_No : " << registration_no << endl
                         << " Fuel type : " << fuelType << endl
                         << "petrol : " << petrol << endl
                         << " color : " << color << endl
                         << "Location : " << availableInCity << endl
                         << " Registered City : " << availableInCity << endl
                         << " Current city : " << availableInCity << endl
                         << "Description : " << description << endl
                         << "rating : " << rating << endl
                         << "*";
        }
        addcar.close();
        newinpection.close();
    }
    void ratings()
    {
        do
        {
            cout << "enter the rating of the car accourding to the report (1(worst) - 5(best) ) : ";
            cin.getline(rating, sizeof(rating));
        } while (strlen(rating) != 1 || rating[0] < '1' || rating[0] > '5');
    }
};

// int main()
// {
//     admin a;
//     a.inspection();

// };
