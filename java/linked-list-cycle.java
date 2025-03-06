/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head==null) {
            return false;
        }
        // using tortoise-hare method to check whether they will collide or not
        // if they collide it implies loop exists
        // if the linked list ends it implies loop doesn't exist
        ListNode fast = head, slow = head;
        while (fast!=null && fast.next!=null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast==slow) {
                return true;
            }
        }
        return false;
    }
}