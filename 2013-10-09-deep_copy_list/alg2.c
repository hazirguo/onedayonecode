

void deep_copy_list(list *old_list, list **new_list)
{
    list_node *p_old_node = old_list;
    list_node *p_new_node = NULL;
    
    //遍历旧链表
    while(p_old_node)
    {
        p_new_node = (list_node *) malloc (sizeof(list_node *));
        p_new_node->key = p_old_node->key;

        //新建的节点插入旧链表当前和下一个节点之间
        p_new_node->next = p_old_node->next==NULL ? NULL : p_old_node->next;
        p_old_node->next = p_new_node;
    }


    //恢复
    *new_list = old_list->next;

    p_old_node = old_list;
    p_new_node = p_old_node->next;

    while(p_old_node)
    {
        p_old_node->next = p_new_node->next==NULL ? NULL : p_new_node->next;
        p_new_node->next = p_new_node->next==NULL ? NULL : p_new_node->next->next;
        p_new_node->random = p_old_node->random==NULL ? NULL : p_old_node->random->next;
    }
}
