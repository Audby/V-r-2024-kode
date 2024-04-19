#include "Meeting.h"

std::ostream& operator<<(std::ostream& os, const Campus& c) {
    switch (c) {
        case Campus::Trondheim:
            os << "Trondheim";
            break;
        case Campus::Aalesund:
            os << "Aalesund";
            break;
        case Campus::Gjovik:
            os << "Gjovik";
            break;
        default:
            os << "Unknown Campus";
    }
    return os;
}

int Meeting::getDay() const {
    return day;
}

int Meeting::getStartTime() const {
    return startTime;
}

int Meeting::getEndTime() const {
    return endTime;
}

Campus Meeting::getLocation() const {
    return location;
}

std::string Meeting::getSubject() const {
    return subject;
}

std::shared_ptr<Person> Meeting::getLeader() const {
    return leader;
}

void Meeting::addParticipant(const std::shared_ptr<Person>& p) {
    participants.push_back(p);
}

Meeting::Meeting(const int& d, const int& start, const int& end, const Campus& l, const std::string& s,
const std::shared_ptr<Person>& leader, std::vector<std::shared_ptr<Person>>& participants) : day(d), 
startTime(start), endTime(end), location(l), subject(s), leader(leader), participants(participants)
{}

//3e): Siden vi her bruker "shared_ptr" så vil referansetelleren til pekeren slettes, hvis det er ingen
//referanser til den pekeren. Denne typen peker håndterer minne automatisk, slik at når pekeren får
//en færre referanse eller ingen, så vil den allokere mindre minne deretter.

std::vector<std::string>& Meeting::getParticipantList() const {
    std::vector<std::string> names;
    std::shared_ptr<Person> leder = getLeader();
    std::string lederNavn = leder->getName();
    names.push_back(lederNavn);
    for (int i = 0; i<participants.size(); i++) {
        names.push_back(participants[i]->getName());
    }
    return names;
}

std::ostream&operator<<(std::ostream& os, const Meeting& m) {
    os << "Tema: " << m.getSubject();
    os << "Lokasjon: " << m.getLocation() << " dato: " << m.getDay();
    os << "Starter: " << m.getStartTime() << " og slutter: " << m.getEndTime();
    os << "Ledet av: " << m.getLeader();
    auto participants = m.getParticipantList();
    for (const auto& name : participants) {
        os << name << ", ";
    }
}