#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
/// constants

const double RATE_REGULAR = 5.0;
const double RATE_VIP = 10.0;
const double RATE_DISABLIED = 0.0;
const int TOTAL_SPOTS = 20;
const double MIN_CHARGE = 5.0;

//  struct

struct ParkingSession
{
    std ::string plate;
    int spotNumber;
    int enteryHour;
    int entryMin;
    std ::string spotType;
};

struct Receipt
{
    std ::string plate;
    int spotNumber;
    std ::string entryTime;
    std ::string exitTime;
    double duration; // in hours 1.5
    double totalCost;
};
// DATA STORAGE

std::map<std::string, ParkingSession> activeSessions; // plate -> current session
std ::map<std ::string, std ::vector<Receipt>> history;
std ::map<int, bool> spots; // true empty false
std ::map<int, std::string> spottype;
std::map<int, int> hourlyTraffic;
double totalRevenue;

// helpers

std ::string FromatTime(int hour, int min) //"HH:MM"
{
    std ::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << min;
    return ss.str();
}
double getRate(std ::string spottype)
{
    if (spottype == "VIP")
        return RATE_VIP;
    if (spottype == "DISABLIED")
        return RATE_DISABLIED;
    return RATE_REGULAR;
}
void initSpots()
{
    // i=1  i<15  -> REGULAR  // true sspots;  //true empty fa         spots & spottype
    for (int i = 1; i <= 15; i++)
    {
        spots[i] = true;
        spottype[i] = "REGULAR";
    }

    // i=16  i<18  -> VIP  // true
    for (int i = 16; i <= 18; i++)
    {
        spots[i] = true;
        spottype[i] = "VIP";
    }

    // i=19 i<20  -> DISABLES  // true
    for (int i = 19; i <= 20; i++)
    {
        spots[i] = true;
        spottype[i] = "DISABLED";
    }
}

bool enterParking(std ::string plate, int hour, int min,
                  std ::string Preferredtype = "REGULAR")
{
    //! not parked   return

    if (activeSessions.count(plate))
    {
        std ::cout << "[WARN]" << plate << " is alreadt parked " << std ::endl;
        return false;
    }
    int foundSPot = -1;
    // for( i& : cou)
    // for (key ,value )
    for (auto &[spotNum, available] : spots) // c++17
    {
        if (available && spottype[spotNum] == Preferredtype)
        {
            foundSPot = spotNum;
            break;
        }
    }

    //! Preferredtype  search
    if (foundSPot == -1)
        for (auto &[spotNum, available] : spots) // c++17
        {
            if (available && spottype[spotNum] != "DISABLED")
            {
                foundSPot = spotNum;
                break;
            }
        }
    //! false FULL  return
    if (foundSPot == -1)
    {
        std ::cout << " FULL " << std ::endl;
        return false;
    }
    // spots-> false
    spots[foundSPot] = false;
    ParkingSession Session;

    Session.plate = plate;
    Session.spotNumber = foundSPot;
    Session.enteryHour = hour;
    Session.entryMin = min;
    Session.spotType = spottype[foundSPot];
    // fall data

    //
    // active [platr]
    activeSessions[plate] = Session;
    hourlyTraffic[hour]++;

    std ::cout << "[IN]" << plate << " -> spot  " << foundSPot
               << "  (" << spottype[foundSPot] << ")  "
               << " at " << FromatTime(hour, min) << std ::endl;
    return true;
}

int main()
{

    initSpots();
    enterParking("ABC123", 00, 8, "REGULAR");

    return 0;
}