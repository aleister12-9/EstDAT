#include "graph.c"

int main()
{
    Graph *g =graph_init();
    int temp;

    temp = graph_newVertex(g, "id:111 tag:Madrid");
    printf("Inserting Madrid... result: %d\n", temp);
    temp = graph_newVertex(g, "id:222 tag:Toledo");
    printf("Inserting Toledo... result: %d\n", temp);

    if (graph_newEdge(g, 222, 111) == OK)
    {
        printf("Inserting Edge %d --> %d\n", 222, 111);
    }
    else
    {
        printf("Edge not inserted\n");
    }

    if (graph_connectionExists(g, 111, 222) == TRUE)
    {
        printf("111 --> 222? Yes\n");
    }
    else
    {
        printf("111 --> 222? No\n");
    }

    if (graph_connectionExists(g, 222, 111) == TRUE)
    {
        printf("222 --> 111? Yes\n");
    }
    else
    {
        printf("222 --> 111? No\n");
    }

    printf("Number of connections from 111: %d\n", graph_getNumberOfConnectionsFromId(g, 111));
    printf("Number of connections from Toledo: %d\n", graph_getNumberOfConnectionsFromTag(g, "Toledo"));

    long *connections = graph_getConnectionsFromTag(g, "Toledo");

    if (connections == NULL)
    {
        printf("Error getting connections from Toledo\n");
    }
    else
    {
        printf("Connections from Toledo: ");
        for (int i = 0; i < graph_getNumberOfConnectionsFromTag(g, "Toledo"); i++)
        {
            printf("%ld ", connections[i]);
        }
        printf("\n");
    }

    graph_print(stdout, g);

    free(connections);
    graph_free(g);

    return 0;
}