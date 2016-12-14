
bool insert_log_queue(struct obj_root *root,
		struct ldu_node *log)
{
	...
	do {
		first = head->first;
		new_last->next = first;
	} while (CAS(&head->first, first, new_first) != first);
	...
}
