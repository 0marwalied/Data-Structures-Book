#include <iostream>

using namespace std;

// Function to solve the Tower of Hanoi problem
// Parameters:
// n: Number of disks
// frompeg: The peg from which the disk is moved
// topeg: The peg to which the disk is moved
// auxpeg: The auxiliary peg used for temporary storage
void towers(int n, char frompeg, char topeg, char auxpeg) {
	// Base case: If only one disk, move it directly from 'frompeg' to 'topeg'
	if (n == 1) {
		cout << "Move disk 1 from peg " << frompeg << " to peg " << topeg << '\n';
		return;
	}

	// Recursive step: Move n-1 disks from 'frompeg' to 'auxpeg' using 'topeg' as auxiliary
	towers(n - 1, frompeg, auxpeg, topeg);

	// Move the nth disk from 'frompeg' to 'topeg'
	cout << "Move disk " << n << " from peg " << frompeg << " to peg " << topeg << '\n';

	// Move the n-1 disks from 'auxpeg' to 'topeg' using 'frompeg' as auxiliary
	towers(n - 1, auxpeg, topeg, frompeg);
}

int main() {
	// Calling the Tower of Hanoi function with 3 disks
	// Pegs are labeled as 'A', 'C', and 'B'
	towers(3, 'A', 'C', 'B');
	return 0;
}