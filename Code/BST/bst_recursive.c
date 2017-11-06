#include <stdio.h>
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 
#define NUM_ELEMENTS 10

struct node {
	int value; 
	struct node  * left_child_ptr;
	struct node  * right_child_ptr;
};

typedef struct node tree_node;

tree_node * root_node_ptr = NULL;

int insert_tree_node(int value, tree_node  * nptr)
{
	if ( ! nptr)
	{
		root_node_ptr = ( tree_node * ) calloc ( 
				sizeof ( tree_node),1);
		assert(root_node_ptr);
		root_node_ptr->value = value;
		return(0);
	}

	/* Check if to insert left */
	if ( value < nptr->value ) 
	{
		/* If left child exist insert on left child */
		if ( nptr->left_child_ptr) 
			insert_tree_node( value, nptr->left_child_ptr);
		/* If left child doesn't exist, we found a place
		   to insert */
		else
		{
			nptr->left_child_ptr =
				( tree_node * ) malloc ( 
						sizeof ( tree_node));
			assert( nptr->left_child_ptr );
			nptr->left_child_ptr-> value = value;
			return 0;
		}


	}
	/* insert right */
	else
	{

		/* If right child exist insert on right child */
		if ( nptr->right_child_ptr) 
			insert_tree_node( value, nptr->right_child_ptr);
		/* If right child doesn't exist, we found a place
		   to insert */
		else
		{
			nptr->right_child_ptr =
				( tree_node * ) calloc ( 
						sizeof ( tree_node),1);
			assert( nptr->right_child_ptr );
			nptr->right_child_ptr-> value = value;
			return 0;
		}
	}
}  


int preorder_traverse(tree_node * ptr)
{
	if ( !ptr ) return 0;

	printf("%d\n", ptr->value);
	if ( ptr->left_child_ptr)  
		preorder_traverse(ptr->left_child_ptr);
	if ( ptr->right_child_ptr)  
		preorder_traverse(ptr->right_child_ptr);

	return 0;
}

int inorder_traverse(tree_node * ptr)
{
	if ( !ptr ) return 0;

	if ( ptr->left_child_ptr)  
		inorder_traverse(ptr->left_child_ptr);
	printf("%d\n", ptr->value);
	if ( ptr->right_child_ptr)  
		inorder_traverse(ptr->right_child_ptr);

	return 0;
}
int postorder_traverse(tree_node * ptr)
{
	if ( !ptr ) return 0;

	if ( ptr->left_child_ptr)  
		postorder_traverse(ptr->left_child_ptr);
	if ( ptr->right_child_ptr)  
		postorder_traverse(ptr->right_child_ptr);
	printf("%d\n", ptr->value);

	return 0;
}

tree_node * search_node(int  value, tree_node * ptr)
{
	if ( value == ptr-> value ) 
	{
		printf("FOUND\n");
		return( ptr);	
	}

	if ( value < ptr->value ) 
	{
		printf("ptr->value = %d searching left child\n",ptr->value); 
		if ( ptr->left_child_ptr == NULL ) 
		{
			printf("NOT FOUND\n");
		        return NULL;	
		}
		search_node(value, ptr->left_child_ptr);
	}
	else
	{
		printf("ptr->value = %d searching right child\n",ptr->value); 
		if ( ptr->right_child_ptr == NULL ) 
		{
			printf("NOT FOUND\n");
		        return NULL;	
		}
		search_node(value, ptr->right_child_ptr);
	}
}

int delete_node(int value, tree_node * ptr,tree_node* parent)
{
	tree_node * tmp_ptr;

	printf("To delete %d \n", value); 
	if ( value < ptr->value ) 
	{
		printf("ptr->value = %d searching left child\n",ptr->value); 
		if ( ptr->left_child_ptr == NULL ) 
		{
			printf("NOT FOUND\n");
		        return 0;;	
		}
		delete_node(value, ptr->left_child_ptr,ptr);
	}
	else if ( value > ptr->value ) 
	{
		printf("ptr->value = %d searching right child\n",ptr->value); 
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
			printf("returning LEAF\n");
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
				parent->left_child_ptr = ptr->right_child_ptr;
			}
			else
			{
				printf("Parents right child\n");
				parent->right_child_ptr = ptr->right_child_ptr;
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
				parent->left_child_ptr = ptr->left_child_ptr;
			}
			else
			{
				printf("Parents right child\n");
				parent->right_child_ptr = ptr->left_child_ptr;
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
			delete_node(tmp_ptr->value, ptr->left_child_ptr, ptr);
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
		insert_tree_node(value,root_node_ptr);

	}

	inorder_traverse(root_node_ptr);

	scanf("%d", &value);
	printf("VALUE is %d\n", value); 

	delete_node(value, root_node_ptr,NULL);

	search_node(value, root_node_ptr);

	inorder_traverse(root_node_ptr);

	printf("root node is %d\n", root_node_ptr->value); 
	return 0;
}

