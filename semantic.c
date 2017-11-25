#include <stdio.h>
#include <stdlib.h>

#include "semantic.h"
#include"y.tab.h"

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
                    fprintf(stderr, "ERRO semantico na declaração de var, Variável '%s' ja declarada.\n", hashNode->key);
                    
                } else {

                    //fprintf(stderr, "Variável '%s' declarada.\n", hashNode->key);
                    hashNode->defined=TRUE;
                    hashNode->declarationNode = node;
                    hashNode->nature = NATURE_SCALAR;

                    switch(node->son[1]->type) {

                        case AST_BYTE:
                        case AST_SHORT:
                        case AST_LONG: {
                           
                            hashNode->dataType = LIT_INTEGER;
                            break;  
                        } 
                        case AST_FLOAT:
                        case AST_DOUBLE: {

                            hashNode->dataType = LIT_REAL;
                            break;
                        }
                    }

                    HashEntry *hashNodeRightSide = node->son[2]->symbol;//right side of the operation
                    
                    int litType = hashNodeRightSide->value; 
                    if(litType == LIT_CHAR) {

                        litType = LIT_INTEGER;
                    }

                    if( hashNode->dataType != litType ) {

                        fprintf(stderr, "%d and %d\n",hashNode->dataType, litType);
                        fprintf(stderr, "ERRO Semantico, var: %s, tipos incompatíveis na declaração.\n", hashNode->key);
                    
                    }
                }
                break;  
            }
            case ASSIGNMENT_LIST: {

                HashEntry *hashNode = (node->son[0]->symbol);
                if(hashNode->defined == TRUE) {
                    fprintf(stderr, "ERRO semantico na declaracao de array Var '%s' ja declarada.\n", hashNode->key);
                    
                } else {

                    hashNode->defined=TRUE;
                    hashNode->declarationNode = node;
                    hashNode->nature = NATURE_VECTOR;

                    switch(node->son[1]->type) {

                        case AST_BYTE:
                        case AST_SHORT:
                        case AST_LONG: {
                           
                            hashNode->dataType = LIT_INTEGER;
                            break;  
                        } 
                        case AST_FLOAT:
                        case AST_DOUBLE: {

                            hashNode->dataType = LIT_REAL;
                            break;
                        }
                    }

                    AST *listNode = node->son[3];

                    if(listNode != 0) {

                        //listNode = listNode->son[1];
                        int expected_literal_count = atoi(node->son[2]->symbol->key);//okay because it is a LIT_INTEGER
                        int literal_count = 0;
                        
                        //fprintf(stderr,"LIT_INTEGER: %d\n", atoi(node->son[2]->symbol->key));

                        while(listNode !=0) {
                        
                            //fprintf(stderr, "%s\n", listNode->son[0]->symbol->key);
                            AST* literals;

                            literals = listNode->son[0];

                            HashEntry* literal_vector = literals->symbol;

                            int literal_vector_type = literal_vector->value;

                            if(literal_vector_type == LIT_CHAR) {

                                literal_vector_type = LIT_INTEGER;
                            }

                            if(literal_vector_type != hashNode->dataType) {

                                fprintf(stderr,"SEMANTIC ERROR: Wrong type on at least one element of the array: %s\n", hashNode->key);
                            }

                            literal_count++;
                            listNode = listNode->son[1]?listNode->son[1] : 0;
                        
                        }
                        //fprintf(stderr, "%d and %d\n",expected_literal_count, literal_count);
                        if(expected_literal_count != literal_count)
                        {
                            fprintf(stderr,"SEMANTIC ERROR: Wrong number of elements on array declaration: %s\n", hashNode->key);
                        }

                    }

                }
              
                break;
            }
            case FUNCTION: {

                AST* function = node->son[0]->son[1];

                if(function->symbol->defined == TRUE)
                {
                    fprintf(stderr,"SEMANTIC ERROR: Function %s is already defined\n", function->symbol->key);
                
                } else {

                    function->symbol->defined=TRUE;
                    function->symbol->declarationNode = node;
                    function->symbol->nature = NATURE_FUNCTION;
                    function->symbol->dataType = DATA_TYPE_FUNCTION;

                    AST* returnType = node->son[0]->son[0];

                    switch(returnType->type) {

                        case AST_BYTE:
                        case AST_SHORT:
                        case AST_LONG: {
                            function->symbol->returnType = LIT_INTEGER;
                            break;  
                        } 
                        case AST_FLOAT:
                        case AST_DOUBLE: {
                            function->symbol->returnType = LIT_REAL;
                            break;
                        }
                    }

                    AST* parameters = node->son[0]->son[2];

                    while(parameters != 0) {

                        //fprintf(stderr, "parameter> %s\n", parameters->son[0]->son[0]->symbol->key);

                        switch(parameters->son[0]->son[1]->type) {

                            case AST_BYTE:
                            case AST_SHORT:
                            case AST_LONG: {
                                parameters->son[0]->son[0]->symbol->dataType = LIT_INTEGER;
                                if(parameters->son[0]->son[0]->symbol->defined==TRUE) {
                                    fprintf(stderr,"SEMANTIC ERROR: Var inside func %s is already defined\n", function->symbol->key);
                                }
                                parameters->son[0]->son[0]->symbol->defined = TRUE;
                                parameters->son[0]->son[0]->symbol->nature = NATURE_SCALAR;
                                break;  
                            } 
                            case AST_FLOAT:
                            case AST_DOUBLE: {
                                parameters->son[0]->son[0]->symbol->dataType = LIT_REAL;
                                if(parameters->son[0]->son[0]->symbol->defined==TRUE) {
                                    fprintf(stderr,"SEMANTIC ERROR: Var inside func %s is already defined\n", function->symbol->key);
                                }
                                parameters->son[0]->son[0]->symbol->defined = TRUE;
                                parameters->son[0]->son[0]->symbol->nature = NATURE_SCALAR;
                                break;
                            }
                        }

                        parameters = parameters->son[1]?parameters->son[1] : 0;
                    }
                }

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
