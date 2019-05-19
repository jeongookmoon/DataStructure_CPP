// Lab 12, Writing A Customer Service Simulation
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <iostream>
#include <iomanip>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <array>
#include <stack>


using namespace std;
//Create a struct or class to represent a customer.
//Include these data members : arrival time, service time, and completion time, all as whole numbers. 
struct Customer
{
	int arrivaltime; //"Arrival time" is the clock time that the customer arrives to be placed in the wait queue. 
	int servicetime;
	//"Service time" is the clock time that the customer's service starts, either by arriving when a server is idle, 
	//or by moving out of the wait queue. Service time should be initialized to zero, 
	//and set only when service actually begins for the customer.
	int completiontime;
	//"Completion time" is the clock time that the customer's service ends.Completion time should be initialized to zero,
	//and set only when service actually ends for the customer.
	char idtag;

	bool inUse; //= false;

	Customer() :arrivaltime(-1), servicetime(-1), completiontime(-1), idtag('*'), inUse(false){}
};


//Customers arrive at the specified average arrival rate from the beginning of the simulation
//until the specified clock time at which new arrivals stop.
//After that time there are no new arrivals, but the simulation continues,
//allowing the wait queue to empty.

//In a customer object, also include an ID tag for the customer, 
//stored as a single letter of the alphabet, A - Z.
//Assign A to the first - created customer, B to the next, and so on.
//After the 26th customer is assigned Z, start the IDs over again
//that is, assign A to the 27th customer.
//HINT: use a variable to count the #of customers ever created
//(e.g., n, and get the corresponding ID code with(char)('A' + (n++ % 26)).


//Create a struct or class to represent a service event, 

class ServiceEvent
{
private:
	int clocktime; // clock time(whole number) for the event(i.e., completed service) to take place, 
	int servernumber; //and the server number(0 - based index).

public:
	// operator< actually does an operator> to make a default priority queue do a min queue
	ServiceEvent();
	bool operator<(const ServiceEvent &)const;
	int getTime()const;
	int getServerNumber() const;
	void setTime(int val);
	void setServerNumber(int val);
};
ServiceEvent::ServiceEvent()
{
	clocktime = 0;
	servernumber = 0;
}
int ServiceEvent::getTime() const
{
	return clocktime;
}
int ServiceEvent::getServerNumber() const
{
	return servernumber;
}

bool ServiceEvent::operator<(const ServiceEvent &val)const // not sure what to put inside.
{
	// Does a ! ( *this < val )
	if (clocktime > val.clocktime) return true;
	return false;
}
void ServiceEvent::setTime(int val)
{
	clocktime = val;
}
void ServiceEvent::setServerNumber(int val)
{
	servernumber = val;
}


//Use an STL queue to represent the single wait queue.
//The queue should store customer objects.
//Use an STL priority_queue to store the service events that get scheduled each time service begins.
//Use a stack, queue, list, or vector(your choice) to store customer objects 
//after service is completed.
//It will be iterated over to determine the average time from arrival to end of service per served customer.
int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
	int requests = 0;
	double probOfnRequests = exp(-averageRequestsPerTimeStep);
	for (double randomValue = (double)rand() / RAND_MAX; (randomValue -= probOfnRequests) > 0.0; probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
	return requests;
}
char GetNextID()
{
	static int counter = 0;
	return 'A' + counter++ % 26;
}

int main()
{
	cout << "Lab 12, Writing A Customer Service Simulation\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing A Customer Service Simulation\" program" << endl << endl;

	//When you use srand in a program, make sure to call it only once.The best place to put the call to srand is as the first statement in main.
	srand((unsigned int)time(NULL));
	rand;
		
	ifstream fin;
	fin.open("simulation.txt");

	if (!fin.good())
		throw(exception(" Error, can't open the file!"));

	int numberofservers, maxqueuelength, minservicetime, maxservicetime, stopComingTime;
	double customerarrivalrate, expectedturnawaytime;
	int linecounter = 0;

	//Read 6 input values from a text file simulation.txt that you will write -- one value per line.
	while (fin.good())
	{
		linecounter++;
		string line;
		getline(fin, line); // read the input values from a text file, one per line, in the order specified above.
		if (linecounter == 1)
		{	
			// the number of servers(1 or more, whole number)
			numberofservers = atoi(line.c_str());
		}
		if (linecounter == 2)
		{
			// the average arrival rate of customers, per minute(greater than 0.0, floating point)
			customerarrivalrate = atof(line.c_str());
		}
		if (linecounter == 3)
		{
			// the maximum length of the wait queue(1 or more, whole number)
			maxqueuelength = atoi(line.c_str());
		}
		if (linecounter == 4)
		{
			// the minimum service time interval, in minutes(1 or more, whole number)
			minservicetime = atoi(line.c_str());
		}
		if (linecounter == 5)
		{
			// the maximum service time interval, in minutes(>= minimum service time interval, whole number)
			maxservicetime = atoi(line.c_str());
		}
		if (linecounter == 6)
		{
			// the clock time at which new arrivals stop, in minutes(>0, whole number)
			stopComingTime = atoi(line.c_str());
		}
	}
	
	// declare and create and assign arrays and queues to be used in the solution
	
	//Use an STL priority_queue to store the service events that get scheduled each time service begins
	// This is a minQueue. And the priority_queue defaults to a maxQueue.
	priority_queue<ServiceEvent> EventQueue;
	
	// Use a stack, queue, list, or vector (your choice) to store customer objects after service is completed.
	//It will be iterated over to determine the average time from arrival to end of service per served customer.
	queue<Customer> CustomerInfo;

	//Create the server array as a vector of customer objects to represent the customers being served by each server.
	//When a customer is removed from the wait queue, you'll copy that customer to a chosen position in the server array. 
	//Include another corresponding vector of boolean values, set to true if the server at that index position is busy serving a customer, 
	//false otherwise, indicating that the server is idle. (There's more than one way to accomplish this, so use a different way if you wish).
	vector<Customer> ServerArray(numberofservers);
	
	//Use an STL queue to represent the single wait queue. The queue should store customer objects
	queue<Customer> WaitQueue;
	
		
	int numofturnedaway = 0;

	// the clock time loop
	for (int time = 0;; time++)
	{
		//The simulation should pause after each minute's summary is outputted,
		//enabling the user to press ENTER to continue to the next minute, 
		//or to type x or X and then press ENTER to end the simulation. 
		//Do not let the simulation end after new arrivals stop arriving -- only end the program upon the user's x or X.

		// handle all service events scheduled to complete at this clock time (?)

		while (EventQueue.empty() != true && EventQueue.top().getTime() == time) //	while (event queue is not empty AND clock time of the top service event equals the current clock time)
		{
			//		remove the top service event from the queue
			int serverNumber = EventQueue.top().getServerNumber();
			EventQueue.pop();

			//		determine the server associated with the removed service event
			//		set this server's current customer's completion time to the current clock time
			ServerArray[serverNumber].completiontime = time;
			//		copy this server's current customer to the served customers queue
			CustomerInfo.push(ServerArray[serverNumber]);

			//		set this server to idle
			ServerArray[serverNumber].inUse = false;
		}
		// handle new arrivals -- can be turned away if wait queue is at maximum length!
		// if time is less than the time at which new arrivals stop
		if (time < stopComingTime)
		{
			// get the #of of arrivals from the Poisson process(a whole number >= 0) --see the lecture topic notes!
			int numofarrivals = getRandomNumberOfServiceRequests(customerarrivalrate);
			// for each new arrival
			for (int i = 0; i < numofarrivals; i++)
			{
				// if the wait queue is full
				if (WaitQueue.size() >= maxqueuelength)
					// "turn away the customer" by adding one to the count of turned away customers
					numofturnedaway++;
				// else
				else
				{
					// create a new customer object, setting its arrival time equal to the current clock time
					Customer newcustomer;
					newcustomer.arrivaltime = time;
					newcustomer.completiontime = 0;
					newcustomer.servicetime = 0;
					newcustomer.inUse = true;
					newcustomer.idtag = GetNextID();
					// copy the new customer to the wait queue
					WaitQueue.push(newcustomer);
				}
			}
		}
		// for idle servers, move customer from wait queue and begin service
		// for each server
		for (int i = 0; i < numberofservers; i++)
		{
			// if (server is idle AND the wait queue is not empty)
			if (ServerArray[i].inUse == false && WaitQueue.empty() != true)
			{
				// remove top customer from wait queue
				Customer temp;
				temp = WaitQueue.front();
				temp.inUse = true;

				WaitQueue.pop();
				// copy it to the server array
				ServerArray[i] = temp;

				// set the copied customer's service time to the current clock time
				ServerArray[i].servicetime = time;

				// use random number generation to determing the service time interval for the customer
				int intervalTime = minservicetime + rand() % (maxservicetime - minservicetime + 1);
				// create a new service event for the server, for the current clock time PLUS the service time interval
				ServiceEvent newService;
				newService.setTime(intervalTime + time);
				newService.setServerNumber(i);
				// add the service event to the event queue
				EventQueue.push(newService);
			}
		}
		// output the summary

		// output the current time
		cout << "Time : " << time << endl;

		// output a heading for the visual prepresentation of the servers and the wait queue
		cout << "---------------------------" << endl;
		cout << setw(3) << "line" << " " << setw(3) << "now serving" << " " << setw(3) << "wait queue" << endl;
		cout << setw(3) << "----" << " " << setw(3) << "-----------" << " " << setw(3) << "----------" << endl;

		// for each server
		for (int i = 0; i < numberofservers; i++)
		{
			// output the server's index number (zero-based)
			// show the ID of the customer being served by that server(blank if idle)
			// for server 0 only, show the IDs of customers in the wait queue

			cout << setw(3) << i << " ";
			if (ServerArray[i].inUse == true)
			{
				cout << setw(7) << ServerArray[i].idtag << " ";
			}
			queue<Customer> tempQueue = WaitQueue;

			if (i == 0)
			{
				cout << setw(10);
				for (int j = 0; j < tempQueue.size(); j++)
				{
					cout << tempQueue.front().idtag;
					tempQueue.pop();
				}
			}
			cout << endl;
		}
		cout << "---------------------------" << endl;


		// summarize performance
		//	if time is greater than zero
		if (time > 0)
		{
			queue<Customer> tempQueue = CustomerInfo;
			// iterate over the served customers to get the average time between arrival and completion
			double timesForAvg = 0.0;
			int i = 0;
			while (tempQueue.size() != 0)
			{
				timesForAvg = timesForAvg + (tempQueue.front().completiontime - tempQueue.front().arrivaltime);
				tempQueue.pop();
				i++;
			}
			double avgTimeofServing = 0.0;
			if (i > 0)
			avgTimeofServing = timesForAvg / i;
			// and if any, output the average of their "completion time" minus their "arrival time"
			cout << "Avg time: " << 1.0*avgTimeofServing << ". ";
			// output the rate of customers turned away as total turned away divided by the current time
			cout << "Turn away per minute: " << 1.0*numofturnedaway / time << endl;
		}
		// if the user wants to quit, break out of this loop
		cout << "Press enter to continue, press x or X to exit..." << endl;
		string answer;
		getline(cin, answer);
		if (answer == "x" || answer == "X")
			break;
	}
	cin.get();
}