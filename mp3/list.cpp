/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */
#include <iostream>
/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
    // call heaper function: clear
    clear();
    /// @todo Graded in MP3.1
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    // if there is a list
    if (head != NULL) {
        ListNode * curr = head;
        // if there is a next node
        while (curr != NULL) {
            // temp holds the next node
            ListNode * temp = curr->next;
            delete curr;
            // now curr holds the next node
            curr = temp;
        }
        // reset length
        length = 0;
    }
    /// @todo Graded in MP3.1
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{
    ListNode * newNode = new ListNode(ndata);
    // if it's an empty list
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    // if it's not an empty list
    else {
        // new node's next points to original head node
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // increment the length;
    length++;
    /// @todo Graded in MP3.1
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
    ListNode * newNode = new ListNode(ndata);
    // if it's an empty list
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    }
    // if it's not an empty list
    else {
        // new node's prev points to original tail node
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    // increment the length
    length++;
    /// @todo Graded in MP3.1
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
 template <class T>
 void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint)
 {
     ListNode * orig = startPoint;
     ListNode * curr = startPoint;
     ListNode * temp = NULL;
     ListNode * connect = NULL;
     // if it's an empty list or only one node, return
     if (startPoint == endPoint) {
         return;
     }
     // if it's not an empty list, not does it have only one node
     if (startPoint != NULL) {
         // if reversing the whole list(not reverseN)
         if ((startPoint->prev == NULL) && (endPoint->next == NULL)){
             // rewiring the first node;
             curr->prev = curr->next;
             curr->next = NULL;
             curr = curr->prev;
             // rewiring the nodes in the middle
             while (curr != endPoint) {
                 temp = curr->prev;
                 curr->prev = curr->next;
                 curr->next = temp;
                 curr = curr->prev;
             }
             // rewiring the last node
             temp = curr->prev;
             curr->next = temp;
             curr->prev = NULL;
             startPoint = endPoint;
             endPoint = orig;
             return;
         }
         // reverse N cases;
         else{
             // reversing first group of nodes that starts with head
             // reversing the first node
             if (startPoint->prev == NULL && (endPoint->next != NULL)){
                 curr->prev = curr->next;
                 curr->next = endPoint->next;
                 (endPoint->next)->prev = curr;
                 curr = curr->prev;
                 // reversing nodes in the middle
                 while (curr != endPoint) {
                     temp = curr->prev;
                     curr->prev = curr->next;
                     curr->next = temp;
                     curr = curr->prev;
                 }
                 // reversing the last node in the first group that starts with head
                 temp = curr->prev;
                 curr->next = temp;
                 curr->prev = NULL;
                 startPoint = endPoint;
                 endPoint = orig;
                 return;
             }
             // reversing the group of node that doesn't contain the head and the tail
             if ((startPoint->prev != NULL) && (endPoint->next != NULL)) {
                 connect = curr->prev;
                 connect->next = endPoint;
                 (endPoint->next)->prev = orig;
                 curr->prev = curr->next;
                 curr->next = endPoint->next;
                 curr = curr->prev;
                 while (curr != endPoint) {
                     temp = curr->prev;
                     curr->prev = curr->next;
                     curr->next = temp;
                     curr = curr->prev;
                 }
                 temp = curr->prev;
                 curr->next = temp;
                 curr->prev = connect;
                 //startPoint = endPoint;
                 endPoint = orig;
                 return;
             }
             // reversing the last group of node that has tail
             if ((startPoint->prev != NULL) && (endPoint->next == NULL)) {
                 connect = curr->prev;
                 connect->next = endPoint;
                 curr->prev = curr->next;
                 curr->next = NULL;
                 curr = curr->prev;
                 while (curr != endPoint) {
                     temp = curr->prev;
                     curr->prev = curr->next;
                     curr->next = temp;
                     curr = curr->prev;
                 }
                 temp = curr->prev;
                 curr->prev = connect;
                 curr->next = temp;
                 endPoint = orig;
                 return;
             }
         }
     }
     /// @todo Graded in MP3.1
 }
     /// @todo Graded in MP3.1

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n)
{
    ListNode * front = head;
    ListNode * end = head;
    int turn = length / n;
    int modTurn = turn - 2;
    int remain = length % n;
    // invalid n or empty list
    if ((n <= 0) || (head == NULL)){
        return;
    }
    // if n is larger or equal to length, just reverse the whole list
    if (n >= length){
        reverse(head, tail);
    }
    // if 0 < n < length
    else{
        if ((modTurn < 0) || ((modTurn == 0) && (remain == 0))){
            for (int i = 0; i < (n - 1); i++) {
                end = end->next;
            }
            reverse(head, end);
            end = end->next;
            front = end;
            reverse(front, tail);
        }
        if ((modTurn > 0) || ((modTurn == 0) && (remain != 0))){
            if (remain != 0) {
                turn ++;
            }
            for (int i = 0; i < (n - 1); i++) {
                end = end->next;
            }
            reverse(head, end);
            end = end->next;
            front = end;
            for (int i = 0; i < (turn - 2); i++) {
                for (int j = 0; j < (n - 1); j++) {
                    end = end->next;
                }
                reverse(front, end);
                end = end->next;
                front = end;
            }
            reverse(front, tail);
        }
    }


    /// @todo Graded in MP3.1
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    // if it's an empty list or it only has one node, return
    if ((head == NULL) || (head->next == NULL)){
        return;
    }
    ListNode * temp = NULL;
    ListNode * curr = head;
    // if it's not an empty list, nor does it have only one node
    // make sure there is at least 1 more node to work on
    while ((curr->next != NULL) && (curr->next->next != NULL)) {
        temp = curr;
        curr = curr->next;
        curr->next->prev = temp;
        curr->prev = tail;
        tail->next = curr;
        temp->next = curr->next;
        curr->next = NULL;
        tail = curr;
        curr = temp->next;
    }
    /// @todo Graded in MP3.1
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
    // if empty list or special cases
    if ((start == NULL) || (splitPoint >= length) || (splitPoint == 0)) {
        return start;
    }
    ListNode * secondHead = start;
    for (int i = 0; i < splitPoint; i++) {
        secondHead = secondHead->next;
    }
    secondHead->prev->next = NULL;
    secondHead->prev = NULL;
    return secondHead;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{
    // if two empty lists, return NULL
    if ((first == NULL) && (second == NULL)) {
        return NULL;
    }
    // if one is empty one is not, return the list with nodes
    if (first == NULL) {
        first = second;
        second = NULL;
        return first;
    }
    if (second == NULL) {
        return first;
    }
    // if same list return first
    if (first == second) {
        second = NULL;
        return first;
    }
    ListNode * newHead = first;
    ListNode * connect = first;
    ListNode * insert = second;
    ListNode * temp = NULL;
    // relocating the new head ptr, and ptrs in two lists
    if (insert->data < connect->data) {
        newHead = insert;
        temp = insert;
        insert = insert->next;
    }
    else {
        temp = connect;
        connect = connect->next;
    }
    // if one of the lists has only one node
    if (connect == NULL) {
        connect = first;
        connect->next = insert;
        insert->prev = connect;
        second = NULL;
        return newHead;
    }
    if (insert == NULL) {
        insert = second;
        insert->next = connect;
        connect->prev = insert;
        second = NULL;
        return newHead;
    }
    // rewiring nodes by comparing their data
    while ((connect != NULL) && (insert != NULL)) {
        if (insert->data < connect->data) {
            temp->next = insert;
            insert->prev = temp;
            connect->prev = NULL;
            temp = insert;
            insert = insert->next;
        }
        else /*if (connect->data < insert->data)*/ {
            temp->next = connect;
            connect->prev = temp;
            insert->prev = NULL;
            temp = connect;
            connect = connect->next;
        }
    }
    // making sure no missing nodes
    if (insert != NULL) {
        insert->prev = temp;
        temp->next = insert;
    }
    else{
        connect->prev = temp;
        temp->next = connect;
    }
    second = NULL;
    return newHead;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{
    if ((start == NULL) || (chainLength <= 0)) {
        return NULL;
    }
    if (chainLength == 1) {
        return start;
    }
    int leftLength = chainLength/2;
    int rightLength = chainLength - chainLength/2;
    ListNode * left = start;
    ListNode * right = split(start, leftLength);
    left = mergesort(left, leftLength);
    right = mergesort(right, rightLength);
    return merge(left,right);
}
