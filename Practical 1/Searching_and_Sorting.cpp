/* Consider a student database of SEIT class (at least 15 records). Database contains different fields of
every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (Use
   Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list
of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. 
   (all the student records having the presence of search key should be displayed) */

#include <iostream>
#include <cstring>

using namespace std;

struct Student {
    unsigned int rollno;
    char name[50];
    float SGPA;
};

class SDB {
private:
    Student* s;
    int n;

public:
    SDB(int size) {
        n = size;
        s = new Student[n];
    }
    ~SDB() {
        delete[] s;
    }

    void accept_data();
    void display_data();
    void bubblesort();
    void insertionsort();
    void quickSort(int low, int high);
    int partition(int low, int high);
    void searchSGPA(float sgpa);
    int binarySearch(const char* name);
};

void SDB::accept_data() {
    cout << "Enter Details of Students:" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter Roll Number: ";
        cin >> s[i].rollno;
        cout << "Enter Name: ";
        cin >> s[i].name;
        cout << "Enter SGPA: ";
        cin >> s[i].SGPA;
    }
}

void SDB::display_data() {
    cout << endl << "RollNo\tName\tSGPA" << endl;
    for (int i = 0; i < n; i++) {
        cout << s[i].rollno << "\t" << s[i].name << "\t" << s[i].SGPA << endl;
    }
}

void SDB::bubblesort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].rollno > s[j + 1].rollno) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

void SDB::insertionsort() {
    for (int i = 1; i < n; i++) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && strcmp(s[j].name, key.name) > 0) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

int SDB::partition(int low, int high) {
    float pivot = s[high].SGPA;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (s[j].SGPA > pivot) {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}

void SDB::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void SDB::searchSGPA(float sgpa) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i].SGPA == sgpa) {
            cout << "RollNo: " << s[i].rollno << ", Name: " << s[i].name << ", SGPA: " << s[i].SGPA << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students with this SGPA: " << sgpa << endl;
    }
}

int SDB::binarySearch(const char* name) {
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        int res = strcmp(s[mid].name, name);

        if (res == 0) {
            int i = mid;
            while (i >= 0 && strcmp(s[i].name, name) == 0) {
                cout << "RollNo: " << s[i].rollno << ", Name: " << s[i].name << ", SGPA: " << s[i].SGPA << endl;
                i--;
            }
            i = mid + 1;
            while (i < n && strcmp(s[i].name, name) == 0) {
                cout << "RollNo: " << s[i].rollno << ", Name: " << s[i].name << ", SGPA: " << s[i].SGPA << endl;
                i++;
            }
            return mid;
        }
        else if (res < 0) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << "Student not found." << endl;
    return -1;
}

int main() {
    int num;
    cout << "Enter number of students: ";
    cin >> num;

    SDB s(num);
    char name[50];
    float sgpa;

    s.accept_data();
    
    // Sorting by Roll Number using Bubble Sort
    cout << "\nSorted by Roll Number (Bubble Sort):" << endl;
    s.bubblesort();
    s.display_data();
    
    // Sorting by Name using Insertion Sort
    cout << "\nSorted by Name (Insertion Sort):" << endl;
    s.insertionsort();
    s.display_data();

    // Sorting by SGPA using Quick Sort and displaying top Students
    cout << "\nTop 10 students sorted by SGPA (Quick Sort):" << endl;
    s.quickSort(0, num - 1);
    s.display_data();
    
    // Searching students by SGPA
    cout << "\nEnter SGPA to search: ";
    cin >> sgpa;
    s.searchSGPA(sgpa);

    // Searching students by name using Binary Search
    cout << "\nEnter name to search: ";
    cin >> name;
    s.binarySearch(name);

    return 0;
}
