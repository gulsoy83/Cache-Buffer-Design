# Cache-Buffer-Design
A cache buffer program.

It consists of 4 main parts:

I. Implementation of double linked list nodes and data structure:
In each node; address of the requested page, total number of requests (counter), previous and next pointers of nodes must be kept. Nodes navigation, counter query, node operations such as adding and deleting should be done.


II. Solution of the given operation using the double linked list:
* a. Reading the input:
    1. Read the requested pages as strings (Ex: ABC, ABE, BCD,…). Pages should be readable from a text document too (line by line).
* b. Processing input:
  1. If the entered page (or 1 line read from the file) is not already in the cache buffer, it will be created as a new node in the cache, it's counter is set to 1, and the start node (head node) will be set as that node.
  2. If the entered page is present in the cache buffer, the counter of the relevant node is increased by 1. If the counter exceeds a specified threshold value (Ex: T = 10), this node will be assigned as head node in cache buffer. (Previous and next node's markers are also arranged.)
* c. Maintanence of the cache buffer:
    1. Cache buffer has a certain capacity (Ex: L = 20). If this capacity is exceeded, the last element (node) of the cache buffer will be deleted (should be controlled in step 2.b).


III. Service of the Cache buffer: Whenever a new request arrives, step 2.b is executed. and cache the current version of the buffer is in the form of a linked list, with the contents of the nodes (address and counter) on the screen is shown.


IV. Cleaning the Cache Buffer: To clear the cache (after listing items to the user), user should be asked first. If cleaning is approved, all elements in the list will be deleted.

***

Sample:
(In order not to take up space, the entries are shown side by side, not as new line.)

(T threshold, L capacity of cache, <-> prev and next links)
T = 5, L = 4
REQUESTS: A B B A C C A A A A C D E F D G D B


Screen outputs:
* A, 1 (A arrived, new node hassigned as head node)
* B, 1 <-> A, 1 (B arrived, new node assigned as head node)
* B, 2 <-> A, 1 (B came, counter increased)
* B, 2 <-> A, 2 (A came, counter increased)
* C, 1 <-> B, 2 <-> A, 2 (C arrived, new node assigned as head node)
* C, 2 <-> B, 2 <-> A, 2 (C came, counter increased)
* C, 2 <-> B, 2 <-> A, 3 (A came, counter increased)
* C, 2 <-> B, 2 <-> A, 4 (A came, counter increased)
* C, 2 <-> B, 2 <-> A, 5 (A came, counter increased)
* A, 6 <-> C, 2 <-> B, 2 (A came, counter increased, [T = 5] A assigned as 6 head node)
* A, 6 <-> C, 3 <-> B, 2 (C came, counter increased)
* D, 1 <-> A, 6 <-> C, 2 <-> B, 2 (D arrived, new node assigned as head node)
* E, 1 <-> D, 1 <-> A, 6 <-> C, 2 (E came, new node assigned as head node [L = 4] last (5th) node deleted)
* F, 1 <-> E, 1 <-> D, 1 <-> A, 6 (F arrived, new node assigned as head node [L = 4] last (5th) node deleted)
* F, 1 <-> E, 1 <-> D, 2 <-> A, 6 (D arrived, counter increased)
* G, 1 <-> F, 1 <-> E, 1 <-> D, 1 (G came, new node assigned as head node [L = 4] last (5th) node deleted)
* G, 1 <-> F, 1 <-> E, 1 <-> D, 2 (D arrived, counter increased)
* B, 1 <-> G, 1 <-> F, 1 <-> E, 1 (B arrived, new node assigned as head node, [L = 4] last (5th) node deleted)

***
![image1](https://github.com/gulsoy83/Cache-Buffer-Design/assets/46426033/555f6131-467d-4aa4-929a-58414e717b9e)

![image2](https://github.com/gulsoy83/Cache-Buffer-Design/assets/46426033/89353c09-444e-4cd2-9d49-68081333204d)



