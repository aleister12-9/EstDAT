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
Vertex *vertex_initFromString(char *descr)
{
	char buffer[1024];
	char *token;
	char *key;
	char *value;
	char *p;
	Vertex *v;
	Status temp;

	/* Check args: */
	if (!descr)
		return NULL;

	/* Allocate memory for vertex: */
	v = vertex_init();
	if (!v)
		return NULL;

	/* Read and tokenize description: */
	sprintf(buffer, "%s", descr);
	token = strtok(buffer, " \t\n");
	while (token)
	{
		p = strchr(token, ':');
		if (!p)
			continue;

		*p = '\0';
		key = token;
		value = p + 1;

		temp = vertex_setField(v, key, value);

		if (temp == ERROR)
		{
			return NULL;
		}
		

		token = strtok(NULL, " \t\n");
	}

	return v;
}

/*----------------------------------------------------------------------------------------*/
Vertex *vertex_init()
{

	Vertex *main = NULL;

	if (!(main = (Vertex *)malloc(sizeof(Vertex))))
	{
		return NULL;
	}

	main->state = WHITE;
	main->id = 0;
	strcpy(main->tag, "\"\""); /*Revisar*/

	return main;
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
    if (!v)
	{
		return NULL;
	}
	
    return v->tag;  
}

/*----------------------------------------------------------------------------------------*/
Label vertex_getState (const Vertex * v)
{
	return v->state;
}


