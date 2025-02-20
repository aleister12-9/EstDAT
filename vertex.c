#include "vertex.h"
#include <string.h>

/*----------------------------------------------------------------------------------------*/
Status vertex_setField(Vertex *v, char *key, char *value);

Status vertex_setField(Vertex *v, char *key, char *value)
{
	if (!key || !value || !v)
		return ERROR;

	if (strcmp(key, "id") == 0)
	{
		return vertex_setId(v, atol(value));
	}
	else if (strcmp(key, "tag") == 0)
	{
		return vertex_setTag(v, value);
	}
	else if (strcmp(key, "state") == 0)
	{
		return vertex_setState(v, (Label)atoi(value));
	}

	return ERROR;
}

/*----------------------------------------------------------------------------------------*/
Vertex *vertex_initFromString(char *descr){
	char buffer[1024];
	char *token;
	char *key;
	char *value;
	char *p;
	Vertex *v;
  
	/* Check args: */
	if (!descr) return NULL;
  
	/* Allocate memory for vertex: */
	v = vertex_init();
	if (!v) return NULL;
  
	/* Read and tokenize description: */
	sprintf(buffer, "%s", descr);
	token = strtok(buffer, " \t\n");
	while (token) {
	  p = strchr(token, ':');
	  if (!p) continue;
  
	  *p = '\0';
	  key = token;
	  value = p+1;
  
	  vertex_setField(v, key, value);
  
	  token = strtok(NULL, " \t\n");
	}
  
	return v;
  }

/*----------------------------------------------------------------------------------------*/
Vertex *vertex_init()
{
	Vertex *v = NULL;

	if (!(v = (Vertex *)malloc(sizeof(Vertex))))
	{
		return NULL;
	}

	v->state = WHITE;
	v->id = 0;
	if (TAG_LENGTH > 0)
	{
		v->tag[0] = '\0';
	}
	else
	{
		/*means length of tag in vertex is too low to initalize*/
		free(v);
		return NULL;
	}

	return v;
}

/*----------------------------------------------------------------------------------------*/
void vertex_free(void *v)
{
	if (v != NULL)
	{
		free(v);
	}
}

/*----------------------------------------------------------------------------------------*/
long vertex_getId(const Vertex *v)
{
	if (v == NULL)
	{
		return -1;
	}
	
	return v->id;
}

/*----------------------------------------------------------------------------------------*/
const char* vertex_getTag(const Vertex *v) 
{
    if (v == NULL)
	{
		return NULL;
	}
	
    return v->tag;  
}

/*----------------------------------------------------------------------------------------*/
Label vertex_getState (const Vertex * v)
{
	if (v == NULL)
	{
		return ERROR_VERTEX;
	}
	
	return v->state;
}

/*----------------------------------------------------------------------------------------*/
Status vertex_setId (Vertex * v, const long id)
{
	if (v == NULL || id < 0)
	{
		return ERROR;
	}

	v->id = id;

	return OK;
}

/*----------------------------------------------------------------------------------------*/
Status vertex_setTag (Vertex * v, const char * tag)
{
	if (v == NULL || strlen(tag) > TAG_LENGTH)
	{
		return ERROR;
	}
	
	strcpy(v->tag, tag);

	return OK;
}

/*----------------------------------------------------------------------------------------*/
Status vertex_setState (Vertex * v, const Label state)
{
	if (v == NULL || (state != WHITE && state != BLACK && state != ERROR_VERTEX))
	{
		return ERROR;
	}
	
	v->state = state;

	return OK;
}

/*----------------------------------------------------------------------------------------*/
int vertex_cmp (const void * v1, const void * v2)
{
	if (v1 == NULL || v2 == NULL)
	{
		return 0;
	}

	const Vertex *vert1 = (const Vertex *)v1;
	const Vertex *vert2 = (const Vertex *)v2;

	if (strlen(vert1->tag) < 1 || strlen(vert2->tag) < 1 || vert1->id < 0 || vert2->id < 0)
	{
		return 0;
	}
	
	if (vert1->id == vert2->id)
	{
		return strcmp(vert1->tag, vert2->tag);
	}
	
	return vert1->id - vert2->id;
}

/*----------------------------------------------------------------------------------------*/
void * vertex_copy (const void * src)
{
	if (src == NULL)
	{
		return NULL;
	}

	const Vertex *source = (const Vertex *)src;

	if (source->id < 0 || strlen(source->tag < 1 || (source->state != WHITE && source->state != BLACK && source->state != ERROR_VERTEX)))
	{
		return NULL;
	}
	
	Vertex *v = NULL;

	if (!(v = (Vertex*)malloc(sizeof(Vertex))))
	{
		return NULL;
	}

	v->id = source->id;
	strcpy(v->tag, source->tag);
	v->state = source->state;

	return v;
}

/*----------------------------------------------------------------------------------------*/
int vertex_print (FILE * pf, const void * v)
{
	if (pf == NULL || v == NULL)
	{
		return -1;
	}

	const Vertex *source = (const Vertex *)v;

	return fprintf(pf, "[%ld, %s, %d]", source->id, source->tag, source->state);
}





