#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
#define min(x,y) (x)>(y)?(y):(x)
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) {val=x;left=NULL;right=NULL;}
};
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
}
};
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class solution{

	public:
    TreeNode* reConstructBinaryTree1(int pre[],int startpre,int endpre,int vin[],int startvin,int endvin) {
		if(startpre > endpre || startvin > endvin)
		{
			return NULL;
		}
		TreeNode *root = new TreeNode(pre[startpre]);
		for(int i=startvin;i<=endvin;i++)
		{
			if(vin[i]==pre[startpre])
			{
				root->left=reConstructBinaryTree1(pre,startpre+1,startpre+(i-startvin),vin,startvin,i-1);
				root->right=reConstructBinaryTree1(pre,i-startvin+startpre+1,endpre,vin,i+1,endvin);
			}
		}
		return root;
    }

	TreeNode* reConstructBinaryTree2(int back[],int startback,int endback,int vin[],int startvin,int endvin) {
		if(startback > endback || startvin > endvin)
		{
			return NULL;
		}
		TreeNode *root = new TreeNode(back[endback]);
		for(int i=startvin;i<=endvin;i++)
		{
			if(vin[i]==back[endback])
			{
				root->left= reConstructBinaryTree2(back,startback,startback+(i-startvin)-1,vin,startvin,i-1);
				root->right=reConstructBinaryTree2(back,i-startvin+startback,endback-1,vin,i+1,endvin);
			}
		}
		return root;
    }


	void replaceSpace(char *str,int length) {
		char *s=new char[length];
		for(int i=0;i<length;i++)
		{
			s[i]=str[i];
		}
		int k=0;
		for(int i=0;i<length;i++)
		{
			if(s[i]==' ')
			{
				str[k]='%';
				str[++k]='2';
				str[++k]='0';
				k++;
			}
			else
			{
				str[k++]=s[i];
			}
		}	
	}

	void nodemirror(TreeNode *pRoot)
	{
		if(pRoot==NULL)
			return;
		TreeNode *temp;
		temp=pRoot->right;
		pRoot->right=pRoot->left;
		pRoot->left=temp;
		nodemirror(pRoot->left);
		nodemirror(pRoot->right);
	}

	void Mirror(TreeNode *pRoot) {
		nodemirror(pRoot);
    }

	vector<int> printMatrix(vector<vector<int> > matrix) {
		int n=matrix.size();
		int m=n;
		int count=0;
		vector<int> result;
		while(n>0)
		{
			if(n==1)
			{
				//cout<<matrix[(m-1)/2][(m-1)/2]<<" ";
				result.push_back(matrix[(m-1)/2][(m-1)/2]);
			}
			else
			{
				for(int i=count;i<count+n;i++)
					result.push_back(matrix[count][i]);
					//cout<<matrix[count][i]<<" ";

				for(int i=count+1;i<=m-1-count-1;i++)
					result.push_back(matrix[i][m-1-count]);
					//cout<<matrix[i][m-1-count]<<" ";


				for(int i=count+n-1;i>=count;i--)
					result.push_back(matrix[m-1-count][i]);
//					cout<<matrix[m-1-count][i]<<" ";

				for(int i=m-1-count-1;i>=count+1;i--)
					result.push_back(matrix[i][count]);
//					cout<<matrix[i][count]<<" ";
			}

			count++;
			n-=2;
		}
		return result;
    }


	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int num=pushV.size();
        stack<int>s;
        int index=0;
        for(int i=0;i<num;i++)
            {
            s.push(pushV[i]);
			while(!s.empty() && s.top()==popV[index])
                {
                index++;
                s.pop();
            }
        }
        return s.empty();
    }


	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
		queue<TreeNode*>q;
		if(root==NULL)
			return result;
		q.push(root);
		while(!q.empty())
		{
			TreeNode* temp=q.front();
			q.pop();
			result.push_back(temp->val);
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
		return result;
    }

	
	vector<vector<int> >  result;
	vector<int> temp;
	vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		
		if(root==NULL)
			return result;
		else
			findonepath(root,expectNumber);
		return result;

    }
	void findonepath(TreeNode *root,int expectNumber)
	{
		temp.push_back(root->val);
		if(root->left==NULL && root->right==NULL && expectNumber-root->val==0){
			
			result.push_back(temp);
		}
		if(root->left!=NULL) findonepath(root->left,expectNumber-root->val);
		if(root->right!=NULL) findonepath(root->right,expectNumber-root->val);
		temp.pop_back();
		
	}

	RandomListNode* Clone(RandomListNode* pHead)
    {
		if(pHead==NULL)
			return pHead;
        RandomListNode*temp=pHead;
		RandomListNode*temp_next;
        while(temp){
            temp_next=new RandomListNode(temp->label);
			temp_next->next=temp->next;
			temp->next=temp_next;
			temp=temp_next->next;
        }
		temp=pHead;
		while(temp){
			if(temp->random){
                temp->next->random=temp->random->next;
                
            }
			temp=temp->next->next;
        }
		temp=pHead->next;
		temp_next=pHead;
        RandomListNode*tmp;
		while(temp_next->next)
		{
            tmp=temp_next->next;
			temp_next->next=tmp->next;
			temp_next=tmp;
		}
        return temp;
    }


	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	vector<ListNode*>vec;
        if(pListHead==NULL) return pListHead;
        while(pListHead)
            {
            vec.push_back(pListHead);
            pListHead=pListHead->next;
        }
        return *(vec.end()-k);
    }
	stack<TreeNode*> s;
	TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return pRootOfTree;
		
        //pRootOfTree = ConvertNode(pRootOfTree);
		link_node(pRootOfTree);
		pRootOfTree = rebuild_list(s);
        //while(pRootOfTree->left) pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }
	TreeNode* rebuild_list(stack<TreeNode*> &s)
	{
		TreeNode* curr;
		TreeNode* old;
		bool isfirst=true;
		while(!s.empty())
		{
			if(isfirst){
				isfirst=false;
				curr=s.top();
				old=curr;
				s.pop();
			}
			else
			{
				curr=s.top();
				curr->right=old;
				old->left=curr;
				old=curr;
				s.pop();
			}

		}
		return curr;
	}
	void link_node(TreeNode* root)
	{
		if(!root) return;
		link_node(root->left);
		s.push(root);
		link_node(root->right);
	}


    TreeNode* ConvertNode(TreeNode* root)
    {
		if(root == NULL) return root;
        if(root->left)
        {
            TreeNode *left = ConvertNode(root->left);
            while(left->right) left = left->right;
            left->right = root;
            root->left = left;
        }
         
        if(root->right)
        {
            TreeNode *right = ConvertNode(root->right);
            while(right->left) right = right->left;
            right->left = root;
            root->right = right;
        }
        return root;
    }

	vector<string> res;
	void p(string str,int index)
	{
		if(str.size()==0 || index<0)
			return ;
		if(index==str.size()-1)
			res.push_back(str);
		else
		{
			for(int i=index;i<str.size();i++)
			{
				if(i!=index && str[i]==str[index])
					continue;
				char temp;
				temp=str[i];
				str[i]=str[index];
				str[index]=temp;


				p(str,index+1);
			}
		}
		return;
	}
	vector<string> Permutation(string str) {
		p(str,0);
		return res;
    }


	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(),numbers.end());
		int l=numbers.size();
		int times=1;
		int temp=1;
		int max_num=numbers[0];
		int index=0;
		int max_times=1;
		for(int i=1;i<l;i++)
		{
			if(numbers[i]==numbers[i-1])
			{
				temp++;
			}
			else
			{
				if(temp>max_times)
				{
					max_times=temp;
					max_num=numbers[i-1];
				}
				//times.push_back(times);
				temp=1;
				
			}
		}
		if(max_times>l/2)
			return max_num;
		else
			return 0;
		
    }

	 bool tail_is_1(int n){
        if(floor(float(n/10.0))*10+1==n) return true;
        else return false;
    }
    
    int NumberOf1Between1AndN_Solution(int n)
    {
        int sum=0;
        //if(n==1)return 1;
        for(int i=1;i<=n;i++)
            {
            int j=i;
            while(j)
            {
                if(tail_is_1(j))
                    sum++;
                j/=10;
            }
        }
        return sum;
    }

	 bool not_ugly(int n){
        if(n==1)return false;
        while(n!=1){
			if(n==2||n==3||n==5)return false;
            if(n%2==0){
                n/=2;
            }
            else if(n%3==0){
                n/=3;
            }
            else if(n%5==0){
                n/=5;
            }
			else return true;
			
			if(n==1)return true;
        }
        
        return false;
        
    }
    int GetUglyNumber_Solution(int index) {
    	int num=0;
		int curr_index=0;
        while(curr_index<index){
			num++;
            if(!not_ugly(num))
                curr_index++;
			 
        }
        return num;
    }

	int GetUglyNumber_Solution1(int index) {
        if (index < 7)return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i;
        for (i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2)t2++;
            if (res[i] == res[t3] * 3)t3++;
            if (res[i] == res[t5] * 5)t5++;
        }
        return res[index - 1];
    }

	bool VerifySquenceOfBST1(vector<int> sequence) {
        if(sequence.size()!=0){
            vector<int> left;
            vector<int> right;
            int rootData=sequence[sequence.size()-1];
            int i=0;
            while(rootData>sequence[i]){
                left.push_back(sequence[i]);
                i++;
            }
            for(int j=i;j<sequence.size()-1;j++){
                if(rootData>sequence[j])
                    return false;
                right.push_back(sequence[j]);
            }
            VerifySquenceOfBST1(left);
            VerifySquenceOfBST1(right);
            return true;
        }
        
        return false;

    }

	bool VerifySquenceOfBST(vector<int> sequence) {
		int m=sequence.size();
		vector<int> vec1;
		vector<int> vec2;
		if (m==1) return true;
		if (m==0) return false;
		for(int i=0;i<m;i++)
		{
			if(sequence[i]<sequence[m-1] && vec2.size()==0)
				vec1.push_back(sequence[i]);
			else if(sequence[i]>sequence[m-1])
				vec2.push_back(sequence[i]);
		}
		if(vec1.size()==m-1)
			return (VerifySquenceOfBST(vec1));
		else if(vec2.size()==m-1)
			return (VerifySquenceOfBST(vec2));
		else if(vec1.size()+vec2.size()==m-1)
			return (VerifySquenceOfBST(vec1) && VerifySquenceOfBST(vec2));
		else
			return false;
	}

};
int run(TreeNode *root) {
    if(root->left==NULL || root->right==NULL)
    {
        return 1;
    }
    else
    {
		int temp1=run(root->left);
		int temp2=run(root->right);
		if(temp1<temp2)
			return temp1+1;
		else
			return temp2+1;
        //return (run(root->left))<(run(root->right))?(run(root->left)):(run(root->right)) + 1;
    }
}

int number_mult(int num)
{
	int total=0;
	while(num>=10)
	{
		total++;
		int res=1;
		while(num>0)
		{
			res*=(num-num/10*10);
			num/=10;
		}
		num=res;
	}
	return total;
}

bool is_prime(int a)
{
	for(int i=2;i<=sqrt(a*1.0);i++)
	{
		if(a%i==0) return false;
	}
	return true;
}

bool part_is_prime(int a)
{
	vector<int> temp;
	while(a>0)
	{
		temp.push_back(a-a/10*10);
		a/=10;
	}
	for(int i=0;i<temp.size();i++)
	{
		for(int j=0;j<temp.size()&&j!=i;j++)
		{
			int temp1=temp[i]*10+temp[j];
			if(temp1>10&&is_prime(temp1)) return true;
			temp1=temp[j]*10+temp[i];
			if(temp1>10&&is_prime(temp1)) return true;
		}
	}
	return false;
}


int total_prime(int a,int b)
{
	int total=0;
	for(int i=a;i<=b;i++)
	{
		if(part_is_prime(i))
			total++;
	}
	return total;

}
int min_dif_chara(string s1,string s2)
{
	int len1=s1.size();
	int len2=s2.size();
	string temp;
	if(s1.size()>s2.size())
	{
		len1=s2.size();
		len2=s1.size();
		temp=s1;
		s1=s2;
		s2=temp;
	}

	int max_same=0;
	for(int i=0;i<=len2-len1;i++)
	{
		int once_same=0;
		for(int j=0;j<len1;j++)
		{
			if(s1[j]==s2[i+j])
				once_same++;
		}
		if(once_same>max_same)
			max_same=once_same;
	}
	return len2-(max_same+(len2-len1));
}


bool is_mult_2(int a,int b)
{
	if(a==b) return true;
	if(a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	while(a>=b)
	{
		if(a==b) return true;
		a/=2;
	}
	return false;
}
bool mult2_same(vector<int>arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(!is_mult_2(arr[i],arr[j])) return false;
		}
	}
	return true;
}


int min_segment(vector<int> arr)
{
	int jizhi=0;
	int j=arr.size();
	for(int i=1;i<arr.size()-1;i++)
	{
		if(((arr[i-1]<arr[i] && arr[i+1]<arr[i]) || (arr[i-1]>arr[i] && arr[i+1]>arr[i])) && i!=j+1)
		{
			jizhi++;
			j=i;
		}
		else if(arr[i]==arr[i+1])
		{
			arr[i]=arr[i-1];
			j=i;
		}
	}
	return jizhi+1;
}

long max_power(int* pow,int* pot,int n)
{
	long add=0;
	long max=0;
	long* sum=new long [n];
	long* sub=new long [n];
	for(int i=0;i<n;i++)  
    {  
        long a=pow[i];  
        long b=pot[i];  
        sum[i]=a+b;  
        sub[i]=0;  
        if(b>a)  
        {  
            sub[i]=b-a;   
            add=add+sub[i];  
        }  
  
    }  
          
    for(int i=0;i<n;i++)  
    {  
        if(add+sum[i]-sub[i]>max)  
        {  
            max=add+sum[i]-sub[i];  
        }  
              
    }  
	return max;
}
int depth_tree(TreeNode* node){
    if(node){
		int ldepth=depth_tree(node->left);
		int rdepth=depth_tree(node->right);
        return (max(ldepth,rdepth)+1);
    }
    else{
        return 0;
    }
}
bool IsBalanced_Solution(TreeNode* pRoot) {
	if(abs(depth_tree(pRoot->left)-depth_tree(pRoot->right))>1)
        return false;
    else
        return true;
}
    
void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		
        while(data.size()>0){
            int tmp=data[0];
            data.erase(data.begin());
            vector<int>::iterator index=find(data.begin(),data.end(),tmp);
            int dis=distance(data.begin(),index);
            if(dis>=data.size() || dis<0){
                *num1=*num2;
                *num2=tmp;
            }
			else{
				data.erase(index);
			}
        }
    }
vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int res=sum*sum;
        vector<int> res1;
        while(array.size()>0){
	    	int tmp=array[0];
            array.erase(array.begin());
            vector<int>::iterator index=find(array.begin(),array.end(),sum-tmp);
            int dis=distance(array.begin(),index);
            if(dis<array.size()&&dis>=0)
                {
                if(res>tmp*array[dis]){
                    res=tmp*array[dis];
                    array.erase(index);
					res1.clear();
					res1.push_back(tmp);
					res1.push_back(array[dis]);
                }
            }
        }
        return res1;
    }

vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        for(int m=2;m<=sum/2;m++){
            vector<int> seq;

				if((sum/m)%2==1&&sum/m/2>=m)
				{
					for(int i=sum/m/2-m+1;i<=sum/m/2+m;i++)
						seq.push_back(i);
					res.push_back(seq);
				}
				if(m%2==1&&sum/m-(m/2)>=1)
				{
					for(int i=sum/m-m/2;i<=sum/m+m/2;i++)
						seq.push_back(i);
					res.push_back(seq);
				}
            
        }
        return res;
    }
bool match(char* str, char* pattern)
{
    if(str[0]=='\0'&&pattern[0]=='\0') return true;
    if((str[0]=='\0'&&pattern[0]!='\0')||(str[0]!='\0'&&pattern[0]=='\0')){
        if(str[0]=='\0'&&pattern[1]=='*') return match(str,pattern+2);
        else return match(str+2,pattern);
    }
    else if((str[0]==pattern[0]||str[0]=='.'||pattern[0]=='.')||(str[0]!=pattern[0] && str[1]=='*'&&pattern[1]=='*')) return match(str+1,pattern+1);
    else if(str[0]!=pattern[0] && str[1]!='*'&&pattern[1]!='*')return false;
    else if(str[0]!=pattern[0] && str[1]=='*') return match(str+1,pattern);
    else return true;
}

ListNode* deleteDuplication(ListNode* pHead)
{
    /*if (!head || !head->next) return head;
    ListNode* dummy = new ListNode(-1);dummy->next = head;
    ListNode*pre = dummy, *p1 = head;
    bool flag = 0;
    while (p1&&p1->next) {
        while (p1->next&&p1->val == p1->next->val) {
            p1->next = p1->next->next;
            flag = 1;
        }
        if (flag == 1) { pre->next = p1->next;flag = 0;p1 = p1->next; }
        else {
            p1 = p1->next;
            pre = pre->next;
        }
    }
    return dummy->next;
	*/
	if(!pHead || !pHead->next)
            return pHead;
        ListNode* head=pHead;
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        ListNode* temp1=newHead;
        while(head && head->next){
            if(head->val!=head->next->val){
            	temp1=head;
                head=head->next;
            }
            else{
                ListNode* temp2=head;
				while(temp2->next && temp2->val==temp2->next->val){
                    temp2=temp2->next;
                }
                temp1->next=temp2->next;
                head=temp2->next;
            }
        }
        return newHead->next;

}

bool isSymmetrical(TreeNode* pRoot)
{
    if(pRoot && pRoot->left==NULL && pRoot->right==NULL)return true;
	else if(pRoot->left&&pRoot->right && pRoot->left->val==pRoot->right->val) return (isSymmetrical(pRoot->left) && isSymmetrical(pRoot->right));
    else return false;
        
}
void combine(void)
{
	int m,n;
	while(cin>>m>>n){
		//cin>>m>>n;
		vector<int>vec1;
		int temp;
		for(int i=0;i<m+n;i++)
		{
			cin>>temp;
			if(i>=m)
			{
				vector<int>::iterator it=find(vec1.begin(),vec1.end(),temp);
				if(it<vec1.end())
					continue;
				
				
			}
			vec1.push_back(temp);
		}
		sort(vec1.begin(),vec1.end());
		for(vector<int>::iterator it=vec1.begin();it<vec1.end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	return;
}
void min_max_diff(void){
	int N;
      
    int num;
    while(cin>>N)
    {
        vector<int>vec;
        vector<int>vec_num0;
        for(int i=0;i<N;i++)
        {
            cin>>num;
            vec.push_back(num);
        }
        sort(vec.begin(),vec.end());
        vector<vector<int> >total;
        vector<int> row;
        int min_temp=vec[1]-vec[0];
        row.push_back(min_temp);
        int flag=(min_temp==0)?1:0;
		int max_begin=1;
		int max_end=1;
        if(vec[0]==vec[N-1]){
            cout<<N*(N-1)/2<<" "<<N*(N-1)/2<<endl;
            continue;
        }
        for(int i=1;i<N;i++)
        {
            if(vec[i]==vec[i-1])
                max_begin++;
            else
                break;
        }
        for(int i=N-1;i>0;i--)
        {
            if(vec[i]==vec[i-1])
                max_end++;
            else
                break;
        }
        for(int i=2;i<N;i++){
            if(flag==0){
                if((vec[i]-vec[i-1])<min_temp){
                    min_temp=vec[i]-vec[i-1];
                    row.clear();
                    row.push_back(min_temp);
                    if(min_temp==0) flag=1;
                }
				else if((vec[i]-vec[i-1])==min_temp){
					row.push_back(min_temp);
				}
            }
            else{
                if((vec[i]-vec[i-1])!=0&&row.size()>0){
                    total.push_back(row);
                    row.clear();
                }
                else if((vec[i]-vec[i-1])==0){
                    row.push_back(0);
                }
            }
        }
		if(row.size()>0) total.push_back(row);
		if(flag==0)
			cout<<row.size()<<" "<<max_begin*max_end<<endl;
		else
		{
			int total_min=0;
			for(int i=0;i<total.size();i++)
			{
				int temp=total[i].size();
				total_min+=temp*(temp+1)/2;
			}
			cout<<total_min<<" "<<max_begin*max_end<<endl;
		}
        //cout<<min_num<<" "<<max_begin*max_end<<endl;
    }
	return;
}
void shaota(void)
{
	bool flag[10][10];
	int n;
	while(cin>>n)
	{
		vector<int>h;
		int height;
		for(int i=0;i<n;i++)
		{
			cin>>height;
			h.push_back(height);
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			int mid=0;
			for(int j=i+1;j<i+n-1;j++)
			{
				if(h[i]>=mid && mid<=h[j%n])
				{
					if(flag[i][j%n] && flag[j%n][i])
						count++;
					mid=h[j%n];
					flag[i][j%n]=false;
				}
				else
					break;
			}
		}
		cout<<count<<endl;
	}
}
int get_sum(int n,int jinzhi){
    int ans=0;
    while(n>0){
        ans+=(n%jinzhi);
        n/=jinzhi;
    }
    return ans;
}
void get_total(int a){
    if(a<=2){
        cout<<1<<'/'<<1<<endl;
    	return;
    }
    int ans=0;
    int num=a-2;
    int temp=a-1;
    while(temp>=2){
        ans+=get_sum(a,temp);
        temp--;
    }
    int z = ans;
    int x=a-2;
    int y=ans;
    while(x%y!=0)  
    {  
        z = x%y;  
        x = y;  
        y = z;    
    } 
    cout<<ans/z<<'/'<<(a-2)/z<<endl;
    return;
}
void insert_sort(vector<int> &arr,int n){
    if(n<arr[0])
        arr.insert(arr.begin(),n);
    else if(n>arr[arr.size()-1])
        arr.push_back(n);
    else{
        for(int i=0;i<arr.size()-1;i++){
            if(n>arr[i] && n < arr[i+1]){
                arr.insert(arr.begin()+i+1,n);
                break;
            }
            else if(n==arr[i] || n==arr[i+1])
                break;
        }
    }
    return;
}
void get_num(){
    int n,m;
    while(cin>>n>>m){
        int temp;
        vector<int>arr;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(i==0) arr.push_back(temp);
            else insert_sort(arr,temp);
        }
        for(int i=0;i<m;i++){
            cin>>temp;
            insert_sort(arr,temp);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            cout<<arr[i]<<' ';
        }
        cout<<arr[arr.size()-1]<<endl;
    }
    return;
}

int get_max(vector<int>&arr,int left,int right){
    int max=arr[left-1];
    if(left==right)return max;
    for(int i=left;i<right;i++){
        if(arr[i]>max) max=arr[i];
    }
    return max;
}
void process(void){
    int n,m;
    while(cin>>n>>m){
        vector<int>grade;
        int grade1;
        for(int i=0;i<n;i++){
            cin>>grade1;
            grade.push_back(grade1);
        }
        char a;
        int num1,num2;
        for(int i=0;i<m;i++){
            cin>>a;
            cin>>num1>>num2;
            if(a=='Q'){
                cout<<get_max(grade,num1,num2);
            }
            else{
                grade[num1-1]=num2;
            }
        }
        
    }
    return;
}

void file_record(void){
	string full_name,line;
	vector<string>str,lines;
	int a[8]={0};
	ifstream fin;
	vector<int>num;
	fin.open("F:\\C++test\\git\\c-project-algorithm\\offer\\data1.txt");
	while(fin>>full_name>>line)
	{
		int index=0;
		for(int i=0;i<full_name.size();i++)
		{
			if(full_name[i]=='\\') index=i;
		}
		string name(full_name.begin()+index+1,full_name.end());
		if(str.size()==0)
		{
			str.push_back(name);
			lines.push_back(line);
			num.push_back(1);
		}
		else
		{
			for(int i=0;i<str.size();i++)
			{
				if(str[i]==name && lines[i]==line)
				{
					num[i]++;
					break;
				}
			}
			str.push_back(name);
			lines.push_back(line);
			num.push_back(1);
		}
	}
	for(int ii=0;ii<(str.size()<8?str.size():8);ii++)
	{
        int max=num[0];
        int index=0;
        for(int i=0;i<str.size();i++){
            if(max<num[i]){
                max=num[i];
                index=i;
            }
        }
        
        string s;
        if(str[index].size()>16)
        {
            s.append(str[index].end()-16,str[index].end());
        }
        else
            s=str[index];
        cout<<s<<" "<<lines[index]<<" "<<num[index]<<" ";
		num[index]=0;
	}
	fin.close();
	return;
}

vector<int> store_poker(string &s)
{
	vector<int> res;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		{
			res.push_back(10);
			i++;
		}
		else if(s[i]=='J') res.push_back(11);
		else if(s[i]=='Q') res.push_back(12);
		else if(s[i]=='K') res.push_back(13);
		else if(s[i]=='A') res.push_back(14);
		else if(s[i]=='2') res.push_back(15);
		else if(s[i]==' ') continue;
		else res.push_back(s[i]-'0');
	}
	return res;
}

void poker_comp(string &s)
{
	int index=s.find('-');
	string s1(s.begin(),s.begin()+index);
	string s2(s.begin()+index+1,s.end());
	if(s1=="joker JOKER" || s2=="joker JOKER")
	{
		cout<<"joker JOKER"<<endl;
		return;
	}
	vector<int> v1=store_poker(s1);
	vector<int> v2=store_poker(s2);

	if(v1.size()==4 && v2.size()==4)
	{
		if(v1[0]<v2[0])cout<<s2<<endl;
		else cout<<s1<<endl;
		return;
	}
	if(v1.size()==4) cout<<s1<<endl;
	else if(v2.size()==4)cout<<s2<<endl;
	else if(v1.size()!=v2.size()) cout<<"ERROR"<<endl;
	else if(v1[0]<v2[0]) cout<<s2<<endl;
	else if(v1[0]>v2[0]) cout<<s1<<endl;
	else cout<<"ERROR"<<endl;
	return;
}

void fine_point(void){
    int len;
    cin>>len;
    int res=0;
    for(int x=0;x<=int(sqrt(len/2.0));x++){
        int y = sqrt((len - x * x)*1.0);
        if((x*x+y*y)==len){
            if(x==0 || y==0 || x == y){
                res+=4;
            }
            else
                res+=8;
        }
    }
    cout<< res;
}

vector<int> yueshu(int a)
{
	vector<int>res;
	for(int i=2;i<=sqrt(a*1.0);i++)
	{
		if(a%i==0)
		{	
			res.push_back(i);
		
			if(a/i!=i)
				res.push_back(a/i);
		}
	}
	return res;
}
void helper(int n,int m)
{
	vector<int>dp(m+1,0);
	dp[n]=1;
	for(int i=n;i<=m;i++)
	{
		if(dp[i]==0)continue;
		vector<int>ys=yueshu(i);
		for(int j=0;j<ys.size();j++)
		{
			if((i+ys[j])<=m)
			{
				if(dp[i+ys[j]]==0)
					dp[i+ys[j]]=dp[i]+1;
				else
					dp[i+ys[j]]=(dp[i]+1)<dp[i+ys[j]]?(dp[i]+1):dp[i+ys[j]];
			}
		}
	}
	if(dp[m]==0)
		cout<<-1<<endl;
	else
		cout<<dp[m]-1<<endl;
}

void jingdong5(void)
{
	long double a,b;
	while(cin>>a>>b)
	{
		string s1=to_string(a);
        string s2=to_string(b);
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
		long long a1=atoi(s1.c_str());
		long long b1=atoi(s2.c_str());
        string res=to_string(a1+b1);
        reverse(res.begin(),res.end());
        cout<<res<<endl;
	}
}

unsigned long long jingdong6(unsigned long long n)
{
	unsigned long long res=0;
	if(n==2) return 2;
	if(n==1) return 1;
	if(int(n)%2!=0)
	{
		unsigned long long index=(n+1)/2;
		res=(index*index);
		n--;
	}
	else
	{
		unsigned long long index=n/2;
		res=(index*index);
	}
	res+=jingdong6(n/2);
	return res;
}
void wangyi7(void)
{
	int num;
	cin>>num;
	int min_count=num/6+1;
	for(int i=0;i<=num/6;i++)
	{
		if((num-6*i)%8==0)
		{
			if((num-6*i)/8+i<min_count)
				min_count=(num-6*i)/8+i;
		}
	}
	if(min_count==num/6+1)
		cout<<-1<<endl;
	else
		cout<<min_count<<endl;
}
void wangyi8(void)
{
	int s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if((s1+s3)<0 || (s1+s3)%2!=0 || (s2+s4)<0 || (s2+s4)%2!=0 || s4<s2 || (s4-s2)%2!=0)
		cout<<"No"<<endl;
	else
		cout<<(s1+s3)/2<<" "<<(s2+s4)/2<<" "<<(s4-s2)/2<<endl;
}
void backpack_0_1(void)
{
	int num;
	vector<int> val;
	vector<int> weight;
	int temp;
	cin>>num;
	val.push_back(0);//保证下标从1开始
	weight.push_back(0);
	for(int i=1;i<=num;i++)
	{
		cin>>temp;//输入物品价值
		val.push_back(temp);
	}
	for(int i=1;i<=num;i++)
	{
		cin>>temp;//输入物品重量
		weight.push_back(temp);
	}
	//int **dp=new int[num+1][11];
	vector<vector <int> > dp(num+1 ,vector<int>(11));  //有 i 个物品，放在容量为 j 的背包 能获得的最大价值，下标都从1开始
	for(int i=1;i<=num;i++)
	{
		for(int j=10;j>=1;j--)
		{
			if(j<weight[i])
			{	
				dp[i][j]=dp[i-1][j];//当前物品重量超过背包容量，则价值为前i-1个物品获得的价值
			}
			else
				dp[i][j]=dp[i-1][j]>(dp[i-1][j-weight[i]]+val[i])?dp[i-1][j]:(dp[i-1][j-weight[i]]+val[i]);
		}
	}
	return;
}
void cpu_min_time(void)
{
	int num;
	cin>>num;
	vector<int> time;
	int temp;
	int sum=0;
	for(int i=0;i<num;i++)
	{
		cin>>temp;
		time.push_back(temp);
		sum+=temp;
	}
	sum/=2;
	vector<int> dp(sum+1,0);
	for(int i=0;i<num;i++)
	{
		for(int j=sum;j>=time[i];j--)
		{
			dp[j]=dp[j]>dp[j-time[i]]+time[i]?dp[j]:dp[j-time[i]]+time[i];
		}
	}
	return;
}
class A {
public:
    int b;
    char c;
    virtual void print() {
        cout << "this is father’s fuction! " << endl;
    }
};
class B: A {
public:
    virtual void print() {
        cout << "this is children’s fuction! " << endl;
    }
};
class myClass{
public:
	void foo();
};
void myClass::foo(){
    delete this;
}
void func(){
    myClass *a = new myClass();
    a->foo();
}
void fast_sort(vector<int> &a,int left,int right)
{
	if(left>=right) return;
	int temp=a[left];
	int i=left;
	int j=right;
	while(i<j)
	{
		while(a[j]>=temp && i<j)
			j--;
		while(a[i]<=temp && i<j)
			i++;
		if(i<j){
			int temp1=a[i];
			a[i]=a[j];
			a[j]=temp1;
		}
	}
	a[left]=a[i];
	a[i]=temp;
	fast_sort(a,left,i-1);
	fast_sort(a,i+1,right);
}
void quicksort(int a[],int left,int right) 
{ 
    int i,j,t,temp; 
    if(left>right) 
       return; 
                                
    temp=a[left]; //temp中存的就是基准数 
    i=left; 
    j=right; 
    while(i!=j) 
    { 
                   //顺序很重要，要先从右边开始找 
                   while(a[j]>=temp && i<j) 
                            j--; 
                   //再找右边的 
                   while(a[i]<=temp && i<j) 
                            i++; 
                   //交换两个数在数组中的位置 
                   if(i<j) 
                   { 
                            t=a[i]; 
                            a[i]=a[j]; 
                            a[j]=t; 
                   } 
    } 
    //最终将基准数归位 
    a[left]=a[i]; 
    a[i]=temp; 
                             
    quicksort(a,left,i-1);//继续处理左边的，这里是一个递归的过程 
    quicksort(a,i+1,right);//继续处理右边的 ，这里是一个递归的过程 
} 
int main()
{
	/*TreeNode * tree=new TreeNode(62);
	tree->left=new TreeNode(47);
	tree->right=new TreeNode(88);
	tree->left->left=new TreeNode(35);
	tree->left->left->left=NULL;
	tree->left->left->right=new TreeNode(37);
	tree->left->right=new TreeNode(51);
	tree->left->right->left=NULL;
	tree->left->right->right=new TreeNode(58);

	tree->right->left=new TreeNode(73);
	tree->right->left->left=NULL;
	tree->right->left->right=NULL;
	tree->right->right=new TreeNode(99);
	tree->right->right->left=new TreeNode(93);
	tree->right->right->right=NULL;
	*/
	//cout<<run(tree)<<endl;
	/*
	solution s;
	int pre[]={4,2,1,3,6,5,7};
	int vin[]={1,2,3,4,5,6,7};
	int back[]={7,4,2,5,8,6,3,1};
	TreeNode *root1=s.reConstructBinaryTree1(pre,0,6,vin,0,6);
	TreeNode *root2=s.reConstructBinaryTree2(back,0,7,vin,0,7);*/
	/*char a[]="hello world haha!";
	s.replaceSpace(a,18);
	s.Mirror(root1);

	int m=4;
	int n=4;
	vector<vector<int>> arr(m);
	//vector<vector<int> > array(m); //这个m一定不能少
//初始化一个m*n的二维数组
	for(int i=0;i<m;i++) {
		arr[i].resize(n);
	}
	for(size_t i=0;i<arr.size();i++)
	{
		for(size_t j=0;j<arr[0].size();j++)
		{
			arr[i][j]=i*arr.size()+j+1;
		}
	}
	//vector<int> res=s.printMatrix(arr);

	int a1[]={1,2,3,4,5};
	int b1[]={4,3,5,1,2};
	vector<int> ain(a1,a1+5);
	vector<int> bin(b1,b1+5);
	bool flag=s.IsPopOrder(ain,bin);
	*/
	//int a1[]={5,7,6,9,11,10,8};
	//int b1[]={1,3,8,5,6,7,4};
	//RandomListNode*head=new RandomListNode(1);
	//head->next=new RandomListNode(2);
	//head->next->next=new RandomListNode(3);
	//head->next->random=head;
	//head->next->next->random=head->next;
	//vector<int> ain(a1,a1+7);
	//vector<int> bin(b1,b1+7);
	//bool result=s.VerifySquenceOfBST1(bin);
	//result=s.VerifySquenceOfBST(bin);
	//vector<int> res=s.PrintFromTopToBottom(root1);
	//vector<vector<int>> vec=s.FindPath(root1,14);
	//RandomListNode*res=s.Clone(head);
	/*ListNode *list1=new ListNode(1);
	list1->next=new ListNode(2);
	list1->next->next=new ListNode(3);
	ListNode*res=s.FindKthToTail(list1,1);
	TreeNode*res_list=s.Convert(root1);
	*/
	//int res=s.MoreThanHalfNum_Solution(bin);
	//string str="aabc";
	//vector<string> result=s.Permutation(str);
	//int max_val=100;
	//cout<<s.GetUglyNumber_Solution(max_val)<<endl;
	//cout<<s.GetUglyNumber_Solution1(max_val)<<endl;
	//cout<<number_mult(258)<<endl;
	//cout<<total_prime(37,98)<<endl;
	//string s1,s2;
	//cin>>s1;
	//cin>>s2;
	//cout<<min_dif_chara(s1,s2);
	//int n;
	//cin>>n;
	//vector<int> arr;
	//int num;
	//ifstream fin;
	/*fin.open("F:\\C++test\\lesson\\test\\offer\\data1.txt");
	while(fin>>num){
		arr.push_back(num);
	}
	*/
	/*for(int i=0;i<n;i++)
	{
		cin>>num;
		arr.push_back(num);
	}*/
	//if(mult2_same(arr,n))
	//	cout<<"YES";
	//else
	//	cout<<"NO";
	//cout<<min_segment(arr);
	//int n;
	//cin>>n;
	//int pow[100000];
	//int pot[100000];
	//for(int i=0;i<n;i++)
	//{
	//	cin>>pow[i];
	//	cin>>pot[i];
	//}
	//cout<<max_power(pow,pot,n)<<endl;
	//bool res=IsBalanced_Solution(tree);
	/*int a1[]={2,3,1,2,3,3,2,6};
	vector<int> ain(a1,a1+8);
	vector<vector<int> >res;//返回对应值的索引
	vector<int>data(1,0);//存放临时索引
	vector<int>index;//返回对应的值
	vector<int> tmp(100,-1);//临时存放标志位
	for(int i=0;i<ain.size();i++)
	{
		if(tmp[ain[i]]<0)
		{
			data[0]=i;
			tmp[ain[i]]=res.size();
			index.push_back(ain[i]);
			res.push_back(data);
		}
		else
		{
			res[tmp[ain[i]]].push_back(i);
		}
	}
	ofstream fout;
	fout.open("F:\\C++test\\lesson\\test\\offer\\data1.txt");
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			fout<<res[i][j]<<" ";
		fout<<-1<<endl;
	}
	fout.close();
	ifstream fin;
	vector<int>in_line;
	vector<vector<int> >in_total;
	fin.open("F:\\C++test\\lesson\\test\\offer\\data1.txt");
	int num;
	while(fin>>num)
	{
		if(num==-1){
			in_total.push_back(in_line);
			in_line.clear();
		}
		else
			in_line.push_back(num);
	}
	fin.close();
	//int a,b;
	//vector<int> res=FindNumbersWithSum(ain,15);
	//vector<vector<int> >res= FindContinuousSequence(99);
	int a=5,b=4;
	double s;
	s=pow(double(a),2)/4;
	*/
	//char a[]={'\0'};
	//char b[]={'.','*','\0'};
	//bool res=match(a,b);
	/*ListNode *list1=new ListNode(1);
	ListNode *head=list1;
	int num;
	while(cin>>num){
		list1->next=new ListNode(num);
		list1=list1->next;
	}
	list1->next=NULL;
	ListNode*res=deleteDuplication(head->next);
	*/
	/*TreeNode * tree=new TreeNode(1);
	tree->left=new TreeNode(2);
	tree->right=new TreeNode(2);
	tree->left->left=new TreeNode(3);
	//tree->left->left->left=NULL;
	tree->left->left->right=new TreeNode(37);
	tree->left->right=new TreeNode(3);
	//tree->left->right->left=NULL;
	tree->left->right->right=new TreeNode(58);

	tree->right->left=new TreeNode(4);
	//tree->right->left->left=NULL;
	//tree->right->left->right=NULL;
	tree->right->right=new TreeNode(4);
	tree->right->right->left=new TreeNode(93);
	//tree->right->right->right=NULL;
	bool res=isSymmetrical(tree);
	*/
	//combine();
	//min_max_diff();
	/*
	int n;
	cin>>n;
    bool *flag=new bool[n*n];
    for(int i=0;i<n*n;i++){
        flag[i]=true;
    }
    vector<int>h;
    int height;
    for(int i=0;i<n;i++)
    {
        cin>>height;
        h.push_back(height);
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        int mid=0;
        for(int j=i+1;j<i+n-1;j++)
        {
            if(h[i]>=mid && mid<=h[j%n])
            {
                if(flag[i*n+j%n] && flag[(j%n)*n+i])
                {
                    count++;
                }

                mid=h[j%n];
                flag[i*n+j%n]=false;
            }
        }
    }
    cout<<count<<endl;
    delete(flag);
    flag=NULL;*/
	//get_total(10);
	//get_num();
	//process();
	//file_record();
	//string s="4 4 4 4-5 5 5 5";
	//poker_comp(s);
	//fine_point();
	//helper(4,24);
	//cout<<long long (jingdong6(1000000000))<<endl;
	//wangyi7();
	//backpack_0_1();
	//cpu_min_time();
	//cout << sizeof(A) << "" << sizeof(B) << endl;
	//myClass s;
	//s.foo();
	int a[]={4,6,8,1,3,7,9,2,0};
	vector<int> arr(a,a+9);
	fast_sort(arr,0,8);
	//quicksort(a,0,8);
    return 0;	
}