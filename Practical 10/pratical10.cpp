// Assignment 10 - Sequential file Organization
// AIM: To implement program for Sequential Access File

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class StudentDatabase {
private:
    int roll;
    char name[50];
    char div[5];
    char add[100];
    char dob[15];
    float per;
    char grade;

public:
    void read_data() {
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter division: ";
        cin.getline(div, 5);
        cout << "Enter address: ";
        cin.getline(add, 100);
        cout << "Enter date of birth: ";
        cin.getline(dob, 15);
        cout << "Enter percentage: ";
        cin >> per;
        cout << "Enter grade: ";
        cin >> grade;
    }

    void print_data() const {
        cout << "Roll No: " << roll << ", Name: " << name
             << ", Division: " << div << ", Address: " << add
             << ", DOB: " << dob << ", Percentage: " << per
             << ", Grade: " << grade << endl;
    }

    void write() {
        string filename = "StudentData.dat";
        if (recordExists(roll, filename)) {
            cout << "Record with this roll number already exists." << endl;
            return;
        }
        ofstream outFile(filename, ios::binary | ios::app);
        outFile.write((char*)this, sizeof(StudentDatabase));
        outFile.close();
        cout << "Record added successfully." << endl;
    }

    void read() {
        string filename = "StudentData.dat";
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "File not present." << endl;
            return;
        }

        while (inFile.read((char*)this, sizeof(StudentDatabase))) {
            print_data();
        }
        inFile.close();
    }

    bool recordExists(int rollToCheck, const string& filename) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) return false;

        while (inFile.read((char*)this, sizeof(StudentDatabase))) {
            if (roll == rollToCheck) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
        return false;
    }

    void delet(int rollToDelete) {
        string filename = "StudentData.dat";
        ifstream inFile(filename, ios::binary);
        ofstream tempFile("Temp.dat", ios::binary);

        if (!inFile) {
            cout << "File not present." << endl;
            return;
        }

        bool found = false;
        while (inFile.read((char*)this, sizeof(StudentDatabase))) {
            if (roll != rollToDelete) {
                tempFile.write((char*)this, sizeof(StudentDatabase));
            } else {
                found = true;
            }
        }

        inFile.close();
        tempFile.close();

        remove(filename.c_str());
        rename("Temp.dat", filename.c_str());

        if (found)
            cout << "Record deleted successfully." << endl;
        else
            cout << "Record not found." << endl;
    }

    void search(int rollToSearch) {
        string filename = "StudentData.dat";
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "File not present." << endl;
            return;
        }

        bool found = false;
        while (inFile.read((char*)this, sizeof(StudentDatabase))) {
            if (roll == rollToSearch) {
                print_data();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Record not found." << endl;
        }

        inFile.close();
    }
};

int main() {
    StudentDatabase db;
    int choice, roll;

    do {
        cout << "\n1. Add a record" << endl;
        cout << "2. Display all records" << endl;
        cout << "3. Search a record" << endl;
        cout << "4. Delete a record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                db.read_data();
                db.write();
                break;
            case 2:
                db.read();
                break;
            case 3:
                cout << "Enter roll number to search: ";
                cin >> roll;
                db.search(roll);
                break;
            case 4:
                cout << "Enter roll number to delete: ";
                cin >> roll;
                db.delet(roll);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}


/* OUTPUT:

1. Add a record
2. Display all records
3. Search a record
4. Delete a record
5. Exit
Enter your choice: 1
Enter roll number: 35
Enter name: shreyash
Enter division: b
Enter address: pune
Enter date of birth: 90
Enter percentage: 90
Enter grade: A
Record added successfully
1. Add a record
2. Display all records
3. Search a record
4. Delete a record
5. Exit
Enter your choice: 2
Roll No: 35, Name: shreyash, Division: b, Address: pune, DOB: 90, Percentage: 90, Grade: A
1. Add a record
2. Display all records
3. Search a record
4. Delete a record
5. Exit
Enter your choice: 1
Enter roll number: 35
Record with this roll number already exists
1. Add a record
2. Display all records
3. Search a record
4. Delete a record
5. Exit
Enter your choice: 3
Enter roll number to search: 35
Roll No: 35, Name: shreyash, Division: b, Address: pune, DOB: 90, Percentage: 90, Grade: A
1. Add a record
2. Display all records
3. Search a record
4. Delete a record
5. Exit
Enter your choice: 4
Enter roll number to delete: 2
Record not found.
1. Add a record
2. Display all records
3. Search a record
4. Delete a record
5. Exit
Enter your choice: 5
Exiting...
*/    
