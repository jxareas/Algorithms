#include<iostream>

using namespace std;

struct node {
    char name;            // Name of the node
    struct node *next_node;
    struct edge *ady;    //Pointer to the first edge of the node
};

struct edge {
    struct node *destination_node;    // Pointer to the destination node
    struct edge *next_edge;
};

typedef struct node *Tnode;        // Node Type
typedef struct edge *Tedge; //Edge Type

Tnode p;    // Head Pointer

void insert_node();

void delete_node();

void clear_edges(Tnode &aux);

void show_graph();

int main() {
    p = nullptr;
    cout << "\nEnter three nodes (a,b y c)\n";
    for (int i = 0; i < 3; i++)
        insert_node();

    show_graph();
    delete_node();
    show_graph();

    cout << endl;
    system("pause");
    return 0;
}

void insert_node() {
    Tnode t, nuevo = new struct node;
    cout << "\nEnter a node: ";
    cin >> nuevo->name;
    nuevo->next_node = nullptr;
    nuevo->ady = nullptr;

    if (p == nullptr) {
        p = nuevo;
        cout << "First Node\n";
    } else {
        t = p;
        while (t->next_node != nullptr) {
            t = t->next_node;
        }
        t->next_node = nuevo;
        cout << "Entered Node\n";
    }
}

/*  FUNCTION TO DELETE ALL THE EDGES OF A NODE
 * This functions is used to delete a node, if it has any edges,
 * it's necessary to delete them and free the memory
---------------------------------------------------------------------*/
void clear_edges(Tnode &aux) {
    Tedge q, r;
    q = aux->ady;
    while (q->next_edge != nullptr) {
        r = q;
        q = q->next_edge;
        delete (r);
    }
}


/*                      DELETE NODE
 * Function used to delete a node from the graph.
 * In order to do that, we have to delete its edges too.
 * Naturally, we call the function clear_edges()
---------------------------------------------------------------------*/
void delete_node() {
    char var;
    Tnode aux, last;
    aux = p;
    cout << "\nDelete a Node\n";
    if (p == nullptr) {
        cout << "Empty Graph";
        return;
    }
    cout << "Enter a node (a, b o c): ";
    cin >> var;

    while (aux != nullptr) {
        if (aux->name == var) {
            if (aux->ady != nullptr)
                clear_edges(aux);
            if (aux == p) {
                p = p->next_node;
                delete (aux);
                cout << "Deleted Node";
                return;
            } else {
                last->next_node = aux->next_node;
                delete (aux);
                cout << "Deleted Node";
                return;
            }
        } else {
            last = aux;
            aux = aux->next_node;
        }
    }

}

/*                      SHOW GRAPH
 * Function to print a graph in it's linked form
---------------------------------------------------------------------*/
void show_graph() {
    Tnode ptr;
    Tedge ar;
    ptr = p;
    cout << "\nList of Adjacency\n";

    while (ptr != nullptr) {
        cout << "   " << ptr->name << "|";
        if (ptr->ady != nullptr) {
            ar = ptr->ady;
            while (ar != nullptr) {
                cout << " " << ar->destination_node->name;
                ar = ar->next_edge;
            }
        }
        ptr = ptr->next_node;
        cout << endl;
    }
}
