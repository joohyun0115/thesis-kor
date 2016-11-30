int search(long key, int *result)
{
	struct el *p;
	rcu_read_lock();
	list_for_each_entry_rcu(p, &head, lp) {

	}
	rcu_read_unlock();
}
