#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>
#include <direct.h>
#include <iomanip>
#include <ctime>

#define total_stock 15
using namespace std;

class customer
{
protected:
    string name;
    string sex;
    string email_address;
    int age;
    string phone;
    string carModel;
    int days;
    const int no_of_cars_available = 4;
};

class rent : public customer
{
    int no_of_cars_A = 4;
    int no_of_cars_B = 5;
    int no_of_cars_C = 3;
    int no_of_cars_D = 3;
    int terminatingVariable = (no_of_cars_A + no_of_cars_B + no_of_cars_C + no_of_cars_D);

public:
    int day = 0;
    int rentalFee = 0;

    void customer_choice_and_info()
    {

        int login_page();
        login_page();

        cout << "\t\t\t\tPlease Enter Your Name: ";
        cin >> name;
        cout << endl;
        cout << "\t\t\t\tPlease Enter Your Sex: ";
        cin >> sex;
        cout << endl;
        cout << "\t\t\t\tPlease Enter Your Phone no: ";
        cin >> phone;
        cout << endl;
        cout << "\t\t\t\tPlease Enter Your preffered car model: ";
        cin >> carModel;
        cout << endl;

        do
        {
            cout << "\t\t\t\tPlease Select a Car" << endl; // giving user a choice to select among three different models
            cout << "\t\t\t\tEnter 'A' for Mercedes Electric 2022." << endl;
            cout << "\t\t\t\tEnter 'B' for Hyundai 2022." << endl;
            cout << "\t\t\t\tEnter 'C' for Ford 2021." << endl;
            cout << "\t\t\t\tEnter 'D' for Jaguar 2019." << endl;
            cout << "\t\t\t\tEnter '0' to exit." << endl;
            cout << endl;
            cout << "\t\t\t\tChoose a Car from the above options: ";
            cin >> carModel;
            cout << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            if (carModel == "A")
            {
                system("CLS");

                cout << "You have choosed Mercedes Electric 2022" << endl;
                ifstream inA("A.txt"); // displaying details of model A
                char str[200];
                while (inA)
                {
                    inA.getline(str, 200);
                    if (inA)
                        cout << str << endl;
                }
                if (no_of_cars_A == 0)
                {
                    cout << "\n\n\n\n\n\t\t\t\t\tThe car you have choosen is out of stock" << endl;
                    cout << "\t\t\t\t\tPlease choose another car model" << endl;
                    sleep(2);
                    system("CLS");
                    customer_choice_and_info();
                }
                no_of_cars_A--;
                sleep(2);
            }
            if (carModel == "B")
            {

                system("CLS");

                cout << "You have choosed Hyundai 2022" << endl;
                ifstream inB("B.txt"); // displaying details of model B
                char str[200];
                while (inB)
                {
                    inB.getline(str, 200);
                    if (inB)
                        cout << str << endl;
                }
                if (no_of_cars_B == 0)
                {
                    cout << "\n\n\n\n\n\t\t\t\t\tThe car you have choosen is out of stock" << endl;
                    cout << "\t\t\t\t\tPlease choose another car model" << endl;
                    sleep(2);
                    system("CLS");
                    customer_choice_and_info();
                }
                no_of_cars_B--;
                sleep(2);
            }
            if (carModel == "C")
            {
                system("CLS");

                cout << "You have choosed Ford 2021" << endl;
                ifstream inC("C.txt"); // displaying details of model C
                char str[200];
                while (inC)
                {
                    inC.getline(str, 200);
                    if (inC)
                        cout << str << endl;
                }
                if (no_of_cars_C == 0)
                {
                    cout << "\n\n\n\n\n\t\t\t\t\tThe car you have choosen is out of stock" << endl;
                    cout << "\t\t\t\t\tPlease choose another car model" << endl;
                    sleep(2);
                    system("CLS");
                    customer_choice_and_info();
                }
                no_of_cars_C--;
                sleep(2);
            }
            if (carModel == "D")
            {
                system("CLS");

                cout << "You have choosed Jaguar 2019" << endl;
                ifstream inC("D.txt"); // displaying details of model D
                char str[200];
                while (inC)
                {
                    inC.getline(str, 200);
                    if (inC)
                        cout << str << endl;
                }
                if (no_of_cars_D == 0)
                {
                    cout << "\n\n\n\n\n\t\t\t\t\tThe car you have choosen is out of stock" << endl;
                    cout << "\t\t\t\t\tPlease choose another car model" << endl;
                    sleep(2);
                    system("CLS");
                    customer_choice_and_info();
                }
                no_of_cars_D--;
                sleep(2);
            }
            if(carModel == "0")
            {
                exit(1);
            }
            if (carModel != "A" && carModel != "B" && carModel != "C" && carModel != "D" && carModel != "0")
            {
                cout << "Invaild Car Model. Please try again!" << endl;
                cout << "--------------------------------------------------------------------------\n";
                customer_choice_and_info();
            }
            terminatingVariable--;
        } while (terminatingVariable < 1);
        if (no_of_cars_A == 0 && no_of_cars_B == 0 && no_of_cars_C == 0 && no_of_cars_D == 0)
        {
            cout << "\n\n\n\n";
            cout << "We are out of stock."
                 << "\n";
        }

        else
        {
            cout << "--------------------------------------------------------------------------" << endl;
            cout << "Please provide following information: " << endl;
            cout << "Number of days you wish to rent the car : ";
            cin >> days;
            cout << endl;
        }
    }

    void calculateRent()
    {
        sleep(1);
        system("CLS");
        cout << "Calculating rent. Please wait......" << endl;
        sleep(2);
        if (carModel == "A" || carModel == "a")
            rentalFee = days * 1500;
        if (carModel == "B" || carModel == "b")
            rentalFee = days * 1600;
        if (carModel == "C" || carModel == "c")
            rentalFee = days * 1750;
        if (carModel == "D" || carModel == "d")
            rentalFee = days * 3000;
    }

    void rentalBill()
    {
        time_t timeToday;
        time(&timeToday);

        cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Invoice No. :"
             << "------------------|" << setw(10) << "#Cnb81353"
             << " |" << endl;
        cout << "\t\t	| Customer Name:"
             << "-----------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Car Model :"
             << "--------------------|" << setw(10) << carModel << " |" << endl;
        cout << "\t\t	| Date :"
             << "----------------------|" << setw(10) << asctime(localtime(&timeToday)) << " |" << endl;
        cout << "\t\t	| Number of days :"
             << "---------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	| Your Rental Amount is :"
             << "--------|" << setw(10) << rentalFee << " |" << endl;
        cout << "\t\t	| Caution Money :"
             << "----------------|" << setw(10) << "0"
             << " |" << endl;
        cout << "\t\t	| Advanced :"
             << "---------------------|" << setw(10) << "0"
             << " |" << endl;
        cout << "\t\t	 ____________________" << endl;
        cout << "\n";
        cout << "\t\t	| Total Rental Amount is :"
             << "-------|" << setw(10) << rentalFee << " |" << endl;
        cout << "\t\t	 ____________________" << endl;
        cout << "\t\t	 # This is a computer generated invoice and it does not" << endl;
        cout << "\t\t	 require an authorised signture #" << endl;
        cout << " " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	You are advised to pay up the amount before due date." << endl;
        cout << "\t\t	Otherwise penalty fee will be applied" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        system("PAUSE");

        system("CLS");
        ifstream inf("thanks.txt");

        char str[300];

        while (inf)
        {
            inf.getline(str, 300);
            if (inf)
                cout << str << endl;
        }
        inf.close();
        sleep(3);
        system("CLS");
    }
};

class welcome // welcome class
{
public:
    int welcome1()
    {
        ifstream in("welcome.txt");
        if (!in)
        {
            cout << "Cannot open input file.\n";
        }
        char str[1000];
        while (in)
        {
            in.getline(str, 1000);
            if (in)
            {
                cout << str << endl;
            }
        }
        in.close();
        sleep(1);
        system("CLS");
        cout << "\nStarting the program please wait....." << endl;
        sleep(1);
        cout << "\nloading up files....." << endl;
        sleep(3);
        system("CLS");
    }
};

int main()
{

    welcome obj1;

    // obj1.welcome1();
    rent obj2;

    for (int i = 0; i < total_stock; i--)
    {
        obj1.welcome1();
        obj2.customer_choice_and_info();
        obj2.calculateRent();
        obj2.rentalBill();
    }

    // obj2.customer_choice_and_info();
    // obj2.calculateRent();
    // obj2.rentalBill();

    return 0;
}

int login_page()
{
    string password = "";
    string username = "";

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t       CAR RENTAL SYSTEM \n\n";
    cout << "\t\t\t\t---------------------------------------";
    cout << "\n\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t---------------------------------------\n\n";

    cout << "\t\t\t\tEnter Username: ";
    cin >> username;
    cout << "\n";
    cout << "\t\t\t\tEnter Password: ";
    cin >> password;

    if (password == "MITWPU")
    {
        cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
        system("PAUSE");
        system("CLS");
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
        system("PAUSE");
        system("CLS");
        login_page();
    }
}