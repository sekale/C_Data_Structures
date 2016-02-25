#include <stdio.h>
#include <stdlib.h>

typedef struct adjlistnode
{
	int dest;
	struct adjlistnode *next;
}node;

typedef struct adjlist
{
	node *head;
}list_node;

typedef struct graph
{
	int vertex;
	list_node *array_list;
}graph;

node *create_node(int dest)
{
	node *new_node;
	new_node = malloc(sizeof(node));
	new_node -> dest = dest;
	new_node -> next = NULL;
	return new_node;	
}

graph *create_graph(int vertices)
{
	graph *new_graph;
	new_graph = malloc(sizeof(graph));
	new_graph -> array_list = malloc(vertices * sizeof(list_node));
	new_graph -> vertex = vertices;

	int i = 0;

	for(i = 0; i < vertices; i++)
	{
		new_graph -> array_list[i].head = NULL;
	}

	return new_graph;
}

graph *add_node(int src, int dest, graph *current_graph)
{
	if(current_graph == NULL)
		return NULL;

	node *curr_node;
	node *curr_node_2;

	if(current_graph ->  array_list[src].head == NULL)
	{
		curr_node = create_node(dest);
		current_graph -> array_list[src].head = curr_node;
	}

	else
	{
		curr_node = create_node(dest);
		curr_node -> next = current_graph -> array_list[src].head;
		current_graph -> array_list[src].head = curr_node;
	}

	if(current_graph ->  array_list[dest].head == NULL)
	{
		curr_node_2 = create_node(src);
		current_graph -> array_list[dest].head = curr_node_2;
	}

	else
	{
		curr_node_2 = create_node(src);
		curr_node_2 -> next = current_graph -> array_list[dest].head;
		current_graph -> array_list[dest].head = curr_node_2;
	}

	return current_graph;

}

typedef struct queue_create
{
	int value;
	struct queue_create *next;
}queue;

void bfs(graph *current_graph, int current_node)
{
	if(current_graph == NULL)
		return NULL;

	int vertices = current_graph -> vertex;
	int *array_visited = malloc(sizeof(int) * vertices);

	for(i = 0; i < vertices; i++)
	{
		array_visited[i] = 0;
	}

	queue *queue_visited;
	queue_visited = malloc(sizeof(queue));

	queue head;
	queue_visited -> value = current_node;
	queue_visited -> next = NULL;

	head = queue;

	while(array_list[queue_visited -> value] -> head -> next != NULL)
	{
		if(array_visited[queue_visited -> value] != 1)
		{
			array_visited[queue_visited -> value] = 1;
			prinf("%d",queue_visited -> value);
		}

		queue_visited -> next = malloc(sizeof(queue));

		queue -> value = current_graph -> array_list[queue -> value] -> head -> next -> dest;
	}


}

int main()
{
	int i = 0;
	node *val;
	val = create_node(5);
	printf("\n Node -> dest = %d", val -> dest);
	printf("\n Node -> next = %p", val -> next);

	graph *adj_list;
	adj_list = create_graph(20);
	/*printf("\nPrinting the null graph");
	for(i = 0; i < 20 ; i++)
	{
		printf("\ngraph -> array_list[%d].head = %p", i,adj_list -> array_list[i].head);
	}*/
	printf("\n");

	adj_list = add_node(2, 5, adj_list);
	adj_list = add_node(3, 5, adj_list);
	node *temp;
	
	for(i = 0; i < 20 ; i++)
	{
		temp = adj_list -> array_list[i].head;

		printf("\ngraph -> array_list[%d].head = %p", i,adj_list -> array_list[i].head);
		if(adj_list -> array_list[i].head != NULL)
		{
			while(temp -> next != NULL)
			{
				temp  = temp -> next;
				printf("---> %p", temp);
			}
		}
	}

	return 0;

}
/*
int queue_array[MAX];
int rear = - 1;
int front = - 1;

insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty 
        front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} /*End of insert()
 
delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /*End of delete() 
display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} */




