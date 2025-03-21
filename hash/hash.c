#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

static hash_item* new_hash_item(const char* key, const char* value){
    hash_item* item = malloc(sizeof(hash_item));
    item->key = strdup(key);
    item->value = strdup(value);

    return item;
}

hash_table* new_hash_table(){
    hash_table* table = malloc(sizeof(hash_table));

    table->size = 53;
    table->count= 0;
    table->items = calloc((size_t)hash_table->size,sizeof(hash_item*));

    return table;
}

static void destroy_item(hash_item* item){
    free(item->key);
    free(item->value);
    free(item);

    return;
}

void destroy_table(hash_table* table){
    for(int i = 0; i <table->size; i++){
        hash_item* item = table->items[i];
        if(item != NULL){
            delete_item(item);
        }
    }
    free(table->items);
    free(table);

    return;
}

int main(void){

    return 1;
}