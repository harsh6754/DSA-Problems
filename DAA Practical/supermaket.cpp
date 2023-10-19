#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administration();
    void customer();
    void add();
    void edit();
    void removeProduct();
    void list();
    void receipt();
};

void Shopping::menu()
{
    int choice;
    string email;
    string password;
    while (true)
    {
        cout << setw(60) << "_______________________________________________" << endl;
        cout << setw(60) << "                                               " << endl;
        cout << setw(60) << "_____________SUPERMARKET MAIN MENU_____________" << endl;
        cout << setw(60) << "                                               " << endl;
        cout << setw(60) << "_______________________________________________" << endl;
        cout << setw(60) << "                                               " << endl;
        cout << setw(50) << "1) Administrator" << endl;
        cout << setw(50) << "2) Customer" << endl;
        cout << setw(50) << "3) Exit" << endl;
        cout << setw(50) << "Please select: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << setw(50) << "Please login" << endl;
            cout << setw(50) << "Enter Email ID: ";
            cin >> email;
            cout << setw(50) << "Password: ";
            cin >> password;
            if (email == "prekshamahajan2020@gmail.com" && password == "Project")
            {
                administration();
            }
            else
            {
                cout << "Invalid Email ID/Password" << endl;
            }
            break;
        case 2:
            customer();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Please select from the above given options." << endl;
        }
    }
}

void Shopping::administration()
{
    int choice;
    while (true)
    {
        cout << setw(40) << "\n\n\n Administrator menu";
        cout << setw(30) << "\n|______1) Add the product_______|";
        cout << setw(30) << "\n|______2) Modify the product____|";
        cout << setw(30) << "\n|______3) Delete the product____|";
        cout << setw(30) << "\n|______4) List all products______|";
        cout << setw(30) << "\n|______5) Back to main menu_____|";

        cout << setw(30) << "\n\nPlease enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            removeProduct();
            break;
        case 4:
            list();
            break;
        case 5:
            menu();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void Shopping::customer()
{
    int choice;
    while (true)
    {
        cout << setw(40) << "Customer" << endl;
        cout << setw(40) << "________________" << endl;
        cout << setw(30) << "1) Buy Product" << endl;
        cout << setw(30) << "2) Go back" << endl;
        cout << setw(30) << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}

void Shopping::add()
{
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;
    cout << setw(50) << "Add new product" << endl;
    cout << setw(50) << "Product code of the product: ";
    cin >> pcode;
    cout << setw(50) << "Name of the product: ";
    cin.ignore();
    getline(cin, pname);
    cout << setw(50) << "Price of the product: ";
    cin >> price;
    cout << setw(50) << "Discount of the product: ";
    cin >> discount;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << pcode << " " << pname << " " << price << " " << discount << endl;
        data.close();
        cout << setw(50) << "Record Inserted" << endl;
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            cout << setw(50) << "Record with the same product code already exists! Please try again." << endl;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << pcode << " " << pname << " " << price << " " << discount << endl;
            data.close();
            cout << setw(50) << "Record Inserted" << endl;
        }
    }
}

void Shopping::edit()
{
    fstream data, data1;
    int pkey, token = 0, c;
    float p, d;
    string n;

    cout << setw(40) << "Modify the record" << endl;
    cout << setw(40) << "Enter the product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << setw(40) << "File doesn't exist!" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;

        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << setw(40) << "Product of new code: ";
                cin >> c;
                cout << setw(40) << "Name of the product: ";
                cin.ignore();
                getline(cin, n);
                cout << setw(40) << "Price: ";
                cin >> p;
                cout << setw(40) << "Discount: ";
                cin >> d;
                data1 << c << " " << n << " " << p << " " << d << endl;
                cout << setw(40) << "Record edited" << endl;
                token++;
            }
            else
            {
                data1 << pcode << " " << pname << " " << price << " " << discount << endl;
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();

        removeProduct();

        if (token == 0)
        {
            cout << setw(40) << "Record not found, sorry!" << endl;
        }
    }
}

void Shopping::removeProduct()
{
    int pkey, token = 0;

    cout << setw(40) << "Delete Product" << endl;
    cout << setw(40) << "Product Code: ";
    cin >> pkey;

    fstream data, data1;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << setw(40) << "File doesn't exist." << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;

        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << setw(40) << "Product deleted successfully" << endl;
                token++;
            }
            else
            {
                data1 << pcode << " " << pname << " " << price << " " << discount << endl;
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << setw(40) << "Record not found!" << endl;
        }
    }
}

void Shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);

    cout << setw(40) << "_____________________________________" << endl;
    cout << setw(40) << "Product No." << setw(20) << "Name" << setw(20) << "Price" << setw(20) << "Discount (%)" << endl;
    cout << setw(40) << "_____________________________________" << endl;
    data >> pcode >> pname >> price >> discount;

    while (!data.eof())
    {
        cout << setw(40) << pcode << setw(20) << pname << setw(20) << price << setw(20) << discount << endl;
        data >> pcode >> pname >> price >> discount;
    }
    data.close();
}

void Shopping::receipt()
{
    fstream data;
    int arrCodes[100], arrQuantity[100];
    char choice;
    int c = 0;
    float amount = 0, discount = 0, total = 0;

    cout << setw(40) << "RECEIPT" << endl;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << setw(40) << "Empty Database!" << endl;
    }
    else
    {
        data.close();
        list();
        cout << setw(40) << "_____________________________________" << endl;
        cout << setw(40) << "" << endl;
        cout << setw(40) << "Please place the order" << endl;
        cout << setw(40) << "" << endl;
        cout << setw(40) << "_____________________________________" << endl;

        do
        {
        m:
            cout << setw(40) << "Enter Product Code: ";
            cin >> arrCodes[c];
            cout << setw(40) << "Enter Product Quantity: ";
            cin >> arrQuantity[c];

            for (int i = 0; i < c; i++)
            {
                if (arrCodes[c] == arrCodes[i])
                {
                    cout << setw(40) << "Duplicate Product Code. Please try again!" << endl;
                    goto m;
                }
            }
            c++;
            cout << setw(40) << "Do you want to buy another product? If yes, then press 'Y' else press 'N'";
            cin >> choice;
        } while (choice == 'Y' || choice == 'y');

        cout << setw(40) << "_______________RECEIPT_______________" << endl;
        cout << setw(40) << "Product No." << setw(20) << "Product Name" << setw(20) << "Product Quantity" << setw(20) << "Price" << setw(20) << "Amount" << setw(30) << "Amount with Discount" << endl;

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;

            while (!data.eof())
            {
                if (pcode == arrCodes[i])
                {
                    amount = price * arrQuantity[i];
                    discount = amount * (discount / 100);
                    total += amount - discount;

                    cout << setw(40) << pcode << setw(20) << pname << setw(20) << arrQuantity[i] << setw(20) << price << setw(20) << amount << setw(30) << amount - discount << endl;
                }

                data >> pcode >> pname >> price >> discount;
            }

            data.close();
        }

        cout << setw(40) << "______________________________________" << endl;
        cout << setw(40) << "Total Amount: " << total << endl;
    }
}

int main()
{
    Shopping S;
    S.menu();
    return 0;
}
