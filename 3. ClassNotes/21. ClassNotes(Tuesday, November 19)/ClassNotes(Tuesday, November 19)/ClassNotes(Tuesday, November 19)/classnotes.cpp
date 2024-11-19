#include <iostream>

using namespace std;

int main() {

	// Simulations
	// time 0 is beginning of simulation
	// units of time should be appropriate
	// Statistical information using probability theory is incorporated into model used to generate events that reflect real world scenarios
	// Arrival time and durration, but not departure time
	//TIME   EVENT
	//20      Cus 1 enters, begins transaction (calculate depart after 6min)
	//22      Cus 2 enters, joins queue
	//23      Cus 3 enters, joins queue
	//26      Cus 1 departs, Cus 2 begins transaction (calculate depart after 4min)
	//30      Cus 2 departs, Cus 3 begins transaction (calculate depart after 2min)
	//        Cus 4 enters, joins queue
	//32      Cus 3 departs, Cus 4 begins transaction (calculate depart after 3min)
	//35      Cus 4 departs
	//
	//customer wait time is elapsed time between arrival in the bank and start of the transaction
	//Cus 1 wait time: 0 min

	//This kind of simulation is concerned with 
	//arrival events: customer arrives at the bank externally generated
	//	no wait, go directly to teller
	//	wait, join back of queue
	//Departure events
	//
	//Simulations must repeatedly determine times at which events occur and process them when they do occur
	//In simulations and gaming this is refered to as an event loop
	//
	//time-driven simulation
	// detemine arrival and departure times at random and compare to clock increment clock by 1 to simulate time passing
	//event-driven simulation
	// file contains arrival times and transaction times
	// no actions required between event so clock jumps
	// keep an event queue
	//  contains all arrival and departure events that will happen
	//  stored in accending order
	// Event-driven simulation requires 2 queues
	// an example
	// arrival
	// departure
	//
	//When making a queue you would want to create a class that is a queue and then you can impliment queues as you want
	//
	//ADTs are either position oriented or value oriented
	//	position
	//		stack
	//		queue
	//		list
	//	value
	//		sorted list
	//		priority queue
	//
	//Sorting Algorithms
	//	selection
	//	bubble
	//	insertion
	//	quick
	//	merge
	//	heap
	//
	// Linear Best case O(1) Worst Case O(n)
	// Binary Best case O(1) Worst Case O(logn)
	// Hashing Best case O(1) Worst Case O(n)
	//

	return 0;
}