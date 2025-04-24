#include "codeKatas.h"

using namespace std;

// You are given two non - empty linked lists representing two non - negative integers.The digits are stored in reverse order, and each of their nodes contains a single digit.Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

class AddTwoNumbers {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

public:
	ListNode* Solution(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        return new ListNode(sum % 10, AddDigit(l1->next, l2->next, sum / 10));
    }

    ListNode* AddDigit(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }

        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        return new ListNode(sum % 10, AddDigit(l1, l2, sum / 10));
    }

    void delete_list(ListNode** list) {
        ListNode* cursor = *list;
        while (cursor != nullptr) {
            auto next = cursor->next;
            delete cursor;
            cursor = next;
        }
        list = nullptr;
    }

    ListNode* to_list(vector<int> v) {
        ListNode *head = nullptr, *tail;
        for (auto e : v) {
            if (head == nullptr) {
                head = tail = new ListNode(e);
            } else {
                tail->next = new ListNode(e);
                tail = tail->next;
            }
        }
        return head;
    }

    vector<int> to_vector(ListNode* list) {
        vector<int> ret;
        ListNode* cursor = list;
        while (cursor != nullptr) {
            ret.push_back(cursor->val);
            cursor = cursor->next;
        }
        return ret;
    }

    void Test(ostream& out, ListNode* in1, ListNode* in2, vector<int> expected) {
        out << "L1 = " << to_vector(in1) << " L2 = " << to_vector(in2) << " Expectation: " << expected;
        auto actual = to_vector(Solution(in1, in2));
        out << " Actual: " << actual << " *** " << ((expected == actual) ? "Pass" : "Fail") << " ***" << endl;
    }

    AddTwoNumbers(ostream& out) {
        ListNode* l1 = to_list({ 2, 4, 3 });
        ListNode* r1 = to_list({ 5, 6, 4 });
        Test(out, l1, r1, { 7, 0, 8 });
        delete_list(&l1);
        delete_list(&r1);

        l1 = new ListNode(0);
        r1 = new ListNode(0);
        Test(out, l1, r1, { 0 });
        delete_list(&l1);
        delete_list(&r1);

        l1 = to_list({ 9, 9, 9, 9, 9, 9, 9 });
        r1 = to_list({ 9, 9, 9, 9 });
        Test(out, l1, r1, { 8, 9, 9, 9, 0, 0, 0, 1 });
        delete_list(&l1);
        delete_list(&r1);
    }
};