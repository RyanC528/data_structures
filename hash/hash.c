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
    table->items = calloc((size_t)table->size,sizeof(hash_item*));

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

static int hash(const char* s, const int a, const int m){
    long hash = 0;
    const int len_s = strlen(s);
    for(int i = 0; i < len_s; i++){
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash - hash % m;
    }

    return(int)hash;
}

static int get_hash(const char* s, const int num_buckets, const int attempt, int in_1, int in_2){
    const int hash_a = hash(s, in_2,num_buckets);
    const int hash_b = hash(s, in_1, num_buckets);
    return( hash_a + (attempt * (hash_b + 1))) % num_buckets; 
}

void hash_insert(hash_table* table, const char* key, const char* value){
    hash_item* item = new_hash_item(key, value);
    int index = hash(item->key, table->size, 0);
    hash_item* cur_item = table->items[index];
    int i = 1;
    while(cur_item != NULL){
        index = hash(item->key, table->size, i);
        cur_item = table->items[index];
        i++;
    }
    table->items[index] = item;
    table->count++;
}

char* hash_search(hash_table* table, const char* key){
    int index = hash(key, table->size, 0);
    hash_item* item = table->items[index];
    int i = 1;
    while(item != NULL){
        if (strcmp(item->key, key) == 0){
            return item->value;
        }
        index = hash(key, table->size, i);
        item = table->items[index];
        i++;
    }
    return NULL;
}

static hash_item DELETED_HASH = {NULL, NULL};

void hash_delete(hash_table* table, const char* key){
    int index = hash(key, table->size, 0);
    hash_item* item = table->items[index];
    int i = 1;
    while (item != NULL){
        if(item != &DELETED_HASH){
            if (strcmp(item->key, key) == 0){
                destroy_item(item);
                table->items[index = &DELETED_HASH];
            }
        }
        index = hash(key, table->size, i);
        item = table ->items[index];
        i++;
    }
    table->count--;
}

void hash_insert(hash_table * table, const char* key, const char* value){

    while(cur_item != NULL){
        if(cur_item != &DELETED_HASH){
            if(strcmp(cur_item->key, key) == 0){
                hash_delete(cur_item):
                table->items[index] = item;
                return;
            }
        }

    }

}

char* hash_search(hash_table* table, const char* key){

    while(table->items != NULL){
        if (table->items != &DELETED_HASH){
            if (strcmp(item-> key, key) == 0){
                return item->value;
            }
        }

    }
}