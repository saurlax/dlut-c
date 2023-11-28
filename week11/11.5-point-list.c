/**
 * 创建一个单向链表存储Point，链表中的每个结点保存Point的x与y（均为int类型）。
 * （1）创建该链表，依次存入点[1,2] [2,3] [3,4] [1,4]
 * （2）输出该链表所有结点数据
 * （3）查找所有x+y=5的结点，并输出这些结点的x与y
 * 练习链表的创建、输出、查找
 */
#include <stdio.h>
#include <stdlib.h>

struct Point
{
  int x;
  int y;
};

struct Node
{
  struct Point data;
  struct Node *next;
};

struct Node *appendNode(struct Node *head, struct Point data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  struct Node *p = head;
  while (p->next != NULL)
    p = p->next;
  p->next = node;
  return node;
}

int main()
{
  struct Node head = {{1, 2}, NULL};
  appendNode(&head, (struct Point){2, 3});
  appendNode(&head, (struct Point){3, 4});
  appendNode(&head, (struct Point){1, 4});
  puts("All nodes:");
  for (struct Node *p = &head; p != NULL; p = p->next)
    printf("[%d,%d]\n", p->data.x, p->data.y);
  puts("All nodes where x+y=5:");
  for (struct Node *p = &head; p != NULL; p = p->next)
    if (p->data.x + p->data.y == 5)
      printf("[%d,%d]\n", p->data.x, p->data.y);
  return 0;
}