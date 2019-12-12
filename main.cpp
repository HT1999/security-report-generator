#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <ctime>
#include <vector>

using namespace std;
string nameFirst, nameLast, unitNumber, type, month, day, hour, status2;

string getTime() {
  string time1;
  time_t t = time(0);
  tm* now = localtime(&t);
  now->tm_hour += 20;
  if (now->tm_hour > 24) {
    now->tm_hour -= 24; 
  }
  if (now->tm_min < 10) {
    string time1 = to_string(now->tm_hour) + ":0" + to_string(now->tm_min);
    return time1;
  }
  else {
    string time1 = to_string(now->tm_hour) + ":" + to_string(now->tm_min);
    return time1;
  }
}

string capitalize(string str) {
  for(auto& x: str)
    x = toupper(x);
  return str;
}

class Agent {
  private:
    string name, unit, viewers;
  public:
    Agent();
    Agent(string v, string u, string n) {
      name = n;
      unit = u;
      viewers = v;
    }
    void printEnter(){ 
      ofstream fout("info.txt", ios::app);

      cout << "\nREAL ESTATE AGENT, " << name << ", HERE TO SEE G" << unit << " WITH " << viewers << " VIEWERS" <<". \nBUSINESS CARD TAKEN, AND LOCKBOX G" << unit << " GIVEN." << endl;

      fout << getTime() << "_REAL ESTATE AGENT, " << name << ", HERE TO SEE G" << unit << " WITH " << viewers << " VIEWERS" <<". \nBUSINESS CARD TAKEN, AND LOCKBOX G" << unit << " GIVEN." << endl;
    }
    
    void printLeave() {
      ofstream fout("info.txt", ios::app);
      cout << "\nREAL ESTATE AGENT, " << name << ", RETURNED LOCKBOX G" << unit << " WITH KEY INSIDE." << endl;
      fout << getTime() << "_REAL ESTATE AGENT, " << name << ", RETURNED LOCKBOX G" << unit << " WITH KEY INSIDE." << endl;
    }
    
    string get_unit() {return unit;}
};

string set_name(){
  string fname, lname, name;
  cout << "Enter name: ";
  cin >> fname;
  cin >> lname;
  name = fname + " " + lname;
  name = capitalize(name);
  return name;
}

string set_unit() {
  string unit;
  cout << "Enter unit: ";
  cin >> unit;
  return unit;
}

string set_viewers() {
  string viewers;
  cout << "Enter number of viewers: ";
  cin >> viewers;
  return viewers;
}

string set_type() {
  cout << "Enter type of move (out, in, or delivery): ";
  cin >> type;
  return type;
}

void parking(string hour) {
  ofstream fout("info.txt", ios::app);
  string date, unit, plate, make, colour, names, initials, numOfNights, tracking, fName, lName, light;
  int nights;
  
  cout << "\nEnter data: \n";
  cin >> date;
  
  cin >> hour >> unit >> plate >> make >> colour >> names >> initials >> nights;
  if (nights == 1) 
    numOfNights = "1 NIGHT.";
  else if (nights == 2)
    numOfNights = "2 NIGHTS.";
  

  fout << getTime() << "_ISSUED VISITOR PARKING PERMIT FOR UNIT G" << unit << ", " << names << ". "<< colour << " " << make << ", " << plate << ", " << numOfNights << endl << endl;
  
  cout << hour << endl;
  
  cout << "ISSUED VISITOR PARKING PERMIT FOR UNIT G" << unit << ", " << names << ". "<< colour << " " << make << ", " << plate << ", " << numOfNights << endl << endl;
  
  fout.close();
}

void parcel(string hour) {
  ofstream fout("info.txt", ios::app);
  string unit, tracking, name;
  string trackingString = "PACKAGE WITH TRACKING #";
  int j=0, spacePositions[j];
  unit = set_unit();

  cout << "Enter tracking number(s): ";
  cin.ignore();
  getline(cin, tracking);
  for (int i = 0; i < tracking.length(); ++i) {
    if (tracking[i] == ' '){
      spacePositions[j] = i;
      ++j;
    }
  }

  for (int i = 0; i < j; ++i) {
    trackingString = "PACKAGES WITH TRACKING #";
    tracking.insert(spacePositions[i], ", #");
    spacePositions[i] += 3;
  }
  
  name = set_name();
  
  fout << hour << "_TENANT, " << name << " - UNIT G" << unit << ", PICKED UP PACKAGE WITH TRACKING #" << tracking << "." << endl;
  
  cout << "\nTENANT, " << name << " - UNIT G" << unit << ", PICKED UP " << trackingString << tracking << "." << endl;
  
  fout.close();
}

void cleaner(string hour){
  ofstream fout("info.txt", std::ios_base::app);
  string name, radio, keys;
  cout << "Enter name: ";
  cin >> name;
  name = capitalize(name);
  
  cout << "Enter number of keys: ";
  cin >> keys;
  cout << "Radio?";
  cin >> radio;
  radio = capitalize(radio);
  if (radio == "YES" || radio == "Y") 
    radio = ", 1 MOTOROLA RADIO, AND ";
  else if(radio == "NO" || radio == "N")
    radio = "";

  if (keys == "0") {
    keys = " ";
    if (radio == ", 1 MOTOROLA RADIO, AND ") 
      radio = "DROPPED OFF 1 MOTOROLA RADIO AND ";
    else if (radio == "")
      radio = "";
  }
  else {
    if (radio == ", 1 MOTOROLA RADIO, AND ") 
      keys = " DROPPED OFF " + keys + " KEYS WITH FOB";
    else if (radio == "")
      keys = " DROPPED OFF " + keys + " KEYS WITH FOB AND ";    
  }
  
  
  cout << "\nCLEANER " << name << keys << radio << "SIGNED OUT." << endl << endl;
  
  fout << "\nCLEANER " << name << keys << radio << "SIGNED OUT." << endl << endl;
}

void custom(string hour) {
  ofstream fout("info.txt", ios::app);
  string statement;
  
  cout << "Enter statement: " << endl;
  cin.ignore();
  getline(cin, statement);
  statement = capitalize(statement);
  cout << hour << "  " << statement << endl;
  fout << hour << "_" << statement << endl;

}

void intro(string hour) {
  string fireboxKeys, parcels, lockboxes, radioPrompt;
  int sets, serviceKeys[sets], radios, keysTotal = 11;
  
  cout << "Number of firebox keys (usually 37): ";
  cin >> fireboxKeys;
  keysTotal += atoi(fireboxKeys.c_str());
  
  cout << "Number of SETS of service keys: ";
  cin >> sets;
  
  for (int i = 0; i < sets; ++i) {
    cout << "Enter number of keys for set #" << i+1 << ":";
    cin >> serviceKeys[i];
    keysTotal += serviceKeys[i];
  }
  
  cout << "Number of parcels: ";
  cin >> parcels;
  
  cout << "Number of radios: ";
  cin >> radios;
  if (radios == 0) {
    radioPrompt = "";
  }
  else if (radios == 1) {
    radioPrompt = " 1 MOTOROLA RADIO.";
  }
  else if (radios == 2) {
    radioPrompt = " 2 MOTOROLA RADIOS.";
  }
  else if (radios == 3) {
    radioPrompt = " 3 MOTOROLA RADIOS";
  }
  
  cout << "Number of lockboxes: ";
  cin >> lockboxes;
  
  cout << "\nSITE AUDIT: " << fireboxKeys << " KEYS IN FIREBOX. 1 SET OFF 11 HOME KEYS WITH FOB.";
  for (int i = 0; i < sets; ++i) {
    cout << " 1 SET OF " << serviceKeys[i] << " SERVICE KEYS WITH FOB.";
  }
  cout << " ALL KEYS RECORDED IN KEY LOG, TOTAL NUMBER OF KEYS IS " << keysTotal << "." << radioPrompt << " " << parcels << " PARCELS FOR TENANT PICK-UP. " << lockboxes << " REAL ESTATE AGENT LOCKBOXES. ALL CCTV CAMERAS WORKING OKAY. FIRE PANEL READING SYSTEM NORMAL. " << endl;
}

void movingCheck(string hour) {
  ofstream fout("info.txt", ios::app);
  string items, status;
  cout << "Any problems? (Enter items if problem, enter no if none): ";
  cin.ignore();
  getline(cin, items);
  items = capitalize(items);

  if (items == "N" || items == "NO") {
   cout << "\nCHECKED MOVING ROOM FOR ANY NON-PERMISSIBLE ITEMS. EVERYTHING OK." << endl;
   fout << hour << "_CHECKED MOVING ROOM FOR ANY NON-PERMISSIBLE ITEMS. EVERYTHING OK." << endl;
   return;
  }
  else {
    cout << "\nCHECKED MOVING ROOM FOR ANY NON-PERMISSIBLE ITEMS. FOUND " << items << ". EVERYTHING ELSE OK." << endl;
    fout << hour << "_CHECKED MOVING ROOM FOR ANY NON-PERMISSIBLE ITEMS. FOUND " << items << ". EVERYTHING ELSE OK." << endl;
  return;
  }
  
}

void inspection(string unit, string type, string fname, string lname, string month, string day, string hour, string status, string theTime) {
  ofstream fout("info.txt", ios::app);
  if (type == "OUT") 
    type = "MOVE-OUT";
  else if (type == "IN") 
    type = "MOVE-IN";
  else if (type == "DELIVERY") 
    type = "DELIVERY";
  else if (type == "BBQ" || type == "BARBEQUE")
    type = "BARBEQUE";
  else {
    cout << "Incorrect type of elevator reservation, try again. Exiting...\n";
    return;
  }
  
  
  cout << "\n" << status << "-INSPECTION COMPLETE FOR " << type << " OF UNIT G" << unit << " – " << fname << " " << lname << ". " << month << " " << day << ", " << hour << ".\n";
  fout << theTime << "_" << status << "-INSPECTION COMPLETE FOR " << type << " OF UNIT G" << unit << " – " << fname << " " << lname << ". " << month << " " << day << ", " << hour << ".\n";
}

void clear() {
  ofstream fout("info.txt");
  fout << endl;
  fout.close();
  cout << "File cleared, ready for new reports.\n";
  return;
}

void package(string hour) {
  ofstream fout("info.txt", ios::app);
  string name, unit, tracking;
  unit = set_unit();
  cout << "Enter tracking number: ";
  cin >> tracking;
  name = set_name();

  fout << hour << "_CANADA POST DROPPED OFF A PACKAGE FOR G" << unit << " – " << name <<", TRACKING #" << tracking << ". RECORDED IN CONNECT SYSTEM AND PUT INSIDE 111 CACF ROOM.\n";

  cout << "\nCANADA POST DROPPED OFF A PACKAGE FOR G" << unit << " – " << name <<", TRACKING #" << tracking << ". RECORDED IN CONNECT SYSTEM AND PUT INSIDE 111 CACF ROOM.\n";
  fout.close();
}

void pads() {
  string building;
  cout << "Enter building number (111, 131, 151): ";
  cin >> building;
  cout << "\nWRITER TOOK DOWN ELEVATOR PADS IN BUILDING " << building << ".\n\n";  
}

int main() {
  string choice = "", status;
  vector<Agent> agents;

  do {
    string theTime = getTime();
    cout << "-------------------------------------------------\n";
    cout << "audit, parking, parcel, cleaner, agent, moving, inspect, custom, package: ";
    cin >> choice;
    cout << "-------------------------------------------------\n";
    choice = capitalize(choice);
    
    if (choice == "PARKING" ) 
      parking(theTime);
    else if (choice == "PARCEL") 
      parcel(theTime);
    else if (choice == "CLEANER")
      cleaner(theTime);
    else if (choice == "CUSTOM") 
      custom(theTime);
    else if (choice == "INTRO" || choice == "AUDIT") 
      intro(theTime);
    else if (choice == "AGENT") {
      cout << "Entering or Leaving?\n";
      cin >> status;
      status = capitalize(status);
      if (status == "E") {
        agents.push_back(Agent(set_viewers(), set_unit(), set_name()));
        agents[agents.size()-1].printEnter();
        }
      else if (status == "L") {
        if (agents.size() == 1) {
          agents[0].printLeave();
          continue;
        }
        else if (agents.size() > 1) {
          string compare;
          cout << "Units: ";
          for (int i = 0; i < agents.size(); i++)
            cout << agents[i].get_unit() << "  ";
          cout << "\nUnit that left: ";
          cin >> compare;
          
          for (int i = 0; i < agents.size(); i++) {
            if (compare == agents[i].get_unit()) {
              agents[i].printLeave();
              agents.erase (agents.begin() + i);
              continue;
            }
          }
        }
      }
    }
    else if (choice == "MOVING")
      movingCheck(theTime);
    else if(choice == "INSPECT" || choice == "INSPECTION") {
      
      cout << "Post or pre?";
      cin >> status;
      status = capitalize(status);
      if (status == "PRE") {

        cout << "Enter name: ";
        cin >> nameFirst; 
        cin >> nameLast;
        nameFirst = capitalize(nameFirst);
        nameLast = capitalize(nameLast);
        
        cout << "Enter unit: ";
        cin >> unitNumber;
        
        cout << "Enter type of move (OUT, IN, OR DELIVERY, BBQ): ";
        cin >> type;
        type = capitalize(type);
        
        cout << "Enter month, day, and hour (ex. APRIL 27 3:00 PM TO 6:00 PM): ";
        cin >> month;
        cin >> day;
        month = capitalize(month);
        day = capitalize(day);
        cin.ignore();
        getline(cin, hour);
        hour = capitalize(hour);
        
        inspection(unitNumber, type, nameFirst, nameLast, month, day, hour, status, theTime);
      }
      else if (status == "POST") {
        inspection(unitNumber, type, nameFirst, nameLast, month, day, hour, status, theTime);
      }
    }
    else if (choice == "PACKAGE")
      package(theTime);
    else if (choice == "PADS")
      pads();
    else if (choice == "CLEAR") 
      clear();
    else {
      if (choice == "EXIT") 
        return 0;
      cout << "No such choice is available.\n";
      continue;
    }
  } while (choice != "EXIT");
}