#include <iostream>

#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

#include <cmath>
#include <cassert>


const unsigned int yAxis = 3;
const unsigned int xAxis = 3;

//Defines movement in cartesian directions
enum CartesianDirection {
	LEFT = -1,
	RIGHT = 1,
	UP = -1, //Up is negative because in an Array grid, UP reduces the y index
	DOWN = 1 //Down is positive because in an Array grid, DOWN increases the y index
};


//Function used for locating x coordinate in cartesian representation (1 based indexing)
int locX(int val, const int config[yAxis][xAxis]) {
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			if (config[i][j] == val) {
				return j + 1;
			}
		}
	}
	assert(false); //Program ends if unexpected behavior occurs, eg.. a programmer is searching for a val that DNE
};


//Function used for locating y coordinate in cartesian representation (1 based indexing)
int locY(int val, const int config[yAxis][xAxis]) {
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			if (config[i][j] == val) {
				return i + 1;
			}
		}
	}
	assert(false); //Program ends if unexpected behavior occurs, eg.. a programmer is searching for a val that DNE
};


//State class used to represent the state of the game currently
class State {
	friend class Agent;
private:
	State* p;                 //Parent game state
	int expO;                 //Order of expansion, when popped from queue
	int g;                    //g(n), the total path cost so far
	int h;                    //h(n), the current heuristic for configuration
	int f;					  //Evaluation function f(n) = h(n) + g(n) used for priority sorting
	int config[yAxis][xAxis]; //Current board configuration
	int eX;                   //Empty space X coordinate
	int eY;                   //Empty space Y coordinate
	int ii;                   //Insertion index, identifies the order for FIFO in ties (tie breaker)
public:
	//Constructors
	State();
	State(State*, int, int, int, int, int[yAxis][xAxis]);

	//Getter and setter for board configuration
	const int(&getConfig() const)[yAxis][xAxis];
	void setConfig(const int[yAxis][xAxis]);
	
	//Prints gamestate values including board config in predefined manner
	void printState();

	//Necessary overloaded operators and functors
	State& operator=(const State& n);
	bool operator==(const State& n) const;
	bool operator!=(const State& n) const;
	struct StateHash;  //Used to avoid collisions in unordered_map using a simple hash
	struct Comparator; //Used to define minheap ordering and FIFO in ties
};



const int(&State::getConfig() const)[yAxis][xAxis]{
	return config; 
}



void State::setConfig(const int config[yAxis][xAxis]) {
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			this->config[i][j] = config[i][j];
		}
	}
};



State::State() : p(nullptr), expO(0), g(0), h(0), f(0), config{ { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } }, eX(0), eY(0), ii(0) {};



State::State(State* p, int expO, int g, int h, int ii, int config[yAxis][xAxis]) : p(p), expO(expO), g(g), h(h), ii(ii) {
	setConfig(config);
	f = g + h;
	eX = locX(0, config);
	eY = locY(0, config);
}



struct State::StateHash {
	std::size_t operator()(const State* s) const {
		std::size_t h = 0;
		for (int i = 0; i < yAxis; i++)
			for (int j = 0; j < xAxis; j++)
				h = h * 31 + std::hash<int>()(s->getConfig()[i][j]);
		return h;
	}
};



struct State::Comparator {
	bool operator()(const State* a, const State* b) const {
		//If states are equal break tie with FIFO otherwise order in minheap fashion
		return (a->f == b->f) ? a->ii > b->ii : a->f > b->f;
	}
};



bool State::operator==(const State& n) const{
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			if (config[i][j] != n.config[i][j]) {
				return false;
			}
		}
	}
	return true;
}



bool State::operator!=(const State& n) const{
	return !(*this == n);
}



State& State::operator=(const State& n) {
	p = n.p;
	expO = n.expO;
	g = n.g;
	h = n.h;
	f = n.f;
	setConfig(n.getConfig());
	eX = n.eX;
	eY = n.eY;
	return *this;
}



void State::printState() {
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			(config[i][j] == 0) ? std::cout << "-" : std::cout << config[i][j]; std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << g << " | " << h << std::endl;
	std::cout << " #" << expO << std::endl;
	std::cout << std::endl;
};




//Agent wrapper class used for high level state handling and solution finding given init and goal 
class Agent {
private:
	State init;
	State goal;

	//Storage for search space
	std::priority_queue<State*, std::vector<State*>, State::Comparator> frontier; //next states to explore
	std::unordered_map<State*, int, State::StateHash> exploredSet; //states already explored
	std::stack<State*> solutionSet; //final storage for solution set, for ease of printing since stack is LIFO

	//Storage vector to keep track of all memory on heap
	std::vector<State*> allocatedMem;
	
	//Index used to keep track of when a state was inserted for tie breaks
	int insertionIndex;

	//tilesOutOfPlace helper function used inside heuristic to find all tiles currently not in correct spot
	int tilesOutOfPlace(const int[yAxis][xAxis], const int[yAxis][xAxis]);

	//Calculates provided heuristic formula based on board configuration
	int heuristic(int[yAxis][xAxis]);
public:
	//Agent constructor, and destructor
	Agent(int[yAxis][xAxis], int[yAxis][xAxis]);
	~Agent();

	//Searching Algorithm
	void findShortestPath();
	//Child generation function handles which child to generate and when to skip
	void genChild(State*, std::string);

	//Setters for Agent constructor parameters allowing setting of various inital and goal states
	void setInit(int[yAxis][xAxis]);
	void setGoal(int[yAxis][xAxis]);

	//Printer for solution set, essentially popping off the stack one by one
	void printSolutionSet();
};



void Agent::setGoal(int goalConfig[yAxis][xAxis]) {
	goal = State(nullptr, 1, 0, 0, 0, goalConfig);
}



void Agent::setInit(int initConfig[yAxis][xAxis]) {
	init = State(nullptr, 1, 0, heuristic(initConfig), 0, initConfig);
}



Agent::Agent(int initConfig[yAxis][xAxis], int goalConfig[yAxis][xAxis]) {
	setGoal(goalConfig);
	setInit(initConfig);
}



Agent::~Agent() {
	for (State* alloc : allocatedMem) {
		delete alloc;
	}
}



int Agent::tilesOutOfPlace(const int config[yAxis][xAxis], const int goalConfig[yAxis][xAxis]) {
	int outOfPlace = 0;
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			if (config[i][j] != goalConfig[i][j] && config[i][j] != 0) {
				outOfPlace++;
			}
		}
	}
	return outOfPlace;
};



int Agent::heuristic(int config[yAxis][xAxis]) {
	const int(&goalConfig)[yAxis][xAxis] = goal.getConfig();
	int totalManhattan = 0;
	int x = 0;
	int y = 0;
	int againstWind = 3;
	int withWind = 1;
	int sideWind = 2;
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			if (config[i][j] == 0) continue; //Skip empty space
			x = locX(config[i][j], goalConfig) - locX(config[i][j], config); //find x param of manhattan before absolute value
			y = locY(config[i][j], goalConfig) - locY(config[i][j], config); //find y param of manhattan before absolute value

			//Identify if the difference is negative, this gives an idea of direction
			if (x < 0) {
				x = abs(x);
				x *= withWind;
			}
			else if (x > 0) {
				x *= againstWind;
			}

			//Since vertical distance is the same cost UP or DOWN there is only one handler
			if (y != 0) {
				y = abs(y);
				y *= sideWind;
			}
			totalManhattan += (x + y);
		}
	}
	return totalManhattan + tilesOutOfPlace(config, goalConfig);
};



void Agent::genChild(State* p, std::string d) {
	//make a pointer that is a copy of the passed in parent
	State* n = new State(*p); 

	// reassign standard cartesian indexing to 0 based indexing
	int x = n->eX - 1;
	int y = n->eY - 1;

	//increment current states insertion index and assign its parent
	n->ii = insertionIndex++;
	n->p = p;

	//Direction handlers updating internal state of the copied pointer to represent new child
	if (d == "LEFT") {
		n->g++;
		n->config[y][x] = n->config[y][x + LEFT];
		n->config[y][x + LEFT] = 0;
		n->eX += LEFT;
	}
	if (d == "RIGHT") {
		n->g += 3;
		n->config[y][x] = n->config[y][x + RIGHT];
		n->config[y][x + RIGHT] = 0;
		n->eX += RIGHT;
	}
	if (d == "UP") {
		n->g += 2;
		n->config[y][x] = n->config[y + UP][x];
		n->config[y + UP][x] = 0;
		n->eY += UP;
	}
	if (d == "DOWN") {
		n->g += 2;
		n->config[y][x] = n->config[y + DOWN][x];
		n->config[y + DOWN][x] = 0;
		n->eY += DOWN;
	}

	//Update all childrens heuristic based on new configuration and also update their f(n)
	n->h = heuristic(n->config);
	n->f = n->h + n->g;

	//If the generated child is in the explored set and the path cost
	//for the current child, g(n), is greater than or equal to the old child 
	//delete it and skip it 
	if (exploredSet.count(n) && n->g >= exploredSet[n]) {
		delete n;
		return;
	}

	//Update the explored set, frontier, and keep track of memory allocated
	exploredSet[n] = n->g;
	frontier.push(n);
	allocatedMem.push_back(n);
	
}



void Agent::findShortestPath() {
	State* n = &init; //Point to the initial State
	int expansionOrder = 1;

	while (true) {
		//Increment after each State is expanded from and update its order
		n->expO = expansionOrder++;

		//If we reach the goal reassign our goal so its pointing to correct parents and exit
		if (*n == goal) { 
			goal = *n; //Mainly to keep solution path continuity within Agent not strictly necessary
			break; 
		}

		//Generate child based on empty spaces possible moves
		if (n->eX > 1) genChild(n, "LEFT");
		if (n->eX < xAxis) genChild(n, "RIGHT");
		if (n->eY > 1) genChild(n, "UP");
		if (n->eY < yAxis) genChild(n, "DOWN");

		//Reassign our pointer to the item at the front of the frontier
		n = frontier.top();
		//Remove from frontier
		frontier.pop();
		//Update explored set
		exploredSet[n] = n->g;
	}

	//Once we hit our goal we want to push the solution path into the solutionSet
	while (n != nullptr) {
		solutionSet.push(n);
		n = n->p;
	}
};



void Agent::printSolutionSet() {
	//Pop our solution set off the stack
	while (!solutionSet.empty()) {
		solutionSet.top()->printState();
		solutionSet.pop();
	}
};



int main() {
	int initConfig[yAxis][xAxis] = { { 1,6,2 },{ 5,7,8 },{ 0,4,3 } };
	int goalConfig[yAxis][xAxis] = { { 7,8,1 },{ 6,0,2 },{ 5,4,3 } };

	Agent a(initConfig, goalConfig);
	a.findShortestPath();
	a.printSolutionSet();
	

	return 0;
}