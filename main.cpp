#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "buyer.h"
#include "seller.h"
#include "admin.h"
// #include "vehicle.h"
using namespace std;

int main()
{
    // system("Color 04");
    buyer b;
    seller s;
    admin a;

    // view_vehicle v;
    int choice;

    cout << "                              _.-=\"_-         _\n";
    cout << "                         _.-=\"   _-          | ||\"\"\"\"\"\"\"\"---._______     __..\n";
    cout << "             ___.===\"\"\"-.______-,,,,,,,,,,,,`-''----\" \"\"\"\"\"\"\"       \"\"\"\"\"\"  __'\n";
    cout << "      __.--\"\"     __        ,'                   o \\           __        [__|\n";
    cout << " __-\"\"=======.--\"\"  \"\"--.=================================.--\"\"  \"\"--.=======:\n";
    cout << "]       [w] : /        \\ : |========================|    : /        \\ :  [w] :\n";
    cout << "V___________:|          |: |========================|    :|          |:   _-\"\n";
    cout << " V__________: \\        / :_|=======================/_____: \\        / :__-\"\n";
    cout << " -----------'  \"-____-\"  `-------------------------------'  \"-____-\"\n";
    cout << "\n\n\n\n\n\n";
    cout << "                                                        ___________                        \n";
    cout << "                                              __..--\"\"\"\"           \"\"\"\"--..__              \n";
    cout << "                                          _.-\"\"\"\"\"\"\"\"\"-----...      ______ `.            \n";
    cout << "                                       .-\"                      | ,-\"\"    \\ \"-.`.          \n";
    cout << "                                    .-\"                         ; ;        ;   \\ \"\"--.._   \n";
    cout << "                                  .'                           : :         |    ;      .l  \n";
    cout << "                            _.._.'                             ; ;  ___    |    ;    .' :  \n";
    cout << "                           (  .'                              : :  :   \".  :..-'   .'    ; \n";
    cout << "                            )'                                | ;  ; __.'-\"(     .'  .--.: \n";
    cout << "                    ___...-'\"\"\"\"----....____          ______.-' :-/.'       \\_.-'  .' .-.\\l\n";
    cout << "            __..--\"                        \"\"\"\"\"\"          /\"\"          ;    / .gs./\\;\n";
    cout << "        _.-\"                                                   /  ;          |   . d$P\"Tb  \n";
    cout << "     .-\"-,                       ____                        /   |          :   ;:$$   $; \n";
    cout << "   .'     ;                    ,\"    \"\"--..__               /    :          |   $$$;   :$ \n";
    cout << "  /\"-._  /                     ;       ____..-'    .-\"\"\"-.  /     :          ;  _$$$;   :$ \n";
    cout << " :     \"\"--.._          ___....+---\"\"\"          .'  _._  \\/      |         _:-\" $$$;   :$ \n";
    cout << " ;                                              /  .d$$$b./       ;      .-\".'   :$$$   $P \n";
    cout << ":            .----...____                      :  dP' `T$P        |   .-\" .' _.gd$$$$b_d$' \n";
    cout << ";    __...---|    SAMI    |----....____         | :$     $b        : .'   (.-\"  `T$$$$$$P'  \n";
    cout << ";  .';       '----...____;       /    \"-.      ; $;     :$;_____..-\"  .-\"                  \n";
    cout << ": /  :                          /        \\__..-':$       $$ ;-.    .-\"                     \n";
    cout << " Y    ;                        /          ;     $;       :$;|  `.-\"                        \n";
    cout << " :    :                       /           |     $$       $$;:.-\"                           \n";
    cout << " '$$$ggggp...____            /            :     :$;     :$$                                \n";
    cout << "  $$$$$$$$$$$$   \"\"\"\"----...:________....gggg$$$$$$     $$;                                \n";
    cout << "  'T$$$$$$$$P'                           T$$$$$$$$$b._.d$P                                 \n";
    cout << "    `T$$$$P'                              T$$$$$$$$$$$$$P                                  \n";
    cout << "                                           `T$$$$$$$$$P'                                   \n";

    cout << "\n\n---------------WELCOME TO THE CAR INVENTORY SYSTEM---------------\n\n"
         << endl;

    //  do
    //     {
    cout << "+-----------------------------------+" << std::endl;
    cout << "|       WHO ARE YOU?                |" << std::endl;
    cout << "|   (1) BUYER :: (2) SELLER         |" << std::endl;
    cout << "|   (3) ADMIN :: (4) EXIT           |" << std::endl;
    cout << "+-----------------------------------+" << std::endl;
    cin >> choice;
    // if(choice<1 || choice>4)
    // {
    //     cout<<"you have entered wrong choice , please enter correct choice :: ";
    //     // cin>>choice;
    // }
    // else
    // {

    switch (choice)
    {
    case 1:
        // for the buyer
        cout << "\n are you a new buyer or an existing buyer :: ";
        cout << "\n N/E ";
        char ch;
        cin >> ch;
        if (ch == 'N' || ch == 'n')
        {
            b.register_buyer(); // for the regestration
        }
        else if (ch == 'E' || ch == 'e')
        {
            b.login_buyer();
        }
        break;
    case 2:
        // for the seller
        cout << "\n are you a new user or an existing user :: ";
        cout << "\n N/E ";
        cin >> ch;
        if (ch == 'N' || ch == 'n')
        {
            s.register_seller(); // for the regestration
        }
        else if (ch == 'E' || ch == 'e')
        {

            s.login_seller();
        }
        break;
    case 3:

        a.login_admin();
    }
}