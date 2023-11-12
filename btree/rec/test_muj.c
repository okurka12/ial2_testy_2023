#include <stdio.h>
#include <assert.h>
#include "../btree.h"
#include "../test_util.h"

/* comment this out if you wantn't logging */
// #define LOGGING

#ifdef LOGGING
#include <stdio.h> // logging

/* logs plain string (like puts) or does nothing if LOGGING is not defined */
#define log(msg) fprintf(stdout, __FILE__ ":%03d (%s): %s\n", __LINE__, \
__func__, (msg)); fflush(stdout)

/* logs format (like printf) or does nothing if LOGGING is not defined */
#define logf(msg, ...) fprintf(stdout, __FILE__ ":%03d (%s): " msg "\n", \
__LINE__, __func__, __VA_ARGS__); fflush(stdout)

#else

#define log(msg) {}
#define logf(msg, ...) {}

#endif  // ifdef LOGGING

/* deklaruje promenne `found` (bool) a `current_value` (int) */
#define boilerplate \
    bool found = false; \
    int current_value

/* udela for loop unsigned int `i` pres pocet prvku `ltrs` */
#define for_loop for (unsigned int i = 0; i < ltrs_count; i++)

const unsigned int ltrs_start = __LINE__; const char ltrs[] = {'K',
    'Y',
    'r',
    'T',
    'J',
    'G',
    'a',
    'e',
    'M',
    'P',
    'A',
    'S',
    'q',
    'd',
    'g',
    'V',
    'm',
    'c',
    'v',
    'p',
    'Z',
    'U',
    'Q',
    'O',
    'R',
    'E',
    'X',
    'L',
    'h',
    'w',
    'j',
    'D',
    'b',
    'F',
    'f',
    'z',
    'x',
    'C',
    'n',
    'H',
    'u',
    's',
    'k',
    'I',
    'y',
    'W',
    'N',
    'o',
    'l',
    'B',
    'i',
    't',
}; const unsigned int ltrs_count = __LINE__ - ltrs_start; 

void add_bunch(bst_node_t **tree) {

    boilerplate;

    for_loop {

        /* zanda tam uzel s pismenkem */
        bst_insert(tree, ltrs[i], i);

        /* zkontroluje ze prvek jde najit a ma spravnou hodnotu */
        found = bst_search(*tree, ltrs[i], &current_value);
        assert(found);
        assert(current_value == i);

        /* zmeni hodnotu prvku s pismenkem */
        bst_insert(tree, ltrs[i], ltrs_count - i);
        found = bst_search(*tree, ltrs[i], &current_value);
        assert(found);
        assert(current_value == ltrs_count - i);
    }

    /* jeste jednou prohledat kdyz je vse vlozene */
    for_loop {

        found = bst_search(*tree, ltrs[i], &current_value);
        assert(found);
        assert(current_value == ltrs_count - i);
    }
}

bool should_del(unsigned int i) {
    return (i > ltrs_count/4 && i < (3 * ltrs_count)/4);
}

/* smaze polovinu prvku z prostredku pole ltrs */
void delete_half(bst_node_t **tree) {

    boilerplate;

    for_loop {

        /* jestli se nachazime v casti kterou chceme smazat */
        if (should_del(i)) {

            logf("eyo eyo mazu %c", ltrs[i]);

            /* smazat */
            bst_delete(tree, ltrs[i]);
            bst_delete(tree, ltrs[i]);
            bst_delete(tree, ltrs[i]);
            bst_delete(tree, ltrs[i]);
            
            /* ujistit se ze to tam nelze najit */
            found = bst_search(*tree, ltrs[i], &current_value);
            assert(!found);
        }
    }


}

/* checks tree state after `delete_half` */
void check_after_deletion(bst_node_t **tree) {

    boilerplate;

    for_loop {

        /* jestli se nachazime mimo cast kterou chceme smazat */
        if (!should_del(i)) {
            found = bst_search(*tree, ltrs[i], &current_value);
            assert(found);
            assert(current_value == ltrs_count - i);
        
        } else {
            found = bst_search(*tree, ltrs[i], &current_value);
            assert(!found);
        }
    }
}

/* deletes all nodes one by one */
void delete_all(bst_node_t **tree) {

    boilerplate;

    for_loop {
        // logf("\n---pred smazanim %c---", ltrs[i]);
        // bst_print_tree(*tree);
        // fflush(stdout);
        bst_delete(tree, ltrs[i]);
        // logf("\n---po smazani %c---", ltrs[i]);
        // bst_print_tree(*tree);
        // fflush(stdout);
        found = bst_search(*tree, ltrs[i], &current_value);
        assert(!found);
    }
}

void check_empty(bst_node_t **tree) {

    boilerplate;

    for_loop {
        found = bst_search(*tree, ltrs[i], &current_value);
        assert(!found);
    }
}

void test_1() {
    bst_node_t *tree;
    bst_init(&tree);
    assert(tree == NULL);
    add_bunch(&tree);

    add_bunch(&tree);
    bst_print_tree(tree);

    delete_half(&tree);
    printf("---------------------------------------------------------------\n");
    printf("after deleting half\n");
    bst_print_tree(tree);

    bst_dispose(&tree);
    check_empty(&tree);
    assert(tree == NULL);
}

void test_2() {
    bst_node_t *tree;

    bst_init(&tree);
    assert(tree == NULL);
    add_bunch(&tree);
    delete_all(&tree);
    log("vse smazano");
    bst_print_tree(tree);
    check_empty(&tree);
    assert(tree == NULL);

}

/* vlozi 3 pismenka */
void test_3() {
    bst_node_t *tree;

    bst_init(&tree);


    bst_insert(&tree, 'b', 2);
    bst_insert(&tree, 'a', 1);
    bst_insert(&tree, 'c', 3);

    bst_delete(&tree, 'b');
    bst_delete(&tree, 'a');
    bst_delete(&tree, 'c');

}

/* vlozi 4 pismenka */
void test_4() {
    bst_node_t *tree;

    bst_init(&tree);
    bst_insert(&tree, 'd', 5);
    bst_insert(&tree, 'b', 5);
    bst_insert(&tree, 'a', 5);
    bst_insert(&tree, 'c', 5);

    bst_delete(&tree, 'b');
    bst_delete(&tree, 'a');
    bst_delete(&tree, 'c');
    bst_delete(&tree, 'd');

}

int main() {

    test_1();

    test_2();

    test_3();

    test_4();

    printf("vse ok\n");
}