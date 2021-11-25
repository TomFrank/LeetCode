//2. 将两个非递减的有序链表合并为一个非递增的有序链表。（要求利用原来两个链表的存储空间，不另外占用其他空间，表中不允许有重复数据
/*思路：
      a.非递增说明最小的在最后面，二两个链表是非递减的，说明两个链表的第一个都是各自最小的，将它们进行对比得出最小值作为合并链表的尾结点
      b.然后依次将剩余最小的结点链接到尾结点*/
#include <iostream>
#include <vector>
using namespace std;
//构造链表
struct ListNode{
    int data;
    ListNode *link;
    ListNode(int data1, ListNode *link1 = nullptr): data(data1),link(link1){}
};

//算法实现
class Solution {
public:
//    static ListNode* l3(ListNode* l1, ListNode* l2){
//        ListNode first(0);
//        ListNode* head=&first;
//        ListNode last(0);
//        ListNode* p=&last;
//        ListNode* go=&last;
//        //开始给尾结点找前驱
//        while (l1!=NULL || l2!= NULL) {
//            if(l1!=NULL && l2!=NULL){
//               if (l1->data < l2->data) { go=l1; l1=l1->link; go->link=p; p=go; }
//               else {go=l2; l2=l2->link; go->link=p; p=go; }}
//            else if (l1==NULL){go=l2; l2=l2->link; go->link=p; p=go; }
//            else {go=l1;  l1=l1->link; go->link=p; p=go;}}
//        head->link=go;
//        ListNode* after = go->link;
//        //删除重复存储值的结点
//        while(after!=NULL) {
//            if (go->data == after->data){after=after->link; free(go->link); go->link=after;}
//            else{go=go->link;after=after->link;}}
//        return first.link;
//    }
    
    static void deleteDuplicate(ListNode* head) {
        while (head != nullptr && head->link != nullptr) {
            if (head->link->data == head->data) {
                ListNode *t = head->link;
                head->link = head->link->link;
                delete t;
            }
            head = head->link;
        }
    }
    
    static ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(-1);
        
        ListNode* p = &head;
        
        while (l1 && l2) {
            if (l1->data > l2->data) {
                p->link = l1;
                l1 = l1->link;
            } else {
                p->link = l2;
                l2 = l2->link;
            }
            p = p->link;
        }
        
        return head.link;
    }
    
    static ListNode* l3(ListNode* l1, ListNode* l2) {
        deleteDuplicate(l1);
        deleteDuplicate(l2);
        ListNode* l3 = merge(l1, l2);
        deleteDuplicate(l3);
        return l3;
    }
    
    static ListNode* listFromArray(vector<int> arr) {
        ListNode head = ListNode(-1);
        ListNode* t = &head;
        for(int a:arr) {
            t->link = new ListNode(a);
            t = t->link;
        }
        return head.link;
    }
    
    static void printList(ListNode* head) {
        while (head != nullptr) {
            printf("%d", head->data);
            head = head->link;
        }
        printf("\n");
    }
    
    static ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->link == nullptr) {
            return head;
        }
        ListNode *p = reverseList(head->link);
        head->link->link = head;
        head->link = nullptr;
        return p;
    }
};


//test
int main() {
    //创建两个测试用的链表
    
    ListNode *l1 = Solution::listFromArray({8,6,4,3,1,1,1,1});
    ListNode *l2 = Solution::listFromArray({7,7,5,5,2,1});
    
    Solution::printList(l1);
    Solution::printList(l2);
    
    ListNode *l3 = Solution::l3(l1, l2);
    Solution::printList(l3);
    
}
