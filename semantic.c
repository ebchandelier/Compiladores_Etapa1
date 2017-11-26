#include <stdio.h>
#include <stdlib.h>

#include "semantic.h"
#include"y.tab.h"

int errCount = 0;
//int currentReturnExpected;
HashEntry* currentFuntion;

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
                    errCount++;
                    
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

                        //fprintf(stderr, "%d and %d\n",hashNode->dataType, litType);
                        fprintf(stderr, "ERRO Semantico, var: %s, tipos incompatíveis na declaração.\n", hashNode->key);
                        errCount++;
                    
                    }
                }
                break;  
            }
            case ASSIGNMENT_LIST: {

                HashEntry *hashNode = (node->son[0]->symbol);
                if(hashNode->defined == TRUE) {
                    fprintf(stderr, "ERRO semantico na declaracao de array Var '%s' ja declarada.\n", hashNode->key);
                    errCount++;
                    
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
                                errCount++;
                            }

                            literal_count++;
                            listNode = listNode->son[1]?listNode->son[1] : 0;
                        
                        }
                        //fprintf(stderr, "%d and %d\n",expected_literal_count, literal_count);
                        if(expected_literal_count != literal_count)
                        {
                            fprintf(stderr,"SEMANTIC ERROR: Wrong number of elements on array declaration: %s\n", hashNode->key);
                            errCount++;
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
                    errCount++;
                
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
                                    errCount++;
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
                                    errCount++;
                                }
                                parameters->son[0]->son[0]->symbol->defined = TRUE;
                                parameters->son[0]->son[0]->symbol->nature = NATURE_SCALAR;
                                break;
                            }
                        }

                        parameters = parameters->son[1]?parameters->son[1] : 0;
                    }
                }

                //TODO: verify return type, is that necessary?

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

int secondPass(AST *node) {
//pass to verify type and usage
    if(node == 0) {
        
		return NO_TYPE;
	
    } else {

		switch(node->type) {

            case AST_LIST:{
                
                secondPass(node->son[0]);
                secondPass(node->son[1]);
                break;
            }
            case AST_BYTE:      
            case AST_SHORT:     
            case AST_LONG: {
                return LIT_INTEGER;
                break;
            }
            case AST_FLOAT: 
            case AST_DOUBLE: {
                return LIT_REAL;
                break;
            }
            case LITERAL: {

                switch(node->symbol->value) {
                    case AST_BYTE:
                    case AST_SHORT:
                    case AST_LONG: {
                        return LIT_INTEGER;
                        break;  
                    } 
                    case AST_FLOAT:
                    case AST_DOUBLE: {
                        return LIT_REAL;
                        break;
                    }

                }
                break;
            }
            case AST_SYMBOL: {
                if(node->symbol->defined != TRUE) {
                    fprintf(stderr, "SEMANTIC ERROR, Var %s was not defined\n", node->symbol->key);
                    errCount++;
                    return NO_TYPE;
                }
                return node->symbol->dataType;
                break;
            }

            case AST_ADD:
            case AST_SUB:
            case AST_MUL:
            case AST_DIV:
            case AST_CHANGE_SIGN:
            case AST_LESS:      
            case AST_GREA:      
            case GE:       
            case LE:       
            case EQUAL:    
            case NOT_EQUAL:
            case OR:       
            case AND: {

                int f1 = secondPass(node->son[0]);
                int f2 = secondPass(node->son[1]);
                if(f1==NO_TYPE || f2 == NO_TYPE) return NO_TYPE;
                if(f1==LIT_CHAR || f1==LIT_STRING || f2==LIT_CHAR || f2==LIT_STRING) {
                    fprintf(stderr, "SEMANTIC ERROR, expression with wrong parameters\n");
                    errCount++;
                    return NO_TYPE;
                }
                if(f1==LIT_REAL || f2==LIT_REAL) {
                    return LIT_REAL;
                }return LIT_INTEGER;
            }      

            case FUNCTION: {
                //int currentReturnExpected = node->son[0]->son[1]->symbol->returnType; 
                currentFuntion = node->son[0]->son[1]->symbol;
                secondPass(node->son[1]);
                break;
            }      
            case FUNCTION_BODY: {
                return secondPass(node->son[0]);
                break;
            }     

            case AST_CMD_BLOCK: {
                return secondPass(node->son[0]);
                break;
            } 

            case AST_CMD_LIST: {
                int t0 = secondPass(node->son[0]);
                int t1 = secondPass(node->son[1]);

                break;
            }
            
            case RETURN_CMD: {
                int t0 = secondPass(node->son[0]);
                if(t0 != currentFuntion->returnType) {
                    fprintf(stderr, "SEMANTIC ERROR, not expected return of function %s\n", currentFuntion->key);
                     errCount++;
                }
                break;
            }    

            case PARENTESES: {
                return secondPass(node->son[0]);
                break;
            }   

            case AST_SYMBOL_ASSIGNMENT: {
                
                if(node->symbol->defined!=TRUE) {
                
                    fprintf(stderr, "SEMANTIC ERROR, variable not defined: %s\n", node->symbol->key);
                    errCount++;

                
                } else if(node->symbol->dataType != secondPass(node->son[0])) {
                    
                    fprintf(stderr, "SEMANTIC ERROR, wrong types on assignment of %s var\n", node->symbol->key);
                    errCount++;
                }
                break;
            } 

            case ASSIGNMENT_LIST_INDEX: {
                
                if(node->symbol->defined!=TRUE) {
                    fprintf(stderr, "SEMANTIC ERROR, Array was not declared :%s var\n", node->symbol->key);
                     errCount++;
                }
                
                int t0 = secondPass(node->son[0]);
                int t1 = secondPass(node->son[1]);

                if(t0 != LIT_INTEGER) {
                    fprintf(stderr, "SEMANTIC ERROR, Array index should be of type INTEGER at %s var\n", node->symbol->key);
                     errCount++;
                }
                if(t1 != node->symbol->dataType) {
                    fprintf(stderr, "SEMANTIC ERROR, Array assignment of diff types at %s var\n", node->symbol->key);
                     errCount++;
                }
                break;
            } 
            
            case PRINT_CMD: {
                secondPass(node->son[0]);
                break;
            }   
            
            case AST_SYMBOL_ARRAY: {
                if(node->symbol->defined!=TRUE) {
                    fprintf(stderr, "SEMANTIC ERROR, Array was not declared :%s var\n", node->symbol->key);
                     errCount++;
                }
                int t0 = secondPass(node->son[0]);
                if(t0 != LIT_INTEGER) {
                    fprintf(stderr, "SEMANTIC ERROR, Array index should be of type INTEGER at %s var\n", node->symbol->key);
                     errCount++;
                }

                return node->symbol->dataType;
                break;
            }  
            case PRINT_CONTENT: {

                int t0 = secondPass(node->son[0]);
                if(t0 != LIT_STRING) {

                    //fprintf(stderr, "SEMANTIC ERROR, Print list Items should be of type LIT_STRING\n");
                    //A LIT_STRING SÒ pode ser usada na print cmd, mas nao quer dizer que outras coisas n podem.
                }
                secondPass(node->son[1]);
                break;
            }
            case READ_CMD: {

                secondPass(node->son[0]);
                break;
            }     

            case WHILE_CMD: {
                secondPass(node->son[0]);
                secondPass(node->son[1]);
                break;
            }   

            case AST_FUN_CAL: {

                if(node->symbol->defined!=TRUE) {
                    fprintf(stderr, "SEMANTIC ERROR, Function was not declared :%s var\n", node->symbol->key);
                     errCount++;
                }

                AST *usageNode = node->son[0];

                AST *declarationNode = node->symbol->declarationNode;
                
                AST* parameters = declarationNode->son[0]->son[2];

                while(parameters != 0 && usageNode != 0) {

                    if( parameters->son[0]->son[0]->symbol->dataType != secondPass(usageNode->son[0])) {
                        fprintf(stderr, "SEMANTIC ERROR, Parameters of diff types at func %s\n", node->symbol->key);
                        errCount++;
                    }

                    usageNode = usageNode->son[1]?usageNode->son[1] :0;
                    parameters = parameters->son[1]?parameters->son[1] : 0;
                }
                
                if(parameters != 0 || usageNode != 0) {
                    fprintf(stderr, "SEMANTIC ERROR, Wrong number of parameters at func %s\n", node->symbol->key);
                     errCount++;
                }

                return node->symbol->returnType;
                break;
            }  

            case IF_THEN_ELSE_CMD:{
                secondPass(node->son[0]);
                secondPass(node->son[1]);
                secondPass(node->son[2]);
                break;
            } 

            case ELSE_CMD: {
                secondPass(node->son[0]);
                break;
            }  

            case AST_AT_ARRAY: {
                return secondPass(node->son[0]);
                break;
            } 
        }
    }
}