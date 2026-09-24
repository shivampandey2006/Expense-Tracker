#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{

  vector<vector<string>> expenses;

  while (true)
  {
    cout << "== Expenses tracker ==" << endl;
    cout << endl;
    cout << "1. Add Expenses" << endl;
    cout << "2. Display All The Expenses" << endl;
    cout << "3. Calculate Total Expenditure" << endl;
    cout << "4. Find Highest Expenses" << endl;
    cout << "5. Exit" << endl;

    int choose;
    cin >> choose;
    if (choose == 1)
    {

      string expense_name;
      string expense_category;
      string expense_amount;

      cout << "Enter Expense Name: ";
      cin >> ws;
      getline(cin, expense_name);

      cout << "Enter Category: ";
      getline(cin, expense_category);

      cout << "Enter Amount: ";
      cin >> expense_amount;

      expenses.push_back({expense_name, expense_category, expense_amount});

      cout << "Expense added successfully!" << endl;
    }

    else if (choose == 2) {

    if (expenses.empty()) {
        cout << "No expenses found!" << endl;
    }
    else {
        cout << "\n----- All Expenses -----\n";

        for (int i = 0; i < expenses.size(); i++) {

            cout << i + 1 << ". "
                 << expenses[i][0]
                 << " | Category: " << expenses[i][1]
                 << " | Amount: Rs. " << expenses[i][2]
                 << endl;
        }
    }
}
    else if (choose == 3)
    {
      double total = 0;

      for (int i = 0; i < expenses.size(); i++)
      {
        total += stod(expenses[i][2]);
      }

      cout << "Total Expenditure: Rs. " << total << endl;
    }
    else if (choose == 4)
    {
      if (expenses.empty())
      {
        cout << "No expenses recorded.\n";
      }
      else
      {
        double highest = 0;

        for (int i = 0; i < expenses.size(); i++)
        {
          highest = max(highest, stod(expenses[i][2]));
        }

        cout << "\n----- Highest Expenses -----\n";

        for (int i = 0; i < expenses.size(); i++)
        {

          if (stod(expenses[i][2]) == highest)
          {

            cout << "Name: " << expenses[i][0] << endl;
            cout << "Category: " << expenses[i][1] << endl;
            cout << "Amount: Rs. " << expenses[i][2] << endl;
          }
        }
      }
    }
    else if (choose == 5)
    {
      cout << "Thank you for using Expense Tracker!\n";
      break;
    }
    else
    {
      cout << " Invalid choice. Try again.\n";
    }
  }
  return 0;
}