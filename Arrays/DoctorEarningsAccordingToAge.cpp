#include <iostream>
#include <vector>
using namespace std;

int DoctorsEarning(vector<int>& arr)
{
    int income = 0;
    int age;
    while (arr.size() < 20)
    {
        string input;
        getline(cin, input);

        if (input.empty())
        {
            break;
        }
        age = stoi(input);
        if (age <= 0 || age > 120)
        {
            cout << "Invalid age" << endl;
            break;
        }
        if (age < 17)
        {
            income += 200;
        }
        else if (age <= 40)
        {
            income += 400;
        }
        else
        {
            income += 300;
        }
        
        arr.push_back(age);
    }
    return income;
}

int main()
{
    vector<int> arr;
    int totalIncome = DoctorsEarning(arr);
    cout << "Total income " << totalIncome << " INR" << endl;
    return 0;
}
/*
20
56
69  
69
9
1
7
89
119

Total income 2500 INR
*/