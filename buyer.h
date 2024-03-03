#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <windows.h>
// #include"vehicle.h"

using namespace std;
class Car
{
public:
    string name, company, model, mileage, price, description, sell_name, contact, fuel, engine, rating, make_year, city, color;
    const int MAX_CARS = 100;
};

class buyer : public Car
{
protected:
    char username[50], password[50];
    char storedUsername[100], storedPassword[100];

public:
    void register_buyer()
    {
        cout << "Enter the username: ";
        cin >> username;
        cout << "Enter the password: ";
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
        cin >> password;
        printf("\x1B[36mTexting\033[0m\t\t");

        ofstream file("buyer.txt", ios::app);
        if (file.is_open())
        {

            file << endl;
            file << username << " " << password;
            cout << "File opened successfully! and data successfully stored! \n\n";
            file.close();
        }
        else
        {
            cout << "File not created!";
        }
    }

    void login_buyer()
    {
        ifstream file("buyer.txt");

        string line;

        bool credentialsCorrect = false;

        while (!credentialsCorrect)
        {
            // cout << "Enter username: ";
            // YELLOW_TEXT << "Enter username:" << RESET_TEXT;
            cout << "\033[32m"
                 << "enter the username" << endl;
            cin >> username;

            cout << "enter the password" << endl;
            cin >> password;
            cout << "\033[0m" << endl;
            // HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

            // DWORD mode = 0;

            // GetConsoleMode(hStdin, &mode);

            // SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

            string line;
            while (getline(file, line))
            {
                istringstream read(line);

                // Read username and password from the file
                read >> storedUsername >> storedPassword;

                // Compare entered credentials with stored credentials
                if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
                {
                    cout << "Login successful!\n\n\n"
                         << endl;

                    credentialsCorrect = true;

                    menu(); // calling the menu function if the credentials are correct

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

    /*-----------------------*/
    /*-----------------------*/
    /*-----------------------*/
    /*-----------------------*/

    void menu()
    {
        cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n";
        cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n";
        cout << "| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |\n";
        cout << "| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |\n";
        cout << "| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |\n";
        cout << "| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |\n";
        cout << "| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |\n";
        cout << "| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |\n";
        cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n";
        cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n";
        cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n";
        int choice;

        cout << "\t\tplease select an option to continue\n\n";

        cout << "   1.    \t\tView Vehicles\n\n";

        cout << "   2.    \t\tView Auction\n\n";

        cout << "   3.    \t\tView Notifications\n\n";

        cout << "   4.    \t\tRequest Inspection Report\n\n";

        cout << "   5.    \t\tLogout \n\n";

        cout << "please enter your choice  :: ";

        cin >> choice;

        char targetname[50];

        switch (choice)
        {

        case 1:

            cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n";
            cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n";
            cout << "| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |\n";
            cout << "| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |\n";
            cout << "| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |\n";
            cout << "| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |\n";
            cout << "| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |\n";
            cout << "| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |\n";
            cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n";
            cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n";
            cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n";

            /*FOR THE VIEW VEHICLE*/

            cout << "\t------------------which vehicle you want to see------------------ \n";

            cout << "\t------------------ 1. New Car 2. Used Cars 3. Bikes------------------ \n";

            cout << "enter choice :: ";

            cin >> choice;

            // system("cls");
            switch (choice)
            {
            case 1:
                newcars();
                break;
            case 2:
                usedcars();
                break;
            case 3:
                bikes();
                break;
            }

            break;

        case 2:
            cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n";
            cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n";
            cout << "| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |\n";
            cout << "| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |\n";
            cout << "| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |\n";
            cout << "| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |\n";
            cout << "| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |\n";
            cout << "| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |\n";
            cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n";
            cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n";
            cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n";

            cout << "\t------------------which vehicle you want to see------------------ \n";

            cout << "\t------------------ 1. New Car 2. Used Cars 3. Bikes------------------ \n";

            cin >> choice;

            switch (choice)
            {
            case 1:
                auction_new();
                break;
            case 2:
                auction_used();
                break;
            case 3:
                auction_bikes();
                break;
            }

            break;
        case 3:
            viewnotification();
            break;
        case 4:
            inspection_report();
            break;
        case 5:
            // logout();
            break;
        }
    }

    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/

    // FUNCTIONS FOR THE VIEW VEHICLE

    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/

    /*----------FUNCTION FOR THE NEW CARS------------------*/

    /*function for price searching */

    /*----------FUNCTION FOR THE USED CARS------------------*/

    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/

    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/

    // FUNCTIONS FOR THE  AUCTION VEHICLE

    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/

    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/

    void newcars()
    {
        int choice;
        int minPrice, maxPrice;
        char targetCompany[50], targetname[50], targetsellername[50];
        ifstream file("new_cars.txt");
        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        int count = 1;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << count << " "
                 << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            count++;
        }

        file.close();

        cout << "enter the name of car you want to view :: ";

        /*FOR PRICE BASES*/ // Ask the user for price search

        cin >> targetname;
        newcarsbyname(targetname);
    }

    /*function for searching on the basis of compnay*/

    void newcarsbyname(const char *targetname)
    {

        ifstream file("new_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(name, targetname) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";

                cout << "Do you want to contact the seller? (Y/N): ";
                char choice;
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    contactSeller(sell_name, contact);
                }
            }
        }

        file.close();

        if (!found)
        {
            cout << "No cars from that specific name  '" << targetname << "' found." << endl;
        }
    }

    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/

    void usedcars()
    {
        int choice;
        char targetname[50];
        ifstream file("used_cars.txt");
        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        int count = 1;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << count << " "
                 << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            count++;
        }

        file.close();

        cout << "enter the name of car you want to view :: ";
        usedcarsbyname(targetname);
    }

    /*function for searching on the basis of compnay*/

    void usedcarsbyname(const char *targetname)
    {

        ifstream file("used_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(name, targetname) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";

                cout << "Do you want to contact the seller? (Y/N): ";
                char choice;
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    contactSeller(sell_name, contact);
                }
            }
        }

        file.close();

        if (!found)
        {
            cout << "No cars from that specific name  '" << targetname << "' found." << endl;
        }
    }

    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/

    void bikes()
    {
        int choice;

        char targetname[50];
        ifstream file("bikes.txt");
        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        int count = 1;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << count << " "
                 << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            count++;
        }

        file.close();

        cout << "enter the name of car you want \n\n";

        cin >> targetname;
        bikesbyname(targetname);
    }

    /*function for searching on the basis of compnay*/

    void bikesbyname(const char *targetname)
    {

        ifstream file("bikes.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(name, targetname) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";

                cout << "Do you want to contact the seller? (Y/N): ";
                char choice;
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    contactSeller(sell_name, contact);
                }
            }
        }

        file.close();

        if (!found)
        {
            cout << "No cars from that specific name  '" << targetname << "' found." << endl;
        }
    }

    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/

    void auction_new()
    {

        char targetname[50];
        ifstream file("new_auction.txt");
        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        int count = 1;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << count << " "
                 << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            count++;
        }

        file.close();

        cout << "enter name of car for viewing the details \n";

        cin >> targetname;
        auction_newbyname(targetname);
    }

    /*function for searching on the basis of compnay*/

    void auction_newbyname(const char *targetname)
    {

        ifstream file("new_auction.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(name, targetname) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";

                cout << "Do you want to contact the seller? (Y/N): ";
                char choice;
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    contactSeller(sell_name, contact);
                }
            }
        }

        file.close();

        if (!found)
        {
            cout << "No cars from that specific name  '" << targetname << "' found." << endl;
        }
    }

    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/

    void auction_used()
    {
        int choice;

        char targetname[50];
        ifstream file("used_auction.txt");
        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        int count = 1;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << count << " "
                 << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            count++;
        }

        file.close();

        cout << "ON WHICH BASIS YOU WANT TO SEARCH :: (1) COMPANY || (2) NAMAE \n\n";

        cin >> choice;

        /*FOR PRICE BASES*/ // Ask the user for price search
        cout << "Enter the price range (minimum and maximum): ";
        cout << "enter name of car for viewing the details \n";

        cin >> targetname;
        auction_usedbyname(targetname);
    }

    /*function for searching on the basis of compnay*/

    void auction_usedbyname(const char *targetname)
    {

        ifstream file("used_auction.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(name, targetname) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";

                cout << "Do you want to contact the seller? (Y/N): ";
                char choice;
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    contactSeller(sell_name, contact);
                }
            }
        }

        file.close();

        if (!found)
        {
            cout << "No cars from that specific name  '" << targetname << "' found." << endl;
        }
    }

    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    void auction_bikes()
    {
        int choice;
        int minPrice, maxPrice;
        char targetCompany[50], targetname[50], targetsellername[50];
        ifstream file("auction_bikes.txt");
        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        int count = 1;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << count << " "
                 << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            count++;
        }

        file.close();

        cout << "enter name of car for viewing the details \n";

        cin >> targetname;
        auction_bikesbyname(targetname);
    }

    /*function for searching on the basis of compnay*/

    void auction_bikesbyname(const char *targetname)
    {

        ifstream file("auction_bikes.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(name, targetname) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";

                cout << "Do you want to contact the seller? (Y/N): ";
                char choice;
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    contactSeller(sell_name, contact);
                }
            }
        }

        file.close();

        if (!found)
        {
            cout << "No cars from that specific name  '" << targetname << "' found." << endl;
        }
    }

    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/
    /*8888888888888888888888888888888888888888888888888888888888888888888888888888888888888*/

    void viewnotification()
    {
        ifstream readnot("notifications.txt");

        if (readnot.is_open())
        {
            if (readnot.peek() == ifstream::traits_type::eof())
            {
                cout << "SORRY NO NOTIFICATIONS TO SEE  \n";
            }
            else
            {
                string line;
                while (getline(readnot, line))
                {
                    cout << line << endl;
                }
            }
            readnot.close();
        }
        else
        {
            cout << "unable to open file \n\n";
        }
    }

    void contactSeller(const char *sellerName, const char *contactInfo)
    {

        cout << "Contacting seller " << sellerName << " at " << contactInfo << "...\n";
        // You can simulate a call or any other communication method here
        cout << "Simulation of calling...\n";
        // Notify the seller with the information
        cout << "Notification sent to seller with the information of the vehicle and your intent to purchase.\n";
    }
    void inspection_report()
    {
        const char *vehicleName;

        ifstream reportFile("new_car_inpection.txt");

        if (!reportFile.is_open())
        {
            cout << "Inspection report file not found.\n";
            return;
        }

        string line;
        bool found = false;
        bool readingReport = false;

        while (getline(reportFile, line))
        {
            cout << line << endl;
            found = true;
        }
        reportFile.close();

        if (!found)
        {
            cout << "Inspection report not found for " << vehicleName << ".\n";
        }
    }
};