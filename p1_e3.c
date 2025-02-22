#include "graph.c"

#define ERROR -1

int main(int argc, char *argv[])
{
    FILE *file = NULL;
    Graph *g = NULL;
    
    if (argc != 2)
    {
        printf("Enter the name of the file to read the graph from.\n");
        return -1;
    }

    if (!(file = fopen(argv[1], "r")))
    {
        printf("Error opening file: %s\n", argv[1]);
        return -1;
    }
    
    if ((g = graph_init()) == NULL)
    {
        printf("Could not initialize graph\n");
        fclose(file);
        return -1;
    }

    if (graph_readFromFile(file, g) == ERROR)
    {
        printf("Could not read graph from file.\n");
        fclose(file);
        graph_free(g);
        return -1;
    }

    if (graph_print(stdout, g) == -1)
    {
        printf("Could not print graph.\n");
        fclose(file);
        graph_free(g);
        return -1;
    }
    
    fclose(file);
    graph_free(g);
    return 0;
}