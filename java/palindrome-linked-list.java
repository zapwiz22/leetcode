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
    // to reverse the second half to then compare 
    public ListNode reverseLL(ListNode head) {
        ListNode prev = null, curr = head, next = null;
        while (curr!=null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public boolean isPalindrome(ListNode head) {
        // tortoise-hare method to find the middle of the linked list
        ListNode first = head, second = head;
        while (second!=null && second.next!=null) {
            first = first.next;
            second = second.next.next;
        }
        // checking palindrome
        ListNode firstHead = head;
        ListNode secondHead = reverseLL(first);
        while (secondHead!=null) {
            if (secondHead.val != firstHead.val) {
                return false;
            }
            firstHead = firstHead.next;
            secondHead = secondHead.next;
        }
        return true;
    }
}

