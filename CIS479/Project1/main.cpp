#include <iostream>

#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>

#include <cmath>
#include <cassert>


const unsigned int yAxis = 3;
const unsigned int xAxis = 3;

enum CartesianDirection {
	LEFT = -1,
	RIGHT = 1,
	UP = -1,
	DOWN = 1
};



int locX(int val, const int config[yAxis][xAxis]) {
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			if (config[i][j] == val) {
				return j + 1;
			}
		}
	}
	assert(false);
};



int locY(int val, const int config[yAxis][xAxis]) {
	for (int i = 0; i < yAxis; i++) {
		for (int j = 0; j < xAxis; j++) {
			if (config[i][j] == val) {
				return i + 1;
			}
		}
	}
	assert(false);
};



class State {
	friend class Agent;
private:
	State* p;
	int expO;
	int g;
	int h;
	int f;
	int config[yAxis][xAxis];
	int eX;
	int eY;
	int ii;
public:
	State();
	State(State*, int, int, int, int, int[yAxis][xAxis]);

	const int(&getConfig() const)[yAxis][xAxis];
	void setConfig(const int[yAxis][xAxis]);
	
	void printState();

	State& operator=(const State& n);
	bool operator==(const State& n) const;
	bool operator!=(const State& n) const;
	struct StateHash;
	struct Comparator;
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





class Agent {
private:
	State init;
	State goal;


	std::priority_queue<State*, std::vector<State*>, State::Comparator> frontier;
	std::unordered_map<State*, int, State::StateHash> exploredSet;
	std::stack<State*> solutionSet;

	std::vector<State*> allocatedMem;
	
	int insertionIndex;
	int tilesOutOfPlace(const int[yAxis][xAxis], const int[yAxis][xAxis]);
	int heuristic(int[yAxis][xAxis]);
public:
	Agent(int[yAxis][xAxis], int[yAxis][xAxis]);
	~Agent();
	void findShortestPath();
	void genChild(State*, std::string);
	void setInit(int[yAxis][xAxis]);
	void setGoal(int[yAxis][xAxis]);
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
			if (config[i][j] == 0) continue;
			x = locX(config[i][j], goalConfig) - locX(config[i][j], config);
			y = locY(config[i][j], goalConfig) - locY(config[i][j], config);

			if (x < 0) {
				x = abs(x);
				x *= withWind;
			}
			else if (x > 0) {
				x *= againstWind;
			}

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
	State* n = new State(*p);
	int x = n->eX - 1;
	int y = n->eY - 1;
	n->ii = insertionIndex++;
	n->p = p;
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

	n->h = heuristic(n->config);
	n->f = n->h + n->g;

	if (exploredSet.count(n) && n->g >= exploredSet[n]) {
		delete n;
		return;
	}

	
	exploredSet[n] = n->g;
	frontier.push(n);
	allocatedMem.push_back(n);
	
}



void Agent::findShortestPath() {
	State* n = &init;
	int expansionOrder = 1;

	while (true) {
		n->expO = expansionOrder++;

		if (*n == goal) { 
			goal = *n; 
			break; 
		}

		if (n->eX > 1) genChild(n, "LEFT");
		if (n->eX < xAxis) genChild(n, "RIGHT");
		if (n->eY > 1) genChild(n, "UP");
		if (n->eY < yAxis) genChild(n, "DOWN");

		n = frontier.top();
		frontier.pop();

		exploredSet[n] = n->g;
	}

	while (*n != init) {
		solutionSet.push(n);
		n = n->p;
	}
};



void Agent::printSolutionSet() {
	init.printState();
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