struct lockfree_list_head {
	struct lockfree_list_node *head, *tail;
};

struct lockfree_list_node {
	struct lockfree_list_node *next;
	void *key;
	int garbage;
};


bool lockfree_list_add_batch(struct lockfree_list_node *new,
		struct lockfree_list_head *head)
{
	struct lockfree_list_node *right_node, *left_node;
	left_node = head->head;
	do {
		right_node = list_search_for_add(head, new->key, &left_node);
		new->next = right_node;
		smp_mb();
	} while (cmpxchg(&left_node->next, right_node, new) != right_node);

	return true;
}
