
typedef struct {
    int key;
    list *random;
    list *next;
}list;

typedef list list_node;

void deep_copy_list(list *old_list, list **new_list)
{
    void *map[100][2];
    
    list_node *p_old_node = old_list;
    list_node *p_new_node = NULL;
    list_node *pre_new_node = p_new_node;
    *new_list = p_new_node;
    int i=0;


    while (p_old_node)    //遍历旧链表
    {
        p_new_node = (list *) malloc (sizeof(list_node));
        
        //完成key 的拷贝
        p_new_node->key = p_old_node->key;

        //完成新链表 next 指针的链接
        pre_new_node->next = p_new_node;
        p_new_node->next = NULL;

        //保存旧链表当前节点和下一节点的映射关系,因为马上要破坏旧链表的 next
        map[i][0] = (void *)p_old_node;
        map[i][1] = (void *)p_old_node->next;

        //旧链表的 next 指向新链表节点, 新链表节点的random 指向旧链表节点
        p_old_node->next = p_new_node;
        p_new_node->random = p_old_node;

        i++;
    }

    //完成新链表 random 指针的链接
    p_new_node = *new_list;

    while(p_new_node)
    {
        p_new_node->random = p_new_node->random->random==NULL ? NULL : p_new_node->random->random->next;
    }

    //完成旧链表 next 指针的恢复
    while(j<i)
    {
        ((list_node *)map[j][0]).next = (list_node *)map[j][1];
        j++;
    }
}
