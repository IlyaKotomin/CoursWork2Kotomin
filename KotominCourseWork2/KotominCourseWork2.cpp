#include <iostream>
using namespace std;

constexpr int COUNT = 5;

struct link
{
    char key;
    link* next;
} * gr[COUNT];

#pragma region GRAPH METHODS

void init(link* graph[COUNT])
{
    for (int i = 0; i < COUNT; i++)
        graph[i] = nullptr;
}

bool search_node(link* graph[COUNT], const char to_find)
{
    for (int i = 0; i < COUNT; i++)
        if (graph[i] != nullptr && graph[i]->key == to_find)
            return true;

    return false;
}

void add_node(link* graph[COUNT], const char to_add)
{
    if (search_node(graph, to_add))
    {
        cout << "\nSKIPPED! Node already exists!\n";
        return;
    }

    int iterator = 0;
    // ReSharper disable once CppPossiblyErroneousEmptyStatements
    for (; graph[iterator] != nullptr && iterator < COUNT; iterator++);

    if (graph[iterator] != nullptr)
    {
        cout << "\nOverflow!\n";
        return;
    }

    graph[iterator] = new link;
    graph[iterator]->key = to_add;
    graph[iterator]->next = nullptr;
}

void del_node(link* graph[], char c)
{
    if (search_node(graph, c))
    {
        int i = 0;
        // ReSharper disable once CppJoinDeclarationAndAssignment
        link *p, *q;
        while (graph[i] && graph[i]->key != c) i++;
        if (graph[i])
        {
            p = graph[i];
            graph[i] = p->next;
            delete p;
        }
        for (i = 0; i < COUNT; i++)
            if (graph[i])
            {
                p = graph[i];
                while (p->next)
                    if (p->next->key == c)
                    {
                        q = p->next;
                        p->next = q->next;
                        delete q;
                    }
                    else
                        p = p->next;
            }
    }
}

int search_arc(link* graph[], const char from, const char to)
{
    int flag = 0;
    if (search_node(graph, from) && search_node(graph, to))
    {
        int i = 0;
        while (graph[i] && graph[i]->key != from) i++;
        if (graph[i])
        {
            const link* p = graph[i];
            while (p && p->key != to && p->next != nullptr)
                p = p->next;
            if (p && p->key == to)
                flag = 1;
        }
    }
    return flag;
}

void add_arc(link* graph[], char cl, char c2)
{
    int i = 0;
    if (search_arc(graph, cl, c2))
    {
        cout << "\nExisting arc!";
        return;
    }

    if (!search_node(graph, cl))
        add_node(graph, cl);
    if (!search_node(graph, c2))
        add_node(graph, c2);
    while (graph[i] != nullptr && graph[i]->key != cl)
        i++;
    if (graph[i] == nullptr)
    {
        cout << "The node is not in the graph!";
        return;
    }

    const auto p = new link;
    p->key = c2;
    p->next = graph[i]->next;
    graph[i]->next = p;
}

void del_arc(link* graph[], const char from, const char to)
{
    if (!search_arc(graph, from, to))
    {
        cout << "The arc is not in the graph!";
        return;
    }

    int i = 0;
    while (graph[i] != nullptr && graph[i]->key != from) i++;
    if (graph[i] != nullptr)
    {
        link* p = graph[i]->next;
        link* q = graph[i];
        while (p != nullptr && p->key != to)
        {
            q = p;
            p = p->next;
        }

        if (p != nullptr && p->key == to)
        {
            q->next = p->next;
            delete p;
        }
    }
}

void list_node(link* graph[])
{
    for (int i = 0; i < COUNT; i++)
        if (graph[i] != nullptr)
        {
            cout << '[' << graph[i]->key << ']';
            const link* p = graph[i]->next;
            while (p != nullptr)
            {
                cout << "=>" << '[' << p->key << ']';
                p = p->next;
            }
            cout << endl;
        }
}

void list_nodes_with_only_incoming_arcs(link* graph[])
{
    bool has_outgoing[COUNT] = {false};

    for (int i = 0; i < COUNT; i++)
        if (graph[i] != nullptr)
            if (const link* p = graph[i]->next; p != nullptr)
                has_outgoing[i] = true;

    cout << "\nNodes with only incoming arcs (no outgoing arcs):\n";
    for (int i = 0; i < COUNT; i++)
        if (graph[i] != nullptr && !has_outgoing[i])
            cout << graph[i]->key << " ";
    
    cout << endl;
}

#pragma endregion

void menu()
{
    link* graph[COUNT];
    init(graph);

    int choice;
    char node1, node2;

    do
    {
        cout << "\nGraph Menu:\n";
        cout << "1. Add node\n";
        cout << "2. Delete node\n";
        cout << "3. Add arc\n";
        cout << "4. Delete arc\n";
        cout << "5. List nodes\n";
        cout << "6. List nodes with only incoming arcs\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter node to add: ";
            cin >> node1;
            add_node(graph, node1);
            break;
        case 2:
            cout << "Enter node to delete: ";
            cin >> node1;
            del_node(graph, node1);
            break;
        case 3:
            cout << "Enter arc (from to): ";
            cin >> node1 >> node2;
            add_arc(graph, node1, node2);
            break;
        case 4:
            cout << "Enter arc to delete (from to): ";
            cin >> node1 >> node2;
            del_arc(graph, node1, node2);
            break;
        case 5:
            list_node(graph);
            break;
        case 6:
            list_nodes_with_only_incoming_arcs(graph);
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    }
    while (choice != 7);
}

int main()
{
    menu();
    return 0;
}
