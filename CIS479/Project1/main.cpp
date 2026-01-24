#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

int locX(int val, const int config[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (config[i][j] == val) {
				return j + 1;
			}
		}
	}
};
int locY(int val, const int config[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (config[i][j] == val) {
				return i + 1;
			}
		}
	}
};

int tilesOutOfPlace(const int config[3][3], const int goalConfig[3][3]) {
	int outOfPlace = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (config[i][j] != goalConfig[i][j] && config[i][j] != 0) {
				outOfPlace++;
			}
		}
	}
	return outOfPlace;
};

class State {
private:
	State* p;
	int l;
	int g;
	int h;
	int f;
	int config[3][3];
	int eX;
	int eY;

public:
	State(State* p, int l, int g, int h, int config[3][3]);
	
	void setConfig(const int[3][3]);
	void printState();
	const int(&getConfig() const)[3][3]{return config;}

	State& operator=(const State& n);
	bool operator==(const State& n) const;
	bool operator!=(const State& n) const;
	bool operator>(const State& n) const;
	struct StateHash;
};
bool State::operator>(const State& n) const {
	return f > n.f;
}
bool State::operator==(const State& n) const{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
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

struct State::StateHash {
	std::size_t operator()(const State& s) const {
		std::size_t h = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				h = h * 31 + std::hash<int>()(s.getConfig()[i][j]);
		return h;
	}
};

State& State::operator=(const State& n) {
	p = n.p;
	l = n.l;
	g = n.g;
	h = n.h;
	f = n.f;
	setConfig(n.getConfig());
	eX = n.eX;
	eY = n.eY;
	return *this;
}

State::State(State* p, int l, int g, int h, int config[3][3]) : p(p), l(l), g(g), h(h) {
	setConfig(config);
	f = g + h;
	eX = locX(0, config);
	eY = locY(0, config);
}





void State::setConfig(const int config[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->config[i][j] = config[i][j];
		}
	}
};
void State::printState() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			(config[i][j] == 0) ? std::cout << "-" : std::cout << config[i][j]; std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << g << " | " << h << std::endl;
	std::cout << " #" << l << std::endl;
};




class Agent {
private:
	State* init;
	State* goal;
	std::priority_queue<State, std::vector<State>, std::greater<State>> frontier;
	std::stack<State> solutionSet;
	std::unordered_map<State, int, State::StateHash> exploredSet;
	
	int heuristic(int[3][3]);
public:
	State* getInit() {
		return this->init;
	};
	State* getGoal() {
		return this->goal;
	};

	void setInit(int[3][3]);
	void setGoal(int[3][3]);
};

void Agent::setGoal(int goalConfig[3][3]) {
	goal = new State(nullptr, 1, 0, 0, goalConfig);
}
void Agent::setInit(int initConfig[3][3]) {
	init = new State(nullptr, 1, 0, heuristic(initConfig), initConfig);
}

int Agent::heuristic(int config[3][3]) {
	const int (& goalConfig)[3][3] = goal->getConfig();
	int totalManhattan = 0;
	int x = 0;
	int y = 0;
	int againstWind = 3;
	int withWind = 1;
	int sideWind = 2;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
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

int main() {
	int initConfig[3][3] = { { 1,6,2 },{ 5,7,8 },{ 0,4,3 } };
	int goalConfig[3][3] = { { 7,8,1 },{ 6,0,2 },{ 5,4,3 } };
	Agent a;
	a.setGoal(goalConfig);
	a.setInit(initConfig);

	a.getInit()->printState();
	a.getGoal()->printState();
	

	return 0;
}