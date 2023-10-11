// C++ program to find largest
// rectangle with all 1s
// in a binary matrix
#include <bits/stdc++.h>
using namespace std;

int A[1001][1001];
int N, M;

// Finds the maximum area under 
// the histogram represented
// by histogram. See below article for details.

int maxHist(int row[])
{
	// Create an empty stack. 
	// The stack holds indexes of
	// hist[] array/ The bars stored 
	// in stack are always
	// in increasing order of their heights.
	stack<int> result;

	int top_val; // Top of stack

	int max_area = 0; // Initialize max area in current
	// row (or histogram)

	int area = 0; // Initialize area with current top

	// Run through all bars of given histogram (or row)
	int i = 0;
	while (i < M) {
		// If this bar is higher than the bar on top stack,
		// push it to stack
		if (result.empty() || row[result.top()] <= row[i])
			result.push(i++);

		else {
			// If this bar is lower than top of stack, then
			// calculate area of rectangle with stack top as
			// the smallest (or minimum height) bar. 'i' is
			// 'right index' for the top and element before
			// top in stack is 'left index'
			top_val = row[result.top()];
			result.pop();
			area = top_val * i;

			if (!result.empty())
				area = top_val * (i - result.top() - 1);
			max_area = max(area, max_area);
		}
	}

	while (!result.empty()) {
		top_val = row[result.top()];
		result.pop();
		area = top_val * i;
		if (!result.empty())
			area = top_val * (i - result.top() - 1);

		max_area = max(area, max_area);
	}
	return max_area;
}

// Returns area of the largest rectangle with all 1s in
// A[][]
int maxRectangle()
{
	// Calculate area for first row and initialize it as
	// result
	int result = maxHist(A[0]);

	// iterate over row to find maximum rectangular area
	// considering each row as histogram
	for (int i = 1; i < N; i++) {

		for (int j = 0; j < M; j++)

			// if A[i][j] is 1 then add A[i -1][j]
			if (A[i][j])
				A[i][j] += A[i - 1][j];

		// Update result if area with current row (as last
		// row) of rectangle) is more
		result = max(result, maxHist(A[i]));
	}

	return result;
}

void input() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> A[i][j];
        }
    }
}

// Driver code
int main()
{
	input();
	cout << maxRectangle();
	return 0;
}

