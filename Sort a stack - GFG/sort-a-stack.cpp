//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void help(stack<int> &st , int check){
    if(st.empty()){
        st.push(check);
        return;
    }
    
    int x = st.top();
    st.pop();
    if(x<check){
        help(st,x);
        
        st.push(check);
        return;
    }
    else{
        help(st,check);
        st.push(x);
    }
}
void SortedStack :: sort()
{
   //Your code here
  if(s.size()==1)
    return;
   if(s.empty())
    return;
    
    int x  = s.top();
    s.pop();
    sort();
    help(s,x);
   
}