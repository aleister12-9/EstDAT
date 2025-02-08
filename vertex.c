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
	char *id_position, *tag_position, *state_position;
	char temp_data[MAX_DATA], descr_position, td_position;
	long temp_id = 0;
	size_t id_size;


	if (!(main = (Vertex *)malloc(sizeof(Vertex))))
	{
		return NULL;
	}

	/*save each position on the description and if not found assign defalut value*/

	id_position = strstr(descr, "id:");
	tag_position = strstr(descr, "tag:");
	state_position = strstr(descr, "state:");

	/*checks each pointer and, if not null, continues reading and assigns value*/

	if (id_position)
	{
		id_position = id_position - descr + 3;

		for (descr_position = id_position, td_position = 0; descr[descr_position] != ' ' && descr[descr_position] != '\0'; descr_position++, td_position++)
		{
			temp_data[td_position] = descr[descr_position];
		}

		temp_data[td_position + 1] = '\0';
		id_size = strlen(temp_data);
		
		for (size_t counter; counter <= id_size; counter++)
		{
			temp_id += temp_data[counter] * pow(10, id_size - counter);
		}
		
		main->id = temp_id;
	}

	else
	{
		main->id = 0;
	}

	/*deletes data from temp_data to prevent errors*/
	memset(temp_data, 0, sizeof(temp_data));

	if (tag_position)
	{
		tag_position = tag_position - descr + 4;

		for (descr_position = tag_position, td_position = 0; descr[descr_position] != ' ' && descr[descr_position] != '\0'; descr_position++, td_position++)
		{
			temp_data[td_position] = descr[descr_position];
		}
		
		temp_data[td_position + 1] = '\0';

		if (strlen(temp_data) < sizeof(main->tag))
		{
			strcpy(main->tag, temp_data);
		}

		else
		{
			/*means value of tag in description larger than supported*/
			return NULL;
		}
	}
	
	else
	{
		if (sizeof(main->tag) > 2)
		{
			strcpy(main->tag, "\"\"");
		}
		else
		{
			/*means length of tag in vertex is too low to initalize*/
			return NULL;
		}
	}
	
	memset(temp_data, 0, sizeof(temp_data));

	





	



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
	if (sizeof(main->tag) > 2)
	{
		strcpy(main->tag, "\"\"");
	}
	else
	{
		/*means length of tag in vertex is too low to initalize*/
		return NULL;
	}

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


