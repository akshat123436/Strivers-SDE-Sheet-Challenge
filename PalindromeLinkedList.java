import java.util.* ;
import java.io.*; 
/****************************************************************

    Following is the class structure of the LinkedListNode class:
	
	class LinkedListNode<T> {
    	T data;
    	LinkedListNode<T> next;

    	public LinkedListNode(T data) {
        	this.data = data;
    	}
	}

*****************************************************************/

public class Solution {

	public static boolean isPalindrome(LinkedListNode<Integer> head) {
		// Write your code here!
		Stack<Integer> s = new Stack <>();
		LinkedListNode <Integer> temp = head;
		int size = 0;
		while(temp != null){
			size++;

			temp = temp.next;
		}
		temp = head;
		for(int i =0;i<size/2;i++){
			s.push(temp.data);
			// System.out.println(temp.data);
			temp = temp.next;
		}
		if((size&1) == 1) temp = temp.next;
		// System.out.println(size);
		for(int i =0;i<size/2;i++){
			// System.out.print(s.peek() + " " + temp.data);
			// System.out.print(s.peek() + " " + temp.data);
			int v1 = s.peek();
			int v2 = temp.data;
			if(v1 == v2) s.pop();
			else return false;
			temp = temp.next;
		}
		return true;
	}
}