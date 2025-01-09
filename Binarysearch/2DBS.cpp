

// The extremely naive approach is to traverse the matrix as usual using nested 
// loops and for every single row count the number of 1’s. Finally, 
// we will return the row with the maximum no. of 1’s. 
// If multiple rows contain the maximum no. of 1’s we will return the row with the minimum index.

// We are going to use the Binary Search algorithm to optimize the approach.

// The primary objective of the Binary Search algorithm is to efficiently 
// determine the appropriate half to eliminate, thereby reducing the search
//  space by half. It does this by determining a specific condition that ensures 
//  that the target is not present in that half.

// We cannot optimize the row traversal but we can optimize the counting of 1’s for each row.

// Instead of counting the number of 1’s, we can use the following formula to calculate 
// the number of 1’s:
// Number_of_ones = m(number of columns) - first occurrence of 1(0-based index).

// As, each row is sorted, we can find the first occurrence of 1 in each row using any
//  of the following approaches:

// lowerBound(1) (ref: Implement Lower Bound)
// upperBound(0) (ref: Implement Upper Bound)
// firstOccurrence(1) (ref: First and Last Occurrences in Array)
// Note: Here, we are going to use the lowerBound() function to find the first occurrence.
// You can use the other methods as well.