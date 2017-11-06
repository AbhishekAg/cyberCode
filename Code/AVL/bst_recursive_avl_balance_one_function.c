#include <stdio.h>
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 
#define NUM_ELEMENTS 12
#define pvi(V)     printf("%-15s=%-12d\n",#V,V)

struct node {
	int value; 
	int height; 
	int balance_factor;   // stored only for info purpose 
	struct node  * left_child_ptr;
	struct node  * right_child_ptr;
};

typedef struct node tree_node;

tree_node * root_node_ptr = NULL;

#define MAX(x,y) ( (x) >=  ( y) ? (x) : (y) )
#define HEIGHT(x) ( (x) ? ((x) -> height) : 0   )

void print_node( tree_node * ptr)
{

	if ( ptr)  
		printf("Node %d ", ptr->value);

	if( ptr-> left_child_ptr ) 
		printf("Left Child %d ", ptr-> left_child_ptr->value); 
	else
		printf("Left Child EMPTY ");

	if( ptr-> right_child_ptr ) 
		printf("Right Child %d ", ptr-> right_child_ptr->value); 
	else
		printf("Right Child EMPTY ");

	printf("\n"); 

}

void print_node_2levels( tree_node * ptr)
{

	if ( ptr)  
		printf("Node %d ", ptr->value);

	if( ptr-> left_child_ptr ) 
		printf("Left Child %d ", ptr-> left_child_ptr->value); 

	else
		printf("Left Child EMPTY ");

	if( ptr-> right_child_ptr ) 
		printf("Right Child %d ", ptr-> right_child_ptr->value); 
	else
		printf("Right Child EMPTY ");

	printf("\n"); 

	if ( ptr-> left_child_ptr) 
		print_node( ptr-> left_child_ptr);
	if ( ptr-> right_child_ptr) 
		print_node( ptr-> right_child_ptr);

}


tree_node * balance( tree_node * nptr)
{
	tree_node *tptr1, *tptr2, *tptr3, *tptr4; 

	printf("***************************\n"); 
	printf("Rectifying Imbalance at %d\n", nptr->value ); 
	if( nptr->balance_factor > 1 ) 
	{
		// Imbalance on Left Child 

		if (  nptr->left_child_ptr->balance_factor > 0 ) 
		{ 
			// Imbalance on Left Child and further Left Child 

			// LL Correction 
			printf("LL Correction\n"); 

			tptr1 = nptr->left_child_ptr;
			tptr2 = tptr1->right_child_ptr;

			tptr1-> right_child_ptr = nptr; 
			nptr -> left_child_ptr  = tptr2;

			nptr -> height = MAX ( 
					HEIGHT(nptr->left_child_ptr),
					HEIGHT(nptr->right_child_ptr)
					)  + 1; 

			nptr->balance_factor = 
				HEIGHT(nptr->left_child_ptr) 
				-
				HEIGHT(nptr->right_child_ptr) ;

			tptr1 -> height = MAX ( 
					HEIGHT(tptr1->left_child_ptr),
					HEIGHT(tptr1->right_child_ptr)
					)  + 1; 

			tptr1->balance_factor = 
				HEIGHT(tptr1->left_child_ptr) 
				-
				HEIGHT(tptr1->right_child_ptr) ;


			printf("After correction :\n"); 
			print_node_2levels(tptr1);
			printf("***************************\n"); 
			return tptr1;
		}

		if (  nptr->left_child_ptr->balance_factor < 0 ) 
		{ 
			// Imbalance on Left Child and further Right Child 

			// LR Correction 
			printf("LR Correction\n"); 

			tptr1 = nptr->left_child_ptr;
			tptr2 = tptr1->right_child_ptr;

			tptr3 = tptr2-> left_child_ptr;
			tptr4 = tptr2-> right_child_ptr;


			tptr2-> left_child_ptr = tptr1; 
			tptr2-> right_child_ptr = nptr; 

			tptr1->right_child_ptr = tptr3;
			nptr-> left_child_ptr  = tptr4;

			nptr -> height = MAX ( 
					HEIGHT(nptr->left_child_ptr),
					HEIGHT(nptr->right_child_ptr)
					)  + 1; 

			nptr->balance_factor = 
				HEIGHT(nptr->left_child_ptr) 
				-
				HEIGHT(nptr->right_child_ptr) ;

			tptr1 -> height = MAX ( 
					HEIGHT(tptr1->left_child_ptr),
					HEIGHT(tptr1->right_child_ptr)
					)  + 1; 

			tptr1->balance_factor = 
				HEIGHT(tptr1->left_child_ptr) 
				-
				HEIGHT(tptr1->right_child_ptr) ;

			tptr2 -> height = MAX ( 
					HEIGHT(tptr2->left_child_ptr),
					HEIGHT(tptr2->right_child_ptr)
					)  + 2; 

			tptr2->balance_factor = 
				HEIGHT(tptr2->left_child_ptr) 
				-
				HEIGHT(tptr2->right_child_ptr) ;

			printf("After correction :\n"); 
			print_node_2levels(tptr2);
			printf("***************************\n"); 
			return tptr2;

		}
	}

	if( nptr->balance_factor < -1 )
	{
		/* Imbalance on Right Child  */

		if ( nptr->right_child_ptr->balance_factor > 0 ) 
		{ 
			// Imbalance on Right Child and further Left Child 

			// RL correction
			printf("RL Correction\n"); 

			tptr1 = nptr->right_child_ptr;
			tptr2 = tptr1->left_child_ptr;

			tptr3 = tptr2-> left_child_ptr;
			tptr4 = tptr2-> right_child_ptr;


			tptr2-> left_child_ptr = nptr; 
			tptr2-> right_child_ptr = tptr1; 

			tptr1->left_child_ptr = tptr4;
			nptr-> right_child_ptr  = tptr3;

			nptr -> height = MAX ( 
					HEIGHT(nptr->left_child_ptr),
					HEIGHT(nptr->right_child_ptr)
					)  + 1; 

			nptr->balance_factor = 
				HEIGHT(nptr->left_child_ptr) 
				-
				HEIGHT(nptr->right_child_ptr) ;

			tptr1 -> height = MAX ( 
					HEIGHT(tptr1->left_child_ptr),
					HEIGHT(tptr1->right_child_ptr)
					)  + 1; 

			tptr1->balance_factor = 
				HEIGHT(tptr1->left_child_ptr) 
				-
				HEIGHT(tptr1->right_child_ptr) ;

			tptr2 -> height = MAX ( 
					HEIGHT(tptr2->left_child_ptr),
					HEIGHT(tptr2->right_child_ptr)
					)  + 1; 

			tptr2->balance_factor = 
				HEIGHT(tptr2->left_child_ptr) 
				-
				HEIGHT(tptr2->right_child_ptr) ;

			printf("After correction :\n"); 
			print_node_2levels(tptr2);
			printf("***************************\n"); 
			return tptr2;

		}

		if ( nptr->right_child_ptr->balance_factor < 0 ) 
		{ 
			// Imbalance on Right Child and further Right Child 

			// RR correction 
			printf("RR Correction\n"); 

			tptr1 = nptr->right_child_ptr;
			tptr2 = tptr1->left_child_ptr;

			tptr1-> left_child_ptr = nptr; 
			nptr -> right_child_ptr  = tptr2;

			nptr -> height = MAX ( 
					HEIGHT(nptr->left_child_ptr),
					HEIGHT(nptr->right_child_ptr)
					)  + 1; 

			nptr->balance_factor = 
				HEIGHT(nptr->left_child_ptr) 
				-
				HEIGHT(nptr->right_child_ptr) ;

			tptr1 -> height = MAX ( 
					HEIGHT(tptr1->left_child_ptr),
					HEIGHT(tptr1->right_child_ptr)
					)  + 1; 

			tptr1->balance_factor = 
				HEIGHT(tptr1->left_child_ptr) 
				-
				HEIGHT(tptr1->right_child_ptr) ;

			printf("After correction :\n"); 
			print_node_2levels(tptr1);
			printf("***************************\n"); 
			return tptr1;
		}
	}
}

tree_node * insert_tree_node(int value, tree_node  * nptr)
{

	if ( ! nptr)
	{
		root_node_ptr = ( tree_node * ) malloc ( 
				sizeof ( tree_node));
		assert(root_node_ptr);
		root_node_ptr->value = value;
		root_node_ptr->height = 1;
		root_node_ptr->balance_factor = 0 ;
		return(root_node_ptr);
	}

	/* Check if to insert left */
	if ( value < nptr->value ) 
	{
		/* If left child exist insert on left child */
		if ( nptr->left_child_ptr) 
			nptr->left_child_ptr =  insert_tree_node( 
					value, nptr->left_child_ptr);

		/* If left child doesn't exist, we found a place
		   to insert */
		else
		{
			nptr->left_child_ptr =
				( tree_node * ) malloc ( sizeof ( tree_node ) );
			assert( nptr->left_child_ptr );
			nptr->left_child_ptr-> value = value;
			nptr->left_child_ptr-> height = 1;
			nptr->left_child_ptr-> balance_factor = 0;
		}
	}
	/* insert right */
	else
	{

		/* If right child exist insert on right child */
		if ( nptr->right_child_ptr) 
			nptr->right_child_ptr = insert_tree_node( 
					value, nptr->right_child_ptr);

		/* If right child doesn't exist, we found a place
		   to insert */
		else
		{
			nptr->right_child_ptr =
				( tree_node * ) malloc ( sizeof ( tree_node ) );
			assert( nptr->right_child_ptr );
			nptr->right_child_ptr-> value = value;
			nptr->right_child_ptr-> height = 1;
			nptr->right_child_ptr-> balance_factor = 0;
		}
	}

	nptr -> height = MAX ( 
			HEIGHT(nptr->left_child_ptr),
			HEIGHT(nptr->right_child_ptr)
			)  + 1; 

	nptr->balance_factor = 
		HEIGHT(nptr->left_child_ptr) 
		-
		HEIGHT(nptr->right_child_ptr) ;

	printf("Node %d, Balance factor  %d Height %d\n", 
			nptr->value,
			nptr->balance_factor,
			nptr->height
	      ) ; 


	if ( nptr->balance_factor == -2 
			|| nptr->balance_factor == 2) 
		return balance(nptr);
	else
		return nptr;
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
	printf("%d height %d balance factor %d \n", 
			ptr->value, ptr->height,
			ptr->balance_factor);
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

tree_node * delete_node(int value, tree_node * ptr,tree_node* parent)
{

	tree_node * tmp_ptr, *left_child_ptr,*right_child_ptr;

	if ( value < ptr->value ) 
	{
		printf("ptr->value = %d searching left child\n",ptr->value); 
		if ( ptr->left_child_ptr == NULL ) 
		{
			printf("NOT FOUND\n");
			return 0;;	
		}
		ptr->left_child_ptr = 
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
		ptr->right_child_ptr = 
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

			/* CHeck if we are delting the root node */
			if( parent ->left_child_ptr == ptr ) 
			{
				printf("Parents left child\n");
				parent->left_child_ptr = NULL;
			}
			else
			{
				printf("Parents right child\n");
				parent->right_child_ptr = NULL;
			}
			free(ptr);
			return NULL;

		}
		if ( ptr->left_child_ptr == NULL  &&
				ptr->right_child_ptr != NULL )
		{
			/* node with only right child */
			printf("node with only right child\n");
			right_child_ptr = ptr->right_child_ptr;

			if( parent ->left_child_ptr == ptr ) 
			{
				printf("Parents left child\n");
				parent->left_child_ptr = right_child_ptr;
			}
			else
			{
				printf("Parents right child\n");
				parent->right_child_ptr = right_child_ptr;
			}
			free(ptr);
			return right_child_ptr;
		}
		if ( ptr->left_child_ptr != NULL  &&
				ptr->right_child_ptr == NULL )
		{
			/* node with only left child */
			printf("node with only left child\n");
			left_child_ptr = ptr->left_child_ptr;

			if( parent ->left_child_ptr == ptr ) 
			{
				printf("Parents left child\n");
				parent->left_child_ptr = left_child_ptr;
			}
			else
			{
				printf("Parents right child\n");
				parent->right_child_ptr = left_child_ptr;
			}
			free(ptr);
			return left_child_ptr;
		}
		if ( ptr->left_child_ptr != NULL  &&
				ptr->right_child_ptr != NULL )
		{
			/* node with both  left  and right child */
			/* find MAXimum of left sub tree */

			tmp_ptr = ptr->left_child_ptr;
			while ( tmp_ptr->right_child_ptr) 
				tmp_ptr = tmp_ptr->right_child_ptr;
			printf("The value to be extra deleted is %d\n",
					tmp_ptr->value); 
			ptr->value = tmp_ptr->value;

			ptr->left_child_ptr = 
				delete_node(tmp_ptr->value, ptr->left_child_ptr, ptr);

		}
	}

	/* Now check for imbalance and return */
	ptr -> height = MAX ( 
			HEIGHT(ptr->left_child_ptr),
			HEIGHT(ptr->right_child_ptr)
			)  + 1; 

	ptr->balance_factor = 
		HEIGHT(ptr->left_child_ptr) 
		-
		HEIGHT(ptr->right_child_ptr) ;

	printf("Node %d, Balance factor  %d Height %d\n", 
			ptr->value,
			ptr->balance_factor,
			ptr->height
	      ) ; 

	if ( ptr->balance_factor == -2 
			|| ptr->balance_factor == 2) 
	{
		return balance(ptr);
	}
	else
		return ptr;

}


int binary_tree_height( tree_node * ptr) 
{

	if ( ! ptr) return 0;

	return  MAX (  
			binary_tree_height( ptr->left_child_ptr), 
			binary_tree_height( ptr->right_child_ptr)
		    ) + 1 ;


} 

void level_order_traversal(tree_node * ptr);

int main(int argc, char * argv[]) 
{
	int i,value;
	for ( i=0 ;i<NUM_ELEMENTS ;i++)
	{
		scanf("%d",&value);
		printf("Inserting %d\n", value); 
		root_node_ptr = insert_tree_node(value,root_node_ptr);
		pvi(root_node_ptr->height);	
		printf("----------------------------------------------------\n"); 

	}

	printf("---------------LEVEL ORDER TRAVERSAL----------------\n"); 
	level_order_traversal(root_node_ptr);
	printf("\nHeight Of the AVL tree  is %d\n", binary_tree_height(root_node_ptr )) ;
	printf("---------------IN ORDER TRAVERSAL-------------------\n"); 
	inorder_traverse(root_node_ptr);
	printf("----------------------------------------------------\n"); 


	scanf("%d", &value);
	printf("VALUE To delete is %d\n", value); 

	root_node_ptr =  delete_node(value, root_node_ptr,NULL);

	search_node(value, root_node_ptr);

	printf("---------------LEVEL ORDER TRAVERSAL----------------\n"); 
	level_order_traversal(root_node_ptr);
	printf("\nHeight Of the AVL tree  is %d\n", binary_tree_height(root_node_ptr )) ;
	printf("---------------IN ORDER TRAVERSAL-------------------\n"); 
	inorder_traverse(root_node_ptr);
	printf("----------------------------------------------------\n"); 

	return 0;
}


/* _______Level order for display   __________________________ */

struct qnode { 
	tree_node * tree_node_ptr;
	struct qnode * np;
};

struct qnode *first_qnode=NULL, *last_qnode=NULL, *new_qnode;

int insert_qnode( tree_node * ptr)
{
	new_qnode = malloc(sizeof(struct qnode));
	if( new_qnode == NULL)
	{
		printf("Error with malloc\n"); 
		return -1;
	}
	new_qnode-> tree_node_ptr = ptr;
	new_qnode-> np            = NULL;

	if( first_qnode==NULL)
	{
		first_qnode=last_qnode=new_qnode;
		return 1;
	}
	else
	{
		last_qnode -> np = new_qnode;
		last_qnode       = new_qnode;
		return 1;
	}
}

tree_node * delete_qnode()
{
	struct qnode * tmp_ptr;
	tree_node    * ptr;

	if( first_qnode==NULL) 
		return NULL;

	ptr = first_qnode -> tree_node_ptr;

	tmp_ptr = first_qnode;
	first_qnode = first_qnode->np;
	free(tmp_ptr);

	return ptr;
}

void level_order_traversal(tree_node * ptr)
{


	if( !ptr) return ;

	printf("Root %d\n", ptr->value); 

	if( ptr->left_child_ptr) 
	{
		printf("	Left Child %d\n", 
				ptr->left_child_ptr->value); 
		insert_qnode(ptr->left_child_ptr);
	}
	else
		printf("	Left Child EMPTY\n"); 

	if( ptr->right_child_ptr) 
	{
		printf("	Right Child %d\n", 
				ptr->right_child_ptr->value); 
		insert_qnode(ptr->right_child_ptr);
	}
	else
		printf("	Right Child EMPTY\n"); 

	while( ptr = delete_qnode() ) 
	{
		printf("Node %d\n", ptr->value); 

		if( ptr->left_child_ptr) 
		{
			printf("	Left Child %d\n", 
					ptr->left_child_ptr->value); 
			insert_qnode(ptr->left_child_ptr);
		}
		else
			printf("	Left Child EMPTY\n"); 

		if( ptr->right_child_ptr) 
		{
			printf("	Right Child %d\n", 
					ptr->right_child_ptr->value); 
			insert_qnode(ptr->right_child_ptr);
		}
		else
			printf("	Right Child EMPTY\n"); 

	}
} 
