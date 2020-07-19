#include <stdio.h>
#include <stdlib.h>

typedef struct	node{
	char*	track;
	struct	node *next;
}				t_node;

int play_song(char *s, t_node songs);
{

}

int main()
{
	t_node *head = NULL;
	t_node *second = NULL;
	t_node *third = NULL;
	
	if (!(head = malloc(sizeof(t_node))))
		return (0);
	if (!(second = malloc(sizeof(t_node))))
		return (0);
	if (!(third = malloc(sizeof(t_node))))
		return (0);

	head->track	= "Future - Im so Groovy";
	head->next = second;

	second->track = "Future - Feds Did A Sweep";
	second->next = third;
	
	third->track = "Kanye West - Wash Us In The Blood";
	third->next = head;
	return (0);
}
