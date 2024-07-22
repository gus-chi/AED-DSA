#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "rb-tree.h"

RB_Node* test = NULL; // Arvore de teste principal

RB_Node* test_input3;

RB_Node* test_recolor; // Arvore de teste para testar recoloração
RB_Node* test_rl_rotation;
RB_Node* test_ll_rotation;
RB_Node* test_prof;
void setUp(){

    // test = InstantiateNode(50);
    // InsertOnTree(test, NULL, NULL, InstantiateNode(20), test);
    // InsertOnTree(test, NULL, NULL, InstantiateNode(60), test);
    // InsertOnTree(test, NULL, NULL, InstantiateNode(10), test);
    // InsertOnTree(test, NULL, NULL, InstantiateNode(30), test);

    test_input3 = InstantiateNode(6);
    Recolor(test_input3);
    InsertOnTree(&test_input3, NULL, NULL, InstantiateNode(4), &test_input3);    
    InsertOnTree(&test_input3, NULL, NULL, InstantiateNode(3), &test_input3);    
    InsertOnTree(&test_input3, NULL, NULL, InstantiateNode(2), &test_input3);    
    InsertOnTree(&test_input3, NULL, NULL, InstantiateNode(1), &test_input3);    
    InsertOnTree(&test_input3, NULL, NULL, InstantiateNode(5), &test_input3);    
    InsertOnTree(&test_input3, NULL, NULL, InstantiateNode(7), &test_input3);    
    InsertOnTree(&test_input3, NULL, NULL, InstantiateNode(8), &test_input3);    
//     test_recolor = InstantiateNode(20);
//     Recolor(test_recolor);
//     InsertOnTree(test_recolor, NULL, NULL, InstantiateNode(30), test_recolor);
//     InsertOnTree(test_recolor, NULL, NULL, InstantiateNode(10), test_recolor);
//     InsertOnTree(test_recolor, NULL, NULL, InstantiateNode(5), test_recolor);
    
    test_ll_rotation = InstantiateNode(40);
    Recolor(test_ll_rotation);
    InsertOnTree(&test_ll_rotation, NULL, NULL, InstantiateNode(30), &test_ll_rotation);
    InsertOnTree(&test_ll_rotation, NULL, NULL, InstantiateNode(20), &test_ll_rotation);

    test_rl_rotation = InstantiateNode(20);
    Recolor(test_rl_rotation);
    InsertOnTree(&test_rl_rotation, NULL, NULL, InstantiateNode(30), &test_rl_rotation);
    InsertOnTree(&test_rl_rotation, NULL, NULL, InstantiateNode(25), &test_rl_rotation);
    
    test_prof = InstantiateNode(6);
    Recolor(test_prof);
    InsertOnTree(&test_prof, NULL, NULL, InstantiateNode(4), &test_prof);
    InsertOnTree(&test_prof, NULL, NULL, InstantiateNode(3), &test_prof);
    InsertOnTree(&test_prof, NULL, NULL, InstantiateNode(2), &test_prof);
    InsertOnTree(&test_prof, NULL, NULL, InstantiateNode(1), &test_prof);
}
void tearDown(){
}
void testCreation(){
    // TEST_ASSERT_EQUAL(50, test->value);
    // TEST_ASSERT_EQUAL('b', test->color);
    // TEST_ASSERT_EQUAL(20, test->left->value);
    // TEST_ASSERT_EQUAL(10, test->left->left->value);
    // TEST_ASSERT_EQUAL(30, test->left->right->value);
    // TEST_ASSERT_EQUAL(60, test->right->value);

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
    // TEST_ASSERT_EQUAL('b', test_recolor->color);
    // TEST_ASSERT_EQUAL('b', test_recolor->left->color);
    // TEST_ASSERT_EQUAL('r', test_recolor->left->left->color);
    // TEST_ASSERT_EQUAL('b', test_recolor->right->color);
    
    TEST_ASSERT_EQUAL(30, test_ll_rotation->value);
    TEST_ASSERT_EQUAL('b', test_ll_rotation->color);
    TEST_ASSERT_EQUAL(20, test_ll_rotation->left->value);
    TEST_ASSERT_EQUAL('r', test_ll_rotation->left->color);
    TEST_ASSERT_EQUAL(40, test_ll_rotation->right->value);
    TEST_ASSERT_EQUAL('r', test_ll_rotation->right->color);


    TEST_ASSERT_EQUAL(25, test_rl_rotation->value);
    TEST_ASSERT_EQUAL('b', test_rl_rotation->color);
    TEST_ASSERT_EQUAL(20, test_rl_rotation->left->value);
    TEST_ASSERT_EQUAL('r', test_rl_rotation->left->color);
    TEST_ASSERT_EQUAL(30, test_rl_rotation->right->value);
    TEST_ASSERT_EQUAL('r', test_rl_rotation->right->color);

    TEST_ASSERT_EQUAL(4, test_prof->value); 
    TEST_ASSERT_EQUAL('b', test_prof->color); 
    TEST_ASSERT_EQUAL(2, test_prof->left->value); 
    TEST_ASSERT_EQUAL('b', test_prof->left->color);
    TEST_ASSERT_EQUAL(1, test_prof->left->left->value);
    TEST_ASSERT_EQUAL('r', test_prof->left->left->color);
    TEST_ASSERT_EQUAL(3, test_prof->left->right->value);
    TEST_ASSERT_EQUAL('r', test_prof->left->right->color);
    TEST_ASSERT_EQUAL(6, test_prof->right->value); 
    TEST_ASSERT_EQUAL('b', test_prof->right->color); 
}
        void testFindHeight(){
//    TEST_ASSERT_EQUAL(2, FindHeight(test));
//    TEST_ASSERT_EQUAL(1, FindHeight(test->left));
//    TEST_ASSERT_EQUAL(0, FindHeight(test->left->left));
//    TEST_ASSERT_EQUAL(0, FindHeight(test->left->right));
//    TEST_ASSERT_EQUAL(0, FindHeight(test->right));
}
int main(void){
    UNITY_BEGIN();
    RUN_TEST(testCreation);
    RUN_TEST(testFindHeight);
    UNITY_END();   
    return 0;
}