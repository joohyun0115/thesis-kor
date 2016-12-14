bool ldu_logical_insert(struct object_struct *obj, void *head) {
	// Phase 1 : update-side removing logs
	if (SWAP(&obj->ldu.remove.mark, false) == false) {
		obj->ldu.insert.mark = true;
		// Phase 2 : reusing garbage log
		if (!TEST_AND_SET_BIT(LDU_INSERT, &obj->ldu.used)) {
			// Phase 3(slow-path): insert log to queue
			// ... : save argument and operation
			ldu_insert_queue(head, log);
		}
	}
}
