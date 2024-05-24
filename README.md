# Directed Graph Operations

This project provides a set of functions to manipulate and analyze a directed graph using an adjacency list representation. It includes operations to add and delete nodes and arcs, list nodes, and specifically list nodes with only incoming arcs (no outgoing arcs). The program also features an interactive menu for user interaction.

## Features

- Initialize a directed graph.
- Add and delete nodes.
- Add and delete arcs (edges) between nodes.
- List all nodes and their outgoing arcs.
- List nodes that only have incoming arcs (no outgoing arcs).

## Getting Started

### Prerequisites

- A C++ compiler (e.g., GCC, Clang, MSVC)

### Building the Project

1. Clone the repository:

    ```sh
    git clone https://github.com/IlyaKotomin/CoursWork2Kotomin.git
    cd CoursWork2Kotomin
    ```

2. Compile the source code:

    ```sh
    g++ -o graph main.cpp
    ```

3. Run the executable:

    ```sh
    ./graph
    ```

## Usage

The program presents a menu with the following options:

1. Add node
2. Delete node
3. Add arc
4. Delete arc
5. List nodes
6. List nodes with only incoming arcs
7. Exit

### Example Interaction

```plaintext
Graph Menu:
1. Add node
2. Delete node
3. Add arc
4. Delete arc
5. List nodes
6. List nodes with only incoming arcs
7. Exit
Enter your choice: 1
Enter node to add: A

Graph Menu:
1. Add node
2. Delete node
3. Add arc
4. Delete arc
5. List nodes
6. List nodes with only incoming arcs
7. Exit
Enter your choice: 3
Enter arc (from to): A B

Graph Menu:
1. Add node
2. Delete node
3. Add arc
4. Delete arc
5. List nodes
6. List nodes with only incoming arcs
7. Exit
Enter your choice: 5
[A]=>[B]

Graph Menu:
1. Add node
2. Delete node
3. Add arc
4. Delete arc
5. List nodes
6. List nodes with only incoming arcs
7. Exit
Enter your choice: 6
Nodes with only incoming arcs (no outgoing arcs):
B
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file

 for details.

## Acknowledgements

- Inspired by basic graph theory concepts.
- Implemented using C++ for educational purposes.
