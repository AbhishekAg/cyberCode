#include <stdio.h>
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 
#define NUM_ELEMENTS 10

#define pvi(V)     printf("%-15s=%-12d\n",#V,V)
#define pvp(V)     printf("%-15s=%-12p\n",#V,V)
 
#define RED    1
#define BLACK  0

#define COLOR(PTR) ( (PTR)  ?  ((PTR)->rb?"Red":"Black")  :  "Black"   )

enum { LL, LR, RL, RR };

struct Node {
	int value:31; 
	unsigned int rb:1;

	struct Node  * left_child_ptr;
	struct Node  * right_child_ptr;
	struct Node  * parent_ptr;
};

typedef struct Node Tree_Node;

Tree_Node   *  root_ptr = NULL;

void XY_RED_correction(Tree_Node * node_ptr, int XY, Tree_Node ** root_d_ptr)
{

	Tree_Node 	* PARENT_PTR = node_ptr->parent_ptr;
	Tree_Node 	* GRAND_PARENT_PTR = PARENT_PTR->parent_ptr;

	printf("\n"); 
	PARENT_PTR -> rb = BLACK;
	if ( GRAND_PARENT_PTR != * root_d_ptr)
		GRAND_PARENT_PTR -> rb = RED;

	switch(XY)
	{
		case LL:
			printf("LL XY_RED_correction for:"); 
			pvi(node_ptr -> value);

		case LR:
			printf("LR XY_RED_correction for:"); 
			pvi(node_ptr -> value);

			GRAND_PARENT_PTR -> right_child_ptr -> rb = BLACK; 
			break;
		case RL:
			printf("RL XY_RED_correction for:"); 
			pvi(node_ptr -> value);

		case RR:
			printf("RR XY_RED_correction for:"); 
			pvi(node_ptr -> value);

			GRAND_PARENT_PTR -> left_child_ptr -> rb = BLACK; 
			break;
	}
	printf("XY_RED_correction completed:");
	pvi(node_ptr -> value);
	printf("\n"); 
} 


void XY_BLACK_correction(Tree_Node * node_ptr, int XY, Tree_Node ** root_d_ptr)
{
	Tree_Node * PARENT_PTR = node_ptr->parent_ptr;
	Tree_Node * GRAND_PARENT_PTR = PARENT_PTR->parent_ptr;

 

	Tree_Node * PARENTS_LEFT_CHILD_PTR  =
		PARENT_PTR->left_child_ptr;

	Tree_Node * PARENTS_RIGHT_CHILD_PTR = 
		PARENT_PTR->right_child_ptr;

	Tree_Node * PARENT_OF_GRAND_PARENT_PTR =
		GRAND_PARENT_PTR -> parent_ptr;

	printf("\n"); 
	switch(XY)
	{
		case LL:

			printf("LL XY_BLACK_correction for:"); 
			pvi(node_ptr -> value);

			PARENT_PTR -> right_child_ptr = GRAND_PARENT_PTR;
			GRAND_PARENT_PTR->parent_ptr  =  PARENT_PTR;

			GRAND_PARENT_PTR -> left_child_ptr = PARENTS_RIGHT_CHILD_PTR;
			if ( PARENTS_RIGHT_CHILD_PTR)
				PARENTS_RIGHT_CHILD_PTR->parent_ptr= GRAND_PARENT_PTR;


			if ( PARENT_OF_GRAND_PARENT_PTR) 
			{
				if ( GRAND_PARENT_PTR == 
						PARENT_OF_GRAND_PARENT_PTR-> left_child_ptr)

					PARENT_OF_GRAND_PARENT_PTR-> left_child_ptr 
						= PARENT_PTR; 
				else 

					PARENT_OF_GRAND_PARENT_PTR-> right_child_ptr 
						= PARENT_PTR; 

				PARENT_PTR -> parent_ptr = PARENT_OF_GRAND_PARENT_PTR; 
			}
			else
			{
				*root_d_ptr = PARENT_PTR;
				(*root_d_ptr) -> parent_ptr = NULL;
			}
			PARENT_PTR->rb= BLACK;
			GRAND_PARENT_PTR -> rb = RED; 
			break;

		case RR:
			printf("RR XY_BLACK_correction for:"); 
			pvi(node_ptr -> value);

			PARENT_PTR -> left_child_ptr = GRAND_PARENT_PTR;
			GRAND_PARENT_PTR->parent_ptr  =  PARENT_PTR;

			GRAND_PARENT_PTR -> right_child_ptr = PARENTS_LEFT_CHILD_PTR;
			if ( PARENTS_LEFT_CHILD_PTR)
				PARENTS_LEFT_CHILD_PTR->parent_ptr= GRAND_PARENT_PTR;

			if ( PARENT_OF_GRAND_PARENT_PTR) 
			{
				if ( GRAND_PARENT_PTR == 
						PARENT_OF_GRAND_PARENT_PTR-> left_child_ptr)

					PARENT_OF_GRAND_PARENT_PTR-> left_child_ptr 
						= PARENT_PTR; 
				else 

					PARENT_OF_GRAND_PARENT_PTR-> right_child_ptr 
						= PARENT_PTR; 

				PARENT_PTR -> parent_ptr = PARENT_OF_GRAND_PARENT_PTR; 
			}
			else
			{
				*root_d_ptr = PARENT_PTR;
				(*root_d_ptr) -> parent_ptr = NULL;
			}


			PARENT_PTR->rb= BLACK;
			GRAND_PARENT_PTR -> rb = RED; 
			break;

		case LR:
			printf("LR XY_BLACK_correction for:"); 
			pvi(node_ptr -> value);

			GRAND_PARENT_PTR -> left_child_ptr =
				node_ptr -> right_child_ptr ;

			if( node_ptr -> right_child_ptr )
				node_ptr -> right_child_ptr -> parent_ptr = GRAND_PARENT_PTR;

			PARENT_PTR -> right_child_ptr =
				node_ptr -> left_child_ptr ;

			if(node_ptr -> left_child_ptr)
				node_ptr -> left_child_ptr->parent_ptr = PARENT_PTR ;

			/* The above two link updates should first happen
			   We will be assignning to node_ptr-> left_child_ptr 
			   and node_right_ptr.  So the previous valus should be 
			   updated as the children of Grand Parent and parent.
			 */

			node_ptr -> left_child_ptr = PARENT_PTR;
			PARENT_PTR -> parent_ptr = node_ptr;

			node_ptr -> right_child_ptr = GRAND_PARENT_PTR;
			GRAND_PARENT_PTR -> parent_ptr = node_ptr;

			if ( PARENT_OF_GRAND_PARENT_PTR) 
			{
				if ( GRAND_PARENT_PTR == 
						PARENT_OF_GRAND_PARENT_PTR-> left_child_ptr)

					PARENT_OF_GRAND_PARENT_PTR-> left_child_ptr 
						= node_ptr; 
				else 

					PARENT_OF_GRAND_PARENT_PTR-> right_child_ptr 
						= node_ptr; 

				node_ptr -> parent_ptr = PARENT_OF_GRAND_PARENT_PTR; 
			}
			else
			{
				*root_d_ptr = node_ptr;
				(*root_d_ptr) -> parent_ptr = NULL;
			}


			node_ptr -> rb = BLACK;
			GRAND_PARENT_PTR -> rb = RED;
			break;

		case RL:
			printf("RL XY_BLACK_correction for:"); 
			pvi(node_ptr -> value);

			GRAND_PARENT_PTR -> right_child_ptr =
				node_ptr -> left_child_ptr ;

			if( node_ptr -> left_child_ptr)
				node_ptr -> left_child_ptr -> parent_ptr = GRAND_PARENT_PTR;


			PARENT_PTR -> left_child_ptr =
				node_ptr -> right_child_ptr ;

			if(node_ptr -> right_child_ptr)
				node_ptr -> right_child_ptr->parent_ptr = PARENT_PTR ;

			/* The above two link updates should first happen
			   We will be assignning to node_ptr-> left_child_ptr 
			   and node_right_ptr.  So the previous valus should be 
			   updated as the children of Grand Parent and parent.
			 */
			node_ptr -> left_child_ptr = GRAND_PARENT_PTR;
			GRAND_PARENT_PTR -> parent_ptr = node_ptr;

			node_ptr -> right_child_ptr = PARENT_PTR;
			PARENT_PTR -> parent_ptr = node_ptr;

			if ( PARENT_OF_GRAND_PARENT_PTR) 
			{
				if ( GRAND_PARENT_PTR == 
						PARENT_OF_GRAND_PARENT_PTR-> left_child_ptr)

					PARENT_OF_GRAND_PARENT_PTR-> left_child_ptr 
						= node_ptr; 
				else 

					PARENT_OF_GRAND_PARENT_PTR-> right_child_ptr 
						= node_ptr; 

				node_ptr -> parent_ptr = PARENT_OF_GRAND_PARENT_PTR; 
			}
			else
			{
				*root_d_ptr =  node_ptr; 
				(*root_d_ptr) -> parent_ptr = NULL;
			}

			node_ptr -> rb = BLACK;
			GRAND_PARENT_PTR -> rb = RED;
			break;

	}
	printf("XY_BLACK_correction completed for :");
	pvi(node_ptr -> value);
	printf("\n"); 
}


void balance(Tree_Node * node_ptr, Tree_Node ** root_d_ptr)
{
	// This function first categories the imbalance as
	//   XY Red  or XY Black, where X and Y can be L or R.

	int XY, GRAND_PARENTS_ANOTHER_CHILD_COLOR;

	Tree_Node 	* PARENT_PTR = node_ptr->parent_ptr;

	Tree_Node 	* GRAND_PARENT_PTR = PARENT_PTR->parent_ptr;

	Tree_Node * PARENT_OF_GRAND_PARENT_PTR =
					GRAND_PARENT_PTR -> parent_ptr;

	printf("To Balance:"); 
	pvi(node_ptr -> value);
	pvi( PARENT_PTR -> value);
	pvi( GRAND_PARENT_PTR -> value);


	if ( PARENT_PTR == GRAND_PARENT_PTR->left_child_ptr)
	{    
		//LY
		if ( node_ptr == PARENT_PTR->left_child_ptr)

		{ 
			XY = LL;
			printf("LL "); 	
		}
		else
		{
			XY = LR;
			printf("LR "); 	
		}	

		GRAND_PARENTS_ANOTHER_CHILD_COLOR =  
			GRAND_PARENT_PTR-> right_child_ptr     ?
			GRAND_PARENT_PTR-> right_child_ptr->rb : BLACK;

		printf("%s", COLOR(GRAND_PARENT_PTR-> right_child_ptr ) );

	}
	else
	{ 
		// RY 		
		if ( node_ptr == PARENT_PTR->left_child_ptr)
		{  
			XY = RL;
			printf("RL "); 					
		}
		else
		{ 
			XY = RR; 
			printf("RR "); 					
		}	

		GRAND_PARENTS_ANOTHER_CHILD_COLOR =  
			GRAND_PARENT_PTR-> left_child_ptr     ?
			GRAND_PARENT_PTR-> left_child_ptr->rb : BLACK;

		printf("%s", COLOR(GRAND_PARENT_PTR-> left_child_ptr) );

	}
	printf("\n"); 


	if ( GRAND_PARENTS_ANOTHER_CHILD_COLOR == RED ) 
	{

		XY_RED_correction(node_ptr, XY,root_d_ptr);

		if( PARENT_OF_GRAND_PARENT_PTR) 
			if ( PARENT_OF_GRAND_PARENT_PTR->rb == RED ) 
				balance(GRAND_PARENT_PTR, root_d_ptr);
	}
	else
		XY_BLACK_correction(node_ptr, XY, root_d_ptr);

	printf("Completed Balance:"); 
	pvi(node_ptr -> value);
	printf("-----------------------------------------------------------\n"); 
}

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
		new_node_ptr->rb    = BLACK;
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

	if ( new_node_ptr->parent_ptr-> rb == RED )
	{ 
		balance(new_node_ptr,root_d_ptr );
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


int inorder_traverse(Tree_Node * ptr)
{
	if ( !ptr ) return 0;

	inorder_traverse(ptr->left_child_ptr);
	printf("%d", ptr->value);

	printf("\tColor=%s\t", COLOR(ptr)); 

	if( ptr->parent_ptr)
		printf("%d", ptr->parent_ptr->value);
	else
		printf("Parent Ptr is NULL"); 

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

	printf("root node is %d\n", root_ptr->value); 
	return 0;
}

