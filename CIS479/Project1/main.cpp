/*
# Author: Logan Berk
# Creation Date : 1 / 23 / 2026
# Modification Date : 1 / 24 / 2026
# Purpose : Code for Simple Agent used to solve Windy 8-Puzzle Problem with A*
# 
# Modification Date : 1 / 25 / 2026
# Purpose : Modified State class to have arrays that contain x and y coordinates to reduce
# time complexity of locX and locY functions from O(N^2) to O(1), and in turn giving ability
# to reduce the time complexity of tilesOutOfPlace function from O(N^2) to O(N)
#
#################################################################################################
# NOTE: All assignment criterion are listed as /*********ASSIGNMENT CRITERION (3-6)**************
#################################################################################################
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

//Board Dimentions, extensibility is limited to 3x3 due to memory limitations of A*
static const unsigned int yAxis = 3;
static const unsigned int xAxis = 3;

//Define the max numbering range for board eg.. 9 (0-8) 
static const unsigned int nTiles = xAxis*yAxis;

//Defines wind strength weights
enum windStrength {
	WITHWIND = 1,
	SIDEWIND = 2,
	AGAINSTWIND = 3,
};

//Defines movement in cartesian directions
enum CartesianDirection {
	LEFT = -1,
	RIGHT = 1,
	UP = -1, //Up is negative because in an Array grid, UP reduces the y index
	DOWN = 1 //Down is positive because in an Array grid, DOWN increases the y index
};





//State class used to represent the state of the game currently
class State {
	friend class Agent;
private:
	State* p;                 //Parent game state
	int expO;                 //Order of expansion, when popped from queue
	int config[yAxis][xAxis]; //Current board configuration
	int tileX[nTiles];        //Array is indexed as tile numbers, with the value inside being corresponding x coordinate
	int tileY[nTiles];        //Array is indexed as tile numbers, with the value inside being corresponding y coordinate

	int g;                    //g(n), the total path cost so far
	int h;                    //h(n), the current heuristic for configuration
	int f;					  //Evaluation function f(n) = h(n) + g(n) used for priority sorting
	
	int eX;                   //Empty space X coordinate
	int eY;                   //Empty space Y coordinate
	int ii;                   //Insertion index, identifies the order for FIFO in ties (tie breaker)
	
public:
	//Constructors
	State();
	State(int[yAxis][xAxis], State* p = nullptr, int g = 0);

	//Setters for board configuration	
	void setConfig(const int[yAxis][xAxis]);
	void setCoords(const int[yAxis][xAxis]);
	void moveTile(int, int);
	void updateState(State*, int, int, int);
	//Prints gamestate values including board config in predefined manner
	void printState();

	//Necessary overloaded operators and functors
	State& operator=(const State& n);
	bool operator==(const State& n) const;
	bool operator!=(const State& n) const;
	struct StateHash;  //Used to avoid collisions in unordered_map using a simple hash
	struct Comparator; //Used to define minheap ordering and FIFO in ties
};



void State::setConfig(const int config[yAxis][xAxis]) {
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			this->config[i][j] = config[i][j];
		}
	}
}



void State::setCoords(const int config[yAxis][xAxis]) {
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			tileX[config[i][j]] = (j + 1);
			tileY[config[i][j]] = (i + 1);
		}
	}
}


void State::moveTile(int dx, int dy) {
	// reassign standard cartesian indexing to 0 based indexing
	int x = eX - 1;
	int y = eY - 1;

	//Assigning values we want to change
	int& oldVal = config[y][x];

	//Assign our new value to swap, find its x and y coordinates
	int& newVal = config[y + dy][x + dx];

	//Swap values and their coordinates
	std::swap(tileX[oldVal], tileX[newVal]);
	std::swap(tileY[oldVal], tileY[newVal]);
	std::swap(oldVal, newVal);

	eX += dx;               //Shift x based on horizontal direction
	eY += dy;				  //Shift y based on vertical direction
}

State::State() : p(nullptr), expO(0), g(0), h(0), f(0), eX(0), eY(0), ii(0), config{ {0} } {
	for (int t = 0; t < nTiles; t++) {
		tileX[t] = (t % xAxis) + 1;
		tileY[t] = (t / xAxis) + 1;
	}
}



State::State(int config[yAxis][xAxis], State* p, int g) : p(p), g(g) {
	setConfig(config);
	setCoords(config);
	eX = tileX[0];
	eY = tileY[0];
}


void State::updateState(State* p, int w, int h, int ii) {
	/*****************************ASSIGNMENT CRITERION 4**************************************************/
	this->p = p;                 //Update Parent
	this->g += w;                //Update pathcost based on wind
	this->h = h;                 //Update Heuristic
	this->f = h + g;             //Recalculate f(n)
	this->ii = ii;               //Update order of insertion
	/*****************************ASSIGNMENT CRITERION 4**************************************************/
}
struct State::StateHash {
	std::size_t operator()(const State& s) const {
		std::size_t h = 0;
		for (int t = 0; t < nTiles; t++) {
			h = h * 31 + std::hash<int>()(s.tileX[t]);
			h = h * 31 + std::hash<int>()(s.tileY[t]);
		}
		return h;
	}
};



/*****************************ASSIGNMENT CRITERION 6**************************************************/
struct State::Comparator {
	bool operator()(const State* a, const State* b) const {
		//If states are equal break tie with FIFO otherwise order in minheap fashion based on smallest f(n)
		return (a->f == b->f) ? a->ii > b->ii : a->f > b->f;
	}
};
/*****************************ASSIGNMENT CRITERION 6**************************************************/



bool State::operator==(const State& n) const{
	for (int t = 1; t < nTiles; t++) {
		if (tileX[t] != n.tileX[t] || tileY[t] != n.tileY[t]) {
			return false;
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
	setConfig(n.config);
	setCoords(n.config);
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
}




//Agent wrapper class used for high level state handling and solution finding given init and goal 
class Agent {
private:
	State init;
	State goal;

	/*****************************ASSIGNMENT CRITERION 3**************************************************/
	//Storage for search space
	std::priority_queue<State*, std::vector<State*>, State::Comparator> frontier; //next states to explore
	std::unordered_map<State, int, State::StateHash> exploredSet; //states already explored
	/*****************************ASSIGNMENT CRITERION 3**************************************************/

	std::stack<State*> solutionSet; //final storage for solution set, for ease of printing since stack is LIFO

	//Storage vector to keep track of all memory on heap
	std::vector<State*> allocatedMem;
	
	//Index used to keep track of when a state was inserted for tie breaks
	int insertionIndex;
	int locX(int val, State& s);
	int locY(int val, State& s);
	//tilesOutOfPlace helper function used inside heuristic to find all tiles currently not in correct spot
	int tilesOutOfPlace(const State& curr, const State& goal);

	//Calculates provided heuristic formula based on board configuration
	int heuristic(State& s);
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


	

//Function used for locating x coordinate in cartesian representation (1 based indexing)
int Agent::locX(int val, State& s) {
	return s.tileX[val];
}


//Function used for locating y coordinate in cartesian representation (1 based indexing)
int Agent::locY(int val, State& s) {
	return s.tileY[val];
}

void Agent::setGoal(int goalConfig[yAxis][xAxis]) {
	goal = State(goalConfig);
}



void Agent::setInit(int initConfig[yAxis][xAxis]) {
	init = State(initConfig);
	init.h = heuristic(init);
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



int Agent::tilesOutOfPlace(const State& curr, const State& goal) {
	int outOfPlace = 0;
	for (int t = 1; t < nTiles; t++) {
		if (curr.tileX[t] != goal.tileX[t] || curr.tileY[t] != goal.tileY[t]) {
			outOfPlace++;
		}
	}
	return outOfPlace;
}



int Agent::heuristic(State& s) {
	int totalManhattan = 0;
	int x = 0;
	int y = 0;
	for(int t = 1; t < nTiles; t++){
			x = locX(t, goal) - locX(t, s); //calculate x param of manhattan before absolute value
			y = locY(t, goal) - locY(t, s); //calculate y param of manhattan before absolute value

			//Identify if the difference is negative, this gives an idea of direction
			if (x < 0) {
				x = abs(x);
				x *= WITHWIND;
			}
			else if (x > 0) {
				x *= AGAINSTWIND;
			}

			//Since vertical distance is the same cost UP or DOWN there is only one handler
			if (y != 0) {
				y = abs(y);
				y *= SIDEWIND;
			}
			totalManhattan += (x + y);
	}
	return totalManhattan + tilesOutOfPlace(s, goal);
}



void Agent::genChild(State* p, std::string d) {
	//make a pointer that is a copy of the passed in parent
	State* n = new State(*p); 

	int dx = 0; //horizontal direction offset
	int dy = 0; //vertical direction offset
	int w = 0; //wind cost
	
	//Direction handlers updating internal state of the copied pointer to represent new child
	if (d == "LEFT") {
		dx = LEFT;
		w = WITHWIND;
	}
	if (d == "RIGHT") {
		dx = RIGHT;
		w = AGAINSTWIND;
	}
	if (d == "UP") {
		dy = UP;
		w = SIDEWIND;
	}
	if (d == "DOWN") {
		dy = DOWN;
		w = SIDEWIND;
	}
	
	n->moveTile(dx, dy);
	n->updateState(p, w, heuristic(*n), insertionIndex++);

	//If the generated child is in the explored set and the path cost
	//for the current child, g(n), is greater than or equal to the old child 
	//delete it and skip it 
	if (exploredSet.count(*n) && n->g >= exploredSet[*n]) {
		delete n;
		return;
	}

	/*****************************ASSIGNMENT CRITERION 5**************************************************/
	//Update the explored set, frontier, and keep track of memory allocated
	exploredSet[*n] = n->g;
	frontier.push(n);
	allocatedMem.push_back(n);
	/*****************************ASSIGNMENT CRITERION 5**************************************************/
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
		exploredSet[*n] = n->g;
	}

	//Once we hit our goal we want to push the solution path into the solutionSet
	while (n != nullptr) {
		solutionSet.push(n);
		n = n->p;
	}
}



void Agent::printSolutionSet() {
	//Pop our solution set off the stack
	while (!solutionSet.empty()) {
		solutionSet.top()->printState();
		solutionSet.pop();
	}
}



int main() {
	int initConfig[yAxis][xAxis] = { { 1,6,2 },{ 5,7,8 },{ 0,4,3 } };
	int goalConfig[yAxis][xAxis] = { { 7,8,1 },{ 6,0,2 },{ 5,4,3 } };

	Agent a(initConfig, goalConfig);
	a.findShortestPath();
	a.printSolutionSet();
	

	return 0;
}