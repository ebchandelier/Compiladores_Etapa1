#include <stdio.h>
#include <stdlib.h>

#include "semantic.h"

void firstPass(AST *node) {
    //verify declarations os variables, lists and functions,
    //set if var/func was defined,
    //point the hash node to the declaration ast node
    //set nature: scalar,vector, function

    if(node == 0) {

        return;
    
    } else {

        switch(node->type) {

            case ASSIGNMENT: {
                
                HashEntry *hashNode = (node->son[0]->symbol);
                if(hashNode->defined == TRUE) {
                    fprintf(stderr, "ERRO semantico, Variável '%s' ja declarada.\n", hashNode->key);
                    
                } else {

                    //fprintf(stderr, "Variável '%s' declarada.\n", hashNode->key);
                    hashNode->defined=TRUE;
                    hashNode->declarationNode = node;
                    hashNode->nature = NATURE_SCALAR;

                    switch(node->son[1]->type) {

                        case AST_BYTE:
                        case AST_SHORT:
                        case AST_LONG: {
                           
                            hashNode->dataType = DATA_TYPE_INTEGER;
                            break;  
                        } 
                        case AST_FLOAT:
                        case AST_DOUBLE: {

                            hashNode->dataType = DATA_TYPE_REAL;
                            break;
                        }
                    }

                    HashEntry *hashNodeRightSide = node->son[2]->symbol;//right side of the operation
                    if( hashNode->value != hashNodeRightSide->dataType ) {

                        fprintf(stderr, "%d and %d\n",hashNode->value, hashNodeRightSide->value);
                        fprintf(stderr, "ERRO Semantico, tipos incompatíveis na declaração.\n");
                    } else {

                        fprintf(stderr, "Tudo certo com os tipos.\n");
                    }
                }
                break;  
            }
            case ASSIGNMENT_LIST: {

                break;
            }
            case FUNCTION: {

                break;
            }
            default: {

                firstPass(node->son[3]);
  				firstPass(node->son[2]);
  				firstPass(node->son[1]);
  				firstPass(node->son[0]);

                  break;
            }
        }
    }
}