# Monocles-and-Misers
A text based game revolving around the idea of building and developing settlements

I created this game as a way to practice implementing the union-find and symbol table data structures in c.

# Union-Find

For this data structure, I utilized weighted quick-union with path compression. This allows the union-find algorithm to run at a near O(1) with amortized performance.

### Quick-Union

Quick-Union is an implementation of Union-Find that links nodes (in this case, array elements) into "trees" that allow for the find algorithm to not have to go through every element of the array in order to link two nodes. To do this, the element at index i is the index for the next element in the tree. When when ```arr[i] == i``` then the root of the node in question has been found. While this seems like a great implementation in and of itself, the "find" algorithm would still have a worst case runtime of O(N). To address this issue, I implemented weighted union and path compression.

### Weighted Quick-Union

This implementation keeps track of tree sizes using a separate array ```size[]```. When determining which tree to connect to which root, the union algorithm will check which tree is smaller by checking the values at ```size[i]``` and ```size[j]``` and connecting the smaller tree to the larger tree. This essentially allows for O(logN) performance.

### Path Compression

Path compression is a quick and cheap way of giving a near O(1) runtime performance if amortized time is considered. Fortunately, it required very little code to implement. I simply added another for loop in the findRoot() function that changes the element of each index examined to the id of root. Thus, guaranteeing near constant time performance with the added note that the construction of the Quick-Union array and the size array still take O(N) time. 

# Things that need to be addressed:

* Currently there are a lot of limitations on array sizes, but I plan on implementing dynamic resizing at a later date.
* Refactor the code to utilize direct pointers for function parameters
