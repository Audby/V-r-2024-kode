#include "MeetingWindow.h"
#include <iostream>

MeetingWindow::MeetingWindow(Point position, int width, int height, const string& title)
	: AnimationWindow{position.x, position.y, width, height, title},

	quitBtn{TDT4102::Point{width - btnW - pad, pad }, btnW, btnH, "Quit" },

	meetingDay      {TDT4102::Point{pad, pad }   	 			  , fieldW, fieldH, "Day       " },
	meetingStart    {TDT4102::Point{pad, pad + (pad + fieldH) * 1}, fieldW, fieldH, "Start time" },
	meetingEnd      {TDT4102::Point{pad, pad + (pad + fieldH) * 2}, fieldW, fieldH, "End time  " },
	meetingLocation {TDT4102::Point{pad, pad + (pad + fieldH) * 3}, fieldW, fieldH, meetingLocations},
	meetingSubject  {TDT4102::Point{pad, pad + (pad + fieldH) * 4}, fieldW, fieldH, "Subject   " },
	meetingLeader   {TDT4102::Point{pad, pad + (pad + fieldH) * 5}, fieldW, fieldH, peopleStrVec},
	meetingNewBtn   {TDT4102::Point{pad, pad + (pad + fieldH) * 6}, btnW * 3/2, btnH, "Add meeting" },
	meetingData     {TDT4102::Point{pad, pad + (pad + fieldH) * 7}, static_cast<unsigned int>(width - pad * 2), fieldH * 7, "All meetings" },

	personName      {TDT4102::Point{pad, pad }, fieldW, fieldH, "Name" },
	personEmail     {TDT4102::Point{pad, pad + (pad + fieldH) * 1}, fieldW, fieldH, "Email" },
	personSeats   	{TDT4102::Point{pad, pad + (pad + fieldH) * 2}, fieldW, fieldH, "Car seats" },
	personNewBtn    {TDT4102::Point{pad, pad + (pad + fieldH) * 3}, btnW * 3/2, btnH, "Add person" },
	personData      {TDT4102::Point{pad, pad + (pad + fieldH) * 5}, static_cast<unsigned int>(width - pad * 2), fieldH * 7, "All persons"},

	createMeetingButton{TDT4102::Point{width - btnW - pad, pad*2 + fieldH}, btnW, btnH, "Meetings"}, 
	createPersonButton {TDT4102::Point{width - btnW - pad, pad*2 + fieldH}, btnW, btnH, "Persons"}
{
	// Felles
	add(quitBtn);
	
	// Nytt møte
	attachMeetingWidget(meetingDay);
	attachMeetingWidget(meetingStart);
	attachMeetingWidget(meetingEnd);
	attachMeetingWidget(meetingLocation);
	attachMeetingWidget(meetingSubject);
	attachMeetingWidget(meetingLeader);
	attachMeetingWidget(meetingNewBtn);
	attachMeetingWidget(createPersonButton);

	quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit,this));
	meetingNewBtn.setCallback(std::bind(&MeetingWindow::cb_new_meeting, this));
	personNewBtn.setCallback(std::bind(&MeetingWindow::cb_new_person, this));
	createMeetingButton.setCallback(std::bind(&MeetingWindow::cb_meetings, this));
	createPersonButton.setCallback(std::bind(&MeetingWindow::cb_persons, this));

	// Møte-liste
	attachMeetingWidget(meetingData);

	// Ny person
	attachPersonWidget(personName);
	attachPersonWidget(personEmail);
	attachPersonWidget(personSeats);
	attachPersonWidget(personNewBtn);
	attachPersonWidget(createMeetingButton);

	// Person-liste
	attachPersonWidget(personData);

	// Initielt vindu
	showPersonPage();
}

MeetingWindow::~MeetingWindow() {}

int getIntegerValue(string value, string nameOfField) {
	int interpretedValue = 0;
	//input validation 
	try {
		interpretedValue = stoi(value);
	}
	catch (...) {
		cout << "ERROR: You entered a non-int value in the field: " + nameOfField << endl;
	}
	return interpretedValue;
}

void MeetingWindow::newMeeting()
{
	int day = getIntegerValue(meetingDay.getText(), "day");
	int start = getIntegerValue(meetingStart.getText(), "start time");
	int end = getIntegerValue(meetingEnd.getText(), "end time");
	
	Campus campus = static_cast<Campus>(stringToCampus.at(meetingLocation.getValue()));
	const string subject = meetingSubject.getText();
	string leaderName = meetingLeader.getValue();

	meetingDay.setText("Day");
	meetingStart.setText("Start");
	meetingEnd.setText("End");
	meetingSubject.setText("Subject");

	if (leaderName == "\0"){
		cout << "Invalid leader!" << endl;
		return;
	}

	for (auto &p : people){
		
		if (p->getName() == leaderName){
			shared_ptr<Person> leader = p;
			meetings.emplace_back(new Meeting{ day, start, end, campus, subject, leader});
		}
	}

	updateMeetingList();
}

void MeetingWindow::newPerson()
{
	int freeSeetCount = getIntegerValue(personSeats.getText(), "Free seats");
	
	Car* carInstanceOrNullptr = nullptr;
	if (freeSeetCount != 0) {
		carInstanceOrNullptr = new Car{ freeSeetCount } ;
	}
	std::unique_ptr<Car> car {carInstanceOrNullptr};

	const string& name = personName.getText();
	const string& email = personEmail.getText();

	personSeats.setText("Car seats");
	personName.setText("Name");
	personEmail.setText("Email");

	people.emplace_back(new Person{ name, email, std::move(car) });

	if(peopleStrVec.at(0)=="\0"){
		peopleStrVec.at(0) = people.back()->getName();

	} else {
		peopleStrVec.emplace_back(people.back()->getName());
	}
	meetingLeader.setOptions(peopleStrVec);
	
	updatePersonList();
}

void MeetingWindow::showMeetingPage()
{
	hideWidgets(personWidgets);

	for (auto* mw : meetingWidgets) {
		mw->setVisible(true);
	}
}

void MeetingWindow::showPersonPage()
{

	for (auto* pw : meetingWidgets) {
		pw->setVisible(false);
	}

	for (auto* pw : personWidgets) {
		pw->setVisible(true);
	}
	hideWidgets(meetingWidgets);	
}

void MeetingWindow::hideWidgets(vector<TDT4102::Widget*>& widgets)
{
	for (auto* w : widgets) {
		w->setVisible(false);
	}
}

void MeetingWindow::updateMeetingList()
{
	stringstream ss;
	for (auto &m : meetings) {
		ss << *m << endl;
	}
	meetingData.setText(ss.str());
}

void MeetingWindow::updatePersonList()
{
	stringstream ss;
	for (auto &p : people) {
		ss << *p << endl;
	}
	personData.setText(ss.str());
}

void MeetingWindow::attachMeetingWidget(TDT4102::Widget& mw)
{
	add(mw);
	meetingWidgets.push_back(&mw);   
}

void MeetingWindow::attachPersonWidget(TDT4102::Widget& pw)
{
	add(pw);
	personWidgets.push_back(&pw);
}

// Callbackfunksjoner
void MeetingWindow::cb_quit()
{
	close();
}

void MeetingWindow::cb_new_meeting()
{
	newMeeting();
}


void MeetingWindow::cb_new_person()
{
	newPerson();
}

void MeetingWindow::cb_meetings()
{
	showMeetingPage();
}

void MeetingWindow::cb_persons()
{
	showPersonPage();
}

void MeetingWindow::printPeople() const {
	for (const auto &person : people) {
		std::cout << *person << endl;
	}
}
