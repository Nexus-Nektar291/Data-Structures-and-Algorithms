#include "header.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void takeInput(Node *curr)
{
    string str;
    cout << "Enter Data: ";
    getline(cin, str);
    curr->data = str;
    str.clear();
}

void Menu()
{
    cout << "Press 'I' to insert Data in cell" << endl;
    cout << "Press 'M' for more options" << endl;
    cout << "Press escape to exit" << endl;
}

string options()
{
    string str;
    cout << " 1) Exit" << endl;
    cout << " 2) Insert row after " << endl;
    cout << " 3) Insert row before " << endl;
    cout << " 4) Insert column Right to the current Cell" << endl;
    cout << " 5) Insert column Left to the current Cell" << endl;
    cout << " 6) Insert cell by left shift" << endl;
    cout << " 7) Insert cell by Right shift" << endl;
    cout << " 8) Insert cell by Up shift" << endl;
    cout << " 9) Insert cell by Down shift" << endl;
    cout << " 10) Delete current Cell by left shift" << endl;
    cout << " 11) Delete current Cell by Up shift" << endl;
    cout << " 12) Delete current Column " << endl;
    cout << " 13) Delete current Row " << endl;
    cout << " 14) Clear current Row " << endl;
    cout << " 15) Clear current Column " << endl;
    cout << " 16) Calculate Sum " << endl;
    cout << " 17) Calculate Average " << endl;
    cout << " 19) Find minimum in given range " << endl;
    cout << " 20) Find maximum in given range " << endl;
    cout << " 21) Copy cells " << endl;
    cout << " 22) Paste cells " << endl;
    cout << " 23) Cut cells " << endl;
    cout << "Select Options : ";
    cin >> str;
    return str;
}
Starting_Range Start_Range()
{
    char r, c;
    cout << "Enter starting row: ";
    cin >> r;
    cout << "Enter starting column: ";
    cin >> c;
    if (isdigit(c) && isdigit(r))
    {
        int row = r - '0';
        int col = c - '0';
        return Starting_Range(row, col);
    }
    else
    {
        return Starting_Range(0, 0);
    }
}
Ending_Range End_Range()
{
    char r, c;
    cout << "Enter ending row: ";
    cin >> r;
    cout << "Enter ending column: ";
    cin >> c;
    if (isdigit(c) && isdigit(r))
    {
        int row = r - '0';
        int col = c - '0';
        return Ending_Range(row, col);
    }
    else
    {
        return Ending_Range(0, 0);
    }
}
int main()
{
    Excel ex;
    ex.printExcel();
    Menu();
    string input;

    while (true)
    {
        if (GetAsyncKeyState(VK_UP) && ex.current->up != nullptr)
        {
            ex.current = ex.current->up;
            ex.printExcel();
            Menu();
        }
        else if (GetAsyncKeyState(VK_DOWN) && ex.current->down != nullptr)
        {
            ex.current = ex.current->down;
            ex.printExcel();
            Menu();
        }
        else if (GetAsyncKeyState(VK_LEFT) && ex.current->left != nullptr)
        {
            ex.current = ex.current->left;
            ex.printExcel();
            Menu();
        }
        else if (GetAsyncKeyState(VK_RIGHT) && ex.current->right != nullptr)
        {
            ex.current = ex.current->right;
            ex.printExcel();
            Menu();
        }
        else if (GetAsyncKeyState(0x4D))
        {
            input = options();
            if (input == "2")
            {
                ex.Add_Row_Below();
            }
            else if (input == "3")
            {
                ex.Add_Row_Above_Node();
            }
            else if (input == "4")
            {
                ex.insertColumnToRight();
            }
            else if (input == "5")
            {
                ex.insertColumnToLeft();
            }
            else if (input == "6")
            {
                ex.insertCellByLeftShift();
            }
            else if (input == "7")
            {
                ex.insertCellByRightShift();
            }
            else if (input == "8")
            {
                ex.insertCellByUpShift();
            }
            else if (input == "9")
            {
                ex.insertCellByDownShift();
            }
            else if (input == "10")
            {
                ex.deleteCellByLeftShift();
            }
            else if (input == "11")
            {
                ex.deleteCellByUpShift(ex.current);
            }
            else if (input == "12")
            {
                ex.deleteColumn();
            }
            else if (input == "13")
            {
                ex.deleteRowCurrent();
            }
            else if (input == "14")
            {
                ex.ClearRow();
            }
            else if (input == "15")
            {
                ex.ClearColumn();
            }
            else if (input == "16")
            {
                Starting_Range start = Start_Range();
                Ending_Range end = End_Range();
                cout << "Sum is: " << ex.GetRangeSum(start, end) << endl;
                cout << "Press any key to continue...";
                _getch();
            }
            else if (input == "17")
            {
                Starting_Range start = Start_Range();
                Ending_Range end = End_Range();
                cout << "Average is: " << ex.GetRangeAverage(start, end) << endl;
                cout << "Press any key to continue...";
                _getch();
            }
            else if (input == "18")
            {
                Starting_Range start = Start_Range();
                Ending_Range end = End_Range();
                cout << "Selectd Cells are: " << ex.getSelectedCount(start, end) << endl;
                cout << "Press any key to continue...";
                _getch();
            }
            else if (input == "19")
            {
                Starting_Range start = Start_Range();
                Ending_Range end = End_Range();
                cout << "Minimum is: " << ex.GetRangeMinimum(start, end) << endl;
                cout << "Press any key to continue...";
                _getch();
            }
            else if (input == "20")
            {
                Starting_Range start = Start_Range();
                Ending_Range end = End_Range();
                cout << "Maximum is: " << ex.GetRangeMaximum(start, end) << endl;
                cout << "Press any key to continue...";
                _getch();
            }
            else if (input == "21")
            {
                Starting_Range start = Start_Range();
                Ending_Range end = End_Range();
                ex.RangeCopySelect(start, end);
                cout << "Press any key to continue...";
                _getch();
            }
            else if (input == "22")
            {
                ex.paste();
                cout << "Press any key to continue...";
                _getch();
            }
            else if (input == "23")
            {
                Starting_Range start = Start_Range();
                Ending_Range end = End_Range();
                ex.RangeCutSelect(start, end);
                cout << "Press any key to continue...";
                _getch();
            }
            ex.printExcel();
            Menu();
        }
        else if (GetAsyncKeyState(0x49))
        {
            takeInput(ex.current);
            ex.printExcel();
            Menu();
        }
        else if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }

        Sleep(50);
    }
    return 0;
}