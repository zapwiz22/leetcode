/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head,int n) {
        if (head.next == null) {
            return null;
        }
        int size = 0;
        ListNode p = head;
        while (p!=null) {
            size++;
            p  = p.next;
        }
        // getting the position from start
        int fromStart = size-n+1;
        if (fromStart==1) {
            return head.next;
        }
        // deleting the node from the start
        int cnt = 1;
        ListNode q = head;
        while (cnt!=fromStart-1) {
            cnt++;
            q = q.next;
        }
        q.next = q.next.next;
        return head;
    }
}