#include "vertex.c"

int main()
{
    Vertex *a = NULL, *b = NULL;
    int error_code, comparator;
    
    a = vertex_initFromString("id:10 tag:one state:0");
    if (a == NULL)
    {
        printf("\nCould not create new vertex");
        return 1;
    }
    
    b = vertex_initFromString("id:20 tag:two state:1");
    if (b == NULL)
    {
        printf("\nCould not create new vertex");
        vertex_free(a);
        return 1;
    }

    error_code = vertex_print(stdout, a);
    if (error_code == -1)
    {
        printf("\nCould not print information");
        vertex_free(a);
        vertex_free(b);
        return 1;
    }

    error_code = vertex_print(stdout, b);
    if (error_code == -1)
    {
        printf("\nCould not print information");
        vertex_free(a);
        vertex_free(b);
        return 1;
    }

    printf("\n");

    comparator = vertex_cmp(a, b);
    if (comparator == 0)
    {
        printf("\nCould not compare vertex (0)");
        vertex_free(a);
        vertex_free(b);
        return 1;
    }

    printf("%d", comparator);

    printf("%s\n", vertex_getTag(b));

    Vertex *c = NULL;
    c = vertex_copy(a);
    if (c == NULL)
    {
        printf("Could not allocate third vertex");
        vertex_free(a);
        vertex_free(b);
        return 1;
    }

    printf("%ld", vertex_getId(c));

    error_code = vertex_print(stdout, a);
    if (error_code == -1)
    {
        printf("\nCould not print information");
        vertex_free(a);
        vertex_free(b);
        vertex_free(c);
        return 1;
    }

    error_code = vertex_print(stdout, c);
    if (error_code == -1)
    {
        printf("\nCould not print information");
        vertex_free(a);
        vertex_free(b);
        vertex_free(c);
        return 1;
    }

    printf("\n");

    comparator = vertex_cmp(a, c);
    if (comparator == -2)
    {
        printf("\nCould not compare vertex (1)");
        vertex_free(a);
        vertex_free(b);
        vertex_free(c);
        return 1;
    }

    printf("%d", comparator);

    vertex_free(a);
    vertex_free(b);
    vertex_free(c);

    return 0;
}