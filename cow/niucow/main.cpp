#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
class solution{
public:
	void odd_even(vector<int> &arr)
	{
		vector<int> arr1(arr);
		int temp1=0;
		int temp2=0;
		for(size_t i=0;i<arr.size();i++ )
		{
			if(arr1[i]%2!=0)
				arr[(temp1++)]=arr1[i];
			if(arr1[arr.size()-1-i]%2==0)
				arr[arr.size()-1+temp2--]=arr1[arr.size()-1-i];
		}
	}
	ListNode* reverse_list(ListNode* head)
	{
		vector<int>a;
		if(head==NULL || head->next==NULL)
			return head;
		ListNode *temp=head;
		while(temp)
		{
			a.push_back(temp->val);
			temp=temp->next;
		}
		temp=new ListNode(0);
		ListNode* head1=temp;
		for(size_t i=0;i<a.size();i++)
		{
			temp->next=new ListNode(a[a.size()-1-i]);
			temp=temp->next;
		}
		return head1->next;
	}

	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        else if(pHead2==NULL)
            return pHead1;
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(pHead1 || pHead2){
			if((pHead1 && pHead2 && pHead1->val<pHead2->val) || !pHead2)
			{
				temp->next=pHead1;
				
				pHead1=pHead1->next;
			}
			else if((pHead1 && pHead2 && pHead1->val>=pHead2->val) || !pHead1)
			{
				temp->next=pHead2;
				pHead2=pHead2->next;
			}
			temp=temp->next;

        }
		temp->next=NULL;
		return head->next;
    }




	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		if(!pRoot1 || !pRoot2 )
			return false;

    }

};


ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
	vector<ListNode*> s1;
	vector<ListNode*> s2;
	if(!pHead1 || !pHead2) return NULL;
	while(pHead1 || pHead2){
		if(pHead1)
			{
			//s1.push_back(pHead1);
			s1.insert(s1.begin(),pHead1);
			pHead1=pHead1->next;
		}
			if(pHead2)
			{
			//s2.push_back(pHead2);
			s2.insert(s2.begin(),pHead2);
			pHead2=pHead2->next;
		}
	}
	//int len1=s1.size()-1;
	//int len2=s2.size()-1;
	int len=0;
	ListNode* res=NULL;
	while(s1[len]==s2[len]){
		res=s1[len];
		
		len++;
		if(len>s1.size()-1 || len>s2.size()-1) break;
            
	}
	return res;
}

string LeftRotateString(string str, int n) {
        int len=str.size();
        if(n==0||len<=1)return str;
        n%=len;
        string str1,str2;
        while(n--)
		{
			str1.append(str.c_str(),1);
            str.erase(str.begin());
        }
        str2=str+str1;
        return str2;
    }
string ReverseSentence(string str) {
	string::iterator begin=str.begin();
	vector<string> s;
	string tmp;
	for(string::iterator i=str.begin()+1;i<str.end();i++)
	{
		//tmp.append(str.c_str(),1);
		if(*i==' ')
		{
			tmp.append(begin,i);
			begin=i+1;
			s.push_back(tmp);
			tmp.clear();
		}
	}
	tmp.append(begin,str.end());
	s.push_back(tmp);
	tmp.clear();
	for(int i=s.size()-1;i>0;i--)
	{
		tmp+=s[i];
		tmp+=' ';
	}
	tmp+=s[0];
    return tmp;
}
int main()
{
	//int a[]={1,5,8,4,6,2,5,7};
	//vector<int> arr(a,a+8);
	/*solution s;
	//s.odd_even(arr);
	ListNode *a=new ListNode(1);
	a->next=	new ListNode(4);
	//a=a->next;
	a->next->next=new ListNode(7);

	ListNode *b=new ListNode(2);
	b->next=	new ListNode(5);
	//a=a->next;
	b->next->next=new ListNode(8);
	b->next->next->next=a->next->next;
	a->next->next->next=new ListNode(11);
	a->next->next->next->next=NULL;

	
	//ListNode* c=s.Merge(a,b);
	//char d[10]={'h','e','l','l','o','\0'};
	//char e[10]="hello";
	ListNode *res=FindFirstCommonNode(a,a);
	*/
	string s("i am a student.");
	string res=ReverseSentence(s);
	return 0;
}