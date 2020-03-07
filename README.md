# Cache-Buffer-Design
A cache buffer program written by C

It consists of 4 main parts:
1. Implementation of double linked list nodes and data structure:
In each node; address of the requested page, total number of requests (counter), previous and next
pointers of nodes must be kept. Nodes navigation, counter query, node
operations such as adding and deleting should be done.
2. Solution of the given transaction using the double linked list:
  a. Reading the login information:
    i. Read the requested pages as strings (Ex: ABC, ABE, BCD,…).
    Pages should be readable from a text document line by line.
  b. Processing input:
    i. If the entered page (or 1 line read from the file) is not already in the cache buffer
    is created as a new node, the counter is set to 1, and the start node (head
    node) is added to the cache buffer.
    ii. If the entered page is present in the cache buffer, the counter of the relevant node is increased by 1.
    If the counter exceeds a specified threshold value (Ex: T = 10), this node
    It is assigned as head node in cache buffer. (Previous and next nodes
    markers are also arranged.)
  c. Care of the cache buffer:
    I. Cache buffer has a certain capacity (Ex: L = 20). If this capacity is exceeded,
    The last element (node) of the cache buffer is deleted (check item 2.b.
    be).
3. Cache buffer serving: Whenever a new request arrives, 2.b item is executed and cache
The current version of the buffer is in the form of a linked list, with the contents of the nodes (address and counter) on the screen.
It is shown.
4. Cleaning the Cache Buffer: To clear the cache after listing to the user
should be asked if he wants. If cleaning is approved, all elements in the list
It should be deleted.
Sample:
(In order not to take up space, the entries are shown side by side and not as characters.)
T = 5, L = 4
REQUESTS: A B B A C C A A A A C D E F D G D B
Screen outputs:
A, 1 (A arrived, new node head node is assigned)
B, 1  A, 1 (B arrived, new node head node is assigned)
B, 2  A, 1 (B came, counter increased)
B, 2  A, 2 (A came, counter increased)
C, 1  B, 2  A, 2 (C arrived, new node head node is assigned)
C, 2  B, 2  A, 2 (C came, counter increased)
C, 2  B, 2  A, 3 (A came, counter increased)
C, 2  B, 2  A, 4 (A came, counter increased)
C, 2  B, 2  A, 5 (A came, counter increased)
A, 6  C, 2  B, 2 (A came, counter increased, [T = 5] A assigned as 6 head node)
A, 6  C, 3  B, 2 (C came, counter increased)
D, 1  A, 6  C, 2  B, 2 (D arrived, new node head node is assigned)
E, 1  D, 1  A, 6  C, 2 (E came, new node head node assigned [L = 4] last (5th) node deleted)
F, 1  E, 1  D, 1  A, 6 (F arrived, new node head node assigned [L = 4] last (5th) node deleted)
F, 1  E, 1  D, 2  A, 6 (D arrived, counter increased)
G, 1  F, 1  E, 1  D, 1 (G came, new node head node assigned [L = 4] last (5th) node deleted)
G, 1  F, 1  E, 1  D, 2 (D arrived, counter increased)
B, 1  G, 1  F, 1  E, 1 (B arrived, new node head node assigned [L = 4] last (5th) node deleted)

The expression given in the entry as a string step by step or at a time from the text file
You receive. At the end of each request, cache buffer's existing linked list structure, with the contents of the nodes
print on the screen.
