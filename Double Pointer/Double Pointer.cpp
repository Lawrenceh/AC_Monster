// DOUBLE POINTER
// Delete item i in the linked list
// Using double pointer, we don't need the special case judgement of the head
// Also, we don't need extra space for the prev pointer anymore.
struct list **lpp;
for(lpp = &list; *lpp != NULL; lpp = &(*lpp)->next)
{
    if((*lpp)->item == i)
    {
        *lpp = (*lpp)->next;
        break;
    }
}
