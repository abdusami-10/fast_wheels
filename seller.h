#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <random>

using namespace std;
class seller_vehicle
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
    char AvailableInCity[20];
    char color[20];
    char availableInCity[50];
};
class seller : public seller_vehicle
{

private:
    char username[50], password[50];
    char username_f[50], password_f[50];
    char searchName[50];
    bool found = false;
    char notification[200];
    int line = 1, id;

public:
    void register_seller()
    {
        cout << "Enter the username: ";
        cin >> username;
        cout << "Enter the password: ";
        cin >> password;

        ofstream file("seller.txt", ios::app);
        if (file.is_open())
        {

            file << endl;
            file << username << " " << password;
            cout << "regestred successfully \n";
            cout << "now please login \n";
            file.close();
            login_seller();
        }
        else
        {
            cout << "File not created!";
        }
    }

    void login_seller()
    {
        ifstream file("seller.txt");

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
                istringstream read(line);
                char storedUsername[100], storedPassword[100];

                // Read username and password from the file
                read >> storedUsername >> storedPassword;

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

    /*.............................................*/
    /*.............................................*/
    /*.............................................*/
    /*.............................................*/
    /*.............................................*/
    void menu()
    {
        cout << "\t---------WELCOME BACK---------------\n";
        cout << "\t---------WHAT DO YOU WANT TO DO---------------\n";
        cout << "\t   1.    VIEW VEHICLE          \n";
        cout << "\t   2.    ADD VEHICLE           \n";
        cout << "\t   3.    REMOVE VEHICLE         \n";
        cout << "\t   4.    REGESTER IN AUCTION     \n";
        cout << "\t   5.    VIEW NOTIFICATIONS       \n";
        cout << "\t   6.    LOGOUT                   \n";

        int choice;
        cout << "enter your choice";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "WELCOME TO VIEW VEHICLE\n";
            cout << "which vehicle do you want to see\n";
            cout << "\t------------------ 1. New Car 2. Used Cars 3. Bikes------------------ \n";

            cout << "enter choice :: ";

            cin >> choice;

            // system("cls");
            switch (choice)
            {
            case 1:

                viewnewcars();
                break;
            case 2:
                viewusedcars();
                break;
                // usedcars();
                // break;
            case 3:
                viewbikes();
                break;
                // bikes();
                // break;
            }

            break;
        case 2:
            cout << "welcome to add vehicle function \n";
            addvehicle();
            break;
        case 3:

            cout << "welcome to remove vehicle functio  \n";
            removevehicle();
            break;
        case 4:

            cout << "welcome to regester in auction";
            break;
        case 5:

            viewnotification();
            break;

        case 6:

            cout << "logout";

            break;
        }
    }

    /*----------FUNCTION FOR THE NEW CARS------------------*/

    void viewnewcars()
    {
        ifstream file("new_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];

        while (file.getline(line, sizeof(line)))
        {
            istringstream iss(line);

            // Read data from the line into character arrays

            iss >> name >> company >> model >> mileage >> price;
            file.ignore();                                      // Ignore the space before the description
            iss.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            iss >> sellerName >> contact >> fuelType >> engine >> rating >> makeYear >> AvailableInCity >> color;

            // Display the data
            cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sellerName << "\nContact: " << contact << "\nFuelType Type: " << fuelType
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << makeYear << "\nAvailableInCity: " << AvailableInCity << "\nColor: " << color << "\n\n";
        }

        file.close();
    }

    /*----------FUNCTION FOR THE USED CARS------------------*/

    void viewusedcars()
    {
        ifstream file("used_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];

        while (file.getline(line, sizeof(line)))
        {
            istringstream iss(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sellerName[50], contact[50], fuelType[50], engine[50], rating[10], makeYear[50], availableInCity[50], color[50];

            iss >> name >> company >> model >> mileage >> price;
            file.ignore();                                      // Ignore the space before the description
            iss.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            iss >> sellerName >> contact >> fuelType >> engine >> rating >> makeYear >> availableInCity >> color;

            // Display the data
            cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sellerName << "\nContact: " << contact << "\nFuelType Type: " << fuelType
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << makeYear << "\nAvailableInCity: " << availableInCity << "\nColor: " << color << "\n\n";
        }

        file.close();
    }

    /*function for the bikes*/

    void viewbikes()
    {
        ifstream file("bikes.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];

        while (file.getline(line, sizeof(line)))
        {
            istringstream iss(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sellerName[50], contact[50], fuelType[50], engine[50], rating[10], makeYear[50], availableInCity[50], color[50];

            iss >> name >> company >> model >> mileage >> price;
            file.ignore();                                      // Ignore the space before the description
            iss.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            iss >> sellerName >> contact >> fuelType >> engine >> rating >> makeYear >> availableInCity >> color;

            // Display the data
            cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sellerName << "\nContact: " << contact << "\nFuelType Type: " << fuelType
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << makeYear << "\nAvailableInCity: " << availableInCity << "\nColor: " << color << "\n\n";
        }

        file.close();
    }

    /*function to add the vehicle*/

    void addvehicle()
    {
        seller_vehicle newVehicle;
        cout << "WELCOME TO ADD VEHICLE...\n";

        cout << "\n\t\tyou want to add vehicle in which \n \t \t (1) new cars (2) used cars (3) bikes :: ";
        cout << "please enter the choice ";
        int choice;
        cin >> choice;

        // Collect information from the seller

        switch (choice)
        {
        case 1:
            cout << "You have chosen to add a new car." << endl;
            cout << "Please enter the following information for the new car:" << endl;
            addnewcar();
            break;
        case 2:
            cout << "You have chosen to add a used car." << endl;
            cout << "Please enter the following information for the used car:" << endl;
            addusedcar();
            break;
        case 3:
            cout << "You have chosen to add a bike." << endl;
            cout << "Please enter the following information for the bikes:" << endl;
            addbikes();
            break;
        }
    }

    /*function to add new car */
    void addnewcar()
    {

        ofstream addcar("new_cars.txt", ios::app);

        if (!addcar)
        {
            cout << "FILE NOT FOUND !" << endl;
            return;
        }

        seller_vehicle newVehicle;

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

    /*function to add used car */
    void addusedcar()
    {
        ofstream addcar("used_cars.txt", ios::app);

        if (!addcar)
        {
            cout << "FILE NOT FOUND !" << endl;
            return;
        }

        seller_vehicle newVehicle;

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

    /*function to add bikes */
    void addbikes()
    {
        cout << "enter the details of the bike \n";
        // char make[50], model[50], mileage[50], price[50], description[100], name[50], contact[50], fuelType[50], engine[50], rating[50], year[10], availableInCity[50], color[50];

        ofstream addbike("bikes.txt", ios::app);

        if (!addbike)
        {
            cout << "FILE NOT FOUND !" << endl;
            return;
        }

        seller_vehicle newVehicle;

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
        addbike << endl
                << newVehicle.name << " " << newVehicle.company << " " << newVehicle.model << " "
                << newVehicle.mileage << " " << newVehicle.price << " " << newVehicle.description << " "
                << newVehicle.sellerName << " " << newVehicle.contact << " " << newVehicle.fuelType << " "
                << newVehicle.engine << " " << rating << " " << newVehicle.makeYear << " "
                << newVehicle.availableInCity << " " << newVehicle.color << " " << username;

        cout << "Vehicle added successfully!" << endl;

        addbike.close();
    }

    /*function to remove the vehicle */

    void removevehicle()
    {
        cout << "\n\nwelcome \n\n";
        cout << "\t\twhich vehicle you want to remove \n\n";
        cout << "\t\t(1) new car (2) used cars (3) bikes \n\n";
        int choice;
        cout << "please enter choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            removenewcar();
            break;
        case 2:
            removeusedcar();
            break;
        case 3:
            removebikes();
            break;

       
        }
    }
    void removenewcar()
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
    




    void removeusedcar()
    {
        cout << "Enter the name of the vehicle to remove: ";
        cin >> searchName;

        ifstream inFile("used_cars.txt", ios::in);
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
        remove("used_cars.txt");

        // Rename the temporary file to the original file
        rename("temp.txt", "used_cars.txt");

        if (!found)
        {
            cout << "Vehicle not found!" << endl;
        }
    }






void  removebikes()
{
    cout << "Enter the name of the vehicle to remove: ";
        cin >> searchName;

        ifstream inFile("bikes.txt", ios::in);
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
        remove("bikes.txt");

        // Rename the temporary file to the original file
        rename("temp.txt", "bikes.txt");

        if (!found)
        {
            cout << "Vehicle not found!" << endl;
        }
}



void viewnotification()
{
    ifstream readnot("notifications.txt");

    if(readnot.is_open())
    {
        if(readnot.peek()==ifstream::traits_type::eof())
    {
        cout<<"SORRY NO NOTIFICATIONS TO SEE  \n";
    }
       else{ string line ;
        while(getline(readnot,line))
        {
            cout<<line<<endl;
        }
    }
     readnot.close();
    }
    else
    {
        cout<<"unable to open file \n\n";
    }
   
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