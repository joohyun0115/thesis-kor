bool insert_log_per_core_queue(struct obj_root *root, struct ldu_node *log) {
	slot = &get_cpu_var(obj_root_slot);
	p = &slot->obj[hash_ptr(root, HASH_ORDER)];
	empty = p->list.first;
	if (!empty) { // is empty list?
		ldu = log_entry(first, struct ldu, ll_node);
		// is hash complict?
		if (ldu->root != log->root) {
			lock = ldu->lock;
			entry = SWAP(&p->list->head->first, NULL);
			...
			// insert log into queue
			do {
				first = head->first; log->->next = first;
			} while (CAS(&head->first, first, new_first) != first);
			// flush log as a direct mapped cache
			object_lock(&lock);
			synchronize_ldu(entry);
			object_unlock(&lock);
			goto out;
		}
	}
	...
	// insert log into queue;
	do {
		first = head->first; log->->next = first;
	} while (CAS(&head->first, first, new_first) != first);

out:
	...
}
