#include <stdio.h>
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 
#define NUM_ELEMENTS 10

#define RED    1
#define BLACK  0

struct Node {
	int value:31; 
	int rb:1;

	struct Node  * left_child_ptr;
	struct Node  * right_child_ptr;
	struct Node  * parent_ptr;
};

typedef struct Node Tree_Node;

Tree_Node   *  root_ptr = NULL;

Tree_Node   * insert_tree_node(int new_value , 
		Tree_Node ** root_d_ptr)
{

	Tree_Node * new_node_ptr  = malloc ( sizeof ( Tree_Node ) );
	assert(new_node_ptr);

	new_node_ptr->value = new_value;
	new_node_ptr->rb    = RED;
	new_node_ptr->left_child_ptr  = 
		new_node_ptr->right_child_ptr  = 
			new_node_ptr->parent_ptr       =   NULL;


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
				new_node_ptr -> parent_ptr = current_ptr ;
				break; 
			}    
			else 
				current_ptr = current_ptr -> left_child_ptr;

		if ( new_value> current_ptr->value ) 
			if ( current_ptr -> right_child_ptr == NULL) 
			{
				current_ptr -> right_child_ptr = new_node_ptr;
				new_node_ptr -> parent_ptr = current_ptr ;
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



int preorder_traverse(Tree_Node * ptr)
{
	if ( !ptr ) return 0;

	printf("%d\n", ptr->value);
	preorder_traverse(ptr->left_child_ptr);
	preorder_traverse(ptr->right_child_ptr);

	return 0;
}

#define DEBUG

int inorder_traverse(Tree_Node * ptr)
{
	if ( !ptr ) return 0;

	inorder_traverse(ptr->left_child_ptr);
	printf("%d", ptr->value);
#ifdef DEBUG
	printf("\tColor=%s\t", 
			ptr->rb?"Red":"Black");

	if( ptr->parent_ptr)
		printf("%d", ptr->parent_ptr->value);
	else
		printf("Parent Ptr is NULL"); 
#endif 
	printf("\n"); 
	inorder_traverse(ptr->right_child_ptr);

	return 0;
}
int postorder_traverse(Tree_Node * ptr)
{
	if ( !ptr ) return 0;

	postorder_traverse(ptr->left_child_ptr);
	postorder_traverse(ptr->right_child_ptr);
	printf("%d\n", ptr->value);

	return 0;
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
			ptr->right_child_ptr->parent_ptr = parent;
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
			ptr->left_child_ptr->parent_ptr = parent;
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

