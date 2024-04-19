#include "Car.h"
#include <vector>

enum class Campus{Trondheim, Aalesund, Gjovik};

std::ostream& operator<<(std::ostream& os, const Campus& c);

class Meeting 
{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector<std::shared_ptr<Person>> participants;
public:
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    std::string getSubject() const;
    Campus getLocation() const;
    std::shared_ptr<Person> getLeader() const;
    void addParticipant(const std::shared_ptr<Person>& p);
    Meeting(const int& d, const int& start, const int& end, const Campus& l, const std::string& s,
    const std::shared_ptr<Person>& leader, std::vector<std::shared_ptr<Person>>& participants);
    std::vector<std::string> getParticipantList();
};

std::ostream&operator<<(std::ostream& os, const Meeting& m);