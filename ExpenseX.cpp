
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_EXPENSES = 100;

int ids[MAX_EXPENSES];
string categories[MAX_EXPENSES];
string descriptions[MAX_EXPENSES];
double amounts[MAX_EXPENSES];
string dates[MAX_EXPENSES];
string times[MAX_EXPENSES];

int count = 0;
int nextId = 1;

void addExpense() {
    if (count == MAX_EXPENSES) {
        cout << "\nStorage is full!\n";
        return;
    }

    cout << "\n========== ADD EXPENSE ==========\n";

    ids[count] = nextId++;

    cout << "Category (Food/Travel/Shopping/Other): ";
    cin >> ws;
    getline(cin, categories[count]);

    cout << "Description: ";
    getline(cin, descriptions[count]);

    cout << "Amount (Rs.): ";
    if (!(cin >> amounts[count]) || amounts[count] <= 0) {
        cout << "Invalid amount!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    cout << "Date (DD-MM-YYYY): ";
    cin >> dates[count];

    cout << "Time (HH:MM): ";
    cin >> times[count];

    count++;

    cout << "\nExpense added successfully!\n";
}

void viewExpenses() {
    cout << "\n==================== EXPENSE HISTORY ====================\n";

    if (count == 0) {
        cout << "No transactions found.\n";
        return;
    }

    cout << left
         << setw(5)  << "No."
         << setw(6)  << "ID"
         << setw(14) << "Category"
         << setw(24) << "Description"
         << right << setw(12) << "Amount"
         << "   " << left << setw(12) << "Date"
         << "Time\n";

    cout << string(85, '-') << '\n';

    for (int i = 0; i < count; i++) {
        cout << left
             << setw(5)  << i + 1
             << setw(6)  << ids[i]
             << setw(14) << categories[i]
             << setw(24) << descriptions[i]
             << right << fixed << setprecision(2)
             << setw(12) << amounts[i]
             << "   " << left << setw(12) << dates[i]
             << times[i] << '\n';
    }
}

void showTotal() {
    double total = 0;

    for (int i = 0; i < count; i++) {
        total += amounts[i];
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal spent: Rs. " << total << '\n';
}

int main() {
    int choice;

    do {
        cout << "\n========== EXPENSEX ==========\n";
        cout << "1. Add Expense\n";
        cout << "2. View Transactions\n";
        cout << "3. Show Total Spending\n";
        cout << "4. Exit\n";
        cout << "Select: ";

        if (!(cin >> choice)) {
            cout << "Please enter a valid number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                showTotal();
                break;

            case 4:
                cout << "Thank you for using ExpenseX!\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
