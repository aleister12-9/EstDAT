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
	Vertex *main = NULL;
	size_t position = 0, position_saver, temp_string_length;
	short *temp_id = NULL;

	if (!(main = (Vertex *)malloc(sizeof(Vertex))))
	{
		return NULL;
	}

	/*find position where ID starts*/
	for (; position < strlen(descr); position++)
	{
		if (descr[position] == 'i' && descr[position + 1] == 'd')
		{
			break;
		}
	}

	if (position < strlen(descr) - 1)
	{
		position += 3;
		position_saver = position;

		/*measure ID as array and allocate*/
		for (; descr[position] != ' ' && descr[position] != '\0'; position++, temp_string_length++)
			;

		if (!(temp_id = (short *)malloc(temp_string_length * sizeof(short))))
		{
			return NULL;
		}

		/*return to id starting position and copy id as array of shorts*/
		position = position_saver;
		for (size_t counter = 0; descr[position] != ' ' && descr[position] != '\0'; position++, counter++)
		{
			temp_id[counter] = descr[position];
		}

		/*transform to long*/
		/*assign value to main vertex*/

		free(temp_id);
	}

	else
	{
		/*if ID is not specified, initialize to 0*/
		main->id = 0;
	}

	return main;
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


