#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "rb-tree.h"

// Árvores testes do pdf

RB_Node *test_input1 = NULL;
RB_Node *test_input2 = NULL;
RB_Node *test_input3 = NULL;
RB_Node *test_input4 = NULL;

// Árvore de teste função Recolorir

RB_Node *test_recolor = NULL;

// Árvore de teste rotações
RB_Node *test_ll_rotation = NULL;
RB_Node *test_rr_rotation = NULL;

void setUp(){

    test_input1 = InstantiateNode(6);
    Recolor(test_input1);
    InsertOnRBTree(test_input1, InstantiateNode(4), &test_input1);
    InsertOnRBTree(test_input1, InstantiateNode(3), &test_input1);
    InsertOnRBTree(test_input1, InstantiateNode(2), &test_input1);
    InsertOnRBTree(test_input1, InstantiateNode(1), &test_input1);
    // InsertOnTree(&test_input1, NULL, NULL, InstantiateNode(4),  &test_input1);
    // InsertOnTree(&test_input1, NULL, NULL, InstantiateNode(3),  &test_input1);
    // InsertOnTree(&test_input1, NULL, NULL, InstantiateNode(2),  &test_input1);
    // InsertOnTree(&test_input1, NULL, NULL, InstantiateNode(1),  &test_input1);

    test_input2 = InstantiateNode(6);
    Recolor(test_input2);
    InsertOnRBTree(test_input2, InstantiateNode(4),  &test_input2);
    InsertOnRBTree(test_input2, InstantiateNode(5),  &test_input2);
    InsertOnRBTree(test_input2, InstantiateNode(3),  &test_input2);
    InsertOnRBTree(test_input2, InstantiateNode(2),  &test_input2);
    InsertOnRBTree(test_input2, InstantiateNode(7),  &test_input2);
    InsertOnRBTree(test_input2, InstantiateNode(1),  &test_input2);
    
    test_input3 = InstantiateNode(6);
    Recolor(test_input3);
    InsertOnRBTree(test_input3, InstantiateNode(4), &test_input3);    
    InsertOnRBTree(test_input3, InstantiateNode(3), &test_input3);    
    InsertOnRBTree(test_input3, InstantiateNode(2), &test_input3);    
    InsertOnRBTree(test_input3, InstantiateNode(1), &test_input3);    
    InsertOnRBTree(test_input3, InstantiateNode(5), &test_input3);    
    InsertOnRBTree(test_input3, InstantiateNode(7), &test_input3);    
    InsertOnRBTree(test_input3, InstantiateNode(8), &test_input3);    

    test_input4 = InstantiateNode(6);
    Recolor(test_input4);
    InsertOnRBTree(test_input4, InstantiateNode(4), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(3), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(2), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(1), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(5), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(7), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(8), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(11), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(9), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(10), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(15), &test_input4);    
    InsertOnRBTree(test_input4, InstantiateNode(13), &test_input4);    


    
    
    // test_recolor = InstantiateNode(20);
    // Recolor(test_recolor);
    // InsertOnTree(&test_recolor, NULL, NULL, InstantiateNode(10), &test_recolor);
    // InsertOnTree(&test_recolor, NULL, NULL, InstantiateNode(30), &test_recolor);

    test_ll_rotation = InstantiateNode(30);
    Recolor(test_ll_rotation);
    test_ll_rotation->left = InstantiateNode(20);
    test_ll_rotation->left->left = InstantiateNode(10);

    test_rr_rotation = InstantiateNode(10);
    Recolor(test_rr_rotation);
    test_rr_rotation->right = InstantiateNode(20);
    test_rr_rotation->right->right = InstantiateNode(30);   
}


void testInsertOnTree(){

    // Teste de inserção, input 1
    TEST_ASSERT_EQUAL(4, test_input1->value);
    TEST_ASSERT_EQUAL('b', test_input1->color);
    TEST_ASSERT_EQUAL(2, test_input1->left->value);
    TEST_ASSERT_EQUAL('b', test_input1->left->color);
    TEST_ASSERT_EQUAL(1, test_input1->left->left->value);
    TEST_ASSERT_EQUAL('r', test_input1->left->left->color);
    TEST_ASSERT_EQUAL(3, test_input1->left->right->value);
    TEST_ASSERT_EQUAL('r', test_input1->left->right->color);
    TEST_ASSERT_EQUAL(6, test_input1->right->value);
    TEST_ASSERT_EQUAL('b', test_input1->right->color);

    // Teste de inserção, input 2
    
    TEST_ASSERT_EQUAL(5, test_input2->value);
    TEST_ASSERT_EQUAL('b', test_input2->color);
    TEST_ASSERT_EQUAL(3, test_input2->left->value);
    TEST_ASSERT_EQUAL('r', test_input2->left->color);
    TEST_ASSERT_EQUAL(2, test_input2->left->left->value);
    TEST_ASSERT_EQUAL('b', test_input2->left->left->color);
    TEST_ASSERT_EQUAL(1, test_input2->left->left->left->value);
    TEST_ASSERT_EQUAL('r', test_input2->left->left->left->color);
    TEST_ASSERT_EQUAL(4, test_input2->left->right->value);
    TEST_ASSERT_EQUAL('b', test_input2->left->right->color);
    TEST_ASSERT_EQUAL(6, test_input2->right->value);
    TEST_ASSERT_EQUAL('b', test_input2->right->color);
    TEST_ASSERT_EQUAL(7, test_input2->right->right->value);
    TEST_ASSERT_EQUAL('r', test_input2->right->right->color);

    // Teste de inserção, input 3

    TEST_ASSERT_EQUAL(4, test_input3->value);
    TEST_ASSERT_EQUAL('b', test_input3->color);
    TEST_ASSERT_EQUAL(2, test_input3->left->value);
    TEST_ASSERT_EQUAL('b', test_input3->left->color);
    TEST_ASSERT_EQUAL(1, test_input3->left->left->value);
    TEST_ASSERT_EQUAL('r', test_input3->left->left->color);
    TEST_ASSERT_EQUAL(3, test_input3->left->right->value);
    TEST_ASSERT_EQUAL('r', test_input3->left->right->color);
    TEST_ASSERT_EQUAL(6, test_input3->right->value);
    TEST_ASSERT_EQUAL('r', test_input3->right->color);
    TEST_ASSERT_EQUAL(5, test_input3->right->left->value);
    TEST_ASSERT_EQUAL('b', test_input3->right->left->color);
    TEST_ASSERT_EQUAL(7, test_input3->right->right->value);
    TEST_ASSERT_EQUAL('b', test_input3->right->right->color);
    TEST_ASSERT_EQUAL(8, test_input3->right->right->right->value);
    TEST_ASSERT_EQUAL('r', test_input3->right->right->right->color);

    TEST_ASSERT_EQUAL(6, test_input4->value);
    TEST_ASSERT_EQUAL('b', test_input4->color);
    TEST_ASSERT_EQUAL(4, test_input4->left->value);
    TEST_ASSERT_EQUAL('b', test_input4->left->color);
}

void testSearchOnTree(){
    RB_Node* aux;
    aux = SearchOnTree(test_input1, 1);
    TEST_ASSERT_EQUAL(test_input1->left->left, aux);
}

void testSearchFather(){
    RB_Node** aux = malloc(sizeof *aux);
    *aux = NULL;
    TEST_ASSERT_EQUAL(test_input1->left, SearchFather(aux, test_input1, test_input1->left->left));
    *aux = NULL;
    TEST_ASSERT_EQUAL(test_input1->left, SearchFather(aux, test_input1, test_input1->left->right));
    *aux = NULL;
    TEST_ASSERT_EQUAL(NULL, SearchFather(aux, test_input1, test_input1));
}
void testSearchPointer(){
    TEST_ASSERT_EQUAL(&test_input1, SearchPointer(&test_input1, test_input1));
}

void testFindHeight(){
    TEST_ASSERT_EQUAL(2, FindHeight(test_input1));
    TEST_ASSERT_EQUAL(1, FindHeight(test_input1->left));
    TEST_ASSERT_EQUAL(0, FindHeight(test_input1->right));
    TEST_ASSERT_EQUAL(0, FindHeight(test_input1->left->left));
    TEST_ASSERT_EQUAL(0, FindHeight(test_input1->left->right));
}

void testRecolor(){
    // key: 20b, 10r, 30r
    TEST_ASSERT_EQUAL('b', test_recolor->color);
    TEST_ASSERT_EQUAL('r', test_recolor->left->color);
    TEST_ASSERT_EQUAL('r', test_recolor->right->color);
    Recolor(test_recolor);
    TEST_ASSERT_EQUAL('r', test_recolor->color);
    Recolor(test_recolor->left);
    TEST_ASSERT_EQUAL('b', test_recolor->left->color);
    Recolor(test_recolor->right);
    TEST_ASSERT_EQUAL('b', test_recolor->right->color);
}

void testLLRotation(){
    test_ll_rotation = LL_Rotation(test_ll_rotation);
    TEST_ASSERT_EQUAL(20, test_ll_rotation->value);
    TEST_ASSERT_EQUAL(10, test_ll_rotation->left->value);
    TEST_ASSERT_EQUAL(30, test_ll_rotation->right->value);
}

void testRRRotation(){
    test_rr_rotation = RR_Rotation(test_rr_rotation);
    TEST_ASSERT_EQUAL(20, test_rr_rotation->value);
    TEST_ASSERT_EQUAL(10, test_rr_rotation->left->value);
    TEST_ASSERT_EQUAL(30, test_rr_rotation->right->value);
}


void tearDown(){

}


int main(void){
    UNITY_BEGIN();
    RUN_TEST(testInsertOnTree);
    RUN_TEST(testSearchPointer);
    // RUN_TEST(testSearchOnTree);
    // RUN_TEST(testSearchFather);
    // RUN_TEST(testFindHeight);
    // RUN_TEST(testRecolor);
    // RUN_TEST(testLLRotation);
    // RUN_TEST(testRRRotation);
    UNITY_END();   
    return 0;
}