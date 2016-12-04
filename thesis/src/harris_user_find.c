static struct lockfree_list_node *list_search(struct lockfree_list_head
		*head, void *key,struct lockfree_list_node **left_node) {
	...
search_again:
	do {
		...
		do {
		/* Find left_node and right_node */
			if (!is_marked_ref((long)t_next)) {
				(*left_node) = t;
				left_node_next = t_next;
			}
			t = (struct lockfree_list_node *) get_unmarked_ref((long)t_next);
			if (!t->next)
				break;
			t_next = t->next;
		} while (is_marked_ref((long)t_next));
		right_node = t;
		/* Check that nodes are adjacent */
		if (left_node_next == right_node) {
			if ((right_node->next) && is_marked_ref((long) right_node->next)) {
				goto search_again;
			} else
				return right_node;
		}
		/* Remove one or more marked nodes */
		if (cmpxchg(&(*left_node)->next, left_node_next, right_node) ==
				left_node_next) {
			struct lockfree_list_node *cur = left_node_next;
			...
			if ((right_node->next) && is_marked_ref((long) right_node->next)) {
				goto search_again;
			} else
				return right_node;
		}
	} while (1);
}
