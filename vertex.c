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
	if (sizeof(v->tag) > 0)
	{
		strcpy(v->tag, "");
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
		return NULL;
	}
	
	return v->state;
}

/*----------------------------------------------------------------------------------------*/
Status vertex_setId (Vertex * v, const long id)
{



	
}



