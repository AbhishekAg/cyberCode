#include <stdio.h>
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 
#define NUM_ELEMENTS 10

struct Node {
	int value; 
	struct Node  * left_child_ptr;
	struct Node  * right_child_ptr;
};

typedef struct Node Tree_Node;

Tree_Node   *  root_ptr = NULL;

Tree_Node   * insert_tree_node(int new_value , 
		Tree_Node ** root_d_ptr)
{

	Tree_Node * new_node_ptr  = malloc ( sizeof ( Tree_Node ) );
	assert(new_node_ptr);

	new_node_ptr->value = new_value;
	new_node_ptr->left_child_ptr  = 
		new_node_ptr->right_child_ptr  = NULL;

	if (  *root_d_ptr == NULL)
	{
		*root_d_ptr = new_node_ptr;
		return ( new_node_ptr);

	}

	Tree_Node * current_ptr =   * root_d_ptr;


	while( 1 ) 
	{ 
		if ( new_value == current_ptr->value )  return NULL;

		if ( new_value < current_ptr->value ) 
			if ( current_ptr -> left_child_ptr == NULL) 
			{    
				current_ptr ->left_child_ptr = new_node_ptr;
				break; 
			}    
			else 
				current_ptr = current_ptr -> left_child_ptr;

		if ( new_value> current_ptr->value ) 
			if ( current_ptr -> right_child_ptr == NULL) 
			{
				current_ptr -> right_child_ptr = new_node_ptr;
				break; 
			}        
			else 
				current_ptr = current_ptr -> right_child_ptr;
	} 

	return new_node_ptr;
}  

Tree_Node * search_node(int  value, Tree_Node * ptr)
{

	while( 1) 
	{
		if ( value == ptr-> value ) 
		{
			printf("FOUND\n");
			return( ptr);	
		}

		if ( value < ptr->value ) 
		{
			printf("ptr->value = %d searching left child\n",
					ptr->value); 
			if ( ptr->left_child_ptr == NULL ) 
			{
				printf("NOT FOUND\n");
				return NULL;	
			}
			ptr = ptr -> left_child_ptr;
		}
		else
		{
			printf("ptr->value = %d searching right child\n",
					ptr->value); 
			if ( ptr->right_child_ptr == NULL ) 
			{
				printf("NOT FOUND\n");
				return NULL;	
			}
			ptr = ptr -> right_child_ptr;
		}
	}
}

Tree_Node  * stack[NUM_ELEMENTS];
int          top=-1 ;
#define  PUSH(a) (top< NUM_ELEMENTS-1 ? \
		stack[++top] = a: NULL )
#define  POP     (top >=0 ? stack[top--]: NULL ) 


int inorder_traverse(Tree_Node * ptr)
{
	Tree_Node * current_ptr=ptr;
	while(1)
	{

		while(  current_ptr ) 
		{   PUSH(current_ptr);  
			current_ptr = current_ptr -> left_child_ptr;
		}

		current_ptr = POP;

		if( current_ptr == NULL) break; 

		printf("%d\n", current_ptr->value); 

		current_ptr = current_ptr->right_child_ptr;
	}

}

Tree_Node  * queue[NUM_ELEMENTS];
int          front=0, rear =0, count=0; 

int queue_insert(Tree_Node  *a) 
{
	if ( count==NUM_ELEMENTS ) 
		return 0; 

	queue[ rear ] = a;            
	rear++ ;  
	rear = rear % NUM_ELEMENTS;

	count ++; 

	return 1;
}

Tree_Node  * queue_delete     ( void)
{ 
	if ( count ==0) return NULL;

	int delete_pos = front;

	count --;
	front++; 
	front = front  % NUM_ELEMENTS ;

	return queue[delete_pos ]  ;
}

int preorder_traverse(Tree_Node * ptr)
{
	Tree_Node * current_ptr=NULL;
	Tree_Node * tmp_ptr=NULL;

	PUSH(ptr);
	while ( 1) 
	{
		current_ptr = POP;
		if ( current_ptr == NULL) 
			break;

		queue_insert(current_ptr); 
		//		printf("queued %d\n", current_ptr -> value); 

		if ( current_ptr -> right_child_ptr) 
			PUSH(current_ptr -> right_child_ptr);

		if ( current_ptr -> left_child_ptr) 
			PUSH(current_ptr -> left_child_ptr);
	} 

	while ( tmp_ptr = queue_delete() ) 
		printf("%d\n", tmp_ptr  -> value ); 
}


int delete_node(int value, Tree_Node * ptr,Tree_Node* parent)
{

	Tree_Node * tmp_ptr;

	printf("To delete %d \n", value); 
	if ( value < ptr->value ) 
	{
		printf("ptr->value = %d searching left child\n",
				ptr->value); 
		if ( ptr->left_child_ptr == NULL ) 
		{
			printf("NOT FOUND\n");
			return 0;;	
		}
		delete_node(value, ptr->left_child_ptr,ptr);
	}
	else if ( value > ptr->value ) 
	{
		printf("ptr->value = %d searching right child\n",
				ptr->value); 
		if ( ptr->right_child_ptr == NULL ) 
		{
			printf("NOT FOUND\n");
			return 0;	
		}
		delete_node(value, ptr->right_child_ptr,ptr);
	}
	else if ( value == ptr-> value ) 
	{
		printf("FOUND\n");
		if ( ptr->left_child_ptr == NULL  &&
				ptr->right_child_ptr == NULL )
		{
			/* leaf node */
			printf("LEAF\n");
			if( parent ->left_child_ptr == ptr ) 
			{
				printf("Parents left child\n");
				free(parent->left_child_ptr);
				parent->left_child_ptr = NULL;
			}
			else
			{
				printf("Parents right child\n");
				free(parent->right_child_ptr);
				parent->right_child_ptr = NULL;
			}
			return 0;
		}
		if ( ptr->left_child_ptr == NULL  &&
				ptr->right_child_ptr != NULL )
		{
			/* node with only right child */
			printf("node with only right child\n");
			if( parent ->left_child_ptr == ptr ) 
			{
				printf("Parents left child\n");
				parent->left_child_ptr = 
					ptr->right_child_ptr;
			}
			else
			{
				printf("Parents right child\n");
				parent->right_child_ptr = 
					ptr->right_child_ptr;
			}
			free(ptr);
			return 0;
		}
		if ( ptr->left_child_ptr != NULL  &&
				ptr->right_child_ptr == NULL )
		{
			/* node with only left child */
			printf("node with only left child\n");
			if( parent ->left_child_ptr == ptr ) 
			{
				printf("Parents left child\n");
				parent->left_child_ptr = 
					ptr->left_child_ptr;
			}
			else
			{
				printf("Parents right child\n");
				parent->right_child_ptr = 
					ptr->left_child_ptr;
			}
			free(ptr);
			return 0;
		}
		if ( ptr->left_child_ptr != NULL  &&
				ptr->right_child_ptr != NULL )
		{
			/* node with both  left  and right child */
			/* find maximum of left sub tree */

			tmp_ptr = ptr->left_child_ptr;
			while ( tmp_ptr->right_child_ptr) 
				tmp_ptr = tmp_ptr->right_child_ptr;

			printf("The value to be extra deleted is %d\n",
					tmp_ptr->value); 

			ptr->value = tmp_ptr->value;

			delete_node(tmp_ptr->value, 
					ptr->left_child_ptr, ptr);
			return 0;
		}
	}
}

int main(int argc, char * argv[]) 
{
	int i,value;
	for ( i=0 ;i<NUM_ELEMENTS ;i++)
	{
		scanf("%d",&value);
		insert_tree_node(value,&root_ptr);

	}

	printf("----Inorder traversal-------------------------------\n"); 
	inorder_traverse(root_ptr);
	printf("----------------------------------------------------\n"); 

	printf("Enter a value to delete:"); 
	scanf("%d", &value);

	delete_node(value, root_ptr,NULL);

	printf("----Searching for %d after deletion------------\n",value); 
	search_node(value, root_ptr);

	printf("----Inorder traversal-------------------------------\n"); 
	inorder_traverse(root_ptr);
	printf("----------------------------------------------------\n"); 

	printf("root node is %d\n", root_ptr->value); 
	return 0;
}

