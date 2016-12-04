struct element {
	int key;
	int value;
	struct element *next;
};

struct element *global;

void push(struct element *e)
{
retry:
	e->next = global;
	if (cmpxchg(&global, e->next, e) != e->next)
		goto retry;
}

struct element *pop(void)
{
retry:
	struct element *e = global;
	if (cmpxchg(&global, e, e->next) != e)
		goto retry;
	return e;
}
