#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphsearch.h"

void free_LLint(LLint *list){
	LLint *freethis;
	while(list != NULL){
		freethis = list;
		list = list->next;
		free(freethis);
	}

}
void free_LLPath(LLPath *path){
	LLPath *freethis;
	while(path != NULL){
		freethis = path;
		path = path->next;
		free(freethis);
	}
}

// dealing with sets of integers. We wrote these in class.
LLint *add_to_set(LLint *set, int val) {
  LLint *newfront = calloc(1, sizeof(LLint));
  newfront->val = val;
  newfront->next = set;
  return newfront;
}

bool set_contains(LLint *set, int val) {
  if (set == NULL) {
    return false;
  } else if (set->val == val) {
    return true;
  } else {
    return set_contains(set->next, val);
  }
}

LLint *enqueue_int(LLint *q, int val) {	//from the class lecture
  LLint *newint = calloc(1, sizeof(LLint));
  newint->val = val;
  if (q == NULL) {
    return newint;
  }
  LLint *current = q;
 // while(current->next != NULL) {
   // current = current->next;
 // }
  current->next = newint;
  return q;
}

bool dequeue_int(LLint **q, int *ret) {	//from the class lecture
  if (*q == NULL) {
    return false;
  }

  *ret = (*q)->val;
  
  LLint *freethis = *q;
  *q = (*q)->next;
  free(freethis);
  return true;
}
// Linked lists of paths. You'll need to implement these.

// Returns the new front of the queue, for a queue of Path structs.
// Usually this will be the old front of the queue, but if q is NULL, then it
// will allocate a new linked list node and return that.
LLPath *enqueue_path(LLPath *q, Path path) {
  // YOUR CODE HERE
  LLPath *newpath = (LLPath *)calloc(1, sizeof(LLPath));	//creates a new path
  newpath->val = path;	//assigns that path that we want to add
  if(q == NULL){return newpath;}	//runs if the linked list is null
  LLPath *temp = q; //takes the pointer of q
  //while(temp->next != NULL){	//this takes us to the bottom the list to add it there
  	//temp = temp->next;			//everything must go in order
 // }									//this makes it first in, first out
  temp->next = newpath; //this adds the new path to the bottom of the list
  return q;
}

bool dequeue_path(LLPath **q, Path *ret) {
  // YOUR CODE HERE
  if(*q == NULL){
  	return false;
  }
  *ret = (*q)->val;
  LLPath *delete = *q;
  *q = (*q)->next;	//assign to actually delete
  free(delete);	//action of freeing the memory
  return true;
}

// We wrote these in class.
Graph *graph_create(int vertices) {
  Graph *g = (Graph *)malloc(sizeof(Graph));
  g->vertices = vertices;
  g->matrix = (int **)calloc(vertices, sizeof(int*));
  for (int i=0; i < vertices; i++) {
    g->matrix[i] = (int *)calloc(vertices, sizeof(int));
  }
  return g;
}

void graph_add_edge(Graph *g, int i, int j) {
  g->matrix[i][j] = 1;
}

bool graph_has_edge(Graph *g, int i, int j) {
  return g->matrix[i][j];
}

// Convenience method for you -- returns a new Path where you have added another
// vertex along the path.
Path path_extend(Path path, int new_vertex) {
  Path out;
  out.steps = path.steps;
  for (int i=0; i < path.steps; i++) {
    out.vertices_visited[i] = path.vertices_visited[i];
  }
  out.vertices_visited[path.steps] = new_vertex;
  out.steps += 1;
  return out;
}

// Print out a path nicely for the user.
void print_path(Path path) {
  if (path.steps == 0) {
    puts("(empty path)");
  }
  for (int i=0; i < path.steps; i++) {
    printf("%s%d",
        (i == 0) ? "" : " -> ",
        path.vertices_visited[i]);
  }
  puts("");
}

// Breadth-first search!
Path graph_find_path_bfs(Graph *g, int i, int j) {
  // YOUR CODE HERE.
  LLint *visited = NULL;	//keeps a list of the paths we want to visit
  LLint *to_visit = NULL;	//keeps a list of the paths we already visit
  LLPath *llpath = NULL;
  Path my_path;
  Path add_path;
  int current;
  to_visit = enqueue_int(to_visit, i);	//adds a path to the queue
  while(to_visit != NULL){
  		dequeue_int(&to_visit, &current);
		if(my_path.steps == 0){
			my_path = path_extend(my_path, i);
		} else{
		  	dequeue_path(&llpath, &my_path);
		}
  		if(current == j){
  		   free_LLint(visited);//functions made to free the rest of the linked lists
  		   free_LLint(to_visit);
  		  	free_LLPath(llpath);
  			return my_path;
		}
		visited = add_to_set(visited, current);
		for(int nextdoor = 0; nextdoor < g->vertices; nextdoor++){
			if(graph_has_edge(g, current, nextdoor) && !set_contains(visited, nextdoor) && current != nextdoor){
				add_path = path_extend(my_path, nextdoor);
				to_visit = enqueue_int(to_visit, nextdoor);
				llpath = enqueue_path(llpath, add_path);
			}
		} 
  }
	Path empty = {0, {0}};
	return empty;
}


// Depth-first search!
Path graph_find_path_dfs(Graph *g, int i, int j) {
  // YOUR CODE HERE.
  LLint *visited = NULL;	//keeps a list of the paths we want to visit
  LLint *to_visit = NULL;	//keeps a list of the paths we already visit
  Path my_path;
  my_path.steps = 0;
  to_visit = enqueue_int(to_visit, i);	//adds a path to the queue
  while(to_visit != NULL){
		int current;
  		dequeue_int(&to_visit, &current);
  		if(current == j){
  		  	my_path = path_extend(my_path, current);
  		  	free_LLint(visited);
  		  	free_LLint(to_visit);
  			return my_path;
		}
  		for(int nextdoor = 0; nextdoor < g->vertices; nextdoor++){
  			if(graph_has_edge(g, current, nextdoor) && !set_contains(visited, nextdoor)){
			if(!set_contains(visited, current)){	//to avoid repeats
	  			my_path.vertices_visited[my_path.steps] = current;//adds this node integer to the path
				my_path.steps++;	//increments the size of the path
			}
  			to_visit = enqueue_int(to_visit, nextdoor);
  			visited = add_to_set(visited, current);
  			}
  		}
  }
  Path empty = {0, {0}};
  return empty;
}


























