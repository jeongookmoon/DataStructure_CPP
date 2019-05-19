// Lab 15a, Breadth First Search
// Programmer: Jeong Ook Moon
// Editor(s) used: VC++ 2015 Express
// Compiler(s) used: VC++ 2015 Express

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Vertex
{
	string name;

	bool isVisited;
	list<int> adjacentVertices;
};

queue<int> doBreadthFirstSearch(int iOriginVertex, vector<Vertex>& database)
{
	// create an empty result queue to return at end of function call
	queue<int> searchOrder; // return this queue of indices
	//	create another queue to store the "to do list"
	queue<int> toDoList;
	//initialize each vertex in database : set to "not visited"
	int max = database.size();
	for (int i = 0; i < max; i++)
	{
		database[i].isVisited = false;
	}
	if (iOriginVertex < 0 || iOriginVertex >= max)
		return searchOrder;
	//mark starting vertex as "visited"
	database[iOriginVertex].isVisited = true;
	//push start vertex's index onto the result queue
	searchOrder.push(iOriginVertex);
	//push start vertex's index onto the "to do list"
	toDoList.push(iOriginVertex);
	Vertex currentVertex;
	//while the "to do list" is not empty
	while (toDoList.empty() != true)
	{
		//peek / pop a vertex from the "to do list"
		currentVertex = database[toDoList.front()];
		toDoList.pop();
		//for each of that vertex's "neighbors"
		for (list<int>::iterator it = currentVertex.adjacentVertices.begin(); it != currentVertex.adjacentVertices.end(); it++)
		{
			//if neighbor has not yet been visited
			if (database[*it].isVisited != true)
			{
				//mark neighbor as visited
				database[*it].isVisited = true;
				// push neighbor onto the result queue
				searchOrder.push(*it);
				//push neighbor onto the "to do list"
				toDoList.push(*it);
			}
		}
	}
	return searchOrder;
}


int main()
{
	cout << "Lab 15a, Breadth First Search Program\n";
	cout << "Programmer: Jeong Ook Moon\n";
	cout << "Editor(s) used: VC++ 2015 Express\n";
	cout << "Compiler(s) used: VC++ 2015 Express\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
	cout << "The \"Breadth First Search\" program" << endl << endl;

	ifstream fin;
	fin.open("cities.txt");
	if (!fin.good()) throw "I/O error";

	// process the input file
	vector<Vertex> database;
	while (fin.good()) // EOF loop
	{
		string fromCity, toCity;

		// read one edge
		getline(fin, fromCity);
		getline(fin, toCity);
		fin.ignore(1000, 10); // skip the line with distance
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
		database[iFromVertex].adjacentVertices.push_back(iToVertex);
		database[iToVertex].adjacentVertices.push_back(iFromVertex);
	}
	fin.close();
	cout << "Input file processed\n\n";

	while (true)
	{
		// get the start city for the search
		string startCity;
		cout << "\nEnter the start city [blank to exit]: ";
		getline(cin, startCity);
		if (startCity.length() == 0) break;

		// find the start city
		int i;
		for (i = 0; i < database.size(); i++)
			if (database[i].name == startCity)
				break;

		// TO DO -- skip the next code blocks if no matching city is found
		if (i == database.size())
			continue;

		// BFS result
		cout << "BFS";
		queue<int> q = doBreadthFirstSearch(i, database);
		while (!q.empty())
		{
			cout << '-' << database[q.front()].name;
			q.pop();
		}
		cout << endl;
	}
}