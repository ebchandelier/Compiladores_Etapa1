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
