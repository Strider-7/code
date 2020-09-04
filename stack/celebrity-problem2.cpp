// C++ program to find 
// celebrity in O(n) time 
// and O(1) extra space 
#include <bits/stdc++.h> 
using namespace std; 

// Max # of persons in the party 
#define N 8 

// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
					{0, 0, 1, 0}, 
					{0, 0, 0, 0}, 
					{0, 0, 1, 0} 
}; 

bool knows(int a, int b) 
{ 
	return MATRIX[a][b]; 
} 

// Returns id of celebrity 
int findCelebrity(int n) 
{ 
	// Initialize two pointers 
	// as two corners 
	int a = 0; 
	int b = n - 1; 

	// Keep moving while 
	// the two pointers 
	// don't become same. 
	while (a < b) 
	{ 
		if (knows(a, b)) 
			a++; 
		else
			b--; 
	} 

	// Check if a is actually 
	// a celebrity or not 
	for (int i = 0; i < n; i++) 
	{ 
		// If any person doesn't 
		// know 'a' or 'a' doesn't 
		// know any person, return -1 
		if ( (i != a) && 
				(knows(a, i) || 
				!knows(i, a)) ) 
			return -1; 
	} 

	return a; 
} 

// Driver code 
int main() 
{ 
	int n = 4; 
	int id = findCelebrity(n); 
	id == -1 ? cout << "No celebrity" : 
			cout << "Celebrity ID "
					<< id; 
	return 0; 
} 
