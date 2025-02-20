#ifndef VERTEX_H_
#define VERTEX_H_

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAG_LENGTH 64
#define MAX_DATA 128


typedef enum {
    WHITE, /* vertex not visited */
    BLACK,  /* vertex visited */
    ERROR_VERTEX   /* not valid vertex */   
} Label;

typedef struct _Vertex Vertex;

struct _Vertex 
{
    long id;
    char tag[TAG_LENGTH];
    Label state;
}; 

/**
 * @brief Creates vertex and initializes its values.
 *
 * @author Izan Robles & Arturo Pérez
 *
 * @return Returns pointer to new vertex
 */
Vertex * vertex_init ();

/**
 * @brief Creates vertex and initializes its values according to
 *        given description.
 *
 * @author Teacher @ UAM
 * 
 * @param descr Description of values to initialize new vertex
 *
 * @return Returns pointer to new vertex
 */
Vertex *vertex_initFromString(char *descr);

/**
 * @brief Frees all memory associated to given vertex
 *
 * @author Izan Robles & Arturo Pérez
 * 
 * @param v vertex pointer
 */
void vertex_free (void * v);

/**
 * @brief Extracts id from given vertex
 *
 * @author Izan Robles & Arturo Pérez
 * 
 * @param v vertex pointer
 *
 * @return Returns long with the ID of the given vertex
 */
long vertex_getId (const Vertex * v);

/**
 * @brief Extracts tag from given vertex
 *
 * @author Izan Robles & Arturo Pérez
 * 
 * @param v vertex pointer
 *
 * @return Returns pointer to string with pointers tag
 */
const char* vertex_getTag (const Vertex * v);

/**
 * @brief Extracts state from given vertex
 *
 * @author Izan Robles & Arturo Pérez
 * 
 * @param v vertex pointer
 *
 * @return Returns label with the state of the given vertex
 */
Label vertex_getState (const Vertex * v);



/**
 * @brief Modifies the id of a given vertex.
 * 
 * @author Izan Robles & Arturo Pérez
 *
 * @param v Vertex pointer
 * @param id New vertex id, must be equal or greater than 0
 *
 * @return Returns OK or ERROR in case of error 
 */
Status vertex_setId (Vertex * v, const long id);


/**
 * @brief Modifies the tag of a given vertex
 * 
 * @author Izan Robles & Arturo Pérez
 *
 * @param v Vertex pointer
 * @param id New vertex tag, must fit in the Vertex
 *
 * @return  Returns OK or ERROR in case of error.
 */
Status vertex_setTag (Vertex * v, const char * tag);


/**
 * @brief Modifies the state of a given vertex
 *
 * @author Izan Robles & Arturo Pérez
 * 
 * @param v Vertex pointer
 * @param state New vertex state
 *
 * @return Returns OK or ERROR in case of error.
 */
Status vertex_setState (Vertex * v, const Label state);


/**
 * @brief Compares two vertices.
 *
 * First it compares their ids. If they are equal, then compares
 * their tags.
 * 
 * @author Izan Robles & Arturo Pérez
 * 
 * @param v1 
 * @param v2 Vertices to compare.
 *
 * @return It returns an integer less than or greater than zero if
 * id of v1 is found,  respectively, to be less than or be greater 
 * than id of v2. If their are equal, then returns the result of 
 * comparing their tags. In case of error, returns 0. 
 */
int vertex_cmp (const void * v1, const void * v2);


/**
 * @brief Reserves memory for a vertex where it copies the data from
 * the vertex src.
 * 
 * @code
 * // Example of use
 * Vertex *trg, *src;
 * src = vertex_init();
 * trg = vertex_copy(src);
 * // .... aditional code ...
 * // free vertexs
 * vertex_free(src);
 * vertex_free(trg);
 * @endcode
 * 
 * @author Izan Robles & Arturo Pérez
 * 
 * @param src Original vertex pointer
 *
 * @return Returns the pointer of the copied vertex if everything 
 * went well, or NULL otherwise.
 */
void * vertex_copy (const void * src);



/** 
 * @brief Prints in pf the data of a vertex.
 * 
 * The format will be: [id, tag, state], without line break at the 
 * end. The type Label is an enumeration so it can be printed as an
 * int. 
 *
 * @code
 * Vertex * v;
 * v = vertex_init();
 * vertex_print (stdout, v);
 * @endcode
 * 
 * @author Izan Robles & Arturo Pérez
 *
 * @param pf File descriptor
 * @param v Vertex to be printed
 *
 * @return Returns the number of characters that have been written 
 * successfully. If there have been errors returns -1.
 */
int vertex_print (FILE * pf, const void * v);

#endif /* VERTEX_H_ */
