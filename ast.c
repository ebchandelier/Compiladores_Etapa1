#include "ast.h"

AST* astCreate(int type, HashEntry* symbol, AST* son1, AST* son2, AST* son3, AST* son4) {

    fprintf(stderr, "CREATING AST NODE\n");
    AST* newNode = (AST*)calloc(1, sizeof(AST));
    newNode->type = type;
    newNode->symbol = symbol;
    newNode->son[0] = son1;
    newNode->son[1] = son2;
    newNode->son[2] = son3;
    newNode->son[3] = son4;

    return newNode;
}

char* toOutput(AST* node) {

    if(node == 0) {

		return "";
    
    } else {

        switch(node->type) {

            case AST_SYMBOL:    {
                
                fprintf(stderr, "AST_SYMBOL\n");                
                
                char* buffer = (char*)calloc(strlen(node->symbol->key)+1, sizeof(char));
                sprintf(buffer, "%s", node->symbol->key);
                return buffer;
            }

            case AST_SYMBOL_ARRAY: {

                fprintf(stderr, "AST_SYMBOL_ARRAY\n");

                char* bufferA = toOutput(node->son[0]);
                
                char* buffer = (char*)calloc(1 + strlen(bufferA) + strlen(node->symbol->key), sizeof(char));
                sprintf(buffer, "%s%s", node->symbol->key, bufferA);

                return buffer;
            }

            case AST_ADD:   {

                fprintf(stderr, "ADD\n");

                char* bufferA = toOutput(node->son[0]);
                char* bufferB = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(4 + strlen(bufferA) + strlen(bufferB), sizeof(char));
                sprintf(buffer, "%s + %s", bufferA, bufferB);

                return buffer;

            }       
            case AST_MUL:   {

                fprintf(stderr, "MUL");

                char* bufferA = toOutput(node->son[0]);
                char* bufferB = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(4 + strlen(bufferA) + strlen(bufferB), sizeof(char));
                sprintf(buffer, "%s * %s", bufferA, bufferB);

                return buffer;
            }       
            case AST_CHANGE_SIGN:   {

                fprintf(stderr, "CHANGE_SIGN"); 
		
                char* bufferA = toOutput(node->son[0]);
							
                char* buffer = (char*)calloc(2 + strlen(bufferA), sizeof(char));
                sprintf(buffer, "-%s", bufferA);



                return buffer;
            }   
            case AST_LIST:  {
            
                fprintf(stderr, "LIST\n"); 
                
                char* bufferA = toOutput(node->son[0]);
                char* bufferB = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(2 + strlen(bufferA) + strlen(bufferB), sizeof(char));
                sprintf(buffer, "%s\n%s", bufferA, bufferB);

                return buffer;
            }
            
            case ASSIGNMENT:    {
                fprintf(stderr, "ASSIGNMENT\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer3 = toOutput(node->son[2]);

                char* buffer = (char*)calloc(9 + strlen(buffer1) + strlen(buffer2) + strlen(buffer3), sizeof(char));
				sprintf(buffer,"%s : %s = %s ;",buffer1, buffer2, buffer3);

                return buffer;

            }
            case AST_BYTE:  return "byte";
            case AST_SHORT: return "short";
            case AST_LONG:  return "long";
            case AST_FLOAT: return "float";
            case AST_DOUBLE:    return "double";
            case LITERAL: {

                char* buffer = (char*)calloc(strlen(node->symbol->key)+1, sizeof(char));
                sprintf(buffer, "%s", node->symbol->key);
                return buffer;
            }
            // case TOKEN:         fprintf(stderr, "TOKEN"); break;
            case ASSIGNMENT_LIST:  {

                fprintf(stderr, "ASSIGNMENT_LIST"); 

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer3 = toOutput(node->son[2]);
                char* buffer4 = toOutput(node->son[3]);

                char* buffer = (char*)calloc(7 + strlen(buffer1) + strlen(buffer2) + strlen(buffer3) + strlen(buffer4), sizeof(char));
				sprintf(buffer,"%s : %s[%s] %s;",buffer1, buffer2, buffer3, buffer4);

                return buffer;

            } 
            case VALUE_LIST:    {

                fprintf(stderr, "VALUE_LIST"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer;

                if(node->son[1] != 0) {
                    
                    buffer = (char*)calloc(2 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                    sprintf(buffer,"%s %s",buffer1, buffer2);

                } else {

                    buffer = (char*)calloc(strlen(buffer1)+1, sizeof(char));
                    sprintf(buffer,"%s",buffer1);
                }
                
                return buffer;

            }   
            case FUNCTION:  {

                fprintf(stderr, "FUNCTION\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);

                char* buffer = (char*)calloc(2 + strlen(buffer1) + strlen(buffer2), sizeof(char));
				sprintf(buffer,"%s\n%s",buffer1, buffer2);

                return buffer;

            }   
            case FUNCTION_HEADER:   {

                fprintf(stderr, "FUNCTION_HEADER\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer3 = toOutput(node->son[2]);
                
                char* buffer = (char*)calloc(11 + strlen(buffer1) + strlen(buffer2) + strlen(buffer3), sizeof(char));
				sprintf(buffer,"( %s ) %s ( %s )",buffer1, buffer2, buffer3);

                return buffer;
            }   
            case ARG_LIST:  {

                fprintf(stderr, "ARG_LIST\n");
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer;

                if(node->son[1]) {

                    buffer = (char*)calloc(3 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                    sprintf(buffer,"%s, %s",buffer1, buffer2);

                } else {

                    buffer = (char*)calloc(strlen(buffer1)+1, sizeof(char));
                    sprintf(buffer,"%s",buffer1);
                }
                
                return buffer;
            }      
            case ARGUMENT:  {

                fprintf(stderr, "ARGUMENT\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(4 + strlen(buffer1) + strlen(buffer2), sizeof(char));
				sprintf(buffer,"%s : %s",buffer1, buffer2);

                return buffer;

            }      
            case FUNCTION_BODY: {

                fprintf(stderr, "FUNCTION_BODY\n");

                char* buffer1 = toOutput(node->son[0]);
                
                char* buffer = (char*)calloc(strlen(buffer1)+1, sizeof(char));
                
                sprintf(buffer,"%s",buffer1);

                return buffer;
            }     
            case ASSIGNMENT_LIST_INDEX: {

                fprintf(stderr, "ASSIGNMENT_LIST_INDEX\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);

                char* buffer = (char*)calloc(9 + strlen(buffer1) + strlen(buffer2) + strlen(node->symbol->key), sizeof(char));
                
                sprintf(buffer,"%s [ %s ] = %s",node->symbol->key, buffer1, buffer2);

                return buffer;
            } 
            case READ_CMD:  {

                fprintf(stderr, "READ_CMD\n");

                char* buffer1 = toOutput(node->son[0]);
                
                char* buffer = (char*)calloc(8 + strlen(buffer1), sizeof(char));
                                
                sprintf(buffer,"read > %s", buffer1);
                
                return buffer;
            }      
            case PRINT_CMD: {

                fprintf(stderr, "PRINT_CMD\n");

                char* buffer1 = toOutput(node->son[0]);

                char* buffer = (char*)calloc(7 + strlen(buffer1), sizeof(char));
                
                sprintf(buffer,"print %s", buffer1);

                return buffer;

            }     
            case RETURN_CMD:    {

                fprintf(stderr, "RETURN_CMD\n");

                char* buffer1 = toOutput(node->son[0]);
                
                char* buffer = (char*)calloc(8 + strlen(buffer1), sizeof(char));
                
                sprintf(buffer,"return %s",buffer1);

                return buffer;
            }    
            case IF_THEN_ELSE_CMD:  {

                fprintf(stderr, "IF_THEN_ELSE_CMD\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer3 = toOutput(node->son[2]);
                
                char* buffer = (char*)calloc(15 + strlen(buffer1) + strlen(buffer2) + strlen(buffer3), sizeof(char));
                
                sprintf(buffer,"if ( %s ) then %s %s",buffer1, buffer2, buffer3);

                return buffer;
            } 
            case ELSE_CMD:  {

                fprintf(stderr, "ELSE_CMD\n");

                char* buffer1 = toOutput(node->son[0]);
                
                char* buffer = (char*)calloc(6 + strlen(buffer1), sizeof(char));
                
                sprintf(buffer,"else %s",buffer1);

                return buffer;
            }

            case WHILE_CMD: {

                fprintf(stderr, "WHILE_CMD\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);

                char* buffer = (char*)calloc(9 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                
                sprintf(buffer,"while(%s) %s", buffer1, buffer2);

                return buffer;

            }     
            case PRINT_CONTENT: {

                fprintf(stderr, "PRINT_CONTENT\n");


                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer;

                if(node->son[1] != 0) {

                    buffer = (char*)calloc(3 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                    sprintf(buffer,"%s, %s",buffer1, buffer2);

                } else {

                    buffer = (char*)calloc(1 + strlen(buffer1), sizeof(char));
                    sprintf(buffer,"%s",buffer1);
                } 
                
                return buffer;

            } 
            case AST_CMD_BLOCK: {

                fprintf(stderr, "AST_CMD_BLOCK\n");

                char* buffer1 = toOutput(node->son[0]);
                                
                char* buffer = (char*)calloc(5 + strlen(buffer1), sizeof(char));
                                
                sprintf(buffer,"{ %s }",buffer1);
                
                return buffer;
            } 
            case AST_CMD_LIST:  {
                
                fprintf(stderr, "AST_CMD_LIST\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer;

                if(node->son[1] != 0) {

                    buffer = (char*)calloc(5 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                    sprintf(buffer,"%s ;\n %s",buffer1, buffer2);

                } else {

                    buffer = (char*)calloc(2 + strlen(buffer1), sizeof(char));
                    sprintf(buffer,"%s\n",buffer1);
                } 
                
                return buffer;
            }
            case AST_FUN_CAL:   {

                fprintf(stderr, "AST_FUN_CAL\n");

                char* buffer1 = toOutput(node->son[0]);
                
                char* buffer = (char*)calloc(6 + strlen(buffer1) + strlen(node->symbol->key), sizeof(char));
                
                sprintf(buffer,"%s ( %s )",node->symbol->key, buffer1);

                return buffer;
            }   
            case AST_AT_ARRAY: {
                
                fprintf(stderr, "AST_AT_ARRAY\n");

                char* buffer1 = toOutput(node->son[0]);
                
                char* buffer = (char*)calloc(5 + strlen(buffer1), sizeof(char));
                
                sprintf(buffer,"[ %s ]",buffer1);

                return buffer;
            }
            case AST_SYMBOL_ASSIGNMENT: {

                fprintf(stderr, "AST_SYMBOL_ASSIGNMENT\n");

                char* buffer1 = toOutput(node->son[0]);
                                
                char* buffer = (char*)calloc(4 + strlen(buffer1) + strlen(node->symbol->key), sizeof(char));
                                
                sprintf(buffer,"%s = %s",node->symbol->key, buffer1);
                
                return buffer;
            } 
            case AST_SUB:   {

                fprintf(stderr, "AST_SUB\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);

                char* buffer = (char*)calloc(2 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                
                sprintf(buffer,"%s-%s", buffer1, buffer2);

                return buffer;
            }       
            case AST_DIV:    {
                
                fprintf(stderr, "DIV\n"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(4 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                                
                sprintf(buffer,"%s / %s", buffer1, buffer2);
                
                return buffer;
            }     
            case AST_LESS:  {

                fprintf(stderr, "AST_LESS\n"); 

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);

                char* buffer = (char*)calloc(4 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                
                sprintf(buffer,"%s < %s", buffer1, buffer2);

                return buffer;
            }     
            case AST_GREA:  {
                
                fprintf(stderr, "AST_GREA\n"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(4 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                                
                sprintf(buffer,"%s > %s", buffer1, buffer2);
                
                return buffer;
            }     
            case AST_PARAM_LIST:    {

                fprintf(stderr, "AST_PARAM_LIST\n");

                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                char* buffer;

                if(node->son[1] != 0) {

                    buffer = (char*)calloc(3 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                    sprintf(buffer,"%s, %s",buffer1, buffer2);

                } else {

                    buffer = (char*)calloc(strlen(buffer1)+2, sizeof(char));
                    sprintf(buffer,"%s\n",buffer1);
                } 
                
                return buffer;

            }    
            case GE:    {
                
                fprintf(stderr, "GE\n"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(5 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                                
                sprintf(buffer,"%s >= %s", buffer1, buffer2);
                
                return buffer;
            }     
            case LE:    {
                
                fprintf(stderr, "LE\n"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(5 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                                
                sprintf(buffer,"%s <= %s", buffer1, buffer2);
                
                return buffer;
            }     
            case EQUAL:  {
                
                fprintf(stderr, "EQUAL\n"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(5 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                                
                sprintf(buffer,"%s == %s", buffer1, buffer2);
                
                return buffer;
            }     
            case NOT_EQUAL:  {
                
                fprintf(stderr, "NOT_EQUAL\n"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(5 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                                
                sprintf(buffer,"%s != %s", buffer1, buffer2);
                
                return buffer;
            }     
            case OR:     {
                
                fprintf(stderr, "OR\n"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(5 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                                
                sprintf(buffer,"%s || %s", buffer1, buffer2);
                
                return buffer;
            }     
            case AND:    {
                
                fprintf(stderr, "AND\n"); 
                
                char* buffer1 = toOutput(node->son[0]);
                char* buffer2 = toOutput(node->son[1]);
                
                char* buffer = (char*)calloc(5 + strlen(buffer1) + strlen(buffer2), sizeof(char));
                                
                sprintf(buffer,"%s && %s", buffer1, buffer2);
                
                return buffer;
            }     
            case PARENTESES:    {

                char* buffer1 = toOutput(node->son[0]);
                
                char* buffer = (char*)calloc(5 + strlen(buffer1), sizeof(char));
				sprintf(buffer,"( %s )",buffer1);

                return buffer;
            }

            default:       fprintf(stderr, "NAO ACHOU...\n"); return "";
        }

    }
}

void astPrint(AST* node, int level) {

    if(node) {



        int i;
        for(i=0; i<level; ++i) {

            fprintf(stderr, " | ");
        }

        //fprintf(stderr, "AST( ");

        switch(node->type) {

            case AST_SYMBOL:    fprintf(stderr, "SYMBOL"); break;
            case AST_ADD:       fprintf(stderr, "ADD"); break;
            case AST_MUL:       fprintf(stderr, "MUL"); break;
            case AST_CHANGE_SIGN:    fprintf(stderr, "CHANGE_SIGN"); break;
            case AST_LIST:       fprintf(stderr, "LIST"); break;
            case ASSIGNMENT:     fprintf(stderr, "ASSIGNMENT"); break;
            case AST_BYTE:      fprintf(stderr, "BYTE"); break;
            case AST_SHORT:     fprintf(stderr, "SHORT"); break;
            case AST_LONG:      fprintf(stderr, "LONG"); break;
            case AST_FLOAT:     fprintf(stderr, "FLOAT"); break;
            case AST_DOUBLE:    fprintf(stderr, "DOUBLE"); break;
            case LITERAL:       fprintf(stderr, "LITERAL"); break;
            case TOKEN:         fprintf(stderr, "TOKEN"); break;
            case ASSIGNMENT_LIST:   fprintf(stderr, "ASSIGNMENT_LIST"); break;
            case VALUE_LIST:         fprintf(stderr, "VALUE_LIST"); break;
            case FUNCTION:      fprintf(stderr, "FUNCTION"); break;
            case FUNCTION_HEADER:   fprintf(stderr, "FUNCTION_HEADER"); break;
            case ARG_LIST:      fprintf(stderr, "ARG_LIST"); break;
            case ARGUMENT:      fprintf(stderr, "ARGUMENT"); break;
            case FUNCTION_BODY:     fprintf(stderr, "FUNCTION_BODY"); break;
            case ASSIGNMENT_LIST_INDEX: fprintf(stderr, "ASSIGNMENT_LIST_INDEX"); break;
            case READ_CMD:      fprintf(stderr, "READ_CMD"); break;
            case PRINT_CMD:     fprintf(stderr, "PRINT_CMD"); break;
            case RETURN_CMD:    fprintf(stderr, "RETURN_CMD"); break;
            case IF_THEN_ELSE_CMD: fprintf(stderr, "IF_THEN_ELSE_CMD"); break;
            case WHILE_CMD:     fprintf(stderr, "WHILE_CMD"); break;
            case PRINT_CONTENT: fprintf(stderr, "PRINT_CONTENT"); break;
            case AST_CMD_BLOCK: fprintf(stderr, "AST_CMD_BLOCK"); break;
            case AST_CMD_LIST:  fprintf(stderr, "AST_CMD_LIST"); break;
            case AST_FUN_CAL:   fprintf(stderr, "AST_FUN_CAL"); break;
            case AST_AT_ARRAY: fprintf(stderr, "AST_AT_ARRAY"); break;
            case AST_SYMBOL_ASSIGNMENT: fprintf(stderr, "AST_SYMBOL_ASSIGNMENT"); break;
            case AST_SUB:       fprintf(stderr, "AST_SUB"); break;
            case AST_DIV:       fprintf(stderr, "AST_DIV"); break;
            case AST_LESS:      fprintf(stderr, "AST_LESS"); break;
            case AST_GREA:      fprintf(stderr, "AST_GREA"); break;
            case AST_PARAM_LIST:    fprintf(stderr, "AST_PARAM_LIST"); break;
            case GE:        fprintf(stderr, "GE"); break;
            case LE:        fprintf(stderr, "LE"); break;
            case EQUAL:        fprintf(stderr, "EQUAL"); break;
            case NOT_EQUAL:        fprintf(stderr, "NOT_EQUAL"); break;
            case OR:        fprintf(stderr, "OR"); break;
            case AND:        fprintf(stderr, "AND"); break;
            case PARENTESES:    fprintf(stderr, "PARENTESES"); break;
            case AST_SYMBOL_ARRAY:  fprintf(stderr, "AST_SYMBOL_ARRAY"); break;
            case ELSE_CMD:      fprintf(stderr, "ELSE_CMD");
            

            default:       fprintf(stderr, "UNKNOWN");
        }

        if(node->symbol) {

            fprintf(stderr, "%s\n", node->symbol->key);

        } else {

            fprintf(stderr, "\n");
        }

        for(i=0; i < 4; ++i) {

            if(node->son[i] != 0) {

                astPrint(node->son[i], level+1);
            }
        }
    
    } else {

        fprintf(stderr, "AST VAZIA\n");
    }
}
