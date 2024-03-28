// including all necessary libraries

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <iomanip>


using namespace std;
int planeLayout[100][100] = { 0 }; // defining global matrix for layout of plane


//function for option of exitting the program
void exitCondition() {

	cout << "Exiting...";
	cout << endl;

}

//main class
class Plane {

	int nrSeats;
	bool Full;
	int planeRows;
	int planeColumns;
	int nrTakenSeats;

public:

	Plane() = default;

	Plane(int _nrSeats, bool _Full, int _planeRows, int _planeColumns, int _nrTakenSeats) {

		nrSeats = _nrSeats;
		Full = _Full;
		planeRows = _planeRows;
		planeColumns = _planeColumns;
		nrTakenSeats = _nrTakenSeats;
	}

	~Plane() {
	}

	//setters

	void set_nrSeats(int _nrSeats) {

		nrSeats = _nrSeats;
	}

	void set_occupancy(bool _Full) {

		Full = _Full;
	}

	void set_rows(int _planeRows) {

		cin >> _planeRows;
		planeRows = _planeRows;
	}

	void set_columns(int _planeColumns) {

		cin >> _planeColumns;
		planeColumns = _planeColumns;
	}

	void set_nrTakenSeats(int _nrTakenSeats) {
		nrTakenSeats = _nrTakenSeats;
	}

	//getters

	int get_nrSeats()
	{
		return nrSeats;
	}

	bool get_occupancy()
	{
		return Full;
	}

	int get_rows() {

		return planeRows;
	}

	int get_columns() {

		return planeColumns;
	}

	int get_nrTakenSeats() {
		return nrTakenSeats;
	}

	//other methods

	void welcoming_MatrixRandomizer();
	void menu();
	void menu2();
	void addTakenSeats();
	void showLayout();

};

//function for showing the layout of the plane useful for certain instances in the program
void Plane::showLayout() {

	cout << "This is the current layout of the plane:  " << endl;
	cout << endl;

	for (int planeRows = 0; planeRows <= 10; planeRows++)
	{
		for (int planeColumns = 0; planeColumns <= 4; planeColumns++)
		{
			if (planeColumns == 1 || planeColumns == 3)
				cout << " ";

			cout << planeLayout[planeRows][planeColumns] << " ";
		}

		cout << endl;
	}
}

//function for increasing the seats which are shown as occupied
void Plane::addTakenSeats() {

	nrTakenSeats++;
}

//main function for the interface of the program
void Plane::welcoming_MatrixRandomizer() {

	Plane p1;
	//seeding the rand() function from the time(0) function
	srand(time(0));

	int planeRows = 0;
	int planeColumns = 0;

	p1.set_nrTakenSeats(0);

	p1.set_nrSeats(55);

	int answer = 0;
	cout << "Welcome. There are a maximum of " << p1.get_nrSeats() << " seats on this plane." << endl;
	cout << endl;

	//setting the layout matrix to 0
	for (int planeRows = 0; planeRows <= 10; planeRows++)
	{
		for (int planeColumns = 0; planeColumns <= 4; planeColumns++)
			planeLayout[planeRows][planeColumns] = 0;
	}

	//randomizing positions in the plane
	for (int i = 0; i <= 54; i++)
	{
		planeRows = rand() % 10;
		planeColumns = rand() % 4;

		//structure for avoiding the counting of duplicate occupied seats
		if (planeLayout[planeRows][planeColumns] == 0)
			p1.addTakenSeats();


		planeLayout[planeRows][planeColumns] = 1;

	}

	cout << "Currently, there are " << p1.get_nrTakenSeats() << " seats taken on this plane. ";
	cout << endl;

	//checking if plane is full through pure chance
	if (p1.get_nrTakenSeats() == p1.get_nrSeats())
		p1.set_occupancy(true);
	else
		p1.set_occupancy(false);

	if (p1.get_occupancy() == true)
		p1.menu2();

	if (p1.get_occupancy() == false || answer == 1)
	{
		p1.showLayout();
		p1.menu();

	}
}

//2nd class detailing info about passengers
class Passenger {

protected:

	string Name;
	float height;
	float weight;
	float budget;

	friend class Economy;
	friend class Business;


public:

	//list of names that can be randomized
	string passengerNames[50] = { "Antony Velasquez", "Eugene O'Connor", "Gerhard Muller", "Mihai Atanasiu",
						"Andre Navarro", "Mikhail Norozovsky", "Andrea Cinetti", "Georgios Papadopulous",
						"Marian Apostol", "Thierry Madras", "Jeane Paulson", "Lisa Ramirez", "Richard Coxley",
						"Atanasia Popov", "Mircea Diaconescu", "Bianca La Paz", "Ongadago Henri", "Wladyslaw Mucek",
						"Bela Horthy", "Theresa Tao", "Kylian Horace", "Rares Tomescu", "Andreea Bucencu", "Natasha Smitova",
						"Volodymyr Mikhalo", "Vlad Popescu", "Mara Tanase", "Adrian Walker", "Recep Peker", "Ahmad Al-Mahmoud",
						"Terrence Yang", "Mito Katamura", "Ida Ratako", "Michelle Platon", "Thomas Henderson", "Ronald Turing",
						"Lyudmila Lublin", "Antonio de Guerra" };


	Passenger() = default;


	Passenger(string _Name, float _height, float _weight, float _budget) {

		Name = _Name;
		height = _height;
		weight = _weight;
		budget = _budget;
	}

	~Passenger() {
	}

	//setters

	void set_Name(string _Name) {
		Name = _Name;
	}

	void set_height(float _height) {
		height = _height;
	}

	void set_weight(float _weight) {
		weight = _weight;
	}

	void set_budget(float _budget) {
		budget = _budget;
	}


	//getters

	string get_name() {
		return Name;
	}

	float get_height() {
		return height;
	}

	float get_weight() {
		return weight;
	}

	float get_budget() {
		return budget;
	}

	//others
	void seat_Assignment();
	void cancellation();
	void info();
	void swappingPlaces();

};

//method related to passenger for showing info about all passengers
void Passenger::info() {

	Plane p1;
	Passenger passenger;
	Passenger p[36]{};

	for (int i = 0; i < 36; i++)
	{

		//randomizing attributes of passenger class
		p[i].set_Name(passengerNames[rand() % 40]);
		passenger.set_height(1.61 + static_cast<float>(rand()) * static_cast<float>(1.98 - 1.61) / RAND_MAX);
		passenger.set_weight(55 + static_cast<float>(rand()) * static_cast<float>(121 - 55) / RAND_MAX);
		passenger.set_budget(162.23 + static_cast<float>(rand()) * static_cast<float>(789.21 - 162.23) / RAND_MAX);

		//displaying results
		cout << endl;
		cout << "Name: " << p[i].get_name() << endl;
		cout << "Height (m): " << setprecision(3) << passenger.get_height() << endl;
		cout << "Weight (kg): " << setprecision(3) << passenger.get_weight() << endl;
		cout << "Budget ($): " << passenger.get_budget() << endl;

	}
}

//function for going back to a certain point in the program
void goBackExit()
{
	Plane p1;
	Passenger passenger;
	int answer = 0;

	cout << "1 - Go back, 2 - Exit" << endl;
	cin >> answer;

	if (answer == 1)
		p1.menu();
	if (answer == 2)
		exitCondition();
}

//method related to passenger for swapping places
void Passenger::swappingPlaces() {

	Plane p1;
	Passenger p[36]{};

	int _planeRows = 0;
	int _planeColumns = 0;

	cout << "What reservations do you want to swap/move? " << endl;

	//selecting first position for the swap
	cout << "Row 1: ";
	p1.set_rows(_planeRows);
	cout << "Column 1: ";
	p1.set_columns(_planeColumns);

	//checking if position is occupied or not
	if (planeLayout[p1.get_rows()][p1.get_columns()] == 0)
	{
		int answer = 0;
		cout << "Invalid choice. That seat is not reserved. Exit ?" << endl;
		cout << "1 - Yes, 2 - No" << endl;

		cin >> answer;

		//if choice no, begin method again
		if (answer == 2)
			swappingPlaces();
		//go to menu if user exits interface
		if (answer == 1)
			p1.menu();
	}
	else
	{
		planeLayout[p1.get_rows()][p1.get_columns()] = 0;

		//selecting second position for swapping
		cout << "Row 2: ";
		p1.set_rows(_planeRows);
		cout << "Column 2: ";
		p1.set_columns(_planeColumns);

		//checking if pairing position is occupied or not
		if (planeLayout[p1.get_rows()][p1.get_columns()] == 0)
		{
			int answer = 0;
			cout << "Do you want to move Mr./Mrs. Velasquez's seat to row and column" << p1.get_rows() << p1.get_columns() << "?" << endl;
			cout << "1 - Yes, 2 - No" << endl;

			cin >> answer;

			if (answer == 1)
			{
				planeLayout[p1.get_rows()][p1.get_columns()] = 1;
				cout << endl;
				p1.showLayout();
				goBackExit();
			}
		}

		else
		{
			//swapping two occupied seats between them
			int answer = 0;
			cout << "Do you want to swap Mr./Mrs. Smitova 's seat with Mr./Mrs. Henderson's? " << endl;
			cout << "1 - Yes, 2 - No" << endl;

			cin >> answer;

			if (answer == 1)
			{
				cout << "Swap complete." << endl;
				goBackExit();
			}

			if (answer == 2)
				p1.menu();
		}

	}
}

//method related to passenger class for the cancellation of a reservation
void Passenger::cancellation() {

	int answer = 0;

	int _planeRows = 0;
	int _planeColumns = 0;

	Plane p1;

	Passenger p[36]{};

	srand(time(0));

	//randomizing owner of seat
	for (int i = 0; i <= 35; i++)
		p[i].set_Name(p[i].passengerNames[rand() % 36]);

	cout << "Please specify the rows and columns of the reservation you'd like to cancel." << endl;
	cout << endl;

	cout << "Rows: ";
	p1.set_rows(_planeRows);
	cout << "Columns: ";
	p1.set_columns(_planeColumns);

	cout << "You are about to cancel Mr./Mrs. " << p[p1.get_rows() * 5 + p1.get_rows()].get_name() << "'s reservation. Proceed?" << endl;
	cout << "1 - Yes, 2 - No";
	cin >> answer;

	if (answer == 2)
		seat_Assignment();

	if (answer == 1)
	{
		cout << "Reservation cancelled succesfully." << endl;
		cout << endl;
		planeLayout[p1.get_rows()][p1.get_columns()] = 0;
		p1.showLayout();
		cout << endl;

		goBackExit();

		answer = 0;
	}

}

//2nd largest method in the program, related to passenger class, the 2nd main interface of the program
//used to assign and select what to do with each seat and passenger and reservation
void Passenger::seat_Assignment() {

	Plane p1;

	Passenger p[36]{};

	srand(time(0));

	//randomizing owner of seats
	for (int i = 0; i < 36; i++)
		p[i].set_Name(p[i].passengerNames[rand() % 36]);

	int answer = 0;

	int _planeRows = 0;
	int _planeColumns = 0;

	cout << "Please choose a free seat, keeping in mind the above layout." << endl;

	cout << "Row: ";
	p1.set_rows(_planeRows);
	cout << "Column: ";
	p1.set_columns(_planeColumns);
	cout << endl;

	//keeping in mind the layout, do or do not create new reservation; takes into account whether if seat is occupied or not
	if (planeLayout[p1.get_rows()][p1.get_columns()] != 0)
	{
		int answer = 0;

		cout << "Seat already taken. Cancel the reservation on that seat?" << endl;
		cout << "1 - Yes, 2 - No, 3 - Exit";
		cin >> answer;

		//exit program
		if (answer == 3)
			exitCondition();

		//decide not to cancel
		if (answer == 2)
		{
			cout << endl;
			cout << "Please choose another seat, keeping in mind the above layout." << endl;
			seat_Assignment();
		}

		//cancel reservation and see whose reservation the user cancels it
		if (answer == 1)
		{
			answer = 0;
			cout << "You are about to cancel Mr./Mrs. " << p[p1.get_rows() * 5 + p1.get_rows()].get_name() << "'s reservation. Proceed?";
			cout << "1 - Yes 2 - No";
			cout << endl;
			cin >> answer;

			//return to interface
			if (answer == 2)
				seat_Assignment();

			//success
			if (answer == 1)
			{
				cout << "Reservation replaced succesfully." << endl;
				cout << endl;
				p1.showLayout();
				cout << endl;
				goBackExit();
			}
		}
	}
	else
	{
		//if seat is empty
		answer = 0;
		cout << "Proceed?" << endl;
		cin >> answer;
		cout << "1 - Yes, 2 - No" << endl;

		if (answer == 1)
		{
			planeLayout[p1.get_rows()][p1.get_columns()] = 1;
			cout << "New reservation successfully done." << endl;
			cout << endl;
			p1.showLayout();
			cout << endl;
			goBackExit();
		}

		if (answer == 2)
			seat_Assignment();


	}

}

//the following two classes take into account the price of the two classes on a plane, business or economy
class Economy : public Passenger {

	float e_startPrice;

public:

	Economy() = default;

	Economy(float _startPrice) {

		e_startPrice = _startPrice;
	}

	~Economy() {
	}

	//setters

	void set_startPrice(float _e_startPrice) {
		e_startPrice = _e_startPrice;
	}

	//getters

	float get_startPrice() {
		return e_startPrice;
	}

};


class Business : public Passenger {

	float b_startPrice;

public:

	Business() = default;

	Business(int _b_nrSeats, float _b_startPrice) {
		b_startPrice = _b_startPrice;
	}

	~Business() {
	}

	//setters

	void set_startPrice(float _b_startPrice) {
		b_startPrice = _b_startPrice;
	}

	//getters

	float get_startPrice() {
		return b_startPrice;
	}


};

//class for creating a new personalized entry

class newEntry : public Passenger {

	//attributes
	string eName;
	float eweight;
	float eheight;
	float ebudget;

public:

	newEntry() = default;

	newEntry(string e_Name, float e_weight, float e_height, float e_budget) {

		eName = e_Name;
		eweight = e_weight;
		eheight = e_height;
		ebudget = e_budget;
	}

	~newEntry() {};

	//setters

	void setName(string _Name) {
		cin >> _Name;
		eName = _Name;
	}

	void setWeight(float e_weight) {
		cin >> e_weight;
		eweight = e_weight;
	}

	void setHeight(float e_height) {
		cin >> e_height;
		eheight = e_height;
	}

	void setBudget(float e_budget) {
		cin >> e_budget;
		ebudget = e_budget;
	}

	//getters

	string getName() {
		return eName;
	}

	float getWeight() {
		return eweight;
	}

	float getHeight() {
		return eheight;
	}

	float getBudget() {
		return ebudget;
	}

	//others
	void checkBusinessOrEconomy();
};

//method related to class newEntry for checking if personalized entry is or itsn't suitable for economy or business or both
void newEntry::checkBusinessOrEconomy() {

	int answer = 0;

	int e_budget = 0;
	int e_height = 0;
	int e_weight = 0;
	string e_Name = " ";

	int _planeRows = 0;
	int _planeColumns = 0;

	newEntry e;
	Business b;
	Economy ec;
	Plane p1;

	b.set_startPrice(500);
	ec.set_startPrice(100);


	float _budget = 0;
	float _height = 0;
	float _weight = 0;
	string _Name = " ";

	cout << "Name: ";
	e.setName(e_Name);
	cout << "Height (m): ";
	e.setHeight(e_height);
	cout << "Weight (kg): ";
	e.setWeight(e_weight);
	cout << "Budget ($): ";
	e.setBudget(e_budget);

	//comparison between price offered and price of business seats
	if (e.getBudget() >= b.get_startPrice())
	{
		cout << "Mr./Mrs. " << e.getName() << " qualifies for a business class seat. The business class seats are the the first two rows. Proceed with reservation?" << endl;
		cout << "1 - Yes, 2 - No" << endl;
		cin >> answer;

		//choose which business seat to make reserve
		if (answer == 1)
		{
			p1.showLayout();
			cout << endl;
			cout << "Choose seat: ";
			cout << "Row: ";
			p1.set_rows(_planeRows);
			cout << "Column: " << endl;
			p1.set_columns(_planeColumns);

			//if seat is already occupied
			if (planeLayout[p1.get_rows()][p1.get_columns()] != 0)
				seat_Assignment();

			//if seat is not occupied
			if (planeLayout[p1.get_rows()][p1.get_columns()] == 0)
			{

				planeLayout[p1.get_rows()][p1.get_columns()] = 1;
				cout << "Reservation succesful. " << endl;
				p1.showLayout();

				goBackExit();
			}
		}
	}

	//seating if price is between 100 and 500 
	if (e.getBudget() >= ec.get_startPrice() && e.getBudget() < b.get_startPrice())
	{
		cout << "Mr./Mrs. " << e.getName() << " qualifies for an economy class seat. The economy class seats are the the first next 9 rows after the first two. Proceed with reservation?" << endl;
		cout << "1 - Yes, 2 - No" << endl;
		cin >> answer;

		if (answer == 1)
		{
			p1.showLayout();
			cout << endl;
			cout << "Choose seat: ";
			cout << "Row: ";
			p1.set_rows(_planeRows);

			//if user chooses business seats
			while (p1.get_rows() < 2)
			{
				int answer = 0;
				cout << "The customer does not qualify for those seats. Proceed with economy class booking?" << endl;
				cout << "1 - Yes, 2 - No" << endl;

				cin >> answer;

				if (answer == 1)
				{
					cout << "Select a row for which the customer qualifies: " << endl;
					p1.set_rows(_planeRows);
				}

				//when user selects good row, exit while loop
			}

			cout << "Column: " << endl;
			p1.set_columns(_planeColumns);

			//reserve chosen seat
			if (planeLayout[p1.get_rows()][p1.get_columns()] != 0)
				seat_Assignment();

			if (planeLayout[p1.get_rows()][p1.get_columns()] == 0)
			{
				planeLayout[p1.get_rows()][p1.get_columns()] = 1;
				cout << "Reservation succesful. " << endl;
				p1.showLayout();

				goBackExit();
			}
		}
	}

	//not having a high enough budget for either
	if (e.getBudget() < ec.get_startPrice())
	{
		cout << "The customer does not qualify for any seat on the airplane." << endl;
		goBackExit();
	}
}

//one of the other main interfaces of the program with which the user interacts
void Plane::menu() {

	Passenger passenger;
	newEntry e;

	int answer = 0;

	cout << endl;
	cout << "What would you like to do? " << endl;
	cout << "1 - Make new reservation, 2 - Swap passengers, 3 - Cancel a reservation, 4 - Request information on all available passengers, 5 - Make new entry, 6 - Exit " << endl;
	cin >> answer;
	cout << endl;

	//choice of what to do with the program
	if (answer == 1)
		passenger.seat_Assignment();

	if (answer == 2)
		passenger.swappingPlaces();

	if (answer == 3)
		passenger.cancellation();

	if (answer == 4)
		passenger.info();

	if (answer == 5)
		e.checkBusinessOrEconomy();

	if (answer == 6)
		exitCondition();
}

//menu for when plane is full. very rare
void Plane::menu2() {

	int answer = 0;

	cout << endl;
	cout << "Plane is full. Modify occupancy? " << endl;
	cout << "1 - Yes, 2 - No. Pressing 2 will exit this interface.";
	cout << endl;

	cin >> answer;

	if (answer == 1)
		menu();

	if (answer == 2)
		exitCondition();
}

int main() {

	//very clean main function; the hard work is done in the above methods and functions
	int nrSeatsTaken = 0;

	Plane p1;

	p1.welcoming_MatrixRandomizer();

	Economy e;
	e.set_startPrice(100);

	return 0;
}