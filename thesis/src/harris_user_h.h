typedef struct node
{
  skey_t key;
  sval_t val;
  uint8_t padding32[8];
  volatile struct node* next;
} node_t;`
