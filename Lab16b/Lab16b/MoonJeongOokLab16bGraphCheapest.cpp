// Lab 16b, Writing A Function For Cheapest Route
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express


#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>

using namespace std;
struct Container
{
	int vertex; // index in database array
	int prev; // index in database array
	double cost;

	bool operator<(const Container& v) const //need operator< for use in priority queue
	{
		return cost > v.cost;
	}
};

struct Vertex
{
	string name;

	bool isVisited;
	list<pair<int, double> > adjacentVertices;
	int prev;
	double cost;
};

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Vertex> database)
{
	pair<stack<int>, double> result; // route, cost
	list<pair<int, double> >::iterator it; // to iterate over adjacentVertices
	//reset the cost and previous indices for all vertices, isVisited to false
	int max = database.size();
	for (int i = 0; i < max; i++)
	{
		database[i].cost = 0;
		database[i].prev = -1;
		database[i].isVisited = false;
	}
	//create priority queue of Container objects
	priority_queue<Container> pqContainer;

	//create a Container object for the start vertex, with 0 cost and negative prev index
	Container startVertex;
	startVertex.vertex = iStart;
	startVertex.cost = 0;
	startVertex.prev = -1;

	//push the start vertex's container onto the priority queue
	pqContainer.push(startVertex);

	//while the priority queue is not empty
	while (pqContainer.empty() == false)
	{
		//peek / pop a container object from the priority queue
		Container currentContainer = pqContainer.top();
		Vertex &currentVertex = database[pqContainer.top().vertex];
		pqContainer.pop();
		
		//if contained object's been visited, "continue"
		if (currentVertex.isVisited == true)
			continue;
		//mark contained object as visited
		currentVertex.isVisited = true;
		//set its cost to that of its container
		currentVertex.cost = currentContainer.cost;
		//set its prev to that of its container
		currentVertex.prev = currentContainer.prev;
		//if contained vertex is the end vertex, exit while - loop
		if (currentContainer.vertex == iEnd)
			break;
		//for each of that vertex's unvisited neighbors
		for (it = currentVertex.adjacentVertices.begin(); it != currentVertex.adjacentVertices.end(); it++)
		{
			if (database[(*it).first].isVisited == false)
			{
				//create a container object for neighbor
				Container neighbor;
				neighbor.vertex = (*it).first;
				//set its cost to that of the vertex, plus edge cost
				neighbor.cost = currentContainer.cost + (*it).second;
				//set its previous to the vertex
				neighbor.prev = currentContainer.vertex;
				//push container onto priority queue
				pqContainer.push(neighbor);
			}
		}
	}
	//the route's cost equals the end vertex's cost
	result.second = database[iEnd].cost;
	//build a stack of entries, starting from the end vertex, back towards the start
	for (int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev)
		result.first.push(vertex);
	return result;
}

int main()
{
	cout << "Lab 16b, Writing A Function For Cheapest Route\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Writing A Function For Cheapest Route\" program" << endl << endl;

	ifstream fin;
	fin.open("cities.txt");
	if (!fin.good()) throw "I/O error";

	// process the input file
	vector<Vertex> database;
	while (fin.good()) // EOF loop
	{
		string fromCity, toCity, cost;

		// read one edge
		getline(fin, fromCity);
		getline(fin, toCity);
		getline(fin, cost);
		fin.ignore(1000, 10); // skip the separator

		// code to eliminate whitespace
		fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
		toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());

		// add vertices for new cities included in the edge
		int iToVertex = -1, iFromVertex = -1, i;
		for (i = 0; i < database.size(); i++) // seek "to" city
			if (database[i].name == fromCity)
				break;

		if (i == database.size()) // not in database yet
		{
			// store the vertex if it is new
			Vertex fromVertex;
			fromVertex.name = fromCity;
			database.push_back(fromVertex);
		}
		iFromVertex = i;

		for (i = 0; i < database.size(); i++) // seek "from" city
			if (database[i].name == toCity)
				break;
		if (i == database.size()) // not in vector yet
		{
			// store the vertex if it is new
			Vertex toVertex;
			toVertex.name = toCity;
			database.push_back(toVertex);
		}
		iToVertex = i;

		// store bi-directional edges
		double edgeCost = atof(cost.c_str());
		database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
		database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
	}
	fin.close();
	cout << "Input file processed\n\n";

	while (true)
	{
		string fromCity, toCity;
		cout << "\nEnter the source city [blank to exit]: ";
		getline(cin, fromCity);
		if (fromCity.length() == 0) break;

		// find the from city
		int iFrom;
		for (iFrom = 0; iFrom < database.size(); iFrom++)
			if (database[iFrom].name == fromCity)
				break;

		cout << "Enter the destination city [blank to exit]: ";
		getline(cin, toCity);
		if (toCity.length() == 0) break;

		// find the destination city
		int iTo;
		for (iTo = 0; iTo < database.size(); iTo++)
			if (database[iTo].name == toCity)
				break;

		//skip the next code block if no matching cites are found
		if (iTo == database.size())
			continue;

		cout << "\nRoute :" << endl;
		pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
		while (!result.first.empty())
		{
			cout << database[result.first.top()].name;
			result.first.pop();
			if (result.first.empty() == false)
				cout << "-";
		}
		cout << "\nTotal miles: " << result.second;
		cout << endl;
	}
}
