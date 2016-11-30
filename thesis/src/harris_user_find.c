sval_t
harris_find(intset_t *set, skey_t key)
{
  node_t *right_node, *left_node;
  left_node = set->head;

  right_node = harris_search(set, key, &left_node);
  if ((right_node->next == NULL) || right_node->key != key)
    {
      return 0;
    }
  else
    {
      return right_node->val;
    }
}
