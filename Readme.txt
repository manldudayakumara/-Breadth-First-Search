======================================================
BFS GRAPH TRAVERSAL SYSTEM
======================================================

STUDENT INFORMATION:
--------------------
Name: M.A.N.L.D.Udayakumara
Index Number: 24002097
Email Address: 2024cs209@stu.ucsc.cmb.ac.lk 

TESTING ENVIRONMENT:
--------------------
- Tested on Linux: Yes
- Compiler: GCC (GNU Compiler Collection)

HOW TO EXECUTE:
---------------
1. Ensure you have a file named "graph.txt" in the same directory as the source code.
2. Open the terminal and compile the code using the provided Makefile:
   $ make
3. Run the executable:
   $ ./bfs
4. To remove the executable after running:
   $ make clean

SPECIAL NOTES:
--------------
- File Dependencies: The program strictly requires "graph.txt" to follow the format: 
  [Number of nodes] 
  [Node list] 
  [Type: directed/undirected] 
  [Edge pairs with weights].
- Logic: The code implements a Breadth-First Search (BFS) using a static queue. 
- Features: It calculates the total weight of the traversal path and identifies 
  nodes that are unreachable from the starting node.
- Memory: The program uses static arrays with a MAX_N of 100 nodes.
