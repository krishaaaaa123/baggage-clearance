

#include<iostream>
#include<string>
#include<vector>
#include<ctime>


using namespace std;

class Baggage {
    private:
      string baggageId;
      bool checkedIn;
      time_t checkInTime;
    
    
    public:
      Baggage(const string& id) : baggageId(id), checkedIn(false), checkInTime(0){}
      
      string getId() const{
          return baggageId;
      }
      bool isCheckedIn() const{
          return checkedIn;
      }
       
       time_t getCheckedInTime() const{
           return checkInTime;
       }
       
       void checkIn() {
           if(!checkedIn){
               checkedIn = true;
               checkInTime = time(nullptr);
               cout<<"Baggage " << baggageId << " checked in at " << asctime(localtime(&checkInTime));
           }
           else{
               cout<<"Baggage"<< baggageId << " is already checked in." << endl;
           }
       }
       void printStatus() const {
           cout << "Baggage ID: " << baggageId << endl;
           cout << "Checked in: " << (checkedIn ? "Yes" : "No") << endl;
           if (checkedIn) {
               cout << "Check-in Time: " << asctime(localtime(&checkInTime));
           }
            cout << "--------------------------------" <<endl;
       }
};

class BaggageScanner {
    public:
        void scanBaggage(const Baggage& baggage) {
            cout << "Scanning baggage " << baggage.getId() << "..." << endl;
        // Perform scanning operations
        // Check for prohibited items, etc.
        
        cout << "Baggage " << baggage.getId() << " scanned successfully." << endl;
        }
};
int main()
{
    // Create baggages
    Baggage baggage1("B001");
    Baggage baggage2("B002");
    
    // Create baggage scanner
    BaggageScanner baggageScanner;
    
    // Check-in baggages
    baggage1.checkIn();
    baggage2.checkIn();
    
    // Scan baggages
    baggageScanner.scanBaggage(baggage1);
    baggageScanner.scanBaggage(baggage2);
    
    // Print baggage's status
    baggage1.printStatus();
    baggage2.printStatus();
    
   
    return 0;
}
