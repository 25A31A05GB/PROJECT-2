#include <iostream>
#include <string>
using namespace std;

struct Citizen {
    int id;
    int age;
    string name;
    Citizen* next;
};

struct Complaint {
    int id;
    string text;
    string status;
    Complaint* next;
    Complaint* prev;
};

struct WaterRecord {
    int consumerId;
    int units;
    float bill;
    WaterRecord* next;
};

struct ElectricityRecord {
    int consumerId;
    int units;
    float bill;
    ElectricityRecord* next;
};

struct WasteRecord {
    int id;
    string type;
    int quantity;
    WasteRecord* next;
};

Citizen* citizenHead = NULL;
Complaint* complaintHead = NULL;
WaterRecord* waterHead = NULL;
ElectricityRecord* electricityHead = NULL;
WasteRecord* wasteHead = NULL;

void addCitizen() {
    Citizen* node = new Citizen();
    cout << "Enter ID: ";
    cin >> node->id;
    cout << "Enter Name: ";
    cin >> node->name;
    cout << "Enter Age: ";
    cin >> node->age;
    node->next = citizenHead;
    citizenHead = node;
    cout << "Citizen added\n";
}

void displayCitizens() {
    if (citizenHead == NULL) {
        cout << "No citizens found\n";
        return;
    }

    cout << "\nCitizen List\n";
    Citizen* temp = citizenHead;

    while (temp != NULL) {
        cout << temp->id << " | " << temp->name << " | " << temp->age << endl;
        temp = temp->next;
    }
}

void addComplaint() {
    Complaint* node = new Complaint();
    cout << "Enter Complaint ID: ";
    cin >> node->id;
    cin.ignore();
    cout << "Enter Text: ";
    getline(cin, node->text);
    node->status = "Pending";
    node->prev = NULL;
    node->next = complaintHead;

    if (complaintHead != NULL)
        complaintHead->prev = node;

    complaintHead = node;
    cout << "Complaint added\n";
}

void displayComplaints() {
    if (complaintHead == NULL) {
        cout << "No complaints\n";
        return;
    }

    cout << "\nComplaint List\n";
    Complaint* temp = complaintHead;

    while (temp != NULL) {
        cout << temp->id << " | " << temp->text << " | " << temp->status << endl;
        temp = temp->next;
    }
}

void updateComplaintStatus() {
    int id;
    cout << "Enter Complaint ID: ";
    cin >> id;

    Complaint* temp = complaintHead;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Enter new status: ";
            cin >> temp->status;
            cout << "Updated\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Not found\n";
}

void addWaterRecord() {
    WaterRecord* node = new WaterRecord();
    cout << "Enter Consumer ID: ";
    cin >> node->consumerId;
    cout << "Enter Units: ";
    cin >> node->units;
    node->bill = node->units * 2.5;
    node->next = waterHead;
    waterHead = node;
    cout << "Water record added\n";
}

void displayWaterRecords() {
    if (waterHead == NULL) {
        cout << "No water records\n";
        return;
    }

    cout << "\nWater Records\n";
    WaterRecord* temp = waterHead;

    while (temp != NULL) {
        cout << temp->consumerId << " | " << temp->units << " | Rs." << temp->bill << endl;
        temp = temp->next;
    }
}

void addElectricityRecord() {
    ElectricityRecord* node = new ElectricityRecord();
    cout << "Enter Consumer ID: ";
    cin >> node->consumerId;
    cout << "Enter Units: ";
    cin >> node->units;

    if (node->units <= 100)
        node->bill = node->units * 3;
    else if (node->units <= 300)
        node->bill = 100 * 3 + (node->units - 100) * 5;
    else
        node->bill = 100 * 3 + 200 * 5 + (node->units - 300) * 7;

    node->next = electricityHead;
    electricityHead = node;
    cout << "Electricity record added\n";
}

void displayElectricityRecords() {
    if (electricityHead == NULL) {
        cout << "No electricity records\n";
        return;
    }

    cout << "\nElectricity Records\n";
    ElectricityRecord* temp = electricityHead;

    while (temp != NULL) {
        cout << temp->consumerId << " | " << temp->units << " | Rs." << temp->bill << endl;
        temp = temp->next;
    }
}

void addWasteRecord() {
    WasteRecord* node = new WasteRecord();
    cout << "Enter ID: ";
    cin >> node->id;
    cout << "Enter Type: ";
    cin >> node->type;
    cout << "Enter Quantity: ";
    cin >> node->quantity;
    node->next = wasteHead;
    wasteHead = node;
    cout << "Waste added\n";
}

void displayWasteRecords() {
    if (wasteHead == NULL) {
        cout << "No waste records\n";
        return;
    }

    cout << "\nWaste Records\n";
    WasteRecord* temp = wasteHead;

    while (temp != NULL) {
        cout << temp->id << " | " << temp->type << " | " << temp->quantity << endl;
        temp = temp->next;
    }
}

int main() {
    int choice, op;

    do {
        cout << "\nMain Menu\n";
        cout << "1 Citizen\n2 Complaint\n3 Water\n4 Electricity\n5 Waste\n6 Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "1 Add\n2 Display\n";
            cin >> op;
            if (op == 1) addCitizen();
            else displayCitizens();
            break;

        case 2:
            cout << "1 Add\n2 Display\n3 Update\n";
            cin >> op;
            if (op == 1) addComplaint();
            else if (op == 2) displayComplaints();
            else updateComplaintStatus();
            break;

        case 3:
            cout << "1 Add\n2 Display\n";
            cin >> op;
            if (op == 1) addWaterRecord();
            else displayWaterRecords();
            break;

        case 4:
            cout << "1 Add\n2 Display\n";
            cin >> op;
            if (op == 1) addElectricityRecord();
            else displayElectricityRecords();
            break;

        case 5:
            cout << "1 Add\n2 Display\n";
            cin >> op;
            if (op == 1) addWasteRecord();
            else displayWasteRecords();
            break;

        case 6:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
