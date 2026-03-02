#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

class GroceryTracker {
public:
   //Constructor loads data and writes backup
   GroceryTracker(const string& inputFileName, const string& backupFileName) {
      inputFile = inputFileName;
      backupFile = backupFileName;

      LoadDataFromFile();//Build frequency map from input file
      WriteBackupFile();//Write frequency map to backup file (frequency.dat)
   }

   //Option 1: Return frequency for one item
   int GetItemFrequency(const string& userItem) const {
      string key = NormalizeItem(userItem);

      auto it = itemFrequencyMap.find(key);
      if (it != itemFrequencyMap.end()) {
         return it->second;
      }
      return 0;//Not found
   }

   //Option 2: Print all items and their frequencies
   void PrintAllFrequencies() const {
      if (itemFrequencyMap.empty()) {
         cout << "No data loaded.\n";
         return;
      }

      for (const auto& pair : itemFrequencyMap) {
         cout << pair.first << " " << pair.second << "\n";
      }
   }

   //Option 3: Print histogram using asterisks
   void PrintHistogram() const {
      if (itemFrequencyMap.empty()) {
         cout << "No data loaded.\n";
         return;
      }

      for (const auto& pair : itemFrequencyMap) {
         cout << pair.first << " ";
         for (int i = 0; i < pair.second; ++i) {
            cout << "*";
         }
         cout << "\n";
      }
   }

   //Static method to print the menu options
   static void PrintMenu() {
      cout << "\nCorner Grocer Analyzer\n";
      cout << "1) Look up an item\n";
      cout << "2) Print all item frequencies\n";
      cout << "3) Print histogram\n";
      cout << "4) Exit\n";
      cout << "Enter choice: ";
   }

private:
   //Private data members
   string inputFile;
   string backupFile;
   map<string, int> itemFrequencyMap; // item -> count

   //Reads the input file and builds the frequency map
   void LoadDataFromFile() {
      ifstream inFS(inputFile);

      if (!inFS.is_open()) {
         cout << "ERROR: Could not open input file: " << inputFile << "\n";
         cout << "Make sure CS210_Project_Three_Input_File.txt is in the same folder as the program.\n";
         return;
      }

      string item;
      while (inFS >> item) {
         //Normalize each word so lookups are consistent
         string normalized = NormalizeItem(item);
         itemFrequencyMap[normalized]++; //Map auto-creates key if missing
      }

      inFS.close();
   }

   //Writes the backup file frequency.dat with item frequencies
   void WriteBackupFile() const {
      ofstream outFS(backupFile);

      if (!outFS.is_open()) {
         cout << "ERROR: Could not create backup file: " << backupFile << "\n";
         return;
      }

      for (const auto& pair : itemFrequencyMap) {
         outFS << pair.first << " " << pair.second << "\n";
      }

      outFS.close();
   }

   //Helper function to normalize item names
   static string NormalizeItem(const string& raw) {
      // Convert to lowercase (simple normalization for consistent keys)
      string result;
      result.reserve(raw.size());

      for (char c : raw) {
         result.push_back(static_cast<char>(tolower(static_cast<unsigned char>(c))));
      }

      return result;
   }
};

int main() {
   //Required file names from the assignment prompt
   const string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
   const string BACKUP_FILE = "frequency.dat";

   //Create tracker (loads file + generates backup automatically)
   GroceryTracker tracker(INPUT_FILE, BACKUP_FILE);

   int choice = 0;

   //Loop until user chooses exit
   while (choice != 4) {
      GroceryTracker::PrintMenu();

      // Validate numeric menu input
      if (!(cin >> choice)) {
         cin.clear();               // Clear fail state
         cin.ignore(10000, '\n');   // Discard bad input
         cout << "Please enter a valid number (1-4).\n";
         continue;
      }

      if (choice == 1) {
         //Option 1: item lookup
         cout << "Enter item to look for: ";
         string item;
         cin >> item;

         int freq = tracker.GetItemFrequency(item);
         cout << item << " appears " << freq << " time(s).\n";
      }
      else if (choice == 2) {
         //Option 2: print all frequencies
         cout << "\nItem Frequencies:\n";
         tracker.PrintAllFrequencies();
      }
      else if (choice == 3) {
         //Option 3: histogram
         cout << "\nHistogram:\n";
         tracker.PrintHistogram();
      }
      else if (choice == 4) {
         //Option 4: exit
         cout << "Exiting program.\n";
      }
      else {
         cout << "Invalid choice. Please select 1-4.\n";
      }
   }

   return 0;
}
