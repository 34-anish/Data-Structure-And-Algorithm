#include <iostream>
int size = 16;
class Graph
{

public:
    Graph();
    bool isEmpty();
    void addVertex(int vertex);
    void addEdge(int, int);
    bool vertex_index_exists(int &index, int target_vertex);
    int vertices[16];
    int last_vertex_index = 0;
    int adjacency_matrix[16][16];
    void removeVertex(int vertex);
    void removeEdge(int vertex1, int vertex2);
    int numberOfEdges();
};
Graph::Graph()
{
    this->last_vertex_index = 0;
    for (int i = 0; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            this->adjacency_matrix[i][j] = 0;
        }
    }
}
bool Graph::isEmpty()
{
    if (last_vertex_index == 0)
    {
        return true;
    }
    else
        return false;
}
void Graph::addVertex(int vertex)
{
    vertices[last_vertex_index] = vertex;
    last_vertex_index++;
}
void Graph ::addEdge(int vertex1, int vertex2)
{
    int index_of_vertex1, index_of_vertex2;
    if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
    {
        this->adjacency_matrix[index_of_vertex1][index_of_vertex2] = 1;
    }
}

void Graph::removeEdge(int vertex1, int vertex2)
{
    int index_of_vertex1, index_of_vertex2;
    if (vertex_index_exists(index_of_vertex1, vertex1) && vertex_index_exists(index_of_vertex2, vertex2))
    {
        this->adjacency_matrix[index_of_vertex1][index_of_vertex2] = 0;
    }
}
bool Graph::vertex_index_exists(int &index, int target_vertex)
{
    for (int i = 0; i <= last_vertex_index; i++)
    {
        if (this->vertices[i] == target_vertex)
        {
            index = i;
            return true;
        }
    }
    return false;
}

void Graph::removeVertex(int vertex)
{
    int index;
    if (vertex_index_exists(index, vertex))
    {
        for (int i = 0; i <= size; i++)
        {
            this->adjacency_matrix[index][i] = 0;
        }
        this->vertices[index] = 0;

        for (int i = index; i <= size - 1; i++)
        {
            this->vertices[i] = this->vertices[i + 1];
        }
        last_vertex_index--;
    }
}
int Graph::numberOfEdges()
{
    if (!isEmpty())
    {
        int edges = 0;
        for (int i = 0; i <= last_vertex_index; i++)
        {
            for (int j = 0; j <= last_vertex_index; j++)
            {
                if (this->adjacency_matrix[i][j] == 1)
                {
                    edges++;
                }
            }
        }
        return edges;
    }
}

int main()
{
    Graph a;
    std::cout << "Is Empty ?? " << a.isEmpty() << std::endl;
    a.addVertex(1);
    a.addVertex(2);
    a.addEdge(1, 2);
    a.addEdge(2, 1);
    a.addVertex(3);
    a.addEdge(3, 3);

    std::cout << "Number of vertices: " << a.last_vertex_index << std::endl;
    std::cout <<"Number of edges:" << a.numberOfEdges() << std::endl;
    a.removeEdge(3, 3);
    a.removeVertex(2);
    std::cout <<"Number of edges:" << a.numberOfEdges() << std::endl;
    std::cout << "Number of vertices: " << a.last_vertex_index << std::endl;
    std::cout << "Is Empty ?? " << a.isEmpty() << std::endl;
    
}