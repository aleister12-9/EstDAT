/**
 * @file vertex.h
 * @brief Definition of the Vertex Abstract Data Type (ADT).
 *
 * This header file contains the definition of the Vertex structure and 
 * the functions necessary for its manipulation. The Vertex ADT represents 
 * a node in a graph, storing an identifier, a tag, and a state.
 *
 * @authors 
 *      - Izan Robles
 *      - Arturo Pérez
 *      - Teacher @ UAM
 * 
 * @date February 2020
 */

 #ifndef VERTEX_H_
 #define VERTEX_H_
 
 #include "types.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 
 #define TAG_LENGTH 64  /**< Maximum length of the vertex tag. */
 #define MAX_DATA 128    /**< Maximum amount of additional data (not used in this version). */
 
 /**
  * @brief Enumeration for vertex states.
  *
  * The Label type is used to indicate the state of a vertex in a graph.
  */
 typedef enum {
     WHITE,         /**< Vertex has not been visited. */
     BLACK,         /**< Vertex has been visited. */
     ERROR_VERTEX   /**< Invalid vertex state. */
 } Label;
 
 /** 
  * @brief Opaque definition of the Vertex structure. 
  */
 typedef struct _Vertex Vertex;
 
 /**
  * @brief Definition of the Vertex structure.
  *
  * This structure stores the properties of a vertex, including:
  * - A unique identifier (`id`).
  * - A descriptive tag (`tag`).
  * - The current state (`state`).
  */
 struct _Vertex 
 {
     long id;              /**< Unique identifier of the vertex. */
     char tag[TAG_LENGTH]; /**< Tag associated with the vertex. */
     Label state;          /**< State of the vertex. */
 }; 
 
 /**
  * @brief Allocates and initializes a new vertex.
  * 
  * @authors Izan Robles & Arturo Pérez
  *
  * @return Pointer to the newly created vertex, or NULL in case of failure.
  */
 Vertex *vertex_init ();
 
 /**
  * @brief Creates and initializes a vertex based on a description string.
  *
  * The description string should follow the format "key:value" pairs, separated by spaces.
  *
  * @authors Teacher @ UAM
  * 
  * @param descr String containing the initialization parameters.
  * @return Pointer to the newly created vertex, or NULL in case of failure.
  */
 Vertex *vertex_initFromString(char *descr);
 
 /**
  * @brief Releases the memory allocated for a vertex.
  *
  * @authors Izan Robles & Arturo Pérez
  * 
  * @param v Pointer to the vertex to be freed.
  */
 void vertex_free (void *v);
 
 /**
  * @brief Retrieves the ID of a given vertex.
  *
  * @authors Izan Robles & Arturo Pérez
  * 
  * @param v Pointer to the vertex.
  * @return The ID of the vertex, or -1 in case of error.
  */
 long vertex_getId (const Vertex *v);
 
 /**
  * @brief Retrieves the tag associated with a vertex.
  *
  * @authors Izan Robles & Arturo Pérez
  * 
  * @param v Pointer to the vertex.
  * @return Pointer to the tag string, or NULL in case of error.
  */
 const char* vertex_getTag (const Vertex *v);
 
 /**
  * @brief Retrieves the state of a given vertex.
  *
  * @authors Izan Robles & Arturo Pérez
  * 
  * @param v Pointer to the vertex.
  * @return The state of the vertex, or ERROR_VERTEX in case of error.
  */
 Label vertex_getState (const Vertex *v);
 
 /**
  * @brief Sets the ID of a vertex.
  * 
  * @authors Izan Robles & Arturo Pérez
  *
  * @param v Pointer to the vertex.
  * @param id New vertex ID (must be non-negative).
  * @return OK if successful, ERROR otherwise.
  */
 Status vertex_setId (Vertex *v, const long id);
 
 /**
  * @brief Sets the tag of a vertex.
  * 
  * @authors Izan Robles & Arturo Pérez
  *
  * @param v Pointer to the vertex.
  * @param tag New tag (must not exceed TAG_LENGTH).
  * @return OK if successful, ERROR otherwise.
  */
 Status vertex_setTag (Vertex *v, const char *tag);
 
 /**
  * @brief Sets the state of a vertex.
  *
  * @authors Izan Robles & Arturo Pérez
  * 
  * @param v Pointer to the vertex.
  * @param state New state to assign to the vertex.
  * @return OK if successful, ERROR otherwise.
  */
 Status vertex_setState (Vertex *v, const Label state);
 
 /**
  * @brief Compares two vertices.
  *
  * The comparison follows these rules:
  * - If their IDs differ, the function returns their numerical difference.
  * - If their IDs are equal, it compares their tags lexicographically.
  * - In case of error, it returns 0.
  * 
  * @authors Izan Robles & Arturo Pérez
  * 
  * @param v1 Pointer to the first vertex.
  * @param v2 Pointer to the second vertex.
  * @return A negative integer if v1 < v2, zero if they are equal, and a positive integer if v1 > v2.
  */
 int vertex_cmp (const void *v1, const void *v2);
 
 /**
  * @brief Creates a copy of a given vertex.
  *
  * The function allocates memory for a new vertex and duplicates the content of `src`.
  * 
  * @authors Izan Robles & Arturo Pérez
  * 
  * @param src Pointer to the source vertex.
  * @return Pointer to the copied vertex if successful, or NULL otherwise.
  *
  * @code
  * // Example of use:
  * Vertex *src, *copy;
  * src = vertex_init();
  * copy = vertex_copy(src);
  * vertex_free(src);
  * vertex_free(copy);
  * @endcode
  */
 void *vertex_copy (const void *src);
 
 /** 
  * @brief Prints a vertex to the specified output stream.
  * 
  * The output format is: `[id, tag, state]`, without a newline at the end.
  * The `state` value is printed as an integer.
  * 
  * @authors Izan Robles & Arturo Pérez
  *
  * @param pf File pointer to the output stream.
  * @param v Pointer to the vertex to print.
  * @return The number of characters printed, or -1 in case of error.
  *
  * @code
  * Vertex *v;
  * v = vertex_init();
  * vertex_print(stdout, v);
  * @endcode
  */
 int vertex_print (FILE *pf, const void *v);
 
 #endif /* VERTEX_H_ */
