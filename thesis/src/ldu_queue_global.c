
bool insert_log_global_queue(struct obj_root *root,
		struct ldu_node *log)
{
	...
	do {
		first = head->first;
		new_last->next = first;
	} while (CMP_AND_SWAP(&head->first, first, new_first) != first);
	...
}
